#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class BankAccount {
    private:
    string fname, lname;
    int anum;
    int pnum;
    string Pnum;
    string pword;
    int acnum;
    string tpnum;
    int Ch_account = 0;
    int Sv_account = 0;

    public:
      void username(){
          cout << "Hello customer. \nI take it that you want to start an account with Class Bank, the classiest choice for banking. \nTo start can I have your first name and last name?" << endl;
          cin >> fname >> lname;
          cout << "\nAlright " << fname << " " << lname << ", let's get started on your account right away!" << endl;
      }
      void accountnum(){
          srand(time(0));
          int a = rand()%9;
          int b = rand()%9;
          int c = rand()%9;
          int d = rand()%9;
          int e = rand()%9;
          int f = rand()%9;
          int g = rand()%9;
          anum = (a*1000000) + (b*100000) + (c*10000) + (d*1000) + (e*100) + (f*10) + g;
          cout << "\nOk so your unique account number will be " << anum << endl;
      }
      void temppword(){
          srand(time(0));
          int h = rand()%99;
          int i = rand()%99;
          pnum = (h*100) + i;
          cout << "\nAnd for simplicity's sake we'll start you off with a temporary password you change once you first log in. \nSo your temporary password is ClassyMoney" << pnum << endl;
          Pnum = "ClassyMoney" + std::to_string(pnum);
      }
      void setpassword(){
          cout << "\nNow what is the new password that you want to replace your temporary password with?" << endl;
          cin >> pword;
          cout << "So your new password is " << pword << "? Ok then let me change that for you right now." << endl;
          cout << "We recommend that you logout right now to test that your new password has been set." << endl;
      }
      void firstlogin(){
          cout << "\nPlease enter your account number and temporary password to log in to your account." << endl;
          cin >> acnum >> tpnum;
          if(acnum == anum && Pnum == tpnum){
              cout << "\nWelcome to your Class Bank Account!" << endl;
          }
          else{
              cout << "\nSorry, the information provided does not match any of the available accounts. Please try again.";
              this->firstlogin();
          }
      }
      void logout(){
          cout << "\n*Clicks Logout Button*" << endl;
          cout << "Thank you for doing business with Class Bank! We hope that it's been a classy transaction!" << endl;
      }
      void login(){
          int acnum2;
          string pword2;
          cout << "\nPlease enter your account number and password to log in to your account." << endl;
          cin >> acnum2 >> pword2;
           if(acnum2 == anum && pword2 == pword){
              cout << "\nWelcome to your Class Bank Account!" << endl;
              cout << "Hello " << fname << " " << lname << "! What transaction can I help you with today?" << endl;
          }
          else{
              cout << "\nSorry, the information provided does not match any of the available accounts. Please try again.";
              this->login();
      }
    }
      void showBalance(){
          cout << "\nSo you would like to see your new balance? Alright, give me a second to pull that up for you." << endl;
          cout << "The following is your Class Bank Account Info and Balance." << endl;
          cout << "\nName: " << fname << " " << lname << endl;
          cout << "Account Number: " << anum << endl;
          cout << "Checkings: $" << Ch_account << endl;
          cout << "Savings: $" << Sv_account << endl; 
      }
      void deposit(){
          int m, n;
          cout << "\nSo how much money do you want to deposit in your checkings and savings accounts?" << endl;
          cin >> m >> n;
          Ch_account = Ch_account + m;
          Sv_account = Sv_account + n;
      }
      void withdraw(){
          int o, p;
          cout << "\nSo how much money do you want to withdraw from your checkings and savings accounts?" << endl;
          cin >> o >> p;
          Ch_account = Ch_account - o;
          Sv_account = Sv_account - p;
      }
};