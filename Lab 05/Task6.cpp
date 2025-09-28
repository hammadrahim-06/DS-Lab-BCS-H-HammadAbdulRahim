#include <iostream>
using namespace std;

#define N 5   

void showPath(int path[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cout << path[r][c] << " ";
        }
        cout << "\n";
    }
}

bool move(int maze[N][N], int r, int c, int used[N][N]) {
    return (r >= 0 && r < N && c >= 0 && c < N && maze[r][c] == 1 && used[r][c] == 0);
}

int dRow[4] = {1, -1, 0, 0};   // up, down, left, right
int dCol[4] = {0, 0, 1, -1};

bool explore(int maze[N][N], int r, int c, int path[N][N], int used[N][N]) {
    if (r == N - 1 && c == N - 1) {
        path[r][c] = 1;
        return true;
    }

    if (move(maze, r, c, used)) {
        path[r][c] = 1;
        used[r][c] = 1;

        for (int step = 0; step < 4; step++) {
            int nr = r + dRow[step];
            int nc = c + dCol[step];
            if (explore(maze, nr, nc, path, used))
                return true;
        }

        path[r][c] = 0;   
        used[r][c] = 0;
    }
    return false;
}

void solve(int maze[N][N]) {
    int path[N][N] = {0};
    int used[N][N] = {0};

    if (explore(maze, 0, 0, path, used)) {
        cout << "Path found (rat moves in 4 directions):\n";
        showPath(path);
    } else {
        cout << "No valid path exists\n";
    }
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1}
    };

    solve(maze);
    return 0;
}