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

int DivisorsSum(int N)
{
    int Sum = 0;
    for (int i = 1; i < N; i++) {
        if (N % i == 0)
            Sum += i;
    }
    return Sum;
}

bool IsPerfect(int N)
{
    if (N == 0)
        return false;

    return DivisorsSum(N) == N;
}

// The boundary of numbers 1 to N are excluded from checking.
void OneToN_Perfect(int N)
{
    cout << "The perfect numbers from 1 to " << N << ":" << endl;
    for (int i = 1; i < N; i++) {
        if (IsPerfect(i))
            cout << i << endl;
    }

}

int main()
{
    OneToN_Perfect(ReadNumber("Enter N: "));

    return 0;
}
