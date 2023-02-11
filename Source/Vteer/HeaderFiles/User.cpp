#include "User.h"

#include <iostream>
#include <fstream>

using namespace std;

//Default constructor for the user class
User::User()
{
    //Empty
}

User::User(int newId, string newUsername, string newPassword, string newEmail)
{
    userid = newId;
    username = newUsername;
    password = newPassword;
    email = newEmail;

    writeNewUser();

    cout << "New user ID " << newId << " has been saved." << endl;
}

User::getUserId() {
    return userid;
}

string User::getUsername() {
    return username;
}

string User::getPassword() {
    return password;
}

string User::getEmail() {
    return email;
}

User::setUserId(int setUserId) {
    userid = setUserId;
    cout << "User ID changed to " << userid;
}

User::setUsername(string setUsername) {
    username = setUsername;
}

User::setPassword(string setPassword) {
    password = setPassword;
}

User::setEmail(string setEmail) {
    email = setEmail;
}

User::writeNewUser() {
     ofstream userfile ("userfile.txt", ios::out | ios::app);
      if (userfile.is_open())
      {
        userfile << userid << "," << username << "," << password << "," << email << "\n";
        userfile.close();
      }
      else cout << "Error: Could not open userfile.txt";
}

User::~User() {

}


