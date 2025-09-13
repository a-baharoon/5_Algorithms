#include <iostream>

using namespace std;

void MultipHeader()
{
    cout << "\n\t\t\tMultiplication Table From 1 to 10\n" << endl;

    for (int i = 1; i <= 10; i++)
        cout << "\t" << i;
    cout << endl << endl;

    for (int i = 0; i < 83; i++)
        cout << "-";
    cout << endl;
}

void MultipValues()
{
    for (int i = 1; i <= 10; i++) {

        if (i == 10)
            cout << i << "   |  ";

        else
            cout << i << "    |  ";

        for (int j = 1; j <= 10; j++)
            cout << i * j << '\t';

        cout << endl;
    }
}

void MultipTable()
{
    MultipHeader();

    MultipValues();
}

int main()
{
    MultipTable();

    return 0;
}
