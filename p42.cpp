#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

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
    for (int i = 0; i < Size; i++)
        Arr[i] = RandomNumber(1, 100);
}

int ArrOddCount(int Arr[], int Size)
{
    int OddCount = 0;
    for (int i = 0; i < Size; i++) {
        if (Arr[i] % 2 != 0)
            OddCount++;
    }
    return OddCount;
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

    cout << "Odd numbers count: " << ArrOddCount(Arr1, Size1) << endl;

    return 0;
}
