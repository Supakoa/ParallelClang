#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <fstream>
#include <thread>
#include <chrono>
#define MAX_BUFFER 10
#include <queue>
#define Size_Of_Sushi 23
using namespace std;

// class sushi
class Sushi
{
public:
    string name;
    int price;
    Sushi(string n = "empty", int p = 0)
    {
        this->name = n;
        this->price = p;
    }
    ~Sushi()
    {
    }
};
// end class

Sushi sushis[23];

void generate_sushi()
{
    fstream csv;
    csv.open("../Sushi-bar - แผ่น1.txt");
    string sushi[23][2];
    int i = 0, c = 0;

    while (c <= 45)
    {
        string line;
        getline(csv, sushi[i][c % 2], ',');
        cout << "[" << i << " : " << c % 2 << "]"
             << ": " << sushi[i][c % 2] << "\n\n";
        if (c % 2 != 0)
        {
            i++;
        }
        c++;
    }

    for (int i = 0; i < Size_Of_Sushi; i++)
    {
        int tmp_num = stoi(sushi[i][1]);
        sushis[i] = Sushi(sushi[i][0], tmp_num);
    }
}

queue<Sushi> buffer;
int n = 0;
void add(Sushi s, string name)
{

    while (buffer.size() >= MAX_BUFFER)
        ;
    n++;
    cout << "\n---------------------- Producer --------------------";
    cout << "\n[PRODUCER] Buffer Size: " << buffer.size() + 1 << " | [" << name << "]"<< endl ; 
    cout << "make sushi => [" << s.name << " : " << s.price << ".B]\n";
    cout << "---------------------- END Producer --------------------" << endl;
    buffer.push(s);
}

Sushi get()
{
    while (buffer.empty()){
                std::this_thread::sleep_for(std::chrono::milliseconds(500));

    }
    Sushi s = buffer.front();
    buffer.pop();
    n--;
    return s;
}

Sushi sushi;
void ranSushi()
{
    sushi = sushis[rand() % 23];
}

class Producer
{
public:
    string name;
    Producer(string n);
    void makeOrder()
    {
        for (int i = 0; true; i++)
        {
            add(sushi, this->name);
        }
    }
};

Producer::Producer(string n)
{
    name = n;
}
