#include <iostream>
#include <string>
using namespace std;


void choosedOption(int ch)
{
    string accNo,accNo1;

    switch(ch)
		{
		case 1:
		    system("CLS");
            create_account();
			break;
		case 2:
		    system("CLS");
		    display_all();
		    break;
		    
		case 3:
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; 
			getline(cin,accNo);
			deposit_withdraw(accNo);
			break;
		case 4:
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; 
		    getline(cin,accNo);
			deposit_amount(accNo);
			break;
		
		case 5:
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; 
		    getline(cin,accNo);
			close_account(accNo);
			break;
		
		case 6:
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; 
		    getline(cin,accNo);
			get_balance(accNo);
			break;
			
		case 7:
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; 
		    getline(cin,accNo);
			get_account(accNo);
			break;
			
		case 8:
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; 
		    getline(cin,accNo);
			transfer_money(accNo);
			break;	

         case 9:
		 	system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; 
		    getline(cin,accNo);
			get_passbook(accNo);
			break;
			
         case 11:
            exit(0);
		 default :cout<<"\a";
		}
    
    
}