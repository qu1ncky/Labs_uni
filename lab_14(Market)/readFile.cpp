#include <fstream>
#include <iostream>

using namespace std;

struct Product
{
    char name[21];
    double price;
    int quantity;
};

bool fileExists()
{
    string filename = "file.txt";
    ifstream file(filename);

    if (!file.is_open())
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int arrayLength = 0;
    Product *products = nullptr;

    if (fileExists())
    {
        ifstream fin("file.txt");
        if (!fin.is_open())
        {
            cout << "Failed to open file" << endl;
            return 1;
        }
        else
        {
            fin >> arrayLength;
            products = new Product[arrayLength];
            for (int i = 0; i < arrayLength; ++i)
            {
                fin >> products[i].name >> products[i].price >> products[i].quantity;
            }
        }
        fin.close();
    }

    // Вывод на экран для проверки
    cout << "Size of inventory: " << arrayLength << endl;
    for (int i = 0; i < arrayLength; ++i)
    {
        cout << "Product " << i + 1 << ": "
             << products[i].name << ", "
             << products[i].price << ", "
             << products[i].quantity << endl;
    }

    // Освобождение памяти после использования массива
    delete[] products;

    return 0;
}
