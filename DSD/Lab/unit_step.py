import matplotlib.pyplot as plt

def unit_step(x):
    if x<0:
        return 0
    else:
        return 1
    
x_values = [i for i in range(-20,21)]
y_values = [unit_step(x) for x in x_values]

plt.figure(figsize=(10,4))
plt.step(x_values, y_values, where='post', label = 'Unit Function', color = 'green')
plt.xlabel('x')
plt.ylabel('u(x)')
plt.title("Unit Function")
plt.grid(True)
plt.axhline(0,color = 'black', linewidth = .5)
plt.axvline(0, color = 'black', linewidth = .5)
plt.legend()
plt.show()