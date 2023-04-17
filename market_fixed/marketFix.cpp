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
    cout << "4. Exit.\n";
}

// int IndexProductInproducts(Product *products, char *name, int currentProducts)
// {

//     int index = -1;
//     for (int j = 0; j < currentProducts; j++)
//     {
//         bool other = true;
//         for (int i = 0; products[j].name[i] != '\0' || name[i] != '\0'; i++)
//         {
//             if (products[j].name[i] > name[i] || products[j].name[i] < name[i])
//             {
//                 other = false;
//                 break;
//             }
//         }
//         if (other)
//         {
//             index = j;
//         }
//     }
//     return index;
// }

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
    if (currentProducts < size)
    {
        char name[MAX];
        double price;
        int count;
        cout << "Enter the name of product: ";
        cin.ignore();
        cin.get(name, MAX);
        int index = findProductIndex(products, name, currentProducts);
        if (index == -1)
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
        else
        {
            int quantity;
            cout << "Product already exists. Quantity will be increased." << endl;
            cout << "Enter the quantity of product: ";
            cin >> quantity;
            products[index].count += quantity;
        }
        int answer;
        cout << "Add another product? 0 - No, 1 - Yes\nAnswer: ";
        cin >> answer;
        if (answer == 1)
        {
            input(products, currentProducts, size);
        }
    }
    else
    {
        cout << "Inventory is full" << endl;
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

// void purchaseProducts(product *products, int &currentProducts, list<product> &check)
// {
//     char name[MAX];
//     int index, answer;
//     double finalPrice = 0;
//     cout << "Введите имя товара: ";
//     cin.ignore(); // игнорирует \n
//     cin.get(name, MAX);

//     index = IndexProductInproducts(products, name, currentProducts);
//     if (index == -1)
//     {
//         cout << "\nТовара нет в списке\n";
//     }
//     else
//     {
//         product buy;
//         int count;
//         do
//         {
//             cout << "Введите количество товара: " << '\n';
//             cin >> count;
//         } while ((count <= 0) || (count > products->count));

//         strcpy_s(buy.name, name);
//         buy.count = count;
//         buy.price = products[index].price;

//         check.push_back(buy); // добавление в чек товара

//         products[index].count -= count;

//         if (products[index].count == 0)
//             productRemove(products, index, currentProducts);
//     }
//     cout << "Хотите купить другой товар? 1-да 2-нет\n";
//     cin >> answer;
//     if (answer == 1)
//         purchaseProducts(products, currentProducts, check);
//     else
//     {
//         cout << "Чек:\n";
//         for (product n : check)
//         {
//             cout << n.name << ' ' << n.price << ' ' << n.count << "шт"
//                  << "\n";
//             finalPrice += n.price * n.count;
//         }
//         cout << endl;
//         cout << "Итого: " << finalPrice << endl;
//     }
// }

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

        product.count -= quantity;
        if (products[index].count == 0)
        {
            productRemove(products, index, currentProducts);
        }
        totalCost += product.price * quantity;

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
}

void writeFile(ofstream &fileOut, int currentProducts, Product *products, int size)
{
    fileOut << size << endl;
    for (int i = 0; i < currentProducts; i++)
    {
        fileOut << products[i].name << endl;
        fileOut << products[i].price << endl;
        fileOut << products[i].count << endl;
    }
    fileOut.close();
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
        int i = 0;
        while (fileIn.getline(products[i].name, MAX) && fileIn >> products[i].price >> products[i].count)
        {
            fileIn.ignore();
            i++;
            currentProducts++;
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
            writeFile(fileOut, currentProducts, products, size);
            break;
        case 2:

            if (currentProducts == 0)
                cout << "Inventory is full.\n"
                     << endl;
            else
            {
                purchaseProducts(products, currentProducts);
            }
            writeFile(fileOut, currentProducts, products, size);
            break;

        case 3:
            outputProducts(products, currentProducts);
            writeFile(fileOut, currentProducts, products, size);
            break;

        case 4:
            cout << "Goodbye!\n";
            writeFile(fileOut, currentProducts, products, size);
            break;

        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    } while (answer != 4);

    delete[] products;

    return 0;
}
