//
// Created by mrsiv on 27.05.2022.
//
#include <iostream>
void testFun(int &a, int &b){
    a = 10;
    b = 20;
}
int main(){
    int a = 0, b = 0;
    testFun(a, b);
    std::cout << a << ' ' << b;
    return 0;
}