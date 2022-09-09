#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<windows.h>

void delayfr(float sec);
void trim(char * str);

void border(){ 
    int rows, columns;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int i;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    printf("\n\n");
    for(i=0; i<columns; i++){
        printf("#");
    }
    printf("\n\n");
}

void routine_maker(char dep_name[]){
    int processing, flag;
    system("cls");
/****************** INITIALIZATION 1 ************************/
    printf(" ROUTINE MAKING PROGRAM \n\n");
    int no_of_routines; 
    char days[7][3] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int period;
    //LOOP Variables
    int t, i=0, j, l, op;
    //Count Variables
    int d, n, lp1;
    //Manipulation Variables
    int per, pert, same_sub, ro_name_choose;

/************* DAY SELECT ******************/

    day_select:
    fflush(stdin);
    int end_day, start_day, total_days;
    printf("\nIf:\n\n[1] Sunday\n[2] Monday\n[3] Tuesday\n[4] Wednesday\n[5] Thursday\n[6] Friday\n[7] Saturday");
    printf ("\n\nChoose a starting day and a ending day for routine\n");
    printf("\nNOTES:\nA> Choose Start and End Day, EG: 1 & 6 For Sunday to Friday\nB> For Only 1 Day routine Enter the same number (eg 1 & 1 for Sunday)");
    printf("\nC> Descending order is not allowed: eg; 7 - 1 (i.e. Sat to Sun is prohibitted)");
    printf("\n\nChoose Start Day: ");
    scanf("%d", &start_day);
    fflush(stdin);

    if(start_day<1 || start_day>7){
        getchar();
        printf("\nError! Out of Range Value!");
        delayfr(1);
        system("cls");
        goto day_select;
    }

    re:
    fflush(stdin);
    printf("\nChoose End Day: ");
    scanf("%d%*c", &end_day);
    fflush(stdin);

    if(end_day<start_day || end_day>7){
        getchar();
        printf("\nError! Out of Range Value!");
        delayfr(0.6);
        goto re;
    }

    total_days = (end_day-start_day)+1;

/********** INITIALIZATION 2 ***************/
    border();
    printf("\nEnter the Total Number of Periods You Want(In a Day): ");
    scanf("%d", &period);
    fflush(stdin);

    printf("\nEnter the Number of Routines You Want to Make: ");
    scanf("%d", &no_of_routines);
    fflush(stdin);

    char faculty[no_of_routines][15];
    char temp_faculty[no_of_routines][15];

    border();
    printf("\nFaculties/Grades:");
    for(i=0; i<no_of_routines; i++){
        printf("\nEnter the Grade/Faculty for routine no. %d: ", i+1);
        gets(faculty[i]);
        trim(faculty[i]);
        strupr(faculty[i]);
        fflush(stdin);
    }

    char period_marker[11] = ">>>       ";

    int total_period = (total_days*period);
    
    char subject[no_of_routines][total_period][14];
    char error_subject[no_of_routines][total_period][14];
    char temp_subject[14], temp_subject1[14], temp_subject2[14];
    
    int t1, t2;
    system("cls");

    for(i=0; i<no_of_routines; i++){
        strcpy(temp_faculty[i], faculty[i]);
    }

/********** ROUTINE MAKING ************/
    for(t=0; t<no_of_routines; t++){
        border();

        for(i=0; i<total_period; i++){
            subject[t][i][14] = '\0';
        }

        system("cls");

        for(op=0; op<total_period; op++){
            lp1 = (start_day-1);
            printf("Routine no. %d\n", (t+1));
            printf("Grade/Faculty = %s\n", temp_faculty[t]);
            strcpy(subject[t][op], period_marker);

            for(i=0; i<total_days; i++){
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
                    printf ("| %-15.14s ", subject[t][j]);
                }

                printf ("|\n");

                printf("----------");
                for(l=1; l<=(period); l++){
                    printf("------------------");
                }

            }

            printf("\nEnter the Subject Down Below to Replace the Pointer '>>>' [Max 14 letters (including space)]:\n");
            printf("Enter Here: ");
            fgets(subject[t][op], 14, stdin);
            fflush(stdin);
            
            trim(subject[t][op]);
            strupr(subject[t][op]);
            system("cls");
        }

        if(op == (total_period-1)){
            delayfr(1);
            system("cls");
        }
    }
    
