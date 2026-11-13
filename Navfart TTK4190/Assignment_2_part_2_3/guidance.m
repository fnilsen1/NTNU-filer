function [psi_ref, y_int_dot] = guidance(e_y, pi_h, y_int, Delta, Ki, kappa)

Kp = 1/Delta;
psi_ref = pi_h - atan(Kp*e_y + Ki*y_int);
y_int_dot = Delta*e_y / (Delta^2 + (e_y + kappa*y_int)^2);
end
