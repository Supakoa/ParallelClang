#include <iostream>
#include<stdio.h>
#include<omp.h>
#define MAX_BUFFER 10
#include <queue>
using namespace std;

class Sushi
{
public:
    string name;
    int price;
    Sushi(string n,int p);

};
Sushi::Sushi(string n,int p){
    name = n;
    price = p;
}
class Buffer
{
public:
    queue<Sushi> buffer;
    int n=0;
    Buffer(){
        cout<<"eiei";
    }
    bool isFull(){
        return buffer.size()>=MAX_BUFFER;
    }
    bool isEmtry(){
        return n==0;
    }

    void add(Sushi s){
        while(isFull());
        buffer.push(s);
    }

    Sushi get(){
         while(isEmtry());
         Sushi s = buffer.front();
         buffer.pop();
         return s;
    }

};

int main()
{

    Buffer a ;
    #pragma omp parallel
    {
    printf("Hello world! %d \n ",omp_get_thread_num());
    }


    return 0;
}