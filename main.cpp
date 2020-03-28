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
        theheap[i] = x;
        size++;
        i++;
    }
    return size;
}

void heapRemove(int* theheap, int size)
{
    // First Step: Replace root with last index.
    theheap[0] = theheap[size - 1];
    theheap[size - 1] = 0;
    size--;

    if (size < 4 && size > 1)
    {
        if (theheap[0] > theheap[1])
        {
            int temp = theheap[0];
            theheap[0] = theheap[1];
            theheap[1] = temp;
        }
    }

    // First Run
    if (size > 3)
    {
        int x = 0;
        if (theheap[x] > theheap[x + 1] || theheap[x] > theheap[x + 2])
        {
            if (theheap[x + 1] < theheap[x + 2])
            {
                int temp = theheap[x];
                theheap[x] = theheap[x + 1];
                theheap[x + 1] = temp;
                x += 2;
            }
            else
            {
                int temp = theheap[x];
                theheap[x] = theheap[x + 2];
                theheap[x + 2] = temp;
                x += 2;
            };
        }
        while (theheap[x] > theheap[(2 * x) + 1] || theheap[x] > theheap[(2 * x) + 2])
        {
            if ((theheap[(2 * x) + 1] == 0 && theheap[(2 * x) + 2] == 0) || ((2 * x) + 1) > 10)
            {
                break;
            }
            else if (theheap[(2 * x) + 1] < theheap[(2 * x) + 2] || (theheap[(2 * x) + 2]) == 0)
            {
                int temp = theheap[x];
                theheap[x] = theheap[(2 * x) + 1];
                theheap[(2 * x) + 1] = temp;
                x = (x * 2) + 1;
            }
            else
            {
                int temp = theheap[x];
                theheap[x] = theheap[(2 * x) + 2];
                theheap[(2 * x) + 2] = temp;
                x = (2 * x) + 2;
            };
        }
    }
}


void newHeapRemove(int* theHeap, int size)
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
    //use cout to print the array representing the heap

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