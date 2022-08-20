#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>


//FUNCTION PROTOTYPES
int menu();
void AddRecords();
void ViewRecords();
void UpdateRecords();
void SearchRecords();
void DeleteRecords();


struct students //beinginning of struct
{
    char StudFirstName[20], StudLastName[20], Teacher[20], grade[3];
    int StudentClass, Age;
    float Math, English, SocialStudies, Music, PhysicalEdu;
    float TotalGradeStudents;
    float Average;

}studs; //end of struct



//Start of main function
int main()
{
    int choice; //declaration of variable

    printf("\n\n\n\n");
        printf("\n\n\n\n");

        system("pause");
        system("cls");

    printf("\t*********************************************************************\n");
    printf("\tWelcome to mandeville primary and junior high school report generator\n");
    printf("\t*********************************************************************\n");


do
{
    choice=menu();
    system("cls");

    switch (choice)//allows user tp choose from the following options
    {

        case 1: AddRecords();
        break;
        case 2: ViewRecords();
        break;
         case 3: UpdateRecords();
         break;
          case 4: SearchRecords();
          break;
           case 5: DeleteRecords();
           break;

            case 6: exit(0);

            default: printf("\n\nError Invalid option chosen.");
            break;
    }

  }while (choice!=5);

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
            scanf( "%d", &choice); //reads the value entered
            return choice;
}


void AddRecords()
{
	//start of add function
	FILE *repository; //calls the file repository
    int StudentCount,NumberItems;
    float average;

      repository=(fopen("repository.txt","a+"));//creates the file repository.txt and opens it for reading and appending.

      	if (repository==NULL)
      	{
      		printf("FILE NOT FOUND!!\n");
      		return;
		}
		else
		{
			int exit; 
			
			printf("\n=======================================ADD RECORDS============================\n");
					  printf("\n HOW MANY RECORDS WILL YOU ADD:");
					  scanf("%d",&NumberItems);

			for (StudentCount=0; StudentCount<NumberItems; StudentCount++) //for loop counter
			{
				    printf("\t ENTER THE FOLLOWING INFORMATION BELOW: ");
				    printf("\n");
				    printf("\n STUDENT INFO");
				    printf("\n_________________________________________");
					printf("\n STUDENT's FIRST NAME: "); //prompts the user to enter data
                    scanf("%s", &studs.StudFirstName); // gets variable from struct and reads the data entered
                    fflush (stdin);  //clears buffer
                    printf("\n STUDENT'S LAST NAME: ");
                    scanf("%s", &studs.StudLastName);
                    fflush (stdin); //clears buffer
                    printf("\n TEACHER'S NAME: ");
                    scanf("%s", &studs.Teacher);
                    fflush (stdin);  //clears buffer
                    printf("\n STUDENT'S CLASS: ");
                    scanf("%d",&studs.StudentClass);
                    fflush (stdin);  //clears buffer
                    printf("\n STUDENT's AGE: ");
                    scanf("%d", &studs.Age);
                    fflush (stdin);  //clears buffer
                    printf("\n");
                    printf("\n SUBJECT GRADE ");
                    printf("\n_________________________________________");
                    printf("\n MATHEMATICS: " );
                    scanf("%f", &studs.Math);
                    fflush (stdin);  //clears buffer
                    printf("\n ENGLISH: ");
                    scanf("%f", &studs.English);
                    fflush (stdin);  //clears buffer
                    printf("\n SOCIALS STUDIES: ");
                    scanf("%f", &studs.SocialStudies);
                    fflush (stdin);  //clears buffer
                    printf("\n MUSIC: ");
                    scanf("%f", &studs.Music);
                    fflush (stdin);  //clears buffer
                    printf("\n PHYSICAL EDUCATION: ");
                    scanf("%f", &studs.PhysicalEdu);
                    fflush (stdin);  //clears buffer
        
              studs.TotalGradeStudents=studs.Math+studs.English+studs.SocialStudies+studs.Music+studs.PhysicalEdu;
              
                //Determines whether the student got an A,B or C based on their average
                studs.Average = studs.TotalGradeStudents/5;
                if(studs.Average>=80)// Determines whether the student got an A,B or C based on their average
                {
                    strcpy(studs.grade,"A");
                }
                else if(studs.Average<80 && studs.Average>=60)
                {
                    strcpy(studs.grade,"B");
                }
                else if(studs.Average<60)
                {
                    strcpy(studs.grade,"C");
                }
                
                
                    //write students information to the repository file
                    fprintf (repository,"\n%s\t %s\t %s\t", studs.StudFirstName,studs.StudLastName,studs.Teacher);
                    fprintf (repository,"%d\t %d\t %.2f\t", studs.StudentClass,studs.Age,studs.Math);
                    fprintf (repository,"%.2f\t %.2f\t %.2f\t %.2f", studs.English,studs.SocialStudies,studs.Music, studs.PhysicalEdu); //studs.grade);
			}
		}
		
	fclose(repository); //close the repository file
	printf("\nFILE REPOSITORY WAS SUCCESSFULLY CREATED!!\n\n");
	system("pause");
	system("cls");
 	return;
} //end of the add function


