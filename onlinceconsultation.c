#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void Diagnoseonl();
void VirtualDoc();
void OflAppoint();
void login();
void registration();
void menu(char[20]);
void doclogin();
void patient();
void docview();
struct logreg{
    char fn[30];
    char ln[30];
    char email[60];
    char mn[10];
    char city[40];
    char state[50];
    char pc[6];
    char an[12];
    char username[20];
    char password[20];
};
struct Doc{
    int id;
    char pd[20];
    char name[50];
    char dept[30];
}doc1,doc2,doc3,doc4,doc5;
int main()
{
    int m;
    printf("\n\t***********\tWelcome to Online Medical Consultation Services\t**********\t");
    menu_again:
    printf("\n Select from one of options given below");
    printf("\n 1.I'm a Patient \n 2.I'm a Doctor\n 3.Quit");
    printf("\n Enter Your Selection: ");
    scanf("%d",&m);
    fflush(stdin);
    if(m==1)
    {
        patient();
    }
    else if(m==2)
    {
        doclogin();
    }
    else if(m==3)
    {
        exit;
    }
    else
    {
        printf("\n Invalid Option! Choose Again!!");
        goto menu_again;
    }
    return 0;
}
void patient()
{
    int n;
    redo:
    printf("\n 1. New User Registration.");
    printf("\n 2. Already a user? Login.");
    printf("\n 3. To quit Website.");
    printf("\n Enter Your Selection: ");
    scanf("%d",&n);
    fflush(stdin);
    switch(n)
    {
        while(n>0&&n<4)
        {
        case 1:
            registration();
            break;
        case 2:
            login();
            break;
        case 3:
            break;
        default:
            printf("\n Invalid Option Entered");
            goto redo;
    }
}
}
void login()
{
    char username[20];
    char password[20];
        FILE *log;

    log = fopen("login.txt","r");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
    struct logreg l;
    log_again:
    printf("\n\t\t Enter Your Login Details ");
    printf("\n\t\t\t Enter User name: ");
    gets(username);
    printf("\n\t\t\t Enter Password: ");
    gets(password);
        while(fread(&l,sizeof(l),1,log))
        {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)

            {
                printf("\nSuccessful Login\n");
                menu(username);
            }
        else
            {
                printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
                goto log_again;
            }
        }

    fclose(log);
}
void doclogin()
{
    strcpy(doc1.name,"Sanjiviah");
    doc1.id=34578;
    strcpy(doc1.pd,"sanjiviah123*");
    strcpy(doc1.dept,"General Medicine");
    strcpy(doc2.name,"Kapil");
    doc2.id=24578;
    strcpy(doc2.pd,"kapil123*");
    strcpy(doc2.dept,"Orthopology");
    strcpy(doc3.name,"Balakrishna");
    doc3.id=44578;
    strcpy(doc3.pd,"balakrishna*");
    strcpy(doc3.dept,"Neurology");
    strcpy(doc4.name,"Swathi");
    doc4.id=54578;
    strcpy(doc4.pd,"swathi123*");
    strcpy(doc4.dept,"Gynaceology");
    strcpy(doc5.name,"Manikanta");
    doc5.id=64578;
    strcpy(doc5.pd,"manikanta123*");
    strcpy(doc5.dept,"Phyisician");
    int docid;
    char pd[20];
    struct Doc d;
    doclog_again:
    printf("\n Hello,Doctor, Please enter your details to login.");
    printf("\n Enter your Doctor I'd: ");
    scanf("%d",&docid);
    fflush(stdin);
    printf("\n Enter Your Password: ");
    gets(pd);
    if(docid==doc1.id&&strcmp(pd,doc1.pd)==0)
    {
        printf("2");
    }
    else if(docid=doc2.id&&strcmp(pd,doc2.pd)==0)
    {
        docview();
    }
    else if(docid==doc3.id&&strcmp(pd,doc3.pd)==0)
    {
        docview();
    }
    else if(docid==doc4.id&&strcmp(pd,doc4.pd)==0)
    {
        docview();
    }
    else if(docid==doc5.id&&strcmp(pd,doc5.pd)==0)
    {
        docview();
    }
    else
    {
        printf("\n Invalid Login Details");
        goto doclog_again;
    }
}
void docview()
{
    printf("\n Hello doc, Your Appointments with patients for tomorrow are: \n ");
}
void menu(char un[20])
{
        int ch;
        printf("\n Welcome, %s, how can we assist you today?",un);
        printf("\n\t What is your query? \n\t Please choose your query option from below: ");
        menu2_again:
        printf("\n 1. Online Diagnosis ");
        printf("\n 2. Consult Doctor Virtually ");
        printf("\n 3. Book Offline Appointment ");
        printf("\n 4. Logout");
        printf("\n Enter your selection: ");
        scanf("%d",&ch);
        switch(ch)
            {
                case 1: Diagnoseonl();
                break;
                case 2: VirtualDoc();
                break;
                case 3: OflAppoint();
                break;
                case 4: break;
                default:
                    printf("\n Invalid Input!!Choose Again");
                    goto menu2_again;
            }
}
void Diagnoseonl()
{
    char cl[5];
    char co[5];
    char fv[5];
    char y[]="yes";
    char n[]="no";
    printf("\n Answer the simple Yes/No questions to diagnose your symptoms. ");
    printf("\n Do you have cold? ");
    fflush(stdin);
    gets(cl);
    printf("\n Do you have Cough? ");
    gets(co);
    printf("\n Do you have Fever? ");
    gets(fv);
    if(strcmp(cl,y)==0&&strcmp(co,y)==0&&strcmp(fv,y)==0)
    {
        printf("\n Kindly visit nearest medical store for medicines");
        printf("\n List of medicines: ");
        printf("\n 1.Dolo 650");
        printf("\n 2.Predmet");
        printf("\n 3.L-HIST MONT");
        printf("\n 4.Ascoril Syrup");
    }
    else if(strcmp(cl,n)==0&&strcmp(co,y)==0&&strcmp(fv,y)==0)
    {
        printf("\n Kindly visit nearest medical store for medicines");
        printf("\n List of medications: ");
        printf("\n 1.Dolo 650");
        printf("\n 2.Ascoril Syrup");
    }
    else if(strcmp(cl,n)==0&&strcmp(co,n)==0&&strcmp(fv,y)==0)
    {
        printf("\n Kindly visit nearest medical store for medicines");
        printf("\n List of medications: ");
        printf("\n 1.Dolo 650");
    }
    else if(strcmp(cl,y)==0&&strcmp(co,n)==0&&strcmp(fv,y)==0)
    {
             printf("\n Kindly visit nearest medical store for medicines");
             printf("\n List of medications: ");
             printf("\n 1.Lancet");
             printf("\n 2.IMOX-500");
             printf("\n 3.Dolo 650");
    }
    else if(strcmp(cl,y)==0&&strcmp(co,n)==0&&strcmp(fv,n)==0)
    {
        printf("\n Kindly visit nearest medical store for medicines");
                printf("\n List of medications: ");
                printf("\n 1.IMOX-500");
                printf("\n L-HIST Mont");
    }
    else if(strcmp(cl,n)==0&&strcmp(co,y)==0&&strcmp(fv,n)==0)
    {
        printf("\n Kindly visit nearest medical store for medicines");
        printf("\n List of medications: ");
        printf("\n 1.Lemsip");
        printf("\n 2.Ascoril Cough Syrup");

    }
    else
    {
        printf("\n Unable to diagnose symptoms properly, kindly visit nearest medical store");
    }

}
void VirtualDoc()
{
    int dc,sjt,kt,bt,st,mt;
    printf("\n Choose a doctor from list of doctor's given below");
    printf("\n 1. Dr.Sanjiviah \n MD,General Medicine");
    printf("\n 2. Dr. Kapil \n MD,M.Phil, Orthopologist");
    printf("\n 3. Dr.Balakrishnan MBBS,MD, Neurologist");
    printf("\n 4.Dr.Swathi \n MD, Gynacelogist");
    printf("\n 5. Dr.Manikanta \n MBBS, Physician");
    printf("\n Enter Your Selection: ");
    scanf("%d",&dc);
    switch(dc)
    {
    case 1:
        printf("\n Choose one of the free slots available from below: \n Note: All bookings must be done one day before only so all the times shown are tomorrow's.");
        printf("\n 1.7PM \n 2.8PM \n 3. 9PM \n 4.10PM");
        printf("\n Enter your selection: ");
        scanf("%d",&sjt);
        if(sjt==1||sjt==2||sjt==3||sjt==4)
        {
            printf("\n Appointment Booked Sucessfully. \n Virtual Meeting link is sent to registered mobile number.");
            printf("\n Kindly join the meet 10 minutes before the actual time.");
        }
        else
        {
            printf("\n Invalid Option Selected");
        }
        break;
    case 2:
        printf("\n Choose one of the free slots available from below: \n Note: All bookings must be done one day before only so all the times shown are tomorrow's.");
        printf("\n 1.10AM \n 2.11AM \n 3. 9PM \n 4.4PM");
        printf("\n Enter your selection: ");
        scanf("%d",&kt);
        if(kt==1||kt==2||kt==3||kt==4)
        {
            printf("\n Appointment Booked Sucessfully. \n Virtual Meeting link is sent to registered mobile number.");
            printf("\n Kindly join the meet 10 minutes before the actual time.");
        }
        else
        {
            printf("\n Invalid Option Selected");
        }
        break;
    case 3:
         printf("\n Choose one of the free slots available from below: \n Note: All bookings must be done one day before only so all the times shown are tomorrow's.");
         printf("\n 1.10AM \n 2.9AM \n 3. 2PM \n 4.5PM");
         printf("\n Enter your selection: ");
         scanf("%d",&bt);
         if(bt==1||bt==2||bt==3||bt==4)
         {
            printf("\n Appointment Booked Sucessfully. \n Virtual Meeting link is sent to registered mobile number.");
            printf("\n Kindly join the meet 10 minutes before the actual time");
         }
         else
         {
            printf("\n Invalid Option Selected");
         }
         break;
    case 4:
        printf("\n Choose one of the free slots available from below: \n Note: All bookings must be done one day before only so all the times shown are tomorrow's.");
        printf("\n 1.12PM \n 2.1PM \n 3. 3PM \n 4.8AM");
        printf("\n Enter your selection: ");
        scanf("%d",&st);
        if(st==1||st==2||st==3||st==4)
        {
            printf("\n Appointment Booked Sucessfully. \n Virtual Meeting link is sent to registered mobile number.");
            printf("\n Kindly join the meet 10 minutes before the actual time.");
        }
        else
        {
            printf("\n Invalid Option Selected");
        }
        break;
    case 5:
        printf("\n Choose one of the free slots available from below: \n Note: All bookings must be done one day before only so all the times shown are tomorrow's.");
        printf("\n 1.6AM \n 2.8AM \n 3. 6PM \n 4.9PM");
        printf("\n Enter your selection: ");
        scanf("%d",&mt);
        if(mt==1||mt==2||mt==3||mt==4)
        {
            printf("\n Appointment Booked Sucessfully. \n Virtual Meeting link is sent to registered mobile number.");
            printf("\n Kindly join the meet 10 minutes before the actual time.");
        }
        else
        {
            printf("\n Invalid Option Selected");
        }
        break;
    default:
        printf("Invalid Option Provided");
    }
}
void OflAppoint()
{
    int hp;
    printf("\n All kinds of doctors will be available in the hospitals given below");
    printf("\n Select a hospital from list of options given below");
    printf("\n *********LIST OF HOSPITALS*********");
    printf("\n 1.Ramesh Hospitals, Market Area, Guntur");
    printf("\n 2.Lalitha Hospitals, Kothapet ,Guntur");
    printf("\n 3.Shri Hospitals, Donka Road, Guntur");
    printf("\n 4.Vedantha Hospitals, Mangala Das Nagar, Guntur");
    printf("\n 5.Nightangle Hospitals, Lakshmipuram, Guntur");
    printf("\n Enter Your Selection: ");
    scanf("%d",&hp);
    if(hp==1||hp==2||hp==3||hp==4||hp==5)
    {
        printf("\n Appointment booked for tomorrow, kindly visit the hospital between 9AM-5PM.");
    }
    else
    {
        printf("\n Invalid option");
    }
}
void registration()
{
    FILE *log;
    log=fopen("login.txt","a");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
    struct logreg l;
    printf("\n************** Welcome to User Registration***************");
    printf("\n Enter First name: ");
    gets(l.fn);
    printf("\n Enter Last name: ");
    gets(l.ln);
    printf("\n Enter Your Email: ");
    gets(l.email);
    printf("\n Enter Mobile Number: ");
    gets(l.mn);
    printf("\n Enter Aadhar Card Number: ");
    gets(l.an);
    printf("\n Enter Your City: ");
    gets(l.city);
    printf("\n Enter Your State: ");
    gets(l.state);
    printf("\n Enter Your Pincode: ");
    gets(l.pc);
    printf("\n Now choose a username and password for login Purposes.");
    printf("\n Enter Your Username[Max 20 characters]: ");
    gets(l.username);
    printf("\n Enter Your Password[Max 20 characters]: ");
    gets(l.password);
    fwrite(&l,sizeof(l),1,log);
    fclose(log);
    system("CLS");
    printf("\nConfirming details...\n...\n");
    printf("\n User Succesfully Created!!! Proceed To Login!!!");
    goto jump;
    jump:
        login();
}

