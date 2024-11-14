import numpy as np
import matplotlib.pyplot as plt
import math


a = 10
f = 1000
fs = 3000
d = np.pi*5/3
t = np.linspace(0,0.005,fs,endpoint=False)

sine_wave = a*np.sin(2*np.pi*f*t+d)
cos_wave = a*np.cos(2*np.pi*f*t+d)

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

def unit_exponential_step(a,n):
    return pow(a,n)

a = (int)
x_values = [i for i in range(-30,31)]
u_values = [unit(x) for x in x_values]
us_values = [unit_step(x) for x in x_values]
ur_values = [unit_ramp(x) for x in x_values]
n_values = [i for i in range(-5,5)]
ue_values = [unit_exponential_step(-2,n) for n in n_values]

plt.figure(figsize=(18,9))

#Unit functio
plt.subplot(3,2,1)
plt.step(x_values,u_values,where='post',label='Unit function',color='red')
plt.title("Unit Function")
plt.xlabel('x')
plt.ylabel('unit(x)')
plt.axhline(0,color='blue',linewidth = 0.5)
plt.axvline(0,color='blue',linewidth = 0.5)
plt.grid(True)

#Unit Step function
plt.subplot(3,2,2)
plt.step(x_values,us_values,where='post',label='Unit step function',color='red')
plt.title("Unit Step Function")
plt.xlabel('x')
plt.ylabel('unit_step(x)')
plt.axhline(0,color='blue',linewidth = 0.5)
plt.axvline(0,color='blue',linewidth = 0.5)
plt.grid(True)

#Unit Ramp function
plt.subplot(3,2,3)
plt.step(x_values,ur_values,where='post',label='Unit ramp function',color='red')
plt.title("Unit Ramp Function")
plt.xlabel('x')
plt.ylabel('unit_ramp(x)')
plt.axhline(0,color='blue',linewidth = 0.5)
plt.axvline(0,color='blue',linewidth = 0.5)
plt.grid(True)

#Exponential function
plt.subplot(3,2,4)
plt.step(n_values,ue_values,where='post',label='Unit exponential function',color='red')
plt.title("UnitExponential  Function")
plt.xlabel('n')
plt.ylabel('unit_exponential_step(x)')
plt.axhline(0,color='blue',linewidth = 0.5)
plt.axvline(0,color='blue',linewidth = 0.5)
plt.grid(True)


#Sine Wave
plt.subplot(3,2,5)
plt.plot(t,sine_wave,color='red')
plt.title("Sine wave")
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.axhline(0,color='blue',linewidth = 0.5)
plt.axvline(0,color='blue',linewidth = 0.5)
plt.grid(True)

#Cosine Waveform
plt.subplot(3,2,6)
plt.plot(t,cos_wave,color='red')
plt.title("Cosine wave")
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.axhline(0,color='blue',linewidth = 0.5)
plt.axvline(0,color='blue',linewidth = 0.5)
plt.grid(True)

plt.legend()
plt.show()