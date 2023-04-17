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
        if (product.quantity != 0)
        {
            cout << "Name: " << product.name << endl;
            cout << "Price: " << product.price << endl;
            cout << "Quantity: " << product.quantity << endl;
            cout << "----------------------------------------\n";
        }
    }
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

bool fileExists(const string &filename)
{
    ifstream file(filename);
    return file.good();
}

bool readProductsFromFile(string filename, Product *&products, int &count)
{
    if (fileExists(filename))
    {
        ifstream fin(filename);
        if (!fin.is_open())
        {
            cout << "Failed to open file" << endl;
            return false;
        }
        else
        {
            int productCount = countLinesInFile(filename);
            fin >> count;
            products = new Product[count];
            for (int i = 0; i < productCount - 1; ++i)
            {
                fin >> products[i].name >> products[i].price >> products[i].quantity;
            }
        }
        fin.close();
        return true;
    }
    else
    {
        ofstream file("file.txt");
        file.close();
    }
    return false;
}

int findProductIndex(Product *products, int count, const char *name)
{
    for (int i = 0; i < count; i++)
    {
        Product &product = products[i];
        if (strcmp(product.name, name) == 0)
        {
            return i;
        }
    }

    return -1;
}

bool isProductExists(Product *products, int count, const char *name)
{
    for (int i = 0; i < count; i++)
    {
        Product &product = products[i];
        if (strcmp(product.name, name) == 0)
        {
            return true;
        }
    }

    // If the product was not found in memory, check the file
    ifstream inputFile("products.txt");
    if (inputFile.is_open())
    {
        while (inputFile.good())
        {
            Product product;
            inputFile.read(reinterpret_cast<char *>(&product), sizeof(product));
            if (strcmp(product.name, name) == 0)
            {
                // Product found in file, add it to the array and return true
                products[count] = product;
                return true;
            }
        }
        inputFile.close();
    }

    return false;
}

void inputProduct(Product *products, int numProducts, int &productCount)
{
    cout << "Enter 'done' when finished." << endl;
    for (int i = productCount > 0 ? productCount : 0; i < numProducts; i++)
    {
        int countInput = 0;
        cout << "Product " << i + 1 << ":" << endl;
        cout << "Enter the name of product (20 symb is max): ";
        cin >> products[i].name;

        if (products[i].name != "done")
        {
            countInput++;
            productCount += countInput;
        }

        if (strcmp(products[i].name, "done") == 0)
        {
            break;
        }

        // Поиск продукта с таким же именем
        if (strcmp(products[i].name, "done") != 0 && !isProductExists(products, i, products[i].name))
        {
            // Продукт с таким именем не найден, добавляем новый продукт
            cout << "Enter the price of product: ";
            cin >> products[i].price;

            cout << "Enter the quantity of product: ";
            cin >> products[i].quantity;
        }
        else
        {
            // Продукт с таким именем уже существует, увеличиваем его количество

            int index = findProductIndex(products, i, products[i].name);
            cout << "Product already exists. Quantity will be increased." << endl;
            cout << "Enter the quantity of product: ";
            cin >> products[i].quantity;
            products[index].quantity += products[i].quantity;
        }
    }
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
            if (products[i].quantity != 0)
            {
                fout << products[i].name << " "
                     << products[i].price << " "
                     << products[i].quantity << "\n";
            }
        }
    }
    fout.close();
}

void purchaseProducts(Product *products, int count)
{
    const int MAX_PURCHASES = 100;
    Product purchases[MAX_PURCHASES];
    int purchasesCount = 0;
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

        int index = findProductIndex(products, count, name);
        if (index == -1)
        {
            cout << "Product not found." << endl;
            continue;
        }

        Product &product = products[index];
        int quantity;
        cout << "Enter the quantity of product: ";
        cin >> quantity;

        if (quantity > product.quantity)
        {
            cout << "Not enough products in stock." << endl;
            continue;
        }

        product.quantity -= quantity;
        totalCost += product.price * quantity;

        // Добавляем продукт в список покупок
        Product purchase = {0};
        strcpy_s(purchase.name, product.name);
        purchase.price = product.price;
        purchase.quantity = quantity;
        purchases[purchasesCount++] = purchase;
    }

    // Выводим список покупок и общий чек
    cout << "Purchases:\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < purchasesCount; i++)
    {
        const Product &product = purchases[i];
        cout << i + 1 << ". " << product.name << " " << product.price << "$ - " << product.quantity << endl;
    }
    cout << "----------------------------------------\n";
    cout << "Thank you for shopping with us!\n";
    cout << "Total cost: " << totalCost << "$\n";
}

int main()
{
    int productCount = 0;
    string filename = "file.txt";
    int numProducts = 0;
    int choice;
    Product *products = nullptr;

    readProductsFromFile(filename, products, numProducts);

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
                    inputProduct(products, numProducts, productCount);
                }
            }
            else
            {
                cout << "Enter the quantity of the product in stock: ";
                cin >> numProducts;
                products = new Product[numProducts];
                inputProduct(products, numProducts, productCount);
            }
            writeFile(products, productCount);

            break;
        case 2:
            readProductsFromFile(filename, products, numProducts);
            purchaseProducts(products, numProducts);
            writeFile(products, numProducts);
            readProductsFromFile(filename, products, numProducts);
            break;
        case 3:
            productCount = countLinesInFile(filename) - 1;
            readProductsFromFile(filename, products, productCount);
            // writeFile(products, numProducts);
            productCount = countLinesInFile(filename) - 1;
            outputProducts(products, productCount);
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