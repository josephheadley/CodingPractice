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
    string Type;
    string Nature;
    int Level;
    int Hp;
    int Atk;
    int Def;
    int SpAtk;
    int SpDef;
    int Spd;
    string Moves[4];
    string RivName;
    string RivPokemon;
    string RivType;
    string RivMoves[4];

    public:
    string starters[3] = {"Turtwig", "Chimchar", "Piplup"};
    string types[3] = {"Grass", "Fire", "Water"};
    int choice;
    void ichooseu(){
        cout << "Alright then it's time to pick your starter Pokemon! \nYou have a choice " << starters[0] << "(1), " << starters[1] << "(2), or " << starters[2] << "(3)." << endl;
        cin >> choice;
        switch(choice){
            case 1:
            cout << "Oh, so you're picking the Grass type Pokemon Turtwig? That's a superb choice! \nTurtwig is a very sturdy Pokemon and is best used in battles of attrition." << endl;
            Name = starters[0];
            Type = types[0];
            break;
            case 2:
            cout << "Oh, so you're picking the Fire type Pokemon Chimchar? That's an excellent choice! \nChimchar is a strong and fast Pokemon, so he is well suited for guerilla warfare." << endl;
            Name = starters[1];
            Type = types[1];
            break;
            case 3:
            cout << "Oh, so you're picking the Water type Pokemon Piplup? That's a wonderful choice! \nPiplup is more geared to special attacks, therefore long distance battling is its strong suit." << endl;
            Name = starters[2];
            Type = types[2];
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
        if(Name == "Turtwig"){
            Moves[0] = "Tackle";
            Moves[1] = "Withdraw";
            Moves[2] = "Absorb";
        }
        if(Name == "Chimchar"){
            Moves[0] = "Scratch";
            Moves[1] = "Leer";
            Moves[2] = "Ember";
        }
        if(Name == "Piplup"){
            Moves[0] = "Pound";
            Moves[1] = "Growl";
            Moves[2] = "Bubble";
        }
    }
    /*void learnMoves(){
        string move1, move2, move3, move4;
        cout << "So what moves do you want " << this->showName() << " to have?" << endl;
        cin >> move1 >> move2 >> move3 >> move4;
        cout << "\nYou want to teach " << this->showName() << " " << move1 << ", " << move2 << ", " << move3 << ", and " << move4 << "? \nOk then you're all set then!" << endl;
        Moves[0] = move1;
        Moves[1] = move2;
        Moves[2] = move3;
        Moves[3] = move4;
    }*/
    void showPokemon(){
        cout << "Pokemon: " << Name << endl;
        cout << "Type: " << Type << endl;
        cout << "Nature: " << Nature << endl;
        cout << "Level: " << Level << endl;
        cout << "Health Points: " << Hp << endl;
        cout << "Attack: " << Atk << endl;
        cout << "Defense " << Def << endl;
        cout << "Special Attack: " << SpAtk << endl;
        cout << "Special Defense: " << SpDef << endl;
        cout << "Speed: " << Spd << endl;
        cout << "\nMoves: " << endl << Moves[0] << endl << Moves[1] << endl << Moves[2] << endl;
    }
    string showName(){
        return Name;
    }
    void pickrivalName(){
        cin >> RivName;
    }
    string showrivalName(){
        return RivName;
    }
    void theychoosethem(){
        int rivchoice = (choice%3)+1;
        switch(rivchoice){
            case 1:
            RivPokemon = starters[0];
            RivType = types[0];
            break;
            case 2:
            RivPokemon = starters[1];
            RivType = types[1];
            break;
            case 3:
            RivPokemon = starters[2];
            RivType = types[2];
            break;
        }
    }
    string showrstarterName(){
        return RivPokemon;
    }
    void setRivMoves(){
        if(RivPokemon == "Turtwig"){
            RivMoves[0] = "Tackle";
            RivMoves[1] = "Withdraw";
            RivMoves[2] = "Absorb";
        }
        if(RivPokemon == "Chimchar"){
            RivMoves[0] = "Scratch";
            RivMoves[1] = "Leer";
            RivMoves[2] = "Ember";
        }
        if(RivPokemon == "Piplup"){
            RivMoves[0] = "Pound";
            RivMoves[1] = "Growl";
            RivMoves[2] = "Bubble";
        }
    }
    void showRivPokemon(){
        cout << "Pokemon: " << RivPokemon << endl;
        cout << "Type: " << RivType << endl;
        cout << "Nature: " << Nature << endl;
        cout << "Level: " << Level << endl;
        cout << "Health Points: " << Hp << endl;
        cout << "Attack: " << Atk << endl;
        cout << "Defense " << Def << endl;
        cout << "Special Attack: " << SpAtk << endl;
        cout << "Special Defense: " << SpDef << endl;
        cout << "Speed: " << Spd << endl;
        cout << "\nMoves: " << endl << RivMoves[0] << endl << RivMoves[1] << endl << RivMoves[2] << endl;
    }
};
int main()
{
    Pokemon starter;
    starter.ichooseu();
    starter.setNature();
    starter.setStats();
    starter.setMoves();
    //starter.learnMoves();
    cout << "\nWhy don't you take a closer look at your new Pokemon's stats?" << endl;
    starter.showPokemon();
    cout << "\nWell then, valiant 10 year old warrior!" << endl;
    cout << "You are finally ready to leave the comfort and safety of your home!" << endl;
    cout << "Start gambling on organized superpowered animal fighting!" << endl;
    cout << "And topple untouchable yet completely conspicuous crime syndicates!" << endl;
    cout << "With " << starter.showName() << " by your side, go and start your Pokemon Adventure! Now!" << endl;
    cout << "\nOh wait! I completely forgot about your loser of a rival! What was their name again?" << endl;
    Pokemon rival;
    rival.pickrivalName();
    cout << "Oh yes that's right his name was " << rival.showrivalName() << "! Hey " << rival.showrivalName() << "! Did you want a Pokemon? I just happen to have some spares in my pocket." << endl; 
    Pokemon rstarter;
    rstarter.theychoosethem();
    cout << "Hmm looks like " << rival.showrivalName() << " picked " << rstarter.showrstarterName() << ". Huh... Interesting how he got that Pokemon ain't it?" << endl;
    rstarter.setNature();
    rstarter.setStats();
    rstarter.setRivMoves();
    cout << "Although their Pokemon doesn't really seem that exceptional." << endl;
    rstarter.showRivPokemon(); 
    cout << "\nWell what are you waiting for? Go kick their ass!" << endl;    
}