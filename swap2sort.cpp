/*
given an array of integers, indicate if it can be sorted by just one
swap
*/

#include <iostream>
#include <vector>
using namespace std;

bool swapToSort(vector<int>& a) {
   bool seen = false;
   for (int i = 0; i < a.size() - 1; i++) {
      if (a[i] > a[i+1]) { // first inverted pair
         if (seen)
            return false;
         int j = i + 2;
         while (j < a.size() && a[j] >= a[i+1])
            j++;
         if (j >= a.size())
            return false;
         swap(a[j], a[i]);
         seen = true;
         }
      }
   }
   return true;
}

int main() {
   // code here
   return 0;
}
