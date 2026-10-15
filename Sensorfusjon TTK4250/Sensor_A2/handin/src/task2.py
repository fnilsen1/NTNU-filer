import numpy as np
from scipy.stats import norm
from typing import Tuple

from gaussian import MultiVarGauss2d
from measurement import Measurement2d
from sensor_model import LinearSensorModel2d
from conditioning import get_cond_state
from solution import task2 as task2_solu

def get_conds(state: MultiVarGauss2d,
              sens_model_c: LinearSensorModel2d, meas_c: Measurement2d,
              sens_model_r: LinearSensorModel2d, meas_r: Measurement2d
              ) -> Tuple[MultiVarGauss2d, MultiVarGauss2d]:

    cond_c = get_cond_state(state, sens_model_c, meas_c)
    cond_r = get_cond_state(state, sens_model_r, meas_r)

    return cond_c, cond_r


def get_double_conds(state: MultiVarGauss2d,
                     sens_model_c: LinearSensorModel2d, meas_c: Measurement2d,
                     sens_model_r: LinearSensorModel2d, meas_r: Measurement2d
                     ) -> Tuple[MultiVarGauss2d, MultiVarGauss2d]:

    # Camera first, then radar: p(x | z^c, z^r)
    cond_c = get_cond_state(state, sens_model_c, meas_c)
    cond_cr = get_cond_state(cond_c, sens_model_r, meas_r)

    # Radar first, then camera: p(x | z^r, z^c)
    cond_r = get_cond_state(state, sens_model_r, meas_r)
    cond_rc = get_cond_state(cond_r, sens_model_c, meas_c)

    return cond_cr, cond_rc


def get_prob_over_line(gauss: MultiVarGauss2d) -> float:
    lin_transform = np.array([[-1, 1]])
    transformed = gauss.get_transformed(lin_transform)

    mean = transformed.mean[0]
    std = np.sqrt(transformed.cov[0, 0])

    prob = 1 - norm.cdf(5, mean, std)

    return prob