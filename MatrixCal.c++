#include <iostream>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix() {
        cout << "\t\t\t\t\t\tMATRIX CALCULATOR\n";
        cout << "CHOOSE :\n1. Sum of matrices\n2. Subtraction of matrices\n3. Multiplication of matrices\n4. Transpose of matrix\n5. Upper triangle of matrix\n6. Lower triangle of matrix\n7. Diagonal Matrix\n8. Zero Matrix\n9. Identity matrix\n\n";
        cout << "Enter your option: ";
        cin >> operation;
        performOperation();
    }

private:
    int operation;

    // Read matrix elements from the user
    void readMatrix(vector<vector<int>>& matrix, int rows, int cols) {
        cout << "Enter elements of the matrix:\n";
        matrix.resize(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    // Print a matrix
    void printMatrix(const vector<vector<int>>& matrix) {
        for (const auto& row : matrix) {
            for (int value : row) {
                cout << value << ' ';
            }
            cout << '\n';
        }
    }

    // Matrix addition
    void sumMatrices() {
        int rows, cols;
        cout << "Enter the number of rows and columns: ";
        cin >> rows >> cols;

        vector<vector<int>> matrix1, matrix2;

        readMatrix(matrix1, rows, cols);
        readMatrix(matrix2, rows, cols);

        cout << "\nMatrix 1:\n";
        printMatrix(matrix1);

        cout << "\nMatrix 2:\n";
        printMatrix(matrix2);

        cout << "\nSum of Matrices:\n";
        vector<vector<int>> result(rows, vector<int>(cols));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        printMatrix(result);
    }

    // Matrix subtraction
    void subtractMatrices() {
        int rows, cols;
        cout << "Enter the number of rows and columns: ";
        cin >> rows >> cols;

        vector<vector<int>> matrix1, matrix2;

        readMatrix(matrix1, rows, cols);
        readMatrix(matrix2, rows, cols);

        cout << "\nMatrix 1:\n";
        printMatrix(matrix1);

        cout << "\nMatrix 2:\n";
        printMatrix(matrix2);

        cout << "\nSubtraction of Matrices:\n";
        vector<vector<int>> result(rows, vector<int>(cols));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }

        printMatrix(result);
    }

    // Matrix multiplication
    void multiplyMatrices() {
        int rows1, cols1, rows2, cols2;
        cout << "Enter the number of rows and columns for the first matrix: ";
        cin >> rows1 >> cols1;

        cout << "Enter the number of rows and columns for the second matrix: ";
        cin >> rows2 >> cols2;

        if (cols1 != rows2) {
            cout << "Matrix multiplication is not possible. Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n";
            return;
        }

        vector<vector<int>> matrix1, matrix2;

        readMatrix(matrix1, rows1, cols1);
        readMatrix(matrix2, rows2, cols2);

        cout << "\nMatrix 1:\n";
        printMatrix(matrix1);

        cout << "\nMatrix 2:\n";
        printMatrix(matrix2);

        cout << "\nMultiplication of Matrices:\n";
        vector<vector<int>> result(rows1, vector<int>(cols2, 0));

        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                for (int k = 0; k < cols1; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        printMatrix(result);
    }

    // Transpose of a matrix
    void transposeMatrix() {
        int rows, cols;
        cout << "Enter the number of rows and columns: ";
        cin >> rows >> cols;

        vector<vector<int>> matrix;

        readMatrix(matrix, rows, cols);

        cout << "\nMatrix:\n";
        printMatrix(matrix);

        cout << "\nTranspose of Matrix:\n";
        vector<vector<int>> result(cols, vector<int>(rows));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[j][i] = matrix[i][j];
            }
        }

        printMatrix(result);
    }

    // Upper triangle of a matrix
void upperTriangle() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix;

    readMatrix(matrix, rows, cols);

    cout << "\nMatrix:\n";
    printMatrix(matrix);

    cout << "\nUpper Triangle of Matrix:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j < i) {
                cout << "0 ";
            } else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << '\n';
    }
}

// Lower triangle of a matrix
void lowerTriangle() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix;

    readMatrix(matrix, rows, cols);

    cout << "\nMatrix:\n";
    printMatrix(matrix);

    cout << "\nLower Triangle of Matrix:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j > i) {
                cout << "0 ";
            } else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << '\n';
    }
}

// Diagonal matrix
void diagonalMatrix() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    cout << "\nEnter the diagonal elements:\n";

    vector<vector<int>> result(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        cin >> result[i][i];
    }

    cout << "\nDiagonal Matrix:\n";
    printMatrix(result);
}

// Zero matrix
void zeroMatrix() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    cout << "\nZero Matrix:\n";
    vector<vector<int>> result(rows, vector<int>(cols, 0));

    printMatrix(result);
}

// Identity matrix
void identityMatrix() {
    int n;
    cout << "Enter the size of the identity matrix: ";
    cin >> n;

    cout << "\nIdentity Matrix:\n";
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }

    printMatrix(result);
}


    // Perform the selected matrix operation
    void performOperation() {
        switch (operation) {
            case 1:
                sumMatrices();
                break;
            case 2:
                subtractMatrices();
                break;
            case 3:
                multiplyMatrices();
                break;
            case 4:
                transposeMatrix();
                break;
            case 5:
                upperTriangle();
                break;
            case 6:
                lowerTriangle();
                break;
            case 7:
                diagonalMatrix();
                break;
            case 8:
                zeroMatrix();
                break;
            case 9:
                identityMatrix();
                break;
            default:
                cout << "\n\n\n\n\n\t\t\t\t\tWRONG DECISION....ERROR 404!!!\n\n\n\n\n";
        }
    }
};

int main() {
    Matrix obj;
    return 0;
}
