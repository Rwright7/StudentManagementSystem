#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FUNCTION PROTOTYPES
int menu();
void AddRecords();
void ViewRecords();
void UpdateRecords();
void SearchRecords();
void DeleteRecords();

struct student {
    char studFirstName[20], studLastName[20], Teacher[20], grade[3];
    int studentClass, Age;
    float Math, English, Socialstudies, Music, PhysicalEdu;
    float TotalGradestudents;
    float Average;
};



int main()
{
    int choice;
    
    printf("\n\n\n\n");
    printf("\n\n\n\n");
    
    system("pause");
    system("cls");
    
    printf("\t*********************************************************************\n");
    printf("\tWelcome to mandeville primary and junior high school report generator\n");
    printf("\t*********************************************************************\n");
    
    do
    {
        choice = menu();
        system("cls");
        
        switch (choice)
        {

            case 1:
            AddRecords();
            break;
            case 2:
            ViewRecords();
            break;
            case 3:
            UpdateRecords();
            break;
            case 4:
            SearchRecords();
            break;
            case 5:
            DeleteRecords();
            break;
            
            case 6:
            exit(0);
            
            default:
            printf("\n\nError Invalid option chosen.");
            break;
        }
    } while (choice != 5);
}


int menu()
{
    int choice;
    
    printf("Enter whichever number that aligns with what you want to do.\n\n");
    printf("1) Add Record(s)\n");
    printf("2) View Record(s)\n");
    printf("3) Update Record(s)\n");
    printf("4) Search Record(s)\n");
    printf("5) Delete Record(s)\n");
    printf("6) Exit menu\n");
    scanf("%d", &choice);
    return choice;
}


void AddRecords()
{
    FILE *repository; // calls the file repository
    int studentCount = 0, NumberItems = 0;
    struct student stud;  


    repository = (fopen("repository.txt", "a+")); // creates the file repository.txt and opens it for reading and appending.
    
    if (repository == NULL)
    {
        printf("FILE NOT FOUND!!\n");
        return;
    }
    else
    {
        int exit;
        
        printf("\n=======================================ADD RECORDS============================\n");
        printf("\n HOW MANY RECORDS WILL YOU ADD:");
        scanf("%d", &NumberItems);
        
        for (studentCount = 0; studentCount < NumberItems; studentCount++)
        {
            printf("\t ENTER THE FOLLOWING INFORMATION BELOW: ");
            printf("\n");
            printf("\n STUDENT INFO");
            printf("\n_________________________________________");
            printf("\n STUDENT's FIRST NAME: ");
            scanf("%s", stud.studFirstName);
            fflush(stdin); // clears buffer
            printf("\n STUDENT'S LAST NAME: ");
            scanf("%s", stud.studLastName);
            fflush(stdin);
            printf("\n TEACHER'S NAME: ");
            scanf("%s", stud.Teacher);
            fflush(stdin);
            printf("\n STUDENT'S CLASS: ");
            scanf("%d", &stud.studentClass);
            fflush(stdin);
            printf("\n STUDENT's AGE: ");
            scanf("%d", &stud.Age);
            fflush(stdin);
            printf("\n");
            printf("\n SUBJECT GRADE ");
            printf("\n_________________________________________");
            printf("\n MATHEMATICS: ");
            scanf("%f", &stud.Math);
            fflush(stdin);
            printf("\n ENGLISH: ");
            scanf("%f", &stud.English);
            fflush(stdin);
            printf("\n SOCIALS STUDIES: ");
            scanf("%f", &stud.Socialstudies);
            fflush(stdin);
            printf("\n MUSIC: ");
            scanf("%f", &stud.Music);
            fflush(stdin);
            printf("\n PHYSICAL EDUCATION: ");
            scanf("%f", &stud.PhysicalEdu);
            fflush(stdin);
            
            stud.TotalGradestudents = stud.Math + stud.English + stud.Socialstudies + stud.Music + stud.PhysicalEdu;
            
            // Determines whether the student got an A,B or C based on their average
            stud.Average = stud.TotalGradestudents / 5;
            if (stud.Average >= 80) {
                strcpy(stud.grade, "A");
            } else if (stud.Average < 80 && stud.Average >= 60) {
                strcpy(stud.grade, "B");
            } else if (stud.Average < 60) {
                strcpy(stud.grade, "C");
            }
            
            // write students information to the repository file
            fprintf(repository, "\n%s\t %s\t %s\t", stud.studFirstName, stud.studLastName, stud.Teacher);
            fprintf(repository, "%d\t %d\t %.2f\t", stud.studentClass, stud.Age, stud.Math);
            fprintf(repository, "%.2f\t %.2f\t %.2f\t %.2f", stud.English, stud.Socialstudies, stud.Music, stud.PhysicalEdu); // stud.grade);
        }
    }
    
    fclose(repository);
    printf("\nFILE REPOSITORY WAS SUCCESSFULLY CREATED!!\n\n");
    system("pause");
    system("cls");
    return;
}


