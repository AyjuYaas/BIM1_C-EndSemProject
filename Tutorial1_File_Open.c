/* FILE OPEN TUTORIAL */

#include<stdio.h>

int main(){
    
    FILE *fp;

    char ch = 'a';

    char str[50] = "Sayujya Satyal";

    fp = fopen("tutorial.txt", "a+");

    fputc (ch, fp);
    fprintf (fp, "\n");
    fputs (str, fp);

    fclose(fp);

    return 0;
}