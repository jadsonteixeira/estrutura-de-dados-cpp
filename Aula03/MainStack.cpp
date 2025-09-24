#include <cstdlib>
#include "Stack.hpp"

int main() {
    system("cls");

    Stack stack1 = Stack(10);

    cout << "Size stack1: " << stack1.peek();

    stack1.printStack();

    cout << "Empty? " << stack1.isEmpty();

    stack1.clear();

    stack1.printStack();

    cout << "Empty? " << stack1.isEmpty();

    stack1.push(1);

    stack1.printStack();

    return 0;
}