#include <iostream>
#include <omp.h>
#include "../Singha/main.cpp"
using namespace std;

class Consumer{
    public:
        string name;
        int money;
        Consumer(string n,int m);
        
        void buy(Consumer a,Buffer b){
           if (a.money != 0){
               
           }else
           {
               NotHaveAmoney(a);
           }
        }

        void NotHaveAmoney(Consumer a){
            if (a.money <= 0)cout << "Now you not have a money";
        }
};

Consumer::Consumer(string n, int m){
            name = n;
            money = m;
        }


// int main(int argc, char const *argv[])
// {
//     Consumer n01("koa", 1500);
//     cout << n01.name << " have a money " << n01.money<< endl;
    

//     return 0;
// }
