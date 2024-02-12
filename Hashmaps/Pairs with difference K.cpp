Problem statement
You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.

Note: Take absolute difference between the elements of the array.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= n <= 10^4
Time Limit: 1 sec
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2
Explanation
(5,2) and (1,4) are the possible combinations as their absolute difference is 3.
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
6














  #include <unordered_map>
int getPairsWithDifferenceK(int *input, int n, int k)
{
    // Write your code here
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
        m[input[i]]++;
    if (k != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (m.count(input[i] - k) > 0)
                count = count + m[input[i] - k];
        }
    }
    else if (k == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (m.count(input[i]) > 0)
            {
                count = count + m[input[i]];
                m[input[i]]--;
            }
            count--;
        }
    }
    return count;
}




















#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}

