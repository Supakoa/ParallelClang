#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include "Sushi.cpp"
using namespace std;

// define
#define MAX_BUFFER 10

queue<Sushi> buffer;

void add(Sushi s, string name)
{
    while (buffer.size() >= MAX_BUFFER)
    {
        // io
        // cout << "Buffer Full\n";
    }
    // #pragma omp critical
    // {
        cout << "\n<[Producer] [" << name << "] make sushi => [" << s.name << " : " << s.price << "B] | Buffer Size: " << buffer.size() + 1 << "\n";
    // }
    // std::this_thread::sleep_for(std::chrono::milliseconds(500));
    buffer.push(s);
}

Sushi get(string name, int money)
{
    while (buffer.empty()){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    Sushi s = buffer.front();
    buffer.pop();
    // #pragma omp critical
    // {
        cout << "\n\t>[Consumer] [" << name << "] [" << money << "B] | Eat >> [" << s.name << " : " << s.price << "B] " << " | Total money: [" << money - s.price << "B] | Buffer Size: " << buffer.size() << "\n\n";
    // }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return s;
}

int getBufferSize(){
    return buffer.size();
}
