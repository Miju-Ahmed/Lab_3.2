import matplotlib.pyplot as plt

# x = []
# h = []
# a = int(input('Enter the number of x values: '))
# b = int(input('Enter the number of h values: '))
# print("Enter the value of x[]:")
# for i in range(a):
#     x.append(int(input()))

# print("Enter the value of h[]:")
# for i in range(b):
#     h.append(int(input()))

x = [1,2,1.-1]
h = [1,2,3,1]

def convolution(x,h):
    y = [0]*(len(x)+len(h)-1)
    for n in range(len(y)):
        for k in range(len(x)):
            if 0<=n-k<len(h):
                y[n] += x[k] * h[n-k]
    return y

y = convolution(x,h)

plt.figure(figsize=(10,10))
plt.stem(range(len(y)),y)
plt.xlabel('n')
plt.ylabel('y[n]')
plt.title('Convolution sum y[n]=x[n]*h[n]')
plt.grid(True)
plt.show()