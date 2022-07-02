#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

void delay(float sec);

int period, wd, sd, ed;
int i, j, per, pert, d, n, no, t, k, w, l, flag = 0;
int solve, soln, error;
char ch = ' ';
char str[2] = " ";

char days[6][3] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri"};

int main(){

    day_select:
    printf("\nIf:\n\n1-Sunday\n2-Monday\n3-Tuesday\n4-Wednesday\n5-Thursday\n6-Friday\n7-Saturday");
    printf ("\n\nChoose a starting day and a ending day for routine\n");
    printf("\nNOTES:\nA> Choose Start and End Day, EG: 1 & 6 For Sunday to Friday\nB> For Only 1 Day routine Enter the same number (eg 1 & 1)");
    printf("\nc> Descending order is not allowed: eg; 7 - 1 (i.e. Sat to Sun is prohibitted)");
    printf("\n\nChoose Start Day: ");
    scanf("%d", &sd);
    printf("Choose End Day: ");
    scanf("%d", &ed);
    wd = (ed - sd);

    if(sd<1 || ed>7){
        printf("Error! Out of Range\n");
        goto day_select;
    }
    if(wd<0){
        printf("Error! Wrong Format\n");
        goto day_select;
    }
    wd = (ed-sd)+1;

    printf ("Enter the number of periods: ");
    scanf ("%d", &period);

    printf ("How many Routines?: ");
    scanf("%d", &no);

    int ts = period*wd;

    char sub[no][ts][11];

    char faculty[no][10];

    /** Getting The Input**/
    for(t=0; t<no; t++){
        printf("\nFor which Faculty?(Max 10 letters): ");
        scanf ("%s", &faculty[t]);
        
        for(i=0; i<wd; i++){
            n = i;
            per = (n*period);
            pert = ((n+1)*period);
            d = 0;
            
            for (j=per; j<pert; j++){
                d += 1;
                printf ("Subject for %.3sday period %d: ", days[i], d);
                scanf ("%s", &sub[t][j]);
            }

            printf("\n");
        }

    }

    /* Printing Section */
    for(t=0; t<no; t++){
        printf ("\nRoutine For %s\n", faculty[t]);
        printf ("\nD/P\t");

        for(i=1; i<=period; i++){
            printf ("%d\t", i);
        }
        printf ("\n");

        for(i=0; i<wd; i++){
            n = i;
            printf("%.3s\t", days[i]);

            per = (n*period);
            pert = ((n+1)*period);
        
            for (j=per; j<pert; j++){
                printf("%s\t", sub[t][j]);
            }
            printf ("\n");
        }
    }
    
    /* collison section */
    do{ 
        error = 0;
        for (t=0; t<(no-1); t++){
            for(i=0; i<wd; i++){
                n = i;
                per = (n*period);
                pert = ((n+1)*period);
                d = 0;

                for (j=per; j<pert; j++){
                    d += 1;
                    w = (t+1);
                    for (k=w; k<no; k++){
                        if (strcmp(sub[t][j], sub[k][j]) == 0){
                            printf ("\nCollision noticed on %sday period %d on %s & %s ", days[i], d, faculty[t], faculty[k]);
                            printf ("(%s = %s)", sub[t][j], sub[k][j]);

                            error = 1;
                            flag = 1;
                            solve_part:
                            printf ("\nSolve it?\n1-YES\n2-NO\n");
                            scanf("%d", &solve);

                            if (solve == 1){
                                soln_part:
                                printf ("Make changes to:\n1-%s\n2-%s\n", faculty[t], faculty[k]);
                                scanf("%d", &soln);

                                if(soln == 1){
                                    printf ("%s Faculty %sday period %d: ", faculty[t], days[i], d);
                                    scanf("%s", sub[t][j]);
                                }

                                else if (soln == 2){
                                    printf ("%s Faculty %sday period %d: ", faculty[k], days[i], d);
                                    scanf("%s", sub[k][j]);
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
                                printf ("Invalid Entery!!");
                                delay(1);
                                goto solve_part;
                            }
                        }
                    }
                }
            }
        }
    }while (error == 1);
    
    if (flag == 1){
        printf ("\n\nYour Final Routine:");
        for(t=0; t<no; t++){
            printf ("\nRoutine For %s\n", faculty[t]);
            printf ("\nD/P\t");

            for(i=1; i<=period; i++){
                printf ("%d\t", i);
            }
            printf ("\n");

            for(i=0; i<wd; i++){
                n = i;
                printf("%.3s\t", days[i]);

                per = (n*period);
                pert = ((n+1)*period);
            
                for (j=per; j<pert; j++){
                    printf("%s\t", sub[t][j]);
                }
                printf ("\n");
            }
        }
    }

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
}


