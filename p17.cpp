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

    cout << endl << endl;
    return Password;
}

bool BruteForcePassword(string Password)
{
    string Letters = "";
    int Trials = 0;

    for(int i = 65; i <= 90; i++) {

        for(int j = 65; j <= 90; j++) {

            for (int k = 65; k <= 90; k++) {
                Trials += 1;

                Letters += char(i);
                Letters += char(j);
                Letters += char(k);

                cout << "Trial [" << Trials << "] : " << Letters << endl;

                if (Password == Letters) {
                    cout << "\nPassword is " + Password + '\n' + "Found after " + to_string(Trials) + " Trial(s)\n";
                    return true;
                }

                Letters = "";
            }
        }
    }
    return false;
}

int main()
{
    string Password = ReadPassword("Enter enter a 3-Letter Password (All Capital): ");

    BruteForcePassword(Password);

    return 0;
}
