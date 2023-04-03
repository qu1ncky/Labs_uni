#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void checkSolutions(double **matrix, int size)
{
    bool hasSolution = true;
    bool hasInfiniteSolutions = false;
    int rowWithNonZeroCoeff = -1;
    for (int i = 0; i < size; i++)
    {
        bool allZeros = true;
        int nonZeroCoeffCount = 0;
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] != 0)
            {
                allZeros = false;
                nonZeroCoeffCount++;
                if (nonZeroCoeffCount > 1)
                {
                    hasInfiniteSolutions = true;
                }
            }
        }
        if (allZeros && matrix[i][size] != 0)
        {
            hasSolution = false;
            cout << "No solution exists." << endl;
            break;
        }
        else if (allZeros && matrix[i][size] == 0)
        {
            hasInfiniteSolutions = true;
        }
        else if (nonZeroCoeffCount == 1)
        {
            rowWithNonZeroCoeff = i;
        }
    }

    if (hasSolution)
    {
        if (hasInfiniteSolutions)
        {
            cout << "There are infinite solutions." << endl;
        }
        else
        {
            cout << "Solution: ";
            double *solution = new double[size];
            for (int i = size - 1; i >= 0; i--)
            {
                double sum = 0;
                for (int j = i + 1; j < size; j++)
                {
                    sum += matrix[i][j] * solution[j];
                }
                solution[i] = (matrix[i][size] - sum) / matrix[i][i];
            }
            for (int i = 0; i < size; i++)
            {
                if (i == rowWithNonZeroCoeff)
                {
                    cout << "x" << i + 1 << " is free";
                }
                else
                {
                    cout << "x" << i + 1 << " = " << solution[i];
                }
                if (i < size - 1)
                {
                    cout << ", ";
                }
            }
            cout << endl;

            // substitution check
            for (int i = 0; i < size; i++)
            {
                double sum = 0;
                for (int j = 0; j < size; j++)
                {
                    sum += matrix[i][j] * solution[j];
                }
                cout << i + 1 << ". " << sum << " = " << matrix[i][size] << endl;
            }

            delete[] solution;
        }
    }
}

void printMatrix(double **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            cout << setw(8) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of the matrix: ";
    cin >> size;

    double **matrix = new double *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new double[size + 1];
    }

    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Gauss elimination method
    for (int i = 0; i < size - 1; i++)
    {
        // pivoting
        for (int j = i + 1; j < size; j++)
        {
            if (abs(matrix[i][i]) < abs(matrix[j][i]))
            {
                for (int k = 0; k <= size; k++)
                {
                    double temp = matrix[i][k];
                    matrix[i][k] = matrix[j][k];
                    matrix[j][k] = temp;
                }
            }
        }
        // elimination
        for (int j = i + 1; j < size; j++)
        {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k <= size; k++)
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
        // print intermediate matrix
        cout << "Intermediate matrix after step " << i + 1 << ":" << endl;
        printMatrix(matrix, size);
    }

    // back substitution
    double *solution = new double[size];
    for (int i = size - 1; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < size; j++)
        {
            sum += matrix[i][j] * solution[j];
        }
        solution[i] = (matrix[i][size] - sum) / matrix[i][i];
    }

    // print final matrix
    cout << "Final matrix:" << endl;
    printMatrix(matrix, size);

    // print solution
    cout << "Solution: ";
    for (int i = 0; i < size; i++)
    {
        cout << "x" << i + 1 << " = " << solution[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;

    // substitution check
    for (int i = 0; i < size; i++)
    {
        double sum = 0;
        for (int j = 0; j < size; j++)
        {
            sum += matrix[i][j] * solution[j];
        }
        cout << i + 1 << ". " << sum << " = " << matrix[i][size] << endl;
    }

    checkSolutions(matrix, size);

    // free memory
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}