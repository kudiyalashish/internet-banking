#include <iostream>
#include <string>
#include <cstring>
#include<conio.h>
#include<time.h>

using namespace std;


void print(struct Transaction t1)
{
    cout<<"***"<<t1.date<<"/"<<t1.month<<"/"<<t1.year<<"***";
}

/* WRITE ACCOUNT IN FILES */

void write_account(string accNo,string ifsc,string name,char type,int balance)
{
    FILE *fp= fopen("account.dat","a");
    struct Account a1;
	
	strcpy(a1.accNo, accNo.c_str()); 
	strcpy(a1.ifsc, ifsc.c_str()); 
	strcpy(a1.name, name.c_str()); 
    
    a1.type= type;
    a1.balance= balance;
    
    fwrite(&a1,sizeof(a1),1,fp);
    strcat(a1.accNo,".txt");
    
    FILE *fp1= fopen(a1.accNo,"w");
    
    struct Transaction t1;
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    
    // t1.date=tm.tm_mday;
    // t1.month=tm.tm_mon+1;
    // t1.year=tm.tm_year+1900;
    
    // t1.withdrawAmount= 0;
    // t1.depositeAmount= balance;
    // t1.balance= balance;
    
    // print(t1);
    // fwrite(&t1,sizeof(t1),1,fp1);
    fputs("\t\t\t\t\t\tPASSBOOK\n\n",fp1);
    fputs("=============================================================================\n",fp1);
    fputs("DATE\t\tWITHDRAW\t\tDEPOSITE\t\tBalance\n",fp1);
    fputs("=============================================================================\n",fp1);
    
    fprintf(fp1,"%d\\%d\\%d\t\t%d\t\t\t%d\t\t\t%d\n",tm.tm_mday+1,tm.tm_mon+1,tm.tm_year+1900,0,balance,balance);
    
    // fprintf(fp,"%s %s %s %c %ld\n",a1.accNo,a1.ifsc,a1.name,a1.type,a1.balance);
    fclose(fp);
    fclose(fp1);
}



void read_all_accounts()
{
    FILE *fp= fopen("account.dat","r");
    
    struct Account a;
    cout << "\n\n\t\t\t\tACCOUNT HOLDER LIST\n\n";
    cout << "=============================================================================\n";
    cout << "Sno.\tAccount No.\t\tName\t\tType\t\tBalance\n";
    cout << "=============================================================================\n";
    
    int sno=1;
    struct Account a1;
    while(fread(&a1,sizeof(a1),1,fp))
    {
        cout<<sno<<".\t"<<a1.accNo<<"\t\t"<<a1.name<<"\t\t"<<a1.type<<"\t\t"<<a1.balance<<endl;
        sno++;
    }
    // while(fscanf(fp,"%s %s %s %c %ld",a1.accNo,a1.ifsc,a1.name,&a1.type,&a1.balance) != EOF)
    // {
        
    //     cout<<sno<<".\t"<<a1.accNo<<"\t\t"<<a1.name<<"\t\t"<<a1.type<<"\t\t"<<a1.balance<<endl;
    //     sno++;
    // }
    
    fclose(fp);
}

void withdraw_money(string accNo)
{
    char newAccNo[20];
    
    strcpy(newAccNo,accNo.c_str());
    
    FILE *fp= fopen("account.dat","r+");

    bool found= false;
    long int bal;
    struct Account a1;
    while(fread(&a1,sizeof(a1),1,fp))
    {
        if(strcmp(a1.accNo,newAccNo)==0)
        {
            found= true;
            cout<<"\n\n\t\t\tEnter Withdraw Amount :";
            cin>>bal;
            
            if(a1.balance >= bal)
            {
                a1.balance -= bal;
                fseek(fp,-sizeof(struct Account),1);
                fwrite(&a1,sizeof(a1),1,fp);
                cout<<"BALANCE UPDATED"<<endl;
                
                strcat(a1.accNo,".txt");
                FILE *fp1= fopen(a1.accNo,"a");
    
                struct Transaction t1;
                time_t t;
                t = time(NULL);
                struct tm tm = *localtime(&t);
    
                // t1.date=tm.tm_mday+1;
                // t1.month=tm.tm_mon+1;
                // t1.year= tm.tm_year+1900;
    
                // t1.withdrawAmount= bal;
                // t1.depositeAmount= 0;
                // t1.balance= a1.balance;
    
                //fwrite(&t1,sizeof(t1),1,fp1);
                fprintf(fp1,"%d\\%d\\%d\t\t%ld\t\t\t%d\t\t\t%ld\n",tm.tm_mday+1,tm.tm_mon+1,tm.tm_year+1900,bal,0,a1.balance);

                fclose(fp1);
            }
            else
            cout<<"INSUFFICIENT BALANCE"<<endl;
            
            break;
        }
        
        
    }
    
    if(!found)
    cout<<"INVALID ACCOUNT"<<endl;
    
    fclose(fp);
}


