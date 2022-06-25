#include<stdio.h>
#include<string.h>
int main(){

    int i, j, l, p, d, k=0;
    
    char days[6][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri"};

    printf ("\nEnter the no. of periods: ");
    scanf ("%d", &p);

    int a[1][p];
    
    
        printf ("\nEnter the period code for %s\n", days + 0);
        for (j=0; j<p; j++){
            printf ("%d. ", j+1);
            scanf ("%d", &a[0][j]);
        }

    printf ("%s\t", days + 0);
    for (i=0; i<p; i++){
        printf ("%d\t", a[0][i]);
    }

    return 0;



}