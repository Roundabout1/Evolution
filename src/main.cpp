#include <iostream>
#include <vector>
#include <algorithm>
#include "random generators/random.cpp"
using namespace std;
int getRandomNumber(int min, int max);
//ген - это минимальная единица генома
class Gen{
private:
    int value;
public:
    Gen(){
        this->value = 0;
    }
    Gen(int value){
       this->value = value;
    }

    void setValue(Gen gen){
        this->value = gen.value;
    }
    string toString(){
        return std::to_string(value);
    }
    Gen mutation(){
        return Gen();
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
    Genome mutation(){
        return Genome(chrom.size());
    }
};
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
    Genome set(int index, Genome genome){
        genomes[index] = genome;
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
    Evolution(int num_population, int num_genes, Terminator terminator, Population population){
        this->num_population = num_population;
        this->num_genes = num_genes;
        this->terminator = terminator;
        this->population = population;
    }
    //инициализация
    Population init(){
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

    }
};

int main(){
    cout << "Hello, world!\n";    
    return 0;
}