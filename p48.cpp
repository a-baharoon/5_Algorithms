#include <iostream>
#include <cmath>

using namespace std;

double ReadNumber(string Message)
{
    double Number = 0;

    cout << Message;
    cin >> Number;

    return Number;
}

int MyFloor(double Number)
{
    int IntNumber = Number;
    if (IntNumber == Number)
        return Number;

    if (Number > 0)
        return (int) Number;
    else
        return (int) (Number-1);
}

 int main()
{
    double Number = 0;
    // in codntioned loop to keep testing the program.
    while (true) {
        Number = ReadNumber("Enter a number: ");
        if (Number == 0)
            break;

        cout << "My floor Result: " <<  MyFloor(Number) << endl;
        cout << "C++ floor Result: " << floor(Number) << endl;
        cout << endl;
    }

    return 0;
}

