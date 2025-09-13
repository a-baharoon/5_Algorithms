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

bool IsPalindrome(int N)
{
    return N ==  ReverseDigits(N);
}

int main()
{
    int N = ReadNumber("Enter N: ");

    if (IsPalindrome(N))
        cout << "Yes, " << N << " is a Palindrome number." << endl;
    else
        cout <<  "No, " << N << " is not a Palindrome number." << endl;

    return 0;
}
