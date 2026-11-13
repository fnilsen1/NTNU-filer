function chi_d = guidance(position, WP, k, lookahead)

[e_y, pi_h] = crossTrackError(WP(1,k), WP(2,k), WP(1,k+1), WP(2,k+1), ...
    position(1), position(2));
chi_d = LOS_guidance(e_y, pi_h, 1/lookahead);
end
