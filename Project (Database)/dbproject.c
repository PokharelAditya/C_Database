#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

int dismsg();
int signup();
int login();
int cedb();

struct student
{
    char fname[99],lname[99],gender[10],address[3][99],email[99],phone[99];
    int roll,dob[3];
};

int main()
{
    int r;
    system("cls");
    FILE *file;
    file = fopen("login.txt","r");
    if(file==NULL)
    {
        if(dismsg()==0)
        {
            return 0;
        }
        if(signup()==0)
        {
            return 0;
        }
    }
    fclose(file);
    repeat1:
    login();
    repeat:
    r=cedb();
    if(r==0)
    {
        goto repeat;
    }
    else if(r==1)
    {
        return 0;
    }
    else if(r==2)
    {
        goto repeat1;
    }
}

int dismsg()
{
    char ans[3];
    printf("Do you want to access the database of KU CE 2023? (Yes/No)\n");
    scanf("%s",ans);
    strupr(ans);
    if(strcmp(ans,"YES")!=0)
    {
        printf("You can close the application now.");
        getch();
        return 0;
    }
    char m[999];
    strcpy(m,"Welcome to the database of Kathmandu University (CE 2023)!    \nThis database created by Aditya Pokharel holds the records of students of Computer Engineering(1st Year 1st Semester) of Kathmandu University.    \nPlease feel free to contact us at adityapokharel63@gmail.com for any problem.\nPRESS ANY KEY TO CONTINUE");
    system("cls");
    for(int i=0;m[i]!='\0';i++)
    {
        printf("%c",m[i]);
        Sleep(25);
    }
    getch();
    char t[999],a[999];
    strcpy(t,"Terms & Conditions:-    \n-->Before you continue using the application, you must be atleast 18 yrs old. We are not responsible for any issues related to age misrepresentation.    \n-->As a user, you are responsible\n  -for any information that you provide\n  -for maintaining the safety and security of your identifying information\n  -for all activities that occur under your account\n\n\nYou must accept all the terms and conditions mentioned above to proceed.\n");
    do
    {
        system("cls");
        for(int i=0;t[i]!='\0';i++)
        {
            printf("%c",t[i]);
            Sleep(10);
        }
        printf("Type AGREE to accept our terms and conditions.\n");
        scanf("%s",a);
        strupr(a);
    }
    while(strcmp(a,"AGREE")!=0);
    system("cls");
    char l[999];
    strcpy(l,"You can login to our application using your registered account. If you do not have any registered account, you can create one on the next page. Please feel free to contact us at adityapokharel63@gmail.com\nPRESS ANY KEY TO CONTINUE");
    for(int i=0;l[i]!='\0';i++)
    {
        printf("%c",l[i]);
        Sleep(15);
    }
    getch();
    return 1;
}

int signup()
{
    char fn[20],ln[20],u[20],p[20],cp[20],msg[100];
    int age;
    system("cls");
    strcpy(msg,"Since you are logging in for the first time, please sign up by filling out the following details :\n");
    for(int i=0;msg[i]!='\0';i++)
    {
        printf("%c",msg[i]);
        Sleep(20);
    }
    printf("First Name : ");
    scanf("%s",fn);
    printf("Last Name : ");
    scanf("%s",ln);
    printf("Create a username : ");
    scanf("%s",u);
    printf("Enter your age : ");
    scanf("%d",&age);
    if(age<18)
    {
        printf("Sorry :(\nYou are not eligible to use the application. You must be at least 18 years old.\n");
        getch();
        return 0;
    }
    again:
    printf("Create a password : ");
    scanf("%s",p);
    printf("Confirm password : ");
    scanf("%s",cp);
    if(strcmp(p,cp)!=0)
    {
        printf("\nThe passwords do not match.\nPlease try again!\n\n");
        goto again;
    }
    FILE *file;
    file = fopen("login.txt","w");
    fprintf(file,"%s\t%s\t%s\t%s\n",fn,ln,u,p);
    fclose(file);
    system("cls");
    printf("The account has been created successfully.\nPRESS ANY KEY TO CONTINUE");
    getch();
    return 1;
}

int login()
{
    char un[20],pw[20],u[20],p[20];
    FILE *file;
    file = fopen("login.txt","r");
    fscanf(file,"%*s\t%*s\t%s\t%s\n",u,p);
    fclose(file);
    system("cls");
    loginagain:
    printf("LOGIN\n");
    printf("Username : ");
    scanf("%s",un);
    printf("Password : ");
    scanf("%s",pw);
    system("cls");
    if(strcmp(un,u)!=0||strcmp(pw,p)!=0)
    {
        printf("Invalid username or password. \nTry again!\n\n\n");
        goto loginagain;
    }
    return 0;
}

