import matplotlib.pyplot as plt

def unit(x):
    if x==0:
        return 1
    else:
        return 0

x_values = [i for i in range(-20,21)]
y_values = [unit(x) for x in x_values]

plt.figure(figsize=(10,4))
plt.step(x_values,y_values,where='post',label='Unit',color='red')
plt.xlabel('x')
plt.ylabel('u(x)')
plt.title("Unit function")
plt.grid(True)
plt.axhline(0,color='black',linewidth = .5)
plt.axvline(0, color='black', linewidth = .5)
plt.legend()
plt.show()