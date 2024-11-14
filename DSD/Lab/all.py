import numpy as np
import matplotlib.pyplot as plt
import cmath
import math

def unit(x):
    if x==0:
        return 1
    else:
        return 0
def unit_step(x):
    if x<0:
        return 0
    else:
        return 1
def unit_ramp(x):
    if x<0:
        return 0
    else:
        return x
def unit_exp(a,n):
    return pow(a,n)

a = 5
f = 1000
fs = 2000
t = np.linspace(0,0.1,fs)
sine_wave = a*np.sin(2*np.pif*t)
cos_wave = a*np.cos(2*np.pi*f*t)

def convolution_sum(x,h):
    y = [0]*(len(x)+len(h)-1)
    for n in range(len(y)):
        for k in range(len(x)):
            if 0<=n-k<len(h):
                y[n] += x[k]*h[n-k]
    return y

def autocorrelation(x):
    R = []
    for n in range(len(x)):
        s = 0
        for l in range(len(x)-n):
            s += x[l]*x[l+n]
        R.append(s)
    return R

def discrete(signal):  
    x = []
    N = 10
    for n in range(N):
        x.append(a*np.sin(2*np.pi*f*n/fs)+a*np.cos(2*np.pi*f*n/fs))
    return x

def dft(x):
    X = []
    N = len(x)
    for m in range(N):
        r = 0
        i = 0
        for n in range(N):
            angel = -2*math.pi*m*n/N
            r += float("{:.3f}".format(x[n]*np.cos(angel)))
            i += float("{:.3f}".format(x[n]*np.cos(angel)))
        X.append(complex(float("{:.3f}".format(r)),float("{:.3f}".format(i))))
    magnitude = [abs(value) for value in X]
    phase = [cmath.phase(value) for value in X]


def H(s):
    return 1/(1-s)
w = np.linspace(0,20,5000)
s = 3-2j*w
H_jw = H(s)


def idft(X):
    x = []
    N = len(X)
    for n in range(N):
        sum = 0
        for m in range(N):
            angel = 2*math.pi*m*n/N
            sum += X[m]*cmath.exp(1j*angel)
        x.append(sum/N)
    real_part = [value.real for value in x]
    imag_part = [value.imag for value in x]
    return x


def correlation(x,h):
    h = np.flip(h)
    cs = [0]*(len(x)+len(h)-1)

    for i in range(len(x)):
        for j in range(len(h)):
            cs[i+j] += x[i]*h[j]
    return cs
