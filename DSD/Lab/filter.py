import numpy as np
import matplotlib.pyplot as plt

# Parameters
N = 100  # Length of the signal
alpha = 0.1  # Filter coefficient (adjustable for stronger/weaker filtering)

# Generate a noisy signal: a sine wave with added noise
t = np.linspace(0, 2 * np.pi, N)
x = np.sin(2 * t) + 0.5 * np.random.normal(size=N)  # Sine wave + noise

# Initialize output array for filtered signal
y = np.zeros(N)
y[0] = x[0]  # Initial condition: set y[0] = x[0] to start

# Apply the low-pass filter
for n in range(1, N):
    y[n] = (1 - alpha) * y[n - 1] + alpha * x[n]

# Plot the original noisy signal and the filtered signal
plt.figure(figsize=(12, 6))

# Plot the noisy input signal
plt.subplot(2, 1, 1)
plt.plot(t, x, label='Noisy Signal', color='orange')
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.title('Input Signal (Noisy)')
plt.legend()
plt.grid(True)

# Plot the filtered output signal
plt.subplot(2, 1, 2)
plt.plot(t, y, label='Filtered Signal (Low-Pass)', color='blue')
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.title('Output Signal (Filtered)')
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()
