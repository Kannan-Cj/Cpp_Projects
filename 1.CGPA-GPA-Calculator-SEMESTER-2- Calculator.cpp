#include <iostream>
#include <string>
using std::cout,std::cin,std::string,std::endl;

int returngradevalue(string);

int main()
{
    float total=0;int choice;
    string grade,name;
    cout<<"\t\t**SEMESTER-2 CGPA/GPA CALCULATOR**\n\nCREDITs-Cj#08\n\n";
    cout<<"\n\t\tEnter your name:";cin>>name;
    cout<<"\n\t\tChoose Your Department\n\t\t1.AI&DS/CSBS\n\t\t2.CSE/AI&ML/CCE\n";
    cin>>choice;
    cout<<"\nEnter Your Grades to Find Your CGPA/GPA...\n";
    cout<<"\nHS3251 - ";cin>>grade;total+=2*returngradevalue(grade);
    cout<<"\nMA3251 - ";cin>>grade;total+=4*returngradevalue(grade);
    cout<<"\nPH3256 - ";cin>>grade;total+=3*returngradevalue(grade);
    cout<<"\nBE3251 - ";cin>>grade;total+=3*returngradevalue(grade);
    cout<<"\nGE3251 - ";cin>>grade;total+=4*returngradevalue(grade);
    if(choice==2){
        cout<<"\nCS3251 - ";cin>>grade;total+=3*returngradevalue(grade);
        cout<<"\nCS3271(lab) - ";cin>>grade;total+=2*returngradevalue(grade);
    }
    else{
        cout<<"\nAD3251 - ";cin>>grade;total+=3*returngradevalue(grade);
        cout<<"\nAD3271(lab) - ";cin>>grade;total+=2*returngradevalue(grade);

    }
    cout<<"\nGE3252 - ";cin>>grade;total+=1*returngradevalue(grade);
    cout<<"\nGE3271(lab) - ";cin>>grade;total+=2*returngradevalue(grade);
    cout<<"\nGE3272(lab) - ";cin>>grade;total+=2*returngradevalue(grade);
    cout<<endl<<"\t\t"<<name<<" CGPA/GPA is "<<total/26<<"\n\n\n";
    return 0;
}
int returngradevalue(string a){
    if(a=="o" || a=="O"){return 10;}
    else if(a=="a+" || a=="A+"){return 9;}
    else if(a=="a" || a=="A"){return 8;}
    else if(a=="b+" || a=="B+"){return 7;}
    else if(a=="b" || a=="B"){return 6;}
    else
        printf("INVALID GRADE ENTERED");
        return 0;
}
