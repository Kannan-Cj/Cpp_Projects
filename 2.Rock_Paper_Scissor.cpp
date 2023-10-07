#include <iostream>
#include <string>
#include "implementations.h"
#include<time.h>
#include<stdlib.h>

using std::cout,std::cin,std::string,std::endl;

int randomgenerator();

int main()
{
    string choices[3]={"ROCK","PAPER","SCISSOR"};
    char name[15];
    int Guess,i=0,points=0,cpoints=0;
    cout<<"\t\t##### ROCK PAPER SCISSOR ######\nLet's Play\n\n10-Round Game Let's See who wins\n\n";
    cout<<"Enter the Player Name:\n";
    gets(name);
    while(i<10){
            cout<<"Round-"<<++i;
            cout<<"\n-------------------------------------------\n";
            int Secret = randomgenerator();
            cout<<"*****1.Rock 2.Paper 3.Scissor*****";
            cout<<"\n\n\t"<<name<<" vs Computer";
            cout<<"\n\nEnter Your Choice: ";
            cin>>Guess;
            while(Guess!=1 && Guess!=2 && Guess!=3){
                cout<<"\nDon't try to fool me bro...\nEnter Proper Choice :)\n";
                cin>>Guess;
            }
            if(choices[Guess-1]=="ROCK"){
                if(choices[Secret-1]=="SCISSOR"){ points++;
                    cout<<choices[Guess-1]<<" vs "<<choices[Secret-1];
                    cout<<"\nYay! thats great..."<<"\nLet me see if you can again\n";
                }
                else if(choices[Secret-1]=="PAPER"){
                        cout<<choices[Guess-1]<<" vs "<<choices[Secret-1];
                        cout<<"\nOh!...Better Luck Next Time...\n";
                        cpoints++;}
                else{
                    cout<<choices[Guess-1]<<" vs "<<choices[Secret-1];
                    cout<<"\n\nBoth got 0 points\n\n";
                }
            }
            else if(choices[Guess-1]=="PAPER"){
                if(choices[Secret-1]=="ROCK"){points++;
                    cout<<choices[Guess-1]<<" vs "<<choices[Secret-1];
                    cout<<"\nYay! thats great..."<<"\nLet me see if you can again\n";
                }
                else if(choices[Secret-1]=="SCISSOR"){
                        cout<<choices[Guess-1]<<" vs "<<choices[Secret-1];
                        cout<<"\nOh!...Better Luck Next Time...\n";
                        cpoints++;}
                else{
                    cout<<choices[Guess-1]<<" vs "<<choices[Secret-1];
                    cout<<"\n\nBoth got 0 points\n\n";
                }
            }
            else if(choices[Guess-1]=="SCISSOR"){
                if(choices[Secret-1]=="PAPER"){points++;
                    cout<<choices[Guess-1]<<" vs "<<choices[Secret-1];
                    cout<<"\nYay! thats great..."<<"\nLet me see if you can again\n";
                }
                else if(choices[Secret-1]=="ROCK"){
                        cout<<choices[Guess-1]<<" vs "<<choices[Secret-1];
                        cout<<"\nOh!...Better Luck Next Time...\n";
                        cpoints++;}
                else{
                    cout<<choices[Guess-1]<<" vs "<<choices[Secret-1];
                    cout<<"\n\nBoth got 0 points\n\n";
                }

            }
            cout<<"\n"<<name<<" : "<<points<<endl;
            cout<<"\n"<<"Computer : "<<cpoints<<endl;
            cout<<"\n-------------------------------------------\n";
            }
    if(points==cpoints){
        cout<<"Tie Match";
    }
    else{
        cout<<"\nFINAL RESULT\n\n"<<name<<" : "<<points<<" pts\n"<<"Computer : "<<cpoints<<" pts\n"<<endl;
        (points>cpoints) ? cout<<name<<" got more pts than Computer":cout<<"Computer got more pts than "<<name;
    }
    return 0;
}
int randomgenerator(){
    int iSecret;
    srand(time(NULL));
    iSecret = rand() % 3 + 1; //between 1 and 3
    return iSecret;
}



