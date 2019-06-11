#include <stdio.h>
#include <stdlib.h>
void NEW_ACCOUNT(void);
void DEPOSIT(int acc,float amt);
void WITHDRAW(int acc,float amt);
float BALANCE_ENQ(int acc);

typedef struct
{
    char name[20];
    int acc_no;
    float balance;
}CUSTOMER;

CUSTOMER c[20];
int count=0;

int main()
{
    int ch,acc;
    float amt;
    do{
        printf(" MENU \n");
        printf("1.New account\n2.Deposit\n3.Withdraw\n4.Balance\n5.Exit\n");
        printf("Enter the choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: NEW_ACCOUNT();
                    break;
            case 2: printf("Enter the account number :");
                    scanf("%d",&acc);
                    printf("Enter amount to be deposited :");
                    scanf("%f",&amt);
                    DEPOSIT(acc,amt);
                    break;
            case 3: printf("Enter the account number :");
                    scanf("%d",&acc);
                    printf("Enter amount to be withdrawn :");
                    scanf("%f",&amt);
                    WITHDRAW(acc,amt);
                    break;
            case 4: printf("Enter the account number :");
                    scanf("%d",&acc);
                    printf("Balance amount is %f\n",BALANCE_ENQ(acc));
                    break;
            case 5: exit(0);
        }
    }while(ch!=5);
    return 0;
}

void NEW_ACCOUNT()
{
    int i,acc,found=0;
    printf("Enter an account number :");
    scanf("%d",&acc);
    for(i=0;i<count;i++)
    {
        if(c[i].acc_no==acc)
        {
            found=1;
            break;
        }
    }
    if(!found)
    {
       c[count].acc_no=acc;
       printf("Enter name :");
       scanf("%s",&c[count].name);
       do{
            printf("Enter balance amt : ");
            scanf("%f",&c[count].balance);
            if(c[count].balance<500)
                printf("Insufficient Balance !\n");
       }while(c[count].balance<500);
       count++;
    }
    else
        printf("Account already exists!\n");
}

float BALANCE_ENQ(int acc)
{
     int found=0;
     int i;
     for(i=0; i<count; i++)
     {
         if(c[i].acc_no==acc)
         {
             found=1;break;
         }
     }
     if(found)
     {
         printf("Account name is %s\n",c[i].name);
         printf("Account number is %d\n",c[i].acc_no);
         return c[i].balance;
     }
     else
        printf("Account number does not exist!\n");
}

void DEPOSIT(int acc,float amt)
{
    int i,found=0;
    for(i=0; i<count; i++)
    {
        if(c[i].acc_no==acc)
        {
            found=1;
            break;
        }
    }

    if(found)
    {
        c[i].balance+=amt;
    }
    else
        printf("Account number does not exist!\n");
}

void WITHDRAW(int acc,float amt)
{
    int i,found=0;
    for(i=0; i<count; i++)
    {
        if(c[i].acc_no==acc)
        {
            found=1;
            break;
        }
    }

    if(found)
    {
            if( c[i].balance-amt<500)
            {
                printf("Insufficient balance!\n");
            do{
            printf("Enter the amount to be withdrawn:");
            scanf("%d",&amt);
            } while(c[i].balance-amt<500);
            }

                c[i].balance-=amt;


    }
        else
            printf("Account number does not exist!\n");
}



