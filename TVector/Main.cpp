#include "TVector.h"
#include <iostream>

int main() {
    int size1, size2;
    std::cout << "Enter first vector size: ";
    std::cin >> size1;
    TVector vec1(size1);
    vec1.input();
    std::cout << "First vector: ";
    vec1.output();

    std::cout << "Enter second vector size: ";
    std::cin >> size2;
    TVector vec2(size2);
    vec2.input();
    std::cout << "Second vector: ";
    vec2.output();

    if (vec1 == vec2) {
    std::cout << "Vectors are equal.\n";
    } else {
    std::cout << "Vectors are not equal.\n";
    }

     // Создаем массив значений для инициализации вектора
    double arr[] = {1.0, 2.0, 3.0};
    
    // Создаем вектор с помощью конструктора инициализатора
    TVector vec(3, arr);
    
    // Выводим значения вектора на экран
    vec.output();

    TVector vec3 = vec1 + vec2;
    std::cout << "Sum of vectors: ";
    vec3.output();

    double num;
    std::cout << "Enter a number to multiply the first vector by: ";
    std::cin >> num;
    TVector vec4 = vec1 * num;
    std::cout << "First vector multiplied by " << num << ": ";
    vec4.output();

    TVector vec5 = num * vec2;
    std::cout << "Second vector multiplied by " << num << ": ";
    vec5.output();

    std::cout << "Third element of the first vector is: " << vec1[2] << "\n";
    vec1[2] += 4;
    std::cout << "Third element of the first vector after adding 4: ";
    vec1.output();

    ++vec2;
    std::cout << "Second vector after prefix increment: ";
    vec2.output();

    vec2++;
    std::cout << "Second vector after postfix increment: ";
    vec2.output();

    --vec1;
    std::cout << "First vector after prefix decrement: ";
    vec1.output();

    vec1--;
    std::cout << "First vector after postfix decrement: ";
    vec1.output();

    double scalarProduct = vec1 * vec2;
    std::cout << "Scalar product of vectors: " << scalarProduct << "\n";

    return 0;
}

