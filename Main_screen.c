#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void title_screen();
void delay(float);
void dep_reg_screen();

int main(){

    title_screen();

    return 0;

}

void title_screen(){

    system("cls");
    int choice;
    printf ("\tWELCOME TO *** LOGIN PAGE\n\n");
    printf ("Please Choose from the following options\n\n");
    printf ("\t1 - Teacher Login\n");
    printf ("\t2 - Student Login\n");
    printf ("\t3 - Department login\n");
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
            //department_screen();
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
    char username[15], password[15], d_name[15], d_uni[10], d_hod[15];
    int e_m, e_y, e_d;

    system("cls");
    printf("Restricted Area Loading");
    for(i=0; i<5; i++){
        printf(".");
        delay(0.5);
    }
    system("cls");

    printf("Welcome To Department Creation Page\n\n");
    printf("\t1 - Add a New Department\n");
    printf("\t2 - Exit to Main Screen\n\n");
    printf("Choose: ");
    scanf("%d%*c", &choose);

    if (choose == 2){
        title_screen();
    }    
    else if (choose == 1){
        system("cls");
        user:
        printf("Department Creation\n\n");
        printf("NOTE: Username Shouldn't contain any space\n\n");
        printf("Enter the Username for Department: ");
        scanf("%s%*c", &username);

        pass:
        printf("\nPassword Must Be Between 5 And 15 Character");
        printf("\nEnter Password: ");
        scanf("%s%*c", &password);
        if (strlen(password)<5){
            printf("\nPassword too Short, Try Again!!!");
            delay(1);
            goto pass;
        }
        
        FILE *dup = fopen("Dep_U_P.bin", "a+");
        fprintf(dup, "%s %s", username, password);
        fclose(dup);

        printf("\nAccount Created!!!");
        printf("\nFill Up The Remaining Details");
        printf("\n\nNOTE: No Spaces, Use '-' Instead");

        printf("\n\nEnter the Name of Department: ");
        scanf("%s%*c", &d_name);
        strupr(d_name);
        
        printf("Enter the Established Date (In Format mm-dd-yyyy): ");
        scanf("%.2d-%.2d-%.4d", &e_m, &e_d, &e_y);

        printf("Enter The Affiliated University: ");
        scanf("%s%*c", &d_uni);
        strupr(d_uni);

        printf("Enter the name of HOD of the Dep:[Can Use Space In This]");
        scanf("%[^\n]%*c", &d_hod);
        strupr(d_hod);
        
        FILE *dd = fopen("dep_us_pw.bin", "a+");
        fprintf (dd, "%s %.2d%.2d%.4d %s %s", d_name, e_m, e_d, e_y, d_uni, d_hod);
        fclose(dd);

        printf("\nDepartment Account Created..");
        printf("\nReturning to Main Screen");  
        delay(1);
        system("cls");
        title_screen();      

    }
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