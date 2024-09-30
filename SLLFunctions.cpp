#include <iostream>
#include "SLLFunctions.h"

// Constructor: Initializes an empty list
SLL::SLL() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor: Deletes all nodes in the list to free memory
SLL::~SLL() {
    while (!empty()) {
        pop_front(); // Remove elements one by one
    }
}
// Push front function
void SLL::push_front(int value) {
    Node* new_node = new Node{ value, head }; // New node points to current head
    head = new_node; // Set new node as head
    if (tail == nullptr) { // If list empty, set tail to new node
        tail = head;
    }
    ++num_items; // Item count
}
//Push back function
void SLL::push_back(int value) {
    Node* new_node = new Node{ value, nullptr }; // New node points to end of list
    if (tail != nullptr) {
        tail->next = new_node; // Update current tail's next pointer
    }
    tail = new_node; // Set new node as new tail
    if (head == nullptr) { // If list empty, set head to new node
        head = tail;
    }
    ++num_items; // Increment item count
}
//Pop front function
void SLL::pop_front() {
    if (empty()) {
        std::cerr << "List is empty, can't pop from front.\n";
        return;
    }
    Node* old_head = head;
    head = head->next; // Move the head to the next node
    delete old_head;   // Free the memory of the old head
    --num_items;       // Decrement item count

    if (head == nullptr) { // If the list becomes empty after pop
        tail = nullptr;
    }
}

// Pop back function
void SLL::pop_back() {
    if (empty()) {
        std::cerr << "List is empty, can't pop from back.\n";
        return;
    }
    if (head == tail) { // If only one element
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* temp = head;
        while (temp->next != tail) { // Traverse to second last element
            temp = temp->next;
        }
        delete tail;    // Delete last element
        tail = temp;    // Update tail to second last element
        tail->next = nullptr;
    }
    --num_items; // Decrement item count
}

// Gets front element
int SLL::front() const {
    if (empty()) {
        std::cerr << "List is empty.\n";
        return -1; // Or handle error appropriately
    }
    return head->data;
}

// Gets back element
int SLL::back() const {
    if (empty()) {
        std::cerr << "List is empty.\n";
        return -1; // Or handle error appropriately
    }
    return tail->data;
}

// Checks if empty
bool SLL::empty() const {
    return num_items == 0;
}

// Inserts item by index
void SLL::insert(size_t index, int item) {
    if (index == 0) {// Front index
        push_front(item); // Insert at front
    }
    else if (index >= num_items) {// Index beyond list 
        push_back(item);  // Insert at end
    }
    else {
        Node* temp = head;
        for (size_t i = 0; i < index - 1; ++i) {
            temp = temp->next; // Traverse to node before insertion point
        }
        Node* new_node = new Node{ item, temp->next }; // Create new node pointing to next node
        temp->next = new_node; // Insert the new node into list
        ++num_items; // Increment item count
    }
}

// Remove item by index
bool SLL::remove(size_t index) {
    if (index >= num_items) {
        return false; // Invalid index
    }
    if (index == 0) {//Front index
        pop_front(); // Remove from front
    }
    else {
        Node* temp = head;
        for (size_t i = 0; i < index - 1; ++i) {
            temp = temp->next; // Traverse to node before the one to be removed
        }
        Node* to_delete = temp->next;
        temp->next = to_delete->next;
        delete to_delete; // Free memory
        if (temp->next == nullptr) {//Checks if tail
            tail = temp; // Update tail if necessary
        }
        --num_items; // Decrement item count
    }
    return true;
}

// Finds first occurrence of item
size_t SLL::find(int item) const {
    Node* temp = head;
    size_t index = 0;
    while (temp != nullptr) {
        if (temp->data == item) {
            return index; // Return index if found
        }
        temp = temp->next;
        ++index;
    }
    return num_items; // Return list size if item is not found
}

// size() function to return number of elements
size_t SLL::size() const {
    return num_items;
}

// Display contents of list
void SLL::display() const {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "null\n"; // End of list
}
