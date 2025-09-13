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

// could have used it by i just used std::abs THANKS!
int MyAbs(int Number)
{
    if (Number > 0)
        return Number;
    else
        return Number * -1;
}

double MyRound(double Number)
{
    bool negative = 0;
    if (Number < 0) {
        Number = abs(Number);
        negative = 1;
    }

    int IntNumber = Number;
    if (Number == IntNumber) {

        if (negative)
            return Number * -1;

        return Number;
    }

    else {
        Number *= 10;
        IntNumber = Number;

        if ((IntNumber % 10) >= 5) {

            if (negative)
                return -1 * ((Number - (IntNumber % 10)) / 10 + 1);

            return (Number - (IntNumber % 10)) / 10 + 1;
        }

        else {

            if (negative)
                return -1 * ((int) (Number / 10));

            return (int) (Number / 10);
        }
    }
}

 int main()
{
    double Number = 0;
    // in codntioned loop to keep testing the program.
    while (true) {
        Number = ReadNumber("Enter a number: ");
        if (Number == -1)
            break;

        cout << "My Round Result: " <<  MyRound(Number) << endl;
        cout << "C++ Round Result: " << round(Number) << endl;
        cout << endl;
    }

    return 0;
}

/*
  Basically we are given a *number*:

  1. Check if that number is an integer or a floating point number
          IF number % 1 == 0 it is an integer.
               don't do anything to it! (no rounding)
           Else Number is a floating point.
                Multiply it by 10
                extract the last digit
                compare it to judge if you are you going to round up or round small.

   ----- Note: a better technique to check the types was just store the number in an int var and then check
               if the int var value equaled our float value this means its an int.
               this techique was used since we can't % on floats.
*/
