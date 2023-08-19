#include <bits/stdc++.h>
using namespace std;

void printtext(string text, bool printup = true, bool printdown = true){
    if(printup){
        cout<<"+-----------------------------------+" << endl;
        cout<<"|";
    }
    else{
        cout<<"|";
    }
    bool up = true;
    for(int i=text.size();i<35;i++){
        if(up){
            text = " "+text;
        }
        else{
            text = text +" ";
        }
        up = !up;
    }
    cout<<text.c_str();

    if(printdown){
        cout<<"|\n";
        cout<<"+-----------------------------------+\n";
    }
    else{
        cout<<"|"<<endl;;
    }
}

void lifeofman(int guess = 0){
    
    if(guess>=1){
        printtext("|",false,false);
    }
    else{
        printtext("",false,false);
    }
    
    if(guess>=2){
        printtext("|",false,false);
    }
    else{
        printtext("",false,false);
    }
    
    if(guess>=3){
        printtext("O",false,false);
    }
    else{
        printtext("",false,false);
    }
    
    if(guess==4){
        printtext("/  ",false,false);
    }
    
    if(guess==5){
        printtext("/| ",false,false);
    }
    
    if(guess>=6){
        printtext("/|\\",false,false);
    }
    else{
        printtext("",false,false);
    }
    
    if(guess>=7){
        printtext("|",false,false);
    }
    else{
        printtext("",false,false);
    }
    
    if(guess==8){
        printtext("/  ",false,false);
    }
    
    if(guess==9){
        printtext("/ \\",false,false);
    }
    else{
        printtext("",false,false);
    }
    
}

void printalpha(string input,char from,char to){
    string s="";
    for(char i=from;i<=to;i++){
        if(input.find(i)==string::npos){
            s+=i;
        }
        s+=" ";
    }
    printtext(s,false,false);
}

void printleft(string input){
    printtext("Remaining letters");
    printalpha(input,'A','M');
    printalpha(input,'N','Z');
}

bool wordcondition(string player, string guessed){
    bool win = true;
    string s="";
    for(int i=0;i<player.size();i++){
        if(guessed.find(player[i])==string::npos){
            win = false;
            s+="_ ";
        }
        else{
            s+=player[i];
            s+=" ";
        }
    }
    printtext(s,false);
    return win;
}

int trys(string player, string guessed){
    int wrong =0;
    for(int i=0;i<guessed.size();i++){
        if(player.find(guessed[i])==string::npos){
            wrong++;
        }
    }
    return wrong;
}

int main(){
    
    bool again = false;
    do{
        cout<<"Ask player 1 to give any word: ";
        string player;
        cin>>player;
        system("clear");
        string guesses;
        int no_of_wrong_trys = 0;
        bool win = false;
        do{
            system("clear");
            printtext("PLAY HANG MAN");
            lifeofman(no_of_wrong_trys);
            printleft(guesses);
            printtext("You've gotta try more");
            win = wordcondition(player,guesses);
            
            if(win){
                break;
            }
            char x;
            cout<<"Guess more letters from word: ";
            cin>>x;
            if(guesses.find(x)==string::npos){
                guesses+=x;
            }
            no_of_wrong_trys = trys(player,guesses);
            
        } while (no_of_wrong_trys < 10);
        
        if(win){
            printtext("YOHOOO!! YOU WON...");
        }
        else{
            printtext("YOU LOST...TRY AGAIN");
            cout<<endl<<"THE WORD IS: "<<player<<endl;
        }
        
        cout<<"\n IF YOU WANT TO PLAY AGAIN ENTER Y, IF NOT N: ";
        char b;
        cin>>b;
        if(b=='Y'){
            again = true;
        }
        else{
            again = false;
        }
        
    } while(again);
    
    return 0;
}