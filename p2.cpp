#include <iostream>
#include <cmath>

using namespace std;

enum kIsPrime {
   Prime = 1,
   NotPrime = 2
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

kIsPrime IsPrime (int Number)
{
    int M = round(Number / 2);

    if (Number == 0 || Number == 1)
        return kIsPrime::NotPrime;

    for (int i = 2; i <= M; i++)
        if(Number % i == 0)
            return kIsPrime::NotPrime;

    return kIsPrime::Prime;
}

void PrimeTillN(int N)
{
    cout << "Prime numbers from 1 to " << N << ":" << endl;
    for (int i = 0; i <= N; i++) {
        if (IsPrime(i) == kIsPrime::Prime)
            cout << i << endl;
    }
}

int main()
{
    PrimeTillN(ReadNumber("Enter N: "));

    return 0;
}
