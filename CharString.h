#ifndef CHARSTRING_H
#define CHARSTRING_H

#include <iostream>

class CharString {
private:
    // Структура вузла однонапрямленого зв'язного списку
    struct Node {
        char data;
        Node* next;
        Node(char c, Node* n = nullptr) : data(c), next(n) {}
    };

    Node* head;

    // Допоміжні внутрішні методи
 
    Node* copyList(Node* otherHead) const;
    int compareTo(const CharString& other) const;

public:
    void clear();
    // Конструктори та деструктор
    CharString();                             
    CharString(const char* str);              
    CharString(const CharString& other);        
    ~CharString();                             

    // Оператор присвоєння
    CharString& operator=(const CharString& other);

    // Функції-члени класу згідно з варіантом 4
    void copyString(const CharString& other);
    void remove(int n, int poz);
    void insert(const CharString& st1, int poz);
    int length() const;
    int find(const CharString& st1) const;

    // Перезавантажені оператори (дружні функції)
    friend CharString operator+(const CharString& lhs, const CharString& rhs);
    friend bool operator==(const CharString& lhs, const CharString& rhs);
    friend bool operator!=(const CharString& lhs, const CharString& rhs);
    friend bool operator<(const CharString& lhs, const CharString& rhs);
    friend bool operator>(const CharString& lhs, const CharString& rhs);
    friend bool operator<=(const CharString& lhs, const CharString& rhs);
    friend bool operator>=(const CharString& lhs, const CharString& rhs);
    friend std::ostream& operator<<(std::ostream& os, const CharString& str);
};

#endif // CHARSTRING_H