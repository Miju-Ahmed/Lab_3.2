import numpy as np
import matplotlib.pyplot as plt

# Define signals (replace with your actual data)
x = np.array([1, 2, 3, 4])
h = np.array([1, 0, 2])

# Perform convolution using loop (assuming you want to avoid built-in functions)
def my_convolve(x, h):
  N = len(x) + len(h) - 1
  y = np.zeros(N)
  for n in range(N):
    for k in range(max(0, n - len(h) + 1), min(len(x), n + 1)):
      y[n] += x[k] * h[n - k]
  return y

y = my_convolve(x, h)

# Plot the signals and convolution result
plt.subplot(3, 1, 1)
plt.plot(x, label='Input Signal (x)')
plt.legend()
plt.grid(True)

plt.subplot(3, 1, 2)
plt.plot(h, label='Impulse Response (h)')
plt.legend()
plt.grid(True)

plt.subplot(3, 1, 3)
plt.plot(y, label='Convolution Output (y)')
plt.legend()
plt.grid(True)
plt.xlabel('Time')

plt.tight_layout()
plt.show()
