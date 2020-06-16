#include<ctype.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
class crim_rec
{
	private:
	char name[100],sex,dob[10],addr[50],bg[5],crime[15];
	int bail_amount,crim_code;
	int size;
	void getco()
	{
		cout<<"\nEnter the criminal code";
		cin>>crim_code;
		checkcode(crim_code);
	}
	public:

	void getd();
	void display();
	void modify();
	int rets(){return size;}
	void csp(){size++;}
	void csn(){size--;}
	void checkcode(int i);
	char *retn(){return name;}
	int retc(){return crim_code;}

}cd;

void crim_rec :: checkcode(int i)
{
	crim_rec l;
	ifstream g;
	int flag=0;
	g.open("CBID.dat",ios::in|ios::binary);
	g.seekg(0,ios::beg);
	while(g.read((char*)&l,sizeof(l)))
	{

		if(i==l.retc())
			{
				flag=1;
				break;
			}
	}
		if(flag==1)
		{
			cout<<"\nThis criminal code already exists! Please enter a new one.";
			cd.getco();

		}


}
	void crim_rec :: getd()
	{
		puts("\nEnter the name:");
		gets(name);
		getco();
		puts("\nsex (M/F/O):");
		cin>>sex;
		puts("\nEnter the date of birth:");
		gets(dob);
		puts("Enter blood group (A+/A-/B+/B-/AB+/AB-/O+/O-:");
		cin>>(bg);
		puts("enter address:");
		gets(addr);
		puts("\nEnter crime commited:");
		gets(crime);
		puts("\nEnter the set bail amount of the criminal:");
		cin>>bail_amount;

	}
	void crim_rec :: display()
	{
		cout<<"The record of criminal:\n";
		cout<<"\nName of criminal: ";puts(name);
		cout<<"Criminal code:"<<crim_code;
		cout<<"\nSex: "<<sex;
		cout<<"\nDOB: "<<dob;
		cout<<"\nBlood Group: "<<bg;
		cout<<"\nAddress: ";puts(addr);
		cout<<"\Crime: ";puts(crime);
		cout<<"Set bail amount: "<<bail_amount;
	}
	void crim_rec ::  modify()
	{
	      clrscr();
	      int p[15];
	      char choice='n';
	      cout<<"\n\t\t\tMODIFY MENU";
	      cout<<"\n\t\t\t____________";
		     cout<<"\n1.Name";
		     cout<<"\n2.Sex";
		     cout<<"\n3.DOB";
		     cout<<"\n4.Blood group";
		     cout<<"\n5.Criminal code";
		     cout<<"\n6.Address";
		     cout<<"\n7.Crime";
		     cout<<"\n8.Bail amount";
		     cout<<"\nDo you want to modify more than one field? (y/n)";
		     cin>>choice;
		     if(choice=='y'||choice=='Y')
		     {
				int c;
			 cout<<"\nHow many fields do you want to change?";
			 cin>>c;

			 for(int i=0;i<c;i++)
			 {
				clrscr();
				cout<<"\n\t\t\tMODIFY MENU:";
				cout<<"\n\t\t\t___________:";
				cout<<"\n1.Name";
				cout<<"\n2.Sex";
				cout<<"\n3.DOB";
				cout<<"\n4.Blood group";
				cout<<"\n5.Criminal code";
				cout<<"\n6.Address";
				cout<<"\n7.Crime";
				cout<<"\n8.Bail amount";
				cout<<"\nEnter choice "<<i+1;
				cin>>p[i];
				if(p[i]>8||p[i]<0)
				{      while(p[i]>8||p[i]<0)
					{cout<<"\nPlease enter a valid choice!";

					cin>>p[i];}
				}


				 switch(p[i])
			    {
			    case 1:     cout<<"\n\nEnter the new name:";
					gets(name);
					break;
			    case 2:     cout<<"\n\nEnter the new sex:";
					cin>>sex;
					break;
			    case 3:     cout<<"\n\nEnter the new date of birth:";
					gets(dob);
					break;
			   case 4:      cout<<"\n\nEnter the new blood group:";
					gets(bg);
					break;
			  case 5:      getco();

					break;
			  case 6:     cout<<"\n\nPlease enter the new address:";
					gets(addr);
					break;
			  case 7:     cout<<"\n\nPlease enter the new crime:";
					gets(crime);
					break;
			   case 8:     cout<<"\n\nPlease enter the new bail amount:";
					cin>>bail_amount;
					break;
			 default:break;
	    }
	}
}
		     else
		     {
			cout<<"Enter your choice(1-8)";
			cin>>p[0];

		     cout<<"Enter the details:";
		    switch(p[0])
		    {
		    case 1:     cout<<"\n\nEnter the new name:";
				gets(name);
				break;
		    case 2:     cout<<"\n\nEnter the new sex:";
				cin>>sex;
				break;
		    case 3:     cout<<"\n\nEnter the new date of birth:";
				gets(dob);
				break;
		   case 4:      cout<<"\n\nEnter the new blood group:";
				gets(bg);
				break;
		   case 5:      getco();
				break;
		    case 6:     cout<<"\n\nPlease enter the new address:";
				gets(addr);
				break;
		    case 7:     cout<<"\n\nPlease enter the new crime:";
				gets(crime);
				break;
		    case 8:     cout<<"\n\nPlease enter the new bail amount:";
				cin>>bail_amount;
				break;
		    default:  cout<<"\nPlease enter a valid choice!";
			      break;
	    }
	}
}
void help()
{
	clrscr();
	cout<<"\t\t\tGUIDELINES:";
	cout<<"\t\t\t___________";
cout<<"\n1. To use a specific function from the menu, type in the keyword written in the brackets.";
cout<<"\n2. Prisoner can only be bailed if criminal code and amount entered are correct.";
cout<<"\n3. The master password is required for deletion and modification.";
cout<<"\n\n_____________________________________________________________________________";
}
int read(crim_rec &f,char str[])
{
	char c='n';
	ifstream i;
	i.open("CBID.dat",ios::in|ios::binary);
	i.seekg(0,ios::beg);
		while(i.read((char*)&f,sizeof(f)))
		{
			if(strcmpi(f.retn(),str)==0)
			{
				cout<<endl<<endl;
				f.display();
				cout<<"\nIs this the record you want? (y/n)";
				cin>>c;
				if(c=='y'){break;}
			}
		}
		i.close();
		if(c=='n'){cout<<"\nNO SUCH RECORD FOUND";return -1;}
		else return 1;
}

