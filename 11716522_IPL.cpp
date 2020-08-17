/*
=================COMPUTER SCIENCE MINI PROJECT=================
=====================IPL MANAGEMENT SYSTEM=====================
=====================Ansh Trehan- 11716522=====================
===============================================================
This program is prototype of a Indian Premier League (IPL)
management system
This program can maintain the information like
1. Display Team names
2. Tournament Schedule display
3. Tournament Matches result display
4. Add and delete a team.
5. Display Team players.
6. Tournament record display
7. Search for player
===============================================================
Colors changes on each task performed and a alert beep tells
about a invalid entry.
Schedule and result are randomly generated on runtime.
*/


#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
class team
{
public:
    void display()
    {
        string ch;
        string tname;
        cout<<"\tEnter team name : ";
        getline(cin,tname);
        string file = tname+".txt";
        ifstream in;
        in.open(file.c_str());
        in>>ch;
        int flag=0;
        if(in.eof() || !in)
        {
            cout<<"\tTeam does not exist"<<endl;
            flag=1;
        }
        in.seekg(ios::beg);
        if(flag==0)
        {
            cout<<"\tList of players of "<<tname<<" team"<<endl<<endl;
            while(getline(in, ch))
                cout<<"\t"<<ch<<endl;
        }
        cout<<endl;
        in.close();
        system("pause");
        system("cls");
    }
    void add()
    {
        string tname;
        fflush(stdin);
        cout<<"\tEnter team name : ";
        getline(cin,tname);
        ofstream out1("team.txt", ios::app);
        out1<<tname<<endl;
        string file = tname+".txt";
        ofstream out;
        out.open(file.c_str());
        cout<<"\tEnter team members details :"<<endl;
        string mem_name;
        for(int i=0; i<11; i++)
        {
            getline(cin, mem_name);
            out<<mem_name<<endl;
        }
        out.close();
        system("pause");
        system("cls");
    }
    void del()
    {
        string tname, line;
        fflush(stdin);
        cout<<"\tEnter team name : ";
        getline(cin, tname);
        ifstream fin;
        fin.open("team.txt");
        ofstream temp;
        temp.open("temp.txt");
        while (getline(fin, line))
        {
            if (line != tname)
                temp << line << endl;
        }
        temp.close();
        fin.close();
        remove("team.txt");
        rename("temp.txt", "team.txt");
        cout<<"\tTeam deleted successfully"<<endl;
        string file=tname+".txt";
        remove(file.c_str());
        system("pause");
        system("cls");
    }
    void srch()
    {
        string name, tm, fl;
        string tem;
        int flag=0;
        cout<<"\tEnter name of player to search : ";
        getline(cin, name);
        ifstream inp1;
        inp1.open("team.txt");
        while(getline(inp1, tm))
        {
            string pl, fl;
            fl=tm+".txt";
            ifstream inp2;
            inp2.open(fl.c_str());
            if(inp2.eof() || !inp2)
                cout<<"\tTeam does not exist"<<endl;
            inp2.seekg(ios::beg);
            while(getline(inp2, pl))
            {
                if(name == pl)
                {
                    tem=tm;
                    flag=1;
                    break;
                }
                else
                {
                    flag=0;
                    continue;
                }
            }
            if(flag==1)
                break;
            inp2.close();
        }
        inp1.close();
        if(flag==1)
            cout<<"\tPlayer found in "<<tem<<endl;
        else
            cout<<"\tPlayer not found"<<endl;
        system("pause");
        system("cls");
    }
};
class tour
{
public:
    void display()
    {
        string ch;
        string file = "team.txt";
        ifstream in;
        in.open(file.c_str());
        cout<<"\tList of teams : "<<endl<<endl;
        while(getline(in, ch))
        {
            cout<<"\t"<<ch<<endl;
        }
        cout<<endl;
        in.close();
        system("pause");
        system("cls");
    }
    void sch()
    {
        string ch;
        string file = "schedule.txt";
        ofstream in;
        in.open(file.c_str());
        ifstream out1, out2;
        out1.open("team.txt");
        string line1, line2;
        srand(time(NULL));
        int d;
        cout<<"\tSchedule of matches :"<<endl;
        while(getline(out1, line1))
        {
            out2.open("team.txt");
            while(getline(out2, line2))
            {
                if(line1 != line2)
                {
                    d=(rand()%57)+7;
                    if(d<=30)
                        in<<line2<<"\tv/s\t"<<line1<<"\ton\t"<<d<<"\tApril.\t\t"<<endl;
                    else
                    {
                        d=d-30;
                        in<<line2<<"\tv/s\t"<<line1<<"\ton\t"<<d<<"\tMay.\t\t"<<endl;
                    }

                }
            }
            out2.close();
        }
        in.close();
        out1.close();
        out2.close();
        ifstream in2;
        in2.open(file.c_str());
        while(getline(in2, ch))
        {
            cout<<"\t"<<ch<<endl;
        }
        cout<<endl;
        in2.close();
        system("pause");
        system("cls");
    }
    void res()
    {
        string ch;
        string file = "schedule.txt";
        ifstream in;
        string line;
        in.open(file.c_str());
        int i=1;
        while(getline(in, ch))
        {
            cout<<i<<". "<<ch<<endl;
            i++;
        }
        cout<<endl<<endl<<"\tEnter number corresponding to match to display it's result : ";
        int n;
        cin>>n;
        ofstream out("record.txt", ios::app);
        srand(time(NULL));
        int r1,r2;
        in.close();
        in.open(file.c_str());
        int j=1;
        while (getline(in, line))
        {
            if(j==n)
            {
                out<<line;
                r1=(rand()%300)+75;
                r2=(rand()%300)+75;
                if(r1 > r2)
                {
                    cout<<"\t1st team scored "<<r1<<" runs and 2nd team scored "<<r2<<" runs."<<endl;
                    cout<<"\t1st team won the match by "<<(r1-r2)<<" runs."<<endl<<endl;
                    out<<"1st team scored "<<r1<<" runs and 2nd team scored "<<r2<<" runs."<<endl;
                    out<<"1st team won the match by "<<(r1-r2)<<" runs."<<endl<<endl;
                    break;
                }
                else if(r1 < r2)
                {
                    cout<<"\t1st team scored "<<r1<<" runs and 2nd team scored "<<r2<<" runs."<<endl;
                    cout<<"\t2nd team won the match by "<<(r2-r1)<<" runs."<<endl<<endl;
                    out<<"1st team scored "<<r1<<" runs and 2nd team scored "<<r2<<" runs."<<endl;
                    out<<"2nd team won the match by "<<(r2-r1)<<" runs."<<endl<<endl;
                    break;
                }
                else if(r1==r2)
                {
                    cout<<"\tIt was a draw match. Both teams scored "<<r1<<" runs"<<endl<<endl;
                    out<<"It was a draw match. Both teams scored "<<r1<<" runs"<<endl<<endl;
                }
            }
            else
                j++;
        }
        out.close();
        in.close();
        system("pause");
        system("cls");
    }
    void rec()
    {
        string ch;
        string file = "record.txt";
        ifstream in;
        in.open(file.c_str());
        cout<<"\tRecords of past matches : "<<endl<<endl<<endl;
        while(getline(in, ch))
        {
            cout<<ch<<endl;
        }
        in.close();
        system("pause");
        system("cls");
    }
};
class app : public tour, public team
{
public:
    void a()
    {
        start:
            system("COLOR A0");
            cout<<"\t=================\t|===============\t|"<<endl;
            cout<<"\t\t|\t\t|\t\t|\t|"<<endl;
            cout<<"\t\t|\t\t|\t\t|\t|"<<endl;
            cout<<"\t\t|\t\t|\t\t|\t|"<<endl;
            cout<<"\t\t|\t\t|===============\t|"<<endl;
            cout<<"\t\t|\t\t|\t\t\t|"<<endl;
            cout<<"\t\t|\t\t|\t\t\t|"<<endl;
            cout<<"\t=================\t|\t\t\t============"<<endl;
            char opt;
            cout<<"Choose your option"<<endl;
            cout<<"\t1. Display team name"<<endl;
            cout<<"\t2. Tournament schedule display"<<endl;
            cout<<"\t3. Tournament matches result display"<<endl;
            cout<<"\t4. Add team"<<endl;
            cout<<"\t5. Delete team"<<endl;
            cout<<"\t6. Display team player"<<endl;
            cout<<"\t7. Tournament record display"<<endl;
            cout<<"\t8. Search Player"<<endl;
            cout<<"\t9. Show code"<<endl;
            cout<<"\tQ. Exit"<<endl;
            fflush(stdin);
            opt=getch();
            switch (opt)
            {
            case '1':
                system("COLOR B1");
                system("cls");
                tour::display();
                break;
            case '2':
                system("COLOR E2");
                system("cls");
                tour::sch();
                break;
            case '3':
                system("COLOR D1");
                system("cls");
                tour::res();
                break;
            case '4':
                system("COLOR B4");
                system("cls");
                team::add();
                break;
            case '5':
                system("COLOR F2");
                system("cls");
                team::del();
                break;
            case '6':
                system("COLOR C0");
                system("cls");
                team::display();
                break;
            case '7':
                system("COLOR D3");
                system("cls");
                tour::rec();
                break;
            case '8':
                system("COLOR C2");
                system("cls");
                team::srch();
                break;
            case '9':
                system("COLOR F0");
                system("cls");
                code();
                break;
            case 'Q':
                system("COLOR F0");
                system("cls");
                cout<<"\tThank you for using this system"<<endl<<endl<<endl<<endl;
                cout<<"\tDeveloped by- Ansh Trehan"<<endl<<"\tRegistration Number- 11716522"<<endl<<"\tSection- K17KQ"<<endl<<"\tRoll Number- B51"<<endl;
                cout<<"\tHave a good day"<<endl;
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                cout<<"\a";
                goto start;
            }
            if(opt!='Q')
                goto start;
    }
    void code()
    {
        ifstream in;
        string line;
        int flag=0;
        in.open("11716522_IPL.cpp");
        in.seekg(ios::beg);
        if(in.eof() || !in)
        {
            cout<<"\tFile does not exist"<<endl;
            flag=1;
        }
        in.seekg(ios::beg);
        if(flag==0)
        {
            while(getline(in, line))
                cout<<line<<endl;
        }
        system("pause");
        system("cls");
    }
};
void IPL()
{
    cout<<"\t=================\t|===============\t|"<<endl;
    cout<<"\t\t|\t\t|\t\t|\t|"<<endl;
	cout<<"\t\t|\t\t|\t\t|\t|"<<endl;
	cout<<"\t\t|\t\t|\t\t|\t|"<<endl;
	cout<<"\t\t|\t\t|===============\t|"<<endl;
	cout<<"\t\t|\t\t|\t\t\t|"<<endl;
	cout<<"\t\t|\t\t|\t\t\t|"<<endl;
	cout<<"\t=================\t|\t\t\t============"<<endl;
}
int main()
{
    system("COLOR F0");
    IPL();
    cout<<endl<<endl<<endl<<"\tPlease wait while IPL Management System Loads"<<endl<<endl;
    char a[14]={'w','e','l','c','o','m','e','\0','t','o','\0','i','p','l'};
    char b[14]={'W','E','L','C','O','M','E','\0','T','O','\0','I','P','L'};
    cout<<"\t";
    for (int i=0;i<14;i++)
        cout<<a[i];
    for (int j=0;j<=1e8;j++);
    cout<<"\r";
    cout<<"\t";
    for (int i=0;i<14;i++)
    {
        cout<<b[i];
        for (int j=0;j<=1e8;j++);
    }
    system("cls");
    char pass[10], password[10]="LPU@123";
    IPL();
    cout<<endl<<endl<<endl<<"\tPlease enter password to use this application : ";
	int x=0;
	while(x<7)
	{
		pass[x]=getch();
		printf("#");
		x++;
	}
	pass[7]='\0';
	printf("\n");
	fflush(stdin);
	if(strcmp(password,pass)==0)
	{
	    system("cls");
        app obj;
        obj.a();
        return 0;
	}
	else
	{
	    system("COLOR C3");
		cout<<"\tUnauthorized Access!\a"<<endl;
		system("pause");
		system("cls");
		main();
	}
}