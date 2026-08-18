#include <iostream>
#include <memory>

// Шаблонный узел односвязного списка
template <typename T>
struct SinglyNode {
    T data;
    SinglyNode* next = nullptr;

    explicit SinglyNode(const T& val) : data(val) {}
};

// Вставка в начало
template <typename T>
void push_front(SinglyNode<T>*& head, const T& value) {
    SinglyNode<T>* new_node = new SinglyNode<T>(value);
    new_node->next = head;
    head = new_node;
}

// Вставка в конец (исправленная версия)
template <typename T>
void push_back(SinglyNode<T>*& head, const T& value) {
    SinglyNode<T>* new_node = new SinglyNode<T>(value);

    // Если список пуст, новый узел становится головой
    if (head == nullptr) {
        head = new_node;
        return;
    }

    // Иначе ищем последний узел
    SinglyNode<T>* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Привязываем новый узел в конец
    current->next = new_node;
}

// Печать списка
template <typename T>
void print_list(const SinglyNode<T>* head) {
    const SinglyNode<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr\n";
}

// Очистка памяти
template <typename T>
void free_list(SinglyNode<T>*& head) {
    while (head != nullptr) {
        SinglyNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
}
template <typename T>
void insert_after(SinglyNode<T>* prev_node, const T& value) {
    if (prev_node == nullptr) {
        std::cout << "Предыдущий узел не может быть nullptr!\n";
        return;
    }

    // 1. Создаем новый узел
    SinglyNode<T>* new_node = new SinglyNode<T>(value);

    // 2. Связываем новый узел со следующим (который шёл после prev_node)
    new_node->next = prev_node->next;

    // 3. Перенаправляем prev_node на новый узел
    prev_node->next = new_node;
}


int main() {
    SinglyNode<int>* head = nullptr;

    push_back(head, 10);
    push_back(head, 20);
    push_back(head, 30);
    push_front(head, 5);
    // Допустим, список сейчас: 10 -> 20 -> 30 -> nullptr
    SinglyNode<int>* current = head;

    // Ищем узел со значением 10 (или проходим нужный шаг)
    while (current != nullptr && current->data != 10) {
        current = current->next;
    }

    // Если нашли узел 10, вставляем 15 после него
    if (current != nullptr) {
        insert_after(current, 15);
    }
    // Результат: 10 -> 15 -> 20 -> 30 -> nullptr


    print_list(head); // Выведет: 5 -> 10 -> 20 -> 30 -> nullptr

    free_list(head);
    return 0;
}