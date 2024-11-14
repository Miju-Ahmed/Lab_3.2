import matplotlib.pyplot as plt
import numpy as np


x = [1, 2, 3]
h = [1, -1, 2]

def convolution_sum(x,h):
    y = [0]*(len(x)+len(h)-1)
    for n in range(len(y)):
        for k in range(len(x)):
            if 0<=n-k<len(h):
                y[n] += x[k]*h[n-k]
    return y

y = convolution_sum(x,h)

plt.figure(figsize=(10,6))
plt.stem(range(len(y)), y)
plt.xlabel('n')
plt.ylabel('y[n]')
plt.title('Convolution of x[n] and h[n]')
plt.grid(True)
plt.show()