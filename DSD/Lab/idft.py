import matplotlib.pyplot as plt
import cmath
import numpy as np
import math

X = [4, -1 + 1j, 0, -1 - 1j]
x = []

N = len(X)
for n in range(N):
    sum = 0
    for m in range(N):
        angel = 2*math.pi*m*n/N
        sum += X[m]*cmath.exp(1j*angel)
    # x.append(float("{:.3f}".format(sum/N)))
    x.append(sum/N)

print(x)
real_part = [value.real for value in x]
imag_part = [value.imag for value in x]
print(real_part)