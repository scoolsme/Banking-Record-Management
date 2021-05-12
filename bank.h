#include<fstream>
#include<iomanip>
using namespace std;

time_t t = time(0);
struct tm * now = localtime(& t);
const int N=50;

class passbook
{
    public:
        int dat,mont,yea;
        char part[N];
        int acn;
        double wmon,dmon,tot;
};

class bank
{
    public:

      char name[N];
      int number,type,ag,top,fy;
      char pass[5];
      double days;
      long double money ,inte;
      passbook entry[N];
      time_t sec;
      char ph[15],address[N];
      void newaccount(int f)                                             // CREATE A NEW ACCOUNT
        {
            cin.get();
            cout<<"\nAccount number:\t\t "<<f+1000<<endl;
            cout<<"\nEnter the account name:  ";
            cin.getline(name,100);
            number=f+1000;
            cout<<"\nEnter password:		 ";
            char c=' ';
            int i=0;

       while(c!=13)
            {
                c=getch();
                if(c!=13&&c!=8)
                    {
                        pass[i]=c;
                        cout<<"*";
                        i++;
                    }

                else if(c==8&&i>0)
                    {
                        cout<<'\b';
                        i=i-1;
                    }
            }

       pass[i]='\0';
       cout<<endl<<endl;
    	   do
                {
                    cout<<"\nEnter the type  \n1-Savings account \n2-Current account \n3-Fixed deposit: 	";
                    cin>>type;
                }while(type!=1 && type!=2 && type!=3);

    	   if(type==1 || type==3)
                {

                do
                    {
                        cout<<"\nEnter your age type\n 1-Adult\n 2-Senior citizen: 	";
                        cin>>ag;

                    }while(ag!=1 && ag!=2);

    		  if(ag==1)
              inte=0.75;
              else
              inte=1.00;

    	       }

		   //INTEREST FOR ADULTS 9 % PER ANNUM
                  //INTEREST FOR SENIOR CITIZENS 12 % PER ANNUM

    	   else
            ag=0;
           if (type==3)
            {
                cout<<"\nEnter the number of years:	";
                cin>>fy;
                fy=fy*365;
            }

    	   do
                {
                    cout<<"\nEnter money deposited:   ";
                    cin>>money;
                }while(money<0);


        cin.get();
        cout<<"\nEnter your phone number: ";
        cin.getline(ph,15);
        cout<<"\nEnter your Address:    ";
        cin.getline(address,50);
        days=0;
        top=0;
        time(&sec);
    }

};

int check(int no)                                  // CHECK IF THE THE GIVEN ACCOUNT EXISTS
{
    bank b;
    ifstream fin("bankmanage.dat",ios::binary);
    if(fin)
    {
        fin.read((char*)&b,sizeof(b));
        while(!fin.eof())
            {
                if(b.number==no)
                {
                    fin.close();
                    return 1;
                }
                else
                    fin.read((char*)&b,sizeof(b));
            }
    }

     fin.close();
    return 0;
}

void writef(bank &b,int &acc)                        // WRITE THE OBJECT INTO THE BINARY FILE
{
    ifstream fin("bankmanage.dat",ios::binary);
    bank ban;
    ofstream fout("temp.dat",ios::binary);
    if(fin)
    {
            fin.read((char*)&ban,sizeof(ban));
            while(!fin.eof())
                {
                        if(ban.number!=acc)
                        fout.write((char*)&ban,sizeof(ban));
                        else
                        fout.write((char*)&b,sizeof(b));
                        fin.read((char*)&ban,sizeof(ban));
                }
    }

            else
            fout.write((char*)&b,sizeof(b));
            fin.close();
            fout.close();
            remove("bankmanage.dat");
            rename("temp.dat","bankmanage.dat");
}

void retcust(bank &b,int acc)                         //RETREIVE AND RETURN CUSTOMER'S DETAILS 
{
    bank x;
    int found=0;
    ifstream fin("bankmanage.dat",ios::binary);
    if(fin)
    {
        fin.read((char *)&x,sizeof(x));
        while(!fin.eof()&&found==0)
            {
                if(x.number==acc)
                    {
                        b=x;
                        found=1;
                    }
                else
                fin.read((char*)&x,sizeof(x));
            }
            fin.close();
    }

}

