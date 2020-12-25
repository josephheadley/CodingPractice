#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 

class Person{
    public:
    string Fname, Lname, Gender, Race, Height1, Height2, Height, Weight, Hcolor, Ecolor, Hstate, Btype, Lang, Month, Day, Year, Bday;
    string FirstNames[2][5] = {{"James", "John", "Robert", "Michael", "David"},{"Mary", "Patricia", "Linda", "Barbara", "Elizabeth"}};
    string LastNames[2][5] = {{"Williams", "Smith", "Nguyen", "Patel", "Garcia"}, {"Jackson", "Miller", "Kim", "Singh", "Rodriguez"}};
    string Races[5] = {"Black", "White", "Asian", "Arab", "Hispanic"}; //I know this list isn't PC so please don't come for my life. :')
    string Genders[2] = {"Male", "Female"};
    string HairColors[5] = {"black", "brown", "blond", "red", "white"};
    string EyeColors[7] = {"brown", "blue", "green", "hazel", "gray", "amber", "red"};
    string HomeStates[50] = {"Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming"};
    string BloodTypes[4] = {"A", "B", "AB", "O"};
    string Languages[8] = {"English", "French", "Spanish", "German", "Japanese", "Chinese", "Korean", "Arabic"};
    int year, Age;

    string gender(){
        srand(time(0));
        int a = rand() % 2;
        Gender = Genders[a];
        return Gender;
    }
    string gender(int p){
        Gender = Genders[p];
        return Gender;
    }
    string firstname(){
        srand(time(0));
        int b = rand() % 5;
        if (Gender == Genders[0]){
            Fname = FirstNames[0][b];
        }
        else if (Gender == Genders[1]){
            Fname = FirstNames[1][b];
        }
        return Fname;
    }
    string race(){
        srand(time(0));
        int c1 = rand() % 5;
        int c2 = rand() % 5;
        if (Gender == Genders[0]){
            Race = Races[c1];
        }
        if (Gender == Genders[1]){
            Race = Races[c2];
        }
        return Race;
    }
    string race(int r){
        Race = Races[r];
        return Race;
    }
    string lastname(){
        srand(time(0));
        int d1 = rand() % 2;
        int d2 = rand() % 2;
        if (Gender == Genders[0]){
            if (Race == Races[0]){
                Lname = LastNames[d1][0];
            }
            if (Race == Races[1]){
                Lname = LastNames[d1][1];
            }
            if (Race == Races[2]){
                Lname = LastNames[d1][2];
            }
            if (Race == Races[3]){
                Lname = LastNames[d1][3];
            }
            if (Race == Races[4]){
                Lname = LastNames[d1][4];
            }
        }
        if (Gender == Genders[1]){
             if (Race == Races[0]){
                Lname = LastNames[d2][0];
            }
            if (Race == Races[1]){
                Lname = LastNames[d2][1];
            }
            if (Race == Races[2]){
                Lname = LastNames[d2][2];
            }
            if (Race == Races[3]){
                Lname = LastNames[d2][3];
            }
            if (Race == Races[4]){
                Lname = LastNames[d2][4];
            }
        }
        return Lname;
    } 
    string height(){
        if (Gender == Genders[0]){
            srand(time(0));
            int e1 = rand() % (6-5+1)+5;
            int f1 = rand() % 12;
            Height1 = std::to_string(e1) + " feet ";
            Height2 = std::to_string(f1) + " inches";
            Height = Height1 + Height2;
        }
        if (Gender == Genders[1]){
            srand(time(0));
            int e2 = rand() % (5-5+1)+5;
            int f2 = rand() % 12;
            Height1 = std::to_string(e2) + " feet ";
            Height2 = std::to_string(f2) + " inches";
            Height = Height1 + Height2;
        } 
        return Height;
    }
    string weight(){
        if (Gender == Genders[0]){
            srand(time(0));
            int g = rand() % (270-130+1)+130;
            Weight = std::to_string(g) + " pounds";
        }
        if (Gender == Genders[1]){
            srand(time(0));
            int g = rand() % (175-100+1)+100;
            Weight = std::to_string(g) + " pounds";
        }
        return Weight;
    }
    string haircolor(){
        if (Race == Races[1]){
            srand(time(0));
            int h1 = rand() % 5;
            int h2 = rand() % 5;
            if (Gender == Genders[0]){
                Hcolor = HairColors[h1];
            }
            if (Gender == Genders[1]){
                Hcolor = HairColors[h2];
            } 
        }
        else{
            Hcolor = HairColors[0];
        }
        return Hcolor;
    }
    string eyecolor(){
        if (Race == Races[1]){
            srand(time(0));
            int i1 = rand() % 7;
            int i2 = rand() % 7;
            if (Gender == Genders[0]){
                Ecolor = EyeColors[i1];
            }
            if (Gender == Genders[1]){
                Ecolor = EyeColors[i2];
            }
        }
        else{
            Ecolor = EyeColors[0];
        }
        return Ecolor;
    }
    string homestate(){
        srand(time(0));
        int j1 = rand() % 50;
        int j2 = rand() % 50;
        if (Gender == Genders[0]){
            Hstate = HomeStates[j1];
        }
        if (Gender == Genders[1]){
            Hstate = HomeStates[j2];
        }
        return Hstate; 
    }
    string bloodtype(){
        srand(time(0));
        int k1 = rand() % 4;
        int k2 = rand() % 4;
        if (Gender == Genders[0]){
            Btype = BloodTypes[k1];
        }
        if (Gender == Genders[1]){
            Btype = BloodTypes[k2];
        }
        return Btype;
    }
    string language(){
        srand(time(0));
        int l1 = rand() % (8-1+1)+1;
        int l2 = rand() % (8-1+1)+1;
        if (Gender == Genders[0]){
            Lang = Languages[l1];
        }
        if (Gender == Genders[1]){
            Lang = Languages[l2];
        }
        return Lang;
    }
    string language(int q){
        Lang = Languages[q];
        return Lang;
    }
    string birthday(){
        srand(time(0));
        int m1 = rand() % (12-1+1)+1;
        int m2 = rand() % (12-1+1)+1;
        int n1 = rand() % (30-1+1)+1;
        int n2 = rand() % (30-1+1)+1;
        int o1 = rand() % (1990-1960+1)+1960;
        int o2 = rand() % (1990-1960+1)+1960;
        if (Gender == Genders[0]){
            Month = std::to_string(m1);
            Day = std::to_string(n1);
            Year = std::to_string(o1);
            year = o1;
            Bday = Month + "/" + Day + "/" + Year;
        }
        if (Gender == Genders[1]){
            Month = std::to_string(m2);
            Day = std::to_string(n2);
            Year = std::to_string(o2);
            year = o2;
            Bday = Month + "/" + Day + "/" + Year;
        }
        return Bday;
    }
    int age(){
        Age = 2019 - year;
        return Age; 
    }
};

