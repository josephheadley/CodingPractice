#include "Matchmaker.h"

int main(){
    Person Human;
    cout << Human.gender(1) << endl;
    cout << Human.firstname() << endl;
    cout << Human.race(1) << endl;
    cout << Human.lastname() << endl;
    cout << Human.height() << endl;
    cout << Human.weight() << endl;
    cout << Human.haircolor() << endl;
    cout << Human.eyecolor() << endl;
    cout << Human.homestate() << endl;
    cout << Human.bloodtype() << endl;
    cout << Human.language(0) << " and " << Human.language() << endl;
    cout << Human.birthday() << endl;
    cout << Human.age() << endl;
}