/*Programming Fundamental Project
AUTHORS :1. UMER FAROOQ 23P-0039
         2. Malik Ibrar 23P-3006
  */
#include<stdio.h>
#include<stdlib.h>
void ticket_inquiry();                   
void bill_receipt();                       
void audience();                          
void currrent_arrangment ();               
void attendance_checker();                
void add_movie();
void addOns();                                           
void staff();                             
void starting();                          
void reserve();                        
                                                      
//Global variables
int total_seats=0;
int total_food=0;
int i ,j;
int arr[10][10]={0};
int book_seat=0;

void ticket_inquiry()
{
	int choice;
	FILE *fptr;  // declaring file pointer
  fptr=fopen("Movies.txt","r"); //opening file for reading
if (fptr!=NULL)  //for checking that does this file exit or not
{
  char c;
  while ((c = fgetc(fptr)) != EOF)// to fetch all characters in file one by one until end of file is reached
  { 
    printf("%c",c);
  }
  fclose(fptr);//close the file
}else //this else executes when we get a null value while we try to access the file which isnt made already
{
  printf("Error opening file.\n");
  fclose(fptr);//closing the file
}
do {
printf("Enter 1 to go back and 2 to exit  \n");
scanf("%d",&choice);
if (choice==1){
	audience();
}
else if (choice==2){
	exit(0);
}
else {
	printf("Enter a Valid input\n");
}	

}while(choice!=1||choice!=2);
}


void bill_receipt(){
     system("cls");// to clear compiler screen while compailing
	char c;
	int total_bill= 400*book_seat + total_food;  //400 is ticket price
	printf("\n--- WE ARE GLAD THAT YOU VISITED US ---\n");
	printf("\n---You reserved %d Seats for the show ---\n ",book_seat);//total number of seats reserved
	printf("\n--- Your total bill of food is %d ---",total_food);//bill of foods that user ordered
	printf("\n---Your total bill of resrved seats is : %d",book_seat*400);//bill of reserved seats
    printf("\n--- Your net total bill is : %d ---- ",total_bill);//total bill of user
    do {
	printf("\n\n\n Enter y to go back and n to Exit");
    scanf(" %c",&c);
    if (c=='y'|| c=='Y'){
    	audience();//for going back
	}
	else if (c=='n'|| c=='N'){
		exit(0);//to exit program
	}
}while (c!='y'|| c!='Y'|| c!='n'|| c!='N');

}

void audience(){
	
    int choice;
    printf("press 1: for watching current arrangment of seats \n");
    printf("Press 2: for Reserving your show \n");
    printf("Press 3: for buying snacks \n");
    printf("Press 4: for generating Bill receipt  \n");
    printf("Press 5: for ticket Inquiry  \n");
    printf("Press 6: for going back  \n");
	scanf(" %d",&choice);
        if (choice == 1)
		{
            currrent_arrangment(); //calling arrangment function
        }
        else if (choice == 2)
		{
        reserve();    //calling reserve function
        }
        else if(choice == 3)
		{
          addOns();   //calling addOn Function
        }
        else if (choice==4)
		{
         bill_receipt();   //Calling recipt function
            
        }
        else if (choice ==5)
		{
        	ticket_inquiry(); //calling ticket inquiry function
		}
		else if (choice==6)
		{
			starting();   // callings starting function
		}
        else {
        	
        	printf("Invalid comand\n");
        	audience();//recursion
		}
    }
    
