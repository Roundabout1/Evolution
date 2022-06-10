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
'''
kmedoids = KMedoids(
        n_clusters=k,
        metric='manhattan',
        method='pam',
        init='k-medoids++',
        max_iter=2*k
    )
'''
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
    print(kmedoids.n_iter_)
    print(inertia)
print(best_inertia)
with open("../cmake-build-debug/data/input/k-medoidsPy.txt", "w") as external_file:
    print(best_labels[1:-1], file=external_file)
    external_file.close()