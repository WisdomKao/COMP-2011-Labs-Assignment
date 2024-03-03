#include <iostream>
using namespace std;

const int MAX_SIZE = 8;

void readArray(int arr[], int &size) 
{
    size = 0;
    int num;
    while (true) 
    {
        cin >> num;
        if (num == -1) 
            break;
        arr[size++] = num;
        if (size == MAX_SIZE) {
            cout << "Array is full!" << endl;
            break;
        }
    }
}

void printArray(const int arr[], int size) 
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool isSame(const int arr1[], const int arr2[], int size1, int size2) 
{
    /***************Start your code here***************/
    if (size1 != size2) return false;
    for (int i; i < size1; i++)
    {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;


    
    /***************End your code here***************/
}

void rotateArray(int arr[], int size, int step)
{
    /****************Start your code here***************/
        int temp[size];
        step %= size;
        for (int i=0; i < size; i++)
        {
            temp[i] = arr[(i+size+step)%size];
        }
        for (int i=0; i < size; i++)
        {
            arr[i] = temp[i];
        }
    /****************End your code here***************/
}


int main()
{
    int arr1[MAX_SIZE], arr2[MAX_SIZE];
    int size1 = 0, size2 = 0;

    cout << "Enter positive integer values for array 1 (enter -1 to stop): \n";
    readArray(arr1, size1);
    cout << "Enter positive integer values for array 2 (enter -1 to stop): \n";
    readArray(arr2, size2);

    int option = 0, step = 0, arrayId = 0;

    while (true) 
    {
        cout << "=========================================\n";
        cout << "Array 1: ";
        printArray(arr1, size1);
        cout << "Array 2: ";
        printArray(arr2, size2);
        cout << "\nMenu:\n";
        cout << "1 to check if the two arrays are the same\n";
        cout << "2 to rotate an array\n";
        cout << "-1 to quit" << endl;
        cout << "\nEnter your option (1, 2 or -1): ";
       
        cin >> option;
     
        if (option == -1) {
            cout << "Bye!" << endl;
            break; 
        } else if (option == 1) { 
            // Check if arr1 and arr2 are same or rotated versions of each other
            if (isSame(arr1, arr2, size1, size2))
                cout << "Arrays are same!" << endl;
            else
                cout << "Arrays are not same!" << endl;
        } else if (option == 2) {
            cout << "Select the array (1 or 2): ";
            cin >> arrayId; 
            cout << "Enter the number of steps to rotate array " << arrayId << ": ";
            cin >> step;
            if (arrayId == 1) 
            {
                // rotate arr1 by step
                rotateArray(arr1, size1, step);
                cout << "Array " << arrayId << " after rotation: ";
                printArray(arr1, size1);
            } else {
                // rotate arr1 by step
                rotateArray(arr2, size2, step);
                cout << "Array " << arrayId << " after rotation: ";
                printArray(arr2, size2);
            }
        }
    }    
    return 0;
}
