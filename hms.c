#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include"hms.h"

int opd();//Sohaib's Production
int symptoms();//Sohaib's Production
void welcomepage();//Basil's Production
void adddoc();//Sohaib's Production && Excel file by Basil
void addpatient();//Sohaib's Production && Excel file by Basil
void search_doc();//Basil's Production
void search_pat();//Basil's Production
char mainpage ();//Sohaib's Production
void displayp();//Hassan's productions
void displayd();//Hassan's productions
void deleted();//Hassan's productions
void deletep();//Hassan's productions
void modify_doc();//Basil's Productions
void modify_pat();//Basil's Productions
void gotodoc();//Basil's Productions
void gotopat();//Basil's Productions
int main(){
	
    char ID[]="ADMIN", password[]="4454", id[20], p[20],ch;
    char ID1[]="DOC", password1[]="4634", id1[20], p1[20],ch1;
    int n=0, x, y,flag=0,choice,option,i,a,b,m=0;
    
    welcomepage();

    while(n<5){
        
		printf("\nID:");
        i=0;
        fflush(stdin);
        scanf("%s", &id);
         

        printf("\nPassword:");
       while(1)
	{
		ch=getch();
		if(ch==13)
		{
			p[i]='\0';
			break;
		}
		else
		{
		p[i]=ch;
		i++;
		printf("*");
		}
	}
        x=strcmp(id, ID);
        y=strcmp(p, password);

        if(x==0 && y==0){
            printf("\n\t\t\t\t\t********Sucessfully Logged In********");
            flag=1;
            printf("\nPress Enter to Continue.........\n");
			getch();
			system("cls");
            break;
        }
        else{
        	if(n>=4){
            printf("\nAccess Denied");
            printf("\nPress Enter to EXIT.......\n");
			exit(0);
            }
            else{
            printf("\nWrong Password, try again");
            n++;
            printf("\nPress Enter to Retry.......\n");
			getch();
			system("cls");
			welcomepage();
            }
        }
    }
    if(flag==1)
    {
	while(choice!=x)
	{
	choice=mainpage();
		switch(choice){
    		case 'A':{
		        while(m<5){
		    	label:
		    		puts("\n\t\t\t\t***************Sign In Page For Doctor's*************** ");
		        printf("\nDOCTOR'S ID:");
		        i=0;
		        fflush(stdin);
		        scanf("%s", &id1);
		         
		
		        printf("\nPassword:");
		       while(1)
			{
				ch1=getch();
				if(ch1==13)
				{
					p1[i]='\0';
					break;
				}
				else
				{
				p1[i]=ch1;
				i++;
				printf("*");
				}
			}
		        a=strcmp(id1, ID1);
		        b=strcmp(p1, password1);
		
		        if(a==0 && b==0){
		            printf("\n\t\t\t\t\t********Sucessfully Logged In********");
		            flag=1;
		            printf("\nPress Enter to Continue.........\n");
					getch();
					system("cls");
		            break;
		        }
		        else{
		        	if(m>=4){
		            printf("\nAccess Denied");
		            printf("\nPress Enter to EXIT.......\n");
					exit(0);
		            }
		            else{
		            printf("\nWrong Password, try again");
		            m++;
		            printf("\nPress Enter to Retry.......\n");
					getch();
					system("cls");
					goto label;
		            }
		        }
		    }
		    		system("cls");
					gotodoc();
		    		printf("\nPress Enter to Continue.......\n");
					getch();
					system("cls");
					}
		    		break;
		    		case 'B':{

			system("cls");
    		gotopat();
    		printf("\nPress Enter to Continue.......\n");
			getch();
			system("cls");
			break;
			}
    		
    		case 'C':{

			system("cls");
			opd();
    		printf("\nPress Enter to Continue.......\n");
			getch();
			system("cls");
    		break;
			}
    		case 'Z':{
    			return 0;
				break;
			}
    	
    			
    	}
    }
}
}






