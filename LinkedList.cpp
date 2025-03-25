#include "LinkedList.h"
#include <stdexcept>

// Default constructor: Initialize an empty list
template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor: Free all dynamically allocated nodes
template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    // Iterate through the list and delete each node
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Add a new node to the front of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    // Create a new node with the given item
    Node* newNode = new Node(item);
    
    // If list is empty, set both head and tail to the new node
    if (empty()) {
        head = tail = newNode;
    }
    else {
        // Point new node's next to current head
        // Then update head to be the new node
        newNode->next = head;
        head = newNode;
    }
    // Increment the number of items
    num_items++;
}

// Add a new node to the back of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    // Create a new node with the given item
    Node* newNode = new Node(item);
    
    // If list is empty, set both head and tail to the new node
    if (empty()) {
        head = tail = newNode;
    }
    else {
        // Append new node to the current tail
        // Then update tail to be the new node
        tail->next = newNode;
        tail = newNode;
    }
    // Increment the number of items
    num_items++;
}

// Remove the first node from the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    // Throw an error if list is empty
    if (empty()) {
        throw std::runtime_error("Cannot pop from an empty list");
    }
    
    // Store the current head to delete later
    Node* temp = head;
    
    // Move head to the next node
    head = head->next;
    
    // Delete the old head
    delete temp;
    
    // Decrement item count
    num_items--;
    
    // If list becomes empty, set tail to nullptr
    if (num_items == 0) {
        tail = nullptr;
    }
}

// Remove the last node from the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    // Throw an error if list is empty
    if (empty()) {
        throw std::runtime_error("Cannot pop from an empty list");
    }
    
    // Special case: only one item in the list
    if (num_items == 1) {
        delete head;
        head = tail = nullptr;
        num_items = 0;
        return;
    }
    
    // Traverse to find the second to last node
    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }
    
    // Delete the last node
    delete tail;
    
    // Update tail to be the second to last node
    tail = current;
    tail->next = nullptr;
    
    // Decrement item count
    num_items--;
}

// Return a reference to the first item
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::front() {
    // Throw an error if list is empty
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    // Return the data of the head node
    return head->data;
}

// Return a reference to the last item
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::back() {
    // Throw an error if list is empty
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    // Return the data of the tail node
    return tail->data;
}

// Check if the list is empty
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    // List is empty if number of items is 0
    return num_items == 0;
}

// Insert an item at a specific index
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    // Adjust index if it's beyond list size
    if (index > num_items) {
        index = num_items;
    }

    // Special cases for inserting at front or back
    if (index == 0) {
        push_front(item);
        return;
    }

    if (index == num_items) {
        push_back(item);
        return;
    }

    // Create new node
    Node* newNode = new Node(item);
    
    // Traverse to the node before insertion point
    Node* current = head;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    
    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
    num_items++;
}

// Remove an item at a specific index
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    // Return false if index is out of bounds
    if (index >= num_items) {
        return false;
    }

    // Special case for removing first item
    if (index == 0) {
        pop_front();
        return true;
    }

    // Traverse to the node before the one to be removed
    Node* current = head;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->next;
    }

    // Node to be deleted
    Node* toDelete = current->next;
    
    // Bypass the node to be deleted
    current->next = toDelete->next;

    // Update tail if last node is removed
    if (toDelete == tail) {
        tail = current;
    }

    // Free the memory and update item count
    delete toDelete;
    num_items--;
    return true;
}

// Find the first occurrence of an item
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    // Traverse the list
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        // If item is found, return its index
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    // Return list size if item is not found
    return num_items;
}

// Return the number of items in the list
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    return num_items;
}

// Explicit template instantiation for int type to ensure compilation
template class Single_Linked_List<int>;
