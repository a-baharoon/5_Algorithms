#include <iostream>

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

void InvertedPattern(int N)
{
    N += 64;
    for (int i = N; i >= 65; i--) {

        for (int j = 64; j < i; j++) {
            cout << (char) i;
        }

        cout << endl;
    }
}

int main()
{
    int N = ReadNumber("Enter N: ");

    InvertedPattern(N);

    return 0;
}
