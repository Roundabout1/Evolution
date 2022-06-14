import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import numpy as np
data_path = '../cmake-build-debug/data'
input_path = data_path + '/input'
points_path = input_path + '/points.txt'
conf_path = input_path + '/conf.txt'
output_path = data_path + '/output'
generation_folder = output_path + '/generation '
best_solution_file = 'best_solution.txt'
fitness_stats_file = 'fitness_stats.txt'
convergence_file = 'convergence.txt'
test_path = data_path + '/tests'

num_points = test_path + '/num_points.txt'
results_file0 = test_path + '/results0.txt'
results_file1 = test_path + '/results1.txt'
results_file2 = test_path + '/results2.txt'

def read_results(results_file):
    f = open(results_file)
    results_string = np.array(f.read().split())
    f.close()
    return results_string.astype(np.float)

f = open(num_points)
points_string = np.array(f.read().split())
f.close()
points_int = points_string.astype(np.int)

results0 = read_results(results_file0)
results1 = read_results(results_file1)
#results2 = read_results(results_file2)

plt.xlabel('Количество точек')
plt.ylabel('Результат')
#ax = plt.gca()
#ax.set_xlim([3, 33])
plt.plot(points_int, results0, label='Точка разрыва')
plt.plot(points_int, results1, label='Коллизия')
#plt.plot(points_int, results1, label='ГА с новой инициализацией')
mn = 100.0
mx = 0.0
mean = 0.0
l = len(results1)
for i in range(0, len(results0)):
    p = (results0[i] - results1[i])/(results0[i]*0.01)
    mn = min(mn, p)
    mx = max(mx, p)
    mean += p
mean /= l
print("1: min = ", mn, "max = ", mx, "mean = ", mean)
'''
mn = 100.0
mx = 0.0
mean = 0.0
l = len(results0)
for i in range(0, len(results0)):
    p = (results0[i] - results2[i])/(results0[i]*0.01)
    mn = min(mn, p)
    mx = max(mx, p)
    mean += p
mean /= l
print("2: min = ", mn, "max = ", mx, "mean = ", mean)
'''
plt.legend()
plt.show()