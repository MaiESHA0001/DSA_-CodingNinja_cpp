/*
Problem statement
Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= Length of String S <= 10^6

Sample Input :
abacd
a x
Sample Output :
xbxcd
  */
void replaceCharacter(char input[], char c1, char c2) {
    // Write your code here
     int i = 0;
    while (input[i] != '\0') {
        if (input[i] == c1) {
            input[i] = c2;
        }
        i++;
    }
}

/*  main code  */

#include <iostream>
#include <cstring>
using namespace std;

#include "solution.h"

int main() {
    char input[1000000];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    replaceCharacter(input, c1, c2);
    cout << input << endl;
}