void ViewRecords()
{
	//start of view function
	FILE *repository;
    
    if( (repository=fopen("repository.txt","r")) == NULL)
	{
		printf("Nothing in pointer.\n");
	 } 
	 else
	 {
	 	// read from the file and prints it to the user
	 	while(!feof(repository))
	 	{
			fscanf (repository,"%s %s %s", studs.StudFirstName,studs.StudLastName,studs.Teacher);
			fscanf (repository,"%d %d %f", &studs.StudentClass, &studs.Age, &studs.Math);
			fscanf (repository,"%f %f %f %f", &studs.English,&studs.SocialStudies,&studs.Music, &studs.PhysicalEdu); //studs.grade);
			
			printf("\n\n STUDENT INFO ");
			printf("\n__________________________________________________________________________________________________");
			printf("\n\tSTUDENT FIRST NAME : %s",studs.StudFirstName);
			printf("\n\n\tSTUDENT LAST NAME: %s",studs.StudLastName);
			printf("\n\n\tTEACHER : %s",studs.Teacher);
			printf("\n\n\tSTUDENT CLASS : %d",studs.StudentClass);
			printf("\n\n\tSTUDENT AGE : %d",studs.Age);
			printf("\n");
			printf("\n\n\tSUBJECT GRADE ");
			printf("\n\t______________________________________________________________________________________");
			printf("\n\n\t MATHEMATICS: %.2f, ENGLISH: %.2f, SOCIAL STUDIES: %.2f, MUSIC: %.2f, PE: %.2f \n\n",studs.Math, studs.English, studs.SocialStudies, studs.Music, studs.PhysicalEdu);
	 		printf("\n\n");
		 }
		 rewind(repository); // brings pointer back to the start of the file
	 }

	fclose(repository); //close file
	system("pause");
	return;
}


void UpdateRecords()
{
	//start of update function
    FILE *repository;
    struct students studs[100];
    struct students temporarystuds[100];

    repository=fopen("repository.txt", "r+"); // open text in read
    int i=0, x=0, counter=0, found=0;
	char search[20];


        if (repository==NULL)
        {
            printf("FILE HAS NOT BEEN FOUND !!!\n");
            system("pause");
            system("cls");
            return;
        }
        else
        { // welcome message
        	printf("\n**************UPDATE REPOSITORY*************\n");
            printf("\n&&&&&&&&&&&&&&  WELCOME &&&&&&&&&&&&&&&&&&&&\n");
            //reads out information to the user to see what's there and what they want to update
            while (!feof(repository))
            {
            	fscanf(repository, "%s %s %s %d %d %f %f %f %f %f", 
					  &studs[i].StudFirstName,&studs[i].StudLastName,
					  &studs[i].Teacher,&studs[i].StudentClass,&studs[i].Age, 
					  &studs[i].Math,&studs[i].English,&studs[i].SocialStudies,
					  &studs[i].Music,&studs[i].PhysicalEdu);
				  
				strcpy(temporarystuds[i].StudFirstName,studs[i].StudFirstName);
				strcpy(temporarystuds[i].StudLastName,studs[i].StudLastName);
				strcpy(temporarystuds[i].Teacher,studs[i].Teacher);
				temporarystuds[i].StudentClass=studs[i].StudentClass;
				temporarystuds[i].Age=studs[i].Age;
				temporarystuds[i].Math=studs[i].Math;
				temporarystuds[i].English=studs[i].English;
				temporarystuds[i].SocialStudies=studs[i].SocialStudies;
				temporarystuds[i].Music=studs[i].Music;
				temporarystuds[i].PhysicalEdu=studs[i].PhysicalEdu;
				
				i++; //increment
            }
                rewind(repository); //brings pointer back to the beginning
                    
				printf("\n Please enter the student Last name of the record to be updated: ");
                scanf("%s",&search);
                        // collects new information for such student
                        for(counter=0; counter<i; counter++)
                        {

                            if(strcmp(search, temporarystuds[counter].StudLastName) == 0)
                            {
                                printf("\n Enter the student new first name: ");
                                scanf("%s",&temporarystuds[counter].StudFirstName);

                                printf("\n Enter the student new last  name: ");
                                scanf("%s",&temporarystuds[counter].StudLastName);

 								printf("\n Enter the teacher new name: ");
                                scanf("%s",&temporarystuds[counter].Teacher);

                                printf("\n Enter the student new class: ");
                                scanf("%d",&temporarystuds[counter].StudentClass);

                                printf("\n Enter the student new age: ");
                                scanf("%d",&temporarystuds[counter].Age);

                                printf("\n Enter the new Math grade: ");
                                scanf("%f",&temporarystuds[counter].Math);

                                printf("\n Enter the new English grade: ");
                                scanf("%f",&temporarystuds[counter].English);

                                printf("\n Enter the new Social Studies grade: ");
                                scanf("%f",&temporarystuds[counter].SocialStudies);

                                printf("\n Enter the new Music grade: ");
                                scanf("%f",&temporarystuds[counter].Music);

                                printf("\n Enter the new Physical Education grade: ");
                                scanf("%f",&temporarystuds[counter].PhysicalEdu);

                                system("cls");
								
								found = 1;
                            }
                        }
                        if(found == 0)
                        {
                        	printf("The record was not found.\n");
                        	system("pause");
						}

                 }
                 fclose(repository); //closes file
                    //open the repository and store the information in it
                 repository=fopen("repository.txt", "w");
        
				for (x=0;x<counter;x++)
				{
					fprintf (repository,"\n%s\t %s\t %s\t",
					temporarystuds[x].StudFirstName,
					temporarystuds[x].StudLastName,
					temporarystuds[x].Teacher);
					
					fprintf (repository,"%d\t %d\t %.2f\t",
					temporarystuds[x].StudentClass,
					temporarystuds[x].Age,
					temporarystuds[x].Math);
					
					fprintf (repository,"%.2f\t %.2f\t %.2f\t %.2f", 
					temporarystuds[x].English,
					temporarystuds[x].SocialStudies,
					temporarystuds[x].Music,
					temporarystuds[x].PhysicalEdu); //studs.grade);
				}
				
			fclose(repository); //closes file
			system("cls");
			printf("FILE HAS BEEN SUCCESSFULLY UPDATED\n\n"); //tells the user the file has been updated successfully
			system("pause");
			system("cls");
			return;
}//end of update function

