#include <iostream>
#include "CharString.h"

using namespace std;

int main() {
    cout << "--- 1. Створення об'єктів та тестування конструкторів ---" << endl;
    CharString str1("Hello");
    CharString str2("World");
    CharString str3(str1);
    CharString str4;
    
    cout << "\n--- 2. Перевірка друку та довжини ---" << endl;
    cout << "str1: " << str1 << " (Довжина: " << str1.length() << ")" << endl;
    cout << "str2: " << str2 << " (Довжина: " << str2.length() << ")" << endl;
    cout << "str3: " << str3 << endl;
    
    cout << "\n--- 3. Перевірка оператора присвоєння та функції копіювання ---" << endl;
    str4 = str2; 
    cout << "str4 після = str2: " << str4 << endl;
    
    CharString str5;
    str5.copyString(str1);
    cout << "str5 після copyString(str1): " << str5 << endl;

    cout << "\n--- 4. Перевірка операторів порівняння ---" << endl;
    cout << "str1 == str3: " << (str1 == str3 ? "Так" : "Ні") << endl;
    cout << "str1 != str2: " << (str1 != str2 ? "Так" : "Ні") << endl;
    cout << "str1 < str2 : " << (str1 < str2 ? "Так" : "Ні") << endl;
    
    cout << "\n--- 5. Перевірка зчеплення (оператор +) ---" << endl;
    CharString str6 = str1 + CharString(" ") + str2;
    cout << "str1 + \" \" + str2 = " << str6 << endl;

    cout << "\n--- 6. Перевірка вставки (insert) ---" << endl;
    CharString target("Program!");
    CharString insertPart("ming");
    cout << "Початковий рядок: " << target << endl;
    target.insert(insertPart, 7); // Вставка перед '!'
    cout << "Після вставки 'ming' на позицію 7: " << target << endl;

    cout << "\n--- 7. Перевірка видалення (remove) ---" << endl;
    target.remove(4, 7);
    cout << "Після видалення 4 символів з 7 позиції: " << target << endl;

    cout << "\n--- 8. Перевірка пошуку (find) ---" << endl;
    CharString searchSource("Find a substring here");
    CharString subStr("substring");
    int pos = searchSource.find(subStr);
    cout << "Рядок: '" << searchSource << "'" << endl;
    cout << "Індекс підрядка '" << subStr << "': " << pos << endl;

    cout << "\n--- Завершення роботи програми та виклик деструкторів ---" << endl;
    str4.clear();
    str4.length();
    return 0;
}