#include <iostream>
#include "allStruct.h"

#include "filesOperations.h"
#include "functions.h"
#include "choiceManager.h"


using namespace std;

int main()
{
    int ch;
    //****ALL AVAILABLE OPTIONS****
    while(true)
    {
        
        system("CLS");
	    cout<<"\n\n\t\t\t\t======================\n";
	    cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
	    cout<<"\n\t\t\t\t======================\n";

		cout<<"\t\t\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t\t\t1. NEW ACCOUNT";
		cout<<"\n\t\t\t\t2. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t\t\t\t3. WITHDRAW AMOUNT";
		cout<<"\n\t\t\t\t4. DEPOSIT AMOUNT";
		cout<<"\n\t\t\t\t5. CLOSE AN ACCOUNT";
		cout<<"\n\t\t\t\t6. BALANCE ENQUIRY";
		cout<<"\n\t\t\t\t7. MODIFY AN ACCOUNT";
		cout<<"\n\t\t\t\t8. TRANSFER MONEY";
		cout<<"\n\t\t\t\t9. PASSBOOK";
		cout<<"\n\t\t\t\t10.ACCOUNT DETAILS";
		cout<<"\n\t\t\t\t11.EXIT";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-11): ";
		cin>>ch;
		getchar();
		choosedOption(ch);
		
        
    }
    
    
    return 0;
}