import matplotlib.pyplot as plt
import numpy as np

x = np.array([1,2,3,4,5])
h = np.array([2,3,4])

plt.subplot(2,2,1)
plt.xlabel("Range")
plt.ylabel('Signal')
plt.stem(np.array([1,2,3,4,5]),x)
plt.grid(True)

plt.subplot(2,2,2)
plt.xlabel("Range")
plt.ylabel("Impulse Signal")
plt.stem(np.array([2,3,4]),h)
plt.grid(True)


#Convolutions Calculations
N = len(x) + len(h) - 1
con_range = []
for i in range(1, N+1):
   con_range.append(i)
y = np.zeros(N)
for n in range(N):
    for k in range(max(0, n - len(h) + 1), min(len(x), n + 1)):
      y[n] += x[k] * h[n - k]
plt.subplot(2,2,3)
plt.stem(np.array(con_range), y)
plt.xlabel("Time")
plt.ylabel("Convolution")
plt.grid(True)


#Correlation Calculations
hr = h[::-1]
cor_range = []
for i in range(1, N+1):
   cor_range.append(i)
yr = np.zeros(N)
for n in range(N):
    for k in range(max(0, n - len(hr) + 1), min(len(x), n + 1)):
      yr[n] += x[k] * hr[n - k]
plt.subplot(2,2,4)
plt.stem(np.array(cor_range), yr)
plt.xlabel("Time")
plt.ylabel("Correlation")
plt.grid(True)

plt.show()
