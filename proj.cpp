#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<cstdio>
using namespace std;

class Bus
{
protected:
    string no[10], drname[10];
    string stops [10][10];
    int nb=0,ns[10],busno=-1;
public:
string txt;
	 void addbus()
    {
    system("cls");
    cout<<"------------------ADD BUS------------------"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Enter bus number:-     "<<endl;
    cin>>busno;
    ofstream file;
     file.open("Bus.txt",ios::app);
     file<<busno<<endl;
    cout<<"Enter bus code         : ";
     cin>>no[busno-1];
     file<<no[busno-1]<<endl;
    cout<<"Enter driver name      : ";
    cin>>drname[busno-1];
    file<<drname[busno-1]<<endl;
     cout<<"Enter number of stops : ";
     cin>>ns[busno-1];
     file<<ns[busno-1]<<endl;
    for(int j=0;j<ns[busno-1];j++)
    {
    cout<<"Enter stop" << (j+1)<<"  : ";
     cin>>stops [busno-1][j];
     file<<stops[busno-1][j]<<endl;
    }
   file<<"****************************************************";
    file.close();
    nb++;
    return;
    }
    void showdetails()
    {
        system("cls");
        cout<<"-----------------bus details------------------"<<endl;
        ifstream file("Bus.txt");
        if(!file)
        {
        cout<<"             no buses available"<<endl;
        cout<<"----------------------------------------------"<<endl;
        }
        else
        {
            while(getline(file,txt))
            {
            cout<<txt<<endl;
            }
        }
    }

};

class Admin: public virtual Bus
{
private:
    string id, pass;
public:


    void adminmenu()
    {
        system("cls");
        adminlogin:
        cout<<"------------------ADMIN MENU------------------"<<endl;
        cout<<"----------------------------------------------"<<endl;
        cout<<"             Login to continue "<<endl;
        cout<<"             Enter your ID :";cin>>id;
        cout<<"             Enter password :"; cin>>pass;
        if(id=="admin" & pass=="admin")
        {
            int ch;
            system("cls");
            cout<<"              LOGIN SUCCESSFUL!                "<<endl;
            while(1)
            {
                cout<<"-----------------ADMIN MENU--------------------"<<endl;
                cout<<"-----------------------------------------------"<<endl;
                cout<<"                 1. Add Bus                    "<<endl;
                cout<<"                 2. Show Buses                 "<<endl;
                cout<<"                 3. Logout                     "<<endl;
                cout<<"-----------------------------------------------"<<endl;
                cout<<"               enter your choice: ";
                cin>>ch;
                switch(ch)
               {
                   case 1:
                        addbus();
                        break;
                   case 2:
                        showdetails();
                        break;
                   case 3:
                        cout<<"LOGGED OUT"<<endl;
                        return;
                        break;
                   default:
                        system("cls");
                        cout<<"invalid choice, try again"<<endl;
               }
            }
        }
        else
        {
            cout<<"incorrect credentials"<<endl;
            goto adminlogin;
        }
    }
};

