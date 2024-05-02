#include<iostream>
#include "SLL.h"
using namespace std;

// Usage example
int main() {
    SinglyLinkedList<int> list;
    list.head = new Node<int>(1);
    list.head->next = new Node<int>(2);
    list.head->next->next = new Node<int>(3);

    cout << "Original list: " << list << endl;
    list.reverse();
    cout << "Reversed list: " << list << endl;

    SinglyLinkedList<int> copiedList = list;
    cout << "Copied reversed list: " << copiedList << endl;

    return 0;
}