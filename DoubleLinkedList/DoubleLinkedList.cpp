#include "double_linked_list.h"

int main() {
    DoubleLinkedList dll;

    // Add elements
    dll.addAtFront(10);
    dll.addAtFront(20);
    dll.addAtEnd(30);

    // Print the list
    dll.print();

    // Remove elements
    std::cout << "Removed from front: " << dll.removeFromFront() << std::endl;
    std::cout << "Removed from end: " << dll.removeFromEnd() << std::endl;

    // Print the updated list
    dll.print();

    // Check the size
    std::cout << "Size of the list: " << dll.getSize() << std::endl;

    return 0;
}
