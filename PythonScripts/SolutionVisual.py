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
solution_file = output_path + '/solution.txt'
fitness_value_file = output_path + '/fitness_value.txt'

def print_solution(file_name):
    f = open(file_name)
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

f = open(points_path, 'r')
coordinates = [float(x) for x in f.read().split()]
f.close()

points = []
for i in range (0, len(coordinates), 2):
    points.append([coordinates[i], coordinates[i+1]])

vertical = 1
horizontal = 1
f = open(fitness_value_file)
length = f.read()
f.close()
plt.title('Расстояние = ' + length)
print_solution(solution_file)
plt.show()