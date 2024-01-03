/*
Problem statement
Given a string, determine if it is a palindrome, considering only alphanumeric characters.

Palindrome
A palindrome is a word, number, phrase, or other sequences of characters which read the same backwards and forwards.
Example:
If the input string happens to be, "malayalam" then as we see that this word can be read the same as forward and backwards, it is said to be a valid palindrome.

The expected output for this example will print, 'Palindrome'.
From that being said, you are required to return a boolean value from the function that has been asked to implement.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1 :
abcdcba
Sample Output 1 :
Palindrome 
Sample Input 2:
coding
Sample Output 2:
Not a Palindrome

bool checkPalindrome(string str) {
     string a=str;
    for(int i=0; i < a; i++)
    {
    if(str==a)
    {
        return true;
    }
    else


*/
bool checkPalindrome(string str) {
     string a=str;
    for(int i=0; i < a; i++)
    {
    if(str==a)
    {
        return true;
    }
    else
    {
        return false;
    }




#include<bits/stdc++.h>
using namespace std;

#include "solution.h"

int main(){
    string a;
    cin>>a;
    cout << (checkPalindrome(a) ? "Palindrome" : "Not a Palindrome");
}
