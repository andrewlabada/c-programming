    #include<stdio.h>
    #include <string.h>
    //global variables to access them worldwide
    int  hmTotal=0,pTotal=0,qTotal=0, j,choice,yes,quiz[100],project[100], homework[100], qPerfect[100],pPerfect[100],hmPerfect[100], studentCount = 0, qCount=0, pCount=0, hmCount=0, qPerfectTotal=0, pPerfectTotal=0, hmPerfectTotal=0;
    float finalGrade=0.0, passingGrade, perfectFinalGrade;
    char studentNames[50][50],searchedname[100];
    float studentGrades[50];
    int studentScores[50];
    //function declarations
    int getMenuChoice();
    void inputItems();
    char CompareStudent();
    void ComparePerfecScore();
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

    void inputItems(){

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

                        //initialization of students and scores;
                        printf("\nEnter number of students: ");
                        scanf("%d",&studentCount);
                            for(int i=0; i<studentCount; i++){
                            printf("\n-------------------------------------------------------------------\n");
                            printf("\n[Student %d of %d]\n",i+1,studentCount);
                            printf("Enter name of student %d: \n",i+1);
                            scanf("%99s", studentNames[i]);
                        for(int j=0; j<qCount; j++){
                                printf("\n[Quiz %d of %d] \n",j+1,qCount);
                                printf("Enter score for quiz %d: \n", j + 1);
                                scanf("%d", &quiz[j]);
                                
                                while (quiz[j] < 0 || quiz[j] > qPerfect[j]) {
                                printf("Invalid score \n");
                                printf("Enter score for quiz %d: \n", j + 1);
                                scanf("%d", &quiz[j]);
                            
                            }//end of while quiz
                            qTotal+=quiz[j];
                        }
                        printf("\n-------------------------------------------------------------------\n");
                        for(int k=0; k<pCount; k++){
                                printf("\n[Project %d of %d]\n",k+1,pCount);
                                printf("Enter score for project %d: \n",k+1);
                                scanf("%d",&project[k]);
                                while (project[k] < 0 || project[k] > pPerfect[k]) {
                                printf("Invalid score \n");
                                printf("Enter score for project %d: \n", k + 1);
                                scanf("%d", &project[k]);
                                
                            }//end of while project
                                pTotal+=project[k];
                            
                        }
                        printf("\n-------------------------------------------------------------------\n");
                        for(int l=0; l<hmCount; l++){
                                printf("\n[Homework %d of %d]\n",l+1,hmCount);
                                printf("Enter score for homework %d: \n",l+1);
                                scanf("%d",&homework[l]);
                                while (homework[l] < 0 || homework[l] > hmPerfect[l]) {
                                printf("Invalid score \n");
                                printf("Enter score for homework %d: \n", l + 1);
                                scanf("%d", &homework[l]);
                               
                            }//end of while project
                                hmTotal+=homework[l];
                        }

                        studentGrades[i]=(qTotal/qCount*0.5)+(pTotal/pCount*0.3)+(hmTotal/hmCount*0.2);
                        studentScores[i]=(qTotal+pTotal+hmTotal);            
                    }
    }
 

    void ComparePerfecScore(){

                    printf("\n-------------------------------------------------------------------\n");
                    for(int i=0; i<studentCount; i++){
                        printf("\nStudent %d:\n",i+1);
                        printf("Name: %s \n",studentNames[i]);
                        for(int i=0; i<qCount; i++){
                        printf("Perfect score Quiz %d = %d \n",i+1,qPerfect[i]);
                        printf("Quiz %d: %d \n",i+1,quiz[j]);
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
    }//end bracket of compare student

    

    void ComputeGrades(){
                passingGrade=perfectFinalGrade*0.6;
                for(int i=0; i<studentCount; i++){
                    printf("\nName: %s",studentNames[i]);
                    printf("\nTotal Perfect Score: %d",qPerfectTotal+pPerfectTotal+hmPerfectTotal);
                    printf("\nPerfect Final Grade: %.2f", perfectFinalGrade);
                    printf("\nPassing grade: %.2f", passingGrade);
                    printf("\nQuiz Total: %d", qTotal);
                    printf("\nProject Total: %d", pTotal);
                    printf("\nHomework total: %d", hmTotal);
                    printf("\nTotal Scores: %d", studentScores[i]);
                    printf("\nYour grade: %.2f\n\n", studentGrades[i]);

                }

        }//end bracket of computeGrades

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
        }//end bracket of display remarks



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
