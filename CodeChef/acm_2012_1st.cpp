#include<iostream>
#include <fstream>
using namespace std;

main() {
	int max, p, indx;
	ifstream read("a.in");
	ofstream write("a.out");
	int tc;
	read >> tc; // number of test cases
	for (int i = 0; i < tc; i++) {
		// code here for a cases
		max = 0;
		read >> indx >> p;
		while (p != 1) {
            max = max < p ? p : max;
            if(p % 2 == 0) p = p>>1;
            else p = p*3 + 1;
        }
        if (max > p) write << indx << " " << max << endl;
        else write << indx << " " << 1 << endl;
	}
	read.close();
	write.close();
	
}