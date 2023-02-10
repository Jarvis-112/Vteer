#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>


using namespace std;

class User {

private:
    int userid;
    string username;
    string password;
    string email;

public:
    User(); //default constructor
    User(int newId, string newUsername, string newPassword, string newEmail);
    getUserId();
    string getUsername();
    string getPassword();
    string getEmail();
    setUserId(int setUserId);
    setUsername(string setUsername);
    setPassword(string setPassword);
    setEmail(string setEmail);

    writeNewUser();

    ~User();
};


#endif // USER_H_INCLUDED
