#визуализация входных данных и решений
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
data_path = '../cmake-build-debug/data'
input_path = data_path + '/input'
points_path = input_path + '/points.txt'
conf_path = input_path + '/conf.txt'
output_path = data_path + '/output'
generation_folder = output_path + '/generation '
best_solution_file = 'best_solution.txt'

def print_solution(generations):
    f = open(generation_folder + generations + '/' + best_solution_file)
    best_solution = [int(x) for x in f.read().split()]
    f.close()
    n = len(best_solution)
    for i in range(n-1):
        p1 = points[best_solution[i]]
        p2 = points[best_solution[i+1]]
        p = (p1[0], p2[1])
        plt.plot([p1[0], p[0], p2[0]], [p1[1], p[1], p2[1]])
        plt.scatter(p1[0], p1[1])
        plt.scatter(p2[0], p2[1])
    #plt.plot([points[0][0], points[best_solution[n-1]][0]], [points[0][1], points[best_solution[n-1]][1]])

f = open(points_path, 'r')
coordinates = [float(x) for x in f.read().split()]
f.close()

points = []
for i in range (0, len(coordinates), 2):
    points.append([coordinates[i], coordinates[i+1]])

vertical = 1
horizontal = 1
'''
plt.subplot(vertical, horizontal, 1)
print_solution('1')
'''
f = open(conf_path, 'r')
generations = f.read().split()[2]
f.close()

plt.subplot(vertical, horizontal, 1)
print_solution(generations)
plt.show()