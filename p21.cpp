
#include <iostream>
#include <cstdlib>

using namespace std;

enum kCharType {
Lower = 1, Upper = 2, Special = 3, Digit = 4
};

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

int Random(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

char RandChar(kCharType Char)
{
    switch (Char) {

        case kCharType::Lower:
            return (char) Random(97, 122);

        case kCharType::Upper:
            return (char) Random(65, 90);

        case kCharType::Special: {
            int rangeChoice = Random(1, 4);
            switch (rangeChoice) {
                case 1: return (char) Random(32, 47);    // !"#$%&'()*+,-./
                case 2: return (char) Random(58, 64);    // :;<=>?@
                case 3: return (char) Random(91, 96);    // [\]^_`
                case 4: return (char) Random(123, 126);  // {|}~
            }
        break;
        }

        case kCharType::Digit:
            return Random(1, 10);
    }

    // in case of a bug.
    return -1;
}

string KeyGen()
{
        string Key = "";

        for (int i = 0; i < 4; i++)  {

            for(int j = 0; j < 4; j++)
                Key += RandChar(kCharType::Upper);

            if (i != 3)
                Key += "-";

            else
                break;
        }
    return Key;
}

void MassKeyGen(int N)
{
    for(int i = 1; i <= N; i++)
        cout << "Key [" << i << "]: " << KeyGen() << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    MassKeyGen(ReadNumber("How many keys do you want: "));

    return 0;
}
