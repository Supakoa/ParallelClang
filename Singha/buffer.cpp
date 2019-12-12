#include <iostream>
#include <stdio.h>
#include <omp.h>
#define MAX_BUFFER 10
#include <queue>
using namespace std;

// class sushi
class Sushi
{
public:
    string name;
    int price;
    Sushi(string n, int p);
};
Sushi::Sushi(string n, int p)
{
    name = n;
    price = p;
}

queue<Sushi> buffer;
int n = 0;

bool isFull()
{
    return n >= MAX_BUFFER;
}
bool isEmtry()
{
    // cout << "Buffer" << n << "\n";
    return n <= 0;
}

void add(Sushi s,string name)
{
  
    while (buffer.size()>=MAX_BUFFER);
    
    
   std:: cout << "Buffer" << n << " // " << name << " Make : " << s.name << " : " << s.price << " \n";
    buffer.push(s);
    n++;
}

Sushi get()
{
    while (buffer.empty())  ;
    Sushi s = buffer.front();
    // cout << "Buffer" << buffer.size() << " GET :" << s.name << " : " << s.price << "\n";
    buffer.pop();
    n--;
    return s;
}
Sushi *all = {new Sushi("Sushi", 10)};
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
