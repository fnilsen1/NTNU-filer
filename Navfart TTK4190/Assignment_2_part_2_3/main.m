% Project in TTK4190 Guidance, Navigation and Control of Vehicles 
%
% Author:           Your name
% Study program:    Your study program

%% User inputs and initial states
clc; clear; close all;
T_final = 8000;	        % Final simulation time (s)
h = 0.1;                % Sampling time (s)

U_ref = 9;            % desired surge speed (m/s)
V_c = 1;              % current speed
use_ilos = true;
crab_compensation_enabled = false;
beta_vc = deg2rad(45);
wind_enabled = false;
show_animation = false;

load('WP.mat', 'WP');
k = 1;
lookahead = 1000;
Kp_los = 1/lookahead;
Ki_ilos = 0.001;
kappa_ilos = 1;
y_int = 0;
R_switch = 250;

% initial states
eta_0 = [WP(:,1); deg2rad(-110)];
nu_0  = [0 0 0]';
delta_0 = 0;
n_0 = 0;
Qm_0 = 0; 
x = [nu_0; eta_0; delta_0; n_0; Qm_0]; % The state vector can be extended with addional states here

%% Simulation setup and controller tuning
t = 0:h:T_final;                % Time vector
nTimeSteps = length(t);         % Number of time steps

simdata = zeros(nTimeSteps, 14); % Pre-allocate matrix for efficiency
e_y_history = zeros(nTimeSteps, 1);

% %%%%%%%%%%%%%%%%%%%%%%%%%%
% Part 2(d)
% %%%%%%%%%%%%%%%%%%%%%%%%%%

% Nomoto parameters from parts (b) and (c)
T_nomoto = 169.549327;
K_nomoto = 0.0074931173;

% PID tuning: Algorithm 15.1
omega_b = 0.06;
zeta = 1;

omega_n = omega_b / sqrt(1 - 2*zeta^2 ...
    + sqrt(4*zeta^4 - 4*zeta^2 + 2));

Kp = (T_nomoto/K_nomoto) * omega_n^2;
Kd = (2*zeta*omega_n*T_nomoto - 1) / K_nomoto;
Ki = (omega_n/10) * Kp;

% Reference model states
omega_ref = 0.09;
xd = [eta_0(3); nu_0(3); 0];

% Heading-error integral
e_int = 0;

% Match the rudder-angle limit
delta_max = deg2rad(40);

