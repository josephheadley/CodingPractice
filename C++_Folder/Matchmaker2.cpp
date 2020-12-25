#include "Matchmaker.h"

int main(){
    Child c1;
    Child c2;
    cout << f.gender(0) << endl;
    cout << f.firstname() << endl;
    cout << f.race() << endl;
    cout << f.lastname() << endl;
    cout << f.height() << endl;
    cout << f.weight() << endl;
    cout << f.haircolor() << endl;
    cout << f.eyecolor() << endl;
    cout << f.homestate() << endl;
    cout << f.bloodtype() << endl;
    cout << f.language(0) << " and " << f.language() << endl;
    cout << f.birthday() << endl;
    cout << f.age() << endl;
    
    cout << "\n" << m.gender(1) << endl;
    cout << m.firstname() << endl;
    cout << m.race() << endl;
    cout << m.lastname() << endl;
    cout << m.height() << endl;
    cout << m.weight() << endl;
    cout << m.haircolor() << endl;
    cout << m.eyecolor() << endl;
    cout << m.homestate() << endl;
    cout << m.bloodtype() << endl;
    cout << m.language(0) << " and " << m.language() << endl;
    cout << m.birthday() << endl;
    cout << m.age() << endl;

    cout << "\n" << c1.gender(0) << endl;
    cout << c1.inheritfirstname() << endl;
    cout << c1.inheritrace() << endl;
    cout << c1.inheritlastname() << endl;
    cout << c1.inheritheight() << endl;
    cout << c1.inheritweight() << endl;
    cout << c1.inherithair() << endl;
    cout << c1.inheriteyes() << endl;
    cout << c1.inherithomestate() << endl;
    cout << c1.inheritbloodtype() << endl;
    cout << c1.inheritlanguage() << endl;
    cout << c1.inheritbirthday() << endl;
    cout << c1.inheritage() << endl;

    cout << "\n" << c2.gender(1) << endl;
    cout << c2.inheritfirstname() << endl;
    cout << c2.inheritrace() << endl;
    cout << c2.inheritlastname() << endl;
    cout << c2.inheritheight() << endl;
    cout << c2.inheritweight() << endl;
    cout << c2.inherithair() << endl;
    cout << c2.inheriteyes() << endl;
    cout << c2.inherithomestate() << endl;
    cout << c2.inheritbloodtype() << endl;
    cout << c2.inheritlanguage() << endl;
    cout << c2.inheritbirthday() << endl;
    cout << c2.inheritage() << endl;
}