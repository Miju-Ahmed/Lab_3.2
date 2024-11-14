import numpy as np
import matplotlib.pyplot as plt
import cmath

def H(s):
    return 1/(1-s*s+2*s)

omega = np.linspace(0,100,5000)
s = -3 - 3j*omega

H_jw = H(s)

magnitude = [abs(value) for value in H_jw]
phase = [cmath.phase(value) for value in H_jw]

plt.figure(figsize=(12, 5))

plt.subplot(1, 2, 1)
plt.plot(omega, magnitude)
plt.xlabel('Frequency (rad/s)')
plt.ylabel('|H(jω)|')
plt.title('Magnitude Response')
plt.grid(True)

# Plotting the phase response
plt.subplot(1, 2, 2)
plt.plot(omega, phase)
plt.xlabel('Frequency (rad/s)')
plt.ylabel('Phase (radians)')
plt.title('Phase Response')
plt.grid(True)

plt.tight_layout()
plt.show()