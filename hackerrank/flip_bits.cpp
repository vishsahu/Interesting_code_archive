#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    unsigned int num, t, flipped = 0, i, bits = sizeof(unsigned int) * 8;
    unsigned int max = 0;
    for(i = 0; i < bits; i++)
        max |= (1 << i);

    cin >> t;
    while (t-- > 0) {
        flipped = 0;
        cin >> num;
        for (i = 0; i < bits; i++) {
            if (num & (1 << i)) 
                flipped &= (max ^ (1 << i));

            else
                flipped |= (1 << i);
        }
        cout << flipped << endl;
    }
    return 0;
}
