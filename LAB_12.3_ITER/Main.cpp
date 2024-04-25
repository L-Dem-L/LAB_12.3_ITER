#include <iostream>
#include <Windows.h>
using namespace std;

// Структура, що представляє вузол двунаправленого списку
struct Node {
    int data;     // Дані вузла
    Node* prev;   // Вказівник на попередній вузол
    Node* next;   // Вказівник на наступний вузол
};

// Функція для створення двунаправленого списку на основі масиву значень
Node* createList(int values[], int size) {
    Node* head = nullptr;  // Початковий вузол
    Node* tail = nullptr;  // Кінцевий вузол

    // Прохід по масиву значень
    for (int i = 0; i < size; i++) {
        // Створення нового вузла
        Node* newNode = new Node(); // 1
        newNode->data = values[i];  // 2 Присвоєння значення вузлу
        newNode->prev = nullptr;    // 3 Початкове значення вказівника на попередній вузол
        newNode->next = nullptr;    // 4 Початкове значення вказівника на наступний вузол

        // Перевірка, чи це перший вузол у списку
        if (head == nullptr) {
            head = newNode;  //5 Якщо так, то встановлення його як початкового та кінцевого вузла
            tail = newNode; //6
        }
        else {
            tail->next = newNode;  // Додавання нового вузла після кінцевого вузла
            newNode->prev = tail;  // Встановлення посилання на попередній вузол для нового вузла
            tail = newNode;        // Встановлення нового вузла як кінцевого
        }
    }

    return head;  // Повернення посилання на початковий вузол
}

// Функція для підрахунку кількості вузлів з непарними значеннями
int countOddElements(Node* head) {
    int count = 0;        // Лічильник непарних вузлів
    Node* current = head; // Поточний вузол, що розглядається

    // Прохід по усіх вузлах у списку
    while (current != nullptr) {
        // Перевірка, чи значення поточного вузла є непарним
        if (current->data % 2 != 0) {
            count++;  // Якщо так, збільшення лічильника
        }
        current = current->next;  // Перехід до наступного вузла
    }

    return count;  // Повернення кількості непарних вузлів
}

// Функція для виведення значень усіх вузлів у списку
void printList(Node* head) {
    Node* current = head;  // Початковий вузол

    // Прохід по усіх вузлах у списку
    while (current != nullptr) {
        cout << current->data << " ";  // Виведення значення поточного вузла
        current = current->next;       // Перехід до наступного вузла
    }

    cout << endl;  // Виведення символу нового рядка в кінці списку
}

// Функція для видалення всього списку та звільнення пам'яті
void deleteList(Node* head) {
    Node* current = head;  // Початковий вузол

    // Прохід по усіх вузлах у списку
    while (current != nullptr) {
        Node* temp = current;      // Тимчасовий вказівник на поточний вузол
        current = current->next;   // Перехід до наступного вузла
        delete temp;               // Звільнення пам'яті, що була виділена для поточного вузла
    }
}

int main() {

    int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };  // Масив значень для створення списку
    int size = sizeof(values) / sizeof(values[0]);  // Розмір масиву

    Node* head = createList(values, size);  // Створення двунаправленого списку

    cout << "Список елементів:" << endl;
    printList(head);  // Виведення елементів списку

    int oddCount = countOddElements(head);  // Підрахунок непарних елементів
    cout << "Кількість елементів з непарними значеннями: " << oddCount << endl;

    deleteList(head);  // Видалення списку та звільнення пам'яті

    return 0;
}
