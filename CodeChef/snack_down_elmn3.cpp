/*Mark has recently started studying string algorithms. So, as to gauge his knowledge, Lucy challenges him to a task.
"Given a string s, answer several times a query to determine whether a substring s[i, j] (inclusive) is palindromic or not.", said Lucy in a confident tone!
As smart as Mark is, he was able to instantly find the solution!
Now, Mark has challenged little Lucy to do the same task by reversing a specific substring beforehand. As Lucy is still just a novice, she asks for your help.
You have to write a program that answers Q queries on a string S.
Each query contains four integers (i, j, k, l).
For every query, first reverse the substring s[i, j] (inclusive) and then report if substring s[k, l] (inclusive) is a palindrome.
Note that the reversal operations are only for the specific query and should not persist for further queries. Please check the explanation section for better understanding.
Input:

The first line of input file contains string S. The next line contains an integer Q.
Each of the following Q lines each contain 4 space separated integers i, j, k and l.
Output:

Output exactly Q lines, each containing the result of corresponding query as "Yes" or "No".
Constraints:

1 ≤ |S| ≤ 105
1 ≤ Q ≤ 333333
1 ≤ i ≤ j ≤ |S|
1 ≤ k ≤ l ≤ |S|
S contains only the characters 'a' to 'z'
Example:

Sample Input:
ababa
4
2 3 3 4
1 2 3 4
1 3 3 5
2 4 1 5

Sample Output:
Yes
No
Yes
Yes
Explanation:

Query 1:
The string becomes aabba. The queried substring is bb, which is a palindrome.
Query 2:
The string becomes baaba. The queried substring is ab, which is not a palindrome.
Query 3:
The string becomes ababa. The queried substring is aba, which is a palindrome.
Query 4:
The string becomes ababa. The queried substring is ababa, which is a palindrome.
Notes:

Here, a substring [i, j] is defined as the string formed by characters s[i], s[i+1],..., s[j].
A palindrome is a sequence of characters which reads the same backward or forward. For example, aba, abba are palindromes, while abab and abcd are not palindromes.
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
