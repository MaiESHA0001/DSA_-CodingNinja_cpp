Problem statement
You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.

Note :
Given array/list can contain duplicate elements.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= X <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
7
1 2 3 4 5 6 7 
12
Sample Output 1:
5
Sample Input 2:
2
7
1 2 3 4 5 6 7 
19
9
2 -5 8 -6 0 5 10 11 -3
10
Sample Output 2:
0
5













  

int pairSum(int *arr, int start, int end, int num) {
    int count = 0;
    for(; start < end;) {
         if(arr[start] + arr[end] < num) {
            start++;
        } else if (arr[start] + arr[end] > num) {
            end--;
        } else {
            int start_element = arr[start];
            int end_element =  arr[end];
            
            //if all the elements are same
            if(start_element == end_element) {
                int total = (end - start) + 1;
                count += ((total ) * (total - 1) ) / 2;  // n choose 2;
                return count;
            }
            
            int start_temp = start;
            int end_temp = end;
            
            for(;start_temp <= end_temp and arr[start_temp] == start_element;) {
               	start_temp++;
            }
            
            for(;start_temp <= end_temp and arr[end_temp] == end_element;) {
                end_temp--;
            }
            
            count += (start_temp - start) * (end - end_temp);
            start = start_temp;
            end = end_temp;
        }
    }
    
    return count;
}

int tripletSum(int *arr, int n, int num)
{
    sort(arr, arr + n);
    int numTriplets = 0;
    for (int i = 0; i < n; i++) {
        int pairSumFor = num - arr[i];
        int numPairs = pairSum(arr, (i + 1), (n - 1), pairSumFor);
        numTriplets += numPairs;
    }
    return numTriplets;
}





















#include <iostream>
#include <algorithm>
using namespace std;

#include "solution.h"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;
        

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}

