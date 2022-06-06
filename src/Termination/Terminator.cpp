
#include "Terminator.h"

Terminator::Terminator() {
    cur_iteration = 0;
    max_iterations = 0;
}

Terminator::Terminator(unsigned int max_iterations) {
    cur_iteration = 0;
    this->max_iterations = max_iterations;
}

bool Terminator::isSatisfied() {
    return cur_iteration >= max_iterations;
}

void Terminator::update() {
    cur_iteration++;
}

unsigned int Terminator::getCurIteration() const {
    return cur_iteration;
}

unsigned int Terminator::getMaxIterations() const {
    return max_iterations;
}

void Terminator::update(bool isProgressed) {
    cur_iteration = (isProgressed) ? 0 : cur_iteration + 1;
}
