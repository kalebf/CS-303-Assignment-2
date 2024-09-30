#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// A class representing a Single-Linked List (SLL)
class SLL {
private:
    struct Node {             // Node structure for linked list
        int data;
        Node* next;
    };

    Node* head;// Pointer to the first node
    Node* tail; // Pointer to the last node
    size_t num_items; // Number of items in the list

public:
    // Constructor
    SLL(); // Initializes the list

    // Destructor
    ~SLL(); // Cleans up resources

    // Member functions
    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void pop_back();
    int front() const; // Returns front value
    int back() const; // Returns back value
    bool empty() const; // Checks if the list is empty
    void insert(size_t index, int item); // Inserts item at a specific position
    bool remove(size_t index); // Removes item at a specific index
    size_t find(int item) const; // Finds the index of the item
    size_t size() const;  // size() function
    void display() const; // Displays the list contents
};

#endif // FUNCTIONS_H
