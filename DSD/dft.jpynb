import numpy as np
import matplotlib.pyplot as plt

f1= 1000
f2 = 2000
amplitude = 0.5
phase = 135
sampling_rate = 8000


t = np.linspace(0,.001, int(sampling_rate), endpoint=False)

sine_wave = np.sin(2*np.pi*f1*t) + np.sin(2*np.pi*f2*t + phase)

#plt.subplot(2,2,1)
plt.plot(t,sine_wave,color='red')
plt.title("Sine Wave")
plt.xlabel("Time(s)")
plt.ylabel("Amplitude")
plt.grid(True)
plt.show()