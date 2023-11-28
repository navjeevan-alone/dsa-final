#include <iostream>

// Node structure for a singly linked list
struct Node {
    int data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(int value) : data(value), next(nullptr) {}
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Function to add a new node to the end of the linked list
    void append(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Function to delete a node with a given value from the linked list
    void deleteNode(int value) {
        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete." << std::endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Node with value " << value << " not found." << std::endl;
            return;
        }

        prev->next = current->next;
        delete current;
    }

    // Destructor to free memory when the object is destroyed
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    // Create a linked list
    LinkedList myList;

    // Append elements to the linked list
    myList.append(1);
    myList.append(2);
    myList.append(3);

    // Display the linked list
    std::cout << "Linked List: ";
    myList.display();

    // Delete a node from the linked list
    myList.deleteNode(2);

    // Display the modified linked list
    std::cout << "Linked List after deletion: ";
    myList.display();

    return 0;
}
