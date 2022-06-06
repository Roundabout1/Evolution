
#ifndef EVOLUTIONALGORITHM_TERMINATOR_H
#define EVOLUTIONALGORITHM_TERMINATOR_H

class Terminator {
private:
    //текущая итерация
    unsigned int cur_iteration;
    //максимальное количество итераций
    unsigned int max_iterations;
public:
    Terminator();
    Terminator(unsigned  int max_iterations);
    //достигнуто ли условие?
    bool isSatisfied();
    void update();
    //если передать значение true, то счётчик cur_iteration сбросится до 0, иначе cur_iteration просто увеличится на единицу
    void update(bool isProgressed);
    unsigned int getCurIteration() const;

    unsigned int getMaxIterations() const;
};


#endif //EVOLUTIONALGORITHM_TERMINATOR_H
