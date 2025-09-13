#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int ReadNumber(string Message)
{
    int Number = 0;

    cout << Message;
    cin >> Number;

    while(Number < 0) {
        cout << "Please enter a positive number: ";
        cin >> Number;
    }

    cout << endl;
    return Number;
}
   ///////////////////////////////////////////////////////////////////////////////////////////////
   // since the digits are char's their values are derived from the ASCII table                 //
   // e.g 0 is 48 till 9 which is 57. I basically subtrcted 0 value to return the number value. //
   // e.g  57 - 48 = 9 etc.                                                                     //
   ///////////////////////////////////////////////////////////////////////////////////////////////

int CharToInt(char Digit)
{
    return Digit - '0';
}

int ReverseDigits(int N)
{
    string Digits = to_string(N);
    int Reversed = 0;
    // based on the number system we will multiply by the base and then deduct
    int Base = pow(10, Digits.length()-1);

    for (int i = Digits.length()-1; i >= 0; i--) {
       Reversed += CharToInt(Digits[i]) * Base;
       Base /= 10;
    }

    return Reversed;
}

int main()
{
    int N = ReadNumber("Enter N: ");

    cout << "Reversed: " << ReverseDigits(N) << endl;

    return 0;
}
