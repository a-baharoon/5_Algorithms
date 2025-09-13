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

// Sum of all divisors for a perfect number
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

void PrintIsPerfect(int N)
{
   if (IsPerfect(N))
       cout << N << " is a Perfect Number" << endl;
   else
       cout << N << " is not a Perfect Number" << endl;
}

int main()
{
    PrintIsPerfect(ReadNumber("Enter N: "));

    return 0;
}
