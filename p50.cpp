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

int MySqrt(double Number)
{
    for (int i = 1; i <= Number; i++) {
        if ((i * i) == Number)
            return i;
    }
    // no sqrt for the number
    return -1;
}

 int main()
{
    double Number = 0;
    // in codntioned loop to keep testing the program.
    while (true) {
        Number = ReadNumber("Enter a number: ");
        if (Number == 0)
            break;

        cout << "My Sqrt Result: " <<  MySqrt(Number) << endl;
        cout << "C++ Sqrt Result: " << sqrt(Number) << endl;
        cout << endl;
    }

    return 0;
}
