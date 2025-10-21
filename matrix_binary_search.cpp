#include <iostream>
#include <vector>
using namespace std;

// Function to search target in sorted 2D matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = 0, high = rows * cols - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int value = matrix[mid / cols][mid % cols]; // map 1D index to 2D

        if (value == target)
            return true;
        else if (value < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main() {
    int rows, cols, target;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements (sorted row-wise and column-wise):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter target element to search: ";
    cin >> target;

    if (searchMatrix(matrix, target))
        cout << "✅ Element found in the matrix!" << endl;
    else
        cout << "❌ Element not found in the matrix." << endl;

    return 0;
}
