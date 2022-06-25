#include<stdio.h>
#include<stdlib.h>

int main(){
    
    char eos;

    struct Dates{
        int dob_y;
        int dob_m; 
        int dob_d;

        int reg_y;
        int reg_m;
        int reg_d;
    } Dates;

    struct data{
        char fname[50];
        char lname[50];
        char Address[50];
        long long int citizenID;
    } details;

    FILE *fp;
    FILE *rd;
 
    printf ("1 for entry, 2 for search: ");
    eos = getche();

    if (eos=='1'){

        printf ("\nEnter ypur name: ");
        gets(details.name);

        printf ("\nEnter your DOB: (mm-dd-yyyy): ");
        scanf ("%d-%d-%d",&details.dob_m, &details.dob_d, &details.dob_y);

        fp = fopen("record.txt", "w");

        fprintf (fp, "%s %d%d%d\n", details.name, details.dob_m, details.dob_d, details.dob_y);

        fclose(fp);
    }

    else{
        char search[50];
        
        printf ("\nEnter the name to be searched: ");
        gets(search);

        rd = fopen("record.txt", "r");

        int count = 0;

        while (fscanf (rd, "%s %d%d%d", &details.name, &details.dob_m, &details.dob_d, &details.dob_y, rd) != EOF){
            
            if (strcmp(details.name, search) == 0){
                count = 1;
            }
        }

        if (count == 1){
            printf ("found");
        }

        else
            printf("Not found");

        fclose(rd);
        
    }

    return 0;
}