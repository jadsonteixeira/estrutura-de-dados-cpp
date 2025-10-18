#include <cstdlib>
#include "Queue.hpp"

int main() {
    system("cls");

    Queue q = Queue(5);

    cout << "Capacity: " << q.getCapacity() << endl;
    cout << "Enqueue" << endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << "Quantity elements: " << q.getQuantityElements() << endl;
    q.print();

    return 0;
}