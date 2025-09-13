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
    for (int i = 1; i <= N; i++) {

        for (int j = 1; j <= i; j++) {
            cout << i;
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
