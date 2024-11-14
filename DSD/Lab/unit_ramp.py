import matplotlib.pyplot as plt

def unit_ramp(x):
    if x<0:
        return 0
    else:
        return x
    
x_values = [i for i in range(-15,40)]
y_values = [unit_ramp(x) for x in x_values]


plt.figure(figsize=(10,4))
plt.step(x_values,y_values,where='post',label='Unit Ramp',color='red')
plt.title("Unit Ramp Function")
plt.xlabel('x')
plt.ylabel('u(x)')
plt.grid(True)
plt.axhline(0,color='black',linewidth=.5)
plt.axvline(0, color='black', linewidth=.5)
plt.legend()
plt.show()