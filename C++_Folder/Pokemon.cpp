/*Pokemon by Joseph
The following C++ code utilizes a class definition to create methods that emulate 
when players pick their starter in a Pokemon game. This code serves as a lesson in 
access specifiers as it hides important variables as "Private" members but enables 
the values of those variables to be set and viewed through "Public" methods. Other
prominently used aspects of C++ are the "switch statement" to allow the user to 
choose the Pokemon they want and the "rand() function" in conjunction with the
"srand() and time(0) functions" to create truly random values to set the starter's
nature and stats.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Pokemon {
    private:
    string Name;
    string Nature;
    int Level;
    int Hp;
    int Atk;
    int Def;
    int SpAtk;
    int SpDef;
    int Spd;
    string Moves[4];

    public:
    void ichooseu(){
        int choice;
        string starters[3] = {"Turtwig", "Chimchar", "Piplup"};
        cout << "Alright then it's time to pick your starter Pokemon! \nYou have a choice " << starters[0] << "(1), " << starters[1] << "(2), or " << starters[2] << "(3)." << endl;
        cin >> choice;
        switch(choice){
            case 1:
            cout << "Oh, so you're picking the Grass type Pokemon Turtwig? That's a superb choice! \nTurtwig is a very sturdy Pokemon and is best used in battles of attrition." << endl;
            Name = "Turtwig";
            break;
            case 2:
            cout << "Oh, so you're picking the Fire type Pokemon Chimchar? That's an excellent choice! \nChimchar is a strong and fast Pokemon, so he is well suited for guerilla warfare." << endl;
            Name = "Chimchar";
            break;
            case 3:
            cout << "Oh, so you're picking the Water type Pokemon Piplup? That's a wonderful choice! \nPiplup is more geared to special attacks, therefore long distance battling is its strong suit." << endl;
            Name = "Piplup";
            break;
            default:
            cout << "So you don't want to be a Pokemon Trainer huh? I guess I'll offer my Pokemon to someone elsewhere then.";
        }
    }
    void setNature(){
        string natures[25] = {"Adamant", "Brave", "Lonely", "Naughty", "Bold", "Lax", "Relaxed", "Impish", "Timid", "Hasty", "Jolly", "Naive", "Mild", "Quiet", "Rash", "Modest", "Gentle", "Calm", "Sassy", "Careful", "Hardy", "Docile", "Serious", "Bashful", "Quirky"};
        srand(time(0));
        int i = rand() % 25;
        Nature = natures[i];
    }
    void setStats(){
        Level = 5;
        Hp = rand() % (21-18+1)+18;
        Atk = rand() % (7-4+1)+4;
        Def = rand() % (7-4+1)+4;
        SpAtk = rand() % (7-4+1)+4;
        SpDef = rand() % (7-4+1)+4;
        Spd = rand() % (7-4+1)+4;
    }
    void setMoves(){
        string move1, move2, move3, move4;
        cout << "So what moves do you want " << this->showName() << " to have?" << endl;
        cin >> move1 >> move2 >> move3 >> move4;
        cout << "\nYou want to teach " << this->showName() << " " << move1 << ", " << move2 << ", " << move3 << ", and " << move4 << "? \nOk then you're all set then!" << endl;
        Moves[0] = move1;
        Moves[1] = move2;
        Moves[2] = move3;
        Moves[3] = move4;
    }
    void showPokemon(){
        cout << "\nWhy don't you take a closer look at your new Pokemon's stats?" << endl;
        cout << "Pokemon: " << Name << endl;
        cout << "Nature: " << Nature << endl;
        cout << "Level: " << Level << endl;
        cout << "Health Points: " << Hp << endl;
        cout << "Attack: " << Atk << endl;
        cout << "Defense " << Def << endl;
        cout << "Special Attack: " << SpAtk << endl;
        cout << "Special Defense: " << SpDef << endl;
        cout << "Speed: " << Spd << endl;
        cout << "\nMoves: " << endl << Moves[0] << endl << Moves[1] << endl << Moves[2] << endl << Moves[3] << endl;
    }
    string showName(){
        return Name;
    }
};
int main()
{
    Pokemon starter;
    starter.ichooseu();
    starter.setNature();
    starter.setStats();
    starter.setMoves();
    starter.showPokemon();
    cout << "\nWell then, valiant 10 year old warrior!" << endl;
    cout << "You are finally ready to leave the comfort and safety of your home!" << endl;
    cout << "Start gambling on organized superpowered animal fighting!" << endl;
    cout << "And topple untouchable yet completely conspicuous crime syndicates!" << endl;
    cout << "With " << starter.showName() << " by your side, go and start your Pokemon Adventure! Now!" << endl;
}