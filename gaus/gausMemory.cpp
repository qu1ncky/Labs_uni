#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> n;

    double **matrix = new double *[n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new double[n + 1];

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n; ++j)
            cin >> matrix[i][j];

    cout << "Entered matrix:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= n; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    // Gauss elimination
    for (int k = 0; k < n; ++k)
    {
        double pivot = matrix[k][k];
        bool singular = true;
        for (int i = k + 1; i < n; ++i)
        {
            if (abs(matrix[i][k]) > abs(pivot))
            {
                swap(matrix[k], matrix[i]);
                singular = false;
                break;
            }
        }
        if (singular)
        {
            cout << "The matrix is singular or the equations are dependent." << endl;
            return 0;
        }

        for (int i = k + 1; i < n; ++i)
        {
            double factor = matrix[i][k] / pivot;
            for (int j = k + 1; j <= n; ++j)
                matrix[i][j] -= factor * matrix[k][j];
        }

        cout << "Step " << k + 1 << ":" << endl;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }

    // Back substitution
    double *result = new double[n];
    for (int i = n - 1; i >= 0; --i)
    {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j)
            sum += matrix[i][j] * result[j];
        result[i] = (matrix[i][n] - sum) / matrix[i][i];
    }

    // Print results
    cout << "Substitution test:" << endl;
    for (int i = 0; i < n; ++i)
    {
        double sum = 0.0;
        for (int j = 0; j < n; ++j)
            sum += matrix[i][j] * result[j];
        cout << "Row " << i + 1 << ": " << sum << " = " << matrix[i][n] << endl;
    }

    cout << "Solution:" << endl;
    for (int i = 0; i < n; ++i)
        cout << "x" << i + 1 << " = " << result[i] << endl;

    // Deallocate memory
    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;
    delete[] result;

    return 0;
}
