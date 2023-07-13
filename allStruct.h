#include <string>
using namespace std;

struct Account
{
  char accNo[20];
  char ifsc[20];
  char name[20];
  char type;
  long int balance;
};

struct Transaction
{
    int date;
    int month;
    int year;
    
    int withdrawAmount;
    int depositeAmount;
    long int balance;
};