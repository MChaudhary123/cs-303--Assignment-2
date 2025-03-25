#include "LinkedList.h"
#include <stdexcept>

template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* newNode = new Node(item);
    if (empty()) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* newNode = new Node(item);
    if (empty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        throw std::runtime_error("Cannot pop from an empty list");
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    num_items--;
    if (num_items == 0) {
        tail = nullptr;
    }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) {
        throw std::runtime_error("Cannot pop from an empty list");
    }
    if (num_items == 1) {
        delete head;
        head = tail = nullptr;
        num_items = 0;
        return;
    }
    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
    num_items--;
}

template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::front() {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    return head->data;
}

template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::back() {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    return tail->data;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index > num_items) {
        index = num_items;  // Insert at the end if index is beyond list size
    }

    if (index == 0) {
        push_front(item);
        return;
    }

    if (index == num_items) {
        push_back(item);
        return;
    }

    Node* newNode = new Node(item);
    Node* current = head;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    num_items++;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }

    if (index == 0) {
        pop_front();
        return true;
    }

    Node* current = head;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->next;
    }

    Node* toDelete = current->next;
    current->next = toDelete->next;

    if (toDelete == tail) {
        tail = current;
    }

    delete toDelete;
    num_items--;
    return true;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    return num_items;
}

// Explicit template instantiation for int type
template class Single_Linked_List<int>;