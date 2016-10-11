/*Chef likes to play table tennis. He found some statistics of matches which described who won the points in order. A game shall be won by the player first scoring 11 points except in the case when both players have 10 points each, then the game shall be won by the first player subsequently gaining a lead of 2 points. Could you please help the Chef find out who the winner was from the given statistics? (It is guaranteed that statistics represent always a valid, finished match.)
Input

The first line of the input contains an integer T, denoting the number of test cases. The description of T test cases follows. Each test case consist a binary string S, which describes a match. '0' means Chef lose a point, whereas '1' means he won the point.
Output

For each test case, output on a separate line a string describing who won the match. If Chef won then print "WIN" (without quotes), otherwise print "LOSE" (without quotes).
Constraints

1 ≤ T ≤ 1000
1 ≤ length(S) ≤ 100

Example

Input:
2
0101111111111
11100000000000

Output:
WIN
LOSE
Explanation

Example case 1. Chef won the match 11:2, his opponent won just two points, the first and the third of the match.
Example case 2. Chef lost this match 11:3, however he started very well the match, he won the first three points in a row, but maybe he got tired and after that lost 11 points in a row.
*/


#include<iostream>
using namespace std;
#include<cstring>
#include<fstream>

int main(){
    int tc, flag,i,chef,opp;
    string s;
    //ifstream in;    // Create an input file stream.
    //in.open("sn_down_elmn_1.txt");  // Use it to read from a file named data.txt.
    cin >> tc;    // Read the first item from the file into an integer variable x.

    while(tc-- >0)
    {
        flag = 0;
        chef = 0;
        opp =0;
        cin >> s;  // Read the next item from the file into a string variable str
        for(i=0;s[i] != '\n';i++)
        {
            if(s[i] == '1') chef++;
            else opp++;
            if(chef == 10 & opp == 10){
                chef = 0;
                opp = 0;
                flag = 1;
            }
            if(chef == 11 | (chef == 2 & flag == 1)){
                printf("WIN\n");
                break;
            }
            if(opp == 11 | (opp == 2 & flag == 1)){
                printf("LOSE\n");
                break;
            }
        }
    }
    return 0;
}
