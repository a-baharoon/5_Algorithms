#include <iostream>
#include <cstdlib>

using namespace std;

enum kCharType {
Lower = 1, Upper = 2, Special = 3, Digit = 4
};

int Random(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void RandChar(kCharType Char)
{
    switch (Char) {
        case kCharType::Lower:
            cout << (char) Random(97, 122) << endl;
            break;

        case kCharType::Upper:
            cout << (char) Random(65, 90) << endl;
            break;

        case kCharType::Special: {
            int rangeChoice = Random(1, 4);
            // I could have me a single case that will take Random(32, 47) but i decided to stretch it
            // and have all special charchter for my case, which are differently distributed.
            switch (rangeChoice) {
                case 1: cout << (char) Random(32, 47) << endl; break;  // !"#$%&'()*+,-./
                case 2: cout << (char) Random(58, 64) << endl; break;  // :;<=>?@
                case 3: cout << (char) Random(91, 96) << endl; break;  // [\]^_`
                case 4: cout << (char) Random(123, 126) << endl; break; // {|}~
            }
            break;
        }

        case kCharType::Digit:
            cout << Random(1, 10) << endl;
            break;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    RandChar(kCharType::Lower);
    RandChar(kCharType::Upper);
    RandChar(kCharType::Special);
    RandChar(kCharType::Digit);

    return 0;
}
