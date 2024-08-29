#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void choice();
void getdata(char** name, char** pwd);
void save_file(FILE* f, char* name, char* pwd);
void compare(char* name, char* pwd);
int main()
{
    choice();
    return 0;
}
void choice()
{
    int choice=0;
    char* name=NULL;
    char* pwd=NULL;
    FILE* f=NULL;
    printf("1.Sign up\n");
    printf("2.Login\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("Hello!\n");
        getdata(&name,&pwd);
        save_file(f,name,pwd);
        break;
        case 2:
        printf("Welcome!\n");
        getdata(&name,&pwd);
        compare(name,pwd);
        break;
          default:
            printf("Invalid choice\n");
            break;
    }
    
    free(name);
    free(pwd);
}
void getdata(char** name, char** pwd)
{
    int d=255;
    *name=(char*)malloc(d*sizeof(char));
    if(*name==NULL)
    {
        printf("Error!");
        exit(1);
    }
    else
    {
        printf("Enter your name:");
        scanf("%s",*name);
    }
    *pwd=(char*)malloc(d*sizeof(char));
    if(*pwd==NULL)
    {
        printf("Error!");
        exit(1);
    }
    else
    {
        printf("Enter password:");
        scanf("%s",*pwd);
    }
}
void save_file(FILE* f, char* name, char* pwd)
{
    int n;
    char line[300];
    f=fopen("Name.txt","a");
        if(f==NULL)
        {
            printf("Error!");
        }
        else
        {
            fprintf(f,"%s %s\n",name, pwd);
            fclose(f);
        }
    /*f=fopen("Name.txt","r");
        while(fgets(line,255,f))
        {
            n++;
            printf("%s\n",line);
        } */
}
void compare(char* name, char* pwd)
{
    char line[300];
    char tmp_name[255];
    char tmp_pwd[255];
    char* t=NULL;
    FILE* f=NULL;
    f=fopen("Name.txt","r");
    if(f==NULL)
    {    
        printf("Error of opening!\n");
    }
        while(fgets(line,300,f))
        {
            t=strtok(line," ");
            if(t!=NULL)
            {
                strcpy(tmp_name,t);
            }
        
            t=strtok(NULL," ");
            if(t!=NULL)
            {
                strcpy(tmp_pwd,t);
                t=strtok(tmp_pwd, "\n");
                strcpy(tmp_pwd,t);
            }
            printf("%s\n",tmp_name);
            printf("%s",tmp_pwd);
            printf("%s\n",pwd);
            if(strcmp(name,tmp_name)==0)
            {
                printf("Déjà inscrit!\n");
                if(strcmp(pwd,tmp_pwd)==0)
                {
                    printf("Appel fonction ip\n");
                    break;
                }
                else
                {
                    printf("Mot de passe incorrect\n");
                    break;
                }
            }
        }
        
    fclose(f);
}