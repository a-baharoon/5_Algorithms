#include <iostream>
#include <cstdlib>
#include <cmath>

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

    return Number;
}

void FillArr(int Arr[], int Size)
{
    for(int i = 0; i < Size; i++)
        Arr[i] = RandomNumber(1, 10);
}

void AddElmToArr(int Arr[], int &SizeArr, int Number)
{
    ++SizeArr;
    Arr[SizeArr-1] = Number;
}


void CopyArrPrimeElmToArr2(int Arr[], int Size, int Arr2[], int &Size2)
{
    for (int i = 0; i < Size; i++)
        if (IsPrime(Arr[i]) == kIsPrime::Prime)
            AddElmToArr(Arr2, Size2, Arr[i]);
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

int main()
{
    int Arr1 [100];
    int Size1 = ReadNumber("Enter Array 1 Size: ");

    FillArr(Arr1, Size1);

    cout << "\nArray 1 Length: " << Size1 << endl;
    cout << "Array 1 Elements: ";
    PrintArr(Arr1, Size1);

    cout << endl;

    int Arr2 [100];
    int Size2 = 0;

    CopyArrPrimeElmToArr2(Arr1, Size1, Arr2, Size2);

    cout << "Array 2 Length: " << Size2 << endl;
    cout << "Array 2 Elements: ";
    PrintArr(Arr2, Size2);

    return 0;
}
