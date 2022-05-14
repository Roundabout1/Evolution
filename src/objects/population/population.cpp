#include "population.hpp"
//популяция - это множество генов
Population::Population(){

}
Population::Population(int num_population, int num_genes){
    genomes.resize(num_population, Genome(num_genes));
}
Genome Population::get(int index){
    return genomes[index];
}
size_t Population::size(){
    return genomes.size();
}
void Population::set(int index, Genome genome){
    genomes[index] = genome;
}
void Population::merge(Population other){
    genomes.insert(other.genomes.end(), other.genomes.begin(), other.genomes.end());
}