#include <iostream>
// #include <omp.h>
// #include "Singha/main.cpp"
#include "koa/consumer.cpp"
using namespace std;

int main(int argc, const char** argv) {

    Buffer buff;
    // Producer p1("singha", buff);
    // Sushi a("name", 50);
    
    for (size_t i = 0; i < 10; i++)
    {
        
        Consumer n01("koa", 1500, buff);
        cout << n01.name << " have a money " << n01.money << " \n";
    }
        



    return 0;
}