import matplotlib.pyplot as plt

# Define the unit step function without using any built-in functions
def unit_step(x):
    if x < 0:
        return 0
    else:
        return 1

# Generate values for x from -10 to 10
x_values = [i for i in range(-10, 11)]
y_values = [unit_step(x) for x in x_values]

# Plotting the unit step function
plt.figure(figsize=(10, 4))
plt.step(x_values, y_values, where='post', label='Unit Step Function', color='blue')
plt.xlabel('x')
plt.ylabel('u(x)')
plt.title('Unit Step Function')
plt.grid(True)
plt.axhline(0, color='black',linewidth=0.5)
plt.axvline(0, color='black',linewidth=0.5)
plt.legend()
plt.show()
