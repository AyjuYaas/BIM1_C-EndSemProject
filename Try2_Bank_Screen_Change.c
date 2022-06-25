#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>

int screen1();
int Details();
void Create();
void Withdraw();
void Deposit();
void Feedback();

int choose, moe; 
long long int AcNo;
char caa;

struct Dates{
        int dob_y;
        int dob_m; 
        int dob_d;

        int reg_y;
        int reg_m;
        int reg_d;
    } date;

    struct data{
        char fname[50];
        char lname[50];
        char Address[50];
        long long int citizenID;
    } details;

int main(){
    
    begin:
    system("cls");
    choose = screen1();
    system("cls");

    switch(choose){
        
        case 1:
            int opt = Details();
            if (opt == 1)
                goto begin;
            
            else if (opt == 1)
                goto exit;

            break; 

        case 2:
            Create();
            break;

        case 3:
            Withdraw();
            break;

        case 4:
            Deposit();
            break;
        
        case 5:
            Feedback();
            break;

        case 6:
            goto exit;
            break;

        default:
            printf ("Invalid Entry, Try Again!!");
            sleep(2);
            goto begin;
    }

    goto begin;

    exit:
    return 0;
}

int screen1(){

    int num;

    printf ("\n\n\n\n\n\n");
    printf ("\t\t\t\t******* WELCOME TO ___ BANK *******\n");
    printf ("\n\t\t\t\t 1 - Account Details");
    printf ("\n\t\t\t\t 2 - Create Account");
    printf ("\n\t\t\t\t 3 - Withdraw Money");
    printf ("\n\t\t\t\t 4 - Deposit Money");
    printf ("\n\t\t\t\t 5 - Feedback");
    printf ("\n\t\t\t\t 6 - exit\n");
    printf ("\n\t\t\t\t");

    scanf ("%d", &num);

    return num;
}

int Details(){

    printf ("Enter your Account number: ");
    scanf ("%lld", &AcNo);
    
    printf ("\nNot found in the list");
    printf ("\nCreate an account? (Y/N): ");
    caa = getche();
    
    caa = tolower(caa);
    if (caa == 'y'){
        Create();
    }

    else{
        printf ("\nPress 1 to go back to main menu or 2 to exit..");
        scanf ("%d", &moe);

        if (moe == 1)
            return 1;
        else    
            return 2;
        }
}

void Create(){
    printf ("\nCreate an account\n");
    FILE *create;
    fopen ("Bank_Record.txt", "a+");
    printf ("Enter your First Name: ");

    sleep(2);
}

void Withdraw(){
    long long int WithAmt;
    printf ("\nEnter the amount to be withdrawn: ");
    scanf ("%lld", &WithAmt);

    printf ("\nRs. %lld has been withdrawn: ", WithAmt);
    sleep(2);
}

void Deposit(){
    long long int DepAmt;
    printf ("\nEnter the amount to be deposited: ");
    scanf ("%lld", &DepAmt);

    printf ("\nRs. %lld has been deposited in your account", DepAmt);
    sleep(2);
}

void Feedback(){
    char fb[500];
    printf ("Any Feedbacks?\n");
    scanf ("%s", fb);

    printf ("\nThank You for your Feedback\nWe'll make sure to work on it next time");
    printf ("\nHave a great day ahead");
    sleep(3);
}