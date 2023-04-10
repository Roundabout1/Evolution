cmake_minimum_required(VERSION 3.22)
project(EvolutionAlgorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(main_genetic src/Gene/GenePoint.cpp src/Gene/GenePoint.h src/Other/Point.cpp src/Other/Point.h src/Random/Random.cpp
        src/Random/Random.h src/Initialization/Init.cpp src/Initialization/Init.h src/Termination/Terminator.cpp
        src/Termination/Terminator.h src/Mutation/MutationOfPopulation.cpp src/Mutation/Mutation.h src/Crossover/Crossover.cpp
        src/Crossover/Crossover.h src/Selection/Selection.cpp src/Selection/Selection.h src/Fitness/FitnessOfGenome.cpp
        src/Fitness/Fitness.h src/Mutation/MutationOfGenome.cpp src/Fitness/FitnessOfPopulation.cpp src/Fix/FixGenome.cpp
        src/Fix/Fix.h src/Fix/FixPopulation.cpp src/Fitness/Distance.cpp src/Pathes.h
        src/Solutions/Auxiliary/Prints.cpp src/Solutions/Auxiliary/Prints.h src/Solutions/Auxiliary/ReadData.cpp
        src/Solutions/Auxiliary/ReadData.h src/Solutions/Auxiliary/Stat.cpp src/Solutions/Auxiliary/Stat.h
        src/Solutions/Genetic/MainGenetic.cpp src/Solutions/Auxiliary/Other.cpp src/Solutions/Auxiliary/Other.h
        src/Other/FileOperations.cpp src/Other/FileOperations.h src/Solutions/Genetic/second_evolution.cpp
        src/Solutions/Non-genetic/nearest.cpp src/Solutions/Non-genetic/nearest.h src/Other/PopulationSort.cpp
        src/Other/PopulationSort.h src/Solutions/Genetic/third_evolution.cpp src/Other/Roulette.cpp
        src/Other/Roulette.h src/Other/DoubleOperations.cpp src/Other/DoubleOperations.h src/Solutions/Genetic/GeneticSolutions.h
        src/Solutions/Genetic/first_evolution.cpp
        src/K-clusters/k-clusters.cpp src/K-clusters/k-clusters.h src/Fitness/Euclidean.cpp src/Solutions/Genetic/k-clusters-evolution.cpp src/Solutions/Genetic/advanced-k-cluster.cpp src/Solutions/Genetic/clusterGA.cpp src/Distance_measures.h)
add_executable(Testing src/Testing/Testing.cpp src/Solutions/Genetic/first_evolution.cpp
        src/Solutions/Genetic/first_evolution.cpp src/Solutions/Genetic/second_evolution.cpp
        src/Gene/GenePoint.cpp src/Gene/GenePoint.h src/Other/Point.cpp
        src/Other/Point.h src/Random/Random.cpp src/Random/Random.h src/Initialization/Init.cpp src/Initialization/Init.h
        src/Termination/Terminator.cpp src/Termination/Terminator.h src/Mutation/MutationOfPopulation.cpp src/Mutation/Mutation.h
        src/Crossover/Crossover.cpp src/Crossover/Crossover.h src/Selection/Selection.cpp src/Selection/Selection.h
        src/Fitness/FitnessOfGenome.cpp src/Fitness/Fitness.h src/Mutation/MutationOfGenome.cpp src/Fitness/FitnessOfPopulation.cpp
        src/Fix/FixGenome.cpp src/Fix/Fix.h src/Fix/FixPopulation.cpp src/Fitness/Distance.cpp
        src/Pathes.h src/Solutions/Auxiliary/Prints.cpp src/Solutions/Auxiliary/Prints.h
        src/Solutions/Auxiliary/ReadData.cpp src/Solutions/Auxiliary/ReadData.h
        src/Solutions/Auxiliary/Stat.cpp src/Solutions/Auxiliary/Stat.h src/Solutions/Auxiliary/Other.cpp
        src/Solutions/Auxiliary/Other.h src/Other/FileOperations.cpp
        src/Other/FileOperations.h src/InputGenerator/generators.h src/Solutions/Non-genetic/nearest.cpp src/Solutions/Non-genetic/nearest.h src/Other/PopulationSort.cpp src/Other/PopulationSort.h src/Solutions/Genetic/third_evolution.cpp src/Other/Roulette.cpp src/Other/Roulette.h src/Other/DoubleOperations.cpp src/Other/DoubleOperations.h src/Solutions/Genetic/GeneticSolutions.h src/K-clusters/k-clusters.cpp src/K-clusters/k-clusters.h src/Fitness/Euclidean.cpp src/Solutions/Genetic/k-clusters-evolution.cpp src/Solutions/Genetic/advanced-k-cluster.cpp src/Solutions/Genetic/clusterGA.cpp src/Distance_measures.h)
add_executable(Main_generator src/InputGenerator/Main_generator.cpp src/InputGenerator/first_generator.cpp src/InputGenerator/generators.h src/InputGenerator/second_generator.cpp src/Random/Random.cpp src/Random/Random.h src/Other/DoubleOperations.cpp src/Other/DoubleOperations.h)
add_executable(
        TestGenerator src/Random/Random.h src/Random/Random.cpp src/InputGenerator/first_generator.cpp
        src/Testing/TestGenerator.cpp src/Pathes.h src/Other/FileOperations.cpp
        src/Other/FileOperations.h src/InputGenerator/generators.h src/InputGenerator/second_generator.cpp
        src/Other/DoubleOperations.cpp src/Other/DoubleOperations.h)
add_executable(non-evolution  src/Solutions/Non-genetic/Main-non-evolution.cpp src/Gene/GenePoint.h src/Gene/GenePoint.cpp
        src/Fitness/Fitness.h src/Fitness/FitnessOfGenome.cpp src/Fitness/Distance.cpp
        src/Pathes.h src/Solutions/Non-genetic/nearest.cpp src/Solutions/Non-genetic/nearest.h src/Other/Point.cpp
        src/Other/Point.h src/Solutions/Auxiliary/Prints.cpp src/Solutions/Auxiliary/Prints.h
        src/Solutions/Auxiliary/ReadData.h src/Solutions/Auxiliary/ReadData.cpp src/Other/PopulationSort.cpp src/Other/PopulationSort.h src/Solutions/Genetic/third_evolution.cpp src/Other/Roulette.cpp src/Other/Roulette.h src/Other/DoubleOperations.cpp src/Other/DoubleOperations.h src/Solutions/Genetic/GeneticSolutions.h src/K-clusters/k-clusters.cpp src/K-clusters/k-clusters.h src/Fitness/Euclidean.cpp src/Distance_measures.h)
