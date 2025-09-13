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

// Copy Arr2 into Arr 1
void CopyArrRev(int Arr1[], int Arr2[], int Size)
{
    int j = 0;
    for(int i = Size-1; i >= 0; i--) {
        Arr1[j] = Arr2[i];
        j++;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Arr1[100];
    int Arr2[100];

    int Size = ReadNumber("Enter Array Size: ");

    cout << "------- Arrays -------" << endl;

    FillArr(Arr1, Size);
    cout << "\nArray 1 Elements: ";
    PrintArr(Arr1, Size);

    CopyArrRev(Arr2, Arr1, Size);
    cout << "\nArray 2 (Array1 but reversed) Elements: ";
    PrintArr(Arr2, Size);

    return 0;
}
