#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#define MAX 20

using namespace std;

struct Product
{
    char name[MAX];
    double price;
    int count;
};

void printMenu()
{
    cout << "Select an option:\n";
    cout << "1. Add product to inventory.\n";
    cout << "2. Purchase a product.\n";
    cout << "3. Print the list of products.\n";
    cout << "4. Exit.\n\n";
}

int findProductIndex(Product *products, char *name, int currentProducts)
{
    for (int i = 0; i < currentProducts; i++)
    {
        Product &product = products[i];
        if (strcmp(product.name, name) == 0)
        {
            return i;
        }
    }

    return -1;
}

void input(Product *products, int &currentProducts, int size)
{

    char name[MAX];
    double price;
    int count;
    cout << "Enter the name of product: ";
    cin.ignore();
    cin.get(name, MAX);
    int index = findProductIndex(products, name, currentProducts);

    if (index == -1 && currentProducts < size)
    {
        strcpy_s(products[currentProducts].name, name);
        do
        {
            cout << "Enter the price of product: ";
            cin >> price;
        } while (price <= 0);
        products[currentProducts].price = price;
        do
        {
            cout << "Enter the quantity of product: ";
            cin >> count;
        } while (count <= 0);
        products[currentProducts].count = count;

        currentProducts++;
    }
    if (index != -1 && currentProducts <= size)
    {
        int quantity;
        cout << "Product already exists. Quantity will be increased." << endl;
        cout << "Enter the quantity of product: ";
        cin >> quantity;
        products[index].count += quantity;
    }
    else
    {
        cout << "Inventory is full" << endl;
    }

    int answer;
    cout << "Add another product? 0 - No, 1 - Yes\nAnswer: ";
    cin >> answer;
    if (answer == 1)
    {
        input(products, currentProducts, size);
    }
}

bool fileExists(const string &filename)
{
    ifstream file(filename);
    return file.good();
}

void productRemove(Product *products, int index, int &currentProducts)
{
    for (int i = index; i < currentProducts - 1; i++)
    {
        swap(products[i], products[i + 1]);
    }
    currentProducts--;
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
        if (product.count != 0)
        {
            cout << "Name: " << product.name << endl;
            cout << "Price: " << product.price << endl;
            cout << "Quantity: " << product.count << endl;
            cout << "----------------------------------------\n";
        }
    }
}

void purchaseProducts(Product *products, int &currentProducts)
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

        int index = findProductIndex(products, name, currentProducts);
        if (index == -1)
        {
            cout << "Product not found." << endl;
            continue;
        }

        Product &product = products[index];
        int quantity;
        cout << "Enter the quantity of product: ";
        cin >> quantity;

        if (quantity > product.count)
        {
            cout << "Not enough products in stock." << endl;
            continue;
        }

        totalCost += product.price * quantity;
        product.count -= quantity;

        // Проверяем, есть ли продукт уже в списке покупок
        bool found = false;
        for (int i = 0; i < purchasesCount; i++)
        {
            if (strcmp(purchases[i].name, product.name) == 0)
            {
                // Если продукт уже есть в списке, увеличиваем его количество
                purchases[i].count += quantity;
                found = true;
                break;
            }
        }

        if (!found)
        {
            // Если продукт еще не был добавлен в список, добавляем его
            Product purchase = {0};
            strcpy_s(purchase.name, product.name);
            purchase.price = product.price;
            purchase.count = quantity;
            purchases[purchasesCount++] = purchase;
        }

        if (products[index].count == 0)
        {
            productRemove(products, index, currentProducts);
        }
    }

    // Выводим список покупок и общий чек
    cout << "Purchases:\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < purchasesCount; i++)
    {
        const Product &product = purchases[i];
        cout << i + 1 << ". " << product.name << " " << product.price << "$ - " << product.count << endl;
    }
    cout << "----------------------------------------\n";
    cout << "Thank you for shopping with us!\n";
    cout << "Total cost: " << totalCost << "$\n";
    cout << "----------------------------------------\n";
}

void writeToFile(Product *products, int size, int currentProducts, string filename)
{
    ofstream fout(filename);

    if (fout.is_open())
    {
        fout << size << endl;
        for (int i = 0; i < currentProducts; i++)
        {
            fout << products[i].name << " " << products[i].price << " " << products[i].count << endl;
        }
        fout.close();
        cout << "Data saved to file." << endl
             << endl;
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}

int countLinesInFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << filename << endl;
        return -1;
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
    string filename = "file.txt";
    ifstream fileIn(filename);
    Product *products = nullptr;
    int answer, size;
    int currentProducts = 0;

    if (!fileExists(filename))
    {
        do
        {
            cout << "Enter the quantity of the product in stock: " << endl;
            cin >> size;
        } while (size <= 0);
    }
    else
    {
        fileIn >> size;
        fileIn.ignore();
    }
    products = new Product[size];

    if (fileExists(filename))
    {
        currentProducts = countLinesInFile(filename) - 1;
        for (int i = 0; i < currentProducts; i++)
        {
            fileIn.getline(products[i].name, MAX, ' ');
            fileIn >> products[i].price >> products[i].count;
            fileIn.ignore();
        }
    }
    fileIn.close();
    ofstream fileOut(filename);

    do
    {
        printMenu();
        cin >> answer;

        switch (answer)
        {
        case 1:

            input(products, currentProducts, size);
            writeToFile(products, size, currentProducts, filename);
            break;
        case 2:

            if (currentProducts == 0)
                cout << "Inventory is full.\n"
                     << endl;
            else
            {
                purchaseProducts(products, currentProducts);
            }
            writeToFile(products, size, currentProducts, filename);
            break;

        case 3:
            outputProducts(products, currentProducts);
            writeToFile(products, size, currentProducts, filename);
            break;

        case 4:
            cout << "Goodbye!\n";
            writeToFile(products, size, currentProducts, filename);
            break;

        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    } while (answer != 4);

    delete[] products;

    return 0;
}