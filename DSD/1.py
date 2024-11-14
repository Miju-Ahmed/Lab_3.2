
import numpy as np
import matplotlib.pyplot as plt

def unit_step(x):
    """Unit step function."""
    return np.where(x >= 0, 1, 0)

# Example usage
x = np.linspace(-5, 5, 100)  # Range of x values
y = unit_step(x)             # Apply unit step function

# Plotting
plt.plot(x, y)
plt.xlabel('x')
plt.ylabel('u(x)')
plt.title('Unit Step Function')
plt.grid()
plt.show()