void currrent_arrangment ()//function which simply showes current arrangment even after user modifies it
{                          //through reserving seats
	
	char choice;
		printf("Current seating arrangment of the theater \n \n");
	for(i=0;i<=9;i++){
		for( j=0;j<=9;j++)
		{
		printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
printf("Enter 'Y' to go back to go back : \n");
printf("Enter 'N' to exit : \n");
scanf(" %c",&choice);
if (choice=='y'||choice=='Y')
{
	audience();
}
else if(choice=='n' || choice=='N'){
	exit(0);
}

}
void add_movie(){
	int n;
char m;
int count,i;
FILE *fptr;
fptr=fopen("Movies.txt","a");
do{

char s_time[4];    //taking character arrays
char e_time[4];   //taking character arrays
int duration; 

printf ("Write number of digits of the movie name which you want to add\n");
scanf("%d",&n);   //to take the size of movie array
char movie[n];
printf ("Write the name of the movie you want to add\n");
for ( i=0;i<n;i++){
	scanf(" %c",&movie[i]);   //taking movie name from user 
}

printf("Enter the ending time of the movie \n");
scanf("%s",&e_time);     //taking input as strings 
printf("Enter the duration of the movie\n");
scanf("%d",&duration);    //taking input as strings 
fprintf(fptr,"%s\t\t%s\t\t%d",movie,e_time,duration);   //printing values in file 
fprintf(fptr,"\n");    //to go to new line

printf(" Movie is sucessfully added\n\n");

printf("Enter N to go back\nEnter Y if you want add another movie\n");
scanf(" %c",&m); 
}
while(m=='y' || m=='Y');//condition to check if user want to add more movies
fclose(fptr);    //closing the file
if(m=='n' || m=='N')
{
staff();//when user select to go back

}
else {
	while (!(m=='n' || m=='y'))//for invalid inputs
	{
			printf("Invalid\n");
			printf("Enter N or Y only\n");
			scanf(" %c",&m);
	}
}
}


void attendance_checker()
{  

int i,k,j;
char att;
char flag='n';
int id=0;
int found=0;
int arr[6]={985,987,986,987,988,989};   //there are 6 workers in theater
char arr1[6]={'A','A','A','A','A','A'}; //intializing array to A which represent absent
while (flag=='N'||flag=='n')
{  
    found=0;
printf("Enter employe id \n");
scanf("%d",&id);
for (i=0;i<6;i++)//sorting in array
{
    if (id == arr[i])
    {
        printf("Enter A for Absent P for present\n");
        scanf(" %c",&att);
        	if(att =='a'|| att == 'A')
            {
				printf("Employee %d is Absent\n",id );  //when worker is absent
                arr1[i]='A';    //assigning value A in attendence array
                break;
			}
		    else if(att == 'P'|| att == 'p')
            {
				printf(" Employe %d is Present \n",id);  //when worker is present
                arr1[i]='P';   //assigning character P which represents Present
                break;
		    }
     		else 
     		{
				printf("INVALID attendence \n");
				break;
			}
    }
    else
    {
    found++;//incrementing found when user id isnt found each time    
    }
}
if (found==6)//if after 6 iterations id isnt found so it means it is a invalid id
{
printf("Invalid id \n");
}
do
{
printf("Press (Y) to exit or press (N) to enter another id\n");
scanf(" %c", &flag);
}
while (flag!='y' && flag!='Y'&& flag!='n' && flag!='N');
}//outer while loop termenated here
for ( k = 0; k < 6; k++)//to show workers ids
    printf("%d\t",arr[k]);

printf("\n");
for (j = 0; j < 6; j++)//to show workers attendence
    printf(" %c\t",arr1[j]);
printf("\n\n\n");
staff();//going back 
}



void addOns(){
	system("cls");//to clear screen
	char c;
	int choice;
	int quant;
	printf("WELCOME TO FOOD CORNER\n");
	printf("\t\tMenu \n ");
	printf("\nPopcorns --2$\nDrinks --2$\nBurger --5$\nPizza --8$\n\n");
	do
	{
	printf("Press 1 for Popcorns\n");
	printf("Press 2 for Drinks\n");
	printf("Press 3 for Burgers\n");
	printf("Press 4 for Pizza\n");
	printf("Press 5 to go back\n");
	scanf("%d",&choice);
	
	
	if (choice==1)
	{
		printf("Please enter how many Popcorn Buckets you want :\n");
		scanf("%d",&quant);
		total_food =total_food + (2*quant);//multiplying with quantity and adding to total sum
	}
	else if (choice == 2)
	{
		printf("Please enter how many drinks you want : \n");
		scanf("%d",&quant);
		total_food = total_food +quant*2;//multiplying with quantity and adding to total sum
		
	}
	else if( choice==3)
	{
	
		printf("Please enter how many Burgers you want :\n");
		
			scanf("%d",&quant);
		total_food=total_food + quant*5;//multiplying with quantity and adding to total sumv
		
 printf("Enter number of Burgers you want : \n");
scanf("%d",&quant);
total_food=total_food+quant*8;//multiplying with quantity and adding to total sum
}
else if (choice==4)
{
	printf("Please enter the number of Pizza You want : \n");
	scanf("%d",&quant);
	total_food=total_food+quant*8;//multiplying with quantity and adding to total sum
}
else if (choice>!1 && choice<!5  )//when user inputs invalid comand
{
	printf("Invalid command");
}


}while (choice!=5); 

audience();//recursion
}

void staff(){
	
	int a;
	printf("*WELCOME DEAR MANAGER*\n");
printf("Chose option you want\n");
printf("1 for Staff Attendence\n");
printf("2 for Add movies\n");
printf("3 for going back\n");
scanf("%d",&a);
if(a==1)
{
attendance_checker();//calling attendence function
 }
else if(a==2)
{
add_movie();  //calling add_movie function
 }

else if(a==3)
{
    starting();//calling starting function
}
else {
printf("invalid\n");
    printf("\n\n");
	staff();//recursion when user inputs wrong command
}
}
void starting()
{
	
	int choice;
		int e;
char f = 'f', a = 'a', s = 's', t = 't';
	char A,B,C,D;
    char *w=&A;
    char *x=&B;
    char *y=&C;
    char *z=&D;
printf("Press 1 if you are theater staff\n");
printf("Press 2 if you are audience\n");
printf("Press 3 if you want to exit \n");
scanf(" %d",&e);
if(e==3)
{
    exit(0);
}
else if (e==2)
{

    	audience();//calling audience function
}
else if (e==1){
printf("Please enter your four letter password\n");
scanf(" %c %c %c %c",&A,&B,&C,&D);
printf(" %c %c %c %c\n",*w,*x,*y,*z);
if(*w =='f'&& *x=='a'&& *y=='s'&& *z=='t')//checking password
{
 printf("Correct! You have access to the theater portal.\n");
 staff();
}
else
{
while(!(*w=='f'&&*x=='a'&&*y=='s'&&*z=='t'))
{
	printf("Incorrect password\n");
	printf("Enter correct password\n");
	printf("Please Enter four digit passward\n");
scanf(" %c %c %c %c",&A,&B,&C,&D);
printf(" %c %c %c %c\n",*w,*x,*y,*z);
if(*w=='f'&&*x=='a'&&*y=='s'&&*z=='t')
{
 printf("Correct! You have access to the theater portal.\n");
 staff();
}
}
}
}
else {
printf("Invalid\n");
starting();
}
}
void reserve()
{
	
		printf("Enter Row and Seat number to Reserve the seat Each seat cost 400$ \n(enter 11 11 to return back)\n");
	scanf(" %d %d", &i,&j);
	if(i==11 && j==11)
	{
		audience();
	}
	while (i<0||i>10 || j<0||j>10)
	{
		printf ("Invalid seat! Enter number between 0 and 10 \n");
			scanf(" %d %d",&i,&j);
	}
    if  (arr[i-1][j-1]==1)
	{
	printf ("Already Reserved\n");
	}
    else if (arr[i-1][j-1]==0)//i-1 so that we can reserve exactly the seat which user wants
	{                         //if we write only i then wrong seat will be reserved because array ondex start at 0
	printf (" Reserved Succsefully\n");
	arr[i-1][j-1]=1;
	book_seat++; //incrementing number of seats
	}
	
		reserve();
}
int main(){
	
	starting();//calling starting Function
	
}
