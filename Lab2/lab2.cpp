#include <iostream>
using namespace std;

// Submit this original main function with only provided cin and cout statements

int main()
{

    int yearX, yearY; // Both inputs will be positive integer, but you do not know which is larger,
    cin >> yearX >> yearY;

    int numLeapYears = 0;

    /*  
        int larger = (yearX > yearY) ? yearX : yearY;
        int smaller = (larger == yearX) ? yearY : yearX;
        
        while (smaller <= larger)
        {
            if (smaller % 400 == 0 || (smaller % 4 == 0 && smaller % 100 != 0))
                numLeapYears++;
            smaller++;
        }
    */

    for (   ;   ;   (yearX<yearY)?yearX++:yearX--   )
    {
        if (yearX % 400 == 0 || (yearX % 4 == 0 && yearX % 100 != 0))
            numLeapYears++;
        if (yearX == yearY)
            break;
    }
    
    cout << numLeapYears;
    return 0;
}