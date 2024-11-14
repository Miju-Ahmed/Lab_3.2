# #Sampling and Showing
# import numpy as np
# import matplotlib.pyplot as plt

# sampling_rate = 1010
# duration = 0.01
# frequency = 500
# phase  = 90
# amplitude = 5

# t = np.linspace(0, duration, int(sampling_rate), endpoint=False)

# sine_wave = amplitude * np.sin(2*np.pi*frequency*t + phase)

# plt.figure(figsize=(15,5))
# plt.plot(t,sine_wave)
# plt.title("Sine Wave")
# plt.xlabel("Time (seconds)")
# plt.ylabel("Amplitude (Hz)")

# plt.grid(True)
# plt.show()


# #Time Shifting
# import numpy as np
# import matplotlib.pyplot as plt

# sampling_rate = 1010
# duration = 0.01
# frequency = 500
# phase  = 90
# amplitude = 5

# t = np.linspace(0, duration, int(sampling_rate), endpoint=False)

# sine_wave = amplitude * np.sin(2*np.pi*frequency*t + phase)

# plt.figure(figsize=(15,5))
# plt.plot(t+0.00134,sine_wave)
# plt.title("Sine Wave")
# plt.xlabel("Time (seconds)")
# plt.ylabel("Amplitude (Hz)")

# plt.grid(True)
# plt.show()


# #Sampling UP/Down
# import numpy as np
# import matplotlib.pyplot as plt

# sampling_rate = 10000
# duration = 0.01
# frequency = 500
# phase  = 90
# amplitude = 5

# t = np.linspace(0, duration, int(sampling_rate), endpoint=False)

# sine_wave = amplitude * np.sin(2*np.pi*frequency*t + phase)

# plt.figure(figsize=(15,5))
# plt.plot(t,sine_wave)
# plt.title("Sine Wave")
# plt.xlabel("Time (seconds)")
# plt.ylabel("Amplitude (Hz)")

# plt.grid(True)
# plt.show()

# #Reverse Sine wave
# import numpy as np
# import matplotlib.pyplot as plt

# sampling_rate = 1000
# duration = 0.01
# frequency = 500
# phase  = 90
# amplitude = 5

# t = np.linspace(0, duration, int(sampling_rate), endpoint=False)
# t_reverse = np.linspace(0,-duration, int(sampling_rate), endpoint=False)

# sine_wave = amplitude * np.sin(2*np.pi*frequency*t + phase)
# #t_reverse = np.flip(t)
# reverse_sine_wave = np.flip(sine_wave)

# plt.figure(figsize=(15,5))
# plt.plot(t,sine_wave, color='red')
# plt.plot(t_reverse,reverse_sine_wave, color='green')
# plt.title("Sine Wave")
# plt.xlabel("Time (seconds)")
# plt.ylabel("Amplitude (Hz)")
# plt.legend()

# plt.grid(True)
# plt.show()

# #Down sampling
# import numpy as np
# import matplotlib.pyplot as plt
# frequency = 500  
# sampling_rate = 1000
# t = np.linspace(0, 0.01, sampling_rate, endpoint=False)
# sine_wave = np.sin(2 * np.pi * frequency * t)

# N = 7

# downsampled_sine_wave = sine_wave[::N]

# plt.figure(figsize=(10, 4))
# plt.plot(t, sine_wave, label='Original Sine Wave')
# plt.stem(t[::N], downsampled_sine_wave, 'r', markerfmt='ro', label='Downsampled Sine Wave')
# plt.xlabel('Time')
# plt.ylabel('Amplitude')
# plt.title('Downsampling Sine Wave')
# plt.legend()
# plt.grid(True)
# plt.show()


import numpy as np
import matplotlib.pyplot as plt

frequency = 500  
sampling_rate = 1000  
t = np.linspace(0, 0.01, sampling_rate, endpoint=False) 
sine_wave = np.sin(2 * np.pi * frequency * t) 


N = 100


upsampled_sine_wave = np.zeros(len(sine_wave) * N)
upsampled_sine_wave[::N] = sine_wave

plt.figure(figsize=(10, 4))
plt.plot(t, sine_wave, label='Original Sine Wave')
plt.plot(np.linspace(0, 0.01, len(upsampled_sine_wave), endpoint=False), upsampled_sine_wave, 'r-', label='Upsampled Sine Wave')
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.title('Upsampling Sine Wave')
plt.legend()
plt.grid(True)
plt.show()







