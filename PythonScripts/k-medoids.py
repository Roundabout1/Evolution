import math
from sklearn_extra.cluster import KMedoids
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
print(points)
tries = 1

best_labels = ""
best_inertia = -1.0
for i in range(tries):
    kmedoids = KMedoids(
        n_clusters=k,
        metric='manhattan',
        init='k-medoids++',
        max_iter=2*k
    )
    kmedoids.fit(points)
    labels = np.array2string(kmedoids.labels_)
    inertia = kmedoids.inertia_
    if(best_labels == "" or inertia < best_inertia):
        best_labels = labels
        best_inertia = inertia
with open("../cmake-build-debug/data/input/k-labelsPy.txt", "w") as external_file:
    print(best_labels[1:-1], file=external_file)
    external_file.close()
centers = kmedoids.cluster_centers_
centers_str = ''
for i in range(k):
    centers_str += str(centers[i][0]) + ' ' + str(centers[i][1]) + '\n'
with open("../cmake-build-debug/data/input/k-centersPy.txt", "w") as external_file:
    print(centers_str, file=external_file)
    external_file.close()
