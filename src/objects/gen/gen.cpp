#include "gen.hpp"
#include <string>


Gen::Gen(){
    this->type = 0;
}
Gen::Gen(int value){
    this->type = value;
}

void Gen::set(Gen gen){
    this->type = gen.type;
}
std::string Gen::toString(){
    return std::to_string(type);
}
bool Gen::equal(Gen gen){
    return gen.type == this->type;
}
int Gen::getType(){
    return type;
}

