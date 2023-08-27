#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
using namespace std;
class Voter {
			int age;
			string id;
			string name;
		public:
			Voter(){
			}
			Voter(int age,string name,string id) {
				this->age=age;
				this->name=name;
				this->id=id;
			}
			string getId(){
				return id;
			}
			bool checkAge() {
				if(age<18 || age>150) {
					return false;
				}
				else {
					return true;
				}
			}
			bool isValidID() {
				if(id.length()==10 && !isdigit(id[5])){
					return true;
				}
				else {
					return false;
				}
			}
			void displayVoterDetails() {
				cout<<"\n****************************************";
				cout<<"\nTHE VOTER DETAILS : \n";
				cout<<"\n\tVOTER NAME : "<<name;
				cout<<"\n\tVOTER AGE  : "<<age;
				cout<<"\n\tVOTER ID   : "<<id;
				cout<<"\n****************************************";
			}
};
class Election {
	static int A,B,C,N;
	public:
	  void voteNow()
      {  
         int a;
		 char n[3];
         cout<<"\n\nThe participated sections are:"<<endl;
         cout<<"1.CSEA"<<endl<<"2.CSEB"<<endl<<"3.CSEC"<<endl<<"4.NOTA"<<endl;
         cout<<endl;
  label1:cout<<"VOTE FOR YOUR FAVOURITE SECTION : ";
         cin>>n;
         a=atoi(n);
         if(a==1)
         {
         cout<<endl<<"\t**you have voted for CSEA**"<<endl;
         A=A+1;
         }
         else if(a==2)
         {
         cout<<endl<<"\t**you have voted for CSEB**"<<endl;
         B=B+1;
         }
         else if(a==3)
         {
         cout<<endl<<"\t**you have voted for CSEC**"<<endl;
         C=C+1;
         }
         else if(a==4)
         {
         cout<<endl<<"\t**I didn't like these sections**"<<endl;
         N=N+1;
         }
         else
         {
         cout<<endl<<"\t---plz enter correct input---"<<endl<<endl;
         goto label1;
         }   
      }
	  void result()
      {
          cout<<"\nThe result is: "<<endl;
          cout<<"\tCSEA got "<<A<<" votes"<<endl;
          cout<<"\tCSEB got "<<B<<" votes"<<endl;
          cout<<"\tCSEC got "<<C<<" votes"<<endl<<endl;
          cout<<N<<" votes are not used to any section"<<endl;
          cout<<endl<<"\n\t\t------> WINNER IS <------"<<endl;
          (A>B&&A>C&&A>N)?cout<<setw(30)<<right<<"CSEA"<<endl:(B>A&&B>C&&B>N)?cout<<setw(30)<<"CSEB"<<endl:(C>A&&C>B&&C>N)?cout<<setw(30)<<"CSEC"<<endl:cout<<setw(34)<<"NOT DECIDED"<<endl;
      }
};
int Election::A;
int Election::B;
int Election::C;
int Election::N;
int main() {
	    Voter v[100];
	    Election e[100];
    	int i=0;
        static int m=0;
        char b;
      do
      {
    	label:cout<<"\n*******************************************************";
		cout<<"\n\t\tCSE ELECTION COMMISSION";
		cout<<"\n*******************************************************";
		int age,j;
		string name,id;
		cout<<"\n\nEnter the voter age : ";
  		cin>>age;
		cout<<"\nEnter the voter name : ";
		cin>>name;
		cout<<"\nEnter the voterID : ";
		cin>>id;
		v[i]=Voter(age,name,id);
		if(v[i].checkAge()==false) {
			system("CLS");
			cout<<"\n\t------> NOT ELIGIBLE DUE TO INVALID AGE <------\n";
			goto label2;
		}
		for(j=0;j<i;j++)
        {
            int f=strcmp(v[j].getId().c_str(),id.c_str());
            if(f==0)
            {
            	system("CLS");
            	cout<<endl<<"\n\t\t-----> VOTER ALREADY VOTED <-----"<<endl<<endl;
                goto label2;
            }
        }
		if(v[i].isValidID()) {
			v[i].displayVoterDetails();
			cout<<"\n\t-----> ELIGIBLE <-----";
            e[i].voteNow();
            system("CLS");
            m=m+1;
            i++;
       }
       else {
       		system("CLS");
       		cout<<"\n\t-----> NOT ELIGIBLE DUE TO INVALID VOTER ID <-----";
       		goto label2;
	   }
        label2: cout<<endl<<m<<" MEMBERS are VOTED any OTHER voters TO VOTE now:"<<endl;
       		cout<<endl<<"if yes enter Y or if no enter N : ";
            cin>>b;
               if(b!='n'&& b!='N'&& b!='Y' && b!='y')
               {
               		cout<<endl<<"\t\tplz enter correct input!!!!"<<endl;
               		goto label2;
               }
               cout<<endl<<"******************************************************"<<endl<<endl;
               if(b=='n'||b=='N')
               		break;
               system("CLS");
      }while(b=='Y'||b=='y');
      system("CLS");
      e[m].result();
}