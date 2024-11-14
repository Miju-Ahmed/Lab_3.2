import numpy as np
import matplotlib.pyplot as plt

f1 = 10
a = 10
f2 = 15
d = np.pi * 3/4
fs = 15000

t = np.linspace(0,2, fs, endpoint=False)
sine_wave = a*np.sin(2*np.pi*f1*t+d)
cose_wave = a* np.cos(2*np.pi*f2*t + d)
sin_cos = sine_wave + cose_wave

plt.figure(figsize=(10, 4))
plt.plot(t, sin_cos)
plt.title("Sine-Cose Wave Signal")
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.grid(True)
plt.show()