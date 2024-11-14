import numpy as np
import matplotlib.pyplot as plt
import cmath
import math

a1 = 1
a2 = 0.5
f1 = 1000
f2 = 2000
fs = 8000
# d1 = np.pi*5/3
d1 = 0
d2 = np.pi*3/4
N = int(input("DFT point number: "))


t = np.linspace(0,0.005,fs,endpoint=False)
signal = a1*np.sin(2*np.pi*f1*t+d1) + a2*np.cos(2*np.pi*f2*t+d2)


plt.figure(figsize=(18,9))
plt.subplot(2,2,1)
plt.plot(t,signal)
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.title("Input signal")
plt.grid(True)



x = []
for n in range(N):
    v = a1*np.sin(2*np.pi*f1*n/fs+d1) + a2*np.sin(2*np.pi*f2*n/fs+d2)
    x.append(v)
# print(x)
plt.subplot(2,2,2)
plt.title("Discrete Value Analysis")
plt.stem(range(len(x)),x)
plt.xlabel('Discrete value')
plt.ylabel('x[n]')
plt.grid(True)



# def DFT(x):
#     X = []
#     for m in range(N):
#         sum_value = 0
#         for n in range(N):
#             angel = -2j * cmath.pi*m*n/N
#             sum_value += x[n]*cmath.exp(angel)
#         X.append(sum_value)
#     return X
# X = DFT(x)

# print(X)



def dft(x):
    Y = []
    for m in range(N):
        a=0
        b=0
        for n in range(N):
            angel = -2*math.pi*m*n/N
            a += float("{:.3f}".format(x[n]*np.cos(angel)))
            b += float("{:.3f}".format(x[n]*np.sin(angel)))
        Y.append(complex(float("{:.3f}".format(a)),float("{:.3f}".format(b))))

    return Y

Y = dft(x)
print(Y)


magnitude = [abs(value) for value in Y]
phase = [cmath.phase(value) for value in Y]


plt.subplot(2,2,3)
plt.title("Magnitude")
plt.stem(range(N), magnitude, label="Magnitude")
plt.xlabel("Discrete value")
plt.ylabel("Magnitude")
plt.grid(True)


plt.subplot(2,2,4)
plt.title("Phase")
plt.stem(range(N), phase, label="Phase")
plt.xlabel("Discrete value")
plt.ylabel("Phase")
plt.grid(True)


plt.tight_layout()
plt.show()