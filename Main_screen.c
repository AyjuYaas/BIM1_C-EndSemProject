#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"designers_info.h"

void title_screen();
void delay(float);
void dep_reg_screen();
void department_screen();

struct {
    char un[10];
    char pw[15];
    char dname[20];
    int dobm, dobd, doby;
    int em, ed, ey;
    char uni[40];
    char hod[20];
}dep, depch, stu, stuch, tea, teach;

int main(){

    title_screen();

    return 0;

}

void title_screen(){

    system("cls");
    int choice;
    printf ("\tWELCOME TO *** LOGIN PAGE\n\n");
    printf ("Please Choose from the following options\n\n");
    printf ("\t[1] Teacher Login\n");
    printf ("\t[2] Student Login\n");
    printf ("\t[3] Department login\n");
    printf ("\t[4] Designers Info\n");
    printf ("\t[5] Exit\n");
    printf ("\tChoose: ");
    scanf ("%d", &choice);

    switch (choice) {
        case 1:
            //teacher_screen();
            break;

        case 2:
            //student_screen();
            break;

        case 3:
            department_screen();
            break;

        case 4:
            animation();
            delay(0.5);
            title_screen();
            break;

        case 5:
            exit(1);
            break;
            
        case 32715:
            dep_reg_screen();
            break;

        default:
            printf ("Invalid entry");
            delay(1);
            title_screen();
    }

}

void dep_reg_screen(){
    int i, choose;

    system("cls");
  /** LOADING SCREEN **/
    printf("Restricted Area Loading");
    for(i=0; i<5; i++){
        printf(".");
        delay(0.2);
    }
    system("cls");

  /** CHOOSING SCREEN **/
    dep_create_choose:
    printf("Welcome To Department Creation Page\n\n");
    printf("\t[1] Add a New Department\n");
    printf("\t[2] Exit to Main Screen\n\n");
    printf("Choose: ");
    scanf("%d%*c", &choose);

    if (choose == 2){
        title_screen();
    }    
    else if (choose != 1){
        printf("Wrong Entry!!!");
        delay(0.6);
        system("cls");
        goto dep_create_choose;
    }

    system("cls");

  /** Department Username Password **/
    user:
    FILE *dcheck;
    dcheck = fopen("DUP.dat", "r");
 
    printf("\tDepartment Creation!!!\n\n");
    printf("NOTE: Username Shouldn't contain any space, 5 - 10 Character\n\n");
    printf("Enter the Username for Department: ");
    scanf("%s%*c", &dep.un);
    depch.un[10] = '\0';
    depch.pw[15] = '\0';

    while (fscanf(dcheck, "%s %s\n", depch.un, depch.pw) != EOF){
        if (strcmp(dep.un, depch.un) == 0){
            printf("\nUsername Already Taken!!!");
            printf("\nTry Again with Another USERNAME");
            delay(1);
            system("cls");
            goto user;
        }
    }

    pass:
    printf("\nPassword Must Be Between 5 And 15 Character");
    printf("\nEnter Password: ");
    scanf("%s%*c", dep.pw);
    if (strlen(dep.pw)<5){
        printf("\nPassword too Short, Try Again!!!");
        delay(1);
        goto pass;
    }
    fclose(dcheck);
    
    FILE *dup;
    dup = fopen("DUP.dat", "a+");
    fprintf(dup, "%s %s\n", dep.un, dep.pw);
    fclose(dup);

    printf("\nAccount Created!!!");
    printf("\nFill Up The Remaining Details");
    printf("\n\nNOTE: Use No Space on FILLING THESE FORMS");

  /** DEPARTMENT FURTHER DETAILS **/
    printf("\n\nEnter the Name of Department: ");
    scanf("%s%*c", &dep.dname);
    strupr(dep.dname);
    
    printf("Enter the Established Date (In Format mm/dd/yyyy): ");
    scanf("%d/%d/%d%*c", &dep.em, &dep.ed, &dep.ey);

    printf("Enter The Affiliated University: ");
    scanf("%s%*c", &dep.uni);
    strupr(dep.uni);

    printf("Enter the name of HOD of the Dep [Can Use Space In This]:\n");
    scanf("%[^\n]%*c", &dep.hod);
    strupr(dep.hod);
    
    FILE *dd;
    dd = fopen("dep_details.dat", "a+");
    fprintf (dd, "%s %s %.2d%.2d%.4d %s %s\n", dep.un, dep.dname, dep.em, dep.ed, dep.ey, dep.uni, dep.hod);
    fclose(dd);

    printf("\nDepartment Account Created..");
    printf("\nReturning to Main Screen .");  
    for(i=0; i<5; i++){
        printf(".");
        delay(0.2);
    }
    system("cls");
    title_screen();      

}

void department_screen(){

    int flag = 0, choice;
    system("cls");
    printf("\tDepartment Login!!!!");
    printf("\n\nEnter Username: ");
    scanf("%s%*c", dep.un);
    printf("Enter Password: ");
    scanf("%s%*c", dep.pw);

    FILE *deptche;
    deptche = fopen("DUP.dat", "r");
    while(fscanf(deptche, "%s %s\n", depch.un, depch.pw) != EOF){
        if(strcmp(dep.un, depch.un)==0 && strcmp(dep.pw, depch.pw)==0){
            flag = 1;
            system("cls");
            printf ("Welcome %s", dep.un);
            delay(1);
            system("cls");
            goto success;
        } 
    }
    if(flag == 0){
        printf("Username/Password Incorrect!!!");
        redo_dep:
        printf("[1] Try Again?\n");
        printf("[2] Main Menu");
        printf("[3] Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        if(choice == 1){
            department_screen();
        }
        else if(choice == 2){
            title_screen();
        }
        else if(choice == 3){
            exit(2);
        }
        else{
            printf("Wrong Entry!!");
            printf("Enter Correctly!!");
            delay(1);
            goto redo_dep;  
        }
        
    } 

    success:
    printf("EOD");
    delay(1);  
}

void delay(float sec) 
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * sec;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;

    /* This Piece of code Was Taken from stackoverflow.com */
}