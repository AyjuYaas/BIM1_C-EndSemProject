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
	scanf("%c",&tea.gender);
	printf("DOB:");
	scanf("%d",&tea.doby);
	scanf("%d",&tea.dobm);
	scanf("%d%*c",&tea.dobd);
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
	fprintf(fp,"%s %s %d %s %c %d%d%d %s\n",tea.u,tea.p,tea.id,tea.name,tea.gender,tea.doby,tea.dobm,tea.dobd,tea.subject);
	fclose(fp);
	teacher_screen();
	
}

void signIn()
{
	FILE *up;
	int flag=0;
	redo4:
	printf("\nWelcome to Teacher Login\n");
	printf("Username:");
	scanf("%s%*c",&teach.u);
	printf("Password:");
	scanf("%s%*c",&teach.p);
	up=fopen("teacher.dat","r");
	while(fscanf(up,"%s %s\n",&tea.u,&tea.p)!= EOF)
	{
        if(strcmp(teach.u,tea.u)==0 && strcmp(teach.p,tea.p)==0)
		{
			flag==1;
           homepage();
           
        }
        
		
    }
    if(flag==0)
    	{
	    	printf("Wrong username or password!!\nRetry!!");
	        delay(1);
	        rewind(up);
	        goto redo4;
		}
    fclose(up);
}
void homepage()
{
	int choose;
	success:
	printf("Welcome!!!%s\n",teach.u);

	printf("Choose:\n");
	printf("1.View Personal Details\n2.ViewRoutine\n3.Logout");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
    	system("cls");
    	FILE *dfp;
    	dfp=fopen("tdetails.dat","r+");
		while(fscanf(dfp,"%s %s %d %s %c %d%d%d %s\n",&tea.u,&tea.p,&tea.id,&tea.name,&tea.gender,&tea.doby,&tea.dobm,&tea.dobd,&tea.subject) != EOF)
		{
        	if(strcmp(tea.u,teach.u) == 0)
			{
				printf("Your Details\n");
	            printf("Username: %s\n",tea.u);
	            printf("Password: %s\n",tea.p);
	            printf("ID: %d\n",tea.id);
	            printf("Name: %s\n",tea.name);
	            printf("Gender: %c\n",tea.gender);
	            printf("DOB: %d/%d/%d\n",tea.doby,tea.dobm,tea.dobd);
	            printf("Subject: %s\n",tea.subject);
	            
        	}
        	int choose1;
        	success1:
        	printf("Press:\n1.Back\n");
        	
        	scanf("%d",&choose1);
        	if(choose1==1)
        	{
        		system("cls");
        		rewind(dfp);
        		goto success;
			}
			goto success1;
    	}
    	fclose(dfp);
    	break;
    	
		case 2:
    		printf("Routine here!!");//sayujya yeta halnus la daju pls
    		int choose2;
        	success2:
        	printf("Press:\n1.Back\n");
        	scanf("%d",&choose2);
        	if(choose2==1)
        	{
        		system("cls");
        		goto success;
			}
			goto success2;
    		break;
    		
        case 3:
        	system("cls");
			signIn();
			break;	
    	default:
    		printf("Wrong Input!!");
    		goto success;
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
