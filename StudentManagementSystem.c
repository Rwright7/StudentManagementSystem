#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// FUNCTION PROTOTYPES
int menu();
void AddRecords();
void ViewRecords();
void UpdateRecords();
void SearchRecords();
void DeleteRecords();

struct Student {
    char StudFirstName[20], StudLastName[20], Teacher[20], grade[3];
    int StudentClass = 0, Age = 0;
    float Math = 0.0f, English = 0.0f, SocialStudies = 0.0f, Music = 0.0f, PhysicalEdu = 0.0f;
    float TotalGradeStudents = 0.0f;
    float Average = 0.0f;
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
    int StudentCount = 0, NumberItems = 0;
    struct Student Stud;  


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
        
        for (StudentCount = 0; StudentCount < NumberItems; StudentCount++)
        {
            printf("\t ENTER THE FOLLOWING INFORMATION BELOW: ");
            printf("\n");
            printf("\n STUDENT INFO");
            printf("\n_________________________________________");
            printf("\n STUDENT's FIRST NAME: ");
            scanf("%s", &Stud.StudFirstName);
            fflush(stdin); // clears buffer
            printf("\n STUDENT'S LAST NAME: ");
            scanf("%s", &Stud.StudLastName);
            fflush(stdin);
            printf("\n TEACHER'S NAME: ");
            scanf("%s", &Stud.Teacher);
            fflush(stdin);
            printf("\n STUDENT'S CLASS: ");
            scanf("%d", &Stud.StudentClass);
            fflush(stdin);
            printf("\n STUDENT's AGE: ");
            scanf("%d", &Stud.Age);
            fflush(stdin);
            printf("\n");
            printf("\n SUBJECT GRADE ");
            printf("\n_________________________________________");
            printf("\n MATHEMATICS: ");
            scanf("%f", &Stud.Math);
            fflush(stdin);
            printf("\n ENGLISH: ");
            scanf("%f", &Stud.English);
            fflush(stdin);
            printf("\n SOCIALS STUDIES: ");
            scanf("%f", &Stud.SocialStudies);
            fflush(stdin);
            printf("\n MUSIC: ");
            scanf("%f", &Stud.Music);
            fflush(stdin);
            printf("\n PHYSICAL EDUCATION: ");
            scanf("%f", &Stud.PhysicalEdu);
            fflush(stdin);
            
            Stud.TotalGradeStudents = Stud.Math + Stud.English + Stud.SocialStudies + Stud.Music + Stud.PhysicalEdu;
            
            // Determines whether the student got an A,B or C based on their average
            Stud.Average = Stud.TotalGradeStudents / 5;
            if (Stud.Average >= 80) {
                strcpy(Stud.grade, "A");
            } else if (Stud.Average < 80 && Stud.Average >= 60) {
                strcpy(Stud.grade, "B");
            } else if (Stud.Average < 60) {
                strcpy(Stud.grade, "C");
            }
            
            // write students information to the repository file
            fprintf(repository, "\n%s\t %s\t %s\t", Stud.StudFirstName, Stud.StudLastName, Stud.Teacher);
            fprintf(repository, "%d\t %d\t %.2f\t", Stud.StudentClass, Stud.Age, Stud.Math);
            fprintf(repository, "%.2f\t %.2f\t %.2f\t %.2f", Stud.English, Stud.SocialStudies, Stud.Music, Stud.PhysicalEdu); // Stud.grade);
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
            fscanf(repository, "%s %s %s", Stud.StudFirstName, Stud.StudLastName, Stud.Teacher);
            fscanf(repository, "%d %d %f", &Stud.StudentClass, &Stud.Age, &Stud.Math);
            fscanf(repository, "%f %f %f %f", &Stud.English, &Stud.SocialStudies, &Stud.Music, &Stud.PhysicalEdu); // Stud.grade);
            
            printf("\n\n STUDENT INFO ");
            printf("\n__________________________________________________________________________________________________");
            printf("\n\tSTUDENT FIRST NAME : %s", Stud.StudFirstName);
            printf("\n\n\tSTUDENT LAST NAME: %s", Stud.StudLastName);
            printf("\n\n\tTEACHER : %s", Stud.Teacher);
            printf("\n\n\tSTUDENT CLASS : %d", Stud.StudentClass);
            printf("\n\n\tSTUDENT AGE : %d", Stud.Age);
            printf("\n");
            printf("\n\n\tSUBJECT GRADE ");
            printf("\n\t______________________________________________________________________________________");
            printf("\n\n\t MATHEMATICS: %.2f, ENGLISH: %.2f, SOCIAL STUDIES: %.2f, MUSIC: %.2f, PE: %.2f \n\n", Stud.Math, Stud.English, Stud.SocialStudies, Stud.Music, Stud.PhysicalEdu);
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
    struct Student Stud[100];
    struct Students TemporaryStud[100];

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
             &Stud[i].StudFirstName, &Stud[i].StudLastName, &Stud[i].Teacher,
             &Stud[i].StudentClass, &Stud[i].Age, &Stud[i].Math,
             &Stud[i].English, &Stud[i].SocialStudies, &Stud[i].Music,
             &Stud[i].PhysicalEdu);
            
