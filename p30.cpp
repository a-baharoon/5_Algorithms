#include <iostream>
#include <cstdlib>

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

    cout << endl;
    return Number;
}

void FillArr(int Arr[], int Size)
{
    for(int i = 0; i < Size; i++)
        Arr[i] = RandomNumber(1, 10);
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

void ArrSum (int Arr1[], int Arr2[], int Arr3[], int Size)
{
    for(int i = 0; i < Size; i++)
        Arr3[i] = Arr1[i] + Arr2[i];
}

int main()
{
    srand((unsigned)time(NULL));

    int Arr1[100];
    int Arr2[100];
    int Arr3[100];

    int Size = ReadNumber("Enter Array Size: ");

    cout << "------- Arrays before copying -------" << endl;

    FillArr(Arr1, Size);
    cout << "\nArray 1 Elements: ";
    PrintArr(Arr1, Size);

    FillArr(Arr2, Size);
    cout << "\nArray 2 Elements: ";
    PrintArr(Arr2, Size);

    ArrSum(Arr1, Arr2, Arr3, Size);
    cout << "\nArray 3 Elements: ";
    PrintArr(Arr3, Size);

    return 0;
}
