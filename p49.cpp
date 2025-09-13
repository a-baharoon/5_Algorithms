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

int MyCeil(double Number)
{
    int IntNumber = Number;
    if (Number == IntNumber)
        return Number;

    else if (Number > 0)
        return (int) Number + 1;

    else
        return (int) Number;
}

 int main()
{
    double Number = 0;
    // in codntioned loop to keep testing the program.
    while (true) {
        Number = ReadNumber("Enter a number: ");
        if (Number == 0)
            break;

        cout << "My ceil Result: " <<  MyCeil(Number) << endl;
        cout << "C++ ceil Result: " << ceil(Number) << endl;
        cout << endl;
    }

    return 0;
}
