import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

f = open('data/input/points.txt', 'r')
coordinates = [float(x) for x in f.read().split()]

plt.subplot(2, 3, 1)
points = []
for i in range (0, len(coordinates), 2):
    points.append([coordinates[i], coordinates[i+1]])
    plt.scatter(coordinates[i], coordinates[i+1])
print(points)
f.close()
plt.show()