#include <iostream>
#include <memory>

// Шаблонный узел двусвязного списка
template <typename T>
struct DoublyNode {
    T data;
    DoublyNode* next = nullptr;
    DoublyNode* prev = nullptr;

    explicit DoublyNode(const T& val) : data(val) {}
};

// Вставка в начало
template <typename T>
void push_front(DoublyNode<T>*& head, const T& value) {
    DoublyNode<T>* new_node = new DoublyNode<T>(value);
    new_node->next = head;

    if (head != nullptr) {
        head->prev = new_node; // Старая голова теперь указывает назад на новый узел
    }
    head = new_node;
}

// Вставка в конец
template <typename T>
void push_back(DoublyNode<T>*& head, const T& value) {
    DoublyNode<T>* new_node = new DoublyNode<T>(value);

    // Если список пуст, новый узел становится головой
    if (head == nullptr) {
        head = new_node;
        return;
    }

    // Ищем последний узел
    DoublyNode<T>* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Привязываем новый узел в конец
    current->next = new_node;
    new_node->prev = current; // Новый узел ссылается назад на прежний хвост
}

// Печать списка
template <typename T>
void print_list(const DoublyNode<T>* head) {
    const DoublyNode<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }
    std::cout << "nullptr\n";
}

// Очистка памяти
template <typename T>
void free_list(DoublyNode<T>*& head) {
    while (head != nullptr) {
        DoublyNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

// Вставка после указанного узла
template <typename T>
void insert_after(DoublyNode<T>* prev_node, const T& value) {
    if (prev_node == nullptr) {
        std::cout << "Предыдущий узел не может быть nullptr!\n";
        return;
    }

    DoublyNode<T>* new_node = new DoublyNode<T>(value);

    // Настраиваем связи нового узла
    new_node->next = prev_node->next;
    new_node->prev = prev_node;

    // Если после prev_node был еще элемент, обновляем его указатель prev
    if (prev_node->next != nullptr) {
        prev_node->next->prev = new_node;
    }

    // Привязываем prev_node к новому узлу
    prev_node->next = new_node;
}

int main() {
    DoublyNode<int>* head = nullptr;

    push_back(head, 10);
    push_back(head, 20);
    push_back(head, 30);
    push_front(head, 5);

    // Ищем узел со значением 10
    DoublyNode<int>* current = head;
    while (current != nullptr && current->data != 10) {
        current = current->next;
    }

    // Если нашли узел 10, вставляем 15 после него
    if (current != nullptr) {
        insert_after(current, 15);
    }

    print_list(head); // Выведет: 5 <-> 10 <-> 15 <-> 20 <-> 30 <-> nullptr

    free_list(head);
    return 0;
}