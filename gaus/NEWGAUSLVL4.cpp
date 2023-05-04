#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPS = 1e-10; // Константа для сравнения с нулем

void printMatrix(double **a, int n, int m)
{
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(10) << a[i][j] << " ";
        }
        cout << endl;
    }
}

void gauss(double **a, int n, int m)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        int sel = i;
        for (j = i + 1; j < n; j++)
            if (abs(a[j][i]) > abs(a[sel][i]))
                sel = j;
        if (abs(a[sel][i]) < EPS)
            continue;
        swap(a[i], a[sel]);

        // вывод промежуточного шага
        cout << "Step " << i + 1 << ":" << endl;
        printMatrix(a, n, m);
        cout << endl;

        for (j = i + 1; j < n; j++)
        {
            double c = a[j][i] / a[i][i];
            for (k = i; k < m; k++)
                a[j][k] -= c * a[i][k];
        }
    }

    // разделительная строка
    cout << "-----------------------------------------" << endl;

    for (i = n - 1; i >= 0; i--)
    {
        if (abs(a[i][i]) < EPS)
            continue;
        for (j = i - 1; j >= 0; j--)
        {
            double c = a[j][i] / a[i][i];
            for (k = i; k < m; k++)
                a[j][k] -= c * a[i][k];
        }
    }

    // разделительная строка
    cout << "-----------------------------------------" << endl;

    for (i = 0; i < n; i++)
    {
        if (abs(a[i][i]) < EPS)
        {
            bool flag = true;
            for (j = i + 1; j < m - 1; j++)
            {
                if (abs(a[i][j]) > EPS)
                {
                    flag = false;
                    break;
                }
            }
            if (flag && abs(a[i][m - 1]) > EPS)
            {
                cout << "No solutions" << endl;
                return;
            }
            cout << "Infinite solutions" << endl;
            return;
        }
    }

    // разделительная строка
    cout << "-----------------------------------------" << endl;

    for (i = 0; i < n; i++)
    {
        double x = a[i][m - 1] / a[i][i];
        cout << "x" << i + 1 << " = " << x << endl;
    }
}

int main()
{
    int n, m;
    cout << "Enter the dimensions of the matrix (rows and columns): ";
    cin >> n >> m;
    double **matrix = new double *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new double[m];
        cout << "Enter the elements " << i + 1 << " -th line: ";
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    gauss(matrix, n, m);
    // Освобождаем память
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}