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

mn = []
mx = []
avg = []
f = open(conf_path, 'r')
generations = f.read().split()[1]
f.close()
for i in range(1, int(generations)):
    f = open(generation_folder + str(i) + '/' + fitness_stats_file, 'r')
    stats = f.read().split()
    mn.append(float(stats[0]))
    mx.append(float(stats[1]))
    avg.append(float(stats[2]))

vertical = 3
horizontal = 1

plt.xlabel('Поколение')
plt.ylabel('Расстояние')
plt.plot(mn,  color='blue', label='Лучший результат')
plt.plot(mx, color='red', label='Худший результат')
plt.plot(avg, color='green', label='Средний результат')
plt.legend()
plt.show()