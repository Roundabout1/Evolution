cmake_minimum_required(VERSION 3.22)
project(EvolutionAlgorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(EvolutionAlgorithm main.cpp Gen.cpp Gen.h Point.cpp Point.h Random.cpp Random.h Init.cpp Init.h Terminator.cpp Terminator.h MutationOfPopulation.cpp Mutation.h Crossover.cpp Crossover.h Selection.cpp Selection.h FitnessOfGenome.cpp Fitness.h MutationOfGenome.cpp FitnessOfPopulation.cpp FixGenome.cpp Fix.h FixPopulation.cpp)
add_executable(Generator generator.cpp Random.cpp Random.h)
