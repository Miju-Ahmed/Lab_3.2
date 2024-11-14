import numpy as np
import matplotlib.pyplot as plt

# Parameters
sampling_rate = 1000  # Sampling rate in Hz
duration = 1  # Duration of the signal in seconds
frequency = 10  # Frequency of the sine wave in Hz

# Time array
t = np.linspace(0, duration, int(sampling_rate), endpoint=False)

# Generate the sine wave signal
sine_wave = 20 * np.sin(2 * np.pi * frequency * t)

# Plot the sine wave
plt.figure(figsize=(10, 4))
plt.plot(t, sine_wave)
plt.title("Sine Wave Signal")
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.grid(True)
plt.show()
