function [x_start, y_start, x_end, y_end, k, last] = WP_selector(position, WP, k, R_switch)

final_segment = size(WP, 2) - 1;
reached = norm(position(:) - WP(:, k+1)) <= R_switch;
last = reached && k == final_segment;
if reached && k < final_segment
    k = k + 1;
end

x_start = WP(1, k);
y_start = WP(2, k);
x_end = WP(1, k+1);
y_end = WP(2, k+1);
end
