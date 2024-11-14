import numpy as np
import matplotlib.pyplot as plt

N = 100
alpha = 0.1

t = np.linspace(0, 2*np.pi, N)
x = np.sin(2*t) + 0.5*np.random.normal(size=N)

plt.figure(figsize=(12,6))
plt.subplot(2, 1, 1)
plt.plot(t, x, label='Noisy Signal', color='orange')
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.title('Input Signal (Noisy)')
plt.legend()
plt.grid(True)


y = np.zeros(N)

y[0] = x[0]

for n in range(1,N):
    y[n] = (1-alpha)*y[n-1] + alpha*x[n]

plt.subplot(2, 1, 2)
plt.plot(t, y, label='Filtered Signal (Low-Pass)', color='blue')
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.title('Output Signal (Filtered)')
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()