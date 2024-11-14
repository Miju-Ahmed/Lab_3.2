import matplotlib.pyplot as plt

# Define the input signals
x = [1, 2, 3]
h = [1, -1, 2]

# Perform the convolution sum manually
def convolution_sum(x, h):
    # Output length is len(x) + len(h) - 1
    y = [0] * (len(x) + len(h) - 1)
    for n in range(len(y)):
        # Sum the products for each position n
        for k in range(len(x)):
            if 0 <= n - k < len(h):
                y[n] += x[k] * h[n - k]
    return y

# Calculate the convolution
y = convolution_sum(x, h)

# Plot the result
plt.stem(range(len(y)), y)
plt.xlabel('n')
plt.ylabel('y[n]')
plt.title('Convolution of x[n] and h[n]')
plt.grid(True)
plt.show()
