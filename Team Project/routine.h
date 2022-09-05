#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

void delayfr(float sec);
void trim(char * str);

char * routine_maker(char dep_name[]){

    system("cls");
/****************** INITIALIZATION 1 ************************/
    printf(" ROUTINE MAKING PROGRAM \n\n");
    int no_of_routines; 
    char days[7][3] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int period;
    //LOOP Variables
    int t, i=0, j, l, op;
    //Count Variables
    int d, n, lp1;
    //Manipulation Variables
    int per, pert;

/************* DAY SELECT ******************/

    day_select:
    fflush(stdin);
    int end_day, start_day, total_days;
    printf("\nIf:\n\n[1] Sunday\n[2] Monday\n[3] Tuesday\n[4] Wednesday\n[5] Thursday\n[6] Friday\n[7] Saturday");
    printf ("\n\nChoose a starting day and a ending day for routine\n");
    printf("\nNOTES:\nA> Choose Start and End Day, EG: 1 & 6 For Sunday to Friday\nB> For Only 1 Day routine Enter the same number (eg 1 & 1 for Sunday)");
    printf("\nC> Descending order is not allowed: eg; 7 - 1 (i.e. Sat to Sun is prohibitted)");
    printf("\n\nChoose Start Day: ");
    scanf("%d", &start_day);
    fflush(stdin);

    if(start_day<1 || start_day>7){
        getchar();
        printf("\nError! Out of Range Value!");
        delayfr(1);
        system("cls");
        goto day_select;
    }

    re:
    fflush(stdin);
    printf("\nChoose End Day: ");
    scanf("%d%*c", &end_day);
    fflush(stdin);

    if(end_day<1 || end_day>7){
        getchar();
        printf("\nError! Out of Range Value!");
        delayfr(0.6);
        goto re;
    }

    total_days = (end_day - start_day);

    if(total_days<0){
        printf("Error! Wrong Format\n");
        delayfr(1);
        system("cls");
        goto day_select;
    }
    total_days = (end_day-start_day)+1;

/********** INITIALIZATION 2 ***************/

    printf("\nEnter the Total Number of Periods You Want(In a Day): ");
    scanf("%d", &period);
    fflush(stdin);

    printf("\nEnter the Number of Routines You Want to Make: ");
    scanf("%d", &no_of_routines);
    fflush(stdin);

    char faculty[no_of_routines][15];

    char period_marker[11] = ">>>       ";

    int total_period = (total_days*period);
    
    char subject[no_of_routines][total_period][14];
    char error_subject[no_of_routines][total_period][15];

    system("cls");

/********** ROUTINE MAKING ************/
    for(t=0; t<no_of_routines; t++){
 
        printf("\nRoutine no. %d\nGrade/Faculty for this Routine: ", (t+1));
        scanf("%[^\n]", faculty[t]);
        fflush(stdin);
        strupr(faculty[t]);

        for(i=0; i<total_period; i++){
            subject[t][i][14] = '\0';
        }

        system("cls");

        for(op=0; op<total_period; op++){
            lp1 = (start_day-1);
            printf("Routine no. %d\n", (t+1));
            printf("Grade/Faculty = %s\n", faculty[t]);
            strcpy(subject[t][op], period_marker);

            for(i=0; i<total_days; i++){
                n = i;

                if (i==0){
                    printf("----------");
                    for(l=1; l<=(period); l++){
                        printf("------------------");
                    }
                    printf("\n|%5.3s\t", "D/P");
                    for(l=0; l<period; l++){
                        printf("|      %-10d ", l+1);
                    }
                    printf("|\n");
                    printf("----------");
                    for(l=1; l<=(period); l++){
                        printf("------------------");
                    }
                }

                printf("\n|%5.3s\t", days[lp1]);
                lp1 += 1;

                per = (n*period);
                pert = ((n+1)*period);
                d = 0;
                
                for (j=per; j<pert; j++){
                    printf ("| %-15.14s ", subject[t][j]);
                }

                printf ("|\n");

                printf("----------");
                for(l=1; l<=(period); l++){
                    printf("------------------");
                }

            }

            printf("\nEnter the Subject Down Below to Replace the Pointer '>>>' [Max 14 letters (including space)]:\n");
            printf("Enter Here: ");
            fgets(subject[t][op], 14, stdin);
            fflush(stdin);
            
            trim(subject[t][op]);
            strupr(subject[t][op]);
            system("cls");
        }

        if(op == (total_period-1)){
            delayfr(1);
            system("cls");
        }
    }
    
/******** Collison Detactor *******/

    for(t=0; t<no_of_routines; t++){
        for(i=0; i<total_period; i++){
            strcpy(error_subject[t][i], subject[t][i]);
        }
    }

    int flag = 0;
    int k, w;
    int choice_1;

    for (t=0; t<(no_of_routines-1); t++){
        for(i=0; i<total_days; i++){
            n = i;
            per = (n*period);
            pert = ((n+1)*period);
            d = 0;

            for (j=per; j<pert; j++){
                d += 1;
                w = (t+1);
                for (k=w; k<no_of_routines; k++){
                    if (strcmp(error_subject[t][j], error_subject[k][j]) == 0){
                        strcat (error_subject[t][j], " <");
                        strcat (error_subject[k][j], " <");
                        flag++;
                    }
                }
            }
        }
    }

/****** Showing Errors ******/
    if(flag != 0){

        for(t=0; t<no_of_routines; t++){
            printf("\n\n");

            lp1 = (start_day-1);
            printf("Routine no. %d\n", (t+1));
            printf("Faculty = %s\n", faculty[t]);

            for(i=0; i<total_days; i++){
                n = i;

                if (i==0){
                    printf("----------");
                    for(l=1; l<=(period); l++){
                        printf("------------------");
                    }
                    printf("\n|%5.3s\t", "D/P");
                    for(l=0; l<period; l++){
                        printf("|      %-10d ", l+1);
                    }
                    printf("|\n");
                    printf("----------");
                    for(l=1; l<=(period); l++){
                        printf("------------------");
                    }
                }
                
                printf("\n|%5.3s\t", days[lp1]);
                lp1 += 1;

                per = (n*period);
                pert = ((n+1)*period);
                d = 0;
                
                for (j=per; j<pert; j++){
                    printf ("| %-16.15s", error_subject[t][j]);
                }

                printf ("|\n");

                printf("----------");
                for(l=1; l<=(period); l++){
                    printf("------------------");
                }

            }

        }

        solve_retry:
        fflush(stdin);
        printf ("\n%d collisions Detected In Subjects Marked '<'\nWant to Solve?\n[1] Yes\n[2] No\nChoose: ", flag);
        scanf("%d", &choice_1);
        fflush(stdin);

        if(choice_1 == 1)
            goto solve;
        
        else if (choice_1 == 2)
            goto final_print;

        else{
            printf("\nError, Wrong Response: ");
            delayfr(1);
            goto solve_retry;
        }

    }

/***** Collison Solver *****/
    solve:
    fflush(stdin);
    int error;
    int solve, soln;
    char collision_count = 1;
    char ch = ' ';
    do{ 
        error = 0;
        for (t=0; t<(no_of_routines-1); t++){
            for(i=0; i<total_days; i++){
                n = i;
                per = (n*period);
                pert = ((n+1)*period);
                d = 0;
                lp1 = (start_day-1);

                for (j=per; j<pert; j++){
                    d += 1;
                    w = (t+1);
                    for (k=w; k<no_of_routines; k++){
                        if (strcmp(subject[t][j], subject[k][j]) == 0){
                            printf("\nCollision No. %d", collision_count);
                            printf ("\nCollision on %.3s period %d on %s & %s ", days[lp1], d, faculty[t], faculty[k]);
                            printf ("(%s = %s)", subject[t][j], subject[k][j]);

                            error = 1;
                            flag = 1;
                            collision_count++;
                            solve_part:
                            fflush(stdin);
                            solve = '\0';
                            printf ("\nSolve it?\n[1] YES\n[2] NO\nChoose: ");
                            scanf("%d", &solve);
                            fflush(stdin);

                            if (solve == 1){
                                soln_part:
                                printf ("\nMake changes to:\n[1] Make Changes to %s\n[2] to Make Changes to %s\nChoose: ", faculty[t], faculty[k]);
                                scanf("%d", &soln);
                                fflush(stdin);

                                if(soln == 1){
                                    printf ("%s Faculty %.3s period %d: ", faculty[t], days[lp1], d);
                                    scanf("%s", subject[t][j]);
                                    fflush(stdin);
                                    strupr(subject[t][j]);
                                }

                                else if (soln == 2){
                                    printf ("%s Faculty %.3s period %d: ", faculty[k], days[lp1], d);
                                    scanf("%s", subject[k][j]);
                                    fflush(stdin);
                                    strupr(subject[k][j]);
                                }

                                else{
                                    printf ("\nInvalid Entry!!");
                                    delayfr(1);
                                    goto soln_part;
                                }
                            }

                            else if (solve == 2){
                                strcat(subject[k][j], " ");
                                lp1 += 1;
                                continue;
                            }

                            else{
                                printf ("Invalid Entry!!");
                                delayfr(1);
                                goto solve_part;
                            }
                        }
                    }
                }

                lp1 += 1;
            }
        }
    }while (error == 1);

/****** THE FINAL OUTPUT ******/
    final_print:
    printf("\nThe Final Routine/s: ");
    for(t=0; t<no_of_routines; t++){
        printf("\n\n");

        lp1 = (start_day-1);
        printf("Routine no. %d\n", (t+1));
        printf("Faculty = %s\n", faculty[t]);

        for(i=0; i<total_days; i++){
            n = i;

            if (i==0){
                printf("----------");
                for(l=1; l<=(period); l++){
                    printf("------------------");
                }
                printf("\n|%5.3s\t", "D/P");
                for(l=0; l<period; l++){
                    printf("|      %-10d ", l+1);
                }
                printf("|\n");
                printf("----------");
                for(l=1; l<=(period); l++){
                    printf("------------------");
                }
            }

            printf("\n|%5.3s\t", days[lp1]);
            lp1 += 1;

            per = (n*period);
            pert = ((n+1)*period);
            d = 0;
            
            for (j=per; j<pert; j++){
                printf ("| %-16.15s", subject[t][j]);
            }

            printf ("|\n");

            printf("----------");
            for(l=1; l<=(period); l++){
                printf("------------------");
            }

        }

    }
    
/**** FIlE PRINTING ****/
    redo_rn:
    fflush(stdin);
    static char routine_name[25], temp_dep[20], temp_routine_name[30];
    
    printf("\n\nEnter the name of routine you want to save it as (25 Words Including Space)\n");
    gets(routine_name);
    fflush(stdin);
    if(strlen(routine_name) > 25){
        printf("\nName too long!!");
        goto redo_rn;
    }
    FILE *op12 = fopen("routinelist.txt", "a+");
    fprintf(op12, "%s|%s\n", dep_name, routine_name);
    fclose(op12);
    
    strcat(routine_name, ".txt");
    fflush(stdin);
    
    FILE *rot = fopen(routine_name, "w+");

    for(t=0; t<no_of_routines; t++){
        if(t!=0){
            fprintf(rot, "\n\n");
        }
        
        lp1 = (start_day-1);
        fprintf(rot, "Faculty: %s\n", faculty[t]);

        for(i=0; i<total_days; i++){
            n = i;

            if (i==0){
                fprintf(rot, "----------");
                for(l=1; l<=(period); l++){
                    fprintf(rot, "------------------");
                }
                fprintf(rot, "\n|%5.3s\t", "D/P");
                for(l=0; l<period; l++){
                    fprintf(rot, "|      %-10d ", l+1);
                }
                fprintf(rot, "|\n");
                fprintf(rot, "----------");
                for(l=1; l<=(period); l++){
                    fprintf(rot, "------------------");
                }
            }

            fprintf(rot, "\n|%5.3s\t", days[lp1]);
            lp1 += 1;

            per = (n*period);
            pert = ((n+1)*period);
            d = 0;
            
            for (j=per; j<pert; j++){
                fprintf (rot, "| %-16.15s", subject[t][j]);
            }

            fprintf (rot, "|\n");

            fprintf(rot, "----------");
            for(l=1; l<=(period); l++){
                fprintf(rot, "------------------");
            }

        }

    }
    fclose(rot);

    printf("\nThis Final Routine Can be Found on '%s' file on the same directory as this exe file", routine_name);

    printf("\nPress Any Key To Exit: ");
    getche();

    return routine_name;
}

void delayfr(float sec) 
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

void trim(char * str)
{
    int index, i;

    index = -1, i = 0;

    while(str[i] != '\0'){ //Finds the End Index of Non-White Space
    
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n'){
            index= i;
        }

        i++;
    }

    str[index + 1] = '\0'; //Mark the 
}