void ViewRecords()
{
    struct student stud;
    FILE *repository = fopen("repository.txt", "r");
    if (repository == NULL)
    {
        puts("Nothing in pointer.\n");
    }
    else
    {
        // read from the file and prints it to the user
        while (!feof(repository))
        {
            fscanf(repository, "%s %s %s", stud.studFirstName, stud.studLastName, stud.Teacher);
            fscanf(repository, "%d %d %f", &stud.studentClass, &stud.Age, &stud.Math);
            fscanf(repository, "%f %f %f %f", &stud.English, &stud.Socialstudies, &stud.Music, &stud.PhysicalEdu); // stud.grade);
            
            printf("\n\n STUDENT INFO ");
            printf("\n__________________________________________________________________________________________________");
            printf("\n\tSTUDENT FIRST NAME : %s", stud.studFirstName);
            printf("\n\n\tSTUDENT LAST NAME: %s", stud.studLastName);
            printf("\n\n\tTEACHER : %s", stud.Teacher);
            printf("\n\n\tSTUDENT CLASS : %d", stud.studentClass);
            printf("\n\n\tSTUDENT AGE : %d", stud.Age);
            printf("\n");
            printf("\n\n\tSUBJECT GRADE ");
            printf("\n\t______________________________________________________________________________________");
            printf("\n\n\t MATHEMATICS: %.2f, ENGLISH: %.2f, SOCIAL STUDIES: %.2f, MUSIC: %.2f, PE: %.2f \n\n", stud.Math, stud.English, stud.Socialstudies, stud.Music, stud.PhysicalEdu);
            printf("\n\n");
        }
        rewind(repository); // brings pointer back to the start of the file
    }
    
    fclose(repository);
    system("pause");
    return;
}


void UpdateRecords()
{
    FILE *repository;
    struct student stud[100];
    struct student Temporarystud[100];

    repository = fopen("repository.txt", "r+");
    int i = 0, x = 0, counter = 0, found = 0;
    char search[20];
    
    if (repository == NULL)
    {
        printf("FILE HAS NOT BEEN FOUND !!!\n");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        // welcome message
        printf("\n**************UPDATE REPOSITORY*************\n");
        printf("\n&&&&&&&&&&&&&&  WELCOME &&&&&&&&&&&&&&&&&&&&\n");
        // reads out information to the user to see what's there and what they want
        // to update
        while (!feof(repository))
        {
            fscanf(repository, "%s %s %s %d %d %f %f %f %f %f",
             stud[i].studFirstName, stud[i].studLastName, stud[i].Teacher,
             &stud[i].studentClass, &stud[i].Age, &stud[i].Math,
             &stud[i].English, &stud[i].Socialstudies, &stud[i].Music,
             &stud[i].PhysicalEdu);
            
            strcpy(Temporarystud[i].studFirstName, stud[i].studFirstName);
            strcpy(Temporarystud[i].studLastName, stud[i].studLastName);
            strcpy(Temporarystud[i].Teacher, stud[i].Teacher);
            
            Temporarystud[i].studentClass = stud[i].studentClass;
            Temporarystud[i].Age = stud[i].Age;
            Temporarystud[i].Math = stud[i].Math;
            Temporarystud[i].English = stud[i].English;
            Temporarystud[i].Socialstudies = stud[i].Socialstudies;
            Temporarystud[i].Music = stud[i].Music;
            Temporarystud[i].PhysicalEdu = stud[i].PhysicalEdu;
            
            i++;
        }
        
        rewind(repository); // brings pointer back to the beginning
        
        printf("\n Please enter the student Last name of the record to be updated: ");
        scanf("%s", search);
        
        // collects new information for such student
        for (counter = 0; counter < i; counter++)
        {
            if (strcmp(search, Temporarystud[counter].studLastName) == 0)
            {
                printf("\n Enter the student new first name: ");
                scanf("%s", Temporarystud[counter].studFirstName);
                
                printf("\n Enter the student new last  name: ");
                scanf("%s", Temporarystud[counter].studLastName);
                
                printf("\n Enter the teacher new name: ");
                scanf("%s", Temporarystud[counter].Teacher);
                
                printf("\n Enter the student new class: ");
                scanf("%d", &Temporarystud[counter].studentClass);
                
                printf("\n Enter the student new age: ");
                scanf("%d", &Temporarystud[counter].Age);
                
                printf("\n Enter the new Math grade: ");
                scanf("%f", &Temporarystud[counter].Math);
                
                printf("\n Enter the new English grade: ");
                scanf("%f", &Temporarystud[counter].English);
                
                printf("\n Enter the new Social studies grade: ");
                scanf("%f", &Temporarystud[counter].Socialstudies);
                
                printf("\n Enter the new Music grade: ");
                scanf("%f", &Temporarystud[counter].Music);
                
                printf("\n Enter the new Physical Education grade: ");
                scanf("%f", &Temporarystud[counter].PhysicalEdu);
                
                system("cls");
                
                found = 1;
            }
        }
        if (found == 0)
        {
            printf("The record was not found.\n");
            system("pause");
        }
    }
    
    fclose(repository);
    // open the repository and store the information in it
    repository = fopen("repository.txt", "w");
    
    for (x = 0; x < counter; x++)
    {
        fprintf(repository, "\n%s\t %s\t %s\t", Temporarystud[x].studFirstName, Temporarystud[x].studLastName, Temporarystud[x].Teacher);
        
        fprintf(repository, "%d\t %d\t %.2f\t", Temporarystud[x].studentClass, Temporarystud[x].Age, Temporarystud[x].Math);
        
        fprintf(repository, "%.2f\t %.2f\t %.2f\t %.2f", Temporarystud[x].English, Temporarystud[x].Socialstudies, Temporarystud[x].Music, Temporarystud[x].PhysicalEdu);
    }
    
    fclose(repository);
    system("cls");
    printf("FILE HAS BEEN SUCCESSFULLY UPDATED\n\n");
    system("pause");
    system("cls");
    return;
}