void SearchRecords()
{
	//start of search function
    struct students studs;
    FILE *repository;
    char name[100];

         repository=fopen("repository.txt", "rb");  //open file in read binary
         if (repository==NULL)
         {
             printf("ERROR IN OPENING!!!\n");
             exit(1);
         }
                printf("\nENTER THE NAME OF STUDENT YOU WANT TO SEARCH: \n"); //prompts the user to enter name they want to search
                scanf("%d",&name);
                    // reads information from the file
                    while(fread(&studs,sizeof(studs),1,repository)==1)
                    {
                        if(strcmp(studs.StudFirstName,name)==0) //compare the first name to the name entered
                        {
                                    //prints out the information
                            printf("\nINFORMATION ABOUT %s",name);
                            printf("\nSTUDENT FIRST NAME:%s\nSTUDENT LAST NAME:%s\nTEACHER:%s\nSTUDENT CLASS:%d\nAGE:%d\nMATH:%d\nENGLISH:%d\nSOCIALSTUDIES:%d\nMUSIC:%d\nPHYSICAL EDUCATION:%d",
                                   studs.StudFirstName, studs.StudLastName, studs.Teacher, studs.StudentClass, studs.Age, studs.Math, studs.English, studs.SocialStudies, studs.Music, studs.PhysicalEdu);
                        }
                                else
                                    printf("\nFILE NOT FOUND!!!!");
                    }
                        fclose(repository);  //closes file
                            printf("\n*******PRESS ANY KEY*********");
                            system("pause");
                            system("cls");

}//end of search function

void DeleteRecords()
{
    FILE *repository, *repository2;
    char ReadFromFile;
    int RemoveLine, tem = 1;

        repository = fopen("repository.txt","r");
            printf("THIS FILE CURRENTLY CONTAINS: \n");
            printf("\n#######################################################################################################################"); // welcoming message
            printf("\nFIRST NAME\tLAST NAME\tTEACHER\tSTUDENT CLASS\tAGE\tMATHS\tENGLISH\tSOCIAL STUDIES\tMUSIC\tPE\n"); //display information headings 
            printf("\n#######################################################################################################################");

                ReadFromFile=fgetc(repository);

                    while(ReadFromFile!=EOF)
                    {
                        printf("%c",ReadFromFile);
                        ReadFromFile=fgetc(repository);

                    }
                        rewind(repository);
                            printf("\n\nENTER THE NUMBER OF THE LINE <<<<FROM ZERO >0< UPWARDS>>>> TO BE DELETED:");
                            scanf("%d", &RemoveLine);

                                RemoveLine= RemoveLine+1;
                                system("cls");

                                    repository2=fopen("repository2.txt","w");
                                        ReadFromFile=getc(repository);

                                         while(ReadFromFile!=EOF)
                                         {
                                             ReadFromFile=getc(repository);
                                                if(ReadFromFile=='\n')
                                                                tem++;
                                                if(tem!= RemoveLine)
                                                {
                                                    putc(ReadFromFile, repository2);
                                                }

                                         }
                                            fclose(repository);
                                            fclose(repository2);

                                            printf("\n\n");
                                            remove("repository.txt");
                                            rename("repository2.txt","repository.txt");

                                                    ViewRecords();
                                                    printf("\n\n");
													system("pause");
                                                    system("cls");
                                            
return;

}




















