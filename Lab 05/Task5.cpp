#include <iostream>
#define N 9
using namespace std;

bool validPlacement(int sudoku[N][N], int rowIdx, int colIdx, int digit) {
    for (int k = 0; k < N; k++) {
        if (sudoku[rowIdx][k] == digit || sudoku[k][colIdx] == digit)
            return false;
    }
    int boxStartRow = rowIdx - rowIdx % 3;
    int boxStartCol = colIdx - colIdx % 3;
    for (int p = 0; p < 3; p++) {
        for (int q = 0; q < 3; q++) {
            if (sudoku[boxStartRow + p][boxStartCol + q] == digit)
                return false;
        }
    }
    return true;
}

bool findBlank(int sudoku[N][N], int &rPos, int &cPos) {
    for (rPos = 0; rPos < N; rPos++) {
        for (cPos = 0; cPos < N; cPos++) {
            if (sudoku[rPos][cPos] == 0)
                return true;
        }
    }
    return false;
}

bool solveSudoku(int sudoku[N][N]) {
    int r, c;
    if (!findBlank(sudoku, r, c))
        return true;

    for (int val = 1; val <= 9; val++) {
        if (validPlacement(sudoku, r, c, val)) {
            sudoku[r][c] = val;
            if (solveSudoku(sudoku))
                return true;
            sudoku[r][c] = 0;
        }
    }
    return false;
}

void showSudoku(int sudoku[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cout << sudoku[r][c] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int board[N][N] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    cout << "Default/Unsolved Sudoku:\n";
    showSudoku(board);

    if (solveSudoku(board)) {
        cout << "\nCompleted Sudoku:\n";
        showSudoku(board);
    } else {
        cout << "\nInvalid Solution.\n";
    }

    return 0;
}