#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib> 
#include <ctime>   

// Звичайна функція, яка буде передана як вказівник
bool isOdd(int n) {
    return n % 2 != 0; // Повертає true, якщо число непарне
}

// Допоміжна функція для виводу списку на екран
void printList(const std::list<int>& lst) {
    for (int val : lst) { // Використовуємо range-based for для виводу елементів списку
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    // Класична ініціалізація генератора
    std::srand(std::time(NULL));

    // 1. Створити std::list на 20 елементів
    std::list<int> numbers(20);

    // 2. Заповнити список випадковим чином числами від 0 до 10
    
    std::generate(numbers.begin(), numbers.end(), [] () -> int {return std::rand() % 11;}); //заповнюємо список випадковими числами від 0 до 10 за допомогою лямбда-функції

    std::cout << "Початковий список (20 елементів від 0 до 10):\n";
    printList(numbers);

    // 3. Використати std::remove_if для обробки списку (видалення непарних)
    auto newEnd = std::remove_if(numbers.begin(), numbers.end(), isOdd); // Використовуємо звичайну функцію як вказівник. 
    
    // Фізично видаляємо елементи від нового кінця до фактичного кінця списку
    numbers.erase(newEnd, numbers.end());

    std::cout << "\nСписок після видалення непарних чисел:\n";
    printList(numbers);

    return 0;
    
    
};