%% Simulation loop
for i = 1:nTimeSteps
    
    %% Ocean current
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Part 2, 1a) Add current here 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    uc = V_c*cos(beta_vc-x(6));
    vc = V_c*sin(beta_vc-x(6));
    
    nu_c = [ uc vc 0 ]';
    
    %% Wind forces
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Part 2, 1c) Add wind here 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%

    % Wind parameters
    V_w = 10;                 % wind speed
    beta_Vw = deg2rad(135);    % southeast
    rho_a = 1.247;             % air density 
    c_y = 0.95;
    c_n = 0.15;
    L_oa = 161;               % ship length (m)
    A_Lw = 10 * L_oa;

    Ywind = 0;
    Nwind = 0;

    if wind_enabled && t(i) >= 200
        % Wind velocity expressed in body axes
        u_w = V_w * cos(beta_Vw - x(6));
        v_w = V_w * sin(beta_Vw - x(6));

        % Ship velocity relative to the air
        u_rw = x(1) - u_w;
        v_rw = x(2) - v_w;

        V_rw = hypot(u_rw, v_rw);
        gamma_rw = -atan2(v_rw, u_rw);

        % Wind coefficients
        C_Y = c_y * sin(gamma_rw);
        C_N = c_n * sin(2 * gamma_rw);

        % Sway force and yaw moment
        Ywind = 0.5 * rho_a * V_rw^2 * A_Lw * C_Y;
        Nwind = 0.5 * rho_a * V_rw^2 * A_Lw * L_oa * C_N;
    end

    tau_wind = [0; Ywind; Nwind];
    
    %% Waypoint selection and guidance
    k_previous = k;
    [x_start, y_start, x_end, y_end, k, last] = WP_selector(x(4:5), WP, k, R_switch);
    if use_ilos && k ~= k_previous
        y_int = 0;
    end
    [e_y, pi_h] = crossTrackError(x_start, y_start, x_end, y_end, x(4), x(5));
    e_y_history(i) = e_y;
    if use_ilos
        [psi_ref, y_int_dot] = guidance(e_y, pi_h, y_int, lookahead, Ki_ilos, kappa_ilos);
        y_int = y_int + h*y_int_dot;
    else
        chi_d = LOS_guidance(e_y, pi_h, Kp_los);
        psi_ref = chi_d;
        if crab_compensation_enabled
            beta_c = atan2(x(2), x(1));
            psi_ref = psi_ref - beta_c;
        end
    end

    %% Heading reference model
    psi_d = xd(1);
    r_d = xd(2);
    u_d = U_ref;
    xd_dot = ref_model(xd, psi_ref, omega_ref);

    %% Heading PID and anti-windup
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Part 2, 2d) Add the heading controller here 
    % Define it as a function
    %
    % The result should look like this:
    % delta_c = PID_heading(e_psi,e_r,e_int);
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    e_psi = atan2(sin(x(6) - psi_d), cos(x(6) - psi_d));
    e_r = x(3) - r_d;

    % PID command before saturation
    delta_unsat = PID_heading(e_psi, e_r, e_int, Kp, Kd, Ki);

    % Rudder-angle command saturation
    delta_c = min(max(delta_unsat, -delta_max), delta_max);

    if abs(delta_unsat) <= delta_max || e_psi*delta_unsat > 0
        e_int = e_int + h*e_psi;
    end

    %% Speed control
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Part 2, 3e) Add open loop speed control here
    % Define it as a function
    %
    % The result should look like this:
    % n_c = open_loop_speed_control(U_ref);
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    n_c =  open_loop_speed_control(U_ref);                   % propeller speed [revolutions per second (rps)]
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Part 2, 3f) Replace the open loop speed controller, 
    % with a closed loop speed controller here 
    % Define it as a function
    %
    % The result should look like this:
    % n_c = closed_loop_speed_control(u_d,e_u,e_int_u);
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    %% Ship dynamics, logging, and integration
    % ship dynamics
    u = [delta_c n_c]';
    [xdot,tau_total] = ship(x,u,nu_c,tau_wind);
    
    % store simulation data in a table (for testing)
    simdata(i,:) = [x(1:3)' x(4:6)' x(7) x(8) u(1) u(2) u_d psi_d r_d psi_ref];
    if last
        fprintf('  Final waypoint reached at %.1f s.\n', t(i));
        break
    end

    % Euler integration
    % x = euler2(xdot,x,h); 
    % Runge Kutta 4 integration
    x = rk4(@ship,h,x,u,nu_c,tau_wind);
    xd = xd + h*xd_dot;

    %% Progress reporting
    % --- Progress Update Logic ---
    if mod(i, floor(nTimeSteps / 10)) == 0 % Print an update every 10%
        progress = (i/nTimeSteps) * 100;
        fprintf('  %d%% complete\n', round(progress));
    elseif i == 1
        disp("  Simulation in progress:")
        fprintf('  %d%% complete\n', 0);
    end

end
if ~last
    fprintf('  Time limit reached before arrival.\n');
end
simdata = simdata(1:i,:);
e_y_history = e_y_history(1:i);
t = t(1:i);
%% Unpack simulation data
u           = simdata(:,1);                 % m/s
v           = simdata(:,2);                 % m/s
r           = simdata(:,3);                 % rad/s
r_deg       = (180/pi) * r;                 % deg/s
x           = simdata(:,4);                 % m
y           = simdata(:,5);                 % m
psi         = simdata(:,6);                 % rad
psi_deg     = (180/pi) * psi;               % deg
delta_deg   = (180/pi) * simdata(:,7);      % deg
n = 60 * simdata(:,8);       % revolutions/s -> rpm
delta_c_deg = (180/pi) * simdata(:,9);      % deg
n_c = 60 * simdata(:,10);    % revolutions/s -> rpm
u_d         = simdata(:,11);                % m/s
psi_d       = simdata(:,12);                % rad
psi_d_deg   = (180/pi) * psi_d;             % deg
r_d         =  simdata(:,13);               % rad/s
r_d_deg     = (180/pi) * r_d;               % deg/s

%% Surge, sideslip, and crab plots
% Part 2 1b)
uc = V_c * cos(beta_vc - psi);
vc = V_c * sin(beta_vc - psi);

figure(2);
clf;
plot(t, u, t, u-uc, t, u_d, '--', 'LineWidth', 1.5);
grid on;
xlabel('Time (s)');
ylabel('Surge velocity (m/s)');
legend('Ground-relative surge', 'Water-relative surge', ...
    'Desired speed', 'Location', 'best');

beta = atan2(v - vc, u - uc);  % Sideslip angle
beta_c = atan2(v, u);          % Crab angle

speed_ground = hypot(u,v);
speed_relative = hypot(u-uc,v-vc);

beta_c(speed_ground < 0.01) = NaN;
beta(speed_relative < 0.01) = NaN;

beta_deg = rad2deg(beta);
beta_c_deg = rad2deg(beta_c);

figure(3)
plot(t, beta_deg, t, beta_c_deg, 'LineWidth', 2);

title('Sideslip and crab angles');
xlabel('Time (s)');
ylabel('Angle (deg)');
legend('Sideslip', 'Crab');
grid on;

