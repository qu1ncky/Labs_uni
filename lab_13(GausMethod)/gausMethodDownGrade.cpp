#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n; // number of rows and columns of the matrix
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> n;

    // initialize the matrix and the right-hand side vector
    double A[n][n];
    double b[n];
    cout << "Enter the matrix and right-hand side vector:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
        cin >> b[i];
    }

    // perform Gauss elimination
    for (int k = 0; k < n - 1; k++)
    {
        for (int i = k + 1; i < n; i++)
        {
            double factor = A[i][k] / A[k][k];
            for (int j = k; j < n; j++)
            {
                A[i][j] -= factor * A[k][j];
            }
            b[i] -= factor * b[k];
        }
    }

    // perform back substitution
    double x[n];
    x[n - 1] = b[n - 1] / A[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }

    // output the solution
    cout << "The solution is:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    // check the solution by substitution
    cout << "Checking the solution by substitution:\n";
    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += A[i][j] * x[j];
        }
        cout << "Equation " << i + 1 << ": " << sum << " = " << b[i] << endl;
    }

    return 0;
}