class Student : public virtual Bus
{
private:
    string id, name, dept, usr, pass, dob, mn, bus, stop;
    int stopno=-1;

public:
void reg()
{
    int opt;
    cout << "Enter Your STUDENT ID    : ";
    cin >> id;
    ofstream file(id+".txt");
    file<<id<<endl;
    cout << "Enter Your Name          : ";
    cin >> name;
    cout << "Enter Your Dept.         : ";
    cin >> dept;
    cout << "Enter Your DOB           : ";
    cin >> dob;
    cout << "Enter Your Moblie Number : ";
    cin >> mn;
    pass = mn;
    file<<pass<<endl;
    file<<dob<<endl;
    string usr = id;
    file.close();
    system("cls");
    cout << "Hello , " << name << endl;
    cout << "Your Username is  " <<usr<< endl;
    option:
    cout << "            Registration Successful\n" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "------Welcome to SRM BUS MANAGEMENT SYSTEM------" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "             Press 1 to continue         " << endl;
    cout << "             Press 2 to reset password   " << endl;
    cout << "             Press 3 to exit             " << endl;
    cout << "------------------------------------------------" << endl;
    cout << "             Enter your choice: " << endl;
    cin >> opt;
    if(opt==1)
    {
        studentmenu();
    }
    else if(opt==2)
    {
        reset();
    }
    else if(opt==3)
    {
        return;
    }
    else
    {
        cout << "invalid option please try again";
        goto option;
    }
}
void login()
{
    string usrnm, passd;
    cout << "Enter Username : ";
    cin >> usrnm;
    // usr = usrnm;
    cout << "Enter Password : ";
    cin >> passd;
    ifstream file(usrnm+".txt");
     // ifstream reads a file
    if(file)
    {
     getline(file, id);            // reads the username
    getline(file, mn);
               // reads the password
        if ( id==usrnm && mn==passd)
        {
            int opt;
            cout << "              Login Successful\n" << endl;
            option:
            cout << "------------------------------------------------" << endl;
            cout << "------Welcome to SRM BUS MANAGEMENT SYSTEM------" << endl;
            cout << "------------------------------------------------" << endl;
            cout << "             Press 1 to continue         " << endl;
            cout << "             Press 2 to reset password             " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "             Enter your choice: " << endl;
            cin >> opt;
            if (opt == 1)
            {
                studentmenu();
            }
            else if(opt==2)
            {
                reset();
            }
            else
            {
            return;
            }
        }
        else
        {
            int opt;
            cout << "Login Failed" << endl;
            cout << " If Forgot Password Press 1 : "<<endl;
            cout<< "  If u want to try again....press 2: "<<endl;
            cin >> opt;
            if (opt == 1)
            {
                forgot();
            }else if(opt == 2)
            {
            login();
            }
        }
    }
    else
    {
        cout<<"not registered \npress 1 to register:";
        int ch;
        cin>>ch;
        if(ch==1)
        {
            reg();
        }
        else
        {

        }
    }
}
void forgot()
{
    string sname, sdob;
    cout << " Enter Username ";
    cin >> sname;
    cout << "Enter DOB : ";
    cin >> sdob;
    ifstream file(sname+".txt");
    getline(file, usr);
    getline(file, pass);
    getline(file, dob);
    if (usr == sname && dob == sdob)
    {
        getline(file, pass);
        cout << "Your Password is : " << pass << endl;
    }
    else
    {
        cout << "Invalid Input, Please try again " << endl;
    }
}
void reset()
{
    string ppass, a,uname;
    cout << " Enter Username ";
    cin >> uname;
    cout << "Enter Previous Password : ";
    cin >> ppass;
    ifstream file(uname+".txt");
    if(file)
    {
    getline(file, usr);
    getline(file, pass);
    if (ppass == pass && uname==usr)
    {
        cout << "Create new password : ";
        cin >> pass;
       ofstream write(usr + ".txt");
        write << usr << endl
              << pass << endl
              << dob;
     cout << "Password Changed Sucessfully" << endl;

    }
    }
    else
    {
        cout << "wrong password Try again" << endl;
        reset();
    }
}

void book()
{
showdetails();

cout<<"------------------BOOK BUS---------------------"<<endl;
cout<<"-----------------------------------------------"<<endl;

cout<<"Enter student ID       : "; cin>>id;
ofstream file(id+"-bus.txt");
file<<id<<endl;
cout<<"Enter student name     : "; cin>>name;
cout<<"Enter Bus Number       : "; cin>>busno;
cout<<"Enter Stop Number      : "; cin>>stopno;
file<<name<<endl;
bus=no[busno-1];
file<<bus<<endl;
stop=stops[busno-1][stopno-1];
file<<stop<<endl;
file.close();
}
void cancel()
{
cout<<"----------------CANCEL BUS---------------------"<<endl;
cout<<"-----------------------------------------------"<<endl;
string ch,str;
cout<<"enter your student id : ";
cin>>ch;
str=ch+"-bus.txt";
char* char_arr;
char_arr=&str[0];
remove(char_arr);
cout<<"cancelled successfully\n";
}
void status()
{
string txt;
cout<<"-----------REGISTRATION STATUS-----------------"<<endl;
ifstream file(id+"-bus.txt");
if (!file)
{
cout<<"NOT REGISTERED"<<endl;
}
else
{

while(getline(file,txt))
{
cout<<txt<<endl;
}
}
}
void studentmenu()
{
    system("cls");
    int ch;
    while(1)
    {

        cout<<"------------ Student Menu-------------"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"             1. Book Transport         "<<endl;
        cout<<"             2. Cancel Transport       "<<endl;
        cout<<"             3. Views Status           "<<endl;
        cout<<"             4. exit                   "<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"        enter your choice : ";cin>>ch;
        switch(ch)
        {
        case 1:
            system("cls");
            book();
            break;
        case 2:
            system("cls");
            cancel();
            break;
        case 3:
            system("cls");
            status();
            break;
        case 4:
            cout<<"EXITED"<<endl;
            return;
            break;
        default:
            system("cls");
            cout<<"invalid choice, try again"<<endl;
            studentmenu();
        }
    }
}
void mainmenu()
{
    system("cls");
    int ch;
    while(1)
    {
        cout<<"------------ Student Menu-------------"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"             1. Register              "<<endl;
        cout<<"             2. login                 "<<endl;
        cout<<"             3. exit                   "<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"        enter your choice : ";cin>>ch;
        switch(ch)
        {
        case 1:
            system("cls");
            reg();
            break;
        case 2:
            system("cls");
            login();
            break;
        case 3:
            cout<<"EXITED"<<endl;
            return;
            break;
        default:
            system("cls");
            cout<<"invalid choice, try again"<<endl;
            mainmenu();
        }
    }
}
};

class Portal:public Admin, public Student
{
public:
void start()
{
int ch;
while(1)
{
cout<<endl;
system("cls");

cout<<"----------------------MAIN MENU-----------------------"<<endl;
cout<<"------------------------------------------------------"<<endl;

cout<<"                1. login as admin                     "<<endl;
cout<<"                2. Login as Student                   "<<endl;
cout<<"                3. Exit                               "<<endl;
cout<<"------------------------------------------------------"<<endl;
cout<<"Enter your choice: "; cin>>ch;
switch(ch)
{
case 1:
system("cls");
adminmenu();
break;

case 2:
system("cls");
mainmenu();
break;

case 3:
cout<<"EXITED"<<endl;
return;
break;

default:
system("cls");
cout<<"Invalid Choice, Try Again!"<<endl;
}
}
}
};

int main()
{
Portal p;
p.start();
return 0;

}
