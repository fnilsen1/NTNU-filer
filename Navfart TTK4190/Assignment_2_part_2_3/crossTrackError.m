function [e_y, pi_h] = crossTrackError(x_start, y_start, x_end, y_end, x, y)

pi_h = atan2(y_end - y_start, x_end - x_start);
e_y = -sin(pi_h)*(x - x_start) + cos(pi_h)*(y - y_start);
end