void disp1(bank & b)                                     //DIPLAY THE ACCOUNT DETAILS OF THE CUSTOMER
{
    cout<<"\nYOUR ACCOUNT DETAILS\n\n";
    cout<<"Account name:   "<<b.name<<endl;
    cout<<"Account number: "<<b.number<<endl ;
    if(b.type==1)
    cout<<"Type:		Savings"<<endl;
    else if(b.type==2)
    cout<<"Type:		Current"<<endl;
    else if(b.type==3)
    cout<<"Type:		Fixed deposit"<<endl;
    if(b.ag==1)
    cout<<"Age Type:	Adult"<<endl;
    else if(b.ag==2)
    cout<<"Age Type:	Senior citizen"<<endl;
    else
    cout<<"Age Type:	NILL"<<endl;

      cout<<"Phone number:	"<<b.ph<<endl;
      cout<<"Address:        "<<b.address<<endl;
      if( b.type==3)
      cout<<"Remaining days:	"<<b.fy-b.days<<endl;
    else
            cout<<"Balance money:   "<<b.money;
    getch();

}

void dispall()                                                // DISPLAY THE DETAILS OF ALL THE CUSTOMERS
{

     cout<<"\n*******************************************************************************"<<endl;
     cout<<left<<setw(20)<<"A/C NAME"<<setw(10)<<"A/C NO"<<setw(15)<<"TYPE"<<setw(20)<<"AGE TYPE"<<setw(10)<<"BALANCE"<<endl;
     cout<<"*******************************************************************************"<<endl;
     ifstream fin("bankmanage.dat",ios::binary);
     bank ba;
     if(fin)
        {
            fin.read((char*)&ba,sizeof(ba));
            while(!fin.eof())
                {
                    cout<<left<<setw(20)<<ba.name<<setw(10)<<ba.number;
                    if(ba.type==1)
                    cout<<setw(15)<<"Savings";
                    else if(ba.type==2)
                    cout<<setw(15)<<"Current";
                    else if(ba.type==3)
                    cout<<setw(15)<<"Fixed deposit";

                    if( ba.ag==1)
                    cout<<setw(20)<<"Adult";
                    else if( ba.ag==2)
                    cout<<setw(20)<<"Senior citizen";
                    else
                    cout<<setw(20)<<"Nill";
                    cout<<setw(10)<<ba.money<<endl;
                    fin.read((char*)&ba,sizeof(ba));
            }

            cout<<endl<<endl<<endl;
            fin.close();
            }
        }

void passen(bank & b,char pa[],int ac,double with,double dep,double tot)          // ADD DETAILS TO THE PASSBOOK
{
    int &x=b.top;
    b.entry[x].dat = now->tm_mday;
    b.entry[x].mont= now->tm_mon+1;
    b.entry[x].yea = now->tm_year+1900;
    strcpy(b.entry[x].part,pa);
    b.entry[x].acn = ac;
    b.entry[x].wmon= with;
    b.entry[x].dmon= dep;
    b.entry[x].tot = tot;
    x++;
    writef(b,b.number);
}

void create(bank & b)                                                               //CREATE AN ACCOUNT
{
    ofstream fout("bankmanage.dat",ios::app|ios::binary);
    fout.write((char*)&b,sizeof(b));
    cout<<"Account created!!!"<<endl;
    fout.close();
    passen(b,"A/C CREATED",0,0,b.money,b.money);
}

void del(bank & b)                                                                 //DELETE AN ACCOUNT
{
        bank ba;
        ifstream fin("bankmanage.dat",ios::binary);
        ofstream fout("temp.dat",ios::binary);
        fin.read((char*)&ba,sizeof(ba));
            while(!fin.eof())
                {
                    if( ba.number!=b.number)
                    fout.write((char*)&ba,sizeof(ba));
                    else
                    cout<<"\nAccount Deleted!!";
                fin.read((char*)&ba,sizeof(ba));
                }

    fout.close();
    fin.close();
    remove("bankmanage.dat");
    rename("temp.dat","bankmanage.dat");
}

