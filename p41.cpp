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
    Arr[0] = 50;
    Arr[1] = 60;
    Arr[2] = 70;
    Arr[3] = 70;
    Arr[4] = 60;
    Arr[5] = 50;
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

// elements of array arr2 will be copied reverly in arr1
void CopyArrRev(int Arr1[], int Arr2[], int Size)
{
    int j = 0;
    for(int i = Size-1; i >= 0; i--) {
        Arr1[j] = Arr2[i];
        j++;
    }
}

bool IsPalindromeArr(int Arr1[], int Arr2[], int Size)
{
    CopyArrRev(Arr1, Arr2, Size);
    for (int i = 0; i < Size; i++) {
        if (!(Arr1[i] == Arr2[i]))
            return false;
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    int Arr1[100];
    int Arr2[100];

    int Size = 6;

    FillArr(Arr1, Size);
    cout << "\nArray 1 Elements: ";
    PrintArr(Arr1, Size);

    if (IsPalindromeArr(Arr2, Arr1, Size))
        cout << "\nYes array is palindrome" << endl;
    else
        cout << "\nNo array is not palindrome" << endl;

    cout << "\nArray 2 Elements: ";
    PrintArr(Arr2, Size);
    cout << endl;

    return 0;
}
