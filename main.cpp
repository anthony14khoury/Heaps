#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int readheap(int* theheap)
{
    int size = 0;
    int x;
    int i = 1;
    while (cin >> x)
    {
        if (x == -1)
        {
            break;
        }

        theheap[i] = x;
        size++;
        i++;
    }
    return size;
}


void heapRemove(int* theHeap, int size)
{
    int temp, removed, hole, firstChild, secondChild;

    temp = theHeap[size];
    size--;
    removed = theHeap[1];
    theHeap[1] = temp;
    hole = 1;
    while (size >= 2 * hole)
    {
        firstChild = theHeap[2 * hole];
        secondChild = theHeap[(2 * hole) + 1];
        if (firstChild < secondChild)
        {
            int tempSwap = theHeap[hole];
            theHeap[hole] = theHeap[2 * hole];
            theHeap[2 * hole] = tempSwap;
            hole = 2 * hole;
        }
        else if (secondChild < firstChild)
        {
            int tempSwap = theHeap[hole];
            theHeap[hole] = theHeap[(2 * hole) + 1];
            theHeap[(2 * hole) + 1] = tempSwap;
            hole = (2 * hole) + 1;
        }
        else
        {
            break;
        }
    }
}
    
void heapPrint(int* theheap, int size)
{
    cout << "blank" << " ";

    for(int i = 1; i < size; i++)
    {
        cout << theheap[i] << " ";
    }
}

int main()
{
    int* theheap = new int[10];
    int size = readheap(theheap);
    heapRemove(theheap, size);
    heapPrint(theheap, size);
}