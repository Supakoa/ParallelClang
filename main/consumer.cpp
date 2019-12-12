#include <iostream>
#include <omp.h>
#include "buffer.cpp"
using namespace std;

class Consumer
{
public:
    string name;
    int money;
    Consumer(string n, int m);

    int getSushi()
    {
        for (int i = 0; true; i++)
        {
            if (money >= buffer.front().price)
            {
                Sushi temp = get();
                cout << "\n[Consumer] [" << name << "] [" << money << "B] | Eat >> [" << temp.name << " : " << temp.price << "B] " << " | Total money: [" << money - temp.price << "B]\n\n";
                money = money - temp.price;
            }
            else
            {
                return 1;
            }
        }
    }
};

Consumer::Consumer(string n, int m)
{
    name = n;
    money = m;
}
