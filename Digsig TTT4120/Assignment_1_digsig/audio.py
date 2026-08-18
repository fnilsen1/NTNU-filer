import numpy as np
import matplotlib.pyplot as plt
import sounddevice as sd

def harmonic_sequence(A, f_1, n_array):
    return A*np.cos(2*np.pi*f_1*n_array)

#F_S = 6000Hz -> 24k samples in 4 sec 
F_S = 1000
F_1 = 2000
f_1 = F_1/F_S


n_values = np.arange(24000)
more_n_values = np.linspace(0,4,1000000)
x_n = harmonic_sequence(1,f_1, n_values)
cos_values = np.cos(2*np.pi*2000*more_n_values)

sd.play(x_n)

plt.xlim(0, 0.002)
plt.plot(more_n_values, cos_values, label="2000 Hz cosine")
plt.scatter(n_values/6000, x_n, color="red", s=5, label="Samples")
plt.show()