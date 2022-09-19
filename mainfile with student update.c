#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include"designers_info.h"
#include"routine.h"
#include<windows.h>

void title_screen();
void delay(float);
void dep_reg_screen();
void department_Lscreen();
void department_screen();
int routine_view(char dep101[]);
int edit_dep_record(char u_name[]);
void secret_tab();
void teacher_screen();
void signIn();
void signup();
void homepage(char t_u_name[]);
void student_signup();
void student_screen();
void student_login(char s_user[]);
int edit_student_details(char stu_user[]);
int change_dep_p(char username[]);

void draw_line(){ 
    int rows, columns;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int i;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    for(i=0; i<columns; i++){
        printf("#");
    }
}

struct dep_details{
    char username[10];
    char password[15];
    char dep_name[40];
    int em, ed, ey;
    char university[40];
    char hod[20];
}dep, depch, depch1; //All these variable names can be used for above variables

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

struct student{
    int roll;
    char name[30];
    char gender;
    int doby, dobm, dobd;
    char user[20];
    char pass[20];
    char dep[20];
    char faculty[20];
}st,stu;

int main(){

    title_screen();

    return 0;

}

void title_screen(){
    system("cls");
    
    int choice;
    printf ("\n\n\tWELCOME TO *** LOGIN PAGE\n\n");
    printf ("Please Choose from the following options\n\n");
    printf ("\t[1] Teacher Login\n");
    printf ("\t[2] Student Login\n");
    printf ("\t[3] Department login\n");
    printf ("\t[4] Developers Info\n");
    printf ("\t[5] Exit\n");
    printf ("\n\nYour Choice: ");
    scanf ("%d", &choice);
    fflush(stdin);

    switch (choice) {
        case 1:
            teacher_screen();
            break;

        case 2:
            student_screen();
            break;

        case 3:
            department_Lscreen();
            break;

        case 4:
            animation();
            delay(0.5);
            title_screen();
            break;

        case 5:
            exit(1);
            break;
            
        case 32715:
            secret_tab();
            break;

        default:
            printf ("Invalid entry");
            delay(1);
            title_screen();
    }

}

void secret_tab(){
    int i, choose, stu_c, number_of_students;

    system("cls");
  /** LOADING SCREEN **/
    printf("Restricted Area Loading");
    for(i=0; i<4; i++){
        printf(".");
        delay(0.2);
    }
    system("cls");

  /** CHOOSING SCREEN **/
    dep_create_choose:
    printf("\n\nWelcome To Team M. Creation Page\n\n");
    printf("\t[1] Add a New Department\n");
    printf("\t[2] Create a Teacher Account\n");
    printf("\t[3] Create a Student Account\n");
    printf("\t[4] Exit to Main Screen\n\n");
    printf("Choose: ");
    scanf("%d", &choose);
    fflush(stdin);

    if(choose == 1){
        dep_reg_screen();
    }
    if (choose == 4){
        title_screen();
    }    
    else if (choose == 2){
        FILE *dep_exist1 = fopen("DUP.dat", "rb");
        if(dep_exist1 == NULL){
            printf("\n\nCannot Find Any Department!! Create a Department 1st");
            delay(1.5);
            secret_tab();
        }
        fclose(dep_exist1);
        system("cls");
        signup();
    }
    else if(choose == 3){
        FILE *dep_exist = fopen("DUP.dat", "rb");
        if(dep_exist == NULL){
            printf("\n\nCannot Find Any Department!! Create a Department 1st");
            delay(1.5);
            secret_tab();
        }
        fclose(dep_exist);
        system("cls");
        printf("\n\t\tSTUDENT ACCOUNT CREATION");
        printf("\n\n[1] Add a Single Sudent\n[2] Add Bulk Students");
        printf("\nChoose: "); scanf("%d", &stu_c); fflush(stdin);
        if(stu_c == 1){
            system("cls");
            student_signup();
        }
        else if(stu_c == 2){
            printf("Enter Number of Student Data to be Entered: ");
            scanf("%d", &number_of_students);
            fflush(stdin);
            for(i = 0; i<number_of_students; i++){
                system("cls");
                printf("\n\t\tDETAILS OF STUDENT no. %d\n", i+1);
                draw_line();
                printf("\n");
                student_signup();
            }
        }
        secret_tab();
        
    }
    else if (choose != 1){
        printf("Wrong Entry!!!");
        delay(0.6);
        system("cls");
        goto dep_create_choose;
    }

    system("cls");

}

