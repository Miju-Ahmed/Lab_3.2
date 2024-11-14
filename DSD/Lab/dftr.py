import matplotlib.pyplot as plt
import numpy as np
import cmath
import math

a1 = 5
a2 = 7.5
f1 = 6000
f2 = 8000
fs = 20000
d1 = np.pi*5/4
d2 = np.pi*3/4

t = np.linspace(0,0.001,fs,endpoint=False)

signal = a1*np.sin(2*np.pi*f1*t+d1)-a2*np.cos(2*np.pi*f2*t+d2)

x = []
N = int(input("Enter the number of Points: "))
for n in range(N):
    x.append(a1*np.sin(2*np.pi*f1*n/fs+d1)-a2*np.cos(2*np.pi*f2*n/fs+d2))


X = []

for m in range(N):
    a = 0
    b = 0
    for n in range(N):
        angel = -2*math.pi*m*n/N
        a += float("{:.3f}".format(x[n]*np.cos(angel)))
        b += float("{:.3f}".format(x[n]*np.sin(angel)))
    X.append(complex(float("{:.3f}".format(a)), float("{:.3f}".format(b))))


magnitude = [abs(value) for value in X]
phase = [cmath.phase(value) for value in X]

plt.figure(figsize=(18,9))

plt.subplot(2,2,1)
plt.plot(t,signal)
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.grid(True)

plt.subplot(2,2,2)
plt.stem(range(N),x)
plt.xlabel('Points')
plt.ylabel('Amplitude')
plt.grid(True)

plt.subplot(2,2,3)
plt.stem(range(N),magnitude)
plt.xlabel('discrete point')
plt.ylabel('Magnitude')
plt.grid(True)

plt.subplot(2,2,4)
plt.stem(range(N),phase)
plt.xlabel('discrete point')
plt.ylabel('Phase')
plt.grid(True)

plt.show()