  #include <iostream>
  #include "TCompl.h"
  
  int main() {
      // Создание объектов комплексных чисел
      TCompl c1(2.0, 3.0);
      TCompl c2(1.0, 2.0);
  
      // Сложение комплексных чисел
      TCompl sum = c1 + c2;
      std::cout << "Сумма: ";
      sum.print();
  
      // Вычитание комплексных чисел
      TCompl diff = c1 - c2;
      std::cout << "Разность: ";
      diff.print();
  
      // Умножение комплексных чисел
      TCompl prod = c1 * c2;
      std::cout << "Произведение: ";
      prod.print();
  
      // Деление комплексных чисел
      TCompl quotient = c1 / c2;
      std::cout << "Частное: ";
      quotient.print();
  
      // Использование перегрузки оператора +
      TCompl sum2 = c1 + 2.5;
      std::cout << "Сумма с числом: ";
      sum2.print();
  
      // Использование перегрузки оператора +
  	TCompl diff3 = c1 - 2.5;
  	std::cout << "Разность с числом (комплексное - число): ";
  	diff3.print();
  
      //Использование ввода
      TCompl c3;
      c3.input();
  
      // Вывод введенного комплексного числа
      std::cout << "Введенное комплексное число: ";
      c3.print();
  
      return 0;
  }
  