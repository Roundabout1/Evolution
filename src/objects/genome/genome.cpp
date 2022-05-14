#include "genome.hpp"
Genome::Genome(){
    this->chrom = std::vector<Gen>();
}

Genome::Genome(int num_genes){
    this->chrom = std::vector<Gen>(num_genes, Gen());
}

Gen Genome::getGen(int i){
    return chrom[i];
}
void Genome::setGen(int i, Gen gen){
    chrom[i] = gen;
}
int Genome::size(){
    return chrom.size();
}
std::string Genome::toString(){
    std::string ans = "";
    for(int i = 0; i < chrom.size(); i++){
        ans += chrom[i].toString() + " ";
    }
    return ans;
}
void Genome::mutation(){
    int l = getRandomNumber(0, size()-2);
    int r = getRandomNumber(1, size()-1);
    std::swap(chrom[l], chrom[r]);
}
