#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

struct teacher{
    int id;
    char name[20];
    char gender;
    int doby;
    int dobm;
    int dobd;
    char subject[20];
    char u[20];
    char p[20];
}tea,teach;

void teacher_screen();
void signIn();
void signup();
void homepage();
void delay(float);
int main()
{
	teacher_screen();
	return 0;
}
	
void teacher_screen()
{
	int i,ch;
	
	system("cls");
	  //loading part
	printf("Loading");
	for(i=0; i<5; i++)
	{
		printf(".");
	    delay(0.2);
	}
	system("cls");
	
	//choosing part
	redo:
	printf("Welcome To Teacher's Login Page\n\n");
	printf("\t[1] SignUp\n");
	printf("\t[2] SignIn\n\n");
	printf("Choose: ");
	scanf("%d%*c", &ch);
	switch(ch)
	{
	case 1:
	signup();
	break;
	case 2:
	signIn();
	break;
	default:
	printf("Wrong Entry!!!");
	        delay(0.6);
	        system("cls");
	        goto redo;
	}
	system("cls");
}

void signup()
{
//for details
	printf("Id:");
	scanf("%d%*c",&tea.id);
	printf("Name:");
	scanf("%s%*c",&tea.name);
	printf("Gender:");
	scanf("%c%*c",&tea.gender);
	printf("DOB:");
	scanf("%d",&tea.doby);
	scanf("%d",&tea.dobm);
	scanf("%d*c",&tea.dobd);
	printf("Subject:");
	scanf("%s",&tea.subject);
//for username and password
	FILE *tcheck;
	tcheck = fopen("teacher.dat", "r");
	printf("NOTE: Username Shouldn't contain any space, 5 - 10 Character\n\n");
	redo1:
	printf("Username:");
	scanf("%s%*c",&tea.u);
	teach.u[10] = '\0';
	teach.p[15] = '\0';
	while (fscanf(tcheck,"%s %s\n",&teach.u,&teach.p)!= EOF)
	{
		if (strcmp(tea.u,teach.u) == 0)
		{
		    printf("\nUsername Already Taken!!!");
		    printf("\nTry Again with Another USERNAME");
		    delay(1);
		    system("cls");
		    rewind(tcheck);
		    goto redo1;
		}
	}
	
	redo3:
	printf("\nPassword Must Be Between 5 And 15 Character");
	printf("\nEnter Password: ");
	scanf("%s%*c",&tea.p);
	if (strlen(tea.p)<5)
	{
	    printf("\nPassword too Short, Try Again!!!");
	    delay(1);
	    goto redo3;
	}
	fclose(tcheck);
	
	FILE *p;
	p = fopen("teacher.dat", "a+");
	fprintf(p, "%s %s\n",tea.u,tea.p);
	fclose(p);
	   
	FILE *fp;
	fp=fopen("tdetails.dat","a+");
	fprintf(fp,"%s %s %d %s %c %.2d%.2d%.4d %s",tea.u,tea.p,tea.id,tea.name,tea.gender,tea.doby,tea.dobm,tea.dobd,tea.subject);
	fclose(fp);
	teacher_screen();
	
}

void signIn()
{
	printf("\nWelcome to Teacher Login\n");
	redo4:
	printf("Username:");
	scanf("%s%*c",&teach.u);
	printf("Password:");
	scanf("%s%*c",&teach.p);
	int flag = 0;
	FILE *up;
	up=fopen("teacher.dat","r");
	while(fscanf(up,"%s %s\n",&tea.u,&tea.p)!= EOF)
	{
        if(strcmp(teach.u,tea.u)==0 && strcmp(teach.p,tea.p)==0)
		{
           homepage();
	}
    }
	if(flag==0){
		printf("Wrong Username/password!!\nTry Again!!\n);
		goto signIn();
	}
    fclose(up);
}
void homepage()
{
	int x;
	printf("1.Personal Info\n2.Routine ");
	printf("Choose:");
	scanf("%d",&n);
	switch(x)
	{
		case 1:
			//viwpersonalinfo
			break;
		case 2:
			//viewroutine
			break;
	}

}
void delay(float sec)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * sec;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);

    /* This Piece of code Was Taken from stackoverflow.com */
}