/*PwordGen4 by Joseph
The following C++ code generates a random password composed of letters, numbers, and special symbols. The 
code first asks the user what character length they want their password to be with the picklength() memeber
function. The makepword() member function serves several purposes aside from just generating a password. 
At the start of the function, there is an if-else statement to ensure that the user requests a character 
length between 8 and 32 and if the user does not the function uses recursion to get the user to keep 
requesting a character length until it fits the requirements. Inside the first if statement is a for loop 
that in one loop will randomly pick 4 characters from the original array of 75 characters that is a letter,
number, special symbol and any character. Next there is a switch statement that relies on the generation of 
a random integer z. This switch statement allows the order of the prior specific characters to be randomized 
by accounting for all 24 ways that they can be arranged with 24 individual cases. After the for loop is 
completed there is an if statement used to generate any remaining random characters in the event that the 
user requested a character length that is not a multiple of 4. The main function then instantiates an object 
of the Password class and then runs the two member functions for it to generate a random password for the 
user.*/

/*Edit: This version is different from PwordGen3 in that there is attempt to fix any repeating characters 
in the passwords generated. This correction attempt was implemented in the while statement immediately after 
the random assignment of characters to variables in the for loop of the makepword() method. However due to 
the nature of how passwords are generated, namely that they are strung together in groups of four characters, 
the repeat correction only ensures that there are no repeats in each group of characters rather than no 
repeats in the password as a whole.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Password {
    private:
    int a;
    char str[115] = {'あ い う え お か き く け こ さ し す せ そ た ち つ て と な に ぬ ね の は ひ ふ へ ほ ま み む め も や ゆ よ ら り る れ ろ わ を ア イ ウ エ オ カ キ ク ケ コ サ シ ス セ ソ タ チ ツ テ ト ハ ヒ フ ホ マ ミ ム メ モ ヤ ユ ヨ ラ リ ル レ ロ ワ ヲ 零 一 二 三 四 五 六 七 八 九 十 ！ ＠ ＃ ＄ ％ ＾ ＆ ＊ ＋ ＝ ： ； ？'};
    //char characters[115] = {'あ','い','う','え','お','か','き','く','け','こ','さ','し','す','せ','そ','た','ち','つ','て','と','な','に','ぬ','ね','の','は','ひ','ふ','へ','ほ','ま','み','む','め','も','や','ゆ','よ','ら','り','る','れ','ろ','わ','を','ア','イ','ウ','エ','オ','カ','キ','ク','ケ','コ','サ','シ','ス','セ','ソ','タ','チ','ツ','テ','ト','ハ','ヒ','フ','ホ','マ','ミ','ム','メ','モ','ヤ','ユ','ヨ','ラ','リ','ル','レ','ロ','ワ','ヲ','零','一','二','三','四','五','六','七','八','九','十','！','＠','＃','＄','％','＾','＆','＊','＋','＝','；','？'};
    char *characters = strtok(str, " ");
    char charac, spcharac1, spcharac2, spcharac3, excharac;
    int b = sizeof(characters)-1;
    string e;
    
    public:
        void picklength(){
            srand(time(0));
            cout << "Please state the number of characters you want your random password to have: " << endl;
            cin >> a;
        }
        void makepword(){
            if(a >= 8 && a <= 32){
                for(int c = 0; c < a/4; c++){
                    charac = characters[rand()%b];
                    spcharac1 = characters[rand()%46];
                    spcharac2 = characters[rand()%(91-47+1)+47];
                    spcharac3 = characters[rand()%(b-92+1)+92];
                    while(charac==spcharac1 || charac==spcharac2 || charac==spcharac3){
                        charac = characters[rand()%b];
                        spcharac1 = characters[rand()%52];
                        spcharac2 = characters[rand()%(61-53+1)+53];
                        spcharac3 = characters[rand()%(b-62+1)+62];
                    }
                        int z = rand()%(24-1+1)+1;
                        switch(z){
                            case 1:
                            cout << charac << spcharac1 << spcharac2 << spcharac3;
                            break;
                            case 2:
                            cout << charac << spcharac1 << spcharac3 << spcharac2;
                            break;
                            case 3:
                            cout << charac << spcharac2 << spcharac1 << spcharac3;
                            break;
                            case 4:
                            cout << charac << spcharac2 << spcharac3 << spcharac1;
                            break;
                            case 5:
                            cout << charac << spcharac3 << spcharac2 << spcharac1;
                            break;
                            case 6:
                            cout << charac << spcharac3 << spcharac1 << spcharac2;
                            break;
                            case 7:
                            cout << spcharac1 << charac << spcharac2 << spcharac3;
                            break;
                            case 8:
                            cout << spcharac1 << charac << spcharac3 << spcharac2;
                            break;
                            case 9:
                            cout << spcharac1 << spcharac2 << charac << spcharac3;
                            break;
                            case 10:
                            cout << spcharac1 << spcharac2 << spcharac3 << charac;
                            break;
                            case 11:
                            cout << spcharac1 << spcharac3 << charac << spcharac2;
                            break;
                            case 12:
                            cout << spcharac1 << spcharac3 << spcharac2 << charac;
                            break;
                            case 13:
                            cout << spcharac2 << charac << spcharac1 << spcharac3;
                            break;
                            case 14:
                            cout << spcharac2 << charac << spcharac3 << spcharac1;
                            break;
                            case 15:
                            cout << spcharac2 << spcharac1 << charac << spcharac3;
                            break;
                            case 16:
                            cout << spcharac2 << spcharac1 << spcharac3 << charac;
                            break;
                            case 17:
                            cout << spcharac2 << spcharac3 << charac << spcharac1;
                            break;
                            case 18:
                            cout << spcharac2 << spcharac3 << spcharac1 << charac;
                            break;
                            case 19:
                            cout << spcharac3 << charac << spcharac1 << spcharac2;
                            break;
                            case 20:
                            cout << spcharac3 << charac << spcharac2 << spcharac1;
                            break;
                            case 21:
                            cout << spcharac3 << spcharac1 << charac << spcharac2;
                            break;
                            case 22:
                            cout << spcharac3 << spcharac1 << spcharac2 << charac;
                            break;
                            case 23:
                            cout << spcharac3 << spcharac2 << charac << spcharac1;
                            break;
                            case 24:
                            cout << spcharac3 << spcharac2 << spcharac1 << charac;
                            break;
                        } 
                }
                if(!(a%4 == 0)){
                    for(int d = 0; d < a%4; d++){
                        excharac = characters[rand()%b];
                        cout << excharac;
                    }
                }
            }
            else{
                cout << "The length must be between 8 and 32 characters. Keep that in mind and try again." << endl;
                this->picklength();
                this->makepword();
            }
        }
};

int main(){
    Password pword;
    pword.picklength();
    pword.makepword();
}