/******** Collison Detactor *******/

    collision_detactor:
    fflush(stdin);
    int times_count = 1, t3;
    int solve, soln;
    char ch;
    int error11, length, view_count = 1, first_view = 1;
    
    do{
        again_again:
        for(t=0; t<no_of_routines; t++){
            for(i=0; i<total_period; i++){
                strcpy(error_subject[t][i], subject[t][i]);
            }
        }

        flag = 0;
        int k, w;
        int choice_1;

        for (t=0; t<(no_of_routines-1); t++){
            for(i=0; i<total_days; i++){
                n = i;
                per = (n*period);
                pert = ((n+1)*period);
                d = 0;

                for (j=per; j<pert; j++){
                    d += 1;
                    w = (t+1);
                    for (k=w; k<no_of_routines; k++){
                        if (view_count == 1){   
                            if (strcmp(subject[t][j], subject[k][j]) == 0){
                                strcpy(temp_subject, subject[t][j]); strcat(temp_subject, " <");
                                if(strcmp(error_subject[t][j], temp_subject) != 0){
                                    strcat (error_subject[t][j], " <");
                                }
                                strcpy(temp_subject1, subject[k][j]); strcat(temp_subject1, " <");
                                if(strcmp(error_subject[k][j], temp_subject) != 0){
                                    strcat (error_subject[k][j], " <");
                                }
                                flag++;
                            }
                        }
                        else{
                            if (strcmp(subject[t][j], subject[k][j]) == 0){
                                strcat (error_subject[t][j], " <");
                                strcat (error_subject[k][j], " <");
                                flag++;
                                goto show_errors;
                            }
                        }
                    }
                }
            }
        }

     /****** Showing Errors ******/
        show_errors:
        border();
        error11 = 0;
        if(flag != 0){

            for(t=0; t<no_of_routines; t++){
                printf("\n\n");

                lp1 = (start_day-1);
                printf("Routine no. %d\n", (t+1));
                printf("Faculty = %s\n", faculty[t]);

                for(i=0; i<total_days; i++){
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
                        printf ("| %-16.15s", error_subject[t][j]);
                    }

                    printf ("|\n");

                    printf("----------");
                    for(l=1; l<=(period); l++){
                        printf("------------------");
                    }

                }

            }

            solve_retry:
            fflush(stdin);
            if(times_count == 1){
                printf ("\nCollisions Detected In Subjects Marked '<'\nWant to Solve?\n[1] Yes\n[2] No\nChoose: ");
                scanf("%d", &choice_1);
                fflush(stdin);

                if(choice_1 == 1){
                    goto solve;
                }
                
                else if (choice_1 == 2){
                    processing = 322;
                    for(t1=0; t1<((no_of_routines)-1); t1++){
                        for(t2=0; t2<total_period; t2++){
                            for(t3=(t1+1); t3<no_of_routines; t3++){
                                if(strcmp(subject[t1][t2], subject[t3][t2]) == 0){
                                    strcat(subject[t3][t2], " ");
                                }
                            }
                        }   
                    }
                    goto final_print;
                }

                else{
                    printf("\nError, Wrong Response: ");
                    delayfr(1);
                    goto solve_retry;
                }
            }

        }
        else{
            processing = 322;
            goto final_print;     
        }

        /***** Collison Solver *****/
        solve:
        fflush(stdin);
        times_count++;
        view_count++;
        
        ch = ' ';
        if(first_view == 1){
            first_view++;
            goto again_again;
        }
        for (t=0; t<(no_of_routines-1); t++){
            for(i=0; i<total_days; i++){
                n = i;
                per = (n*period);
                pert = ((n+1)*period);
                d = 0;
                lp1 = (start_day-1);

                for (j=per; j<pert; j++){
                    d += 1;
                    w = (t+1);
                    for (k=w; k<no_of_routines; k++){
                        if (strcmp(subject[t][j], subject[k][j]) == 0){
                            printf ("\n\nCollision on period %d on %s & %s (marked <)", d, faculty[t], faculty[k]);
                            printf ("(%s)", subject[t][j]);

                            error11 = 1;
                            flag = 1;
                            solve_part:
                            fflush(stdin);
                            solve = '\0';
                            printf ("\nSolve it?\n[1] YES\n[2] NO\nChoose: ");
                            scanf("%d", &solve);
                            fflush(stdin);

                            if (solve == 1){
                                soln_part:
                                printf ("\nMake changes to:\n[1] Make Changes to %s\n[2] to Make Changes to %s\nChoose: ", faculty[t], faculty[k]);
                                scanf("%d", &soln);
                                fflush(stdin);

                                if(soln == 1){
                                    printf ("%s Faculty %.3s period %d: ", faculty[t], days[lp1], d);
                                    fgets(subject[t][j], 14, stdin);
                                    fflush(stdin);
                                    strupr(subject[t][j]);
                                    times_count++;
                                    goto again_again;
                                }

                                else if (soln == 2){
                                    printf ("%s Faculty %.3s period %d: ", faculty[k], days[lp1], d);
                                    fgets(subject[k][j], 14, stdin);
                                    fflush(stdin);
                                    strupr(subject[k][j]);
                                    times_count++;
                                    goto again_again;
                                }

                                else{
                                    printf ("\nInvalid Entry!!");
                                    delayfr(1);
                                }
                            }

                            else if (solve == 2){
                                strcat(subject[k][j], " ");
                                lp1 += 1;
                                times_count++;
                                goto again_again;
                            }

                            else{
                                printf ("Invalid Entry!!");
                                delayfr(1);
                                goto solve_part;
                            }
                        }
                    }
                }

                lp1 += 1;
            }
        }
        times_count++;
    }while(error11 == 1);
    processing = 322;
    