void withdraw(bank &b)                                                         //WITHDRAW MONEY FROM AN ACCOUNT
{
    double amm;
        if(b.type==3)
            {
                b.money=0;
                cout<<"Balance money Rs "<<b.money<<" withdrawn"<<endl;
                cout<<"Fixed  deposit account closed";
                del(b);
            }
        else
            {
                cout<<"Enter amount to be withdrawn:";
                cin>>amm;
            if( b.money>=amm && amm>0)
                {
                    b.money-=amm;
                    writef(b,b.number);
                    cout<<"Money withdrawn!!! Your account balance is "<<b.money<<endl;
                    passen(b,"WITHDRAWN",0,amm,0,b.money);
                }
            else
                cout<<"\aMoney Not Withdrawn!!!"<<endl;
            }
    getch();
}

void deposit(bank & b)                                               //DEPOSIT MONEY INTO AN ACCOUNT
{
    double amm;
    if(b.type!=4)
    {
        cout<<"Enter amount to be deposited:";
        cin>>amm;
        if(amm>0)
            {
                b.money+=amm;
                writef(b,b.number);
                cout<<"Money deposited!!! \nYour account balance is "<<b.money<<endl;
                passen(b,"DEPOSITED",0,0,amm,b.money);
            }
        else
                cout<<"\aMoney not Deposited!!"<<endl;
    }
    getch();

}

void accset(bank & b)                                       //MODIFY THE DETAILS OF AN EXISTING CUSTOMER
{
    int z;
    disp1(b);
    cout<<endl<<endl;
    cout<<"1 - Account Name"<<endl;
    cout<<"2 - Password"<<endl;
    cout<<"3 - Type"<<endl;
    cout<<"4 - Age type"<<endl;
    cout<<"5 - Phone number"<<endl;
    cout<<"6 - Address"<<endl;
    cout<<"Enter detail to be changed"<<endl;
    cout<<"Enter 7 to go back"<<endl;
    cin>>z;
    cin.get();

	    if(z==1)
        {
            cout<<"Enter your new account name :";
            cin.getline(b.name,N);
            cout<<"Account name changed!!"<<endl;
        }

	    else if(z==2)
        {
            cout<<"Enter your new account Password :";
            char c=' ';
            int i=0;
            while(c!=13)
        {
            c=getch();
            if(c!=13&&c!=8)
                {
                    b.pass[i]=c;
                    cout<<"*";
                    i++;
                }

            else if(c==8&&i>0)
                {
                    cout<<'\b';
                    i--;
                }
        }

            b.pass[i]=0;
            cout<<endl;
            cout<<"Account password changed!!"<<endl;

	    }

	    else if(z==3&&b.type!=4)
        {
            do
                {
                    cout<<"Enter your new account Type 1-Savings 2-Current 3-Fixed deposit :";
                    cin>>b.type;

                }while(b.type==1&&b.type==2&&b.type!=3);

	      if(b.type==3)
            {
                cout<<"Enter the number of years";
                cin>>b.fy;
            }

		      cout<<"Account Type changed!!"<<endl;

	    }

	    else if(z==4)
        {

		    if(b.ag!=0)
                {

                    do
                    {

                        cout<<"Enter your age type 1-Adult 2-Senior citizen :";
                        cin>>b.ag;
                    }while(b.ag!=1 && b.ag!=2);

                    if(b.ag==1)
                    {
                        if(b.type==4)
                        b.inte=1;
                        else
                        b.inte=0.75;
                    }
                    else
                    {
                        if(b.type==4)
                        b.inte=0.75;
                        else
                        b.inte=1;
                    }

		    cout<<"Account age type changed!!"<<endl;
            cin.get();

	     }

         else
        cout<<"\aAccount age type cannot be changed";

     }

	 else if( z==5)
    {
        cout<<"Enter your Phone Number :";
        cin.getline(b.ph,15);
        cout<<"Phone Number changed!!!\n";
    }

	 else if( z==6)
        {

            cout<<"Enter your Address :";
            cin.getline(b.address,50);
            cout<<"Account address changed!!!\n";
        }

    else if(z!=7)
            cout<<"Invalid Number\a";

    if(b.type==4&&z==3)
            cout<<"\aType cannot be changed";

    writef(b,b.number);
    getch();
}

