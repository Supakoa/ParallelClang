#include <iostream>
#include <omp.h>
#include "../Singha/main.cpp"
using namespace std;

class Consumer
{
public:
    string name;
    Buffer buffer;
    int money;
    Consumer(string n, int m, Buffer b);

    void buy(Consumer a, Buffer b)
    {
        if (a.money != 0)
        {
            /* code this here */
        }
        else
        {
            NotHaveAmoney(a);
        }
    }

    void NotHaveAmoney(Consumer a)
    {
        if (a.money <= 0)
            cout << "Now you not have a money";
    }
};

Consumer::Consumer(string n, int m, Buffer b)
{
    name = n;
    money = m;
    buffer = b;
}

// int main(int argc, char const *argv[])
// {
//     Consumer n01("koa", 1500);
//     cout << n01.name << " have a money " << n01.money<< endl;

//     return 0;
// }
