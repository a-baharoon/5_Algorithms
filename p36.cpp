#include <iostream>

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

    return Number;
}

void FillArr(int Arr[], int &Size)
{
    bool cond = 0;
    for(int i = 0; i <= Size; i++) {
        Arr[i] = ReadNumber("Please enter a number: ");
        ++Size;

        cout << "Would you like to add another number? Enter 1 to continue, 0 to finish: ";
        cin >> cond;
        cout << endl;
        if (!cond)
            break;
    }
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

    int Size = 0;
    FillArr(Arr1, Size);

    cout << "Array Length: " << Size << endl;
    cout << "Array Elements: ";
    PrintArr(Arr1, Size);

    return 0;
}