int cedb()
{
    system("cls");
    char db[100],fn[20],ln[20];
    FILE *file;
    file = fopen("login.txt","r");
    fscanf(file,"%s\t%s",fn,ln);
    fclose(file);
    strcpy(db,"~ Database of Computer Engineering (1st Yr 1st Sem) ~\n\n");
    printf("Welcome %s %s!\n\n",fn,ln);
    for(int i=0;db[i]!='\0';i++)
    {
        printf("%c",db[i]);
        Sleep(25);
    }
    struct student s[100];
    char ask[999];
    Sleep(50);
    printf("Type SEARCH to search a student\n");
    Sleep(50);
    printf("Type VIEW to view student's information\n");
    Sleep(50);
    printf("Type ADD to add student's personal information\n");
    Sleep(50);
    printf("Type MODIFY to modify student's personal information\n");
    Sleep(50);
    printf("Type DELETE to delete student's information\n");
    Sleep(50);
    printf("Type LOGOUT to logout of the database\n");
    Sleep(50);
    printf("Type EXIT to exit the database\n");
    Sleep(50);
    printf("Type CHANGE to change your account's password\n");
    Sleep(50);
    printf("Type RESET to reset the application\n\n");
    Sleep(50);
    scanf("%s",ask);
    strupr(ask);
    system("cls");
    if(strcmp(ask,"SEARCH")==0)
    {
        int n,i;
        file = fopen("variable.txt","r");
        fscanf(file,"%d",&n);
        fclose(file);
        file = fopen("data.txt","r");
        if(file==NULL)
        {
            printf("No data found!\nPRESS ANY KEY TO CONTINUE");
            getch();
            return 0;
        }
        for(i=0;i<n;i++)
        {
            fscanf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",&s[i].roll,s[i].fname,s[i].lname,&s[i].dob[0],&s[i].dob[1],&s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);
        }
        fclose(file);
        Sleep(50);
        printf("Type ROLL to search student by roll number\n");
        Sleep(50);
        printf("Type FN to search student by first name\n");
        Sleep(50);
        printf("Type LN to search student by last name\n");
        Sleep(50);
        printf("Type DOB to search student by date of birth\n");
        Sleep(50);
        printf("Type GENDER to search student by gender\n");
        Sleep(50);
        printf("Type ADDRESS to search student by address\n");
        Sleep(50);
        printf("Type EMAIL to search student by email\n");
        Sleep(50);
        printf("Type PHONE to search student by phone number\n\n");
        Sleep(50);
        char a[9];
        scanf("%s",a);
        strupr(a);
        system("cls");
        int roll,dob[3],c=0;
        char fname[99],lname[99],gender[10],email[99],phone[99],address[3][99];
        if(strcmp(a,"ROLL")==0)
        {
            printf("Enter roll number : ");
            scanf("%d",&roll);
            for(i=0;i<n;i++)
            {
                if(s[i].roll==roll)
                {
                    printf("\nName : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                    c++;
                }
            }
            if(c==0)
            {
                printf("\nStudent with roll number %d not found.\nPRESS ANY KEY TO CONTINUE",roll);
            }
            else
            {
                printf("\nStudents with roll number %d are mentioned above.\nPRESS ANY KEY TO CONTINUE",roll);
            }
        }
        else if(strcmp(a,"FN")==0)
        {
            printf("Enter first name : ");
            scanf("%s",fname);
            for(i=0;i<n;i++)
            {
                if(strcmp(s[i].fname,fname)==0)
                {
                    printf("\nName : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                    c++;
                }
            }
            if(c==0)
            {
                printf("\nStudent with first name '%s' not found.\nPRESS ANY KEY TO CONTINUE",fname);
            }
            else
            {
                printf("\nStudents with first name '%s' are mentioned above.\nPRESS ANY KEY TO CONTINUE",fname);
            }
        }
        else if(strcmp(a,"LN")==0)
        {
            printf("Enter last name : ");
            scanf("%s",lname);
            for(i=0;i<n;i++)
            {
                if(strcmp(s[i].lname,lname)==0)
                {
                    printf("\nName : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                    c++;
                }
            }
            if(c==0)
            {
                printf("\nStudent with last name '%s' not found.\nPRESS ANY KEY TO CONTINUE",lname);
            }
            else
            {
                printf("\nStudents with last name '%s' are mentioned above.\nPRESS ANY KEY TO CONTINUE",lname);
            }
        }
        else if(strcmp(a,"DOB")==0)
        {
            Sleep(50);
            printf("Type Y to search by year\n");
            Sleep(50);
            printf("Type YM to search by year & month\n");
            Sleep(50);
            printf("Type YMD to search by year, month & day\n\n");
            Sleep(50);
            scanf("%s",a);
            strupr(a);
            system("cls");
            if(strcmp(a,"Y")==0)
            {
                printf("Enter year : ");
                scanf("%d",&dob[0]);
                for(i=0;i<n;i++)
                {
                    if(s[i].dob[0]==dob[0])
                    {
                        printf("\nName : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                        c++;
                    }
                }
                if(c==0)
                {
                    printf("\nStudent with date of birth %d not found.\nPRESS ANY KEY TO CONTINUE",dob[0]);
                }
                else
                {
                    printf("\nStudents with date of birth %d are mentioned above.\nPRESS ANY KEY TO CONTINUE",dob[0]);
                }
            }
            else if(strcmp(a,"YM")==0)
            {
                printf("Enter year : ");
                scanf("%d",&dob[0]);
                printf("Enter month : ");
                scanf("%d",&dob[1]);
                for(i=0;i<n;i++)
                {
                    if(s[i].dob[0]==dob[0]&&s[i].dob[1]==dob[1])
                    {
                        printf("\nName : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                        c++;
                    }
                }
                if(c==0)
                {
                    printf("\nStudent with date of birth %d-%d not found.\nPRESS ANY KEY TO CONTINUE",dob[0],dob[1]);
                }
                else
                {
                    printf("\nStudents with date of birth %d-%d are mentioned above.\nPRESS ANY KEY TO CONTINUE",dob[0],dob[1]);
                }
            }
            else if(strcmp(a,"YMD")==0)
            {
                printf("Enter year : ");
                scanf("%d",&dob[0]);
                printf("Enter month : ");
                scanf("%d",&dob[1]);
                printf("Enter day : ");
                scanf("%d",&dob[2]);
                for(i=0;i<n;i++)
                {
                    if(s[i].dob[0]==dob[0]&&s[i].dob[1]==dob[1]&&s[i].dob[2]==dob[2])
                    {
                        printf("\nName : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                        c++;
                    }
                }
                if(c==0)
                {
                    printf("\nStudent with date of birth %d-%d-%d not found.\nPRESS ANY KEY TO CONTINUE",dob[0],dob[1],dob[2]);
                }
                else
                {
                    printf("\nStudents with date of birth %d-%d-%d are mentioned above.\nPRESS ANY KEY TO CONTINUE",dob[0],dob[1],dob[2]);
                }
            }
            else
            {
                printf("Invalid command!\nPRESS ANY KEY TO CONTINUE");
            }
        }
        else if(strcmp(a,"GENDER")==0)
        {
            printf("Enter gender : ");
            scanf("%s",gender);
            strupr(gender);
            for(i=0;i<n;i++)
            {
                if(strcmp(s[i].gender,gender)==0)
                {
                    printf("\nName : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                    c++;
                }
            }
            if(c==0)
            {
                printf("\nStudent with gender '%s' not found.\nPRESS ANY KEY TO CONTINUE",gender);
            }
            else
            {
                printf("\nStudents with gender '%s' are mentioned above.\nPRESS ANY KEY TO CONTINUE",gender);
            }
        }
        else if(strcmp(a,"ADDRESS")==0)
        {
            Sleep(50);
            printf("Type D to search by district\n");
            Sleep(50);
            printf("Type DM to search by district & municipality\n");
            Sleep(50);
            printf("Type DMW to search by district, municipality & ward no.\n\n");
            Sleep(50);
            scanf("%s",a);
            strupr(a);
            system("cls");
            if(strcmp(a,"D")==0)
            {
                printf("Enter district : ");
                scanf("%s",address[0]);
                for(i=0;i<n;i++)
                {
                    if(strcmp(s[i].address[0],address[0])==0)
                    {
                        printf("\nName : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                        c++;
                    }
                }
                if(c==0)
                {
                    printf("\nStudent with district '%s' not found.\nPRESS ANY KEY TO CONTINUE",address[0]);
                }
                else
                {
                    printf("\nStudents with district '%s' are mentioned above.\nPRESS ANY KEY TO CONTINUE",address[0]);
                }
            }
            else if(strcmp(a,"DM")==0)
            {
                printf("Enter district : ");
                scanf("%s",address[0]);
                printf("Enter municipality : ");
                scanf("%s",address[1]);
                for(i=0;i<n;i++)
                {
                    if(strcmp(s[i].address[0],address[0])==0&&strcmp(s[i].address[1],address[1])==0)
                    {
                        printf("\nName : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                        c++;
                    }
                }
                if(c==0)
                {
                    printf("\nStudent with district '%s' & municipality '%s' not found.\nPRESS ANY KEY TO CONTINUE",address[0],address[1]);
                }
                else
                {
                    printf("\nStudents with district '%s' & municipality '%s' are mentioned above.\nPRESS ANY KEY TO CONTINUE",address[0],address[1]);
                }
            }
            else if(strcmp(a,"DMW")==0)
            {
                printf("Enter district : ");
                scanf("%s",address[0]);
                printf("Enter municipality : ");
                scanf("%s",address[1]);
                printf("Enter ward no. : ");
                scanf("%s",address[2]);
                for(i=0;i<n;i++)
                {
                    if(strcmp(s[i].address[0],address[0])==0&&strcmp(s[i].address[1],address[1])==0&&strcmp(s[i].address[2],address[2])==0)
                    {
                        printf("\nName : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                        c++;
                    }
                }
                if(c==0)
                {
                    printf("\nStudent with district '%s', municipality '%s' & ward no. %s not found.\nPRESS ANY KEY TO CONTINUE",address[0],address[1],address[2]);
                }
                else
                {
                    printf("\nStudents with district '%s', municipality '%s' & ward no. %s are mentioned above.\nPRESS ANY KEY TO CONTINUE",address[0],address[1],address[2]);
                }
            }
            else
            {
                printf("Invalid command!\nPRESS ANY KEY TO CONTINUE");
            }
        }
        else if(strcmp(a,"EMAIL")==0)
        {
            printf("Enter email : ");
            scanf("%s",email);
            for(i=0;i<n;i++)
            {
                if(strcmp(s[i].email,email)==0)
                {
                    printf("\nName : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                    c++;
                }
            }
            if(c==0)
            {
                printf("\nStudent with email '%s' not found.\nPRESS ANY KEY TO CONTINUE",email);
            }
            else
            {
                printf("\nStudents with email '%s' are mentioned above.\nPRESS ANY KEY TO CONTINUE",email);
            }
        }
        else if(strcmp(a,"PHONE")==0)
        {
            printf("Enter phone number : ");
            scanf("%s",phone);
            for(i=0;i<n;i++)
            {
                if(strcmp(s[i].phone,phone)==0)
                {
                    printf("\nName : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                    c++;
                }
            }
            if(c==0)
            {
                printf("\nStudent with phone number '%s' not found.\nPRESS ANY KEY TO CONTINUE",phone);
            }
            else
            {
                printf("\nStudents with phone number '%s' are mentioned above.\nPRESS ANY KEY TO CONTINUE",phone);
            }
        }
        else
        {
            printf("Invalid command!\nPRESS ANY KEY TO CONTINUE");
        }
        getch();
        return 0;
    }
    else if(strcmp(ask,"VIEW")==0)
    {
        int n,i,j,ex;
        char exc[100];
        file = fopen("variable.txt","r");
        fscanf(file,"%d",&n);
        fclose(file);
        file = fopen("data.txt","r");
        if(file==NULL)
        {
            printf("No data found!\nPRESS ANY KEY TO CONTINUE");
            getch();
            return 0;
        }
        for(i=0;i<n;i++)
        {
            fscanf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",&s[i].roll,s[i].fname,s[i].lname,&s[i].dob[0],&s[i].dob[1],&s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);
        }
        fclose(file);
        Sleep(50);
        printf("Type RANDOM to view the data randomly\n");
        Sleep(50);
        printf("Type FNAME to sort the data by first name\n");
        Sleep(50);
        printf("Type LNAME to sort the data by last name\n");
        Sleep(50);
        printf("Type ROLL to sort the data by roll number\n");
        Sleep(50);
        char a[9];
        scanf("%s",a);
        strupr(a);
        system("cls");
        if(strcmp(a,"RANDOM")==0)
        {
        }
        else if(strcmp(a,"FNAME")==0)
        {
            printf("Type A for ascending\n");
            printf("Type D for descending\n");
            char ad[9];
            scanf("%s",&ad);
            strupr(ad);
            system("cls");
            if(strcmp(ad,"A")==0)
            {
                for(i=0;i<n-1;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(strcmp(s[i].fname,s[j].fname)>0)
                        {
                            ex=s[i].roll;
                            s[i].roll=s[j].roll;
                            s[j].roll=ex;
                            strcpy(exc,s[i].fname);
                            strcpy(s[i].fname,s[j].fname);
                            strcpy(s[j].fname,exc);
                            strcpy(exc,s[i].lname);
                            strcpy(s[i].lname,s[j].lname);
                            strcpy(s[j].lname,exc);
                            ex=s[i].dob[0];
                            s[i].dob[0]=s[j].dob[0];
                            s[j].dob[0]=ex;
                            ex=s[i].dob[1];
                            s[i].dob[1]=s[j].dob[1];
                            s[j].dob[1]=ex;
                            ex=s[i].dob[2];
                            s[i].dob[2]=s[j].dob[2];
                            s[j].dob[2]=ex;
                            strcpy(exc,s[i].gender);
                            strcpy(s[i].gender,s[j].gender);
                            strcpy(s[j].gender,exc);
                            strcpy(exc,s[i].address[0]);
                            strcpy(s[i].address[0],s[j].address[0]);
                            strcpy(s[j].address[0],exc);
                            strcpy(exc,s[i].address[1]);
                            strcpy(s[i].address[1],s[j].address[1]);
                            strcpy(s[j].address[1],exc);
                            strcpy(exc,s[i].address[2]);
                            strcpy(s[i].address[2],s[j].address[2]);
                            strcpy(s[j].address[2],exc);
                            strcpy(exc,s[i].email);
                            strcpy(s[i].email,s[j].email);
                            strcpy(s[j].email,exc);
                            strcpy(exc,s[i].phone);
                            strcpy(s[i].phone,s[j].phone);
                            strcpy(s[j].phone,exc);
                        }
                    }
                }
            }
            else if(strcmp(ad,"D")==0)
            {
                for(i=0;i<n-1;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(strcmp(s[i].fname,s[j].fname)<0)
                        {
                            ex=s[i].roll;
                            s[i].roll=s[j].roll;
                            s[j].roll=ex;
                            strcpy(exc,s[i].fname);
                            strcpy(s[i].fname,s[j].fname);
                            strcpy(s[j].fname,exc);
                            strcpy(exc,s[i].lname);
                            strcpy(s[i].lname,s[j].lname);
                            strcpy(s[j].lname,exc);
                            ex=s[i].dob[0];
                            s[i].dob[0]=s[j].dob[0];
                            s[j].dob[0]=ex;
                            ex=s[i].dob[1];
                            s[i].dob[1]=s[j].dob[1];
                            s[j].dob[1]=ex;
                            ex=s[i].dob[2];
                            s[i].dob[2]=s[j].dob[2];
                            s[j].dob[2]=ex;
                            strcpy(exc,s[i].gender);
                            strcpy(s[i].gender,s[j].gender);
                            strcpy(s[j].gender,exc);
                            strcpy(exc,s[i].address[0]);
                            strcpy(s[i].address[0],s[j].address[0]);
                            strcpy(s[j].address[0],exc);
                            strcpy(exc,s[i].address[1]);
                            strcpy(s[i].address[1],s[j].address[1]);
                            strcpy(s[j].address[1],exc);
                            strcpy(exc,s[i].address[2]);
                            strcpy(s[i].address[2],s[j].address[2]);
                            strcpy(s[j].address[2],exc);
                            strcpy(exc,s[i].email);
                            strcpy(s[i].email,s[j].email);
                            strcpy(s[j].email,exc);
                            strcpy(exc,s[i].phone);
                            strcpy(s[i].phone,s[j].phone);
                            strcpy(s[j].phone,exc);
                        }
                    }
                }
            }
            else
            {
                printf("Invalid command!\nPRESS ANY KEY TO CONTINUE");
                getch();
                return 0;
            }
        }
        else if(strcmp(a,"LNAME")==0)
        {
            printf("Type A for ascending\n");
            printf("Type D for descending\n");
            char ad[9];
            scanf("%s",&ad);
            strupr(ad);
            system("cls");
            if(strcmp(ad,"A")==0)
            {
                for(i=0;i<n-1;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(strcmp(s[i].lname,s[j].lname)>0)
                        {
                            ex=s[i].roll;
                            s[i].roll=s[j].roll;
                            s[j].roll=ex;
                            strcpy(exc,s[i].fname);
                            strcpy(s[i].fname,s[j].fname);
                            strcpy(s[j].fname,exc);
                            strcpy(exc,s[i].lname);
                            strcpy(s[i].lname,s[j].lname);
                            strcpy(s[j].lname,exc);
                            ex=s[i].dob[0];
                            s[i].dob[0]=s[j].dob[0];
                            s[j].dob[0]=ex;
                            ex=s[i].dob[1];
                            s[i].dob[1]=s[j].dob[1];
                            s[j].dob[1]=ex;
                            ex=s[i].dob[2];
                            s[i].dob[2]=s[j].dob[2];
                            s[j].dob[2]=ex;
                            strcpy(exc,s[i].gender);
                            strcpy(s[i].gender,s[j].gender);
                            strcpy(s[j].gender,exc);
                            strcpy(exc,s[i].address[0]);
                            strcpy(s[i].address[0],s[j].address[0]);
                            strcpy(s[j].address[0],exc);
                            strcpy(exc,s[i].address[1]);
                            strcpy(s[i].address[1],s[j].address[1]);
                            strcpy(s[j].address[1],exc);
                            strcpy(exc,s[i].address[2]);
                            strcpy(s[i].address[2],s[j].address[2]);
                            strcpy(s[j].address[2],exc);
                            strcpy(exc,s[i].email);
                            strcpy(s[i].email,s[j].email);
                            strcpy(s[j].email,exc);
                            strcpy(exc,s[i].phone);
                            strcpy(s[i].phone,s[j].phone);
                            strcpy(s[j].phone,exc);
                        }
                    }
                }
            }
            else if(strcmp(ad,"D")==0)
            {
                for(i=0;i<n-1;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(strcmp(s[i].lname,s[j].lname)<0)
                        {
                            ex=s[i].roll;
                            s[i].roll=s[j].roll;
                            s[j].roll=ex;
                            strcpy(exc,s[i].fname);
                            strcpy(s[i].fname,s[j].fname);
                            strcpy(s[j].fname,exc);
                            strcpy(exc,s[i].lname);
                            strcpy(s[i].lname,s[j].lname);
                            strcpy(s[j].lname,exc);
                            ex=s[i].dob[0];
                            s[i].dob[0]=s[j].dob[0];
                            s[j].dob[0]=ex;
                            ex=s[i].dob[1];
                            s[i].dob[1]=s[j].dob[1];
                            s[j].dob[1]=ex;
                            ex=s[i].dob[2];
                            s[i].dob[2]=s[j].dob[2];
                            s[j].dob[2]=ex;
                            strcpy(exc,s[i].gender);
                            strcpy(s[i].gender,s[j].gender);
                            strcpy(s[j].gender,exc);
                            strcpy(exc,s[i].address[0]);
                            strcpy(s[i].address[0],s[j].address[0]);
                            strcpy(s[j].address[0],exc);
                            strcpy(exc,s[i].address[1]);
                            strcpy(s[i].address[1],s[j].address[1]);
                            strcpy(s[j].address[1],exc);
                            strcpy(exc,s[i].address[2]);
                            strcpy(s[i].address[2],s[j].address[2]);
                            strcpy(s[j].address[2],exc);
                            strcpy(exc,s[i].email);
                            strcpy(s[i].email,s[j].email);
                            strcpy(s[j].email,exc);
                            strcpy(exc,s[i].phone);
                            strcpy(s[i].phone,s[j].phone);
                            strcpy(s[j].phone,exc);
                        }
                    }
                }
            }
            else
            {
                printf("Invalid command!\nPRESS ANY KEY TO CONTINUE");
                getch();
                return 0;
            }
        }
        else if(strcmp(a,"ROLL")==0)
        {
            printf("Type A for ascending\n");
            printf("Type D for descending\n");
            char ad[9];
            scanf("%s",&ad);
            strupr(ad);
            system("cls");
            if(strcmp(ad,"A")==0)
            {
                for(i=0;i<n-1;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(s[i].roll>s[j].roll)
                        {
                            ex=s[i].roll;
                            s[i].roll=s[j].roll;
                            s[j].roll=ex;
                            strcpy(exc,s[i].fname);
                            strcpy(s[i].fname,s[j].fname);
                            strcpy(s[j].fname,exc);
                            strcpy(exc,s[i].lname);
                            strcpy(s[i].lname,s[j].lname);
                            strcpy(s[j].lname,exc);
                            ex=s[i].dob[0];
                            s[i].dob[0]=s[j].dob[0];
                            s[j].dob[0]=ex;
                            ex=s[i].dob[1];
                            s[i].dob[1]=s[j].dob[1];
                            s[j].dob[1]=ex;
                            ex=s[i].dob[2];
                            s[i].dob[2]=s[j].dob[2];
                            s[j].dob[2]=ex;
                            strcpy(exc,s[i].gender);
                            strcpy(s[i].gender,s[j].gender);
                            strcpy(s[j].gender,exc);
                            strcpy(exc,s[i].address[0]);
                            strcpy(s[i].address[0],s[j].address[0]);
                            strcpy(s[j].address[0],exc);
                            strcpy(exc,s[i].address[1]);
                            strcpy(s[i].address[1],s[j].address[1]);
                            strcpy(s[j].address[1],exc);
                            strcpy(exc,s[i].address[2]);
                            strcpy(s[i].address[2],s[j].address[2]);
                            strcpy(s[j].address[2],exc);
                            strcpy(exc,s[i].email);
                            strcpy(s[i].email,s[j].email);
                            strcpy(s[j].email,exc);
                            strcpy(exc,s[i].phone);
                            strcpy(s[i].phone,s[j].phone);
                            strcpy(s[j].phone,exc);
                        }
                    }
                }
            }
            else if(strcmp(ad,"D")==0)
            {
                for(i=0;i<n-1;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(s[i].roll<s[j].roll)
                        {
                            ex=s[i].roll;
                            s[i].roll=s[j].roll;
                            s[j].roll=ex;
                            strcpy(exc,s[i].fname);
                            strcpy(s[i].fname,s[j].fname);
                            strcpy(s[j].fname,exc);
                            strcpy(exc,s[i].lname);
                            strcpy(s[i].lname,s[j].lname);
                            strcpy(s[j].lname,exc);
                            ex=s[i].dob[0];
                            s[i].dob[0]=s[j].dob[0];
                            s[j].dob[0]=ex;
                            ex=s[i].dob[1];
                            s[i].dob[1]=s[j].dob[1];
                            s[j].dob[1]=ex;
                            ex=s[i].dob[2];
                            s[i].dob[2]=s[j].dob[2];
                            s[j].dob[2]=ex;
                            strcpy(exc,s[i].gender);
                            strcpy(s[i].gender,s[j].gender);
                            strcpy(s[j].gender,exc);
                            strcpy(exc,s[i].address[0]);
                            strcpy(s[i].address[0],s[j].address[0]);
                            strcpy(s[j].address[0],exc);
                            strcpy(exc,s[i].address[1]);
                            strcpy(s[i].address[1],s[j].address[1]);
                            strcpy(s[j].address[1],exc);
                            strcpy(exc,s[i].address[2]);
                            strcpy(s[i].address[2],s[j].address[2]);
                            strcpy(s[j].address[2],exc);
                            strcpy(exc,s[i].email);
                            strcpy(s[i].email,s[j].email);
                            strcpy(s[j].email,exc);
                            strcpy(exc,s[i].phone);
                            strcpy(s[i].phone,s[j].phone);
                            strcpy(s[j].phone,exc);
                        }
                    }
                }
            }
            else
            {
                printf("Invalid command!\nPRESS ANY KEY TO CONTINUE");
                getch();
                return 0;
            }
        }
        else
        {
            printf("Invalid command!\nPRESS ANY KEY TO CONTINUE");
            getch();
            return 0;
        }
        printf("Roll No.\tFirst Name\tLast Name\tDate of Birth\tGender\tPhone No.\tEmail\t\t\t\tAddress\n\n");
        for(i=0;i<n;i++)
        {
            printf("%-8d\t%-10s\t%-10s\t%04d-%02d-%02d\t%-6s\t%-10s\t%-30s\t%02s-%s,%s\n",s[i].roll,s[i].fname,s[i].lname,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].phone,s[i].email,s[i].address[2],s[i].address[1],s[i].address[0]);
            Sleep(50);
        }
        printf("\nNumber of Students = %d",n);
        printf("\n\n\nPRESS ANY KEY TO CONTINUE");
        getch();
        return 0;
    }
    else if(strcmp(ask,"ADD")==0)
    {
        int n;
        file = fopen("variable.txt","r");
        if(file == NULL)
        {
            n=0;
        }
        else
        {
            fscanf(file,"%d",&n);
        }
        fclose(file);
        file = fopen("data.txt","a");
        char a[9];
        do
        {
            printf("Enter Student's First Name : ");
            scanf("%s",s[n].fname);
            printf("Enter Student's Last Name : ");
            scanf("%s",s[n].lname);
            printf("Enter Student's Roll no. : ");
            scanf("%d",&s[n].roll);
            printf("Enter student's Date Of Birth (AD):-\n");
            printf("Year : ");
            scanf("%d",&s[n].dob[0]);
            printf("Month : ");
            scanf("%d",&s[n].dob[1]);
            printf("Day : ");
            scanf("%d",&s[n].dob[2]);
            printf("Enter student's Gender (Male/Female): ");
            scanf("%s",s[n].gender);
            strupr(s[n].gender);
            printf("Enter student's Address :-\n");
            printf("District : ");
            scanf("%s",s[n].address[0]);
            printf("Municipality : ");
            scanf("%s",s[n].address[1]);
            printf("Ward No. : ");
            scanf("%s",s[n].address[2]);
            printf("Enter student's Email : ");
            scanf("%s",s[n].email);
            printf("Enter student's Phone No. : ");
            scanf("%s",s[n].phone);
            fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[n].roll,s[n].fname,s[n].lname,s[n].dob[0],s[n].dob[1],s[n].dob[2],s[n].gender,s[n].address[0],s[n].address[1],s[n].address[2],s[n].email,s[n].phone);
            printf("\n\nDo you want to add another student's information? (Yes/No)\n");
            scanf("%s",a);
            strupr(a);
            printf("\n\n");
            n++;
        }
        while(strcmp(a,"YES")==0);
        fclose(file);
        file = fopen("variable.txt","w");
        fprintf(file,"%d",n);
        fclose(file);
        printf("All the provided information are added successfully.\nPRESS ANY KEY TO CONTINUE");
        getch();
        return 0;
    }
    else if(strcmp(ask,"MODIFY")==0)
    {
        int n,i,r,c=0,d=0;
        file = fopen("variable.txt","r");
        fscanf(file,"%d",&n);
        fclose(file);
        file = fopen("data.txt","r");
        if(file==NULL)
        {
            printf("No data found!\nPRESS ANY KEY TO CONTINUE");
            getch();
            return 0;
        }
        for(i=0;i<n;i++)
        {
            fscanf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",&s[i].roll,s[i].fname,s[i].lname,&s[i].dob[0],&s[i].dob[1],&s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);
        }
        fclose(file);
        printf("Enter the student's roll no. : ");
        scanf("%d",&r);
        system("cls");
        char a[9];
        file = fopen("temp.txt","w");
        for(i=0;i<n;i++)
        {
            if(r==s[i].roll)
            {
                retry:
                system("cls");
                printf("Name : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                Sleep(50);
                printf("Type ROLL to modify roll number\n");
                Sleep(50);
                printf("Type FN to modify first name\n");
                Sleep(50);
                printf("Type LN to modify last name\n");
                Sleep(50);
                printf("Type DOB to modify date of birth\n");
                Sleep(50);
                printf("Type GENDER to modify gender\n");
                Sleep(50);
                printf("Type ADDRESS to modify address\n");
                Sleep(50);
                printf("Type EMAIL to modify email\n");
                Sleep(50);
                printf("Type PHONE to modify phone number\n");
                Sleep(50);
                printf("Type CANCEL to cancel modification\n\n");
                Sleep(50);
                scanf("%s",a);
                strupr(a);
                if(strcmp(a,"ROLL")==0)
                {
                    int newroll;
                    printf("\nEnter new roll number : ");
                    scanf("%d",&newroll);
                    fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",newroll,s[i].fname,s[i].lname,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);
                }
                else if(strcmp(a,"FN")==0)
                {
                    char newfn[99];
                    printf("\nEnter new first name : ");
                    scanf("%s",newfn);
                    fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].roll,newfn,s[i].lname,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);
                }
                else if(strcmp(a,"LN")==0)
                {
                    char newln[99];
                    printf("\nEnter new last name : ");
                    scanf("%s",newln);
                    fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].roll,s[i].fname,newln,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);
                }
                else if(strcmp(a,"DOB")==0)
                {
                    int newdob[3];
                    printf("\nEnter new date of birth :-\n");
                    printf("Year : ");
                    scanf("%d",&newdob[0]);
                    printf("Month : ");
                    scanf("%d",&newdob[1]);
                    printf("Day : ");
                    scanf("%d",&newdob[2]);
                    fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].roll,s[i].fname,s[i].lname,newdob[0],newdob[1],newdob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);
                }
                else if(strcmp(a,"GENDER")==0)
                {
                    char newg[99];
                    printf("\nEnter new gender : ");
                    scanf("%s",newg);
                    strupr(newg);
                    fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].roll,s[i].fname,s[i].lname,s[i].dob[0],s[i].dob[1],s[i].dob[2],newg,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);
                }
                else if(strcmp(a,"ADDRESS")==0)
                {
                    char newadd[3][99];
                    printf("\nEnter new address :-\n");
                    printf("District : ");
                    scanf("%s",newadd[0]);
                    printf("Municipality : ");
                    scanf("%s",newadd[1]);
                    printf("Ward : ");
                    scanf("%s",newadd[2]);
                    fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].roll,s[i].fname,s[i].lname,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,newadd[0],newadd[1],newadd[2],s[i].email,s[i].phone);
                }
                else if(strcmp(a,"EMAIL")==0)
                {
                    char newemail[99];
                    printf("\nEnter new email : ");
                    scanf("%s",newemail);
                    fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].roll,s[i].fname,s[i].lname,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],newemail,s[i].phone);
                }
                else if(strcmp(a,"PHONE")==0)
                {
                    char newphone[99];
                    printf("\nEnter new phone number : ");
                    scanf("%s",newphone);
                    fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].roll,s[i].fname,s[i].lname,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,newphone);
                }
                else if(strcmp(a,"CANCEL")==0)
                {
                    fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].roll,s[i].fname,s[i].lname,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);
                    d++;
                }
                else
                {
                    printf("Invalid Command!\nPRESS ANY KEY TO CONTINUE");
                    getch();
                    goto retry;
                }
            }
            else
            {
                fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].roll,s[i].fname,s[i].lname,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);
                c++;
            }
        }
        fclose(file);
        remove("data.txt");
        rename("temp.txt","data.txt");
        if(c==n)
        {
            printf("Roll Number %d not found.\nPRESS ANY KEY TO CONTINUE",r);
        }
        else if((c+d)==n)
        {
            system("cls");
            printf("Data not modified.\nPRESS ANY KEY TO CONTINUE");
        }
        else
        {
            system("cls");
            printf("Data modififed successfully.\nPRESS ANY KEY TO CONTINUE");    
        }
        getch();
        return 0;
    }
    else if(strcmp(ask,"DELETE")==0)
    {
        int n,i;
        file = fopen("variable.txt","r");
        fscanf(file,"%d",&n);
        fclose(file);
        file = fopen("data.txt","r");
        if(file==NULL)
        {
            printf("No data found!\nPRESS ANY KEY TO CONTINUE");
            getch();
            return 0;
        }
        for(i=0;i<n;i++)
        {
            fscanf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",&s[i].roll,s[i].fname,s[i].lname,&s[i].dob[0],&s[i].dob[1],&s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);
        }
        fclose(file);
        Sleep(50);
        printf("Type ROLL to delete data by roll number\n");
        Sleep(50);
        printf("Type FN to delete data by first name\n");
        Sleep(50);
        printf("Type LN to delete data by last name\n\n");
        Sleep(50);
        char a[9];
        scanf("%s",a);
        strupr(a);
        if(strcmp(a,"ROLL")==0)
        {
            system("cls");
            int r,m;
            m=n;
            printf("Enter roll number : ");
            scanf("%d",&r);
            system("cls");
            char q[9];
            file = fopen("temp.txt","w");
            for(i=0;i<n;i++)
            {
                if (s[i].roll==r)
                {
                    invalid1:
                    printf("Name : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                    printf("Are you sure to remove this student's information? (Yes/No)\n");
                    scanf("%s",q);
                    strupr(q);
                    if(strcmp(q,"YES")==0)
                    {
                        m--;
                        printf("\nThis student's information has been removed.\nPRESS ANY KEY TO CONTINUE");
                        getch();
                        system("cls");
                    }
                    else if(strcmp(q,"NO")==0)
                    {
                        fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].roll,s[i].fname,s[i].lname,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);
                        printf("\nThis student's information has not been removed.\nPRESS ANY KEY TO CONTINUE");
                        getch();
                        system("cls");
                    }
                    else
                    {
                        printf("Invalid command!\nPRESS ANY KEY TO CONTINUE");
                        getch();
                        system("cls");
                        goto invalid1;
                    }
                }
                else
                {
                    fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].roll,s[i].fname,s[i].lname,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);      
                }
            }
            fclose(file);
            remove("data.txt");
            rename("temp.txt","data.txt");
            if(m==n)
            {
                printf("No data has been deleted.\nPRESS ANY KEY TO CONTINUE");
                getch();
            }
            else
            {
                file = fopen("variable.txt","w");
                fprintf(file,"%d",m);
                fclose(file);
            }
            return 0;
        }
        else if(strcmp(a,"FN")==0)
        {
            system("cls");
            char f[20];
            int m;
            m=n;
            printf("Enter first name : ");
            scanf("%s",f);
            system("cls");
            char q[9];
            file = fopen("temp.txt","w");
            for(i=0;i<n;i++)
            {
                if (strcmp(s[i].fname,f)==0)
                {
                    invalid2:
                    printf("Name : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                    printf("Are you sure to remove this student's information? (Yes/No)\n");
                    scanf("%s",q);
                    strupr(q);
                    if(strcmp(q,"YES")==0)
                    {
                        m--;
                        printf("\nThis student's information has been removed.\nPRESS ANY KEY TO CONTINUE");
                        getch();
                        system("cls");
                    }
                    else if(strcmp(q,"NO")==0)
                    {
                        fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].roll,s[i].fname,s[i].lname,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);
                        printf("\nThis student's information has not been removed.\nPRESS ANY KEY TO CONTINUE");
                        getch();
                        system("cls");
                    }
                    else
                    {
                        printf("Invalid command!\nPRESS ANY KEY TO CONTINUE");
                        getch();
                        system("cls");
                        goto invalid2;
                    }
                }
                else
                {
                    fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].roll,s[i].fname,s[i].lname,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);      
                }
            }
            fclose(file);
            remove("data.txt");
            rename("temp.txt","data.txt");
            if(m==n)
            {
                printf("No data has been deleted.\nPRESS ANY KEY TO CONTINUE");
                getch();
            }
            else
            {
                file = fopen("variable.txt","w");
                fprintf(file,"%d",m);
                fclose(file);
            }
            return 0;
        }
        else if(strcmp(a,"LN")==0)
        {
            system("cls");
            char l[20];
            int m;
            m=n;
            printf("Enter last name : ");
            scanf("%s",l);
            system("cls");
            char q[9];
            file = fopen("temp.txt","w");
            for(i=0;i<n;i++)
            {
                if (strcmp(s[i].lname,l)==0)
                {
                    invalid3:
                    printf("Name : %s %s\nRoll number : %d\nDate of Birth : %d-%d-%d\nGender : %s\nAddress : %s-%s, %s\nEmail : %s\nPhone Number : %s\n",s[i].fname,s[i].lname,s[i].roll,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[2],s[i].address[1],s[i].address[0],s[i].email,s[i].phone);
                    printf("Are you sure to remove this student's information? (Yes/No)\n");
                    scanf("%s",q);
                    strupr(q);
                    if(strcmp(q,"YES")==0)
                    {
                        m--;
                        printf("\nThis student's information has been removed.\nPRESS ANY KEY TO CONTINUE");
                        getch();
                        system("cls");
                    }
                    else if(strcmp(q,"NO")==0)
                    {
                        fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].roll,s[i].fname,s[i].lname,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);
                        printf("\nThis student's information has not been removed.\nPRESS ANY KEY TO CONTINUE");
                        getch();
                        system("cls");
                    }
                    else
                    {
                        printf("Invalid command!\nPRESS ANY KEY TO CONTINUE");
                        getch();
                        system("cls");
                        goto invalid3;
                    }
                }
                else
                {
                    fprintf(file,"%d\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",s[i].roll,s[i].fname,s[i].lname,s[i].dob[0],s[i].dob[1],s[i].dob[2],s[i].gender,s[i].address[0],s[i].address[1],s[i].address[2],s[i].email,s[i].phone);      
                }
            }
            fclose(file);
            remove("data.txt");
            rename("temp.txt","data.txt");
            if(m==n)
            {
                printf("No data has been deleted.\nPRESS ANY KEY TO CONTINUE");
                getch();
            }
            else
            {
                file = fopen("variable.txt","w");
                fprintf(file,"%d",m);
                fclose(file);
            }
            return 0;
        }
        else
        {
            printf("Invalid command!\nPRESS ANY KEY TO CONTINUE");
            getch();
            return 0;
        }
    }
    else if(strcmp(ask,"LOGOUT")==0)
    {
        printf("Logged out successfully!\nPRESS ANY KEY TO CONTINUE");
        getch();
        return 2;
    }
    else if(strcmp(ask,"EXIT")==0)
    {
        return 1;
    }
    else if(strcmp(ask,"CHANGE")==0)
    {
        char fn[20],ln[20],un[20],op[20],p[20],np[20],cnp[20];
        file = fopen("login.txt","r");
        fscanf(file,"%s\t%s\t%s\t%s\n",fn,ln,un,op);
        fclose(file);
        again:
        system("cls");
        printf("Current Password : ");
        scanf("%s",p);
        printf("New Password : ");
        scanf("%s",np);
        printf("Confirm New Password : ");
        scanf("%s",cnp);
        if(strcmp(op,p)!=0)
        {
            printf("\nCurrent Password is incorrect.\nPress any key to try again!");
            getch();
            goto again;
        }
        else if(strcmp(np,cnp)!=0)
        {
            printf("\nThe passwords do not match.\nPress any key to try again!");
            getch();
            goto again;
        }
        else
        {
            file = fopen("login.txt","w");
            fprintf(file,"%s\t%s\t%s\t%s\n",fn,ln,un,np);
            fclose(file);
            printf("\nThe password has been changed successfully.\nPRESS ANY KEY TO CONTINUE");
        }
        getch();
        return 2;
    }
    else if(strcmp(ask,"RESET")==0)
    {
        char a[9],msg[99];
        strcpy(msg,"WARNING\nResetting the application will remove all the data.\nDo you want to continue? (Yes/No)\n");
        for(int i=0;msg[i]!='\0';i++)
        {
            printf("%c",msg[i]);
            Sleep(20);
        }
        scanf("%s",a);
        strupr(a);
        if(strcmp(a,"YES")==0)
        {
            char p[20],pw[20];
            file = fopen("login.txt","r");
            fscanf(file,"%*s\t%*s\t%*s\t%s\n",p);
            fclose(file);
            system("cls");
            tryagain:
            printf("Enter your account's password : ");
            scanf("%s",pw);
            system("cls");
            if(strcmp(p,pw)==0)
            {
                remove("login.txt");
                remove("variable.txt");
                remove("data.txt");
                printf("Reset Successful!\nPLEASE RESTART THE APP TO CONTINUE");
                getch();
                return 1;
            }
            else
            {   
                printf("Incorrect Password.\nPlease try again!\n\n");
                goto tryagain;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("Sorry! The command you typed is not currently applicable in this program.\nPRESS ANY KEY TO CONTINUE");
        getch();
        return 0;
    }      
}