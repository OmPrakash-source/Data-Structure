#include <iostream>
#include <vector>
using namespace std;

// Function to check if a queen can be placed at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    // Check this row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i]) return false;
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) return false;
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueensUtil(vector<vector<int>>& board, int col, int N) {
    // Base case: If all queens are placed
    if (col >= N) return true;

    // Try placing a queen in each row of the current column
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;  // Place the queen

            // Recur to place queens in the next column
            if (solveNQueensUtil(board, col + 1, N)) return true;

            // If placing queen at board[i][col] doesn't lead to a solution, backtrack
            board[i][col] = 0;  // Remove the queen
        }
    }

    // If the queen can't be placed in any row in this column, return false
    return false;
}

// Function to print the solution
void printSolution(const vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Main function to solve the N-Queens problem
void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueensUtil(board, 0, N)) {
        printSolution(board, N);
    } else {
        cout << "No solution exists for " << N << " queens.\n";
    }
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    solveNQueens(N);

    return 0;
}
