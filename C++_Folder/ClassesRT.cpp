/*Classes by Joseph
The following C++ code utilizes a class definition to create methods that emulate
the process of creating and making use of a new bank account. The code uses the 
"Private" and "Public" access specifiers to separate and hide important variables 
like name and account number from being directly altered and to display methods that
can set and display the values of these encapsulated variables. The methods 
accountnum() and temppword() employ the functions rand(), srand(), and time(0) to 
create a truly random account number and temporary password respectively. The two 
login methods make use of if-else statements to ensure that the user inputs the 
correct information for the account number and the passwords. The else statement
uses recursion to allow the user as many chances as they need to input the correct
info. The main method, then makes use of all the created methods to emulate the 
experience of being a first time customer at the classiest choice for banking.*/

#include "ClassesRT.h"

int main()
{
    BankAccount customer;
    customer.username();
    customer.accountnum();
    customer.temppword();
    customer.firstlogin();
    customer.setpassword();
    customer.logout();
    customer.login(); 
    customer.showBalance();
    cout << "\nHmm? You would like to deposit some money in your new account? \nWow you move quick! Sure thing! Let's get started!" << endl;
    customer.deposit();
    customer.showBalance();
    cout << "\nHuh you want to make a withdrawal already?! Man you really do move fast!" << endl;
    customer.withdraw();
    customer.showBalance();
    cout << "\nOh are you done with your transactions? We hope to see you again soon!"<< endl;
    customer.logout();
    return 0;
}