int read(crim_rec &f,int c)
{
	ifstream i;
	char k='n';
	i.open("CBID.dat",ios::in|ios::binary);
	i.seekg(0,ios::beg);
	while(i.read((char*)&f,sizeof(f)))
		{
			if(f.retc()==c)
			{

				k='y';
				break  ;
			}
		}
		i.close();
		if(k=='n'){cout<<"\nNO SUCH RECORD FOUND";return -1;}
		else return 1;
}

void write(crim_rec f)
{
	ofstream o;
	o.open("temp.dat",ios::out|ios::binary|ios::app);
	o.write((char*)&f,sizeof(f));
	o.close();
}
void del(crim_rec f)
{
	ifstream d;
	crim_rec j;
	d.open("CBID.dat",ios::in|ios::binary);
	while(d.read((char*)&j,sizeof(j)))
		{
			if(f.retc()==j.retc())
			{
			char fl='n';
			clrscr();
		       cout<<"\nThe required details:\n";
			j.display();
			cout<<"\nAre you sure that you want to delete this record? (y/n)";
			cin>>fl;
			if(fl=='y'||fl=='Y')cd.csn();
			else write(j);
			}
			else write(j);
		}
		remove("CBID.dat");
		rename("temp.dat","CBID.dat");
}
void mod(crim_rec f)
{
	ifstream d;
	crim_rec j;
	d.open("CBID.dat",ios::in|ios::binary);
	while(d.read((char*)&j,sizeof(j)))
		{
			if(f.retc()==j.retc())
			{
			char fl='n';
			clrscr();
		       cout<<"\nThe required details:\n";
			j.display();
			cout<<"\nAre you sure that you want to modify this record? (y/n)";
			cin>>fl;
			if(fl=='y'||fl=='Y'){j.modify();write(j);}
			else write(j);
			}
			else write(j);
		}
		remove("CBID.dat");
		rename("temp.dat","CBID.dat");
}
class login
{
	char username[100],password[100];
	public:
	login()
	{

		strcpy(username,"");
		strcpy(password,"");
	}
	void cld();
	int checkp();
	void changeId();
	int checkifp();

}p;
int login :: checkifp()
	{
		int r=-1;
		ifstream n;
		n.open("password.txt",ios::in);
		n.seekg(0,ios::beg);
		char u[100],p[100]="";
		n>>u>>p;
		if(strcmp(p,"")==0)r=-1;
		else r=1;

		return r;
	}

