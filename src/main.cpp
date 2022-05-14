#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <map>
#include "header.hpp"
using namespace std;
/*int getRandomNumber(int min, int max);
//ген - это минимальная единица генома
class Gen{
private:
    int type;
public:
    Gen(){
        this->type = 0;
    }
    Gen(int value){
       this->type = value;
    }

    void setValue(Gen gen){
        this->type = gen.type;
    }
    string toString(){
        return std::to_string(type);
    }
    bool equal(Gen gen){
        return gen.type == this->type;
    }
    int getType(){
        return type;
    }
};

//геном - это закодированное решение задачи
class Genome{

private:
    //хромосома
    vector <Gen> chrom;

public:
    Genome(){
        chrom = vector<Gen>();
    }

    Genome(int num_genes){
        chrom = vector<Gen>(num_genes, Gen());
    }

    Gen getGen(int i){
        return chrom[i];
    }
    void setGen(int i, Gen gen){
        chrom[i] = gen;
    }
    int size(){
        return chrom.size();
    }
    string toString(){
        string ans = "";
        for(int i = 0; i < chrom.size(); i++){
            ans += chrom[i].toString() + " ";
        }
        return ans;
    }
    void mutation(){
        int l = getRandomNumber(0, size()-2);
        int r = getRandomNumber(1, size()-1);
        std::swap(chrom[l], chrom[r]);
    }
};

//функции, реализация которых зависит от поставленной задачи

//возвращает исправленный геном, если он содержал недопустимые ошибки
Genome fix(Genome genome, int maxType){
    Genome fixed_genome = Genome(genome.size());
    map<Gen, bool> used;
    vector<size_t> mistakes;
    for(size_t i = 0; i < genome.size(); i++){
        bool u = used[genome.getGen(i)];
        if(u){
            mistakes.push_back(i);
        }else{
            used[genome.getGen(i)] = true;
        }
    }
    
}

//популяция - это множество генов
class Population{
private:
    vector<Genome> genomes;
public:
    Population(){

    }
    Population(int num_population, int num_genes){
        genomes.resize(num_population, Genome(num_genes));
    }
    Genome get(int index){
        return genomes[index];
    }
    size_t size(){
        return genomes.size();
    }
    void set(int index, Genome genome){
        genomes[index] = genome;
    }
    void merge(Population other){
        genomes.insert(other.genomes.end(), other.genomes.begin(), other.genomes.end());
    }
};
//критерий остановки
class Terminator{
private:
    //текущая итерация
    size_t cur_iteration;
    //количество итераций
    size_t max_iterations;

public:
    Terminator(){
        
    }
    Terminator(size_t max_iterations){
        cur_iteration = 0;
        this->max_iterations = max_iterations;
    }
    //достигнуто ли условие?
    bool isSatisfied(){
        return cur_iteration > max_iterations;
    }
    void update(){
        cur_iteration++;
    }
};
//Процесс эволюции
class Evolution{
private:
    //кол-во особей в одном поколении
    int num_population;
    //кол-во генов в одной особи
    int num_genes;
    Terminator terminator;
    Population population;
public:
    Evolution(int num_population, int num_genes, Terminator terminator){
        this->num_genes = num_genes;
        this->terminator = terminator;
        this->population = population;
    }
    //инициализация
    Population init(){
        Population res = Population(num_population, num_genes);
        for(int i = 0; i < res.size(); i++){
            res.get(i).mutation();
        }
        return Population();
    }
    //скрещивание
    Population crossover(){
        return Population();
    }
    //мутация
    Population mutation(){
        return Population();
    }
    //селекция
    Population selection(){
        return Population();
    }

    //запуск эволюционного алгоритма
    void run(){
        population = init();
        while(!terminator.isSatisfied()){
            Population children = crossover();
            Population mutants = mutation();
            population.merge(children);
            population.merge(mutants);
            population = selection();
            terminator.update();
        }
    }
};
*/
int main(){
    Genome population;
    return 0;
}