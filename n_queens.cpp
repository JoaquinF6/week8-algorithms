#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<int>& board, int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[i] == row || 
            abs(board[i] - row) == abs(i - col)) {
            return false;
        }
    }
    return true;
}

bool solveNQueens(vector<int>& board, int col, int n) {
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col)) {
            board[col] = i;

            if (solveNQueens(board, col + 1, n))
                return true;
        }
    }

    return false;
}

int main() {
    int n;

    cout << "Numero de reinas: ";
    cin >> n;

    vector<int> board(n, -1);

    if (solveNQueens(board, 0, n)) {
        cout << "Solucion encontrada:\n";

        for (int i = 0; i < n; i++) {
            cout << "Columna " << i 
                 << " -> Fila " << board[i] << endl;
        }
    } else {
        cout << "No existe solucion\n";
    }

    return 0;
}
