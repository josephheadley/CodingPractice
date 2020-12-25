#include <iostream>
#include <cstdlib>
using namespace std;

class Temperature {  
    public:
        double temp, newtemp;
        char sys;
        void setTemp() {
            cout << "Please state whether you are converting from Celsius (C) or Fahrenheit (F): " << endl;
            cin >> sys;
            cout << "Please state the value of the temperature you would like to convert: " << endl;
            cin >> temp;
        }
        void Conversion(){
            if(sys == 'C' || sys == 'c'){
                newtemp = (temp * 1.8) + 32;
                cout << "The initial temperature in Celsius is " << newtemp << " degrees in Fahrenheit. " << endl;
            }
            if(sys == 'F' || sys == 'f'){
                newtemp = ((temp - 32) * 5)/9;
                cout << "The initial temperature in Fahrenheit is " << newtemp << " degrees in Celsius. " << endl;
            }
        }
};

int main(){
    Temperature num;
    num.setTemp();
    num.Conversion();
}