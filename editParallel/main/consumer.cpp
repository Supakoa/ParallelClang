#include <iostream>
#include "Producer.cpp"
#include<stdio.h> 
#include<stdlib.h> 
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
                Sushi temp = get(name, money);
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
