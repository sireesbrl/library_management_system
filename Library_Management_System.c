//A program for library management

//List of header files
#include<stdio.h>                 //Contains printf(), scanf(),etc
#include<conio.h>                 //Contains getch(), gotoxy(),etc
#include<string.h>                //Contains strcmp(), strcpy(), strlen(), etc
#include<stdlib.h>
#include<ctype.h>                 //Contains toupper(), tolower(), etc
#include<windows.h>               //Contains sleep(), etc
#include<time.h>

//list of function prototype
void loginScreen();
void headMessage();
void welcomeMessage();
void searchBooks();
void addBooks();
void viewBooks();
void deleteBooks();
void menu();
void getdata();
void data();
void date();
void lines();
void rdate();
char categories[][20]={"Computer","Electronics","Electrical","Civil","Mechanical","Architecture","Geomatics"};
int i=0,s=0,line=0;
char chk;

COORD coord = {0, 0}; // sets coordinates to 0,0

void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y;// X & Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct data
{
	char bookName[20],stdName[20],author[20],category[20];
	int roll,rmonth,rdate,ryear;
};


//list of global files that can be accessed form anywhere in the program
FILE *fp, *fq;

struct data a;


 main()   //main function
{
	headMessage();
    loginScreen();
    getch();
}

void menu()     //Displays user options
{
	system("cls");
	headMessage();
	printf("\n\n\n");
	printf("\t\t\t\t   MAIN MENU");
	printf("\n\n\n1. Add Books");
	printf("\n2. View Books");
	printf("\n3. Delete Books");
	printf("\n4. Exit");
	gotoxy(0,24);
	printf("Enter your choice: "); 
	switch(getch())
	{
    case '1':
		addBooks();
        break;
    case '2':
		viewBooks();
        break;
	case '3':
		deleteBooks();
        break;
    case '4':    	
    	for(i=5;i>=1;i--){
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\t     This program is written by Shirish Baral(PAS076BEI037).\n");
	   	printf("\n\t\t\t\t Thank you!\n\n\n\n\n\n\n\n\n\n\n\nExiting in %d secs...",i);
		sleep(1);
    	}
		exit(0);
		break;
    default:   //If invalid character is entered
    
    	printf("Invalid!");  
    	if(getch())
		{
    		menu();
		}      
	}

}

void loginScreen()     //Initial login screen
{
	char user0[20],pass0[20];
	char su[10]="admin";
	char su_key[10]="admin";
	int x=0;
	gotoxy(26,15);
    printf("Enter username: ");	
	scanf("%s",user0);
	gotoxy(26,17);
   	printf("Enter password: ");
    while(1)
	{
		chk=getch();
		if(chk==13)    //ASCII value for enter key
		{
			pass0[x]='\0';
			break;
	    }
	    else if(chk==8)   //ASCII value for backspace key
	    {
	    	if(x>0)
	    	{
	    		x--;
	    		printf("\b \b");
			}
		}
		else if(chk==9 || chk==32)     //ASCII value for tab & spacebar keys respectively
		{
			continue;
		}
		else
		{
			pass0[x]=chk;
			x++;
			printf("*");          //Replaces the entered password with '*'
		}
    	
	}
	if(strcmp(su, user0) == 0 && strcmp(su_key, pass0) == 0 )
	{  
	    welcomeMessage();
	}
    else
    {
    	system("cls");
    	headMessage();
        gotoxy(24,16);
	    printf("Incorrect username and password\n");
	    sleep(1);
	    while(i < 2){
	    system("cls");
	    headMessage();
	    int a;
	    i++;
	    a = 3 - i ;
	    gotoxy(26,24);
	    printf("You have %d tries left", a);     //Displays the number of tries left
	    printf("\n\n");
	    loginScreen();	
    } 
    for(i=5;i>=1;i--)      //Displays when wrong info is entered three times
	{     
   	    system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n");
        printf("################################################################################");
        printf("#########                                                              #########");
        printf("#########                     Error!!! Can't log in.                   #########");
        printf("#########                                                              #########");
        printf("################################################################################");
        printf("\n\n\n\n\n\n\n\n\nExiting in %d secs...",i);
        sleep(1);
	}
    exit(0);
	}	
}
void headMessage()     //Displays on the top of the program
{
    printf("################################################################################");
    printf("#########                                                              #########");
    printf("#########            Library Management System Project in C            #########");
    printf("#########                                                              #########");
    printf("################################################################################");
  	printf("--------------------------------------------------------------------------------\n");
  	gotoxy(28,6);
    printf("Email: sireesbrl@gmail.com\n");
    printf("--------------------------------------------------------------------------------\n");
    gotoxy(65,8);
    date(); 
}

