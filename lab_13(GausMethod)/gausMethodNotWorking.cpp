#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<double>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (const auto &elem : row)
        {
            cout << setw(10) << elem << " ";
        }
        cout << endl;
    }
}

void gaussianElimination(vector<vector<double>> &matrix)
{
    const int numRows = matrix.size();
    const int numCols = matrix[0].size();

    for (int i = 0; i < numRows - 1; ++i)
    {
        for (int j = i + 1; j < numRows; ++j)
        {
            const double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < numCols; ++k)
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    for (int i = numRows - 1; i >= 0; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            const double factor = matrix[j][i] / matrix[i][i];
            for (int k = numCols - 1; k >= i; --k)
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    for (int i = 0; i < numRows; ++i)
    {
        const double factor = 1 / matrix[i][i];
        for (int j = 0; j < numCols; ++j)
        {
            matrix[i][j] *= factor;
        }
    }
}

int main()
{
    int numRows, numCols;
    cout << "Enter the number of rows and columns: ";
    cin >> numRows >> numCols;

    vector<vector<double>> matrix(numRows, vector<double>(numCols));

    cout << "Enter the elements of the matrix:\n";
    for (auto &row : matrix)
    {
        for (auto &elem : row)
        {
            cin >> elem;
        }
    }

    cout << "Input matrix:\n";
    printMatrix(matrix);

    gaussianElimination(matrix);

    cout << "Solution matrix:\n";
    printMatrix(matrix);

    // Check the solution by substitution
    cout << "Check the solution by substitution:\n";
    for (int i = 0; i < numRows; ++i)
    {
        cout << "Equation " << i + 1 << ": ";
        for (int j = 0; j < numCols - 1; ++j)
        {
            cout << matrix[i][j] << " * x" << j + 1 << " + ";
        }
        cout << matrix[i][numCols - 1] << " = " << matrix[i][numCols - 1] << endl;
    }

    // Output the solutions
    cout << "The solutions are:\n";
    for (int i = 0; i < numRows; ++i)
    {
        cout << "x" << i + 1 << " = " << matrix[i][numCols - 1] << endl;
    }

    return 0;
}
