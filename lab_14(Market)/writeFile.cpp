#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Product
{
    string name = "Молоко";
    double price = 10;
    int quantity = 2;
};

int main()
{
    int arrayLength = 3;
    Product products[arrayLength] = {{"Product1", 124, 5},
                                     {"Product1", 20.0, 5},
                                     {"Product1", 10.0, 15}};

    string path = "file.txt";
    ofstream fout;

    fout.open(path);

    if (!fout.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }
    else
    {
        fout << arrayLength << endl;
        for (int i = 0; i < arrayLength; i++)
        {
            fout << products[i].name << " "
                 << products[i].price << " "
                 << products[i].quantity << "\n";
        }
    }
    fout.close();

    return 0;
}
