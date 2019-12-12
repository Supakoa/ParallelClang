#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <fstream>
// #include "../temp/main.cpp"
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

Sushi *generate_sushi()
{
    fstream csv;
    csv.open("../Sushi-bar - แผ่น1.csv");
    string sushi[23][2];
    int i = 0, c = 0;

    while (c <= 45)
    {
        string line;
        // cout << i << " : " << c % 2 << "\n";
        getline(csv, sushi[i][c % 2], ',');
        // sushi[i][c % 2]
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

// bool isFull()
// {
//     return n >= MAX_BUFFER;
// }
// bool isEmtry()
// {
//     return n <= 0;
// }

void add(Sushi s, string name)
{

    while (buffer.size() >= MAX_BUFFER)
        ;
    n++;
    cout << "\nBuffer" << n << " // " << name << " Make : " << s.name << " : " << s.price << "\n";
    buffer.push(s);
}

Sushi get()
{
    while (buffer.empty())
        ;
    Sushi s = buffer.front();
    buffer.pop();
    n--;
    return s;
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
            int ra = rand() % 23;
            cout << "ran: " << ra << "\n";
            add(sushis[ra], name);
        }
    }
};

Producer::Producer(string n)
{
    name = n;
}
