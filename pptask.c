#include<stdio.h>
#include <string.h>
struct user
{

	char name[50];
	char email[50];
	char pass[50];
    char confpass[50];
	char username[50];
};

void takeinput(char input[50])
{
	fgets(input,50,stdin);
    input[strlen(input)-1]=0;
};

char generatuser(char email[50],char username[50]) 
{
    for (int i = 0; i <= strlen(email); i++)
    {
        if (email[i]=='@')
        {
            break;
        }
        else
        {
            username[i]=email[i];
        }
        
    }
};
int main()
{
    FILE *us;
    int choice,userfound=0;
    char userlogin[50],passlogin[50];
    struct user users;
    printf("\n------------------");
    do {
        printf("\n1. Register\n2. Login\n3. Exit\nEnter Your Choice : ");
        scanf("%d", &choice);

    fgetc(stdin);
    switch (choice)
    {
    case 1:
    printf("\n");
    printf("Enter your Name :\t");
    takeinput(users.name);
    printf("\n");
    printf("Enter your Email :\t");
    takeinput(users.email);
    printf("\n");    
    printf("Enter your Pass :");
    takeinput(users.pass);
    printf("\n");
    printf("Confirm your Pass :");
    takeinput(users.confpass);
    if (!strcmp(users.pass,users.confpass))
    {
        printf("\nMatched Pass");
        generatuser(users.email,users.username);
        us=fopen("Users.dat","a+");
        fwrite(&users,sizeof(struct user),1,us);
        if(fwrite!=0)
        {
            printf("\nUser Regester Done");
            fclose(us);
        }
        else
        {
            printf("\nSorry Try Again");
        }
    }
    else
    {
        printf("\nNot Matched Pass");
    }
    break;

    case 2:
    printf("Enter your UserName :\t");
    takeinput(userlogin);
    printf("\n");    
    printf("Enter your Password :");
    takeinput(passlogin);
    printf("\n");
    us=fopen("Users.dat","r");
    while (fread(&users,sizeof(struct user),1,us))
    {
        if (!strcmp(users.username,userlogin))
        {
            if (!strcmp(users.pass,passlogin))
            {
                printf(" Login Succed ");
                printf("\n");
                printf("\n");
                
            }
            else
            {
                printf("!!!!!! Error Password !!!!!!");
            }
            userfound=1;
        }
        if (userfound=0)
        {
            printf("Sorry !! Just1 Create New Account :) ");
        }
        
    }
    fclose(us);
    break;
    case 3:
    printf("Exiting program. Good Bye");
    printf("\n");
    return 0;
    break;
    default:
        break;
    }
    } while (choice != 3);

    return 0;

}

