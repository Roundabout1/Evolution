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
time1 = test_path + '/time1.txt'
time2 = test_path + '/time2.txt'

def read_results(results_file):
    f = open(results_file)
    results_string = np.array(f.read().split())
    f.close()
    return results_string.astype(np.float)

f = open(num_points)
points_string = np.array(f.read().split())
f.close()
points_int = points_string.astype(np.int)

results1 = read_results(time1)
results2 = read_results(time2)

plt.xlabel('Количество точек')
plt.ylabel('Время выполнения программы в мс')
#ax = plt.gca()
#ax.set_xlim([3, 33])
plt.plot(points_int, results1, label='Первое решение')
plt.plot(points_int, results2, label='Второе решение')
plt.legend()
plt.show()