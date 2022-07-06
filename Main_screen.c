#include<stdio.h>

void title_screen();

int main(){

    title_screen();

    return 0;

}

void title_screen(){

    system("cls");
    int choice;
    printf ("\t\t\t\t\t\t WELCOME TO *** LOGIN PAGE\n\n");
    printf ("\t\t\t\t\t Please Choose from the following options\n\n");
    printf ("\t\t\t\t\t\t1 - Teacher Login\n");
    printf ("\t\t\t\t\t\t2 - Student Login\n");
    printf ("\t\t\t\t\t\t3 - Department login\n");
    printf ("\t\t\t\t\t\tChoose: ");
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
            //dep_reg_screen();
            break;

        default:
            printf ("Invalid entry");
            delay(1);
            title_screen();
    }

}
