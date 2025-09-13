#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct kDigitsFreq {
    int Zero = 0;
    int One = 0;
    int Two = 0;
    int Three = 0;
    int Four = 0;
    int Five = 0;
    int Six = 0;
    int Seven = 0;
    int Eight = 0;
    int Nine = 0;
};

int ReadNumber(string Message)
{
    int Number = 0;
    cout << Message;

    while (true) {

        cin >> Number;

        // check if input failed (non-numeric input like 'a', 'abc', etc.)
        if(cin.fail()) {
            cin.clear();                // Clear error flags
            cin.ignore(1000, '\n');     // Clear input buffer
            cout << "Invalid input! Please enter a valid number: ";
            continue;
        }

        if (Number < 0) {
            cout << "Please enter a positive number: ";
            continue;
        }

        break;
    }
    cout << endl;
    return Number;
}

int CharToInt(char Digit)
{
    return Digit - '0';
}

kDigitsFreq DigitsFreq(int N)
{
    kDigitsFreq Number;
    string Digits = to_string(N);

   for (int i = 0; i < (int) Digits.length(); i++) {
        switch (CharToInt(Digits[i])) {

            case 0:
                Number.Zero += 1;
                break;

            case 1:
                Number.One += 1;
                break;

            case 2:
                Number.Two += 1;
                break;

            case 3:
                Number.Three += 1;
                break;

            case 4:
                Number.Four += 1;
                break;

            case 5:
                Number.Five += 1;
                break;

            case 6:
                Number.Six += 1;
                break;

            case 7:
                Number.Seven += 1;
                break;

            case 8:
                Number.Eight += 1;
                break;

            case 9:
                Number.Nine += 1;
                break;

            default:
                break;
        }
    }
    return Number;
}

int DigitFreq(int digit, int N)
{
    kDigitsFreq Frequency = DigitsFreq(N);

    switch (digit) {
        case 0:
            return Frequency.Zero;
        case 1:
            return Frequency.One;
        case 2:
            return Frequency.Two;
        case 3:
            return Frequency.Three;
        case 4:
            return Frequency.Four;
        case 5:
            return Frequency.Five;
        case 6:
            return Frequency.Six;
        case 7:
            return Frequency.Seven;
        case 8:
            return Frequency.Eight;
        case 9:
            return Frequency.Nine;
        default:
            return -1;
    }
}

int main()
{
    int N = ReadNumber("Enter N: ");
    int Digit = ReadNumber("Enter Digit: ");

    cout << "Digit " << Digit << " Frequency is: " << DigitFreq(Digit, N) << endl;

    return 0;
}