class Father : public Person {};
class Mother : public Person {};
Father f;
Mother m;

class Child : public Father{
    public: 
    string IFname, ILname, IRace, IHeight1, IHeight2, IHeight, IWeight, IHcolor, IEcolor, ILang, IHstate, IBtype, IMonth, IDay, IYear, IBday;
    string IFirstNames[2][5] = {{"Richard", "Joseph", "Thomas", "Christopher", "Daniel"},{"Susan", "Jessica", "Sarah", "Lisa", "Emily"}};
    string LastNames[2][5] = {{"Williams", "Smith", "Nguyen", "Patel", "Garcia"}, {"Jackson", "Miller", "Kim", "Singh", "Rodriguez"}};
    string Races[5] = {"Black", "White", "Asian", "Arab", "Hispanic"}; //I know this list isn't PC so please don't come for my life. :')
    string Genders[2] = {"Male", "Female"};
    string HairColors[5] = {"black", "brown", "blond", "red", "white"};
    string EyeColors[7] = {"brown", "blue", "green", "hazel", "gray", "amber", "red"};
    string IHomeStates[50] = {"Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming"};
    string BloodTypes[4] = {"A", "B", "AB", "O"};
    string Languages[8] = {"English", "French", "Spanish", "German", "Japanese", "Chinese", "Korean", "Arabic"};
    int Iyear, IAge; 

