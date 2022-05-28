import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
data_path = '../cmake-build-debug/data'
input_path = data_path + '/input'
points_path = input_path + '/points.txt'
conf_path = input_path + '/conf.txt'
output_path = data_path + '/output'
generation_folder = output_path + '/generation '
best_solution_file = 'best_solution.txt'
fitness_stats_file = 'fitness_stats.txt'
convergence_file = 'convergence.txt'

f = open(conf_path, 'r')
generations = f.read().split()[2]
f.close()
convergece = []
for i in range(1, int(generations)):
    f = open(generation_folder + str(i) + '/' + convergence_file, 'r')
    c = float(f.read().split()[0])
    convergece.append(c)

plt.plot(convergece)
plt.show()