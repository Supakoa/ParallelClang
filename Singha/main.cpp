#include <iostream>
#include <stdio.h>
#include <omp.h>
#define MAX_BUFFER 100
#include <queue>
using namespace std;

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
class Buffer
{
public:
    queue<Sushi> buffer;
    int n = 0;
    Buffer()
    {
    }
    bool isFull()
    {
        return buffer.size() >= MAX_BUFFER;
    }
    bool isEmtry()
    {
        return n == 0;
    }

    void add(Sushi s)
    {
        while (isFull())
            ;
        cout << s.name << " : " << s.price << "\n";
        buffer.push(s);
    }

    Sushi get()
    {
        while (isEmtry())
            ;
        Sushi s = buffer.front();
        buffer.pop();
        return s;
    }
};
class Producer
{

public:
    string name;
    Buffer buffer;
    Producer(string n, Buffer b);
};

Producer::Producer(string n, Buffer b)
{
    name = n;
    buffer = b;
}

int main()
{

    Buffer buffer;
    Producer p1("singha", buffer);
    Sushi a("name", 50);
#pragma omp sections
    {
#pragma omp section
        {
            a.price = a.price + 1;
            p1.buffer.add(a);
        }
    }

    // printf(" %s\n", p1.name);
    // cout << p1.name << "\n";
    // #pragma omp parallel
    // {
    // printf("Hello world! %d \n",omp_get_thread_num());
    // }

    return 0;
}