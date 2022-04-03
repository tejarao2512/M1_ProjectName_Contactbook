
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct person
{
    char name[40];
    char address[60];
     char father_name[40];
     char mother_name[35];
    long int mble_no;
    char sex[10];
    char mail[100];
    char citision_no[30];

    };
void menu();
void got();
void start();
void back();
void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();
int main()
{
    system("color 10");
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{
    system("cls");
printf("\t\t------------------WELCOME TO THE CONTACTBOOK--------------------");

printf("\n\n\t\t\t  Menu  \t\t\n\n");
printf("\t1.Add New Contact \n  \n \n \t2.Contact List \n\n \n \t3.Exit  \n \n \n\t4.Modify my Contacts   \n \n \n    \t5.Search the Contact \n \n  \n   \t6.Delete Contacts");

switch(getch())
{
    case '1':

                addrecord();
    break;
   case '2': listrecord();
    break;
    case '3': exit(0);
    break;
    case '4': modifyrecord();
    break;
    case '5': searchrecord();
    break;
    case '6': deleterecord();
    break;
    default:
                system("cls");
                printf("\nEnter from 1 to 6 only");
                printf("\n Press any key");
                getch();

menu();
}
}
        void addrecord()
{
        system("cls");
        FILE *f;
        struct person p;
        f=fopen("project","ab+");
        printf("\n Enter Contact Name: ");
        got(p.name);
        printf("\nEnter the Address: ");
        got(p.address);
        printf("\nEnter Father name: ");
        got(p.father_name);
        printf("\nEnter Mother name: ");
        got(p.mother_name);
        printf("\nEnter phone no.:");
        scanf("%ld",&p.mble_no);
        printf("Enter sex:");
        got(p.sex);
        printf("\nEnter E-mail:");
         got(p.mail);
        printf("\nEnter Citizen no:");
        got(p.citision_no);
        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        printf("\nRecord Saved Successfully.....");

fclose(f);

    printf("\n\nPress any key");

	 getch();
    system("cls");
    menu();
}
void listrecord()
{
    struct person p;
    FILE *f;
f=fopen("project","rb");
if(f==NULL)
{
printf("\nFile got error in listing :");

exit(1);
}
while(fread(&p,sizeof(p),1,f)==1)
{
     printf("\n\n\n Your Rcord is\n\n ");
        printf("\nName=%s\nAddress=%s\nFather name=%s\nMother name=%s\nMobile no=%ld\nSex=%s\nE-mail=%s\nCitizen no=%s",p.name,p.address,p.father_name,p.mother_name,p.mble_no,p.sex,p.mail,p.citision_no);

	 getch();
	 system("cls");
}
fclose(f);
 printf("\n Press any key");
 getch();
    system("cls");
menu();
}
void searchrecord()
{
    struct person p;
FILE *f;
char name[100];

f=fopen("project","rb");
if(f==NULL)
{
    printf("\n Error while opening\a\a\a\a");
    exit(1);

}
printf("\nEnter the contact person name to search\n");
got(name);
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        printf("\n\tDetail Information About %s",name);
        printf("\nName:%s\naddress:%s\nFather name:%s\nMother name:%s\nMobile no:%ld\nsex:%s\nE-mail:%s\nCitision no:%s",p.name,p.address,p.father_name,p.mother_name,p.mble_no,p.sex,p.mail,p.citision_no);
    }
        else
        printf("Unable to found a file");

}
 fclose(f);
  printf("\n Press any key");

	 getch();
    system("cls");
menu();
}
void deleterecord()
{
    struct person p;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("project","rb");
	if(f==NULL)
		{

			printf("Contact's data not yet recorded");

		}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)

            printf("Error while opening file");
		else

        {


		printf("Enter Contact person name:");
		got(name);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.name,name)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.name,name)==0)
                flag=1;
		}
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("No Contact Found to Delete.");
		remove("temp.txt");
	}
		else
		{
			remove("project");
			rename("temp.txt","project");
			printf("Record Deleted Successfully.....");

		}
	}
}
 printf("\n Press any key");

	 getch();
    system("cls");
menu();
}

void modifyrecord()
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
	char  name[50];
	f=fopen("project","rb+");
	if(f==NULL)
		{

			printf("Contacts data not yet recorded");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nEnter name of a contact to modify:\n");
            got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {



                    printf("\n Enter Contact Name:");
                    got(s.name);
                    printf("\nEnter the Address:");
                    got(s.address);
                    printf("\nEnter Father name:");
                    got(s.father_name);
                    printf("\nEnter Mother name:");
                    got(s.mother_name);
                    printf("\nEnter Phone no:");
                    scanf("%ld",&s.mble_no);
                    printf("\nEnter sex:");
                    got(s.sex);
                    printf("\nEnter E-mail:");
                    got(s.mail);
                    printf("\nEnter Citizen no\n");
                    got(s.citision_no);
                    fseek(f,sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);


            }
            if(flag==1)
            {
                printf("\n Your data modification is done.....");

            }
            else
            {
                    printf(" \n Unable to found data");

            }
            fclose(f);
	}
	 printf("\n Press any key");
	 getch();
    system("cls");
	menu();

}
void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}
