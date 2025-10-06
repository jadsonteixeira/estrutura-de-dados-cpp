#include <cstdlib>
#include "Queue.hpp"

int main() {
    system("cls");

    Queue queue = Queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    cout << queue.getFront() << endl;
    cout << queue.getRear() << endl;

    return 0;
}