#include <iostream>

// Node structure for a queue
template <typename T>
struct Node
{
    T data;
    Node *next;

    // Constructor to initialize data and next pointer
    Node(T value) : data(value), next(nullptr) {}
};

// Queue class
template <typename T>
class Queue
{
private:
    Node<T> *front;
    Node<T> *rear;

public:
    // Constructor to initialize an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to check if the queue is empty
    bool isEmpty() const
    {
        return front == nullptr;
    }

    // Function to enqueue a new element to the queue
    void enqueue(T value)
    {
        Node<T> *newNode = new Node<T>(value);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to dequeue an element from the queue
    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        Node<T> *temp = front;
        front = front->next;
        delete temp;

        // If the queue becomes empty after dequeue, update rear to nullptr
        if (front == nullptr)
        {
            rear = nullptr;
        }
    }

    // Function to get the front element of the queue
    T getFront() const
    {
        if (isEmpty())
        {
            throw std::runtime_error("Queue is empty. Cannot get front element.");
        }
        return front->data;
    }

    // Function to display the elements in the queue
    void display() const
    {
        Node<T> *current = front;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free memory when the object is destroyed
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    // Create a queue of integers
    Queue<int> myQueue;

    // Enqueue elements
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    // Display the elements in the queue
    std::cout << "Queue: ";
    myQueue.display();

    // Dequeue an element
    myQueue.dequeue();

    // Display the modified queue
    std::cout << "Queue after dequeue: ";
    myQueue.display();

    return 0;
}
