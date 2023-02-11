#include <iostream>
#include <fstream>
#include <string>
#include "HeaderFiles/User.h"

using namespace std;
bool validateUser(string username, string password);

int main()
{
    string username;
    string password;

    bool validlogin = false;

    cout << "This is Vteer. An application to connect volunteers with non-profit organisations.";

    while(!validlogin) {

    cout << "\n\nPlease login" << endl;

    cout << "Username:";
    cin >> username;
    cout << "Password:";
    cin >> password;

    validlogin = validateUser(username, password);

    }


    return 0;
}

bool validateUser(string user, string pass) {

    bool validate = false; //Set validation to false to begin with

        string line;
        ifstream userfile ("userfile.txt");
        if (userfile.is_open())
        {
        while ( getline (userfile,line) )
        {

          int firstcomma;
          int secondcomma;
          int thirdcomma;

          string checkuser;
          string checkpass;

          firstcomma = line.find(",");
          secondcomma = line.find(",",firstcomma+1);
          thirdcomma = line.find(",",secondcomma+1);

          checkuser = line.substr(firstcomma+1,(secondcomma-1)-firstcomma);
          checkpass = line.substr(secondcomma+1,(thirdcomma-1)-secondcomma);

          if(user==checkuser && pass == checkpass)
            {
            validate = true;
            }

        }
        userfile.close();
        }

        else cout << "Could not open the userfile for login validation. Either it is locked or does not exist in the source program file or directory.";

        if(validate) {
            cout << "\n\nLogin successful." << endl;
        } else {
            cout << "\n\nUsername or password incorrect." << endl;
        }

      return validate;

}




