#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int rows, cols;
    cout << "Enter the number of lines: ";
    cin >> rows;
    cout << "Enter the number of colums: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    srand(time(nullptr));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 9 + 1;
        }
    }

    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int totalSum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            totalSum += matrix[i][j];
        }
    }
    cout << "Sum of all cells: " << totalSum << endl;

    cout << "Amounts for each line:" << endl;
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Line " << i + 1 << ": " << rowSum << endl;
    }

    cout << "Amounts for each column:" << endl;
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += matrix[i][j];
        }
        cout << "Column " << j + 1 << ": " << colSum << endl;
    }

    int mainDiagonalSum = 0;
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < rows; i++) {
        mainDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][cols - i - 1];
    }
    cout << "Sum along the main diagonal: " << mainDiagonalSum << endl;
    cout << "Sum along side diagonal: " << secondaryDiagonalSum << endl;

    cout << "Inverted Matrix:" << endl;
    for (int j = cols - 1; j >= 0; j--) {
        for (int i = 0; i < rows; i++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}