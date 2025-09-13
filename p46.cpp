#include <iostream>
#include <cmath>

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

int MyAbs(int Number)
{
    if (Number > 0)
        return Number;
    else
        return Number * -1;
}

 int main()
{
    // you can use Readnumber function to test it.
    cout  << "My Abs results: " << MyAbs(-10) << endl;
    cout  << "C++ Abs results: " << abs(-10) << endl;
    cout << "---------------------------------------\n";
    cout  << "My Abs results: " << MyAbs(10) << endl;
    cout  << "C++ Abs results: " << abs(10) << endl;

    return 0;
}
