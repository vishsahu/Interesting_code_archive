#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

int main () {
  string line;
  ifstream myfile ("1.txt");
  if (myfile.is_open())
  {
    getline (myfile, line);
    myfile.close();
  }
    vector<string> cols;
    split(line, ' ', cols);

    // code here
    vector<string> out;
    out.push_back(cols[0]);

    for (int i = 1; i <= cols.size() - 2; i++) {
       if (out[i-1] == cols[i])
          out.push_back("blank");

       else if ((out[i-1] == "red" && cols[i] == "purple"))
          out.push_back("blue");
       else if ((out[i-1] == "blue" && cols[i] == "purple"))
          out.push_back("red");

       else if ((out[i-1] == "blue" && cols[i] == "green"))
          out.push_back("yellow");
       else if ((out[i-1] == "yellow" && cols[i] == "green"))
          out.push_back("blue");

       else if ((out[i-1] == "yellow" && cols[i] == "orange"))
          out.push_back("red");
       else if ((out[i-1] == "red" && cols[i] == "orange"))
          out.push_back("yellow");

       else if (out[i-1] == "blank" || cols[i] == "blank")
          out.push_back(cols[i]);
    }

    for (auto x : out)
       cout << x << " ";



  return 0;
}