void interest(bank & b)                          //CALCULATE THE INTEREST AMOUNT
{
    if(b.type!=3)
        {
            double &d=b.days;
            double mon;
            double inter;

            if(d>=30)
            {
                mon=d/30;
                d=int(d)%30;
                inter=mon*(b.inte)*b.money/100;
                b.money+=inter;
                writef(b,b.number);
                passen(b,"INTEREST",0,0,inter,b.money);
            }
        }
}

void dispass(bank & b)                           //VIEW THE PASSBOOK ENTRIES
{
    interest(b);
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"DATE         PARTICULARS     AC/NO       WITHDRAW       DEPOSIT     BALANCE    "<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<b.top;i++)
    {
        if(b.entry[i].dat<10)
        cout<<"0";
        cout<<b.entry[i].dat<<"/";
        if(b.entry[i].mont<10)
        cout<<"0";
        cout<<b.entry[i].mont<<"/"<<b.entry[i].yea<<"   ";
        if( strcmp(b.entry[i].part,"A/C CREATED")==0)
        cout<<b.entry[i].part<<"      ";
        else
        cout<<b.entry[i].part<<"\t      ";
        if( b.entry[i].acn!=0)
        cout<<b.entry[i].acn<<"\t ";
        else
        cout<<"NILL\t ";
        if( b.entry[i].wmon!=0)
        cout<<b.entry[i].wmon<<"\t\t";
        else
        cout<<"NILL\t\t";
        if( b.entry[i].dmon!=0)
        cout<<b.entry[i].dmon<<"\t    ";
        else
        cout<<"NILL\t    ";
        cout<<b.entry[i].tot<<endl;
    }
    getch();
}

void trans(bank & b)                                                             //TRANSFER MONEY
{
    int am,c,amt;
        cout<<"Enter the account number where money is to be transfered: ";
        cin>>am;
        bank to;
        retcust(to,am);
        int nu=check(am);
        if(am!=b.number)
            {
                if(nu)
                {
                    do
                        {
                            cout<<"Enter money to be transfored: ";
                            cin>>amt;
                        }while(amt<=0);

                   if(b.money>=amt)
                        {
                            cout<<"Confirm-1 Cancel-2. Enter 1 or 2: ";
                            cin>>c;
                    if(c==1)
                        {
                            b.money-=amt;
                            to.money+=amt;
                            cout<<"MONEY TRANSFERED!!!"<<endl;
                            writef(b,b.number);
                            passen(b,"TRANSFERED",am,amt,0,b.money);
                            writef(to,am);
                            passen(to,"TRANSFERED",am,0,amt,to.money);
                        }

                        }

                   else
                            cout<<"\aNot Enough Balance"<<endl;

                }

             else
                            cout<<"\aInvalid account number"<<endl;

         }
        else
            cout<<"\aMoney cannot be transfered to your own account";
        getch();
}

int free()                                         // TO GET AN ACCOUNT NUMBER
{
    ifstream fin("bankmanage.dat",ios::binary);
    bank b;
    int i;
    if(fin)
        {
            fin.read((char*)&b,sizeof(b));
            if(!fin.eof());
            i=0;

	    while(!fin.eof())
            {
                i=b.number;
                fin.read((char*)&b,sizeof(b));
            }

        fin.close();
        if(i!=0)
        return i-999;
        else
        return 0;
        }

     else
     return 0;
}

int noday(time_t t1,time_t t2)                 //CALCULATE THE PERIOD
{
    int dar;
    dar=(t1-t2)/(3600*24);
    return dar;
}
