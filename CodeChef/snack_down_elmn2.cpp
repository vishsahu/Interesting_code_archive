/*Chef Zidane likes the number 9. He has a number N, and he wants to turn it into a multiple of 9. He cannot add or remove digits, and he can only change one digit at a time. The only allowed operation is to increment or decrement a digit by one, and doing this takes exactly one second. Note that he cannot increase a digit 9 or decrease a digit 0, and the resulting number must not contain any leading zeroes unless N has a single digit.
Chef Zidane wants to know the minimum amount of time (in seconds) needed to accomplish this. Please help him, before his kitchen gets overwhelmed with mist!
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case consists of one line containing a single positive integer N.
Output

For each test case, output a single line containing the answer.
Constraints

1 ≤ T ≤ 105
1 ≤ N ≤ 10105
N will not contain leading zeroes.
Each test file is at most 3Mb in size.
Example

Input:
4
1989
86236
90210
99999999999999999999999999999999999999988


Output:
0
2
3
2

Explanation

Example case 1. 1989 is already divisible by 9, so no operations are needed to be performed.
Example case 2. 86236 can be turned into a multiple of 9 by incrementing the first and third digit (from the left), to get 96336. This takes 2 seconds.
Example case 3. 90210 can be turned into a multiple of 9 by decrementing the third digit twice and the fourth digit once, to get 90000. This takes 3 seconds.
*/


#include<iostream>
using namespace std;
#include<cstring>
//#include<fstream>
#include<stdlib.h>

int main(){
    int tc,i,diff,length;
    long long int sum;
    string s;
    cin >> tc;    // Read the first item from the file into an integer variable x.

    while(tc-- >0)
    {
        sum = 0;
        cin >> s;  // Read the next item from the file into a string variable str
        length = s.length();
        cout<<length<<endl;
        for(i=0;i<length;i++) sum += (s[i]-'0');
        diff = sum%9; // if 0,1,2,3,4
        if(diff<5) cout<<diff<<endl;
        else cout<<9-diff<<endl;
    }
    return 0;
}
