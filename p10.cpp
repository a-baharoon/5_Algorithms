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

void ReverseDigit(int N)
{
    string Digits = to_string(N);

    for (int i = 0; i < Digits.length(); i++)
       cout << Digits[i] << endl;
}

int main()
{
    int N = ReadNumber("Enter N: ");

    ReverseDigit(N);

    return 0;
}
