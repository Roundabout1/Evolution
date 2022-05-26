

#include <iostream>
#include "Fix.h"
#include "../Random/Random.h"

void fix(Genome &genome, Genome &example) {
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
