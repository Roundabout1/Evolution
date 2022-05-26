cmake_minimum_required(VERSION 3.22)
project(EvolutionAlgorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(EvolutionAlgorithm src/Solutions/Genetic/first_g.cpp src/Gene/Gene.cpp src/Gene/Gene.h src/Other/Point.cpp src/Other/Point.h src/Random/Random.cpp src/Random/Random.h src/Initialization/Init.cpp src/Initialization/Init.h src/Termination/Terminator.cpp src/Termination/Terminator.h src/Mutation/MutationOfPopulation.cpp src/Mutation/Mutation.h src/Crossover/Crossover.cpp src/Crossover/Crossover.h src/Selection/Selection.cpp src/Selection/Selection.h src/Fitness/Euclidean.cpp src/Fitness/Fitness.h src/Mutation/MutationOfGenome.cpp src/Fitness/FitnessOfPopulation.cpp src/Fix/FixGenome.cpp src/Fix/Fix.h src/Fix/FixPopulation.cpp)
add_executable(Generator src/InputGenerator/Generator.cpp src/Random/Random.cpp src/Random/Random.h)
