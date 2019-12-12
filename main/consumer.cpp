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
            if(money >= buffer.front().price){
                Sushi temp =get();
               std:: cout << "\n" <<name<<" have money "<< money<<" ::::: Get " << temp.name<<" : " << temp.price << endl;
                money = money-temp.price;
               std:: cout << "have :"<< money <<"\n\n";
            }else{
                
                return 1 ;
            }
        }
    }
};

Consumer::Consumer(string n, int m)
{
    name = n;
    money = m;
}

