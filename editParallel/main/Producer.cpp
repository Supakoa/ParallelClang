#include <iostream>
#include "buffer.cpp"
#include<string>  
using namespace std;

class Producer
{
public:
    string name;
    Producer(string n);

    void makeOrder(int thread_num)
    {
        string tn = to_string(thread_num);
        add(ranSushi(), this->name + tn);
    }
};

Producer::Producer(string n)
{
    name = n;
}