void student_signup(){
    //for username and password

    FILE *s_check;
	s_check = fopen("student.dat", "r");
    redo_student_username:
    printf("\n\n\t\tCreate a Username and Password");
	printf("\nNOTE: Username Shouldn't contain any space, 5 - 10 Character\n");
    printf("\nWARNING!! Username CANNOT BE CHANGED once created\n\n");
	printf("Username: ");
	scanf("%s%*c",&st.user);
    fflush(stdin);

    if(strlen(st.user) < 5 || strlen(st.user)>10){
        printf("\nUsername Length Not According to Instructions\n");
        printf("Try Again!!");
        goto redo_student_username;
    }

	stu.user[10] = '\0';
	stu.pass[15] = '\0';
    int i = 0;
	while (fscanf(s_check,"%s %s\n",&stu.user,&stu.pass)!= EOF)
	{
		if (strcmp(st.user,stu.user) == 0)
		{
		    printf("\nUsername Already Taken!!!");
		    printf("\nTry Again with Another USERNAME\n\n");
		    delay(1);
		    system("cls");
		    rewind(s_check);
		    goto redo_student_username;
		}
	
    }
	redo_student_password:
	printf("\nPassword Must Be Between 5 And 15 Character");
	printf("\nEnter Password: ");
	scanf("%s%*c",&st.pass);
    fflush(stdin);

	if (strlen(st.pass)<5 || strlen(st.pass) > 15)
	{
	    printf("\nPassword Length Doesn't Match Instructions, Try Again!!!");
	    delay(1);
	    goto redo_student_password;
	}
	fclose(s_check);

//for details
    printf("\n\nFill up the Additional Details\n");
	printf("\nRoll no: ");
	scanf("%d%*c",&st.roll);
    fflush(stdin);
	printf("\nName: ");
	scanf("%[^\n]%*c",&st.name);
    fflush(stdin);
	printf("\nGender (M/F/O): ");
	scanf("%c",&st.gender);
    fflush(stdin);
	printf("\nDOB (yyyy/mm/dd): ");
	scanf("%d/%d/%d",&st.doby, &st.dobm, &st.dobd);
    fflush(stdin);
	printf("\nChoose Department:\n");
    FILE *choose_sf = fopen("DUP.dat", "rb");
    int choice, count = 1;
    //while((fscanf(choose_sf, "%[^|]|%[^|]|%d/%d/%d|%[^|]|%[^\n]\n", &depch1.username, &depch1.dep_name, &depch1.em, &depch1.ed, &depch1.ey, &depch1.university, &depch1.hod)) != EOF){
    while(fread(&depch1, sizeof(struct dep_details),1, choose_sf)){
        printf("[%d] %s\n", count, depch1.dep_name);
        count++;
    }
	scanf("%d", &choice);
    fflush(stdin);
    count = 1;
    rewind(choose_sf);
    //while((fscanf(choose_sf, "%[^|]|%[^|]|%d/%d/%d|%[^|]|%[^\n]\n", &depch1.username, &depch1.dep_name, &depch1.em, &depch1.ed, &depch1.ey, &depch1.university, &depch1.hod)) != EOF){
    while(fread(&depch1, sizeof(struct dep_details),1, choose_sf)){
        if(choice == count){
            break;
        }
        count++;
    }
    fclose(choose_sf);
	printf("\nEnter Faculty: ");
    scanf("%[^\n]", &st.faculty);
    fflush(stdin);
    FILE *p;
	p = fopen("student.dat", "a");
	fprintf(p, "%s %s\n",st.user,st.pass);
    fclose(p);

	FILE *fp;
	fp=fopen("stu_details.dat","a+");
	fprintf(fp,"%s|%d|%s|%c|%d/%d/%d|%s|%s\n",st.user,st.roll,st.name,st.gender,st.doby,st.dobm,st.dobd,depch1.dep_name, st.faculty);
	fclose(fp);
}

