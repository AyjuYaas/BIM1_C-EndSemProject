#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

void delay(float sec);
void trim(char * str);

int main(){

    system("cls");
/****************** INITIALIZATION 1 ************************/

    int no; 
    char days[7][3] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int period;
    int t, i=0, j, d, n, l, op, lp1;
    int per, pert;

/************* DAY SELECT ******************/

    day_select:
    int ed, sd, td;
    printf("\nIf:\n\n1 = Sunday\n2 = Monday\n3 = Tuesday\n4 = Wednesday\n5 = Thursday\n6 = Friday\n7 = Saturday");
    printf ("\n\nChoose a starting day and a ending day for routine\n");
    printf("\nNOTES:\nA> Choose Start and End Day, EG: 1 & 6 For Sunday to Friday\nB> For Only 1 Day routine Enter the same number (eg 1 & 1)");
    printf("\nc> Descending order is not allowed: eg; 7 - 1 (i.e. Sat to Sun is prohibitted)");
    printf("\n\nChoose Start Day: ");
    scanf("%d%*c", &sd);

    if(sd<1 || sd>7){
        getchar();
        printf("\nError! Out of Range Value!");
        delay(1);
        system("cls");
        goto day_select;
    }

    re:
    printf("\nChoose End Day: ");
    scanf("%d%*c", &ed);

    if(ed<1 || ed>7){
        getchar();
        printf("\nError! Out of Range Value!");
        delay(0.6);
        goto re;
    }

    td = (ed - sd);

    if(td<0){
        printf("Error! Wrong Format\n");
        delay(1);
        system("cls");
        goto day_select;
    }
    td = (ed-sd)+1;

/********** INITIALIZATION 2 ***************/

    printf("\nEnter the Total Number of Periods(In a Day): ");
    scanf("%d%*c", &period);

    printf("\nNumber of Routines You Want to Make: ");
    scanf("%d%*c", &no);

    char fac[no][15];

    char ch1[11] = ">        ";

    int tp = (td*period);
    
    char sub[no][tp][14];
    char error_sub[no][tp][15];

    system("cls");

/********** ROUTINE MAKING ************/
    for(t=0; t<no; t++){
 
        printf("\nRoutine no. %d\nGrade/Faculty for this Routine: ", (t+1));
        scanf("%[^\n]%*c", fac[t]);
        strupr(fac[t]);

        for(i=0; i<tp; i++){
            sub[t][i][14] = '\0';
        }

        system("cls");

        for(op=0; op<tp; op++){
            lp1 = (sd-1);
            printf("Routine no. %d\n", (t+1));
            printf("Grade/Faculty = %s\n", fac[t]);
            strcpy(sub[t][op], ch1);

            for(i=0; i<td; i++){
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
                    printf ("| %-15.14s ", sub[t][j]);
                }

                printf ("|\n");

                printf("----------");
                for(l=1; l<=(period); l++){
                    printf("------------------");
                }

            }

            printf("\nEnter the subject In Place '>'[Max 14 letters (including space)]:\n");
            
            fgets(sub[t][op], 14, stdin);
            if(t == 0 && op == 0)
                getchar();
            trim(sub[t][op]);
            strupr(sub[t][op]);
            system("cls");
        }

        system("cls");
    }
    
/******** Collison Detactor *******/

    for(t=0; t<no; t++){
        for(i=0; i<tp; i++){
            strcpy(error_sub[t][i], sub[t][i]);
        }
    }

    int flag = 0;
    int k, w;
    char es = '*', res;

    for (t=0; t<(no-1); t++){
        for(i=0; i<td; i++){
            n = i;
            per = (n*period);
            pert = ((n+1)*period);
            d = 0;

            for (j=per; j<pert; j++){
                d += 1;
                w = (t+1);
                for (k=w; k<no; k++){
                    if (strcmp(error_sub[t][j], error_sub[k][j]) == 0){
                        strncat (error_sub[t][j], &es, 1);
                        strncat (error_sub[k][j], &es, 1);
                        flag++;
                    }
                }
            }
        }
    }

