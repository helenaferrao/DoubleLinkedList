// double_linked_list.h

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Add a new node at the front
    void addAtFront(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode; // If the list was empty, update the tail
        }
        head = newNode;
        size++;
    }

    // Add a new node at the end
    void addAtEnd(int data) {
        Node* newNode = new Node(data);
        newNode->prev = tail;
        if (tail != nullptr) {
            tail->next = newNode;
        }
        else {
            head = newNode; // If the list was empty, update the head
        }
        tail = newNode;
        size++;
    }

    // Remove a node from the front
    int removeFromFront() {
        if (head == nullptr) {
            throw std::runtime_error("removeFromFront: List is empty.");
        }
        int removedData = head->data;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr; // If the list is now empty, update tail
        }
        delete temp;
        size--;
        return removedData;
    }

    // Remove a node from the end
    int removeFromEnd() {
        if (tail == nullptr) {
            throw std::runtime_error("removeFromEnd: List is empty.");
        }
        int removedData = tail->data;
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr; // If the list is now empty, update head
        }
        delete temp;
        size--;
        return removedData;
    }

    // Print the list from head to tail
    void print() const {
        Node* current = head;
        std::cout << "List: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Return the size of the list
    int getSize() const {
        return size;
    }

    // Destructor to clean up memory
    ~DoubleLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif // DOUBLE_LINKED_LIST_H