void student_screen(){
    char s_username[30], s_password[30];
    int flag = 0, choice;
    system("cls");
    printf("\n\n\tWelcome to Student Login Page");
    printf("\n\nEnter Username: ");
    scanf("%s%*c", s_username);
    fflush(stdin);
    printf("\nEnter Password: ");
    scanf("%s%*c", s_password);
    fflush(stdin);

    FILE *login_check;
    login_check = fopen("student.dat", "r");
    while(fscanf(login_check, "%s %s\n", stu.user, stu.pass) != EOF){
        if(strcmp(s_username, stu.user)==0 && strcmp(s_password, stu.pass)==0){
            flag = 1;
            system("cls");
            student_login(s_username);      
        } 
    }
    if(flag == 0){
        printf("\n\nUsername/Password Incorrect!!!\n");
        redo_stu:
        printf("[1] Try Again?\n");
        printf("[2] Main Menu\n");
        printf("[3] Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        fflush(stdin);

        if(choice == 1){
            student_screen();
        }
        else if(choice == 2){
            fclose(login_check);
            title_screen();
        }
        else if(choice == 3){
            fclose(login_check);
            exit(2);
        }
        else{
            printf("Wrong Entry!!");
            printf("Enter Correctly!!");
            delay(1);
            goto redo_stu;  
        }
        
    } 
}

void student_login(char s_user[]){
    system("cls");
    FILE *fp,*dep_view;
    FILE *details_check;
    fp = fopen("stu_details.dat", "r");
    while(fscanf(fp,"%[^|]|%d|%[^|]|%c|%d/%d/%d|%[^|]|%[^\n]\n", &st.user,&st.roll,&st.name,&st.gender,&st.doby,&st.dobm,&st.dobd, &st.dep, &st.faculty)!=EOF){
        if(strcmp(st.user, s_user)==0){
            break;
        }
    }
    printf("\n\n\tWelcome %s", st.name);
    fclose(fp);
    int choose = 0;
    printf("\nChoose from The Following Options:\n");
    printf("\n\t[1] View Details");
    printf("\n\t[2] View Routine");
    printf("\n\t[3] View Assignments");
    printf("\n\t[4] Edit Details");
    printf("\n\t[5] Logout");
    printf("\n\t[6] Exit");
    printf("\n\nYour Choice: ");
    scanf("%d%*c", &choose);
    fflush(stdin);

    switch (choose)
    {
    case 1:
        system("cls");
        printf("\n\t\tYOUR DETAILS\n");
        printf("\n\tRoll Number: %d\n", st.roll);
        printf("\n\tStudent Name: %s\n", st.name);
        printf("\n\tDOB (yyyy/mm/dd): %d/%d/%d\n", st.doby, st.dobm, st.dobd);
        printf("\n\tGender: %c\n", st.gender);
        printf("\n\tDepartment: %s\n", st.dep);
        printf("\n\Faculty: %s\n", st.faculty);
        printf("\nPress Any Key to Go Back...\n");
        fflush(stdin);
        getche();
        student_login(s_user);
        break;

    case 2:
    	fflush(stdin);
        int r_v_check = routine_view(st.dep);
        student_login(s_user);
        break;
    
    case 3:
    		
    		printf("\n\Assignments for today:\n");
        	
			details_check= fopen("DUP.dat", "rb");
	    		while(fread(&depch1, sizeof(struct dep_details), 1, details_check))
				{
					
					if(strcmp(st.dep, depch1.dep_name)==0)
					{
						int name101[100];
						strcpy(name101,depch1.dep_name);
						strcat(name101, "assign");
		            	strcat(name101, ".txt");
			            FILE *assign_print = fopen(name101, "r");
			            char assign1[100];
			            while(fscanf(assign_print,"%[^\n]\n",&assign1)!=EOF)
			            {
			            	printf(assign_print,"%s\n", assign1);
						}
			            
			            fclose(assign_print);	
			            fclose(details_check);
			            rewind(details_check);
			        	system("pause");
			        	void student_login(char s_user[]);
					}
				}
		
			break;
           
    case 4:
        edit_student_details(s_user);
        student_login(s_user);
        break;

    case 5:
        title_screen();
        break;

    case 6:
        exit(3);
        break;
    
    default:
        printf("Wrong Entry!! Try Again!");
        system("cls");
        student_login(s_user);
    }
    
}

int edit_student_details(char stu_user[]){
    FILE *fp;
    fp = fopen("stu_details.dat", "r");
    while(fscanf(fp,"%[^|]|%d|%[^|]|%c|%d/%d/%d|%[^|]|%[^\n]\n", &st.user,&st.roll,&st.name,&st.gender,&st.doby,&st.dobm,&st.dobd,&st.dep, &st.faculty)!=EOF){
        if(strcmp(st.user, stu_user)==0){
            break;
        }
    }
    printf("\tWelcome %s", st.name);
    fclose(fp);

    re_choice:
    printf("\n\n******** Your Current Details ********\n");
    printf("\nRoll Number: %d", st.roll);
    printf("\n\nStudent Name: %s", st.name);
    printf("\n\nDOB (yyyy/mm/dd): %d/%d/%d", st.doby, st.dobm, st.dobd);
    printf("\n\nGender: %c", st.gender);
    printf("\n\nDepartment: %s", st.dep);
    printf("\n\nBatch Year: %s\n\n", st.faculty);
    fflush(stdin);
    
    draw_line();
    printf("\nSelect the Field You Want to Update:\n");
    printf("\n[1] Roll Number\n[2] Student Name\n[3] Date of Birth\n[4] Gender\n[5] Department\n[6] Batch Year\n[7] Go Back\n[8] Exit");
    printf("\n\nChoose: ");
    int editchoice;
    scanf("%d%*c", &editchoice);
    fflush(stdin);

    switch (editchoice){
        case 1:
        printf("\nEnter New Roll Number: ");
        scanf("%d%*c",&st.roll);
        fflush(stdin);
        break;
        
        case 2:
        printf("\nEnter New Name: ");
        gets(st.name);
        fflush(stdin);
        break;
        
        case 3:
        printf("\nEnter New DOB (yyyy/mm/dd): ");
        scanf("%d/%d/%d", &st.doby, &st.dobm, &st.dobd);
        fflush(stdin);
        break;

        case 4:
        printf("\nEnter New Gender: ");
        scanf("%c%*c", &st.gender);
        fflush(stdin);
        break;

        case 5:
        printf("\nChoose New Department:\n\n");
        FILE *choose_sf = fopen("DUP.dat", "rb");
        int choice, count = 1;
        //while((fscanf(choose_sf, "%[^|]|%[^|]|%d/%d/%d|%[^|]|%[^\n]\n", &depch1.username, &depch1.dep_name, &depch1.em, &depch1.ed, &depch1.ey, &depch1.university, &depch1.hod)) != EOF){
        while(fread(&depch1, sizeof(struct dep_details),1, choose_sf)){
            printf("[%d] %s\n", count, depch1.dep_name);
            count++;
        }
	    scanf("%d", &choice);
        fflush(stdin);
        count = 1;
        rewind(choose_sf);
        //while((fscanf(choose_sf, "%[^|]|%[^|]|%d/%d/%d|%[^|]|%[^\n]\n", &depch1.username, &depch1.dep_name, &depch1.em, &depch1.ed, &depch1.ey, &depch1.university, &depch1.hod)) != EOF){
        while(fread(&depch1, sizeof(struct dep_details),1, choose_sf)){
            if(choice == count){
                break;
            }
            count++;
        }
        fclose(choose_sf);
        strcpy(st.dep, depch1.dep_name);
        break;

        case 6:
        printf("\nEnter New Batch Year: ");
        scanf("%[^\n]", &st.faculty);
        fflush(stdin);
        break;

        case 7:
        return 0;

        case 8:
        exit(12);

        default:
        fflush(stdin);
        system("cls");
        goto re_choice;
    }

    FILE *nrf = fopen("new.dat", "w");
    FILE *prf1 = fopen("stu_details.dat", "r");

    while(fscanf(prf1, "%[^|]|%d|%[^|]|%c|%d/%d/%d|%[^|]|%[^\n]\n", &stu.user,&stu.roll,&stu.name,&stu.gender,&stu.doby,&stu.dobm,&stu.dobd,&stu.dep, &stu.faculty) != EOF){
        if(strcmp(stu.user, stu_user) == 0){
            fprintf(nrf,"%s|%d|%s|%c|%d/%d/%d|%s|%s\n",st.user,st.roll,st.name,st.gender,st.doby,st.dobm,st.dobd,st.dep, st.faculty);
        }
        else{
            fprintf(nrf,"%s|%d|%s|%c|%d/%d/%d|%s|%s\n",stu.user,stu.roll,stu.name,stu.gender,stu.doby,stu.dobm,stu.dobd,stu.dep, stu.faculty);
        }
    }
    fclose(nrf);
    fclose(prf1);

    remove("stu_details.dat");
    rename("new.dat", "stu_details.dat");
    printf("\n\nUpdate Successful!!");
    
    retry:
    fflush(stdin);
    int re_choose = 0;
    printf("\nMake Any More Changes?\n[1] Yes\n[2] No\n\nChoose: ");
    scanf("%d", &re_choose);
    fflush(stdin);

    switch(re_choose){
        case 1:
            edit_student_details(stu_user);
        case 2:
            return 0;
        default:
            goto retry;
    }
}

void dep_reg_screen(){
    
  /** Department Username Password **/
    system("cls");
    FILE *signup_check;
    signup_check = fopen("DUP.dat", "rb");
    int i;
    user:
    printf("\n\n\tDepartment Creation!!!\n\n");
    printf("NOTE: Username Shouldn't contain any space, 5 - 10 Character\n");
    printf("\nWARNING!! Username CANNOT BE CHANGED once created\n\n");
    printf("Create a Username for Department: ");
    scanf("%s%*c", &dep.username);
    fflush(stdin);

    if(strlen(dep.username) < 5 || strlen(dep.username) > 10){
        printf("\n\nUsername Length Mismaych Instructions");
        printf("\nTry Again!!");
        goto user;
    }
    depch.username[10] = '\0';
    depch.password[15] = '\0';

    //while (fscanf(signup_check, "%s %s\n", depch.username, depch.password) != EOF){
    while(fread(&depch, sizeof(struct dep_details), 1, signup_check)){
        if (strcmp(dep.username, depch.username) == 0){
            printf("\nUsername Already Taken!!!");
            printf("\nTry Again with Another USERNAME");
            delay(1);
            rewind(signup_check);
            goto user;
        }
    }

    pass:
    printf("\nPassword Must Be Between 5 And 15 Character");
    printf("\nCreate Password: ");
    scanf("%s%*c", dep.password);
    fflush(stdin);
    if (strlen(dep.password)<5 || strlen(dep.password)>15){
        printf("\nPassword Requirement Not Met, Try Again!!!");
        delay(1);
        goto pass;
    }
    fclose(signup_check);

    printf("\nAccount Created!!!");
    printf("\nFill Up The Remaining Details");

  /** DEPARTMENT FURTHER DETAILS **/
    printf("\n\nEnter the Name of Department: ");
    gets(dep.dep_name);
    fflush(stdin);
    
    printf("\nEnter the Established Date (In Format mm/dd/yyyy): ");
    scanf("%d/%d/%d", &dep.em, &dep.ed, &dep.ey);
    fflush(stdin);

    printf("\nEnter The Affiliated University: ");
    gets(dep.university);
    fflush(stdin);

    printf("\nEnter the name of HOD of the Dep: "); 
    gets(dep.hod);
    fflush(stdin);
    
    // FILE *un_pw_entry;
    // un_pw_entry = fopen("DUP.dat", "ab");
    // fprintf(un_pw_entry, "%s %s\n", dep.username, dep.password);
    // fclose(un_pw_entry);

    FILE *dep_data_entry;
    dep_data_entry = fopen("DUP.dat", "a+b");
    //fprintf (dep_data_entry, "%s|%s|%.2d/%.2d/%.4d|%s|%s\n", dep.username, dep.dep_name, dep.em, dep.ed, dep.ey, dep.university, dep.hod);
    fwrite(&dep, sizeof(struct dep_details), 1, dep_data_entry);
    fclose(dep_data_entry);

    printf("\nDepartment Account Created..");
    printf("\nReturning to Main Screen .");  
    for(i=0; i<5; i++){
        printf(".");
        delay(0.2);
    }
    system("cls");
    secret_tab();

}

void department_Lscreen(){

    char per_username[30], per_password[30];
    int flag = 0, choice;
    system("cls");
    printf("\n\n\tWelcome to Department Login Page");
    printf("\n\nEnter Username: ");
    scanf("%s%*c", per_username);
    fflush(stdin);
    printf("\nEnter Password: ");
    scanf("%s%*c", per_password);
    fflush(stdin);

    FILE *login_check;
    login_check = fopen("DUP.dat", "rb");
    //while(fscanf(login_check, "%s %s\n", depch.username, depch.password) != EOF){
    while(fread(&depch, sizeof(struct dep_details), 1, login_check)){
        if(strcmp(per_username, depch.username)==0 && strcmp(per_password, depch.password)==0){
            flag = 1;
            system("cls");
            goto successful_login;
        } 
    }
    if(flag == 0){
        printf("\n\nUsername/Password Incorrect!!!\n");
        redo_dep:
        printf("[1] Try Again?\n");
        printf("[2] Main Menu\n");
        printf("[3] Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        fflush(stdin);

        if(choice == 1){
            department_Lscreen();
        }
        else if(choice == 2){
            fclose(login_check);
            title_screen();
        }
        else if(choice == 3){
            fclose(login_check);
            exit(2);
        }
        else{
            printf("Wrong Entry!!");
            printf("Enter Correctly!!");
            delay(1);
            goto redo_dep;  
        }
        
    } 

    successful_login:
    system("cls");
    FILE *details_check = fopen("DUP.dat", "rb");
    //while((fscanf(details_check, "%[^|]|%[^|]|%d/%d/%d|%[^|]|%[^\n]\n", &depch1.username, &depch1.dep_name, &depch1.em, &depch1.ed, &depch1.ey, &depch1.university, &depch1.hod)) != EOF){
    while(fread(&depch1, sizeof(struct dep_details), 1, details_check)){
        if(strcmp(depch1.username, per_username) == 0){
            printf("\tAccount: %s Department\n", depch1.dep_name);
            fclose(login_check);
            break;
        }
    }
    fclose(details_check);
    int dep_after_L_choose = 0;
    printf("\nChoose from The Following Options:\n");
    printf("\n\t[1] Make Routine");
    printf("\n\t[2] View Routine");
    printf("\n\t[3] View Details");
    printf("\n\t[4] Edit Details");
    printf("\n\t[5] Logout");
    printf("\n\t[6] Exit");
    printf("\n\nYour Choice: ");
    scanf("%d%*c", &dep_after_L_choose);
    fflush(stdin);

    switch (dep_after_L_choose)
    {
    case 1:
    	fflush(stdin);
        routine_maker(depch1.dep_name);
        goto successful_login;
        break;

    case 2:
    	fflush(stdin);
        int r_v_check = routine_view(depch1.dep_name);
        goto successful_login;
        break;

    case 3:
        printf("\n");
        draw_line();
        printf("\n\t\tYOUR DETAILS\n");
        printf("\n\tUsername: %s\n", depch1.username);
        printf("\n\tDepartment Name: %s\n", depch1.dep_name);
        printf("\n\tEstablished (mm/dd/yyyy): %.2d/%.2d/%.4d\n", depch1.em, depch1.ed, depch1.ey);
        printf("\n\tAffiliated University: %s\n", depch1.university);
        printf("\n\tHOD: %s\n", depch1.hod);
        printf("\nPress Any Key to Go Back...\n");
        draw_line();
        fflush(stdin);
        getche();
        goto successful_login;
        break;

    case 4:
        edit_dep_record(per_username);
        goto successful_login;
        break;
        
    case 5:
        title_screen();
        break;

    case 6:
        exit(3);
        break;
    
    default:
        printf("Wrong Entry!! Try Again!");
        system("cls");
        goto successful_login;
    }
    
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
	
	signIn();
	system("cls");
}

void signup()
{   
    //for username and password
    FILE *tcheck;
	tcheck = fopen("teacher.dat", "r");
    redo_teacher_username:
    printf("\n\n\t\tCreate a Username and Password");
	printf("\nNOTE: Username Shouldn't contain any space, 5 - 10 Character\n");
    printf("\nWARNING!! Username CANNOT BE CHANGED once created\n\n");
	printf("Username: ");
	scanf("%s%*c",&tea.u);
    fflush(stdin);

    if(strlen(tea.u) < 5 || strlen(tea.u)>10){
        printf("\nUsername Length Not According to Instructions\n");
        printf("Try Again!!");
        goto redo_teacher_username;
    }

	teach.u[10] = '\0';
	teach.p[15] = '\0';
	while (fscanf(tcheck,"%s %s\n",&teach.u,&teach.p)!= EOF)
	{
		if (strcmp(tea.u,teach.u) == 0)
		{
		    printf("\nUsername Already Taken!!!");
		    printf("\nTry Again with Another USERNAME\n\n");
		    delay(1);
		    system("cls");
		    rewind(tcheck);
		    goto redo_teacher_username;
		}
	}
	
	redo_teacher_password:
	printf("\nPassword Must Be Between 5 And 15 Character");
	printf("\nEnter Password: ");
	scanf("%s%*c",&tea.p);
    fflush(stdin);

	if (strlen(tea.p)<5 || strlen(tea.p) > 15)
	{
	    printf("\nPassword Length Doesn't Match Instructions, Try Again!!!");
	    delay(1);
	    goto redo_teacher_password;
	}
	fclose(tcheck);

//for details
    printf("\n\nFill up the Additional Details\n");
	printf("\nId: ");
	scanf("%d%*c",&tea.id);
    fflush(stdin);
	printf("\nName: ");
	scanf("%[^\n]%*c",&tea.name);
    fflush(stdin);
	printf("\nGender (M/F/O): ");
	scanf("%c",&tea.gender);
    fflush(stdin);
	printf("\nDOB (yyyy/mm/dd): ");
	scanf("%d/%d/%d",&tea.doby, &tea.dobm, &tea.dobd);
    fflush(stdin);
	printf("\nSubject:");
	scanf("%[^\n]",&tea.subject);
    fflush(stdin);
	
    FILE *p;
	p = fopen("teacher.dat", "a+");
	fprintf(p, "%s %s\n",tea.u,tea.p);
	fclose(p);
    
	FILE *fp;
	fp=fopen("tdetails.dat","a+");
	fprintf(fp,"%s|%d|%s|%c|%d/%d/%d|%s\n",tea.u,tea.id,tea.name,tea.gender,tea.doby,tea.dobm,tea.dobd,tea.subject);
	fclose(fp);
	secret_tab();
	
}

void signIn()
{
	FILE *up;
	int flag=0, choice_teacher;
	redo4:
    system("cls");
	printf("\n\n\tWelcome to Teacher Login\n");
	printf("\nEnter Username: ");
	scanf("%s%*c",&teach.u);
    fflush(stdin);
	printf("\nEnter Password: ");
	scanf("%s%*c",&teach.p);
    fflush(stdin);

	up=fopen("teacher.dat","r");
	while(fscanf(up,"%s %s\n",&tea.u,&tea.p)!= EOF)
	{
        if(strcmp(teach.u,tea.u)==0 && strcmp(teach.p,tea.p)==0)
		{
			flag==1;
            fclose(up);
            homepage(teach.u);
           
        }
    }
    if(flag==0)
    {
	    printf("\n\nUsername/Password Incorrect!!!\n");
        redo_teach:
        printf("[1] Try Again?\n");
        printf("[2] Main Menu\n");
        printf("[3] Exit\n");
        printf("Choose: ");
        scanf("%d", &choice_teacher);
        fflush(stdin);

        if(choice_teacher == 1){
            signIn();
        }
        else if(choice_teacher == 2){
            fclose(up);
            title_screen();
        }
        else if(choice_teacher == 3){
            fclose(up);
            exit(12);
        }
        else{
            printf("Wrong Entry!!");
            printf("Enter Correctly!!");
            delay(1);
            goto redo_teach;  
        }
	}
    
}

void homepage(char t_u_name[])
{
	int choose;
	success:
    system("cls");
	printf("\t\tWelcome %s !!\n",t_u_name);
	printf("\nChoose From The Following:\n\n");
	printf("\t[1]View Personal Details\n\t[2]View Routine\n\t[3]Give Assignment\n\t[4]Logout");
    printf("\n\nYour Choice:");
	scanf("%d",&choose);
    fflush(stdin);

	switch(choose)
	{
		case 1:
    	system("cls");
    	FILE *dfp;
    	dfp=fopen("tdetails.dat","r+");
		while(fscanf(dfp,"%[^|]|%d|%[^|]|%c|%d/%d/%d|%[^\n]\n",&tea.u,&tea.id,&tea.name,&tea.gender,&tea.doby,&tea.dobm,&tea.dobd,&tea.subject) != EOF)
		{
        	if(strcmp(tea.u,t_u_name) == 0)
			{
				printf("\nYour Details\n");
	            printf("\nUsername: %s\n",tea.u);
	            printf("ID: %d\n",tea.id);
	            printf("Name: %s\n",tea.name);
	            printf("Gender: %c\n",tea.gender);
	            printf("DOB: %d/%d/%d\n",tea.doby,tea.dobm,tea.dobd);
	            printf("Subject: %s\n",tea.subject);
	            
        	}
        	
    	}
    	fclose(dfp);
        int choose1;
        success1:
        printf("\n\nPress:\n[1] Edit\n[2] Back\n");
        scanf("%d",&choose1);
        fflush(stdin);
		if(choose1==1)
		{
			re_choice1:
			system("cls");
			
    		printf("\nSelect the Field You Want to Update:\n");
		    printf("\n[1] ID\n[2] Name\n[3] Gender\n[4] DOB\n[5] Subject\n[6] Go Back\n[7] Exit");
		    printf("\n\nChoose: ");
		    int editchoice1;
		    scanf("%d%*c", &editchoice1);
		    fflush(stdin);
		
		    switch (editchoice1)
			{
		        case 1:
		        printf("\nEnter New ID: ");
		        scanf("%d%*c",&tea.id);
		        fflush(stdin);
		        break;
		        
		        case 2:
		        printf("\nEnter New Name: ");
		        scanf("%[^\n]%*c",&tea.name);
		        fflush(stdin);
		        break;
		        
		        case 3:
		        printf("\nEnter New Gender: ");
		        scanf("%c%*c", &tea.gender);
		        fflush(stdin);
		        break;
		        
		        case 4:
		        printf("\nEnter New DOB (yyyy/mm/dd): ");
		        scanf("%d/%d/%d", &tea.doby, &tea.dobm, &tea.dobd);
		        fflush(stdin);
		        break;
		
		        
		
		        case 5:
		        printf("\nEnter New Subject: ");
		        scanf("%[^\n]",tea.subject);
		        fflush(stdin);
		        break;
		
		        case 6:
		        goto re_choice1;
		        break;
		
		        case 7:
		        exit(12);
		
		        default:
		        fflush(stdin);
		        system("cls");
		        goto re_choice1;
		    }
		
		    FILE *pp = fopen("new30.dat", "w");
		    FILE *ff = fopen("tdetails.dat", "r");
			while(fscanf(ff,"%[^|]|%d|%[^|]|%c|%d/%d/%d|%[^\n]\n",&teach.u,&teach.id,&teach.name,&teach.gender,&teach.doby,&teach.dobm,&teach.dobd,&teach.subject) != EOF)
			{
        		if(strcmp(tea.u,t_u_name) == 0)
				{
		    		fprintf(pp,"%s|%d|%s|%c|%d/%d/%d|%s\n",tea.u,tea.id,tea.name,tea.gender,tea.doby,tea.dobm,tea.dobd,tea.subject);
		            
		        }
		        else{
		            fprintf(pp,"%s|%d|%s|%c|%d/%d/%d|%s\n",teach.u,teach.id,teach.name,teach.gender,teach.doby,teach.dobm,teach.dobd,teach.subject);
		        }
		    }
		    fclose(ff);
		    fclose(pp);
		
		    remove("tdetails.dat");
		    rename("new30.dat", "tdetails.dat");
		    printf("\n\nUpdate Successful!!");
		    
		    retry1:
		    fflush(stdin);
		    int choice;
		    printf("\nMake Any More Changes?\n[1] Yes\n[2] No\n\nChoose: ");
		    scanf("%d", &choice);
		    fflush(stdin);
		
		    switch(choice)
			{
		        case 1:
		            goto re_choice1;
		        case 2:
		            goto success;
		        default:
		            goto retry1;
		    }
		}
				
        else if(choose1==2)
        {
            system("cls");
            fclose(dfp);
            goto success;
        }
        printf("\nWrong Entry");
        goto success1;
    	break;
    	
		case 2:
			fflush(stdin);
    		int reply = routine_view("AYJUYAAS");
            system("cls");
            goto success;
    		
        case 3:
        	system("cls");
        	int wish, number = 1, flag = 0;
            char assign[100], file_name[30];
        	tt:
        	printf("\tGive Assignment\n");
            printf("\n\nGive Assignment to:\n");
        	FILE *dep_view = fopen("DUP.dat", "rb");
            while(fread(&depch1, sizeof(struct dep_details), 1, dep_view)){
                printf("\n[%d] %s", number, depch1.dep_name);
                number++;
            }
            printf("\nChoose: ");
            scanf("%d", &wish); 
			fflush(stdin);
            rewind(dep_view);
            number = 1;
            while(fread(&depch1, sizeof(struct dep_details), 1, dep_view)){
                if(wish == number){
                    flag = 1;
                    break;
                }
                number++;
            }
            fclose(dep_view);
            if(flag == 0){
                printf("\nWrong Choice");
            }

            printf("\n\nGive Assignment to Students of %s department", depch1.dep_name);
            printf("\n\nPress enter to end assignment text\n\n => ");
            scanf("%[^\n]", assign); 
			fflush(stdin);
			printf("\nAssigned to Department!!");
            strcpy(file_name, depch1.dep_name);
            strcat(file_name, "assign");
            strcat(file_name, ".txt");
            FILE *assign_print = fopen(file_name, "a");
            fprintf(assign_print, "%s\n", assign);
            fclose(assign_print);
            printf("\nPress Any Key to Go Back");
            getche();

            homepage(t_u_name);
            break;

			  
		case 4:
		system("cls");
		title_screen();
		break;	
		
		default:
		system("cls");
		printf("Wrong Input!!");
		goto success;
		break;
		    		
	}
			

}

int routine_view(char dep101[]){
    system("cls");
    int a, r_ch;
    int n, count;
    char ro_list[30], ro_choose[30], ro_dep[20];

    FILE *rop = fopen("routinelist.txt", "r");
    
    if(strcmp(dep101, "AYJUYAAS") != 0){
        count = 1;
        printf("\n\nChoose the Routine You want to View: (Enter 0 to return)\n\n");
        while(fscanf(rop, "%[^|]|%[^\n]\n", &ro_dep, &ro_list) != EOF){
            if(strcmp(ro_dep, dep101) == 0){
                printf("\t[%d] %s\n", count, ro_list);
                count++;
            }
        }
        printf("\nChoose: ");
        scanf("%d", &r_ch);
        fflush(stdin);
        if(r_ch == 0){
            return 0;
        }
        rewind(rop);
        count = 1;
        while(fscanf(rop, "%[^|]|%[^\n]\n", &ro_dep, &ro_list) != EOF){
            if(strcmp(ro_dep, dep101) == 0){
                if(count == r_ch){
                    strcat(ro_list, ".txt");
                    strcpy(ro_choose, ro_list);
                    break;
                }
                count++;
            }
        }
        fclose(rop);
        printf("\nYour Selected Routine:\n\n");

        FILE *routine_view = fopen(ro_choose, "r");
        char c;
        while ((c=fgetc(routine_view)) != EOF){
            putchar(c);
        }
        fclose(routine_view);

        printf("\nPress any Key to go back...");
        getche();
        return 0;
    }
    else{
        count = 1;
        printf("Choose the Routine You want to View: (Enter 0 to return)\n\n");
        while(fscanf(rop, "%[^|]|%[^\n]\n", &ro_dep, &ro_list) != EOF){
            printf("\t[%d] %s\n", count, ro_list);
            count++;
        }
        printf("\nChoose: ");
        scanf("%d", &r_ch);
        fflush(stdin);
        if(r_ch == 0){
            return 0;
        }
        rewind(rop);
        count = 1;
        while(fscanf(rop, "%[^|]|%[^\n]\n", &ro_dep, &ro_list) != EOF){
            if(count == r_ch){
                strcat(ro_list, ".txt");
                strcpy(ro_choose, ro_list);
                break;
            }
            count++;
        }
        fclose(rop);
        printf("\nYour Selected Routine:\n\n");

        FILE *routine_view = fopen(ro_choose, "r");
        char c;
        while ((c=fgetc(routine_view)) != EOF){
            putchar(c);
        }
        fclose(routine_view);

        printf("\nPress any Key to go back...");
        getche();
        return 0;
    }

}

int edit_dep_record(char u_name[]){
    system("cls");

    int editchoice = 0, re_choose = 0;
    char temp_depname[30], ro_list[30], ro_dep[30];
    FILE *prf = fopen("DUP.dat", "rb");

    if(prf == NULL){
        printf("Error Opening File");
    }
    
    //while((fscanf(prf, "%[^|]|%[^|]|%d/%d/%d|%[^|]|%[^\n]\n", &depch1.username, &depch1.dep_name, &depch1.em, &depch1.ed, &depch1.ey, &depch1.university, &depch1.hod)) != EOF){
    while(fread(&depch1, sizeof(struct dep_details), 1, prf)){
        if(strcmp(depch1.username, u_name) == 0){
            break;
        }
    }
    fclose(prf);

    re_choice:
    printf("\n\n\t\t%s Department\n", depch1.dep_name);
    draw_line(); printf("\n");
    printf("\n\t     Your Current Details\n");
    draw_line(); printf("\n");
    printf("\nDepartment Name: %s", depch1.dep_name);
    printf("\n\nEstablished (mm/dd/yyyy): %.2d/%.2d/%.4d", depch1.em, depch1.ed, depch1.ey);
    printf("\n\nAffiliated University: %s", depch1.university);
    printf("\n\nHOD: %s\n\n", depch1.hod);
    fflush(stdin);
    
    draw_line();
    printf("\n\nSelect the Field You Want to Update:\n");
    printf("\n[1] Department Name\n[2] Established Date\n[3] Affiliated University\n[4] HOD name\n[5] Change Password\n[6] Go Back\n[7] Exit");
    printf("\n\nChoose: ");

    scanf("%d%*c", &editchoice);
    fflush(stdin);

    switch (editchoice){
        case 1:
        strcpy(temp_depname, depch1.dep_name);
        printf("\nEnter New Department Name: ");
        gets(depch1.dep_name);
        fflush(stdin);

        FILE *ro = fopen("routinelist.txt", "r");
        FILE *ron = fopen("new_ro.txt", "w");
        while(fscanf(ro, "%[^|]|%[^\n]\n", &ro_dep, &ro_list) != EOF){
            if(strcmp(ro_dep, temp_depname) == 0){
                fprintf(ron, "%s|%s", depch1.dep_name, ro_list);
            }
            else{
                fprintf(ron, "%s|%s\n", ro_dep, ro_list);
            }
        }
        fclose(ro); fclose(ron); remove("routinelist.txt"); rename("new_ro.txt", "routinelist.txt");

        FILE *so = fopen("stu_details.dat", "r");
        FILE *son = fopen("new_sd.dat", "w");
        while(fscanf(so,"%[^|]|%d|%[^|]|%c|%d/%d/%d|%[^|]|%[^\n]\n", &st.user,&st.roll,&st.name,&st.gender,&st.doby,&st.dobm,&st.dobd, &st.dep, &st.faculty)!=EOF){
            if(strcmp(st.dep, temp_depname)==0){
                fprintf(son,"%s|%d|%s|%c|%d/%d/%d|%s|%s\n",st.user,st.roll,st.name,st.gender,st.doby,st.dobm,st.dobd,depch1.dep_name, st.faculty);
            }
            else{
                fprintf(son,"%s|%d|%s|%c|%d/%d/%d|%s|%s\n",st.user,st.roll,st.name,st.gender,st.doby,st.dobm,st.dobd, st.dep, st.faculty);
            }
        }
        fclose(so); fclose(son); remove("stu_details.dat"); rename("new_sd.dat", "stu_details.dat");
        break;

        case 2:
        printf("\nNew Established Date (mm/dd/yyyy): ");
        scanf("%d/%d/%d", &depch1.em, &depch1.ed, &depch1.ey);
        fflush(stdin);
        break;

        case 3:
        printf("\nNew Affiliated University: ");
        gets(depch1.university);
        fflush(stdin);
        break;

        case 4:
        printf("\nNew Department HOD Name: ");
        gets(depch1.hod);
        fflush(stdin);
        break;

        case 5:
        change_dep_p(depch1.username);
        break;

        case 6:
        return 0;

        case 7:
        exit(12);

        default:
        fflush(stdin);
        system("cls");
        goto re_choice;
    }

    FILE *nrf = fopen("new.dat", "wb");
    FILE *prf1 = fopen("DUP.dat", "rb");
    //while((fscanf(prf1, "%[^|]|%[^|]|%d/%d/%d|%[^|]|%[^\n]\n", &depch.username, &depch.dep_name, &depch.em, &depch.ed, &depch.ey, &depch.university, &depch.hod)) != EOF){
    while(fread(&depch, sizeof(struct dep_details), 1, prf1)){
        if(strcmp(depch1.username, depch.username) == 0){
            //fprintf (nrf, "%s|%s|%.2d/%.2d/%.4d|%s|%s\n", depch1.username, depch1.dep_name, depch1.em, depch1.ed, depch1.ey, depch1.university, depch1.hod);
            fwrite(&depch1, sizeof(struct dep_details), 1, nrf);
        }
        else{
            //fprintf (nrf, "%s|%s|%.2d/%.2d/%.4d|%s|%s\n", depch.username, depch.dep_name, depch.em, depch.ed, depch.ey, depch.university, depch.hod);
            fwrite(&depch, sizeof(struct dep_details), 1, nrf);
        }
    }
    fclose(nrf);
    fclose(prf1);

    remove("DUP.dat");
    rename("new.dat", "DUP.dat");
    printf("\n\nUpdate Successful!!");
    
    retry:
    re_choose = 0;
    printf("\nMake Any More Changes?\n[1] Yes\n[2] No\n\nChoose: ");
    scanf("%d", &re_choose);
    fflush(stdin);

    switch(re_choose){
        case 1:
            edit_dep_record(u_name);
        case 2:
            return 0;
        default:
            goto retry;
    }
}

int change_dep_p(char username[]){

    system("cls");
    retry_cp:
    fflush(stdin);
    int flag = 0;
    char current_pass[16];
    char changed_pass[16];
    draw_line();

    printf("\n\n\n\t\tChange Password For: %s", username);
    printf("\n\n\tEnter Your Current Password: ");
    scanf("%[^\n]", &current_pass);
    fflush(stdin);

    FILE *login_check;
    login_check = fopen("DUP.dat", "rb");
    //while(fscanf(login_check, "%s %s\n", depch.username, depch.password) != EOF){
    while(fread(&depch, sizeof(struct dep_details), 1, login_check)){
        if(strcmp(username, depch.username)==0 && strcmp(current_pass, depch.password)==0){
            flag = 1;
            break;
        } 
    }
    fclose(login_check);
    if(flag == 0){
        printf("\n\nCurrent Password Doesn't Match!!\n\n");
        goto retry_cp;
    }

    printf("\n\n\tEnter New Password: ");
    scanf("%[^\n]", &depch.password);
    fflush(stdin);

    FILE *read = fopen("DUP.dat", "rb");
    FILE *new = fopen("new.dat", "wb");

    //while(fscanf(read, "%s %s\n", depch.username, depch.password) != EOF){
    while(fread(&depch1, sizeof(struct dep_details), 1, read)){
        if(strcmp(username, depch1.username)==0 && strcmp(current_pass, depch1.password)==0){
            fwrite(&depch, sizeof(struct dep_details), 1, new);
        } 
        else{
            //fprintf(new, "%s %s\n", depch.username, depch.password);
            fwrite(&depch1, sizeof(struct dep_details), 1, new);
        }
    }

    fclose(read);
    fclose(new);
    remove("DUP.dat");
    rename("new.dat", "DUP.dat");

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
