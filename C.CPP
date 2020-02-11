#include<stdio.h>
#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<graphics.h>
class bank
{
  int acno;
  char name[20];
  char address[30];
  char actype;
  double balance,amount;
public:
  void crt_ac();
  void ac_info();
  void dep_ac();
  void withdraw();
  void transfer();
  void delete();
  void read_file();
  void write_file();
};
void bank::write_file()
{ ofstream outfile;
  outfile.open("bank.txt");
  outfile<<acno<<endl;
  outfile<<name<<endl;
  outfile<<address<<endl;
  outfile<<actype<<endl;
  outfile<<balance<<endl;
  outfile.close();
}
void bank::read_file()
{ ifstream infile;
  infile.open("bank.txt");
  infile>>acno;
  infile>>name;
  infile>>address;
  infile>>actype;
  infile>>balance;
  infile.close();
}
void bank::crt_ac()
{ acno=rand();
  cout<<"Enter your full name : ";
  cin.ignore();
  cin.getline(name,20);
  cout<<"Enter your address : ";
  //cin.ignore();
  cin.getline(address,30);
  cout<<"What type of account do you want to open Saving(s) or Current(c)";
  cin>>actype;
  cout<<"Enter amount to deposit : ";
  cin>>balance;
  write_file();
  system("cls");
  cout<<"Your account is created :-)";

}
void bank::ac_info()
{   cout<<"Account No : "<<acno;
    cout<<"\nName::"<<name;
    cout<<"\nAddress::"<<address;
    cout<<"\nType of account ::"<<actype;
    cout<<"\nAmount in your account ::"<<balance;
    read_file();
}
void bank::dep_ac()
{int money;
cout<<"Enter the amount to be deposited::";
cin>>money;
balance=balance+money;
}
void graphics()
{ int gd,gm; char c;
 gd=DETECT;
 initgraph(&gd,&gm,"..\\BGI");
  line(10,10,getmaxx()-10,10);
  line(10,getmaxy()-10,getmaxx()-10,getmaxy()-10);
  line(10,10,10,getmaxy()-10);
  line(getmaxx()-10,10,getmaxx()-10,getmaxy()-10);
  outtextxy((getmaxx()/2)-120,getmaxy()/2,"WELCOME TO BANK MANGEMENT SYSTEM");
  outtextxy(120,getmaxy()-50,"Press Enter to continue....");
  scanf("%c",&c);
  system("cls");
}
void password()
{
 char ch,b;int i=0;
 char user[30],pass[30],u[30]="admin",p[30]="admin";
 cout<<"Do you want to login??(y/n)";
 cin>>b;
 if(b=='n')
 {exit(0);
 }
 else
{NULL;
}
printf("Enter username:");
gets(user);
printf("Enter password:");

 while((ch=getch())!=13)
  {
       if(ch==8)
     {if(i==0) continue;
     printf("\b \b");i--;continue;
     }
    printf("%c",'*');
    pass[i]=ch;
    i++;
  }
    pass[i]='\0';
    system("cls");
if(stricmp(user,u)==0&&stricmp(pass,p)==0) printf("Login sucessful\n");
else {printf("\bLogin unsecsesful\n"); password();}
}
void main()
{  int d; char p;
 graphics();
 clrscr();
bank obj;
password();

while('y')
{
cout<<"\n1.Create account";
cout<<"\n2.View account info";
cout<<"\n3.Deposit amount";
cout<<"\n4.Withdraw amount";
cout<<"\n5.Transfer amount";
cout<<"\n6.Delete account";
cout<<"\nExit";
cout<<"\nEnter choice";
cin>>d;
system("cls");
switch(d)
{
 case 1:
     obj.crt_ac();break;
 case 2:
     obj.ac_info();
     break;
 case 3:
     obj.dep_ac();
     break;
 case 4:
 exit(0);
 break;

 }
 cout<<"\nDo you want to select next option??(y/n)";
 cin>>p;
 if(p=='n'){exit(0);}
 }

getch();
}
