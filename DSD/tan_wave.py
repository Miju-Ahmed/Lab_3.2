import numpy as np
import matplotlib.pyplot as plt

frequency = 5
duration = 1
phase = np.pi*1000
sampling_rate = 100000

t = np.linspace(0,duration, int(sampling_rate), endpoint=False)

tan_wave = np.tan(2*np.pi*frequency*t + phase)

plt.figure(figsize = (15,5))
plt.plot(t,tan_wave,color = 'red')
plt.title("Tan Wave")
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.grid(False)
plt.show()