//MENGHITUNG DETERMINAN, ADJOIN, DAN INVERS DARI MATRIKS 3x3

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<vector<double>> Matrix;

Matrix inputMatrix() {
    Matrix matrix(3, vector<double>(3));
    for (int i = 0; i < 3; ++i) {
        cout << "Input elemen row " << i + 1 << ": ";
        for (int j = 0; j < 3; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

double determinant(const Matrix& matrix) {
    double det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])-
                 matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
                 matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    return det;
}

Matrix transpose(const Matrix& matrix) {
    Matrix transposed(3, vector<double>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            transposed[i][j] = matrix[j][i];
        }
    }
    return transposed;
}

Matrix cofactorMatrix(const Matrix& matrix) {
    Matrix cofactor(3, vector<double>(3));
    cofactor[0][0] = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]);
    cofactor[0][1] = -(matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
    cofactor[0][2] = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    cofactor[1][0] = -(matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1]);
    cofactor[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]);
    cofactor[1][2] = -(matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0]);
    cofactor[2][0] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]);
    cofactor[2][1] = -(matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0]);
    cofactor[2][2] = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    return cofactor;
}

Matrix adjoint(const Matrix& matrix) {
    return transpose(cofactorMatrix(matrix));
}

Matrix inverse(const Matrix& matrix) {
    double det = determinant(matrix);
    if (det == 0) {
        cout << "Invers tidak ada (determinan adalah nol).\n";
        return Matrix(3, vector<double>(3, 0));
    }
    Matrix adj = adjoint(matrix);
    Matrix inv(3, vector<double>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            inv[i][j] = adj[i][j] / det;
        }
    }
    return inv;
}

void printMatrix(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << setw(10) << elem << " ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "MENGHITUNG DETERMINAN, ADJOIN, DAN INVERS DARI MATRIKS 3x3\n";
    char choice = 'y';
    while (choice == 'y') {
        Matrix matrix = inputMatrix();
        cout << "Matriks yang diinput adalah:\n";
        printMatrix(matrix);
        cout << "Determinan: " << determinant(matrix) << "\n";
        cout << "Adjoin:\n";
        printMatrix(adjoint(matrix));
        cout << "Invers:\n";
        printMatrix(inverse(matrix));
        cout << "Apakah ingin input matriks lagi? (y/n): ";
        cin >> choice;
    }
    return 0;
}