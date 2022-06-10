#визуализация входных данных
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

f = open('../cmake-build-debug/data/input/points.txt', 'r')
coordinates = [float(x) for x in f.read().split()]
points = []
for i in range (0, len(coordinates), 2):
    points.append([coordinates[i], coordinates[i+1]])
    plt.scatter(coordinates[i], coordinates[i+1])
print(points)
f.close()
plt.show()