Problem statement
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:

a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
abb
Sample Output 1 :
true
Sample Input 2 :
abababa
Sample Output 2 :
false

















  bool checkAB(char input[],char prev='\0') {
	// Write your code here
    if(input[0]=='\0')
        return true;
    else if(input[0]=='b' && prev=='\0')
        return false;
    else if(input[0]=='b' && prev=='b' && input[1]=='b')
        return false;
    else if(input[0]=='b' && prev!='b' && input[1]=='\0')
        return false;
    else if(input[0]=='b' && prev=='a' && input[1]!='b')
        return false;
    else
        return checkAB(input+1,input[0]);
    
}



















#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}

