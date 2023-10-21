#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(NULL), rear(NULL) {}

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    int frontValue() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1; // Return a sentinel value to indicate an error
        } else {
            return front->data;
        }
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    std::cout << "Front of the queue: " << queue.frontValue() << std::endl;

    queue.dequeue();
    queue.dequeue();

    std::cout << "Front of the queue: " << queue.frontValue() << std::endl;

    return 0;
}

