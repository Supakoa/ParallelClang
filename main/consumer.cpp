#include <iostream>
#include <omp.h>
#include "buffer.cpp"
using namespace std;

class Consumer
{
public:
    string name;
    int money;
    int numtd;
    Consumer(string n, int m, int ntd);

    int getSushi()
    {
        for (int i = 0; true; i++)
        {
            if (money >= buffer.front().price)
            {
                Sushi temp = get();
                cout << "\n\t\t\t[Consumer] [" << name << "] [" << money << "B] | Eat >> [" << temp.name << " : " << temp.price << "B] " << " | Total money: [" << money - temp.price << "B]\n\n";
                money = money - temp.price;
                // cout << "---------------------- END Consumer --------------------\n";

            }
            else
            {
                return 0;
            }
        }
    }
};

Consumer::Consumer(string n, int m, int ntd)
{
    name = n;
    money = m;
    numtd = ntd;
}
