#include <iostream>
using namespace std;

int count_ps(string s) {
	if (!s.length()) return 0;
    // odd length one
    int l, r, ans = 0;
    for (int i = 1; i < s.length()-1; i++) {
        l = i-1;
        r = i+1;
        while (l > -1 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
            ans++;
        }
    }
    // even length one
    for (int i = 0; i < s.length()-1; i++) {
        l = i;
        r = i+1;
        while (l > -1 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
            ans++;
        }
    }
    return ans + s.length();
}

int main() {
	string s = "abba";
	cout << count_ps(s) << endl;
	return 0;
}