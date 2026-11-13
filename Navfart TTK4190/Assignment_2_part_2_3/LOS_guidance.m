function chi_d = LOS_guidance(e_y, pi_h, Kp_los)

chi_d = pi_h - atan(Kp_los*e_y);
end
