#include <iostream>
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

int ReverseDigit(int N)
{
    string Digits = to_string(N);
    int Sum = 0;
    // sum will start from first digit
    for (int i = 0; i < Digits.length(); i++)
        Sum += Digits[i] - '0';
    return Sum;
}

// this function was built for me to know ASCII numbers values
void ASCII ()
{
    for (int i = 48; i < 58; i++)
        cout << i << " " << (char) i << endl;
}

int main()
{
    int N = ReadNumber("Enter N: ");

    cout << "Sum Of Digits: " << ReverseDigit(N) << endl;

    return 0;
}
