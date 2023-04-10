import math
from sklearn.cluster import KMeans
import numpy as np
f = open('../cmake-build-debug/data/input/points.txt', 'r')
coordinates = [float(x) for x in f.read().split()]
points = []
for i in range(0, len(coordinates), 2):
    points.append([coordinates[i], coordinates[i+1]])
f.close()
n = len(points)
k = round(math.sqrt(n)+0.51)
print(k)
kmeans = KMeans(
    init="k-means++",
    n_clusters=k,
    n_init=k,
    max_iter=n,
    algorithm="lloyd"
)
kmeans.fit(points)
labels = np.array2string(kmeans.labels_)
with open("../cmake-build-debug/data/input/k-labelsPy.txt", "w") as external_file:
    print(labels[1:-1], file=external_file)
    external_file.close()

centers = kmeans.cluster_centers_
centers_str = ''
for i in range(k):
    centers_str += str(centers[i][0]) + ' ' + str(centers[i][1]) + '\n'
with open("../cmake-build-debug/data/input/k-centersPy.txt", "w") as external_file:
    print(centers_str, file=external_file)
    external_file.close()


