#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
using namespace std;

int amount;
string name;
void display()
	{
		string show=
		"\n                                                            "
		"\n    C C        A       SSSSS   IIIII    N     N    OOOO     "
 		"\n  C           A A      S        III     N N   N   OO  OO    "
 		"\n C           A   A     SSSSS     I      N  N  N  OO    OO   "
		 "\n  C         AAAAAAA        S    III     N   N N   OO  OO    " 
 		"\n    C C    A       A   SSSSS   IIIII    N     N    OOOO     "  ;

 		for(int i=0;i<show.size();i++)
		{
 			Sleep(8);
 			cout<<show[i];
 		}
	}

void rules()
	{
		system("cls");
		cout << "\n\n";
    	cout << "THE RULES OFE THE GAME ARE : \n";
    	cout << "You have to choose any number between 1 to 20 and bet on it \n";
    	cout << "If you win you will get 10 times of money you bet \n";
    	cout << "If you bet on wrong number you will lose your betting amount \n";
	}	

void user()
	{	
		cout<<"\nEnter name :\n";
		getline(cin,name);
		cout<<endl;
		cout<<"Enter the total amount :\n";
		cin>>amount;
		cout<<endl;
	}

int main()
	{
		bool flag=0;
		display();
		rules();
		user();
		char input;
		do
		{
		int money;
		back:
		cout<<"Enter the amount you want to bet :\n";
		cin>>money; 
		cout<<endl;
		if(money > amount)
		{
			int choice;
			cout<<"You don't have enough money \n\n";
			cout<<"Do you want to know your total amount ? \n 1.Yes \n 2.No \n" ;
			cin>>choice;
			if(choice==1)
			{
				cout<<"User " << name <<" have currently "<< amount <<" Rs. available \n\n";
				goto back;
			}
			else if(choice ==2)
			{
				goto back;
			}
		}
		int spin= rand()%10+1;
		int guess;
		bool flag=0;
		back2:
		cout<<"Select your desired mode: \n";
		cout<<"1: Guess the number the spin will stop on \n";
		cout<<"2: Guess if the spin will stop on an even number or odd number \n";
		cout<<"Enter input : ";
		cin>>guess;
		cout<<endl;
		if(guess==1)
		{
			int n;
			cout<<"The spin is rotating : \n";
			int arr[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
			int arr2[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
			for(int i=0;i<20;i++)
			{
 				Sleep(15);
 				cout<<arr[i]<<" ";
 			}
 			for(int i=0;i<20;i++)
			{
 				Sleep(15);
 				cout<<arr2[i]<<" ";
 			}
			cout<<"\n\nEnter the number you want to bet on in between 1-20 : \n";
			cin>>n;
			cout<<endl;
			if(guess==spin)
			{
				flag=1;
			}
			else
			{
				flag=0;
			}
			}
			else if(guess==2)
			{
				if(spin%2==0)
			{
				flag=1;
			}
			else
			{
				flag=0;
			}
			}
			else if(guess==3)
			{
				if(spin%2!=0)
			{
				flag=1;
			}
			else
			{
				flag=0;
			}	
			}
			else
			{
			cout<<"Invalid input "<<endl;
				goto back2;
			}	
			if(flag==1)
			{
				cout<<"BINGO ! YOU GUESSED IT RIGHT \n"<<endl;
				cout<<"You win Rs. "<<money*10<<endl;
				amount+=money*10;
			}
			else
			{
				cout<<"Sorry ";
				cout<<"You lose Rs."<<money<<endl;
				amount=amount-money;	
			}
			cout<<"Would you like to play again y/n :		";
			cin>>input;
			cout<<endl;
			if(amount==0)
			{
				cout<<"You have not enough money to play"<<endl;
				break;
			}
			}
			while(input!='n');
			cout<<"User "<<name<<" have "<<amount<<"Rs. left"<<endl;
			return 0;
	}
