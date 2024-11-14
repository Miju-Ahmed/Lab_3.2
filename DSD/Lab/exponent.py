import matplotlib.pyplot as plt

def expo(x,a):
    return pow(a,x)
a = (int)
x_values = [i for i in range(-10,3)]
y_values = [expo(x,-2) for x in x_values]

plt.figure(figsize=(10,6))
plt.step(x_values,y_values,where='post',label='Exponential',color='green')
plt.xlabel('n')
plt.ylabel('u(n)')
plt.title("Exponential Function")
plt.grid(True)
plt.axhline(0,color='red', linewidth=0.5)
plt.axvline(0,color='red', linewidth=.5)
plt.legend()
plt.show()
