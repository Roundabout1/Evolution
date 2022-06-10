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
    n_init=2*k,
    max_iter=2*n,
    algorithm="lloyd"
)
kmeans.fit(points)
labels = np.array2string(kmeans.labels_)
print(points)
print(labels)
print(kmeans.n_iter_)
print(kmeans.inertia_)
with open("../cmake-build-debug/data/input/k-meansPy.txt", "w") as external_file:
    print(labels[1:-1], file=external_file)
    external_file.close()



