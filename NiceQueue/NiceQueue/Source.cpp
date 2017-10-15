#include <iostream>
#include "NiceQueue.h"

int main()
{
    NiceQueue<int> queue (11);
    int a[11]{ 1, -9, 5, 7, 4, 6, -1, 6, 8, 0, -91 };
    for (int i : a)
        queue.enq(i);
    cout << queue.deq() << endl;
    cout << queue.deq() << endl;
    cout << queue.getMinimum() << endl;
    system("pause");
}