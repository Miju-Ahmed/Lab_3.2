import matplotlib.pyplot as plt
import numpy as np
import math
import cmath

a1 = 5
a2 = 0.5
f1 = 1000
f2 = 6000
fs = 12000
d1 = np.pi*3/4
d2 = np.pi*5/3

t = np.linspace(0,0.005,fs, endpoint=False)

signal = a1*np.sin(2*np.pi*f1*t+d1)+a2*np.cos(2*np.pi*f2*t+d2)

plt.figure(figsize=(18,9))
plt.subplot(2,2,1)
plt.plot(t,signal)
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.title('Composite Signal')
plt.grid(True)


x = []
N = int(input("Enter the point number: "))

for n in range(N):
    r = a1*np.sin(2*np.pi*f1*n/fs+d1)+a2*np.cos(2*np.pi*f2*n/fs+d2)
    x.append(r)
print(x)
plt.subplot(2,2,2)
plt.stem(range(len(x)),x)
plt.xlabel('Discrete Value')
plt.ylabel('Amplitude')
plt.title('Discrete Signal')
plt.grid(True)


X = []

for m in range(N):
    a=0
    b=0
    for n in range(N):
        angel = -2*math.pi*m*n/N
        a += float("{:.3f}".format(x[n]*np.cos(angel)))
        b += float("{:.3f}".format(x[n]*np.sin(angel)))
    X.append(complex(float("{:.3f}".format(a)),float("{:.3f}".format(b))))
print(X)

magnitude = [abs(value) for value in X]
phase = [cmath.phase(value) for value in x]

plt.subplot(2,2,3)
plt.stem(range(N),magnitude)
plt.xlabel('Point')
plt.ylabel('Magnitude')
plt.title('Magnitude')
plt.grid(True)

plt.subplot(2,2,4)
plt.stem(range(N),phase)
plt.xlabel('Point')
plt.ylabel('Phase')
plt.title('Phase')
plt.grid(True)

plt.show()