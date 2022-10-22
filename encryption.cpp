#include <iostream>
#include <string>
using namespace std;
string KEY(string message, string password);
string encrypt(string message, string password);
string decrypt(string message, string password);
string blank(string text);
int main() {
    string password, message;      //defining 'message' and 'password' variable
    cout << "Enter a password that only contains the letters of the alphabet : "; getline(cin, password);  //getting the values of its from the user
    cout << "Enter a message that only contains the letters of the alphabet and the space character : "; getline(cin, message);
    cout << "---------------------" << endl;
    cout << "PASSWORD : " << password << endl << "MESSAGE : " << message << endl;
    cout << "--------------------- " << endl;
    string key = KEY(message, password);
    string newMessage = encrypt(message, password);
    cout << "ENCRYPTED MESSAGE : " << newMessage << endl;             // printing the encrypted and 
    cout << "DECRYPTED MESSAGE : " << decrypt(newMessage, key) << endl; //decrypted messages
    cout << "---------------------" << endl;
    return 0;
    system("pause>0");
}
string encrypt(string message, string password) {   //this function calculates the encrypted message
    string newMessage;
    for (int i = 0, j = 0; i < message.length(); ++i) {
        char h = message[i];
        if (h == ' ') {
            newMessage += ' ';
        }
        else {
            if (h >= 'a' && h <= 'z')
                h += 'A' - 'a';
            else if (h < 'A' || h > 'Z')
                continue;
            newMessage += (h + password[j] - 2 * 'A') % 26 + 'A'; j = (j + 1) % password.length();
        }
    }
    return newMessage;        // This function returns the encrypted message
}
string decrypt(string message, string password) {   //this function calculates the decrypted message 
    string originalMessage;
    for (int i = 0, j = 0; i < message.length(); ++i) {
        char h = message[i];
        if (h == ' ') {
            originalMessage += ' ';
        }
        else {
            if (h >= 'a' && h <= 'z')
                h += 'A' - 'a';
            else if (h < 'A' || h > 'Z')
                continue;
            originalMessage += (h - password[j] + 26) % 26 + 'A'; j = (j + 1) % password.length();
        }
    }
    return originalMessage;   //This function returns the decrypted message
}
string KEY(string message, string password)
{
    int a = message.size();
    for (int i = 0; ; i++)
    {
        if (a == i)
            i = 0;
        if (password.size() == message.size())
            break;
        password.push_back(password[i]);
    }
    return password;
}
string blank(string text) {
    string t;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            t += text[i + 1];
            i++;
        }
        else
            t += text[i];
    }
    return t;
}


