#include <iostream>
#include <fstream>
using namespace std;

bool is_prime(int number)
{

    // Please fill in the function body here.
    // Return true if the given number is a prime, return false otherwise.

    /////////////////////////////
    // To be implemented
    /////////////////////////////
    if (number == 1)
        return false;
    for (int i = 2; i < number; i++)
        if (number % i == 0)
            return false;
    return true;
}

int next_prime(int number)
{

    // Please fill in the function body here.
    // Call is_prime() to justify whether a given number is a prime
    // If the given number is a prime, directly return it. Otherwise, use loop to find the first greater one.

    /////////////////////////////
    // To be implemented (Should call the function is_prime)
    /////////////////////////////
    while (!is_prime(number))
        number++;
    return number;
}

int main()
{

    // Read integer numbers (>= 1) from a given txt file placed at ./input_cases
    // Justify whether a number is a prime. If not, calculate the first prime number that is greater than it.
    // Output the results using cout.

    cout << "Hello, welcome to lab3 (Function & FileIO)" << endl;

    char input_case_path[100];
    cout << "The path for input cases (e.g   ./input_cases/case5.txt ) :" << endl;
    cin >> input_case_path;

    ifstream fin(input_case_path);

    if (!fin)
    {
        cout << "Error: Can not open " << input_case_path << endl;
        return -1;
    }
    else
    {

        /////////////////////////////
        // To be implemented (Should call the function next_prime)
        /////////////////////////////
        char s[10];
        
        int nextPrime;

        while (!fin.eof())
        {
            fin >> nextPrime;
            cout << next_prime(nextPrime) << endl;
        }
        fin.close();

        cout << "Finish! Please check whether the results are correct :)" << endl;
    }

    return 0;
}