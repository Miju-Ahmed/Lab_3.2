import numpy as np
import matplotlib.pyplot as plt

# Define the system function H(s) = 1 / (s + 1)
def H(s):
    return 1 / (s + 1)

# Frequency range (omega values) from 0 to 10 rad/s
omega = np.linspace(0, 10, 500)
s = 1j * omega  # Substitute s = j * omega

# Calculate H(j*omega) for each frequency
H_jw = H(s)

# Compute magnitude and phase responses
magnitude = np.abs(H_jw)
phase = np.angle(H_jw)

# Plotting the magnitude response
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
