#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string ans;
	double a = 19.6253463;
	int intpart = floor(a);
	double fracpart = a - intpart;
	while (intpart) {
	    ans = to_string(intpart % 2) + ans;
	    intpart = intpart / 2;
	}
        ans += '.';

        int cnt = 10;
        while (fracpart && cnt--) {
            fracpart = fracpart * 2;
            int digit = fracpart / 1;
            ans = ans + to_string(digit);
            fracpart -= floor(fracpart);
        }

	cout << ans << endl;

	return 0;
}

