import numpy as np
import matplotlib.pyplot as plt

frequency = 5
duration = 1
phase = np.pi*2
sampling_rate = 100000

t = np.linspace(0,duration, int(sampling_rate), endpoint=False)

cos_wave = np.cos(2*np.pi*frequency*t + phase)

plt.figure(figsize = (15,5))
plt.plot(t,cos_wave,color = 'red')
plt.title("Cosine Wave")
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.grid(False)
plt.show()