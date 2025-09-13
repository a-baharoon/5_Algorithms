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

void FillArrToN(int Arr[], int Size)
{
    for(int i = 0; i < Size; i++)
        Arr[i] = i+1;
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


bool InArr(int Arr[], int Size, int Number)
{
    for(int i = 0; i < Size; i++) {
        if (Arr[i] == Number)
            return true;
    }
    return false;
}

void ShuffleArr(int Arr1[], int Size)
{
    int Arr2[100];
    int Random = 0;

    for (int i = 0; i < Size; i++) {

        do {

            Random = RandomNumber(1, Size);
            Arr1[i] = Random;
            Arr2[i] = Random;

        } while (InArr(Arr2, i, Random));
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Arr1[100];
    int Size = ReadNumber("Enter Array Size: ");

    FillArrToN(Arr1, Size);
    cout << "\nArray 1 Elements: ";
    PrintArr(Arr1, Size);

    ShuffleArr(Arr1, Size);
    cout << "\nArray 1 Shuffled Elements: ";
    PrintArr(Arr1, Size);

    return 0;
}

// Basically I am inputted an array of Size N.
// Input:  1 2 3 4 5
//
// Process:
//         1- Create Arr2 to track duplication while shuffling
//         2- Iterate through Arr1
//         3- Add a random element from the size of the array Arr1[i] = Random(1, 10)
//         4- Add the random element into Arr2
//         5- Go back to step 3 but before that check if the random generated number
//         6- exists in the new array if true regenrate a new number until its not dup
//         7- if not continue
//
//
// Output: 2 3 5 4 1         Shuffle it randomly each run.
//
//
