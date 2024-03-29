/*
Problem statement
You are given a matrix ‘MAT’. Print the transpose of the matrix. The transpose of a matrix is obtained by changing rows to columns and columns to rows. In other words, transpose of a matrix A[][] is obtained by changing A[i][j] to A[j][i].

For example:
Let matrix be : 
1 2
3 4

Then transpose of the matrix will be: 
1 3
2 4
Note:
You don't have to return anything just complete the function and print the final output.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= M, N <= 3*10^3
0 <= MAT[i][j] <= 10^7

Time Limit: 1 sec
Sample Input 1 :
2 2
1 2
3 4
Sample Output 1 :
1 3
2 4
Explanation For Sample Input 1 :
The transpose of the matrix will be: 
1 3
2 4
Sample Input 2 :
2 3
1 2 3 
3 4 5
Sample Output 2 :
1 3
2 4 
3 5
void transpose(int row,int col,int input[][1001]) {
    // Creating a new matrix to store the transpose
    int transposed[col][row];

    // Transposing the matrix
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            transposed[i][j] = input[j][i];
        }
    }

*/

void transpose(int row,int col,int input[][1001]) {
    // Creating a new matrix to store the transpose
    int transposed[col][row];

    // Transposing the matrix
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            transposed[i][j] = input[j][i];
        }
    }

    // Printing the transposed matrix
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            std::cout << transposed[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/* main code */

#include<iostream>
using namespace std;

#include "solution.h"
int main(){
    int row,col;
    cin>>row>>col;
    int input[row][1001];

    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            
            cin>>input[i][j];
        }
    }
    transpose(row,col,input);
}
