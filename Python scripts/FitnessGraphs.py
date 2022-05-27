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
generations = f.read().split()[2]
f.close()
for i in range(1, int(generations)):
    f = open(generation_folder + str(i) + '/' + fitness_stats_file, 'r')
    stats = f.read().split()
    mn.append(stats[0])
    mx.append(stats[1])
    avg.append(stats[2])

vertical = 3
horizontal = 1

plt.subplot(vertical, horizontal, 1).yaxis.set_major_locator(ticker.MultipleLocator(3))
plt.plot(mn,  color='blue')
plt.subplot(vertical, horizontal, 2).yaxis.set_major_locator(ticker.MultipleLocator(3))
plt.plot(mx, color='red')
plt.subplot(vertical, horizontal, 3).yaxis.set_major_locator(ticker.MultipleLocator(5))
plt.plot(avg, color='green')
plt.show()