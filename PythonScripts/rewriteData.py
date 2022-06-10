f = open('../cmake-build-debug/data/input/tsplib.txt', 'r')
coordinates = [float(x) for x in f.read().split()]
f.close()
form = ''
for i in range (len(coordinates)):
    if(i%3 != 0):
        form += str(coordinates[i]) + ' '
with open("../cmake-build-debug/data/input/points.txt", "w") as external_file:
    print(form, file=external_file)
external_file.close()
