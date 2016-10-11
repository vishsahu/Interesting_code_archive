#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    bitset<26> bits;
    string str;
    int i, j, l = 0, val;
    cin >> str;
    cout << str << endl;
    bits.reset();
    for (i = 0; i < str.length(); i++) {
        val = str[i];
        cout << val << endl;
        for (j = 0; j < 26; j++) {
            if (val == (65 + j) || val == (97 + j)) {
                bits.set(j);
                break;
            } 
        }
        cout << bits << endl;
        if (bits.count() == 26) {
            cout << "pangram";
            return 0;
        }
    
    }
    cout << "not pangram";
    return 0;
}
