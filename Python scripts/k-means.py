import matplotlib.pyplot as plt
import seaborn as sns
import math
f = open('../cmake-build-debug/data/input/points.txt', 'r')
coordinates = [float(x) for x in f.read().split()]
points = []
for i in range (0, len(coordinates), 2):
    points.append([coordinates[i], coordinates[i+1]])
f.close()
f = open('../cmake-build-debug/data/clusters.txt')
clusters = [int(x) for x in f.read().split()]
num_points = len(points)
num_clusters = max(clusters)+1
print('\n')
print('nc = ', num_clusters)
palette = sns.color_palette("hls", n_colors=num_clusters)
for i in range(num_points):
    plt.scatter(points[i][0], points[i][1], color=palette[clusters[i]])
plt.show()