    string inheritfirstname(){
        srand(time(0));
        int b2 = rand() % 5;
        if (Gender == Genders[0]){
            IFname = IFirstNames[0][b2];
        }
        else if (Gender == Genders[1]){
            IFname = IFirstNames[1][b2];
        }
        return IFname;
    }
    string inheritlastname(){
        ILname = f.lastname();
        return ILname;
    }
    string inheritrace(){
        IRace = f.race() + " and " + m.race();
        return IRace;
    }
    string inheritheight(){
        if (Gender == Genders[0]){
            srand(time(0));
            int e3 = rand() % (5-5+1)+5;
            int f3 = rand() % 12;
            IHeight1 = std::to_string(e3) + " feet ";
            IHeight2 = std::to_string(f3) + " inches";
            IHeight = IHeight1 + IHeight2;
        }
        if (Gender == Genders[1]){
            srand(time(0));
            int e4 = rand() % (4-4+1)+4;
            int f4 = rand() % 12;
            IHeight1 = std::to_string(e4) + " feet ";
            IHeight2 = std::to_string(f4) + " inches";
            IHeight = IHeight1 + IHeight2;
        } 
        return IHeight;
    }
    string inheritweight(){
        if (Gender == Genders[0]){
            srand(time(0));
            int g2 = rand() % (200-100+1)+100;
            IWeight = std::to_string(g2) + " pounds";
        }
        if (Gender == Genders[1]){
            srand(time(0));
            int g2 = rand() % (150-80+1)+80;
            IWeight = std::to_string(g2) + " pounds";
        }
        return IWeight;
    }
    string inherithair(){
        srand(time(0));
        int s = rand() % 2;
        if (s == 0){
            IHcolor = f.haircolor();
        }
        if (s == 1){
            IHcolor = m.haircolor();
        }
        return IHcolor;
    }
    string inheriteyes(){
        if (f.eyecolor() == EyeColors[0] || m.eyecolor() == EyeColors[0]){
            IEcolor = EyeColors[0];
        }
        else{
            srand(time(0));
            int t = rand() % 2;
            if (t == 0){
                IEcolor = f.eyecolor();
            }
            if (t == 1){
                IEcolor = m.eyecolor();
            }
        }
        return IEcolor;
    }
    string inheritlanguage(){
        ILang = Languages[0] + ", " + f.language() + ", and " + m.language();
        return ILang;
    }
    string inheritbloodtype(){
        if (f.bloodtype() == m.bloodtype()){
            IBtype = f.bloodtype();
        }
        else{
            srand(time(0));
            int u = rand() % 2;
            if (u == 0){
                IBtype = f.bloodtype();
            }
            if (u == 1){
                IBtype = m.bloodtype();
            }
        }
        return IBtype;
    }
    string inherithomestate(){
        srand(time(0));
        int j3 = rand() % 50;
        int j4 = rand() % 50;
        if (Gender == Genders[0]){
            IHstate = IHomeStates[j3];
        }
        if (Gender == Genders[1]){
            IHstate = IHomeStates[j4];
        }
        return IHstate; 
    }
    string inheritbirthday(){
        srand(time(0));
        int m3 = rand() % (12-1+1)+1;
        int m4 = rand() % (12-1+1)+1;
        int n3 = rand() % (30-1+1)+1;
        int n4 = rand() % (30-1+1)+1;
        int o3 = rand() % (2005-1995+1)+1995;
        int o4 = rand() % (2005-1995+1)+1995;
        if (Gender == Genders[0]){
            IMonth = std::to_string(m3);
            IDay = std::to_string(n3);
            IYear = std::to_string(o3);
            Iyear = o3;
            IBday = IMonth + "/" + IDay + "/" + IYear;
        }
        if (Gender == Genders[1]){
            IMonth = std::to_string(m4);
            IDay = std::to_string(n4);
            IYear = std::to_string(o4);
            Iyear = o4;
            IBday = IMonth + "/" + IDay + "/" + IYear;
        }
        return IBday;
    }
    int inheritage(){
        IAge = 2019 - Iyear;
        return IAge;
    }
};