#include <iostream>
#include <fstream>
using namespace std;

// defind
#define Size_Of_Sushi 23

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

    while (c < Size_Of_Sushi * 2)
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

Sushi ranSushi()
{
    return sushis[rand() % 23];
}