#include <iostream>
#include <iostream>
#include <numeric>  
#include "SLLFunctions.h"
#include "stack.h"

using namespace std; 

void listMenu() {
    cout << "\n--- Linked List Menu ---\n";
    cout << "1. Push Front\n";
    cout << "2. Push Back\n";
    cout << "3. Pop Front\n";
    cout << "4. Pop Back\n";
    cout << "5. Display List\n";
    cout << "6. View Front Element\n";
    cout << "7. View Back Element\n";
    cout << "8. Insert at Index\n";
    cout << "9. Remove from Index\n";
    cout << "10. Find Element\n";
    cout << "11. Check if Empty\n";
    cout << "12. Exit to main menu\n";
    cout << "Enter your choice: ";
}

void stackMenu() {
    cout << "\n--- Stack Operations Menu ---\n";
    cout << "1. Check if empty\n";
    cout << "2. Push element\n";
    cout << "3. Pop element\n";
    cout << "4. View top element\n";
    cout << "5. Find the average value in stack\n";
    cout << "6. Display the stack\n";
    cout << "7. Exit to main menu\n";
    cout << "Enter your choice: ";

}

int main() {
    Stack myStack;
    SLL list;
    int choice, value, index;

    while (true) {
        cout << "--- Main Menu ---\n";
        cout << "Choose the container to work with\n";
        cout << "1. Use Linked List\n2. Use stack\n";
        cin >> choice;

        switch (choice) {
        case 1:
            while (true) {
                listMenu();
                cin >> choice;
                if (choice == 12) {
                    break;
                }

                switch (choice) {
                case 1:
                    cout << "Enter value to push front: ";
                    cin >> value;
                    list.push_front(value);
                    break;

                case 2:
                    cout << "Enter value to push back: ";
                    cin >> value;
                    list.push_back(value);
                    break;

                case 3:
                    list.pop_front();
                    cout << "Element popped front\n";
                    break;

                case 4:
                    list.pop_back();
                    cout << "Element popped back\n";
                    break;

                case 5:
                    cout << "List contents: ";
                    list.display();
                    break;

                case 6:
                    cout << "Front element: " << list.front() << endl;
                    break;

                case 7:
                    cout << "Back element: " << list.back() << endl;
                    break;

                case 8:
                    cout << "Enter index to insert at: ";
                    cin >> index;
                    cout << "Enter value to insert: ";
                    cin >> value;
                    list.insert(index, value);
                    break;

                case 9:
                    cout << "Enter index to remove: ";
                    cin >> index;
                    if (list.remove(index)) {
                        std::cout << "Element removed at index: " << index << endl;
                    }
                    else {
                        std::cout << "Invalid index\n";
                    }
                    break;

                case 10:
                    cout << "Enter value to find: ";
                    cin >> value;
                    index = list.find(value);
                    if (index < list.size()) {
                        cout << "Element at index: " << index << endl;
                    }
                    else {
                        cout << "Element not found\n";
                    }
                    break;

                case 11:
                    cout << (list.empty() ? "List Empty" : "List Not Empty") << endl;
                    break;

                case 12:
                    cout << "Switch to stack menu ...\n";
                    

                default:
                    cout << "Invalid choice, please try again.\n";
                    break;
                }
            }
        case 2: 
            while (true) {
                stackMenu();
                cin >> choice;
                if (choice == 7) {
                    break;
                }

                switch (choice) {
                case 1:
                    if (myStack.empty()) {
                        cout << "Stack is empty.\n";
                    }
                    else {
                        cout << "Stack is not empty.\n";
                    }
                    break;

                case 2:
                    cout << "Enter value to push: ";
                    cin >> value;
                    myStack.push(value);
                    cout << value << " pushed onto the stack.\n";
                    break;

                case 3:
                    myStack.pop();
                    cout << "Top element popped from the stack.\n";
                    break;

                case 4:
                    value = myStack.top();
                    if (value != -1) {
                        cout << "Top element: " << value << endl;
                    }
                    break;

                case 5:
                    cout << "Average value of stack elements: " << myStack.average() << endl;
                    break;

                case 6:
                    myStack.display();
                    break;

                case 7:
                    cout << "Exiting to main menu...\n";
                

                default:
                    cout << "Invalid choice, please try again.\n";
                    break;
                }



            }
        }
    }

    

    return 0;
}