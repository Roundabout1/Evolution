import matplotlib.pyplot as plt
import math
from sklearn.cluster import KMeans
import numpy as np
import seaborn as sns
data_path = '../cmake-build-debug/data'
input_path = data_path + '/input'
points_path = input_path + '/points.txt'
conf_path = input_path + '/conf.txt'
output_path = data_path + '/output'
generation_folder = output_path + '/generation '
best_solution_file = 'best_solution.txt'
fitness_stats_file = 'fitness_stats.txt'
convergence_file = 'convergence.txt'
solution_file = output_path + '/solution.txt'
fitness_value_file = output_path + '/fitness_value.txt'


def showPoints(points):
    for i in range(len(points)):
        plt.scatter(points[i][0], points[i][1])
    plt.show()


def showClusters(points, clusters):
    num_points = len(points)
    num_clusters = max(clusters)+1
    palette = sns.color_palette("hls", n_colors=num_clusters)
    for i in range(num_points):
        plt.scatter(points[i][0], points[i][1], color=palette[clusters[i]])
    plt.show()


def showKmeans(points):
    f = open('../cmake-build-debug/data/input/k-meansPy.txt')
    clusters = [int(x) for x in f.read().split()]
    f.close()
    showClusters(points, clusters)


def showKmedoids(points):
    f = open('../cmake-build-debug/data/input/k-medoidsPy.txt')
    clusters = [int(x) for x in f.read().split()]
    f.close()
    showClusters(points, clusters)


def showSolution(points, vis):
    f = open(solution_file)
    solution = [int(x) for x in f.read().split()]
    f.close()
    f = open(fitness_value_file)
    length = f.read()
    f.close()
    plt.title('Расстояние = ' + length)
    f = open(conf_path)
    isClosed = int(f.read().split()[2])
    f.close()
    if isClosed:
        solution.append(solution[0])
    if vis == 1:
        solutionEuclid(points, solution)
    else:
        solutionManhattan(points, solution)
    plt.show()


def solutionEuclid(points, solution):
    n = len(solution)
    for i in range(n-1):
        p1 = points[solution[i]]
        p2 = points[solution[i+1]]
        plt.plot([p1[0], p2[0]], [p1[1], p2[1]])
        plt.scatter(p1[0], p1[1])
        plt.scatter(p2[0], p2[1])


def solutionManhattan(points, solution):
    n = len(solution)
    for i in range(n-1):
        p1 = points[solution[i]]
        p2 = points[solution[i+1]]
        p = (p1[0], p2[1])
        plt.plot([p1[0], p[0], p2[0]], [p1[1], p[1], p2[1]])
        plt.scatter(p1[0], p1[1])
        plt.scatter(p2[0], p2[1])


def readGenerations():
    f = open(conf_path, 'r')
    generations = f.read().split()[1]
    f.close()
    return generations


def showFitness():
    mn = []
    mx = []
    avg = []
    generations = readGenerations()
    for i in range(1, int(generations)):
        f = open(generation_folder + str(i) + '/' + fitness_stats_file, 'r')
        stats = f.read().split()
        mn.append(float(stats[0]))
        mx.append(float(stats[1]))
        avg.append(float(stats[2]))

    plt.xlabel('Поколение')
    plt.ylabel('Расстояние')
    plt.plot(mn,  color='blue', label='Лучший результат')
    plt.plot(mx, color='red', label='Худший результат')
    plt.plot(avg, color='green', label='Средний результат')
    plt.legend()
    plt.show()


def showConvergence():
    generations = readGenerations()
    convergece = []
    for i in range(1, int(generations)):
        f = open(generation_folder + str(i) + '/' + convergence_file, 'r')
        c = float(f.read().split()[0])
        convergece.append(c)
    plt.xlabel('Поколение')
    plt.ylabel('Схожесть')
    plt.plot(convergece)
    plt.show()

#чтение точек
f = open('../cmake-build-debug/data/input/points.txt', 'r')
coordinates = [float(x) for x in f.read().split()]
points = []
for i in range(0, len(coordinates), 2):
    points.append([coordinates[i], coordinates[i+1]])
f.close()

#чтение значения функции приспособленности

#showPoints(points)
#showKmeans(points)
#showKmedoids(points)
showSolution(points, 1)
#showFitness()
#showConvergence()
