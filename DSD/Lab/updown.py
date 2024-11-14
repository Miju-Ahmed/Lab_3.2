import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import resample, lfilter, firwin

# Original signal parameters
fs = 100  # Original sampling rate (100 Hz)
t = np.arange(0, 1, 1/fs)  # Time vector for 1 second
f = 5  # Frequency of the sinusoid (5 Hz)
x = np.sin(2 * np.pi * f * t)  # Original signal (5 Hz sine wave)

# Down-Sample by a factor of 2
down_factor = 2
x_down = x[::down_factor]
t_down = t[::down_factor]

# Up-Sample by a factor of 2
up_factor = 2
x_up = np.zeros(len(x_down) * up_factor)
x_up[::up_factor] = x_down

# Low-pass filter to smooth the up-sampled signal
# Define a simple low-pass FIR filter to remove high-frequency artifacts
numtaps = 21  # Number of filter taps
cutoff = 0.5  # Cutoff frequency relative to Nyquist (0.5 * upsampling rate)
lp_filter = firwin(numtaps, cutoff)
x_up_smooth = lfilter(lp_filter, 1.0, x_up)

# Plotting the original, down-sampled, and up-sampled signals
plt.figure(figsize=(12, 8))

# Original signal
plt.subplot(3, 1, 1)
plt.plot(t, x, label='Original Signal')
plt.xlabel('Time [s]')
plt.ylabel('Amplitude')
plt.title('Original Signal')
plt.grid(True)
plt.legend()

# Down-sampled signal
plt.subplot(3, 1, 2)
plt.stem(t_down, x_down, linefmt='orange', markerfmt='o', basefmt=" ", label='Down-Sampled Signal')
plt.xlabel('Time [s]')
plt.ylabel('Amplitude')
plt.title('Down-Sampled Signal (Factor = 2)')
plt.grid(True)
plt.legend()

# Up-sampled signal (interpolated)
plt.subplot(3, 1, 3)
plt.plot(t, x_up_smooth, label='Up-Sampled and Smoothed Signal', color='green')
plt.xlabel('Time [s]')
plt.ylabel('Amplitude')
plt.title('Up-Sampled and Smoothed Signal (Factor = 2)')
plt.grid(True)
plt.legend()

plt.tight_layout()
plt.show()