/****** THE FINAL OUTPUT ******/
    final_print:
    border();
    printf("\nThe Final Routine/s: ");
    for(t=0; t<no_of_routines; t++){
        printf("\n\n");

        lp1 = (start_day-1);
        printf("Routine no. %d\n", (t+1));
        printf("Faculty = %s\n", faculty[t]);

        for(i=0; i<total_days; i++){
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
                printf ("| %-16.15s", subject[t][j]);
            }

            printf ("|\n");

            printf("----------");
            for(l=1; l<=(period); l++){
                printf("------------------");
            }

        }

    }
    /****** ASK FOR FINAL *****/
    ask_for_final:
    border();
    fflush(stdin);
    int final_r_choose;
    printf("\nIs This Your Final Routine??\n");
    printf("[1] Yes\n[2] Edit Some Changes\n[3] Start Creating Again\n[4] Exit Routine Making\n\nCHOOSE: ");
    scanf("%d", &final_r_choose);
    fflush(stdin);

    switch (final_r_choose)
    {
    case 1:
        if(processing == 322){
            goto redo_rn;
        }
        goto collision_detactor;
        break;
    
    case 2:
        processing = 0;
        goto edit_change;
        break;

    case 3:
        routine_maker(dep_name);
        break;

    case 4:
        return;

    default:
        goto ask_for_final;
    }
    
 /******* Edit Change ***********/
    
    edit_change:
    border();
    fflush(stdin);
    int edit_choice;
    printf("\nMake Changes to:\n");
    for(i=0; i<no_of_routines; i++){
        printf("[%d] %s\n", i+1, faculty[i]);
    }
    printf("Choose: "); scanf("%d", &edit_choice); fflush(stdin);
    if(edit_choice < 0 || edit_choice > no_of_routines){
        goto edit_change;
    }
    int qr = edit_choice - 1;
    int marker, period_select, day_select, original_cp;
        printf("\n\n");
        lp1 = (start_day-1);
        printf("Faculty = %s\n", faculty[qr]);

        for(i=0; i<total_days; i++){
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
                printf ("| %-16.15s", subject[qr][j]);
            }

            printf ("|\n");

            printf("----------");
            for(l=1; l<=(period); l++){
                printf("------------------");
            }

        }

        re_day:
        printf("\n\nSelect the day You want to make changes to :\n");
        for(i=0; i<total_days; i++){
            printf("[%d] %.3s\n", i+1, days[i]);
        }
        scanf("%d", &day_select);
        fflush(stdin);
        if(day_select<0 || day_select>total_days){
            printf("Wrong Day!!");
            goto re_day;
        }
        marker = (day_select-1);
        re_per:
        printf("\nEnter Period: "); scanf("%d", &period_select); fflush(stdin);
        if(period_select<0 || period_select>period){
            printf("\nWrong Period!!");
            goto re_per;
        }
        period_select -= 1;
        if(marker == 0){
            original_cp = period_select;
        }
        else{
            original_cp = (marker*period) + period_select;
        }
        new_sub:
        printf("\nEnter the New Subject on %.3s %d period:\n\nCurrent Sub: %s\n", days[marker], (period_select+1) , subject[qr][original_cp]);
        strcpy(temp_subject1, subject[qr][original_cp]); trim(temp_subject1);
        printf("Enter Here: "); fgets(subject[qr][original_cp], 14, stdin); fflush(stdin); trim(subject[qr][original_cp]); strupr(subject[qr][original_cp]);
        if(strcmp(temp_subject1, subject[qr][original_cp]) == 0){
            fflush(stdin);
            printf("\nSame Subject As Previous!!");
            agin_choose_new_sub:
            printf("\n\n[1] Continue\n[2] Enter a new Subject\nChoose: ");
            scanf("%d", &same_sub); fflush(stdin);
            if(same_sub == 1){
            }
            else if(same_sub == 2){
                goto new_sub;
            }
            else{
                goto agin_choose_new_sub;
            }
        }
        goto collision_detactor;


 /**** FIlE PRINTING ****/
    redo_rn:
    border();
    fflush(stdin);
    static char routine_name[25], temp_dep[20], temp_routine_name[30];
    
    printf("\n\nEnter the name of routine you want to save it as (25 Words Including Space)\n");
    gets(routine_name);
    fflush(stdin);
    if(strlen(routine_name) > 25){
        printf("\nName too long!!");
        goto redo_rn;
    }
    FILE *op123 = fopen("routinelist.txt", "r");
    while(fscanf(op123, "%[^|]|%[^\n]", &temp_dep, &temp_routine_name) != EOF){
        if(strcmp(temp_routine_name, routine_name) == 0){
            printf("\nRoutine Already Exist!!\n");
            ro_name_collide_choice:
            printf("[1] Overwrite\n[2] New Name\nChoose: ");
            scanf("%d", &ro_name_choose); fflush(stdin);
            if(ro_name_choose == 1){
                strcat(temp_routine_name, ".txt");
                remove(temp_routine_name);
                break;
            }
            else if(ro_name_choose == 2){
                fclose(op123);
                goto redo_rn;
            }
            else{
                goto ro_name_collide_choice;
            }
        }
    }
    fclose(op123);
    FILE *op12 = fopen("routinelist.txt", "a+");
    fprintf(op12, "%s|%s\n", dep_name, routine_name);
    fclose(op12);
    
    strcat(routine_name, ".txt");
    fflush(stdin);
    
    FILE *rot = fopen(routine_name, "w+");

    for(t=0; t<no_of_routines; t++){
        if(t!=0){
            fprintf(rot, "\n\n");
        }
        
        lp1 = (start_day-1);
        fprintf(rot, "Faculty: %s\n", faculty[t]);

        for(i=0; i<total_days; i++){
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
                fprintf (rot, "| %-16.15s", subject[t][j]);
            }

            fprintf (rot, "|\n");

            fprintf(rot, "----------");
            for(l=1; l<=(period); l++){
                fprintf(rot, "------------------");
            }

        }

    }
    fclose(rot);

    printf("\nThis Final Routine Can be Found on '%s' file on the same directory as this exe file", routine_name);

    printf("\nPress Any Key To Exit: ");
    getche();

    return;
}

void delayfr(float sec) 
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

    index = -1, i = 0;

    while(str[i] != '\0'){ //Finds the End Index of Non-White Space
    
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n'){
            index= i;
        }

        i++;
    }

    str[index + 1] = '\0'; //Mark the 
}