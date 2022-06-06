cmake_minimum_required(VERSION 3.22)
project(EvolutionAlgorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(first_solution src/Solutions/Genetic/First/first_g.cpp src/Gene/Gene.cpp src/Gene/Gene.h src/Other/Point.cpp
        src/Other/Point.h src/Random/Random.cpp src/Random/Random.h src/Initialization/Init.cpp src/Initialization/Init.h
        src/Termination/Terminator.cpp src/Termination/Terminator.h src/Mutation/MutationOfPopulation.cpp src/Mutation/Mutation.h
        src/Crossover/Crossover.cpp src/Crossover/Crossover.h src/Selection/Selection.cpp src/Selection/Selection.h
        src/Fitness/FitnessOfGenome.cpp src/Fitness/Fitness.h src/Mutation/MutationOfGenome.cpp src/Fitness/FitnessOfPopulation.cpp
        src/Fix/FixGenome.cpp src/Fix/Fix.h src/Fix/FixPopulation.cpp src/Fitness/Euclidean.cpp src/Fitness/Manhattan.cpp
        src/Pathes.h src/Solutions/Auxiliary/Prints.cpp src/Solutions/Auxiliary/Prints.h
        src/Solutions/Auxiliary/ReadData.cpp src/Solutions/Auxiliary/ReadData.h
        src/Solutions/Auxiliary/Stat.cpp src/Solutions/Auxiliary/Stat.h src/Solutions/Auxiliary/Other.cpp
        src/Solutions/Auxiliary/Other.h src/Other/FileOperations.cpp
        src/Other/FileOperations.h src/Solutions/Genetic/First/first_evolution.cpp src/Solutions/Genetic/First/first_evolution.h
        src/Solutions/Non-genetic/nearest.cpp src/Solutions/Non-genetic/nearest.h
        src/Other/PopulationSort.cpp src/Other/PopulationSort.h src/Other/Roulette.cpp src/Other/Roulette.h src/Other/DoubleOperations.cpp src/Other/DoubleOperations.h)
add_executable(second_solution src/Gene/Gene.cpp src/Gene/Gene.h src/Other/Point.cpp src/Other/Point.h src/Random/Random.cpp
        src/Random/Random.h src/Initialization/Init.cpp src/Initialization/Init.h src/Termination/Terminator.cpp
        src/Termination/Terminator.h src/Mutation/MutationOfPopulation.cpp src/Mutation/Mutation.h src/Crossover/Crossover.cpp
        src/Crossover/Crossover.h src/Selection/Selection.cpp src/Selection/Selection.h src/Fitness/FitnessOfGenome.cpp
        src/Fitness/Fitness.h src/Mutation/MutationOfGenome.cpp src/Fitness/FitnessOfPopulation.cpp src/Fix/FixGenome.cpp
        src/Fix/Fix.h src/Fix/FixPopulation.cpp src/Fitness/Euclidean.cpp src/Fitness/Manhattan.cpp src/Pathes.h
        src/Solutions/Auxiliary/Prints.cpp src/Solutions/Auxiliary/Prints.h src/Solutions/Auxiliary/ReadData.cpp
        src/Solutions/Auxiliary/ReadData.h src/Solutions/Auxiliary/Stat.cpp src/Solutions/Auxiliary/Stat.h
        src/Solutions/Genetic/Second/second_g.cpp src/Solutions/Auxiliary/Other.cpp src/Solutions/Auxiliary/Other.h
        src/Other/FileOperations.cpp src/Other/FileOperations.h src/Solutions/Genetic/Second/second_evolution.cpp
        src/Solutions/Genetic/Second/second_evolution.h src/Solutions/Non-genetic/nearest.cpp src/Solutions/Non-genetic/nearest.h src/Other/PopulationSort.cpp src/Other/PopulationSort.h src/Solutions/Genetic/Third/third_evolution.cpp src/Solutions/Genetic/Third/third_evolution.h src/Other/Roulette.cpp src/Other/Roulette.h src/Other/DoubleOperations.cpp src/Other/DoubleOperations.h)
add_executable(First_generator src/InputGenerator/first_generator.cpp src/Random/Random.cpp src/Random/Random.h)
add_executable(Test src/Test.cpp src/Gene/Gene.cpp src/Gene/Gene.h src/Other/Point.cpp src/Other/Point.h src/Random/Random.cpp src/Random/Random.h src/Initialization/Init.cpp src/Initialization/Init.h src/Termination/Terminator.cpp src/Termination/Terminator.h src/Mutation/MutationOfPopulation.cpp src/Mutation/Mutation.h src/Crossover/Crossover.cpp src/Crossover/Crossover.h src/Selection/Selection.cpp src/Selection/Selection.h src/Fitness/FitnessOfGenome.cpp src/Fitness/Fitness.h src/Mutation/MutationOfGenome.cpp src/Fitness/FitnessOfPopulation.cpp src/Fix/FixGenome.cpp src/Fix/Fix.h src/Fix/FixPopulation.cpp src/Fitness/Euclidean.cpp src/Fitness/Manhattan.cpp src/Pathes.h src/Solutions/Auxiliary/Prints.cpp src/Solutions/Auxiliary/Prints.h src/Solutions/Auxiliary/ReadData.cpp src/Solutions/Auxiliary/ReadData.h src/Solutions/Auxiliary/Stat.cpp src/Solutions/Auxiliary/Stat.h src/Solutions/Auxiliary/Other.cpp src/Solutions/Auxiliary/Other.h src/Other/FileOperations.cpp src/Other/FileOperations.h src/Solutions/Non-genetic/nearest.h src/Solutions/Non-genetic/nearest.cpp src/Other/PopulationSort.cpp src/Other/PopulationSort.h src/Solutions/Genetic/Third/third_evolution.cpp src/Solutions/Genetic/Third/third_evolution.h src/Other/Roulette.cpp src/Other/Roulette.h src/Other/DoubleOperations.cpp src/Other/DoubleOperations.h)
add_executable(Testing src/Testing/Testing.cpp src/Solutions/Genetic/First/first_evolution.cpp
        src/Solutions/Genetic/First/first_evolution.h src/Solutions/Genetic/Second/second_evolution.cpp
        src/Solutions/Genetic/Second/second_evolution.h
        src/Gene/Gene.cpp src/Gene/Gene.h src/Other/Point.cpp
        src/Other/Point.h src/Random/Random.cpp src/Random/Random.h src/Initialization/Init.cpp src/Initialization/Init.h
        src/Termination/Terminator.cpp src/Termination/Terminator.h src/Mutation/MutationOfPopulation.cpp src/Mutation/Mutation.h
        src/Crossover/Crossover.cpp src/Crossover/Crossover.h src/Selection/Selection.cpp src/Selection/Selection.h
        src/Fitness/FitnessOfGenome.cpp src/Fitness/Fitness.h src/Mutation/MutationOfGenome.cpp src/Fitness/FitnessOfPopulation.cpp
        src/Fix/FixGenome.cpp src/Fix/Fix.h src/Fix/FixPopulation.cpp src/Fitness/Euclidean.cpp src/Fitness/Manhattan.cpp
        src/Pathes.h src/Solutions/Auxiliary/Prints.cpp src/Solutions/Auxiliary/Prints.h
        src/Solutions/Auxiliary/ReadData.cpp src/Solutions/Auxiliary/ReadData.h
        src/Solutions/Auxiliary/Stat.cpp src/Solutions/Auxiliary/Stat.h src/Solutions/Auxiliary/Other.cpp
        src/Solutions/Auxiliary/Other.h src/Other/FileOperations.cpp
        src/Other/FileOperations.h src/InputGenerator/second_generator.h src/Solutions/Non-genetic/nearest.cpp src/Solutions/Non-genetic/nearest.h src/Other/PopulationSort.cpp src/Other/PopulationSort.h src/Solutions/Genetic/Third/third_evolution.cpp src/Solutions/Genetic/Third/third_evolution.h src/Other/Roulette.cpp src/Other/Roulette.h src/Other/DoubleOperations.cpp src/Other/DoubleOperations.h)
add_executable(Main_generator src/InputGenerator/Main_generator.cpp src/InputGenerator/second_generator.h src/InputGenerator/second_generator.cpp src/Random/Random.cpp src/Random/Random.h src/Other/DoubleOperations.cpp src/Other/DoubleOperations.h)
add_executable(TestGenerator src/Random/Random.h src/Random/Random.cpp src/Testing/TestGenerator.cpp src/Pathes.h src/Other/FileOperations.cpp src/Other/FileOperations.h src/InputGenerator/second_generator.h src/InputGenerator/second_generator.cpp src/Other/PopulationSort.cpp src/Other/PopulationSort.h src/Other/DoubleOperations.cpp src/Other/DoubleOperations.h)
add_executable(non-evolution  src/Solutions/Non-genetic/Main-non-evolution.cpp src/Gene/Gene.h src/Gene/Gene.cpp
        src/Fitness/Fitness.h src/Fitness/FitnessOfGenome.cpp src/Fitness/Manhattan.cpp
        src/Pathes.h src/Solutions/Non-genetic/nearest.cpp src/Solutions/Non-genetic/nearest.h src/Other/Point.cpp
        src/Other/Point.h src/Solutions/Auxiliary/Prints.cpp src/Solutions/Auxiliary/Prints.h
        src/Solutions/Auxiliary/ReadData.h src/Solutions/Auxiliary/ReadData.cpp src/Other/PopulationSort.cpp src/Other/PopulationSort.h src/Solutions/Genetic/Third/third_evolution.cpp src/Solutions/Genetic/Third/third_evolution.h src/Other/Roulette.cpp src/Other/Roulette.h src/Other/DoubleOperations.cpp src/Other/DoubleOperations.h)