%% Position and yaw plots
figure(4)
figure(gcf)
subplot(311)
plot(y,x,'linewidth',2); axis('equal')
title('North-East positions'); xlabel('(m)'); ylabel('(m)'); 
subplot(312)
plot(t,psi_deg,t,psi_d_deg,'linewidth',2);
title('Actual and desired yaw angle'); xlabel('Time (s)');  ylabel('Angle (deg)'); 
legend('actual yaw','desired yaw')
subplot(313)
plot(t,r_deg,t,r_d_deg,'linewidth',2);
title('Actual and desired yaw rates'); xlabel('Time (s)');  ylabel('Angle rate (deg/s)'); 
legend('actual yaw rate','desired yaw rate')

%% Speed and actuator plots
figure(5)
figure(gcf)
subplot(311)
plot(t,u,t,u_d,'linewidth',2);
title('Actual and desired surge velocity'); xlabel('Time (s)'); ylabel('Velocity (m/s)');
legend('actual surge','desired surge')
subplot(312)
plot(t,n,t,n_c,'linewidth',2);
title('Actual and commanded propeller speed'); xlabel('Time (s)'); ylabel('Motor speed (RPM)');
legend('actual RPM','commanded RPM')
subplot(313)
plot(t,delta_deg,t,delta_c_deg,'linewidth',2);
title('Actual and commanded rudder angle'); xlabel('Time (s)'); ylabel('Angle (deg)');
legend('actual rudder angle','commanded rudder angle')
%% Create objects for 3-D visualization 
if show_animation
    addpath(genpath('flypath3d_v3'));
    % Since we only simulate 3-DOF we need to construct zero arrays for the 
    % excluded dimensions, including height, roll and pitch
    z = zeros(length(x),1);
    phi = zeros(length(psi),1);
    theta = zeros(length(psi),1);

    % create object 1: ship (ship1.mat)
    new_object('flypath3d_v3/ship1.mat',[x,y,z,phi,theta,psi],...
    'model','royalNavy2.mat','scale',(max(max(abs(x)),max(abs(y)))/1000),...
    'edge',[0 0 0],'face',[0 0 0],'alpha',1,...
    'path','on','pathcolor',[.89 .0 .27],'pathwidth',2);

    % Plot trajectories 
    flypath('flypath3d_v3/ship1.mat',...
    'animate','on','step',500,...
    'axis','on','axiscolor',[0 0 0],'color',[1 1 1],...
    'font','Georgia','fontsize',12,...
    'view',[-25 35],'window',[900 900],...
    'xlim', [min(y)-0.1*max(abs(y)),max(y)+0.1*max(abs(y))],... 
    'ylim', [min(x)-0.1*max(abs(x)),max(x)+0.1*max(abs(x))], ...
    'zlim', [-max(max(abs(x)),max(abs(y)))/100,max(max(abs(x)),max(abs(y)))/20]);
end

%% Heading tracking plot
psi_command = rad2deg(simdata(:,14));
chi = psi+beta_c;

figure(6);
clf;
plot(t, psi_command, 'k:', 'LineWidth', 1.5);
hold on;
plot(t, psi_d_deg, 'b--', 'LineWidth', 1.5);
plot(t, psi_deg, 'r', 'LineWidth', 1.5);
plot(t, rad2deg(chi), 'g-.', 'LineWidth', 1.5);
grid on;
xlabel('Time (s)');
ylabel('Heading (deg)');
legend('Heading command', 'Reference-model heading', 'Actual heading', ...
    'Course', 'Location', 'best');
title('Heading tracking');

%% Cross-track error plot
figure(7);
plot(t, e_y_history, 'LineWidth', 1.5);
grid on;
xlabel('Time (s)');
ylabel('Cross-track error (m)');
title('Cross-track error');

%% Map plot
pathplotter(x,y)

%% Local functions
function xd_dot = ref_model(xd, psi_ref, omega_ref)
% States: xd = [psi_d; r_d; a_d]

xd_dot = zeros(3,1);

xd_dot(1) = xd(2);
xd_dot(2) = xd(3);

heading_error = atan2(sin(xd(1) - psi_ref), cos(xd(1) - psi_ref));
xd_dot(3) = -omega_ref^3*heading_error ...
    -3*omega_ref^2*xd(2) ...
    -3*omega_ref*xd(3);
end

function delta_c = PID_heading(e_psi, e_r, e_int, Kp, Kd, Ki)
delta_c = -Kp*e_psi - Kd*e_r - Ki*e_int;
end

function n_d = open_loop_speed_control(U_ref)
m = 17.0677e6;
Xudot = -8.9830e5;
T1 = 20;

rho = 1025;
Dia = 3.3;
KT = 0.6366516179;
t_thr = 0.05;

Xu = -(m - Xudot)/T1;
T_d = -Xu * U_ref / (1 - t_thr);

n_d = sqrt(T_d / (rho * Dia^4 * KT));
end
