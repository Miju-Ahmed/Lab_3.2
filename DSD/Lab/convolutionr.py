import matplotlib.pyplot as plt
import numpy as np

def convolution(x,h):
    y = [0]*(len(x)+len(h)-1)
    for n in range(len(y)):
        for l in range(len(x)):
            if 0<=n-l<len(h):
                y[n] += x[l]*h[n-l]

    return y

x = [1, 2, 3, 4, 5]
h = [1, 2, 3]

y = convolution(x, h)
print(y)

plt.stem(range(len(y)), y)
plt.xlabel('n')
plt.ylabel('y[n]')
plt.title('Convolution of x[n] and h[n]')
plt.grid(True)
plt.show()