void deposit_money(string accNo)
{
    char newAccNo[20];
    
    strcpy(newAccNo,accNo.c_str());
    
    FILE *fp= fopen("account.dat","r+");

    bool found= false;
    long int bal;
    struct Account a1;
    while(fread(&a1,sizeof(a1),1,fp))
    {
        if(strcmp(a1.accNo,newAccNo)==0)
        {
            found= true;
            cout<<"\n\n\t\t\tEnter Deposite Amount :";
            cin>>bal;
            
                a1.balance += bal;
                fseek(fp,-sizeof(struct Account),1);
                fwrite(&a1,sizeof(a1),1,fp);
                cout<<"BALANCE UPDATED"<<endl;
                strcat(a1.accNo,".txt");
                FILE *fp1= fopen(a1.accNo,"a");
    
                struct Transaction t1;
                time_t t;
                t = time(NULL);
                struct tm tm = *localtime(&t);
    
                // t1.date=tm.tm_mday+1;
                // t1.month=tm.tm_mon+1;
                // t1.year=tm.tm_year+1900;
    
                // t1.withdrawAmount= 0;
                // t1.depositeAmount= bal;
                // t1.balance= a1.balance;
    
                // fwrite(&t1,sizeof(t1),1,fp1);
                fprintf(fp1,"%d\\%d\\%d\t\t%d\t\t\t%ld\t\t\t%ld\n",tm.tm_mday+1,tm.tm_mon+1,tm.tm_year+1900,0,bal,a1.balance);

                fclose(fp1);
            
            break;
        }
        
        
    }
    
    if(!found)
    cout<<"INVALID ACCOUNT"<<endl;
    
    fclose(fp);
}



void delete_account(string accNo)
{
    char newAccNo[20];
    
    strcpy(newAccNo,accNo.c_str());
    
    FILE *fp1= fopen("account.dat","r");
    FILE *fp2= fopen("temp.dat","w");

    bool found= false;
    long int bal;
    struct Account a1;
    while(fread(&a1,sizeof(a1),1,fp1))
    {
        if(strcmp(a1.accNo,newAccNo)==0)
        {
            found= true;
            continue;
        }
        else
        fwrite(&a1,sizeof(a1),1,fp2);
        
    }
    
    fclose(fp1);
    fclose(fp2);
    
    if(!found)
    {
        cout<<"INVALID ACCOUNT"<<endl;
        return;
    }
    
    
    
    
    fp1= fopen("account.dat","w");
    fp2= fopen("temp.dat","r");
    
    while(fread(&a1,sizeof(a1),1,fp2))
    {
        if(strcmp(a1.accNo,newAccNo)==0)
        {
            found= true;
            continue;
        }
        else
        fwrite(&a1,sizeof(a1),1,fp1);
        
    }
    
    remove("temp.dat");
    
    fclose(fp1);
    fclose(fp2);
}


void transaction_details(string accNo)
{
    char newAccNo[20];
    
    strcpy(newAccNo,accNo.c_str());
    strcat(newAccNo,".txt");
    FILE *fp= fopen(newAccNo,"r");
    
    char line[100];
    
    while(fgets(line,99,fp))
    {
        
        printf("%s",line);
    }
    
    
    fclose(fp);
}



void balance_details(string accNo)
{
    char newAccNo[20];
    
    strcpy(newAccNo,accNo.c_str());
    
    FILE *fp= fopen("account.dat","r");
    
    bool found= false;
    struct Account a1;
    
     while(fread(&a1,sizeof(a1),1,fp))
    {
        if(strcmp(a1.accNo,newAccNo)==0)
        {
            cout<<"=> "<<"HELLO "<<a1.name<<endl;
            cout<<"      AVAILABLE BALANCE ="<<a1.balance<<endl;
            found= true;
            break;
        }
       
        
    }
    
    if(!found)
    cout<<"INVALID ACCOUNT"<<endl;
    
    fclose(fp);
}