int login :: checkp()
{
	int i;
	char u[100]="",p[100]="";

	cout<<"Enter your current login details:";
	cout<<"\nUsername: ";gets(u);
	cout<<"Password: ";gets(p);

	ifstream pp;
	pp.open("password.txt",ios::in);
	pp.seekg(0,ios::beg);
	pp>>username>>password;
	if(strcmp(username,u)==0 && strcmp(password,p)==0)
	{
		i=1;
	}
	else i=-1;
	return i;
}


void login :: changeId()
{
	clrscr();
	int f=0;
	f=checkp();
	if(f==1)cld();
	else cout<<"You have entered incorrect login details!";
}

void  login :: cld()
{
	clrscr();
	cout<<"Enter the login username that is to be used:";
	gets(username);
	cout<<"Please create the password!";
	cout<<"\nThis password shall give you access to modification,deletion and bail functions!";
	cout<<"\nThe password should contain atleast one number, uppercase and lowercase \ncharacter.";
	cout<<"\nThe password shouldn't contain a space or a backspace.";
	cout<<"\nEnter the password:";
	gets(password);
	int s=strlen(password);
	int count1=0,count2=0,count3=0,count4=0;
	for(int i=0;i<s;i++)
	{
		if(isupper(password[i]))count1++;
		if(islower(password[i]))count2++;
		if(password[i]==' ')count4++;
		if(password[i]>='0'&&password[i]<='9')count3++;
	}

	if(count1==0 || count2==0 || count3==0 || count4!=0)
	{
		if(count1==0)cout<<"No uppercase character!";
		if(count2==0)cout<<"\nNo lowercase character!";
		if(count3==0)cout<<"\nNo number!";
		if(count4!=0)cout<<"\nThere should be no spaces!";

		char u='n';
		cout<<"\nDo you want to enter the login details again? (y/n)";
		cin>>u;
		if(u=='y'||u=='Y')
		{       cout<<"\nPress enter to continue.";
			cin.ignore();
			cld();
		}
		else exit(1);
	}
else
{
	char f[10];
	int flag100=-1;
	int x;
	randomize();
	x=random(3)+1;
	cout<<"\nPlease enter the following pattern";
	cout<<endl;
	switch (x)
	{
	case 1:

	cout<<"\n*     *     *     * * * * * * * * *     *";
	cout<<"\n*     *    * *    *     * *     *  *   * ";
	cout<<"\n* * * *   * * *   * * * * * * * *    *   ";
	cout<<"\n*     *  *     *  *       *          *   ";
	cout<<"\n*     * *       * *       *          *   ";
	cin>>f;
	if(strcmpi(f,"Happy")==0)flag100=1;
	break;
	case 2:

	cout<<"\n* * * *      *      * * * *  * * * *  ";
	cout<<"\n*     *     * *     *        *    ";
	cout<<"\n* * * *    * * *    * * * *  * * * *       ";
	cout<<"\n*     *   *     *         *  *             ";
	cout<<"\n* * * *  *       *  * * * *  * * * *	    ";
	cin>>f;
	if(strcmpi(f,"Base")==0)flag100=1;
	break;
	case 3:

	cout<<"\n* * * *   * * * *  * * * *  * * * *	 ";
	cout<<"\n*     *   *        *        *     *	 ";
	cout<<"\n*     *   * * * *  * * * *  * * * *	   ";
	cout<<"\n*     *   *        *        *   	    ";
	cout<<"\n* * * *   * * * *  * * * *  *	   	 ";
	cin>>f;
	if(strcmpi(f,"Deep")==0)flag100=1;
	break;

	}

	if(flag100==1)
	{
		cout<<"\nPassword created successfully!\nYour login details are:";
		cout<<"\nUsername: ";puts(username);
		cout<<"Password:";puts(password);
		strcpy(password,password);
		ofstream pp;
		pp.open("password.txt",ios::out);
		pp<<username<<" "<<password;
		cout<<"Press enter to continue.";

		cin.ignore();

	}
	else
	{
		char u='n';
		cout<<"\nWrong word entered! Do you want to enter the login details again? (y/n)";
		cin>>u;
		if(u=='y'||u=='Y')
		{       cout<<"\nPress enter to continue.";
			cin.ignore();
			cld();
		}
		else exit(1);

	}

	}
}

