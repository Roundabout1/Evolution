#include <iostream>
#include "Fix.h"
#include "../Random/Random.h"
#include "../Fitness/Fitness.h"



void fix_greedy(std::vector<GenePoint> &genome, std::vector<GenePoint> &example, bool isClosed, measures distance_measure) {
    int n = genome.size();

    std::vector<int>
    //присутствующие гены
    used(n),
    //отсутствующие гены
    unused,
    //позиции на которых находятся дупликаты
    mistake;

    //заполняем used и mistake
    for(int i = 0; i < n; i++){
        int type = genome[i].getType();
        if(!used[type]) {
            used[type] = true;
        }
        else
            mistake.push_back(i);
    }
    //заполняем unused
    for(int i = 0; i < n; i++){
        if(!used[i]) {
            unused.push_back(i);
        }
    }
    //меняем дупликаты на неиспользованные гены
    for(int i = 0; i < mistake.size(); i++){
        int mistake_pos = mistake[i];
        int unused_pos = unused[i];
        double min = distance(genome[mistake_pos - 1].getPoint(), example[unused_pos].getPoint(), isClosed, distance_measure);
        if(mistake_pos != genome.size()-1){
            min += distance(genome[mistake_pos + 1].getPoint(), example[unused_pos].getPoint(), isClosed, distance_measure);
        }
        for(int j = i + 1; j < mistake.size(); j++){
            unused_pos = unused[j];
            double cur = distance(genome[mistake_pos - 1].getPoint(), example[unused_pos].getPoint(), isClosed, distance_measure);
            if(mistake_pos != genome.size()-1){
                cur += distance(genome[mistake_pos + 1].getPoint(), example[unused_pos].getPoint(), isClosed, distance_measure);
            }
            if(cur < min){
                min = cur;
                std::swap(unused[i], unused[j]);
            }
        }
        genome[mistake[i]] = example[unused[i]];
    }
}

void fix_greedy2(std::vector<GenePoint> &genome, std::vector<GenePoint> &example, bool isClosed, measures distance_measure) {
    int n = genome.size();

    std::vector<int>
    //присутствующие гены
    used(n),
    //отсутствующие гены
    unused,
    //позиции на которых находятся дупликаты
    mistake;

    //заполняем used
    for(int i = 0; i < n; i++){
        int type = genome[i].getType();
        used[type]++;
    }
    //заполняем mistakes
    for(int i = 0; i < n; i++){
        int type = genome[i].getType();
        if(used[type] > 1)
            mistake.push_back(i);
    }
    //заполняем unused
    for(int i = 0; i < n; i++){
        if(used[i] != 1) {
            unused.push_back(i);
        }
    }
    //std::cout << mistake.size() << std::endl;
    //меняем дупликаты на неиспользованные гены
    for(int i = 0; i < mistake.size(); i++){
        int mistake_pos = mistake[i];
        int unused_pos = unused[i];
        double min = get_distance(genome, example, mistake_pos, unused_pos, isClosed, distance_measure);
        for(int j = i + 1; j < mistake.size(); j++){
            unused_pos = unused[j];
            double cur = get_distance(genome, example, mistake_pos, unused_pos, isClosed, distance_measure);
            if(cur < min){
                min = cur;
                std::swap(unused[i], unused[j]);
            }
        }
        genome[mistake_pos] = example[unused[i]];
    }
}
//жадно чинит гены, смотря только на левую сторону
void fix_greedy_left(std::vector<GenePoint> &genome, std::vector<GenePoint> &example, bool isClosed,
                     measures distance_measure) {
    int n = genome.size();

    std::vector<int>
    //присутствующие гены
    used(n),
    //отсутствующие гены
    unused,
    //позиции на которых находятся дупликаты
    mistake;

    //заполняем used
    for(int i = 0; i < n; i++){
        int type = genome[i].getType();
        used[type]++;
    }
    //заполняем mistakes
    for(int i = 0; i < n; i++){
        int type = genome[i].getType();
        if(used[type] > 1)
            mistake.push_back(i);
    }
    //заполняем unused
    for(int i = 0; i < n; i++){
        if(used[i] != 1) {
            unused.push_back(i);
        }
    }
    //std::cout << mistake.size() << std::endl;
    //меняем дупликаты на неиспользованные гены
    for(int i = 0; i < mistake.size(); i++){
        int mistake_pos = mistake[i];
        int unused_pos = unused[i];
        double min = get_left_distance(genome, example, mistake_pos, unused_pos, isClosed, distance_measure);
        for(int j = i + 1; j < mistake.size(); j++){
            unused_pos = unused[j];
            double cur = get_left_distance(genome, example, mistake_pos, unused_pos, isClosed, distance_measure);
            if(cur < min){
                min = cur;
                std::swap(unused[i], unused[j]);
            }
        }
        genome[mistake_pos] = example[unused[i]];
    }
}

void fix_random(std::vector<GenePoint> &genome, std::vector<GenePoint> &example) {
    int n = genome.size();

    std::vector<int>
    //присутствующие гены
    used(n),
    //отсутствующие гены
    unused,
    //позиции на которых находятся дупликаты
    mistake;

    //заполняем used и mistake
    for(int i = 0; i < n; i++){
        int type = genome[i].getType();
        if(!used[type]) {
            used[type] = true;
        }
        else
            mistake.push_back(i);
    }
    //заполняем unused
    for(int i = 0; i < n; i++){
        if(!used[i]) {
            unused.push_back(i);
        }
    }
    //меняем дупликаты на неиспользованные гены
    for(int i = 0; i < mistake.size(); i++){
        int j = getRandomNumber(i, unused.size() - 1);
        std::swap(unused[i], unused[j]);
        genome[mistake[i]] = example[unused[i]];
    }
}

