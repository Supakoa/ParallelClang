#include <iostream>
#include <omp.h>
#include "../Singha/buffer.cpp"
using namespace std;

class Producer
{
public:
    string name;
    Producer(string n);
    void makeOrder()
    {
        for (int i = 0; true; i++)
        {
            Sushi temp = all[0];
            all[0].price = all[0].price + 1;

            add(temp,name);
        }
    }
};

Producer::Producer(string n)
{
    name = n;
}
