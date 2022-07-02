#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

/****************** INITIALIZATION 1 ************************/
    int no, ts, ed, sd, td; 
    char days[7][3] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int period;
    int t, i=0, j, d, n, l, op, lp1;
    int per, pert;
    char faculty[11];

/************* DAY SELECT ******************/
    day_select:
    printf("\nIf:\n\n1-Sunday\n2-Monday\n3-Tuesday\n4-Wednesday\n5-Thursday\n6-Friday\n7-Saturday");
    printf ("\n\nChoose a starting day and a ending day for routine\n");
    printf("\nNOTES:\nA> Choose Start and End Day, EG: 1 & 6 For Sunday to Friday\nB> For Only 1 Day routine Enter the same number (eg 1 & 1)");
    printf("\nc> Descending order is not allowed: eg; 7 - 1 (i.e. Sat to Sun is prohibitted)");
    printf("\n\nChoose Start Day: ");
    scanf("%d", &sd);
    printf("Choose End Day: ");
    scanf("%d", &ed);
    td = (ed - sd);

    if(sd<1 || ed>7){
        printf("Error! Out of Range\n");
        goto day_select;
    }
    if(td<0){
        printf("Error! Wrong Format\n");
        goto day_select;
    }
    td = (ed-sd)+1;

/********** INITIALIZATION 2 *******************/
    printf("\nEnter Number of Periods In a Day: ");
    scanf("%d%*c", &period);

    char ch = ' ', ch1[11] = ">        ";
    int tp = (td*period);
    
    char sub[(tp-1)][16];

    for(i=0; i<tp; i++){
        sub[i][16] = '\0';
    }

/********** ROUTINE MAKING ************/
    op = 0;
    while(op < tp){
        lp1 = (sd-1);
        printf("Faculty = BIM\n");
        strcpy(sub[op], ch1);
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
                printf ("| %-16.15s", sub[j]);
            }

            printf ("|\n");

            printf("----------");
            for(l=1; l<=(period); l++){
                printf("------------------");
            }

        }

        printf("\nEnter the subject (Max 15 letters) (In position of Pointer '>'):\n");
        scanf("%[^\n]%*c", sub[op]);
        strupr(sub[op]);
        op += 1;
        system("cls");
    }
    
/******* FINAL ROUTINE ********/
    lp1 = (sd-1);
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
                printf ("| %-16.15s", sub[j]);
            }

            printf ("|\n");

            printf("----------");
            for(l=1; l<=(period); l++){
                printf("------------------");
            }

        }
    
    return 0;
}

