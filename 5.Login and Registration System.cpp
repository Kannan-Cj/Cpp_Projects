 #include <iostream>
#include <string>
#include <fstream>
#define SIZE 10
using namespace std;

void display();
bool PasswordCheck(string);

class LoginRegister{
private:
    string username;
    string password="secret";
public:
    int choice2=0;
    bool flag = false;
    string temp_password="null";
    void Register(){
        while(choice2!=1){
            cout<<"\nPlease Enter your username:\n";
            cin>>username;
            cout<<"\nUserName - <"<<username<<">"<<"\nConfirm?\n\n";
            cout<<"[1] Yes\n[2] No\n";
            cin>>choice2;
        }
        while(password != temp_password){
                cout<<"\nPlease enter your password:\n";
                cin>>password;
                flag=PasswordCheck(password);
                while(flag==false){
                    cout<<"\nPassword Not Met the Requirements,\n\n\tminimum 8 letters\n\tmust have 1 Uppercase\n\tmust have 1 numbers\n\tmust have 1 special character\n\n ";
                    cin>>password;
                    flag=PasswordCheck(password);
                }
                cout<<"\nPlease renter your password:\n";
                cin>>temp_password;
        }
        cout<<"\n\t\tSuccessfully Created your Portfolio on Database";
        Database();         //need to implement using file streams
    }
    string getUsername(){
            return username;
        }
    string getPassword(){
            return password;
        }

    void Database(){
        fstream file;
        file.open("DataBase.txt",ios::out|ios::app);
        if(!file.is_open()){
            cout<<"\nSorry,something wrong occured saving to database! ";
        }
        else{
        file<<"Username - "<<username<<"\tPassword - "<<password<<endl;
        }
        file.close();
    }
};

int main()
{   int usercount=0;
    LoginRegister user[SIZE];
    int choice1=0;
    display();
    while(!(choice1>=1 && choice1<=3)){
        cout<<"\nEnter your choice : ";             //user++ do int user=0;
        cin>>choice1;
    }
    if(choice1==1){
        cout<<"\n\t\tLogin\n";
        string username;
        string pw;
        cout<<"\nUsername - ";cin>>username;
        cout<<"\nPassword - ";cin>>pw;
        for(int i=0;i<SIZE;i++){
            if(username==user[i].getUsername()){
                if(pw==user[i].getPassword()){
                    cout<<"\n Hi,"<<user[i].getUsername()<<endl;
                    cout<<"\n\n\t\tSuccessfully Logged in";
                    //you can further implement functions here for future updates;
                }
            }
            else{
                int choice3=1;
                while(choice3!=2){
                    cout<<"\n\n\tNot Yet Registered!!!\n";
                    cout<<"Would you like to Register ?\n[1]Yes\n[2]No";cin>>choice3;
                    if(choice3==1){
                        user[usercount].Register();
                        usercount++;
                    }else{
                        cout<<"\n\nOk ThankYou...\n";
                    }
                }
            }
        }
    }
    else if(choice1==2){
        cout<<"\n\t\tRegister\n";
        user[usercount].Register();
        usercount++;
    }
    else{
        cout<<"\n\t\tEXIT Successfully\n\n";
    }
    return 0;
}

void display(){
    cout<<"Hello, would you like to log in or register\n\n";
    cout<<"[1] Login\n[2] Register\n[3] Exit\n";
}

bool PasswordCheck(string pw){
    bool upper=false,splChar=false,numb=false;
    for(auto s:pw){
        if(isupper(s))
            upper=true;
        if(ispunct(s))
            splChar=true;
        if(isdigit(s))
            numb=true;
    }
    if(upper && splChar && numb && pw.size()>=8)
        return true;
    return false;
}

