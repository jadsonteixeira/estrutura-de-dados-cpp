#include <cstdlib>
#include "Stack.hpp"

int main() {
    system("cls");

    Stack stack = Stack(3);

    for (int i = 0; i < stack.getSize(); i++) {
        stack.push(i+1);
    }

    stack.printStack();

    return 0;
}