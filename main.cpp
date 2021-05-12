#include<iostream>
#include<conio.h>
#include<fstream>
#include<time.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "bank.h"
using namespace std;

int main()
{
    bank newcust,b;
    int i,A=1;
    char c;
    int numb,y;
    char nam[N],ph[N];
    cout<<"";

    do
    {

        char pas[5]="\0";
        system("cls");
        cout<<endl<<"\a\t\t\t\tBANK OF PEOPLE ";
        cout<<endl<<"\t\t\t\t____________________ "<<endl<<endl<<endl;
        cout<<"\t1 - Create New Account"<<endl;
        cout<<"\t2 - Login(User)"<<endl;
        cout<<"\t3 - View all Account Details"<<endl;
        cout<<"\t4 - Forgot Password"<<endl;
        cout<<"\t5 - Close an Existing Account"<<endl;
        cout<<"\t6 - Exit"<<endl<<endl<<endl;
        cout<<"\tChoose a number from 1 to 6 :";
        cin>>A;

        switch(A)
        {
            case 1:
                    system("cls");
                    cout<<"CREATE NEW ACCOUNT"<<endl;
                    newcust.newaccount(free());
                    i=0;
                    cout<<"\nConfirm-1 Cancel-2:";
                    cin>>i;
                    if(i==1)
                    create(newcust);
                    else
                    cout<<"\aAccount not created!!";
                    getch();
                    break;
            case 2:
                    system("cls");
                    cout<<"ACCOUNT LOGIN\n\n";
                    cout<<"Enter your account number:";
                    cin>>numb;
                    cout<<"Enter your password:      ";
                    c=' ';
                    i=0;
                    while(c!=13)
                        {
                            c=getch();
                            if(c!=13&&c!=8)
                                {
                                    pas[i]=c;
                                    cout<<"*";
                                    i++;
                                }
                            else if(c==8&&i>0)
                                {
                                    cout<<'\b';
                                    i=i-1;
                                }

                        }

                    pas[i]=0;
                    cout<<endl;
                    retcust(b,numb);

                    if( check(numb)&& strcmp(b.pass,pas)==0)
                        {
                        do
                        {
                            system("cls");
                            cout<<endl<<"\a\t\t\t\tWELCOME "<<strupr(b.name);
                            cout<<endl<<endl<<endl<<endl;
                            cout<<"\t1 - Withdraw Money"<<endl;
                            cout<<"\t2 - Deposit Money"<<endl;
                            cout<<"\t3 - Modify Account Details"<<endl;
                            cout<<"\t4 - Money Transfer"<<endl;
                            cout<<"\t5 - View Account Details"<<endl;
                            cout<<"\t6 - View PassBook"<<endl;
                            cout<<"\t7 - Exit"<<endl<<endl<<endl;
                            cout<<"\tEnter a number from 1 to 7 :";
                            cin>>A;

                            switch(A)
                            {
                                case 1:
                                    system("cls");
                                    if(b.type!=2)
                                    {
                                        time_t ti;
                                        time(&ti);
                                        b.days+=noday(ti,b.sec);
                                        b.sec=ti;
                                        writef(b,numb);
                                    }

                                    if(b.type!=3 ||b.type==3 && b.days>=b.fy)
                                    {
                                            interest(b);
                                            disp1(b);
                                            cout<<endl<<endl;
                                            if(b.type==3)
                                            {
                                                cout<<"1-Increase the number of years"<<endl;
                                                cout<<"2-Continue "<<endl;
                                                int co;
                                            do
                                                {
                                                    cout<<"Press 1 or 2				:";
                                                    cin>>co;
                                                }while(co!=1 && co!=2);

                                            if(co==1)
                                                {
                                                    cout<<"Enter the number of years		";
                                                    cin>>y;
                                                    b.fy=y;
                                                    writef(b,numb);
                                                }

                                            }

                                     else
                                            withdraw(b);

                                    }
                                    else
                                    cout<<"\aMoney cannot be withdrawn due to incompletion of years of fixed deposit."<<endl;
                                    getch();
                                        break;
                                case 2:
                                    system("cls");
                                    if(b.type==3)
                                        cout<<"\aMoney cannot be deposited in a fixed deposit account.";
                                    else
                                        {

                                            if(b.type!=2)
                                                    {
                                                        time_t ti;
                                                        time(&ti);
                                                        b.days+=noday(ti,b.sec);
                                                        b.sec=ti;
                                                        writef(b,numb);
                                                    }

                                            interest(b);
                                            disp1(b);
                                            cout<<endl<<endl;
                                            deposit(b);
                                        }
                                        getch();
                                        break;
                                case 3:
                                        system("cls");
                                        if(b.type!=2)
                                            {
                                                time_t ti;
                                                time(&ti);
                                                b.days+=noday(ti,b.sec);
                                                b.sec=ti;
                                                writef(b,numb);
                                            }

                                        interest(b);
                                        accset(b);
                                        break;
                                case 4:
                                    system("cls");
                                    if(b.type!=2)
                                        {
                                            time_t ti;
                                            time(&ti);
                                            b.days+=noday(ti,b.sec);
                                            b.sec=ti;
                                        }

                                    if(b.type!=3)
                                        {
                                            interest(b);
                                            disp1(b);
                                            cout<<endl<<endl;
                                            trans(b);
                                            cout<<endl;
                                            disp1(b);
                                        }

                                          else
                                            cout<<"\aMoney cannot be transfered from fixed deposit";
                                            getch();
                                        break;
                                case 5:
                                        system("cls");
                                        if(b.type!=2)
                                        {
                                            time_t ti;
                                            time(&ti);
                                            b.days+=noday(ti,b.sec);
                                            b.sec=ti;
                                            writef(b,numb);
                                        }

                                        interest(b);
                                        disp1(b);
                                        break;
                                case 6:
                                        system("cls");
                                        if(b.type!=2)
                                            {
                                                time_t ti;
                                                time(&ti);
                                                b.days+=noday(ti,b.sec);
                                                b.sec=ti;
                                            }
                                        interest(b);
                                        dispass(b);
                                        writef(b,numb);
                                        break;
                                case 7:
                                        system("cls");
                                        cout<<endl<<endl<<endl<<endl;
                                        cout<<"\t\t\a\aSUCCESSFUL LOGOUT..."<<endl<<endl;
                                        break;
                                default:
                                        cout<<"\aEnter a valid number";
                            }

                        }while(A!=7);
                        getch();
                                            }

                    else
                        cout<<"\aInvalid account!!";
                    break;
            case 3:
                    system("cls");
                    cout<<"Enter Bank Password:";
                    c=' ';
                    i=0;
                    while(c!=13)
                        {
                            c=getch();
                            if(c!=13&&c!=8)
                                {
                                    pas[i]=c;
                                    cout<<"*";
                                    i++;
                                }
                            else if(c==8&&i>0)
                                {
                                    cout<<'\b';
                                    i=i-1;
                                }
                        }
                    pas[i]=0;
                    if(strcmp(pas,"geu")==0)
                    dispall();
                    else
                    cout<<"\n\aWrong bank password"<<endl;
                    getch();
                    break;
            case 4:
                    system("cls");
                    cout<<"FORGOT PASSWORD\n\n";
                    cout<<"Enter your account number: ";
                    cin>>numb;
                    cin.get();
                    cout<<"Enter your name:           ";
                    cin.getline(nam,N);
                    cout<<"Enter your phone number :  ";
                    cin>>ph;
                    retcust( b,numb);
                    if(check(numb)&&!strcmp(b.name,nam)&&!strcmp(b.ph,ph))
                    cout<<"Your password is "<<b.pass;
                    else
                    cout<<"Invalid account!!\a";
                    cin.get();
                    break;
            case 5:
                    system("cls");
                    cout<<"DELETE ACCOUNT\n\n";
                    cout<<"Enter your account number:";
                    cin>>numb;
                    cout<<"Enter your password:      ";
                    c=' ';
                    i=0;
                    while(c!=13)
                        {
                            c=getch();
                            if(c!=13&&c!=8)
                                {
                                    pas[i]=c;
                                    cout<<"*";
                                    i++;
                                }
                            else if(c==8&&i>0)
                                {
                                    cout<<'\b';
                                    i=i-1;
                                }

                        }

                        pas[i]=0;
                        cout<<endl;
                        retcust(b,numb);

            if( check(numb)&& strcmp(b.pass,pas)==0&&b.type!=4)
                {
                    if(b.type!=2)
                        {
                                time_t ti;
                                time(&ti);
                                b.days+=noday(ti,b.sec);
                                b.sec=ti;
                                writef(b,numb);
                        }

                    interest(b);

                    if( b.type!=3||b.type==3&&b.days>=b.fy)
                        {
                                disp1(b);
                                cout<<endl<<endl;
                                cout<<"Do You surely want to delete your account Y/N";
                                cin>>c;
                                if(c=='y'||c=='Y')
                                    {
                                        cout<<"Balance money Rs "<<b.money<<" withdrawn";
                                        del(b);
                                    }
                                else
                                        cout<<"\aAccount not deleted!!!";

                         }

                    else
                            cout<<"\aAccount cannot be deleted due incompletion of finishing date!!!";
                }

                     else
                            cout<<"\aInvalid account!!";
                            getch();
                    break;
            case 6:
                    system("cls");
                    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
                    cout<<"\t\t\t\a\aPROJECT:-"<<endl<<endl;
                    cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM"<<endl;
                    cout<<endl<<endl;
                    cout<<"\t\t\t\a\aDONE BY:-"<<endl<<endl;
                    cout<<"\t\t\t\tSAHIL SANGWAN"<<endl;

                    break;
            default:
                    cout<<"\aEnter a valid number";
        }
        cin.get();
        cin.get();

    }while(A!=6);
    getch();
    return 0;
}

