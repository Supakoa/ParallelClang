#include <iostream>
#include <string>
#include <omp.h>
#include <fstream>
#include <string> //geek

// #include "../Singha/buffer.cpp"
using namespace std;

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

int main()
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

  cout << c << "\n";

  cout << sushi[0][0] << "\n";

  // create object array
  Sushi sushis[23];

  for (int i = 0; i < Size_Of_Sushi; i++)
  {
    int tmp_num = stoi(sushi[i][1]);
    sushis[i] = Sushi(sushi[i][0], tmp_num);
  }

  cout << sushis[0].price << "\n";

  return 0;
}
