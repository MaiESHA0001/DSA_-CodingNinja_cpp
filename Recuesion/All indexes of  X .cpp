Problem statement
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in the output array (in increasing order).

Do this recursively. Indexing in the array starts from 0.

Hint:
Try making a helper function with the required arguments and call the helper function from the allIndexes function.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4

















  int allIndexes(int input[], int size, int x, int output[]) {
    if (size == 0) {
        return 0; // Base case: If array is empty, return 0
    }

    int smallOutput = allIndexes(input + 1, size - 1, x, output); // Recursive call

    // If x is found at the current index, update output array and return the count
    if (input[0] == x) {
        for (int i = smallOutput - 1; i >= 0; i--) {
            output[i + 1] = output[i] + 1;
        }
        output[0] = 0;
        return smallOutput + 1;
    } else {
        // If x is not found at the current index, simply increment the existing indexes in output array
        for (int i = 0; i < smallOutput; i++) {
            output[i]++;
        }
        return smallOutput;
    }
}



















#include<iostream>
#include "Solution.h"
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}




