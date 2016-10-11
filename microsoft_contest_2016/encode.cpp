#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main () {
  string line;
  ifstream myfile ("PracticeInput.txt");
  if (myfile.is_open())
  {
    while (getline (myfile, line)) {
       // code here
       string pt;
       int i = 0;
       while (i < line.length() && line[i] != '|')
          i++;
       pt = line.substr(0, 64);
       string key = line.substr(i+1);

       int kp = 0; // key ptr
       string ct(64, ' ');
       for (int i = 0; i < 64; i++) {
             if (pt[i] >= 97 && pt[i] <= 122) {
               ct[i] = (((pt[i] - 'a') + (key[kp++] - 'A')) % 26) + 'a';
             }
             else if (pt[i] >= 65 && pt[i] <= 90) {
                ct[i] = (((pt[i] - 'A') + (key[kp++] - 'A')) % 26) + 'A';
             }
             else
                ct[i] = pt[i];
             kp = kp % 10;
          }
       cout << ct << endl;
    }
    myfile.close();
  }
    return 0;
  }
