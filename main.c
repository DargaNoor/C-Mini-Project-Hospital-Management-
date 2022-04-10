#include<stdio.h>
#include<string.h>
//#include <stdlib.h>
struct ad           //structure of the details of patient
{
    char name[30];
    char disease[30];
    int cabin;
    int phone;
    int age;
} x[100];
int n,i,j=0,a=0,sum=0,g,flag,num;    //declaring globally
void read();
void add();
void view();
void search();
void edit();
void del();
void show();
void write();
int main()
{
    read();
    int c,i,q;
    printf("\tHospital Management System\n");
    int m,n;
    for(m=1; m<=4; m++)  //For printing the pattern
    {
        for(n=1; n<=5; n++)
            printf(" ");
        for(n=1; n<=m-1; n++)
        {
            printf(" ");
        }
        for(n=1; n<=4-m+1; n++)
        {
            if(n==4-m+1 || m==1 || m==4)
                printf("*");
            else
                printf(" ");
        }
        for(n=1; n<=4-m+1; n++)
        {
            if(n==1 ||m==1 || m==4)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    while(c!=6)
    {

        printf("\t** Enter your choice **\n 1: Add Patient Details\n 2: View Information\n 3: Search (for viewing a particular pateient record\n 4: Edit Information\n 5: Delete any specific or whole Information\n 6: Exit\n");
        printf("Enter the option:\n");
        fflush(stdin);    //if by mistake press an enter key
        scanf("%d",&c);
        switch(c)
        {
            case 1:system("cls");
                   add();            //adding the details
                   printf("\n\t** Patient Record added successgully **\n\n");
                   break;
            case 2:system("cls");
                   view();           //viewing the entered information
                   break;
            case 3:system("cls");
                   search();          //search
                   break;
            case 4:system("cls");
                   edit();           //editing the entered information
                   printf("\n\t** Patient Record edited successgully **\n\n");
                   break;
            case 5:system("cls");
                   del();           //delete
                   printf("\n\t** Patient Record deleted successgully **\n\n");
                   break;
            case 6:write();
                   return 0;
            default:system("cls");
                    printf("\n\tPlease enter the correct option\n\n");
        }
        printf("\n\n");
    }
}
void add()
{
    printf("\n\n");
    printf("\tAlready data entered on to the database = %d\n\n",num);  //keeps the track of no. of inputs
    printf("Enter the no. of entry you want to add = ");
    scanf("%d",&n);
    sum=n+num;
    for(i=num,j=0; i<sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter patient's Name: ");
        gets(x[i].name);                   //if patient's name is more than one string
        fflush(stdin);
        printf("Enter the disease name: ");
        gets(x[i].disease);
        fflush(stdin);
        printf("Enter the age: ");
        scanf("%d",&x[i].age);
        fflush(stdin);
        printf("Enter cabin no: ");
        scanf("%d",&x[i].cabin);
        fflush(stdin);
        printf("Enter phone number : ");
        scanf("%d",&x[i].phone);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;    //incrementing num as another data has been entered
    }
}

void view()
{
    for(i=0; i<num; i++)
    {
        printf("\n Serial Number=%d\n",i);
        printf("  Name = ");
        puts(x[i].name);
        printf(" Disease = ");
        puts(x[i].disease);
        printf(" Cabin no = %d\n Phone number = 0%d\n Age=%d\n",x[i].cabin,x[i].phone,x[i].age);
    }
}
void edit()
{
    int q,p,l,i,w=1,ji;
    char names[50];
    fflush(stdin);
    printf("To edit the details of the patient you must know name or phone no.\n\tPress 1 if you know the Name\n\tPress 2 if you know the Phone number\n\tPress 3 if you know the Cabin number :\n");
    scanf("%d",&l);
    switch(l)
    {
        case 1:fflush(stdin);
               printf("Enter the name(must be entered for valid check):\n");
               gets(names);
               for(i=0;i<num;i++)
               {
                    if(strcmp(x[i].name,names)==0)
                    {
                        p=i;
                        w=0;
                    }
               }
               if(w==1)
               {
                    printf("Please enter correct name else Wrong person is handling the system will be considered\n");
                    return ;

               }
               break;
       case 2:fflush(stdin);
              printf("Enter the Phone number(must be entered for valid check):\n");
              scanf("%d",&ji);
              for(i=0;i<num;i++)
               {
                    if(x[i].phone==ji)
                    {
                        p=i;
                        w=0;
                    }
               }
              if(w==1)
               {
                    printf("Please enter correct phone number else Wrong person is handling the system will be considered\n");
                    return;
               }
              break;
       case 3:fflush(stdin);
              printf("Enter the Cabin number(must be entered for valid check):\n");
              scanf("%d",&ji);
              for(i=0;i<num;i++)
               {
                    if(x[i].cabin==ji)
                    {
                        p=i;
                        w=0;
                    }
               }
              if(w==1)
               {
                    printf("Please enter correct cabin number else Wrong person is handling the system will be considered\n");
                    return;
               }
              break;
    }
    printf("Press the option for which you want to edit:\n");
    printf("\t1. Name\n\t2. Disease name\n\t3. Age\n\t4. Cabin\n\t5. Phone nunber\n");
    printf("Enter your option\n");
    scanf("%d",&q);    //option
    if(q<=5)
    {
        if(p<num)
        {
            if(q==1)
            {
                fflush(stdin);
                printf("Enter the new name : ");
                gets(x[p].name);

            }
            else if(q==2)
            {
                fflush(stdin);
                printf("Enter the new Disease name : ");
                gets(x[p].disease);
            }
            else if(q==3)
            {
                fflush(stdin);
                printf("Enter the new Age : ");
                scanf("%d",&x[p].age);
            }

            else if(q==4)
            {
                fflush(stdin);
                printf("Enter the new Cabin number : ");
                scanf("%d",&x[p].cabin);
            }

            else if(q==5)
            {
                fflush(stdin);
                printf("Enter the new Phone number = ");
                scanf("%d",&x[p].phone);
            }
        }
        else
        {
            printf("\n\n\tInvalid option entered\n\t   Try Again!!\n\n");
        }
    }
    else
    {
        printf("\n\n\tInvalid option entered\n\t   Try Again!!\n\n");
    }
}
void search()
{
    int s,h,f,l,ji,w=1;
    char u[100],names[50];
    fflush(stdin);
    printf("To search the details of a particular patient you must know name or phone no.\n\tPress 1 if you know the Name\n\tPress 2 if you know the Phone number:\n");
    scanf("%d",&l);
    switch(l)
    {
        case 1:fflush(stdin);
               printf("Enter the name(must be entered for valid check):\n");
               gets(names);
               for(i=0;i<num;i++)
               {
                    if(strcmp(x[i].name,names)==0)
                    {
                        s=i;
                        w=0;
                    }
               }
               if(w==1)
               {
                    printf("Please enter correct name else Wrong person is handling the system will be considered\n");
                    return ;

               }
               break;
       case 2:fflush(stdin);
              printf("Enter the Phone number(must be entered for valid check):\n");
              scanf("%d",&ji);
              for(i=0;i<num;i++)
               {
                    if(x[i].phone==ji)
                    {
                        s=i;
                        w=0;
                    }
               }
              if(w==1)
               {
                    printf("Please enter correct phone number else Wrong person is handling the system will be considered\n");
                    return;
               }
              break;
    }
    printf("Press the option through which you want to search: \n");
    printf("1. Serial no.\n2. Name\n3. Disease\n4. Cabin no.\n5. Phone no.\n6. Age\n\n");
    printf("Enter the option:");
    scanf("%d",&h);
    if(h==1)
    {
        printf("Enter Serial number of the patient=");
        scanf("%d",&s);
        if(s<num)
        {
            printf("\n");
            printf("Serial Number=%d\n",s);
            printf("Name = ");
            puts(x[s].name);
            printf("Disease = ");
            puts(x[s].disease);
            printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[s].cabin,x[s].phone,x[s].age);
            printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if(h==2)//problem is here.........
    {
        int f=1;
        fflush(stdin);
        printf("Enter your name=");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].name)==0)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("\nNot Found\n");



    }
    else if(h==3)
    {
        int f=1;
        fflush(stdin);
        printf("Enter Disease = ");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].disease)==0)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;
            }


        }
        if(f==1)
            printf("\nNot Found\n");


    }
    else if(h==4)
    {
        int f=1;
        printf("Enter Cabin number = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].cabin)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Not Found\n\n");

    }
    else if(h==5)
    {
        int f=1;
        printf("Enter Phone number = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].phone)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Not Found");
    }
    else if(h==6)
    {
        int f=1;
        printf("Enter Age = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].age)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Not Found\n\n");

    }
    else
        printf("\n\nInvalid input\n\n");
}
void del()
{
    int f,h;
    printf("Enter the serial number of the patient that you want to delete=");
    scanf("%d",&f);
    if(f<num)
    {
        printf("What do you want ?\n");
        printf("1.Remove the whole record\n2.Remove Name\n3.Remove Disease\n4.Remove age\n5.Remove Cabin\n6.Remove phone number\nOption = ");
        scanf("%d",&h);
        if(h==1)
        {
            while(f<num)
            {
                strcpy(x[f].name,x[f+1].name);
                strcpy(x[f].disease,x[f+1].disease);
                x[f].age=x[f+1].age;
                x[f].cabin=x[f+1].cabin;
                x[f].phone=x[f+1].phone;
                f++;
            }
            num--;
        }
        else if(h==2)
        {
            strcpy(x[f].name,"Cleared");

        }
        else if(h==3)
        {
            strcpy(x[f].disease,"Cleared");
        }
        else if(h==4)
        {
            x[f].age=0;
        }
        else if(h==5)
        {
            x[f].cabin=0;
        }
        else if(h==6)
        {
            x[f].phone=0;
        }

    }
    else
        printf("\n\nInvalid Serial number\n");

}
void read()
{
    FILE *fp = fopen("patient.txt","r");
    if(fp == NULL)
    {
        //create empty file, so that we can open it and edit or we can use in next execution of program
        fp = fopen("patient.txt","w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, it is exiting...\n\n\n");
        return 0;
    }

    num = fread(x, sizeof(struct ad),100, fp);
    fclose(fp);
}
void write()
{
    FILE *fp = fopen("patient.txt","w");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(x, sizeof(struct ad),num, fp);
    fclose(fp);
}

