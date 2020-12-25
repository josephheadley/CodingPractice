#include <iostream>
#include <cstdlib>
using namespace std;

class Mass {
    public:
        double mass, newmass;
        string sys;
        void setMass(){
            cout << "Please state whether you are converting from Pounds (lb) or Kilograms (kg): " << endl;
            cin >> sys;
            cout << "Please state the value of the mass you would like to convert: " << endl;
            cin >> mass;
        }
        void Conversion(){
            if(sys == "lb"){
                newmass = mass * 0.453592;
                cout << "The initial mass in Pounds is " << newmass << " in Kilograms. " << endl;
            }
            if(sys == "kg"){
                newmass = mass * 2.2;
                cout << "The initial mass in Kilograms is " << newmass << " in Pounds. " << endl;
            }
        }
};

int main(){
    Mass num;
    num.setMass();
    num.Conversion();
}