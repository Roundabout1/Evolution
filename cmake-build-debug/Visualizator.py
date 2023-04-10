import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
def print_best_solution(generations):
    f = open('data/output/generation ' + generations + '/best_solution.txt')
    best_solution = [int(x) for x in f.read().split()]
    f.close()
    n = len(best_solution)
    for i in range(n-1):
        p1 = points[best_solution[i]]
        p2 = points[best_solution[i+1]]
        plt.plot([p1[0], p2[0]], [p1[1], p2[1]])
    plt.plot([points[0][0], points[best_solution[n-1]][0]], [points[0][1], points[best_solution[n-1]][1]])


f = open('data/input/points.txt', 'r')
coordinates = [float(x) for x in f.read().split()]

plt.subplot(2, 3, 1)
points = []
for i in range (0, len(coordinates), 2):
    points.append([coordinates[i], coordinates[i+1]])
    plt.scatter(coordinates[i], coordinates[i+1])
print(points)
f.close()

plt.subplot(2, 3, 2)
print_best_solution('1')
f = open('data/input/conf.txt', 'r')
generations = f.read().split()[2]
f.close()
plt.subplot(2, 3, 3)
print_best_solution(generations)

mn = []
mx = []
avg = []
for i in range(1, int(generations)):
    f = open('data/output/generation ' + str(i) + '/fitness_stats.txt', 'r')
    stats = f.read().split()
    mn.append(stats[0])
    mx.append(stats[1])
    avg.append(stats[2])
plt.subplot(2, 3, 4)
plt.plot(mn,  color='blue')
plt.subplot(2, 3, 5).yaxis.set_major_locator(ticker.MultipleLocator(3))
plt.plot(mx, color='red')
plt.subplot(2, 3, 6).yaxis.set_major_locator(ticker.MultipleLocator(5))
plt.plot(avg, color='green')
plt.show()