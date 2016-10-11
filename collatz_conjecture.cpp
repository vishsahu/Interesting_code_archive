/*
given n find the max reduction count between 1 to n
f(n) = 3n + 1 if n is odd
else f(n) = n/2

find max # of steps to reach at 1

sol(i) = 1 + sol(3 * i + 1) if n is odd
else
sol(i)
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> m;
int reduce1(int i) {
   int k = m.size();
  if (i % 2) { // odd case
    if ((3 * i + 1) < k && m[3 * i + 1] != -1)
      m[i] = 1 + m[3 * i + 1];
    else
      m[i] = 1 + reduce1(3 * i + 1);
  }
  else { // even case
    if (i/2 < k && m[i/2] != -1)
      m[i] = 1 + m[i/2];
    else
      m[i] = 1 + reduce1(i/2);
  }
  return m[i];
}

int reduce(int n) {
  for (int x = 0; x <= n; x++)
    m.push_back(-1);
  m[0] = 0;
  m[1] = 0;
  int i = 2;
  while (i <= n) {
    m[i] = reduce1(i);
    i++;
  }
  for (int j = 0; j < m.size(); j++)
     cout << j << ":" << m[j] << " ";
  cout << endl;
  return m[n];
}

int main() {
  cout << reduce(115) << endl;
  return 0;
}