void modify_account(string accNo)
{
    char newAccNo[20];
    
    strcpy(newAccNo,accNo.c_str());
    
    FILE *fp= fopen("account.dat","r+");
    
    bool found= false;
    struct Account a1;
    int ch;
    
    while(fread(&a1,sizeof(a1),1,fp))
    {
        if(strcmp(a1.accNo,newAccNo)==0)
        {
            cout<<"*****|ACCOUNT FOUND|*******"<<endl;
            cout<<"1. UPDATE NAME"<<endl;
            cout<<"2. UPDATE TYPE"<<endl;
            cin>>ch;
            getchar();
            
            switch(ch)
            {
                case 1:
                cout<<"ENTER NEW NAME :";
                fgets(a1.name,20,stdin);
                a1.name[strlen(a1.name)-1]= '\0';
                break;
                case 2:
                cout<<"ENTER NEW ACCOUNT TYPE :";
                cin>>a1.type;
                getchar();
                break;
                default:
                cout<<"INVALID CHOICE"<<endl;
            }
            
            fseek(fp,-sizeof(a1),1);
            fwrite(&a1,sizeof(a1),1,fp);
            cout<<"!!!!!!ACCOUNT DETAILS UPDATED!!!!!!"<<endl;
            found= true;
            break;
        }
       
        
    }
    
    if(!found)
    cout<<"INVALID ACCOUNT"<<endl;
    
    fclose(fp);
}



void start_transfer(string accNo)
{
    char newAccNo[20];
    strcpy(newAccNo,accNo.c_str());
    
    char name[20],taccNo[20];
    cout<<"ENTER BENEFICIARY NAME :"<<endl;
    fgets(name,20,stdin);
    
    cout<<"ENTER BENEFICIARY ACCOUNT NUMBER :"<<endl;
    fgets(taccNo,20,stdin);
    taccNo[strlen(taccNo)-1]= '\0';
    
    FILE *fp= fopen("account.dat","r+");

    bool found= false;
    long int bal;
    struct Account a1;
    while(fread(&a1,sizeof(a1),1,fp))
    {
        if(strcmp(a1.accNo,newAccNo)==0)
        {
            found= true;
            cout<<"\n\n\t\t\tEnter Transfer Amount :";
            cin>>bal;
            
            if(a1.balance >= bal)
            {
                a1.balance -= bal;
                fseek(fp,-sizeof(struct Account),1);
                fwrite(&a1,sizeof(a1),1,fp);
                cout<<"\n\nTranfer Initiating Plz Wait .......\n\n"<<endl;
                
                strcat(a1.accNo,".txt");
                FILE *fp1= fopen(a1.accNo,"a");
    
                struct Transaction t1;
                time_t t;
                t = time(NULL);
                struct tm tm = *localtime(&t);
    
                fprintf(fp1,"%d\\%d\\%d\t\t%ld\t\t\t%d\t\t\t%ld\n",tm.tm_mday+1,tm.tm_mon+1,tm.tm_year+1900,bal,0,a1.balance);

                fclose(fp1);
            }
            else
            cout<<"INSUFFICIENT BALANCE"<<endl;
            
            break;
        }
        
        
    }
    
    if(!found)
    cout<<"INVALID ACCOUNT"<<endl;
    
    fclose(fp);
    
    
    fp= fopen("account.dat","r+");

    found= false;
    while(fread(&a1,sizeof(a1),1,fp))
    {
        if(strcmp(a1.accNo,taccNo)==0)
        {
            found= true;
            
                a1.balance += bal;
                fseek(fp,-sizeof(struct Account),1);
                fwrite(&a1,sizeof(a1),1,fp);
                cout<<"Transfer completed"<<endl;
                strcat(a1.accNo,".txt");
                FILE *fp1= fopen(a1.accNo,"a");
    
                struct Transaction t1;
                time_t t;
                t = time(NULL);
                struct tm tm = *localtime(&t);
    
                
                fprintf(fp1,"%d\\%d\\%d\t\t%d\t\t\t%ld\t\t\t%ld\n",tm.tm_mday+1,tm.tm_mon+1,tm.tm_year+1900,0,bal,a1.balance);

                fclose(fp1);
            
            break;
        }
        
        
    }
    
    if(!found)
    cout<<"INVALID ACCOUNT"<<endl;
    
    fclose(fp);
}