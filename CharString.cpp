#include "CharString.h"
#include <iostream>

using namespace std;

// === Допоміжні методи ===
void CharString::clear() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = nullptr;
}

CharString::Node* CharString::copyList(Node* otherHead) const {
    if (!otherHead) return nullptr;
    Node* newHead = new Node(otherHead->data);
    Node* currNew = newHead;
    Node* currOld = otherHead->next;
    while (currOld != nullptr) {
        currNew->next = new Node(currOld->data);
        currNew = currNew->next;
        currOld = currOld->next;
    }
    return newHead;
}

int CharString::compareTo(const CharString& other) const {
    Node* p1 = head;
    Node* p2 = other.head;
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->data < p2->data) return -1;
        if (p1->data > p2->data) return 1;
        p1 = p1->next;
        p2 = p2->next;
    }
    if (p1 == nullptr && p2 != nullptr) return -1;
    if (p1 != nullptr && p2 == nullptr) return 1;
    return 0;
}

// === Конструктори, деструктор, присвоєння ===
CharString::CharString() : head(nullptr) {
    cout << "[Конструктор за замовчуванням] викликано" << endl;
}

CharString::CharString(const char* str) : head(nullptr) {
    cout << "[Конструктор з параметром] викликано" << endl;
    if (str && str[0] != '\0') {
        head = new Node(str[0]);
        Node* curr = head;
        for (int i = 1; str[i] != '\0'; ++i) {
            curr->next = new Node(str[i]);
            curr = curr->next;
        }
    }
}

CharString::CharString(const CharString& other) {
    cout << "[Конструктор копіювання] викликано" << endl;
    head = copyList(other.head);
}

CharString::~CharString() {
    cout << "[Деструктор] викликано" << endl;
    clear();
}

CharString& CharString::operator=(const CharString& other) {
    cout << "[Оператор присвоєння] викликано" << endl;
    if (this != &other) {
        clear();
        head = copyList(other.head);
    }
    return *this;
}

// === Функції згідно з завданням ===
void CharString::copyString(const CharString& other) {
    *this = other; // Використовуємо вже готовий оператор присвоєння
}

int CharString::length() const {
    int len = 0;
    Node* curr = head;
    while (curr) {
        len++;
        curr = curr->next;
    }
    return len;
}

void CharString::remove(int n, int poz) {
    if (poz < 0 || n <= 0 || !head) return;

    Node* prev = nullptr;
    Node* curr = head;
    int i = 0;


    while (curr != nullptr && i < poz) {
        prev = curr;
        curr = curr->next;
        i++;
    }

    if (!curr) return;

    for (int j = 0; j < n && curr != nullptr; ++j) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    if (prev != nullptr) {
        prev->next = curr;
    } else {
        head = curr;
    }
}

void CharString::insert(const CharString& st1, int poz) {
    if (!st1.head || poz < 0) return;

    Node* insertHead = copyList(st1.head);
    Node* insertTail = insertHead;
    while (insertTail->next != nullptr) {
        insertTail = insertTail->next;
    }

    if (poz == 0) {
        insertTail->next = head;
        head = insertHead;
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;
    int i = 0;
    while (curr != nullptr && i < poz) {
        prev = curr;
        curr = curr->next;
        i++;
    }

    if (prev != nullptr) {
        prev->next = insertHead;
        insertTail->next = curr;
    }
}

int CharString::find(const CharString& st1) const {
    if (!st1.head || !head) return -1;

    int index = 0;
    Node* curr = head;

    while (curr != nullptr) {
        Node* p1 = curr;
        Node* p2 = st1.head;
        bool match = true;
        
        while (p2 != nullptr) {
            if (p1 == nullptr || p1->data != p2->data) {
                match = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        if (match) return index;
        
        curr = curr->next;
        index++;
    }
    return -1;
}

// === Дружні оператори ===
CharString operator+(const CharString& lhs, const CharString& rhs) {
    CharString res(lhs);
    if (!res.head) {
        res.head = res.copyList(rhs.head);
    } else {
        CharString::Node* tail = res.head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = res.copyList(rhs.head);
    }
    return res;
}

bool operator==(const CharString& lhs, const CharString& rhs) { return lhs.compareTo(rhs) == 0; }
bool operator!=(const CharString& lhs, const CharString& rhs) { return lhs.compareTo(rhs) != 0; }
bool operator<(const CharString& lhs, const CharString& rhs) { return lhs.compareTo(rhs) < 0; }
bool operator>(const CharString& lhs, const CharString& rhs) { return lhs.compareTo(rhs) > 0; }
bool operator<=(const CharString& lhs, const CharString& rhs) { return lhs.compareTo(rhs) <= 0; }
bool operator>=(const CharString& lhs, const CharString& rhs) { return lhs.compareTo(rhs) >= 0; }

std::ostream& operator<<(std::ostream& os, const CharString& str) {
    CharString::Node* curr = str.head;
    while (curr != nullptr) {
        os << curr->data;
        curr = curr->next;
    }

    return os;
}