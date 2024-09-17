#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct User{
      string username;
      string password;
};

void registerUser(){
      User newUser;
      string regUsername = newUser.username;
      string regPsw = newUser.password;
      string repeatPassword;

      cout << "Enter your username: ";
      cin >> regUsername;
      cout << "Enter your passowrd: ";
      cin >> regPsw;
      cout << "Please repeat a password: ";
      cin >> repeatPassword;

      if(regPsw != repeatPassword){
            cout << "Password is not matching!" << endl;
      }else{

      }
}

bool loginUser(){

}

int main(){
      int choice;
      cout << "1. Register\n2.Login\nChoose option: " << endl;
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