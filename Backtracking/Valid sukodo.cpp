Problem statement
You have been given a 9 X 9 2D matrix 'MATRIX' with some cells filled with digits(1 - 9), and some empty cells (denoted by 0).

You need to find whether there exists a way to fill all the empty cells with some digit(1 - 9) such that the final matrix is a valid Sudoku solution.

A Sudoku solution must satisfy all the following conditions-

1. Each of the digits 1 - 9 must occur exactly once in each row.
2. Each of the digits 1 - 9 must occur exactly once in each column.
3. Each of the digits 1 - 9 must occur exactly once in each of the 9, 3 x 3 sub-matrices of the matrix.
Note
1. There will always be a cell in the matrix which is empty.
2. The given initial matrix will always be consistent according to the rules mentioned in the problem statement.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'T' <= 5
N = 9
0 <= MATRIX[i][j] <= 9

Where 'N' denotes the size of the given square matrix.

Time Limit: 1sec
Sample Input 1:
1
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output 1:
yes
Explanation of the Sample Input1:
One of the possible solutions is:
9 4 1 3 2 6 7 5 8
6 3 7 1 5 8 2 4 9
8 2 5 4 9 7 6 1 3
2 6 8 7 1 4 3 9 5
1 7 4 5 3 9 8 6 2
3 5 9 6 8 2 4 7 1
4 1 3 2 6 5 9 8 7
5 9 6 8 7 3 1 2 4
7 8 2 9 4 1 5 3 6
Sample Input 2:
1
1 5 9 0 0 6 0 3 2
2 7 4 0 0 0 0 0 0
3 8 6 2 0 0 0 0 5
4 9 2 5 0 1 0 8 0
6 3 7 0 4 0 0 0 0
5 1 0 8 2 0 0 0 0
8 2 1 0 0 0 0 0 0
7 6 0 1 0 0 4 2 0
9 4 3 0 7 0 0 6 1
Sample Output 2:
no
Explanation of the Sample Input2:
In the third column from the left, there are two empty cells out of which one has to be filled with ‘8’, but we can’t put 8 in any of those two cells.

















  bool isValid(int row, int col, int num, int matrix[9][9]) {
    // Check if 'num' is already present in the row or column
    for (int i = 0; i < 9; ++i) {
        if (matrix[row][i] == num || matrix[i][col] == num) {
            return false;
        }
    }

    // Check within the 3x3 sub-matrix
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; ++i) {
        for (int j = startCol; j < startCol + 3; ++j) {
            if (matrix[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool isItSudoku(int matrix[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (matrix[i][j] == 0) { // Check empty cells
                for (int num = 1; num <= 9; ++num) {
                    if (isValid(i, j, num, matrix)) {
                        matrix[i][j] = num; // Try placing the number
                        if (isItSudoku(matrix)) {
                            return true;
                        }
                        matrix[i][j] = 0; // If not valid, backtrack
                    }
                }
                return false; // If no number can be placed, Sudoku is invalid
            }
        }
    }
    return true; // All cells filled and Sudoku is valid
}





















  #include <iostream>

using namespace std;

#include "solution.h"

int main() {
    int t;
    cin >> t;
    while(t--){
        int matrix[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cin >> matrix[i][j];
        }
        bool ans = isItSudoku(matrix);
        if (ans) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

}




