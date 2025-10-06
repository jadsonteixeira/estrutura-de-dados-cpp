#include "Stack.hpp"

int main(void) {
    Stack stack1;
    Stack stack2 = Stack(5);

    cout << "\n ...Pushing on Stack 1....";
    stack1.push(5);
    stack1.push(3);
    stack1.push(10);
    stack1.print("Stack 1: ");

    cout << "\n\n ...Pushing on Stack 2....";
    stack2.push(40);
    stack2.push(50);
    stack2.push(60);
    stack2.print("Stack 2: ");

    cout << "\n\n ...Copying Stack 2 into Stack 1....";
    stack1 = stack2;
    stack1.print("Stack 1: ");
    
    cout << "\n\n ...Pushing Stack 1 with resize....";
    int capacity = stack1.getCapacity();
    for(int i = 0; i < capacity; i++) {
        stack1.push(i * 3);
    }
    cout << "\n Stack 1 capacity: " << stack1.getCapacity();
    stack1.print("Stack 1: ");

    cout << "\n\n ...Popping Stack 2 into Stack 1...";
    while(!stack2.isEmpty()) {
        stack1.push(stack2.pop());
    }    

    cout << "\n Stack 1: " << stack1;    

    cout << "\n\n ...Popping Stack 1...";
    for (int i = 0; i < 3; i++) {
        int pop = stack1.pop();
        cout << "\n Stack 1: " << stack1 << " -> " << pop;    
    }

    return 0;
}