/****** Showing Errors ******/
    if(flag != 0){

        for(t=0; t<no; t++){
            printf("\n\n");

            lp1 = (sd-1);
            printf("Routine no. %d\n", (t+1));
            printf("Faculty = %s\n", fac[t]);

            for(i=0; i<td; i++){
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
                    printf ("| %-16.15s", error_sub[t][j]);
                }

                printf ("|\n");

                printf("----------");
                for(l=1; l<=(period); l++){
                    printf("------------------");
                }

            }

        }

        solve_q:
        printf ("\n%d collisions Detected In Subjects Marked '#'\nWant to Solve?(Y/N): ", flag);
        scanf("%c", &res);
        res = toupper(res);
        if(res == 'Y')
            goto solve;
        
        else if (res == 'N')
            goto final_print;

        else{
            printf("\nError, Wrong Response: ");
            delay(1);
            goto solve_q;
        }

    }

/***** Collison Solver *****/
    solve:
    int error, solve, soln;
    char ch = ' ';
    do{ 
        error = 0;
        for (t=0; t<(no-1); t++){
            for(i=0; i<td; i++){
                n = i;
                per = (n*period);
                pert = ((n+1)*period);
                d = 0;

                for (j=per; j<pert; j++){
                    d += 1;
                    w = (t+1);
                    for (k=w; k<no; k++){
                        if (strcmp(sub[t][j], sub[k][j]) == 0){
                            printf ("\nCollision on %.3sday period %d on %s & %s ", days[i], d, fac[t], fac[k]);
                            printf ("(%s = %s)", sub[t][j], sub[k][j]);

                            error = 1;
                            flag = 1;
                            solve_part:
                            printf ("\nSolve it?\n1-YES\n2-NO\n");
                            scanf("%d", &solve);

                            if (solve == 1){
                                soln_part:
                                printf ("\nMake changes to:\n1-%s\n2-%s\n", fac[t], fac[k]);
                                scanf("%d", &soln);

                                if(soln == 1){
                                    printf ("%s Faculty %s period %d: ", fac[t], days[i], d);
                                    scanf("%s", sub[t][j]);
                                    strupr(sub[t][j]);
                                }

                                else if (soln == 2){
                                    printf ("%s Faculty %sday period %d: ", fac[k], days[i], d);
                                    scanf("%s", sub[k][j]);
                                    strupr(sub[k][j]);
                                }

                                else{
                                    printf ("\nInvalid Entry!!");
                                    delay(1);
                                    goto soln_part;
                                }
                            }

                            else if (solve == 2){
                                strncat(sub[k][j], &ch, 1);
                            }

                            else{
                                printf ("Invalid Entry!!");
                                delay(1);
                                goto solve_part;
                            }
                        }
                    }
                }
            }
        }
    }while (error == 1);

/****** THE FINAL OUTPUT ******/
    final_print:
    printf("\nThe Final Routine/s: ");
    for(t=0; t<no; t++){
        printf("\n\n");

        lp1 = (sd-1);
        printf("Routine no. %d\n", (t+1));
        printf("Faculty = %s\n", fac[t]);

        for(i=0; i<td; i++){
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
                printf ("| %-16.15s", sub[t][j]);
            }

            printf ("|\n");

            printf("----------");
            for(l=1; l<=(period); l++){
                printf("------------------");
            }

        }

    }
    
/**** FIlE PRINTING ****/
    FILE *rot = fopen("routine.txt", "w+");

    for(t=0; t<no; t++){
        if(t!=0){
            fprintf(rot, "\n\n");
        }
        
        lp1 = (sd-1);
        fprintf(rot, "%s\n", fac[t]);

        for(i=0; i<td; i++){
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
                fprintf (rot, "| %-16.15s", sub[t][j]);
            }

            fprintf (rot, "|\n");

            fprintf(rot, "----------");
            for(l=1; l<=(period); l++){
                fprintf(rot, "------------------");
            }

        }

    }
    fclose(rot);

    printf("\nThis Final Routine Can be Found on 'routine.txt' file on the same directory as this exe file");

    printf("\nPress Any Key To Exit: ");
    getche();

    return 0;
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

void trim(char * str)
{
    int index, i;

    /* Set default index */
    index = -1;

    /* Find last index of non-white space character */
    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            index= i;
        }

        i++;
    }

    /* Mark next character to last non-white space character as NULL */
    str[index + 1] = '\0';
}
