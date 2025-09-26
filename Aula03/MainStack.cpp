#include <cstdlib>
#include "Stack.hpp"

int main() {
    system("cls");

    Stack stack = Stack(3);
    
    cout << "Size: " << stack.getSize() << endl;
    cout << "Top: " << stack.getTop() << endl;

    cout << "\nAfter push" << endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Top index: " << stack.getTop() << endl;
    cout << "Top value: " << stack.peek() << endl;
    cout << "Quantity of elements: " << stack.quantityElements() << endl;
    stack.printStack();

    // cout << "\nTest operator =" << endl;
    // Stack stack3 = stack;
    // cout << "Top index: " << stack3.getTop() << endl;
    // cout << "Top value: " << stack3.peek() << endl;
    // cout << "Quantity of elements: " << stack3.quantityElements() << endl;

    // cout << "\nTest copy constructor" << endl;
    // Stack stack2 = Stack(stack);
    // cout << "Top index: " << stack2.getTop() << endl;
    // cout << "Top value: " << stack2.peek() << endl;
    // cout << "Quantity of elements: " << stack2.quantityElements() << endl;
    // stack2.printStack();

    // cout << "\nTest removeLast()" << endl;
    // stack.removeLast();
    // cout << "Top index: " << stack.getTop() << endl;
    // cout << "Top value: " << stack.peek() << endl;
    // cout << "Quantity of elements: " << stack.quantityElements() << endl;
    // stack.printStack();

    // cout << "\nTest resize()" << endl;
    // stack.push(4);
    // stack.push(5);
    // cout << "Size: " << stack.getSize() << endl;
    // cout << "Top index: " << stack.getTop() << endl;
    // cout << "Top value: " << stack.peek() << endl;
    // cout << "Quantity of elements: " << stack.quantityElements() << endl;
    // stack.printStack();

    // cout << "\nHave elements?" << endl;
    // if (stack.isEmpty()) {
    //     cout << "Yes, have: " << stack.getTop() + 1 << " elements" << endl;
    // } else {
    //     cout << "No, is empty" << endl;
    // }

    // stack.clear();
    // cout << "After clear()" << endl;
    // cout << "New top value (clear): " << stack.getTop() << endl;

    // cout << "\nHave elements?" << endl;
    // if (stack.isEmpty()) {
    //     cout << "Yes" << endl;
    // } else {
    //     cout << "No, is empty" << endl;
    // }

    return 0;
}