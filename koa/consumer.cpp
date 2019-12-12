#include <iostream>
#include <omp.h>
#include "../Singha/buff&Prod.cpp"
using namespace std;

class Consumer
{
public:
    string name;
    int money;
    Consumer(string n, int m);

    void getSushi()
    {
        for (int i = 0; true; i++)
        {
            if(money>=buffer.front().price){
                Sushi temp =get();
               std:: cout << "\n" <<name<<" have money "<< money<<" ::::: Get " << temp.name<<" : " << temp.price << endl;
                money = money-temp.price;
               std:: cout<< "have :"<<money<<"\n\n";
            }else{
                break;
            }
        }
    }
};

Consumer::Consumer(string n, int m)
{
    name = n;
    money = m;
}

