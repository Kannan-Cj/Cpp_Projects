#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

using  std::cout,std::cin,std::string,std::endl;

void drawLine(int,char);
void Rule(int);
char WhetherSucceed(int,int,int,int*,int);
char Result(int,int,string);


int main()
{   char name[20],internalChoice='y',recurringchoice='n';
    int deposit,choice,Secret,Guess,bet;
    srand(time(NULL));
    drawLine(55,'$');
    cout<<"\n\t\tCASINO GAME\n";
    drawLine(55,'$');
    cout<<"\nEnter Your Name: ";
    gets(name);
    cout<<"\n\nEnter your Deposit Amount : $";
    cin>>deposit;
    block:
    cout<<"\n\nChoose Your Difficulty Level\n\n1.EASY\n\n2,MEDIUM\n\n3.HARD\n\n";
    cin>>choice;
    while(choice>3 || choice<1){
        cout<<"\n\nEnter choice Correctly bro...\n\n";
        cin>>choice;
    }
    Sleep(1000);
    Rule(choice);
    cout<<"\n\nYour Current Balance is $"<<deposit;
    cout<<endl<<name<<" Enter Your Bet Amount : $";
    cin>>bet;
    while(bet>deposit){
        cout<<endl<<name<<"\nWhy Entering more than your Deposit Amount\nThat's not gonna workout\n\nEnter Your Bet Amount : $";
        cin>>bet;
    }
    while(internalChoice=='y'||internalChoice=='Y'||bet<0){
    switch(choice){
    case 1:
        Secret = rand()%5 + 1;
        cout<<"\n\nGuess The Number Between 1 to 5 to win the Bet : ";cin>>Guess;
        recurringchoice=WhetherSucceed(Secret,Guess,bet,&deposit,4);
        internalChoice= Result(Secret,deposit,name);
        if(recurringchoice=='y')
            goto block;
        break;
    case 2:
        Secret = rand()%9 +1;
        cout<<"\n\nGuess The Number Between 1 to 9 to win the Bet : ";cin>>Guess;
        recurringchoice=WhetherSucceed(Secret,Guess,bet,&deposit,7);
        internalChoice= Result(Secret,deposit,name);
        if(recurringchoice=='y')
            goto block;
        break;
    case 3:
        Secret = rand()%13 +1;
        cout<<"\n\nGuess The Number Between 1 to 13 to win the Bet : ";cin>>Guess;
        recurringchoice=WhetherSucceed(Secret,Guess,bet,&deposit,10);
        internalChoice= Result(Secret,deposit,name);
        if(recurringchoice=='y')
            goto block;
        break;
    }}
    return 0;
}

void drawLine(int number,char symbol){
    cout<<"\n";
    for(int iter=0;iter<number;iter++){
        cout<<symbol;
    }
    cout<<"\n";
}

void Rule(int choice){
    drawLine(80,'_');
    cout<<"\n\t\tRULE OF THE GAME\n";
    drawLine(80,'_');
    if(choice==1)
        cout<<"\n\t\t1.Choose any number between 1 and 5\n\t\t2.If you win you will get 4 times of money you bet\n\t\t3.If you bet on wrong number you will lose your Betting Amount\n";
    else if(choice==2)
        cout<<"\n\t\t1.Choose any number between 1 and 9\n\t\t2.If you win you will get 7 times of money you bet\n\t\t3.If you bet on wrong number you will lose your Betting Amount\n";
    else
        cout<<"\n\t\t1.Choose any number between 1 and 13\n\t\t2.If you win you will get 10 times of money you bet\n\t\t3.If you bet on wrong number you will lose your Betting Amount\n";
    cout<<"\n\n*Disclaimer: Rules of the Game Change According to the Difficulty Level you have Chosen\n";
    drawLine(80,'_');

}

char WhetherSucceed(int secret,int guess,int bet,int*depositAddress,int multiplier){
    if(secret==guess){
            *depositAddress=*depositAddress+((*depositAddress)*multiplier);
            cout<<"\n\nGood Luck!! You won $"<<*depositAddress<<endl;
            return 'y';
    }
    else{
            cout<<"\n\nBad Luck this time !! You lost $"<<bet<<endl;
            *depositAddress-=bet;
    }
}

char Result(int Secret,int deposit,string name){
    char intChoice;
    cout<<"\n\nThe Winning Number was : "<<Secret<<"\n\n";
    cout<<name<<" , You have $"<<deposit<<" Amount\n\n";
        if(deposit==0){
            cout << "\nYou have no money to play";
            return 'n';
        }
        else{
            cout<<"\n\n--<Do you want to play again (y/n)? ";
            cin>>intChoice;
            return (intChoice == 'y'||intChoice == 'Y') ? 'y':'n';
        }
}

