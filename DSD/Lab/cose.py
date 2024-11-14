import numpy as np
import matplotlib.pyplot as plt

a = 10
f = 15
d = np.pi * 3/4
fs = 1500

t = np.linspace(1,1.5, fs, endpoint=False)

cose_wave = a* np.cos(2*np.pi*f*t + d)

plt.figure(figsize=(10,6))
plt.plot(t,cose_wave)
plt.title("Cose Wave")
plt.xlabel("Time")
plt.ylabel("Amplitude")
plt.grid(True)
plt.show()