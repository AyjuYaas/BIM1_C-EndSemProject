#include<stdio.h>
#include<stdbool.h>

void time_frame(int h, int m, int p, int d);

int main(){

/****************** Initialization ********************/
    int j, line, duration, period, hourp, minutesp;
    float StartTime;
    char date[100], subjects[100];
/*#################################################################*/

/**************** Value Get *************************/
    printf ("Create a Class routine:\n");

    printf ("Use 24-hours TIme format\n");

    printf ("Enter class start time (hh.mm): ");
    scanf ("%f", &StartTime);
    hourp = StartTime;
    int m1 = (StartTime*100);
    minutesp = m1%100;

    printf ("Duration for each subject (in minutes): ");
    scanf ("%d", &duration);

    printf ("Enter no of periods: ");
    scanf ("%d", &period);
/*####################################################################*/
    
    printf ("\n");

/*************** The Time Frame ********************/
    printf ("Time:\t");
    time_frame (hourp, minutesp, period, duration); // calling time
/*####################################################################*/

/************* EXIT PORTION ************************/
    printf ("\nEnter any key to exit...");
    char exit = getche();
    
    return 0;
}

void time_frame(int h, int m, int p, int d){
    int i, a, rem;
    for (i = 1; i <= p; i++){
        if (h>=24){
            h -= 24;
        }
        printf ("%02d:%02d\t", h, m);
        
        do{
            if ((m + d) < 60){
                m += d;
            }

            else{
                a = 60 - m;
                h += 1;
                rem = d - a;

                if (rem>59){
                    m = 0;
                    continue;
                }
                else{
                    m = rem;
                    break;
                }            
            }
        }while (true);
    }
}