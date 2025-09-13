#include <iostream>
#include <string>

using namespace std;

string ReadText()
{
    string Text;

    cout <<"Please enter Text: ";
    getline(cin, Text);

    cout << endl;
    return Text;
}

string Encrypt(string Text, int Key)
{

    for(int i = 0; i < Text.length(); i++)
        Text[i] += Key;

    // text after encryption process
    return Text;
}


string Decrypt(string Text, int Key)
{

    for(int i = 0; i < Text.length(); i++)
        Text[i] -= Key;


    // text after decryption process
    return Text;
}

int main()
{
   string Name = ReadText();

   cout << "Text before encryption: " <<  Name << endl;

   Name = Encrypt(Name, 2);
   cout << "Text after  encryption: " <<  Name << endl;

   Name = Decrypt(Name, 2);
   cout << "Text after  decryption: " <<  Name << endl;

   return 0;
}
