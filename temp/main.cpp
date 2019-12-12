#include <iostream>
#include <string>
#include <omp.h>
#include <fstream>
#include "../Singha/buffer.cpp"
using namespace std;

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
    cout << "[" << i << " : " << c % 2 << "]" << ":" << sushi[i][c % 2] << "\n\n";
    if (c % 2 != 0)
    {
      i++;
    }
    c++;
  }

  cout << c << "\n";

  cout << sushi[0][0] << "\n";

  return 0;
}
