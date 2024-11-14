import numpy as np
import matplotlib.pyplot as plt
import cmath
import math

x = [1,2,1.-1]
h = [1,2,3,1]
y = [0]*(len(x)*len(h)-1)

for i in range(len(x)):
    for j in range(len(h)):
        y[i+j] += x[i]*h[j]



plt.figure(figsize=(10,10))
plt.subplot(1,2,1)
plt.stem(range(len(y)),y)
plt.xlabel('n')
plt.ylabel('y[n]')
plt.title('Convolution sum y[n]=x[n]*h[n]')
plt.grid(True)

h = np.flip(h)
for i in range(len(x)):
    for j in range(len(h)):
        y[i+j] += x[i]*h[j]

plt.subplot(1,2,2)
plt.stem(range(len(y)),y)
plt.xlabel('n')
plt.ylabel('y[n]')
plt.title('Correlation sum y[n]=x[n]*h[n]')
plt.grid(True)
plt.show()