#include <iostream>
#include <iomanip>
#include "lab8.h"
using namespace std;

void printOrderArray(const Order *orderArray, int size)
{
    cout << "================================================================================" << endl;
    cout << left << setw(12) << "Order id"
         << left << setw(12) << "Show id"
         << left << setw(12) << "Number"
         << "Priority" << endl;
    cout << "================================================================================" << endl;
    // TODO
    /* Task 1: print order array by pointer arithmetic
    orderArray: first element of orderArray
    size: the size of orderArray
    */
    for (int i = 0; i < size; i++)
    {
        cout << left << setw(12) << i
             << left << setw(12) << (orderArray + i)->show_id
             << left << setw(12) << (orderArray + i)->ticket_cnt
             << static_cast<int>((orderArray + i)->priority) << endl;
    }
}

void sortByPriority(Order *orderPtrArray[], int size)
{
    // TODO
    /* Task 2:  sort orders by priority via an array of pointer to orderArray
    orderPtrArray: an array of pointers to items of orderArray
    size: the size of orderPtrArray
    */
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((*(orderPtrArray + j))->priority > (*(orderPtrArray + i))->priority)
            {
                Order *temp;
                temp = *(orderPtrArray + i);
                *(orderPtrArray + i) = *(orderPtrArray + j);
                *(orderPtrArray + j) = temp;
            }
            else if ((*(orderPtrArray + j))->priority == (*(orderPtrArray + i))->priority)
            {
                if ((*(orderPtrArray + i))->order_id > (*(orderPtrArray + j))->order_id)
                {
                    Order *temp;
                    temp = *(orderPtrArray + i);
                    *(orderPtrArray + i) = *(orderPtrArray + j);
                    *(orderPtrArray + j) = temp;
                }
            }
        }
    }
}

void priorityTicketing(Show showList[], Order *orderPtrArray[], int size)
{
    // TODO
    /* Task 3: sell tickets based on priority
    showList: array of Show object
    orderPtrArray: sorted order pointer array of pointers to orderArray
    size: the size of orderPtrArray
    */
    for (int i=0; i<size; i++)
    {
        int showid = (*(orderPtrArray+i))->show_id;
        if (showList[showid].stock_cnt >= (*(orderPtrArray+i))->ticket_cnt)
        {
            showList[showid].stock_cnt -= (*(orderPtrArray+i))->ticket_cnt;
            (*(orderPtrArray+i))->finished = true;
        }
    }
}