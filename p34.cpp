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

// It will return the index of the number, could be used for our prev problem
int NinArrIndex(int Arr1[], int Size, int Number)
{
    for (int i = 0; i < Size; i++) {
         if (Arr1[i] == Number)
             return i;
    }
    return -1;
}

bool NumberinArr(int Arr[], int Size, int Number)
{
     for (int i = 0; i < Size; i++) {
        if (Arr[i] == Number)
            return true;
     }
     return false;
}

int main()
{
    srand((unsigned)time(NULL));

    int Arr1[100];

    int Size = ReadNumber("Enter Array Size: ");

    FillArr(Arr1, Size);

    cout << "\nArray 1 Elements: ";
    PrintArr(Arr1, Size);

    int Number = ReadNumber("\nEnter a number to look for: ");

    if (NumberinArr(Arr1, Size, Number)) {
        cout << "The number index is: " << NinArrIndex(Arr1, Size, Number)<< endl;
        cout << "The number position is: " << NinArrIndex(Arr1, Size, Number) + 1 << endl;
    }
    else {
        cout << "The number was not found. :-(" << endl;
    }

    return 0;
}
