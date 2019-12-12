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
                cout << "---------------------- Consumer --------------------";
                cout << "\n[CONSUMER]{"<<"[THREAD :" << numtd << "]" << "} [" << name << "] [" << money << "B] |\n";
                cout << "Eat >> [" << temp.name << " : " << temp.price << "B] " << " | Total money: [" << money - temp.price << "B]\n";
                money = money - temp.price;
                cout << "---------------------- END Consumer --------------------\n" << endl;

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
