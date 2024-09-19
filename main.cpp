#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* Creating user */
struct User{
      string username;
      string password;
};

int loginUser() {
      User user;
      /* Variables for taking input for login */
      string logUsername = user.username;
      string logPassword = user.password;

      /* Variables to store data from file */
      string fileUsername;
      string filePassword;

      /* Taking input from user to check if input is equal to data in file */
      cout << "-----------------------" << endl;
      cout << "LOGIN" << endl;
      cout << "Username: " << logUsername << endl;
      cin >> logUsername;
      cout << "Password: " << logPassword << endl;
      cin >> logPassword;

      /* Checking for file */
      ifstream loginFile;
      loginFile.open("login.txt");
      /* If you cannot open, return fail */
      if (!loginFile.is_open()) {
          cout << "Failed to open login file" << endl;
          return -1;
      }

      bool found = false;
      /* Reading each line (username and password) */
      while (loginFile >> fileUsername >> filePassword) {
            if (logUsername == fileUsername && logPassword == filePassword) {
                  found = true;
                  break;
            }
      }
      loginFile.close();

      if (found) {
            cout << "Login successful!" << endl;
            return 0;
      }else {
            cout << "Invalid username or password" << endl;
            return -1;
      }
}

void registerUser(){
      User newUser;
      /* Creating variables for new user */
      string regUsername = newUser.username;
      string regPsw = newUser.password;
      string repeatPassword;

      /* Taking choice from user */
      cout << "-----------------------" << endl;
      cout << "REGISTER" << endl;
      cout << "Enter your username: ";
      cin >> regUsername;
      cout << "Enter your password: ";
      cin >> regPsw;
      cout << "Please repeat a password: ";
      cin >> repeatPassword;

      /* Check if repeated password is ok */
      if(regPsw != repeatPassword){
            cout << "Password is not matching!" << endl;
      }else{
            /* Append new user data to file */
            ofstream loginFile("login.txt", ios::app);
            if (loginFile.is_open()) {
                  loginFile << newUser.username << " " << newUser.password << endl;
                  loginFile.close();
                  cout << "User registered successfully!" << endl;
            } else {
                  cout << "Failed to open file for registration!" << endl;
            }
      }
}

int main(){
      /* Taking choice from user */
      int choice;
      cout << "1. Register\n2. Login\nChoose option: " << endl;
      cin >> choice;
      switch (choice)
      {
      case 1:
            registerUser();
            break;
      case 2:
            loginUser();
            break;
      default:
            cout << "Please select 1 or 2!" << endl;
            break;
      }
      return 0;
}