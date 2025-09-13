#include <iostream>
#include <string>

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

void ReadArrElmnt(int Arr[], int Size)
{
    for(int i = 0; i < Size; i++) {
        cout << "Element [" << (i + 1) << "] : ";
        cin >> Arr[i];
    }
}

int ArrDuplicates(int N, int Arr[], int Size)
{
    int Counter = 0;
    for(int i = 0; i < Size; i++) {
        if (Arr[i] == N)
            Counter++;
    }
   return Counter;
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
    int Arr[100];
    int Size = ReadNumber("Enter Array Size: ");

    ReadArrElmnt(Arr, Size);

    int Duplicate = ReadNumber("Enter the number you want to check its repetition in the array: ");

    cout << "\nOriginal Array: ";
    PrintArr(Arr, Size);


    cout << Duplicate << " Is repeated " << ArrDuplicates(Duplicate, Arr, Size) << " time(s).\n";


    return 0;
}
