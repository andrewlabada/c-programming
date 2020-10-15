    #include<stdio.h>
    #include <string.h>
    //global variables to access them worldwide
    int choice,quiz[100],project[100], homework[100], qPerfect[100],pPerfect[100],hmPerfect[100], studentCount = 0, qCount=0, pCount=0, hmCount=0, qPerfectTotal=0, pPerfectTotal=0, hmPerfectTotal=0, qPerfectCount=0, pPerfectCount=0, hmPerfectCount=0;
    float finalGrade=0.0, passingGrade, perfectFinalGrade;
    char studentNames[50][50],names[50][50];
    float studentGrades[50];
    int studentScores[50];
    //function declarations
    int getMenuChoice();
    void initPerfectScores();
    void initStudents();
    void ComparePerfecScore();
    char CompareStudent();
    void inputItems();




    int main(){


    do{
            choice=getMenuChoice();
            printf("\nChoice Is: [%d] \n",choice);
            switch(choice){
                case 0:
                    break;
                case 1:
                        inputItems();
                    break;
                case 2:
                        ComparePerfecScore();
                    break;
                case 3:
                        CompareStudent();
                    break;
                case 4:
                
                    break;
            }
        }while(choice!=0);

        return 0;
    }


    //functions
    void initPerfectScores(){
                    printf("\nEnter number of quizzes: ");
                    scanf("%d",&qCount);
                    for(int i=0; i<qCount; i++){
                        printf("Enter perfect score for quiz %d: \n",i+1);
                        scanf("%d",&qPerfect[i]);
                        qPerfectTotal+=qPerfect[i];
                    }
                    printf("\nEnter number of projects: ");
                    scanf("%d",&pCount);
                    for(int i=0; i<pCount; i++){
                        printf("Enter perfect score for project %d: \n",i+1);
                        scanf("%d",&pPerfect[i]);
                        pPerfectTotal+=pPerfect[i];
                    
                    }
                    printf("\nEnter number of homework: ");
                    scanf("%d",&hmCount);
                    for(int i=0; i<hmCount; i++){
                        printf("Enter perfect score for homework %d: \n",i+1);
                        scanf("%d",&hmPerfect[i]);
                        hmPerfectTotal+=hmPerfect[i];
                        
                    }
                    perfectFinalGrade=(qPerfectTotal/qCount*0.5)+(pPerfectTotal/pCount*0.3)+(hmPerfectTotal/hmCount*0.2);
    }//end of initPerfectScores;
    void initStudents(){
                    printf("\nEnter number of students: ");
                    scanf("%d",&studentCount);
                    for(int i=0; i<studentCount; i++){
                        printf("\n-------------------------------------------------------------------\n");
                        printf("\n[Student %d of %d]\n",i+1,studentCount);
                        printf("Enter name of student %d: \n",i+1);
                        scanf("%s",studentNames[i]);
                        /*for(int j=0; j<qCount; j++){
                            printf("\n[Quiz %d of %d] \n",j+1,qCount);
                            printf("Enter score for quiz %d: \n", j + 1);
                            scanf("%d", &quiz[j]);
                            while (quiz[j] < 0 || quiz[j] > qPerfect[j]) {
                            printf("Invalid score \n");
                            printf("Enter score for quiz %d: \n", j + 1);
                            scanf("%d", &quiz[j]);
                            }//end of while quiz
                        }
                        printf("\n-------------------------------------------------------------------\n");
                        for(int j=0; j<pCount; j++){
                            printf("\n[Project %d of %d]\n",j+1,pCount);
                            printf("Enter score for project %d: \n",j+1);
                            scanf("%d",&project[j]);
                            while (project[j] < 0 || project[j] > pPerfect[j]) {
                                printf("Invalid score \n");
                                printf("Enter score for project %d: \n", j + 1);
                                scanf("%d", &project[j]);
                            }//end of while project
                        }
                        printf("\n-------------------------------------------------------------------\n");
                        for(int j=0; j<hmCount; j++){
                            printf("\n[Homework %d of %d]\n",j+1,hmCount);
                            printf("Enter score for homework %d: \n",j+1);
                            scanf("%d",&homework[j]);
                            while (homework[j] < 0 || homework[j] > hmPerfect[j]) {
                                printf("Invalid score \n");
                                printf("Enter score for homework %d: \n", j + 1);
                                scanf("%d", &homework[j]);
                            }//end of while project
                        }*/
                        
                    }

    }//end of initstudents

    void ComparePerfecScore(){

                    printf("\n-------------------------------------------------------------------\n");
                    for(int i=0; i<studentCount; i++){
                        printf("\nStudent %d:\n",i+1);
                        printf("Name: %s \n",studentNames[i]);
                        for(int i=0; i<qCount; i++){
                        printf("Perfect score Quiz %d = %d \n",i+1,qPerfect[i]);
                        printf("Quiz %d: %d \n",i+1,quiz[i]);
                        }
                        for(int i=0; i<pCount; i++){
                        printf("Perfect score Project %d = %d \n",i+1,pPerfect[i]);
                        printf("Project %d: %d \n",i+1,project[i]);
                        }
                        for(int i=0; i<hmCount; i++){
                        printf("Perfect score Homework %d = %d \n",i+1,hmPerfect[i]);
                        printf("Homwork %d: %d \n",i+1,homework[i]);
                        }

                        
                    }

    }//end of compare perfect score display;

    char CompareStudent(){

                printf("\nEnter Student's Name to be search: ");
                for(int i=0; i<studentCount; i++){
                scanf("%s",names[i]);
                    
                    if (strcmp(names[i],studentNames[i]) == 0)
                                    {
                                    printf("Already exist.\n");
                                    return 0;
                                    }
                    printf("Not found\n");
                                return 1;

                }
                

                









    /* 
        
                        ::::algo::::

                        if array is empty get string name
                            
                        check ang array if the name exists
                        dayun

    */
                                /*for (int i = 0; i < studentCount; i++)
                                {
                                    if (strcmp(names[i],studentNames[i]) == 0)
                                    {
                                    printf("Found\n");
                                    return 0;
                                    }
                                }
                                printf("Not found\n");
                                return 1;*/
        
                        /* printf("Name already existed.\n");
                            printf("Enter name of student %d: \n",i+1);
                            scanf("%s",studentNames[i]);*/
                    /*
                        for(int i=0; i<studentCount; i++){
                        printf("\nStudent %d:\n",i+1);
                        printf("Name: %s \n",studentNames[i]);
                        
                        }*/

                        
                    




    }//end of compare student names;

    void inputItems(){

    // initPerfectScores();
        initStudents();
        //ComparePerfecScore();
    }






    int getMenuChoice()
    {
        int choice;
        printf("\n[1] Initialize number of quiz/project/homework, perfect score, student score ");
        printf("\n[2] Compare Perfect score");
        printf("\n[3] Compare Student ");
        printf("\n[4] Compute Grades");
        printf("\n[4] Display Remarks");
        printf("\n[0] Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        return choice;
    }