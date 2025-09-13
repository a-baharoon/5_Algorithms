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

int ArrSum(int Arr[], int Size)
{
    int Sum = 0;
    for (int i = 0; i < Size; i++)
        Sum += Arr[i];
    return Sum;
}

int main()
{
    srand((unsigned)time(NULL));

    int Arr[100];
    int Size = ReadNumber("Enter Array Size: ");

    // fill the array elements
    FillArr(Arr, Size);

    cout << "\nArray Elements: ";
    PrintArr(Arr, Size);

    cout << "Arr Sum value: " << ArrSum(Arr, Size) << endl;

    return 0;
}