            strcpy(TemporaryStud[i].StudFirstName, Stud[i].StudFirstName);
            strcpy(TemporaryStud[i].StudLastName, Stud[i].StudLastName);
            strcpy(TemporaryStud[i].Teacher, Stud[i].Teacher);
            
            TemporaryStud[i].StudentClass = Stud[i].StudentClass;
            TemporaryStud[i].Age = Stud[i].Age;
            TemporaryStud[i].Math = Stud[i].Math;
            TemporaryStud[i].English = Stud[i].English;
            TemporaryStud[i].SocialStudies = Stud[i].SocialStudies;
            TemporaryStud[i].Music = Stud[i].Music;
            TemporaryStud[i].PhysicalEdu = Stud[i].PhysicalEdu;
            
            i++;
        }
        
        rewind(repository); // brings pointer back to the beginning
        
        printf("\n Please enter the student Last name of the record to be updated: ");
        scanf("%s", &search);
        
        // collects new information for such student
        for (counter = 0; counter < i; counter++)
        {
            if (strcmp(search, TemporaryStud[counter].StudLastName) == 0)
            {
                printf("\n Enter the student new first name: ");
                scanf("%s", &TemporaryStud[counter].StudFirstName);
                
                printf("\n Enter the student new last  name: ");
                scanf("%s", &TemporaryStud[counter].StudLastName);
                
                printf("\n Enter the teacher new name: ");
                scanf("%s", &TemporaryStud[counter].Teacher);
                
                printf("\n Enter the student new class: ");
                scanf("%d", &TemporaryStud[counter].StudentClass);
                
                printf("\n Enter the student new age: ");
                scanf("%d", &TemporaryStud[counter].Age);
                
                printf("\n Enter the new Math grade: ");
                scanf("%f", &TemporaryStud[counter].Math);
                
                printf("\n Enter the new English grade: ");
                scanf("%f", &TemporaryStud[counter].English);
                
                printf("\n Enter the new Social Studies grade: ");
                scanf("%f", &TemporaryStud[counter].SocialStudies);
                
                printf("\n Enter the new Music grade: ");
                scanf("%f", &TemporaryStud[counter].Music);
                
                printf("\n Enter the new Physical Education grade: ");
                scanf("%f", &TemporaryStud[counter].PhysicalEdu);
                
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
        fprintf(repository, "\n%s\t %s\t %s\t", TemporaryStud[x].StudFirstName, TemporaryStud[x].StudLastName, TemporaryStud[x].Teacher);
        
        fprintf(repository, "%d\t %d\t %.2f\t", TemporaryStud[x].StudentClass, TemporaryStud[x].Age, TemporaryStud[x].Math);
        
        fprintf(repository, "%.2f\t %.2f\t %.2f\t %.2f", TemporaryStud[x].English, TemporaryStud[x].SocialStudies, TemporaryStud[x].Music, TemporaryStud[x].PhysicalEdu);
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
    struct Student Stud;
    FILE *repository = fopen("repository.txt", "rb");
    char name[100];
    
    if (repository == NULL)
    {
        printf("ERROR IN OPENING!!!\n");
        exit(1);
    }
    
    printf("\nENTER THE NAME OF STUDENT YOU WANT TO SEARCH: \n");
    scanf("%s", &name);
    
    // reads information from the file
    while (fread(&Stud, sizeof(Stud), 1, repository) == 1)
    {
        if (strcmp(Stud.StudFirstName, name) == 0) // compare the first name to the name entered
        {
            // prints out the information
            printf("\nINFORMATION ABOUT %s", name);
            printf("\nSTUDENT FIRST NAME:%s\nSTUDENT LAST NAME:%s\nTEACHER:%s\nSTUDENT CLASS:%d\nAGE:%d\nMATH:%d\nENGLISH:%d\nSOCIALSTUDIES:%d\nMUSIC:%d\nPHYSICAL EDUCATION:%d",
                Stud.StudFirstName, Stud.StudLastName, Stud.Teacher,
                Stud.StudentClass, Stud.Age, Stud.Math, Stud.English,
                Stud.SocialStudies, Stud.Music, Stud.PhysicalEdu);
        }
        else
        {
            printf("\nFILE NOT FOUND!!!!");
        }
    }
    
    fclose(repository);
    printf("\n*******PRESS ANY KEY*********");
    system("pause");
    system("cls");
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
