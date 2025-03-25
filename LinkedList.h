#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>  // for size_t

template <typename Item_Type>
class Single_Linked_List {
private:
    // Node structure for the linked list
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& value) : data(value), next(nullptr) {}
    };

    Node* head;    // Pointer to the first node
    Node* tail;    // Pointer to the last node
    size_t num_items;  // Number of items in the list

public:
    // Constructor
    Single_Linked_List();

    // Destructor
    ~Single_Linked_List();

    // Add item to the front of the list
    void push_front(const Item_Type& item);

    // Add item to the back of the list
    void push_back(const Item_Type& item);

    // Remove item from the front of the list
    void pop_front();

    // Remove item from the back of the list
    void pop_back();

    // Get the first item in the list
    Item_Type& front();

    // Get the last item in the list
    Item_Type& back();

    // Check if the list is empty
    bool empty() const;

    // Insert item at a specific index
    void insert(size_t index, const Item_Type& item);

    // Remove item at a specific index
    bool remove(size_t index);

    // Find the first occurrence of an item
    size_t find(const Item_Type& item) const;

    // Get the number of items in the list
    size_t size() const;
};

#endif // SINGLE_LINKED_LIST_H