import matplotlib.pyplot as plt
import numpy as np
import math

x = []
N = int(input("Enter the number of values: "))
print("Enter the value: ")
for i in range(N):
    x.append(float(input()))
R = []
for n in range(N):
    s=0
    for l in range(N-n):
        s += x[n]*x[n+l]
    R.append(s)


plt.figure(figsize=(10,5))
plt.stem(range(N), R)
plt.xlabel('Lag l')
plt.ylabel('Autocorrelation R_x[k]')
plt.title('Autocorrelation of Signal x[n]')
plt.grid(True)
plt.show()