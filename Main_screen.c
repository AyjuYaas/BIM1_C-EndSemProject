#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void title_screen();
void delay(float);

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
            //dep_reg_screen();
            break;

        default:
            printf ("Invalid entry");
            delay(1);
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