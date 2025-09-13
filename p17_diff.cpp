#include <iostream>
#include <string>

using namespace std;

bool ValidatePassword(string Password)
{
    bool PassCond = (Password[0] >= 'A' && Password[0] <= 'Z') &&
                (Password[1] >= 'A' && Password[1] <= 'Z') &&
                (Password[2] >= 'A' && Password[2] <= 'Z');

    return PassCond;
}

string ReadPassword(string Message)
{
    string Password = "";

    cout << Message << " ";
    cin >> Password;

    while (!(ValidatePassword(Password)))  {

        cout << "Please enter any 3 capital chars from A to Z ";
        cin >> Password;
    }

    return Password;
}

void Trials(string Password)
{
    int Trials = 0;

    while (Trials <= 6) {
        Trials += 1;
        if(Password  == ReadPassword("Trial [" + to_string(Trials) + "] "))
            break;

    }
    cout << "\nGuessed after " << Trials << " Trial(s)." << endl;
}

int main()
{
    string Password = ReadPassword("Enter enter Password: ");

    cout << '\n' << endl;

    Trials(Password);

    return 0;
}
