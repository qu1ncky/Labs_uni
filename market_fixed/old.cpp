#include <iostream>
#include <fstream>
#include <limits>
#include <cstring>

using namespace std;

struct Product
{
    char name[21];
    double price;
    int quantity;
};

void printMenu()
{
    cout << "Select an option:\n";
    cout << "1. Add product to inventory.\n";
    cout << "2. Purchase a product.\n";
    cout << "3. Print the list of products.\n";
    cout << "4. Exit.\n";
}

// Функция для ввода данных товара
void inputProduct(Product &product)
{
    cout << "Enter the name of product (20 symb is max): ";
    cin >> product.name;

    cout << "Enter the price of product: ";
    cin >> product.price;

    cout << "Enter the quantity of product: ";
    cin >> product.quantity;

    // очистка буфера ввода, чтобы избежать проблем при следующем вводе
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void outputProducts(const Product *products, int count)
{
    if (count == 0)
    {
        cout << "The inventory is empty.\n";
        return;
    }
    cout << "Inventory:\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < count; i++)
    {
        const Product &product = products[i];
        cout << "Name: " << product.name << endl;
        cout << "Price: " << product.price << endl;
        cout << "Quantity: " << product.quantity << endl;
        cout << "----------------------------------------\n";
    }
}

int findProductIndex(const Product *products, int count, const char *name)
{
    for (int i = 0; i < count; i++)
    {
        const Product &product = products[i];
        if (strcmp(product.name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

void purchaseProducts(Product *products, int count)
{
    cout << "Enter the products you want to buy. Enter 'done' when finished." << endl;
    double totalCost = 0.0;
    while (true)
    {
        char name[21];
        cout << "Product name: ";
        cin >> name;

        if (strcmp(name, "done") == 0)
        {
            break;
        }

        int productIndex = findProductIndex(products, count, name);
        if (productIndex == -1)
        {
            cout << "Sorry, we don't have that product." << endl;
            continue;
        }

        Product &product = products[productIndex];
        int quantity;
        cout << "Enter quantity: ";
        cin >> quantity;

        if (quantity > product.quantity)
        {
            cout << "Sorry, we don't have that many " << name << "." << endl;
            continue;
        }

        product.quantity -= quantity;
        double cost = quantity * product.price;
        totalCost += cost;

        cout << "You purchased " << quantity << " " << name << " for $" << cost << "." << endl;
    }

    cout << "----------------------------------------\n";
    cout << "Thank you for shopping with us!" << endl;
    cout << "Total cost: $" << totalCost << endl;
    cout << "----------------------------------------\n";
}

bool fileExists(const string &filename)
{
    ifstream file(filename);
    return file.good();
}

void writeFile(Product *products, int numProducts)
{
    ofstream fout;
    fout.open("file.txt");

    if (!fout.is_open())
    {
        cout << "Reading error!" << endl;
    }
    else
    {
        fout << numProducts << endl;
        for (int i = 0; i < numProducts; i++)
        {
            fout << products[i].name << " "
                 << products[i].price << " "
                 << products[i].quantity << "\n";
        }
    }
    fout.close();
}

int countLinesInFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << filename << endl;
        return -1; // возвратить отрицательное значение в случае ошибки открытия файла
    }

    int productCount = 0;
    string line = " ";
    while (getline(file, line))
    {
        ++productCount;
    }

    return productCount;
}

int main()
{
    int productCount = 0;
    string filename = "file.txt";
    int numProducts = 0;
    int choice;
    Product *products = nullptr;

    if (fileExists(filename))
    {
        ifstream fin("file.txt");
        if (!fin.is_open())
        {
            cout << "Failed to open file" << endl;
            return 1;
        }
        else
        {
            productCount = countLinesInFile(filename);
            fin >> numProducts;
            products = new Product[numProducts];
            for (int i = 0; i < productCount - 1; ++i)
            {
                fin >> products[i].name >> products[i].price >> products[i].quantity;
            }
        }
        fin.close();
    }
    else
    {
        ofstream file("file.txt");
        file.close();
    }

    do
    {
        printMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            productCount = countLinesInFile(filename) - 1;
            if (numProducts > 0)
            {
                if (productCount >= numProducts)
                {
                    cout << "The inventory is full" << endl;
                }
                else
                {
                    for (int i = productCount; i < numProducts; i++)
                    {
                        cout << "Product " << i + 1 << ":" << endl;
                        inputProduct(products[i]);
                    }
                }
            }
            else
            {
                cout << "Enter the quantity of the product in stock: ";
                cin >> numProducts;
                products = new Product[numProducts];
                for (int i = 0; i < numProducts; i++)
                {
                    cout << "Product " << i + 1 << ":" << endl;
                    inputProduct(products[i]);
                }
            }
            writeFile(products, numProducts);
            break;
        case 2:

            purchaseProducts(products, numProducts);
            writeFile(products, numProducts);
            break;
        case 3:
            outputProducts(products, numProducts);
            writeFile(products, numProducts);
            break;
        case 4:
            cout << "Goodbye!\n";
            writeFile(products, numProducts);
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            writeFile(products, numProducts);
            break;
        }
    } while (choice != 4);

    delete[] products;

    return 0;
}