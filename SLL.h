#ifndef _SLL_H
#define _SLL_H

#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) : data(data), next(nullptr) {}
};

template<typename T>
class SinglyLinkedList {
public:
    Node<T>* head;

    // Default constructor
    SinglyLinkedList() : head(nullptr) {}

    // Copy constructor
    SinglyLinkedList(const SinglyLinkedList& other) : head(nullptr) {
        Node<T>* current = other.head;
        Node<T>* last = nullptr;
        while (current != nullptr) {
            Node<T>* newNode = new Node<T>(current->data);
            if (last == nullptr) {
                head = newNode;
            } else {
                last->next = newNode;
            }
            last = newNode;
            current = current->next;
        }
    }

    // Assignment operator
    SinglyLinkedList& operator=(SinglyLinkedList other) {
        swap(head, other.head);
        return *this;
    }

    // Destructor
    ~SinglyLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    // Function to reverse the singly linked list
    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Overload the output operator
    friend ostream& operator<<(ostream& os, const SinglyLinkedList<T>& list) {
        Node<T>* current = list.head;
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }
    template <typename T>
    void insertAtFront(T item)
    {
        /* This function insert a node with value item at
         the beginning of the list*/
    }
   template <typename T>
    void insertAtTail(T item )
    {
       /* This function inserts a node with value item
        at the end of the list */
    }


    void deduplicate() {
        /* This function removes consecutive duplicates from the list
        For example if the list  is 1 1 1 2 3 1 4 4,
        After calling this function, the list should be 1 2 3 1 4
        */
    }

    void duplicate(){
        /*This function should duplicate every entry in the list.
        For example if the list is 3 4 6,
        After calling this function, the list should be 3 3 4 4 6 6
        */
    }
};

#endif 