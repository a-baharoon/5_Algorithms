#include <iostream>

using namespace std;

void PrintTripleChars()
{
    string Letters = "AAA";

    // outer loop for 1st char, Letters[0]
    for(int i = 65; i <= 90; i++) {

        // inner loop for 2nd char, Letters[1]
        for(int j = 65; j <= 90; j++) {

         // most inner loop for 3nd char, Letters[2]
            for (int k = 65; k <= 90; k++) {
               cout << Letters << endl;
               Letters[2] += 1;
            }
            Letters[2] = 65;
            Letters[1] += 1;
        }
       Letters[1] = 65;
       Letters[0] += 1;
    }
}

// Alternate implementation (abo-hadhoud technique)
void PrintAAAtoZZZ()
{
    string Letters = "";

    // outer loop for 1st char, Letters[0]
    for(int i = 65; i <= 90; i++) {

        // inner loop for 2nd char, Letters[1]
        for(int j = 65; j <= 90; j++) {

         // most inner loop for 3nd char, Letters[2]
            for (int k = 65; k <= 90; k++) {
                Letters += char(i);
                Letters += char(j);
                Letters += char(k);
                cout << Letters << endl;
                Letters = "";
            }
        }
    }
}

int main()
{
    PrintTripleChars();

    return 0;
}

