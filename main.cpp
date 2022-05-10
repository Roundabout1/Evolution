#include <iostream>
#include <vector>#include <iostream>
#include <vector>
#include <cstdlib> // ��� ������� rand() � srand()
#include <ctime> // ��� ������� time()
#include <algorithm>
using namespace std;
int getRandomNumber(int min, int max);

//��� - ����������� ������� ���������
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
        this->value = gen->value;
    }
    string toString(){
        return std::to_string(value);
    }
    Gen mutation(){
        return this;
    }
};

//������� �����
class Genome{

private:
    //���������
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
        return this;
    }
};
//��������� ������
class Population{
private:
    vector<Genome> genomes;
public:
    Population(int num_population, num_genes){
        genomes.resize(num_population, Genome(num_genes));
    }
    Genome get(int index){
        return genomes[i];
    }
    Genome set(int index, Genome genome){
        genomes[i] = genome;
    }
};
//�������� ��������� (������� � ����������)
class Terminator{
private:
    //������� ��������
    size_t cur_iteration;
    //���������� ��������
    size_t max_iterations;

public:
    Terminator(size_t max_iterations){
        cur_iteration = 0;
        this->max_iterations = max_iterations;
    }
    //�������� �� �������� ��������?
    bool isSatisfied(){
        return cur_iteration > max_iterations;
    }
    void update(){
        cur_iteration++;
    }
};
//������������ �������
class Evolution(){
private:
    //���������� ������ � ����� ���������
    int num_population;
    //���������� ����� � ����� �����
    int num_genes;
    //�������� ���������
    Terminator terminator;
    //���������
    Population population;
public:
    Evolution(){

    }
    //�������������
    vector<Genome> init(){

    }
    //�����������
    vector<Genome> crossover(){

    }
    //�������
    vector<Genome> mutation(){

    }
    //��������
    vector <Genome> selection(){

    }

    //������ ������ �������
    void run(){

    }
};

int main(){
    srand(time(0));
    rand();

    int popSize = 100, genSize = 1000;
    vector <Genome> population = vector<Genome>(popSize, Genome(genSize));
    for(int i = 0; i < popSize; i++){
        population[i].randomize();
    }

    for(int i = 0; i < 100; i++){
        vector <Genome> newPopulation = newGen(population);
        population = newPopulation;
        cout << "gen " << i << endl;
        cout << population[0].toString() << endl;
        cout << "fitness = " << population[0].fit() << endl;
    }
    /*cout << population[0].toString() << endl;
    cout << "fitness = " << population[0].fit() << endl;*/
    return 0;
}

int getRandomNumber(int min, int max){
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // ���������� ������������ ��������� ����� � ����� ���������
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
Genome crossover(Genome ind1, Genome ind2, int mutationChance){
    //srand(time(0));
    int n = min(ind1.size(), ind2.size());
    //cout << "CROS " << ind1.size() << ' ' << ind2.size() << endl;
    Genome child = Genome(n);
    for(int i = 0; i < n; i++){
        bool a = rand()%2;
        if(a){
            child.setGen(i, ind1.getGen(i));
        }else{
            child.setGen(i, ind2.getGen(i));
        }
        child.getGen(i).mutation(mutationChance);
    }
    return child;
}
