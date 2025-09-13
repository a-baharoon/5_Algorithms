
#include <iostream>
#include <cmath>
#include <cstring>
#include <string.h>

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

void PrintDigitsFreq(int N)
{
    kDigitsFreq Frequency = DigitsFreq(N);

    if (Frequency.Zero > 0)
        cout << "Digit 0 frequency is: " << Frequency.Zero << " Time(s)." << endl;

    if (Frequency.One > 0)
        cout << "Digit 1 frequency is: " << Frequency.One << " Time(s)." << endl;

    if (Frequency.Two > 0)
        cout << "Digit 2 frequency is: " << Frequency.Two << " Time(s)." << endl;

    if (Frequency.Three > 0)
        cout << "Digit 3 frequency is: " << Frequency.Three << " Time(s)." << endl;

    if (Frequency.Four > 0)
        cout << "Digit 4 frequency is: " << Frequency.Four << " Time(s)." << endl;

    if (Frequency.Five > 0)
        cout << "Digit 5 frequency is: " << Frequency.Five << " Time(s)." << endl;

    if (Frequency.Six > 0)
        cout << "Digit 6 frequency is: " << Frequency.Six << " Time(s)." << endl;

    if (Frequency.Seven > 0)
        cout << "Digit 7 frequency is: " << Frequency.Seven << " Time(s)." << endl;

    if (Frequency.Eight > 0)
        cout << "Digit 8 frequency is: " << Frequency.Eight << " Time(s)." << endl;

    if (Frequency.Nine > 0)
        cout << "Digit 9 frequency is: " << Frequency.Nine << " Time(s)." << endl;
}

int main()
{
    int N = ReadNumber("Enter N: ");

    PrintDigitsFreq(N);

    return 0;
}
