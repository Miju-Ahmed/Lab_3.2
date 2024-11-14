import numpy as np
import matplotlib.pyplot as plt


def unit(x):
    if x==0:
        return 1
    else:
        return 0

def step(x):
    if x<0:
        return 0
    else:
        return 1
    
def ramp(x):
    if x<0:
        return 0
    else:
        return x
    
def exp(a,x):
    return pow(a,x)

x_value = [i for i in range(-20,21)]
u_value = [unit(x) for x in x_value]
s_value = [step(x) for x in x_value]
r_value = [ramp(x) for x in x_value]
n_value = [i for i in range(-3,4)]
e_value = [exp(-3,x) for x in n_value]

plt.figure(figsize=(16,10))

plt.subplot(2,2,1)
plt.step(x_value,u_value)
plt.title("Unit function")
plt.xlabel('x')
plt.ylabel('u(x)')
plt.grid(True)
plt.axhline(0,color='black', linewidth=0.5)
plt.axvline(0,color='black', linewidth=0.5)

plt.subplot(2,2,2)
plt.step(x_value,s_value)
plt.title("Unit step function")
plt.xlabel('x')
plt.ylabel('u(x)')
plt.grid(True)
plt.axhline(0,color='black', linewidth=0.5)
plt.axvline(0,color='black', linewidth=0.5)

plt.subplot(2,2,3)
plt.step(x_value,r_value)
plt.title("Unit ramp function")
plt.xlabel('x')
plt.ylabel('u(x)')
plt.grid(True)
plt.axhline(0,color='black', linewidth=0.5)
plt.axvline(0,color='black', linewidth=0.5)

plt.subplot(2,2,4)
plt.step(n_value,e_value)
plt.title("Unit exponential function")
plt.xlabel('n')
plt.ylabel('u(x)')
plt.grid(True)
plt.axhline(0,color='black', linewidth=0.5)
plt.axvline(0,color='black', linewidth=0.5)

plt.show()