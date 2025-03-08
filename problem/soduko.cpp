#include <iostream>
#include <vector>

#define N 9 // Size of the Sudoku sudoku (9x9)

using namespace std;

// Function to print the Sudoku sudoku
void printGrid(const vector<vector<int>>& sudoku) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << sudoku[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if a number can be placed at a given position
bool isSafe(const vector<vector<int>>& sudoku, int row, int col, int num) {
    // Check the row
    for (int x = 0; x < N; x++) {
        if (sudoku[row][x] == num) {
            return false;
        }
    }

    // Check the column
    for (int x = 0; x < N; x++) {
        if (sudoku[x][col] == num) {
            return false;
        }
    }

    // Check the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(vector<vector<int>>& sudoku, int row, int col) {
    // If we reached the end, the puzzle is solved
    if (row == N - 1 && col == N) {
        return true;
    }

    // Move to column
    if (col == N) {
        row++;
        col = 0;
    }

    // Skip cells that are already filled
    if (sudoku[row][col] != 0) {
        return solveSudoku(sudoku, row, col + 1);
    }

    // Try placing numbers 1-9 in the cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(sudoku, row, col, num)) {
            sudoku[row][col] = num;

            // Recurse to solve the rest of the sudoku
            if (solveSudoku(sudoku, row, col + 1)) {
                return true;
            }

            // Backtrack if the number doesn't lead to a solution
            sudoku[row][col] = 0;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(sudoku, 0, 0)) {
        printGrid(sudoku);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}

