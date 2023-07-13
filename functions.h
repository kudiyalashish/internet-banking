#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*RANDOM ACCOUNT NUMBER GENRATOR*/
string account_no_genrator()
{
    string accNo= "1";
    
    //ACCOUNT NUMBER OF LENGTH 16
    for(int i=1; i<=9 ; i++)
    {
        int randNum= rand() % 10;
        accNo= accNo + to_string(randNum);
        
    }
    
//     FILE *fp= fopen("account.dat","r");
//     struct Account a1;
// 	char dupAccNo[20];
	
// 	strcpy(dupAccNo,accNo.c_str());
    
    // while(fread(&a1,sizeof(a1),1,fp))
    // {
    //     if(strcmp(a1.accNo,dupAccNo)==0)
    //     {
    //         return account_no_genrator();
    //     }
    // }
    
    //fclose(fp);
    
    return accNo;
    
}


/*RANDOM IFSC CODE GENRATOR*/
string ifsc_code_genrator()
{
    string ifsc= "BOI";
    string alpha= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for(int i=1; i<=8 ; i++)
    {
        int randNum= rand() % 10;
        ifsc= ifsc + to_string(randNum);
        
    }
    
    int ind= rand()%9;
    ifsc[ind+3]= alpha[rand()%26];
    
    return ifsc;
}


/*  ACCOUNT DETAILS */
void display_account(string accNo,string ifsc,string name,char type,int balance)
{
    cout<<"\n***************|BANK OF INDIA|*****************";
    cout<<"\n\nAccount No. : "<<accNo;
    cout<<"     IFSC CODE:"<<ifsc;
    cout<<"\nName: "<<name;
    cout<<"\nType: "<<type;
    cout<<"\n			 Balance= Rs"<<balance;
    cout<<"\n\n***********************************************";
}

/* UPPER CASE */
string upperCase(string text)
{
    string up= "";
    
    for(int i=0; i<text.length() ;i++)
    {
        char ch= (text[i]>=65 && text[i]<=90 ? text[i]:text[i]-32);
        up = up+ch;
    }
    
    return up;
}

/* CREATE ACCOUNT */
void create_account()
{
    string accNo= account_no_genrator();
    string ifscCode= ifsc_code_genrator();
    
    string name;
    char type;
    int balance;
    
    cout<<"\n\n\t\t\tEnter the Name of the Account holder : ";
	getline(cin,name);
	name= upperCase(name);
	
	cout<<"\n\t\t\tEnter Type of the Account (C/S) : ";
	cin>>type;
	type=  type>=65 && type<=90 ? type : type-32;
	cout<<"\n\t\t\tEnter The Initial amount : ";
	cin>>balance;
	getchar();
	cout<<"\n\n\t\t\tAccount Created..";
	
	write_account(accNo,ifscCode,name,type,balance);
	display_account(accNo,ifscCode,name,type,balance);
    
}


void display_all()
{
    read_all_accounts();
}



void deposit_withdraw(string accNo)
{
    withdraw_money(accNo);
}


void deposit_amount(string accNo)
{
    deposit_money(accNo);
}


void close_account(string accNo)
{
    delete_account(accNo);
}



void get_passbook(string accNo)
{
    transaction_details(accNo);
}


void get_balance(string accNo)
{
    balance_details(accNo);
}

void get_account(string accNo)
{
    modify_account(accNo);
}

void transfer_money(string accNo)
{
    start_transfer(accNo);
}