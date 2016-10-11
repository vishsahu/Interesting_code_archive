#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void nextPermutation(string s) {
   /* approach here is to find next bigger number. If not found,
   just reverse the number. To find next bigger, we look for pair
   which gives positive slope. Then swap it with smallest numbers
   which is greater than the number to be swapped. finally sort
   right part in increasing order */
   int i = s.length() - 1;
   while (i > 0) {
      if (s[i-1] < s[i]) {
         int mini = i, j = i;
         while (j < s.length()) {
            if (s[j] > s[i-1])
               mini = s[mini] > s[j] ? j : mini;
            j++;
         }
         swap(s[i-1], s[mini]);
         sort(s.begin() + i, s.end());
         cout << s << endl;
         return;
      }
      i--;
   }
   reverse(s.begin(), s.end());
   cout << s << endl;
   return;
}

int main() {
   string s;
   int t;
   cin >> t;
   while (t-- > 0) {
      cin >> s;
      nextPermutation(s);
   }
   return 0;
}