void exitp()
{
	char g;
	cout<<"Are you sure you want to exit?(y/n)";
	cin>>g;
	if(g=='y')
	exit(0);
}

void main()
{
clrscr();
ifstream n;
if(p.checkifp()==-1)
{cout<<"You haven't created your login. Press enter to go to the login creation menu.\n";
cin.ignore();
p.cld();
}

clrscr();
crim_rec j;
char t;
int flag;
int te;
char c='n';
int ce;
do
{
clrscr();
cout<<"\t\t\tCBI JAIL CRIMINAL DATABASE";
cout<<"\n\t\t\t_________________________";
cout<<"\n\n\t\t\t\tGUIDELINES:\n";
cout<<"\n1. To use a specific function from the menu, type in the number written \n   alongside.";
cout<<"\n2. Deletion and modification can only be done if login details entered are \n   correct.";
cout<<"\n3. Change login details by typing '6' in the menu.";
cout<<"\n______________________________________________________________________________";
cout<<"\n\n\t\t\t\tMENU:";
cout<<"\n\t1.ADD A CRIMINAL RECORD";
cout<<"\n\t2.DELETE A CRIMINAL RECORD";
cout<<"\n\t3.MODIFY A CRIMINAL RECORD";
cout<<"\n\t4.DISPLAY A CRIMINAL RECORD";
cout<<"\n\t5.HELP";
cout<<"\n\t6.CHANGE LOGIN DETAILS";
cout<<"\n\t7.EXIT";

	cout<<"\nWhat do you want to do(from the above menu)?";
	int choice;
	cin>>choice;
	switch(choice)
	{
			case 1: clrscr();
				cd.getd();
				cout<<"\n\nThe entered details are:";
				cd.display();
				ofstream h;
				h.open("CBID.dat",ios::out|ios::binary|ios::app);
				h.write((char*)&cd,sizeof(cd));
				h.close();
				cd.csp();
				break;

			case 2:
						int flag;
						char t[100];
						int te;

						char c='n';
						int ce;
						int tt=0;
						tt=p.checkp();
						if(tt==1){
						cout<<"\n\nYou are being directed to the SEARCH MENU. Please press enter to continue.";
						cin.ignore();
						cin.ignore();
						do{
						clrscr();
						cout<<"\t\t\tSEARCH MENU";
						cout<<"\n\t\t\t__________";
						cout<<"\n1. On the basis of the name";
						cout<<"\n2. On the basis of the criminal code";
						cout<<"\n3. Back to the main menu.";
						cout<<"\nEnter your choice(1-3)";
						cin>>ce;
						switch(ce)
						{
							case 1:cout<<"\nEnter the name:";
							       gets(t);
							       flag=read(j,t);
							       if(flag==1)
							       {
								del(j);
							       }
							       else cout<<"\nPlease enter a valid name.";
								cout<<"\nDo you want to go back to the search menu to delete records? (y/n)";
								cin>>c;
							       break;
							case 2:cout<<"\nEnter the code:";
							       cin>>te;
							       flag=read(j,te);
								if(flag==1)
							       {
									del(j);
							       }
							       else cout<<"\nPlease enter a valid code.";
								cout<<"\nDo you want to go back to the search menu to delete records? (y/n)";
								cin>>c;
								break;
							case 3:break;
							default:cout<<"\nPlease enter a valid choice!";
								break;
						}
						}while(c=='y'|c=='Y');
				}
				else cout<<"\nWrong login details!";

				break;

			case 3:
						tt=p.checkp();
						if(tt==1){
						cout<<"\n\nYou are being directed to the SEARCH MENU. Please press enter to continue.";
						cin.ignore();
						cin.ignore();
						do{
						clrscr();
						cout<<"\t\t\tSEARCH MENU";
						cout<<"\n\t\t\t__________";
						cout<<"\n1. On the basis of the name";
						cout<<"\n2. On the basis of the criminal code";
						cout<<"\n3. Back to the main menu.";
						cout<<"\nEnter your choice(1-3)";
						cin>>ce;
						switch(ce)
						{
							case 1:cout<<"\nEnter the name:";
							       gets(t);
							       flag=read(j,t);
							       if(flag==1)
							       {
								mod(j);
							       }
							       else cout<<"\nPlease enter a valid name.";

								cout<<"\nDo you want to go back to the search menu to modify records? (y/n)";
								cin>>c;

							       break;
							case 2:cout<<"\nEnter the code:";
							       cin>>te;
							       flag=read(j,te);
								if(flag==1)
							       {
									mod(j);
							       }
							       else cout<<"\nPlease enter a valid code.";

								cout<<"\nDo you want to go back to the search menu to modify records? (y/n)";
								cin>>c;
								break;
							case 3:break;
							default:cout<<"\nPlease enter a valid choice!";
								break;
						}
						}while(c=='y'|c=='Y');
				}
				else cout<<"\nWrong login details!";
				break;
			case 4: clrscr();

				cout<<"\t\t\tDISPLAY MENU";
				cout<<"\n\t\t\t____________";
				cout<<"\n\t1.Display all records";
				cout<<"\n\t2.Search and display a specific record.";
				cout<<"\n\t3.Exit";
				cout<<"\nEnter your choice(1-3):";
				int u=0;
				cin>>u;
				switch(u)
				{
					case 1:	clrscr();
						ifstream d;

						d.open("CBID.dat",ios::in|ios::binary);
						d.seekg(0,ios::beg);
						if (d.eof()) cout<<"No records in file.";
						else while(d.read((char*)&j,sizeof(j)))
						{
						j.display();
						}
						cout<<"\n---->>END OF FILE<<----";
						break;
					case 2: int flag;
						char t[100];
						int te;
						char c='n';
						int ce=0;
						cout<<"\n\nYou are being directed to the SEARCH MENU. Please press enter to continue.";
						cin.ignore();
						cin.ignore();
						do{
						clrscr();
						cout<<"\t\t\tSEARCH MENU";
						cout<<"\n\t\t\t__________";
						cout<<"\n1. On the basis of the name";
						cout<<"\n2. On the basis of the criminal code";
						cout<<"\n3. Back to main menu.";
						cout<<"\nEnter your choice(1-3)";
						cin>>ce;
						switch(ce)
						{
							case 1:cout<<"\nEnter the name:";
							       gets(t);
							       flag=read(j,t);
							       if(flag==1)
							       {
									clrscr();
									cout<<"The required details:\n";
									j.display();
							       }
							       else cout<<"\nPlease enter a valid name!";

								cout<<"\nDo you want to go back to the search menu to display records? (y/n)";
								cin>>c;
							       break;
							case 2:cout<<"\nEnter the code:";
							       cin>>te;
							       flag=read(j,te);
							       if(flag==1)
							       {
									clrscr();
									cout<<"The required details:\n";
									j.display();
							       }
							       else cout<<"\nPlease enter a valid code!";

								cout<<"\nDo you want to go back to the search menu to display records? (y/n)";
								cin>>c;
								break;
							case 3:break;
							default:cout<<"\nPlease enter a valid choice!";
								break;
						}
						}while(c=='y'|c=='Y');
						break;
					case 3:break;
					default:cout<<"\nEnter a valid choice!";
							break;
				}
				break;
			case 5: help();
				break;
			case 7: exitp();
			break;
			case 6:p.changeId();
				break;

			default : cout<<"\n\Please enter a valid choice!";
				  break;
	}
	cout<<"\nDo you still want to do something?(y/n)";

	cin>>t;
}while(t=='y'||t=='Y');
cout<<"\n\nHere the program ends :)";

getch();
}