void welcomeMessage()   //Displays welcome message if the user is logged into the system
{
	system("cls");    	
    printf("\n\n\n\n\n\n\n");
    printf("\n**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
	printf("\n                   =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=     ");
    printf("\n                   =                 WELCOME                   =     ");
    printf("\n                   =                   TO                      =     ");
    printf("\n                   =                 LIBRARY                   =     ");
    printf("\n                   =               MANAGEMENT                  =     ");
    printf("\n                   =                 SYSTEM                    =     ");
    printf("\n                   =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=     ");
    printf("\n**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");	
    printf("\n\n\n\nLoading");
    for(i=1;i<=3;i++)
	{
    	printf(".");
	    sleep(1);	
	} 
    menu();
    
}

void addBooks()      //Adds books into the system
{
	system("cls");
	headMessage();
	printf("\n\n\n");
	rdate();
	gotoxy(32,12);
	printf("SELECT CATEGORIES\n\n\n");
	printf(" 1. Computer\n");
	printf(" 2. Electronics, Communication and Information\n");
	printf(" 3. Electrical\n");
	printf(" 4. Civil\n");
	printf(" 5. Mechanical\n");
	printf(" 6. Architecture\n");
	printf(" 7. Geomatics\n");
	printf(" 8. Back to main menu");
	gotoxy(0,24);
	printf("Enter your choice: ");
	switch(getch())
	{
	    case '1':
    	s=0;
    	getdata();
		break;
	    case '2':
    	s=1;
    	getdata();
		break;
	    case '3':
    	s=2;
		getdata();
		break;
	    case '4':
    	s=3;
        getdata();
		break;
	    case '5':
    	s=4;
        getdata();
		break;
	    case '6':
    	s=5;
        getdata();
		break;
		case '7':
    	s=6;
        getdata();
		break;
	    case '8':
		system("cls");
	    menu();	
	    break;
	    default:
		printf("Invalid input!");
		if(getch())
		{
			addBooks();
		}
        
	}

}

void viewBooks()      //Lists the books saved in the system
{
	data();
	printf("\n\nEnter any key to go back to main menu...");
	getch();
	menu();
}
void deleteBooks()     //Deletes student's data from the system
{
	system("cls");
	headMessage();
	printf("\n\n\n");
    int ln=0,rln;
    char str[100];
    data();
    lines();
	printf("\n\nEnter line no.: ");
	scanf("%d",&rln);
	if(rln>line || rln==0)
	{
		printf("Invalid!");
		if(getch())
		{
			line=0;      //Nos. of lines is set to zero as it keeps on adding if the loop runs more than once
			fclose(fp);
			deleteBooks();	
		}
	}
	else
    {
	    fp=fopen("books.bin","rb");
        fq=fopen("temp.bin","wb");
        for(i=1;i<=line;i++)
    	{
		    strcpy(str,"\0");
		    fgets(str,100,fp);
		    ln++;
		    if(!feof(fp))   
		    {
			    if(ln!=rln)             //Only copies the data to a temporary file if it is other than the data to be deleted
		        {   		
    	        fprintf(fq,"%s",str);   		
		        }					
		    }			
	    }
	    fclose(fp);
		fclose(fq);
	    remove("books.bin");
        rename("temp.bin","books.bin");	
		line=0;                      //Nos. of lines is set to zero again
	    printf("\nData deleted!\nDo you want to delete more data[Y/N]? ");
	    chk=getch(); 
	    if(chk==tolower('y'))
		{   
		    deleteBooks();
	    }
	    else
		{		    	
		    menu();	
	    }
		fclose(fp);
	    fclose(fq);	
	}   

}

void getdata()      //Gets student's data from the user
{	
    system("cls");
    headMessage();
    printf("\n\n\n");
    printf("Faculty: %s Engineering\n",categories[s]);
	printf("Student's Name: ");
    scanf("%s",a.stdName);	
    printf("Roll No.: ");
    scanf("%d",&a.roll);
    printf("Book Name: ");
	scanf("%s",a.bookName);
	printf("Author: ");
	scanf("%s",a.author);
	fp = fopen("books.bin","ab");
	fprintf(fp,"%s\t%s\t%d\t%s\t%s\t%d\t%d\t%d\n",categories[s],a.stdName,a.roll,a.bookName,a.author,a.ryear,a.rmonth,a.rdate); 
	fclose(fp);
	gotoxy(0,23);
	printf("Data saved successfully!\nDo you want to add more[Y/N]? ");
    chk=getch();
    if (tolower(chk)=='y')
	{
        system("cls");
	    headMessage();
	    addBooks();
	}
    else
	{	
        menu();
    }	
}

void date()    //Always shows the current date on the top 
{   
    time_t currentTime;
    time(&currentTime);
    struct tm *myTime = localtime(&currentTime);
	printf("Date: %d/%d/%d\n",myTime->tm_year + 1900, myTime->tm_mon + 1, myTime->tm_mday);
} 

void rdate(){      //Gives the return date for the issued book
	
	time_t currentTime;
    time(&currentTime);
    struct tm *myTime = localtime(&currentTime);
    if(myTime->tm_mon+1==12 || myTime->tm_mon+1==11 || myTime->tm_mon+1==10 )
	{
        a.ryear = (myTime->tm_year+1900)+ 1;
        a.rmonth = 1;
    	
	}
	else{
		a.ryear = (myTime->tm_year+1900);
		a.rmonth = (myTime->tm_mon+1) + 3;
	}
	a.rdate = (myTime->tm_mday);
}


void lines()    //Checking for the total nos. of lines in the file as EOF is running the loop one time more than necessary, thus printing last data twice
{
	int x;
	fp=fopen("books.bin","rb");
    while((chk=fgetc(fp))!=EOF)
	{
        if(chk=='\n')     //Checks nos. of lines in file
	    {
    	 line++;
		}
    	
    }
    fclose(fp);
    if(line==0){
    	remove("books.bin");
	}
}

void data()   //Displays student's data on the screen
{
	int z=1;
	i=14;
	lines();
	system("cls");
	headMessage();
	printf("\n\n");
	fp=fopen("books.bin","rb");
	if(fp == NULL)
    {
    	gotoxy(33,16);
		printf("File not found!");
		gotoxy(0,24);
		printf("Enter any key to go back to main menu...");
		if(getch())
		{
			fclose(fp);
			menu();
			
		}
    }
    else
	{
		printf("      CATEGORY\t    NAME     \t ROLL NO.  BOOK NAME\tAUTHOR       RETURN DATE\n\n");
        for(z=1;z<=line;z++)    //Loop runs for the total nos. of lines in the file
		{
			fscanf(fp,"%s%s%d%s%s%d%d%d",a.category,a.stdName,&a.roll,a.bookName,a.author,&a.ryear,&a.rmonth,&a.rdate);
			gotoxy(1,i);
			printf("%d.",z);
            gotoxy(6,i);
  	        printf("%s",a.category);
	       	gotoxy(20,i);	
       	   	printf("%s",a.stdName);
       	   	gotoxy(33,i);
       	   	printf("%d",a.roll);
   	       	gotoxy(43,i);
   	    	printf("%s",a.bookName);
           	gotoxy(56,i);
       	 	printf("%s",a.author);
       	 	gotoxy(69,i);
       	 	printf("%d/%d/%d",a.ryear,a.rmonth,a.rdate);
         	i++;  		
	    }
	    line=0;                 //Nos. of lines is set to zero again
	    fclose(fp);

    }
		
}

