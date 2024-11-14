import numpy as np
import matplotlib.pyplot as plt

sampling_rate = 100000
frequency = 5
duration = 1
phase = np.pi*(2)

t = np.linspace(0, duration, int(sampling_rate * duration), endpoint=False)

sine_wave = 10 * np.sin(2*np.pi * frequency * t + phase)

plt.figure(figsize=(15,5),facecolor='gray')
plt.plot(t,sine_wave,color='red')
plt.title("Sine Wave")
plt.xlabel("Time(s)")
plt.ylabel("Amplitude")
plt.grid(True)
plt.show()