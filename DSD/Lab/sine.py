import numpy as np
import matplotlib.pyplot as plt

a = 6
f = 10
fs = 1000
d = np.pi*3/4

t = np.linspace(0,1,int(fs),endpoint=False)

sine_wave = a*np.sin(2*np.pi*f*t+d)

plt.figure(figsize=(10,5))
plt.plot(t,sine_wave)
plt.title("Sine Wave")
plt.xlabel("Time")
plt.ylabel("Amplitude")
plt.grid(True)
plt.legend()
plt.show()
