#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

enum kIsPrime {
   Prime = 1,
   NotPrime = 2
};

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

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

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

void FillArr(int Arr[], int Size)
{
    for(int i = 0; i < Size; i++)
        Arr[i] = RandomNumber(1, 100);
}

void PrintArr(int Arr[], int Size)
{
    for(int i = 0; i < Size; i++) {
        if (i == (Size-1))
            cout << Arr[i] << endl;
        else
            cout << Arr[i] << " ";
    }
}

// Copy Arr2 Prime Numbers into Arr 1
void CopyArrPrime(int Arr1[], int Arr2[], int Size, int &PrimeCount)
{
    PrimeCount = 0;
    for(int i = 0; i < Size; i++) {

        if (IsPrime(Arr2[i]) == 1) {
            Arr1[PrimeCount] = Arr2[i];
            ++PrimeCount;
        }

        else {
            Arr2[i] = -1;
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Arr1[100];
    int Arr2[100];

    int Size1 = ReadNumber("Enter Array Size: ");
    int Size2 = 0;

    FillArr(Arr1, Size1);
    cout << "Array 1 Elements: ";
    PrintArr(Arr1, Size1);

    CopyArrPrime(Arr2, Arr1, Size1, Size2);
    cout << "\nArray 1 Prime Elements: ";
    PrintArr(Arr2, Size2);

    return 0;
}
