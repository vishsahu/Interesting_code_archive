#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, size_t l, size_t mid, size_t r, vector<int>& aux) {
    if (a.size() <= 1)
        return;
    size_t i = mid + 1, j = 0, k = l;
    while (i <= r && j < aux.size()) {
        if (a[i] < aux[j])
          a[k++] = a[i++];
        else
          a[k++] = aux[j++];
    }
    while (i <= r)
        a[k++] = a[i++];
    while (j < aux.size())
        a[k++] = aux[j++];
}

void mergesort(vector<int>& a, size_t l, size_t r) {
   if (l >= r)
       return;
   int mid = l + (r-l)/2;
   mergesort(a, l, mid);
   mergesort(a, mid+1, r);
   vector<int> aux(a.begin() + l, a.begin() + mid + 1);
   merge(a, l, mid, r, aux);
}

int main() {
   int foo[] = {23,4,2,54,8,34,90,111,32,67,94,13,4};
   size_t n = sizeof(foo)/sizeof(int);
   vector<int> a(foo, foo + n);
   mergesort(a, 0, n-1);
   for (auto x : a)
     cout << x << " ";
   cout << endl;
   return 0;
}
