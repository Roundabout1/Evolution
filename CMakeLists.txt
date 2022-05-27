cmake_minimum_required(VERSION 3.22)
project(EvolutionAlgorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(EvolutionAlgorithm src/Solutions/Genetic/first_g.cpp src/Gene/Gene.cpp src/Gene/Gene.h src/Other/Point.cpp src/Other/Point.h src/Random/Random.cpp src/Random/Random.h src/Initialization/Init.cpp src/Initialization/Init.h src/Termination/Terminator.cpp src/Termination/Terminator.h src/Mutation/MutationOfPopulation.cpp src/Mutation/Mutation.h src/Crossover/Crossover.cpp src/Crossover/Crossover.h src/Selection/Selection.cpp src/Selection/Selection.h src/Fitness/FitnessOfGenome.cpp src/Fitness/Fitness.h src/Mutation/MutationOfGenome.cpp src/Fitness/FitnessOfPopulation.cpp src/Fix/FixGenome.cpp src/Fix/Fix.h src/Fix/FixPopulation.cpp src/Fitness/Euclidean.cpp src/Fitness/Manhattan.cpp src/Solutions/Genetic/Pathes.h src/Solutions/Genetic/Prints.cpp src/Solutions/Genetic/Prints.h src/Solutions/Genetic/ReadData.cpp src/Solutions/Genetic/ReadData.h src/Solutions/Genetic/Stat.cpp src/Solutions/Genetic/Stat.h)
add_executable(First_generator src/InputGenerator/First_generator.cpp src/Random/Random.cpp src/Random/Random.h)
add_executable(Second_generator src/InputGenerator/Second_generator.cpp src/Random/Random.cpp src/Random/Random.h)
add_executable(Test src/Test.cpp)
