    #include<stdio.h>
    #include <string.h>
    //global variables to access them worldwide
    int  hmTotal,pTotal,qTotal, j,choice,yes,quiz[100][100],project[100][100], homework[100][100], qPerfect[100],pPerfect[100],hmPerfect[100], studentCount = 0, qCount=0, pCount=0, hmCount=0, qPerfectTotal=0, pPerfectTotal=0, hmPerfectTotal=0, qPerfectCount=0, pPerfectCount=0, hmPerfectCount=0;
    float finalGrade=0.0, passingGrade, perfectFinalGrade;
    char studentNames[50][50],searchedname[100],studentNames1[50][50];
    float studentGrades[50];
    int studentScores[50];
    //function declarations
    int getMenuChoice();
    void initPerfectScores();
    void initStudents();
    void ComparePerfecScore();
    char CompareStudent();
    void inputItems();
    void ComputeGrades();
    void DisplayRemarks();



    void main(){


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
                        ComputeGrades();
                    break;
                case 5:
                        DisplayRemarks();
                    break;
            }
        }while(choice!=0);

    
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
                        qTotal=0;
                        pTotal=0;
                        hmTotal=0;
                        printf("\n-------------------------------------------------------------------\n");
                        printf("\n[Student %d of %d]\n",i+1,studentCount);
                        printf("Enter name of student %d: \n",i+1);
                        scanf("%99s", studentNames[i]);
                        for(int j=0; j<qCount; j++){
                            printf("\n[Quiz %d of %d] \n",j+1,qCount);
                            printf("Enter score for quiz %d: \n", j + 1);
                            scanf("%d", &quiz[i][j]);
                            while (quiz[i][j] < 0 || quiz[i][j] > qPerfect[j]) {
                            printf("Invalid score \n");
                            printf("Enter score for quiz %d: \n", j + 1);
                            scanf("%d", &quiz[i][j]);
                            
                            }//end of while quiz
                            qTotal+=quiz[i][j];
                        }
                        printf("\n-------------------------------------------------------------------\n");
                        for(int j=0; j<pCount; j++){
                            printf("\n[Project %d of %d]\n",j+1,pCount);
                            printf("Enter score for project %d: \n",j+1);
                            scanf("%d",&project[i][j]);
                            while (project[i][j] < 0 || project[i][j] > pPerfect[j]) {
                                printf("Invalid score \n");
                                printf("Enter score for project %d: \n", j + 1);
                                scanf("%d", &project[i][j]);
                                
                            }//end of while project
                            pTotal+=project[i][j];
                        }
                        printf("\n-------------------------------------------------------------------\n");
                        for(int j=0; j<hmCount; j++){
                            printf("\n[Homework %d of %d]\n",j+1,hmCount);
                            printf("Enter score for homework %d: \n",j+1);
                            scanf("%d",&homework[i][j]);
                            while (homework[i][j] < 0 || homework[i][j] > hmPerfect[j]) {
                                printf("Invalid score \n");
                                printf("Enter score for homework %d: \n", j + 1);
                                scanf("%d", &homework[i][j]);
                                
                               
                            }//end of while project
                            hmTotal+=homework[i][j];
                        }
                        studentGrades[i]=(qTotal/qCount*0.5)+(pTotal/pCount*0.3)+(hmTotal/hmCount*0.2);
                        studentScores[i]=(qTotal+pTotal+hmTotal);
                    }

    }//end of initstudents

    void ComparePerfecScore(){

                    printf("\n-------------------------------------------------------------------\n");

                    for(int i=0; i<studentCount; i++){
                        printf("\nStudent %d:\n",i+1);
                        printf("Name: %s \n",studentNames[i]);
                        for(int j=0; j<qCount; j++){
                            printf("Perfect score Quiz %d = %d \n",j+1,qPerfect[j]);
                            printf("Quiz %d: %d \n",j+1,quiz[i][j]);
                        }
                        for(int j=0; j<pCount; j++){
                            printf("Perfect score Project %d = %d \n",j+1,pPerfect[j]);
                            printf("Project %d: %d \n",j+1,project[i][j]);
                        }
                        for(int j=0; j<hmCount; j++){
                            printf("Perfect score Homework %d = %d \n",j+1,hmPerfect[j]);
                            printf("Homwork %d: %d \n",j+1,homework[i][j]);
                        }

                        
                    }

    }//end of compare perfect score display;



  char CompareStudent() {
                printf("\nEnter Student's Name to be search: ");    
                scanf("%99s", searchedname);

                for (int i = 0; i < studentCount; i++) {
                    if (strcmp(studentNames[i], searchedname) == 0) {
                    printf("Already exists.\n");
                                return 0;
                }
            }
                printf("Not found\n");
                return 1;
}

    void inputItems(){

     initPerfectScores();
     initStudents();
    }


        void ComputeGrades(){
                passingGrade=perfectFinalGrade*0.6;
                for(int i=0; i<studentCount; i++){
                    printf("\nName: %s",studentNames[i]);
                      printf("\nTotal Perfect Score: %d",qPerfectTotal+pPerfectTotal+hmPerfectTotal);
                    printf("\nPerfect Final Grade: %.2f", perfectFinalGrade);
                    printf("\nPassing grade: %.2f", passingGrade);
                    printf("\nQuiz total : %d", qTotal);
                    printf("\nProject total : %d", pTotal);
                    printf("\nHomework total : %d", hmTotal);
                    printf("\nTotal Scores: %d", studentScores[i]);
                    printf("\nYour grade: %.2f\n\n", studentGrades[i]);
                }

        }
        void DisplayRemarks(){
            
             passingGrade=perfectFinalGrade*0.6;
                for(int i=0; i<studentCount; i++){
                    
                    printf("\nName: %s",studentNames[i]);
                    if(studentGrades[i]>=passingGrade){
                        printf("\nPASSED\n");
                    }
                    else{
                        printf("\nFAILED\n");
                    }
                }


        }




    int getMenuChoice()
    {
        int choice;
        printf("\n[1] Initialize number of quiz/project/homework, perfect score, student score ");
        printf("\n[2] Compare Perfect score");
        printf("\n[3] Compare Student ");
        printf("\n[4] Compute Grades");
        printf("\n[5] Display Remarks");
        printf("\n[0] Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        return choice;
    }