void SearchRecords()
{
    struct student stud; 
    char name[20];
    FILE *repository = fopen("repository.txt", "r");

    printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Students Record !!!!!!!!!!!!!\n");
    printf("\n Enter Student Name to be viewed:");
    scanf("%s",name);
    fflush(stdin);
    printf("\n");

    while(fscanf(repository,"%s %s %s %d %d %.2f %.2f %.2f %.2f %.2f\n",stud.studFirstName, stud.studLastName, stud.Teacher,
    &stud.studentClass, &stud.Age, &stud.Math, &stud.English, &stud.Socialstudies, &stud.Music, &stud.PhysicalEdu)!=EOF)
    {
        if(strcmp(stud.studFirstName,name)==0)
        {

            printf("Full Name\t");
            printf("Teacher\t");
            printf("Class\t");
            printf("Age\t");
            printf("Math\t");
            printf("English\t");
            printf("Socialstudies\t");
            printf("Music\t");
            printf("Physical Education\t\n");
            printf("======================================================");
            printf("%s %s\t",stud.studFirstName, stud.studLastName);
            printf("%s\t",stud.Teacher);
            printf("%d\t",stud.studentClass);
            printf("%d\t",stud.Age);
            printf("%.2f\t",stud.Math);
            printf("%.2f\t",stud.English);
            printf("%.2f\t",stud.Socialstudies);
            printf("\t%.2f\t",stud.Music);
            printf("%.2f\t",stud.PhysicalEdu);
            printf("\n");
            break;
        }
    }
    if(strcmp(stud.studFirstname,name)!=0)
    {
        printf("Record not found!");
    }
    fclose(repository); 
}


void DeleteRecords()
{
    FILE *repository, *repository2;
    char ReadFromFile;
    int RemoveLine = 0, tem = 1;
    
    repository = fopen("repository.txt", "r");
    printf("THIS FILE CURRENTLY CONTAINS: \n");
    printf("\n#######################################################################################################################");
    printf("\nFIRST NAME\tLAST NAME\tTEACHER\tSTUDENT CLASS\tAGE\tMATHS\tENGLISH\tSOCIAL STUDIES\tMUSIC\tPE\n");
    printf("\n#######################################################################################################################");
    
    ReadFromFile = fgetc(repository);
    
    while (ReadFromFile != EOF) {
        printf("%c", ReadFromFile);
        ReadFromFile = fgetc(repository);
    }
    
    rewind(repository);
    printf("\n\nENTER THE NUMBER OF THE LINE <<<<FROM ZERO >0< UPWARDS>>>> TO BE DELETED:");
    scanf("%d", &RemoveLine);
    
    RemoveLine = RemoveLine + 1;
    system("cls");
    
    repository2 = fopen("repository2.txt", "w");
    ReadFromFile = getc(repository);
    
    while (ReadFromFile != EOF)
    {
        ReadFromFile = getc(repository);
        if (ReadFromFile == '\n')
        {
            tem++;
        }
        if (tem != RemoveLine)
        {
            putc(ReadFromFile, repository2);
        }
    }
    
    fclose(repository);
    fclose(repository2);
    
    printf("\n\n");
    remove("repository.txt");
    rename("repository2.txt", "repository.txt");
    
    ViewRecords();
    printf("\n\n");
    system("pause");
    system("cls");
    
    return;
}
