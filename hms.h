#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct doctor{
	char name[50];
	int id;
	char specialization[100];
    long long int num;
    char pos[20];
    char dept[50];
    
	};

struct patient{
	int id;
    char pname[50];
    int age;
	int roomnum;
	char admitteddept[50];
	char cause[100];//reason for admit
	char assigneddoc[50];
	unsigned int contactnum;
	unsigned int emergencycontact;
	
};
char mainpage(){
char ID[]="ADMIN", password[]="4454", id[20], p[20];
int n=0, x, y;char choice;
	
    	printf("\nWelcome  What would you like to do?(Enter Corresponding Alphabet of your choice)\n\n");
    	printf("(A)DOCTORS MANAGEMENT\n(B)PATIENT MANAGEMENT\n(C)OPD\n(Z)END PROGRAM\n");
    	fflush(stdin);
		scanf("%c",&choice);
    	return choice;
}
void adddoc(){
	struct doctor doc;
    FILE *adddoc;
    FILE *adddoc_view;

    
	adddoc=fopen("Doctor.txt","ab+");
	adddoc_view=fopen("Doctor_View.xls","a+");
	puts("Enter Doctor Name: ");
	fflush(stdin);
	gets(doc.name);
	fprintf(adddoc_view,"%s\t",doc.name);
	
	fflush(stdin);
	puts("Enter Doctor ID: ");
	fflush(stdin);
	scanf("%d",&doc.id);
	fprintf(adddoc_view,"%d\t",doc.id);
	
	fflush(stdin);
	puts("Enter Department: ");
	fflush(stdin);
	gets(doc.dept);
	fprintf(adddoc_view,"%s\t",doc.dept);
	
	fflush(stdin);
	puts("Enter Position: ");
	fflush(stdin);
	gets(doc.pos);
	fprintf(adddoc_view,"%s\t",doc.pos);
	
	fflush(stdin);
	puts("Enter Doctor Specialization: ");
	fflush(stdin);
	gets(doc.specialization);
	fprintf(adddoc_view,"%s\t",doc.specialization);
	
	fflush(stdin);
	puts("Enter Doctor Contact Number: ");
	fflush(stdin);
	scanf("%d",&doc.num);
	fprintf(adddoc_view,"+92%lld\n",doc.num);
	fflush(stdin);
	
	fflush(stdin);
	fwrite(&doc,sizeof(struct doctor),1,adddoc);
	fclose(adddoc);
	fclose(adddoc_view);
			
}
void addpatient(){
	struct patient pat;
	FILE *addpat;
	FILE *addpat_view;
	
	addpat=fopen("patient.txt","ab+");
	addpat_view=fopen("patient_view.xls","a+");
	puts("Enter Patient Id: ");
	fflush(stdin);
	scanf("%d",&pat.id);
	fprintf(addpat_view,"%d\t",pat.id);
	fflush(stdin);
	
	fflush(stdin);
	
	
	puts("Enter Patient Name: ");
	fflush(stdin);
	gets(pat.pname);
	fprintf(addpat_view,"%s\t",pat.pname);
	fflush(stdin);
	
	puts("Enter Patient Age: ");
	fflush(stdin);
	scanf("%d",&pat.age);
	fprintf(addpat_view,"%d\t",pat.age);
	fflush(stdin);
	
	puts("Enter Room Number where the patient is admitted to: ");
	scanf("%d",&pat.roomnum);
	fprintf(addpat_view,"%d\t",pat.roomnum);
	fflush(stdin);
	
	puts("Enter Name of Department where the patient has been admitted to: ");
	fflush(stdin);
	gets(pat.admitteddept);
	fprintf(addpat_view,"%s\t",pat.admitteddept);
	fflush(stdin);

	
	puts("Cause Of Admit: ");
	fflush(stdin);
	gets(pat.cause);
	fprintf(addpat_view,"%s\t",pat.cause);
	fflush(stdin);
	
	puts("Enter Name of Doctor assigned to this patient: ");
	fflush(stdin);
	gets(pat.assigneddoc);
	fprintf(addpat_view,"%s\t",pat.assigneddoc);
	fflush(stdin);
	
	puts("Enter Patient Contact Number:");
	scanf("%u",&pat.contactnum);
	fprintf(addpat_view,"%u\t",pat.contactnum);
	fflush(stdin);
	
	
	puts("Enter Emergency Contact Number: ");
	scanf("%u",&pat.emergencycontact);
	fprintf(addpat_view,"%u\n",pat.emergencycontact);
	fflush(stdin);
	
	fwrite(&pat,sizeof(struct patient),1,addpat);
	fclose(addpat);
	fclose(addpat_view);	
}
void search_doc()
{
struct doctor doc;
int id;
int flag1=0;char print_check=0;
FILE *adddoc;
adddoc=fopen("Doctor.txt","rb");
if(adddoc==NULL){
	puts("Can not open File");
	puts("Press Enter to Continue.......");
	getch();
	system("cls");
	mainpage();
}
else{
puts("Enter the Doctor ID you want to search:");
scanf("%d",&id);
fflush(stdin);
while(fread(&doc,sizeof(struct doctor),1,adddoc)>0 && flag1==0){
	if(doc.id==id){
		flag1=1;
		printf("Record is Found\n");
		fflush(stdin);
		puts("Enter P to Print the Doctors Detail or Enter R to return to Main Page.");
		scanf("%c",&print_check);
		fflush(stdin);
		if(print_check=='R'){
			mainpage();
		}
		else if(print_check=='P'){
			printf("\n\n\t\t\t!!!!!!!!!!!!!! Display Doctor's Record !!!!!!!!!!!!!\n");
			printf("Doctor Name:%s\nDoctor ID:%d\nDoctor Specialization:%s\nDoctor Number:+92%lld\nDoctor Position:%s\nDoctor Department:%s",doc.name,doc.id,doc.specialization,doc.num,doc.pos,doc.dept);
			}
			
	}
}
if(flag1==0)
{
printf("Record Not Found\n");
		

}	
}
fclose(adddoc);
}
void search_pat()
{
	struct patient pat;
	int flag=0;int IDP;char print;
	FILE *addpat;
	addpat=fopen("patient.txt","rb");
	if(addpat==NULL)
	{
		puts("FILE CANNOT BE OPEN");
		printf("Press Enter to Continue.......");
		getch();
		system("cls");
		mainpage();
	}
	else
	{
	puts("Enter Patient ID you want to find:");
	scanf("%d",&IDP);
	fflush(stdin);
	while(fread(&pat,sizeof(struct patient),1,addpat)>0 && flag==0){
		if(pat.id==IDP){
			flag=1;
			printf("Patient Found\n");
			fflush(stdin);
			puts("Press P to print Patient Details or R to return");
			scanf("%c",&print);
			fflush(stdin);
			if(print=='P'){
				fflush(stdin);
				printf("\n\n\t\t\t!!!!!!!!!!!!!! Display Patient's Record !!!!!!!!!!!!!\n");
				printf("Patient Name:%s\nPatient id:%d\nPatient Room Number:%d\nAssigned Doctor:%s\nADMITTED Department:%s\nContact Number:+92%u\nEmergency Contact Number:+92%u\nCause of Admission:%s\n",pat.pname,pat.id,pat.roomnum,pat.assigneddoc,pat.admitteddept,pat.contactnum,pat.emergencycontact,pat.cause);
				
				printf("Press Enter to Continue.......");
				getch();
				fflush(stdin);
				system("cls");
				mainpage();
			}
			else if(print=='r'){
				mainpage();
			}
		}
		if(flag==0){
			puts("Record Not Found.");
			fflush(stdin);
			printf("Press Enter to Continue.......");
			getch();
			fflush(stdin);
			mainpage();
		}
	}
	
	
	
	
	
	
	}
	fclose(addpat);
}

void welcomepage()
{
	system("COLOR 3F");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        |                 WELCOME                   |");
    printf("\n\t\t\t        |                   TO                      |");
    printf("\n\t\t\t        |          Mankind Hospital Record          |");
    printf("\n\t\t\t        |                MANAGEMENT                 |");
    printf("\n\t\t\t        |                  SYSTEM                   |");
    printf("\n\t\t\t        -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t\t\t\t****WELCOME**\n\t\t\t\t\t*Please Enter Your Credentials* ");
    
}
void displayp()
{
FILE *addpat;
struct patient pat;
	addpat=fopen("patient.txt","rb");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Display Patients Record !!!!!!!!!!!!!\n");
				 while (fread(&pat,sizeof(struct patient), 1, addpat) == 1)
		{
				printf("Patient Name:%s\nPatient id:%d\nPatient Room Number:%d\nAssigned Doctor:%s\nADMITTED Department:%s\nContact Number:+92%u\nEmergency Contact Number:+92%u\nCause of Admission:%s\n",pat.pname,pat.id,pat.roomnum,pat.assigneddoc,pat.admitteddept,pat.contactnum,pat.emergencycontact,pat.cause);
				puts("");
				puts("");
				puts("");	}
	printf("Press Enter to Continue.......");
	getch();
	fflush(stdin);
	system("cls");
	mainpage();
	
	fclose(addpat);
}
void displayd()
{
FILE *adddoc;
struct doctor doc;
	adddoc=fopen("doctor.txt","rb");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Display Doctors Record !!!!!!!!!!!!!\n");
				 while (fread(&doc,sizeof(struct doctor), 1, adddoc) == 1)
		{printf("Doctor Name:%s\nDoctor ID:%d\nDoctor Specialization:%s\nDoctor Number:%lld\nDoctor Position:%s\nDoctor Department:%s",doc.name,doc.id,doc.specialization,doc.num,doc.pos,doc.dept);
				
				puts("");
				puts("");
				puts("");	}
	printf("Press Enter to Continue.......");
	getch();
	fflush(stdin);
	system("cls");
	mainpage();
	
	fclose(adddoc);
}
void deleted()
{
	int id;
	struct doctor doc;
	printf("enter the id of Doctor you want to Delete:\n");
	scanf("%d",&id);
FILE *adddoc,*adddoc2;
	adddoc=fopen("doctor.txt","rb");
	adddoc2=fopen("copydoc.txt","a+");
	{
		 while (fread(&doc,sizeof(struct doctor), 1, adddoc) == 1)
		 {
		 	if(doc.id!=id)
		 	{
		 		fwrite(&doc,sizeof(struct doctor),1,adddoc2);
			}
		 }
		 fclose(adddoc);
		 fclose(adddoc2);
		 remove("doctor.txt");
		 rename("copydoc.txt","doctor.txt");
		 puts("Record has been Deleted Succesfully");
	}
}
void deletep()
{
	int id;
	struct patient pat;
	printf("Enter the Id of Patient you want to Delete:\n");
	scanf("%d",&id);
FILE *addpat,*addpat2;
	addpat=fopen("patient.txt","rb");
	addpat2=fopen("copypat.txt","a+");
	{
		 while (fread(&pat,sizeof(struct patient), 1, addpat) == 1)
		 {
		 	if(pat.id!=id)
		 	{
		 		fwrite(&pat,sizeof(struct patient),1,addpat2);
			}
		 }
		 fclose(addpat);
		 fclose(addpat2);
		 remove("patient.txt");
		 rename("copypat.txt","patient.txt");
		 puts("Record has been Deleted Succesfully");
	}
}
void modify_doc(){
	struct doctor doc;
    FILE *adddoc;
	int temp,flag=0,choice,choice0;
   	adddoc=fopen("Doctor.txt","rb+");
   	fflush(stdin);
	here:
	printf("Enter Doctor ID to Modify:");
	scanf("%d",&temp);
	while(fread(&doc,sizeof(struct doctor),1,adddoc)>0 && flag==0){
		if(doc.id==temp);
		flag=1;
		struct doctor doc;
    FILE *adddoc;
    FILE *adddoc_view;

    
	adddoc=fopen("Doctor.txt","rb+");
	adddoc_view=fopen("Doctor_View.xls","r+");
	puts("Enter Doctor Name: ");
	fflush(stdin);
	gets(doc.name);
	fprintf(adddoc_view,"%s\t",doc.name);
	
	fflush(stdin);
	puts("Enter Doctor ID: ");
	fflush(stdin);
	scanf("%d",&doc.id);
	fprintf(adddoc_view,"%d\t",doc.id);
	
	fflush(stdin);
	puts("Enter Department: ");
	fflush(stdin);
	gets(doc.dept);
	fprintf(adddoc_view,"%s\t",doc.dept);
	
	fflush(stdin);
	puts("Enter Position: ");
	fflush(stdin);
	gets(doc.pos);
	fprintf(adddoc_view,"%s\t",doc.pos);
	
	fflush(stdin);
	puts("Enter Doctor Specialisation: ");
	fflush(stdin);
	gets(doc.specialization);
	fprintf(adddoc_view,"%s\t",doc.specialization);
	
	fflush(stdin);
	puts("Enter Doctor Contact Number: ");
	fflush(stdin);
	scanf("%d",&doc.num);
	fprintf(adddoc_view,"+92%lld\n",doc.num);
	fflush(stdin);
	
	fflush(stdin);
	fseek(&doc,-(long)sizeof (struct doctor),adddoc);
	fwrite(&doc,sizeof(struct doctor),1,adddoc);
	fclose(adddoc);
	fflush(stdin);
	puts("Doctors Record Succesfully Modified.");
	puts("Press any Key to Print the Modified Data");
	getch();
	system("cls");
				printf("\n\n\t\t\t!!!!!!!!!!!!!! Display Modified Doctor's Record !!!!!!!!!!!!!\n");
				printf("Doctor Name:%s\nDoctor ID:%d\nDoctor Specialization:%s\nDoctor Number:+92%lld\nDoctor Position:%s\nDoctor Department:%s",doc.name,doc.id,doc.specialization,doc.num,doc.pos,doc.dept);
	}
	if(flag==0){
		puts("Doctor's ID is not Found!\nPlease Input Correct Id Again.\nPress:\n\t(1)Enter ID Again\n\t(2)Go to Main Page.");
		scanf("%d",choice0);
		if(choice0==1){
			system("cls");
			goto here;
		}
		else if(choice0==2){
			system("cls");
			mainpage();
		}
		
	}
	}
		
	void modify_pat(){
	struct patient pat;
    FILE *addpat;
	FILE *addpat_view;
	int temp,flag=0,choice,choice0;
   	addpat=fopen("patient.txt","rb+");
   	fflush(stdin);
	here:
	printf("Enter Patient ID to Modify:");
	scanf("%d",&temp);
	while(fread(&pat,sizeof(struct patient),1,addpat)>0 && flag==0){
		if(pat.id==temp);
		flag=1;

    
	addpat=fopen("patient.txt","rb+");
	addpat_view=fopen("patient_view.xls","r+");
	
	puts("Enter Patient Id: ");
	fflush(stdin);
	scanf("%d",&pat.id);
	fprintf(addpat_view,"%d\t",pat.id);
	fflush(stdin);
	
	fflush(stdin);
	
	
	puts("Enter Patient Name: ");
	fflush(stdin);
	gets(pat.pname);
	fprintf(addpat_view,"%s\t",pat.pname);
	fflush(stdin);
	
	puts("Enter Patient Age: ");
	fflush(stdin);
	scanf("%d",&pat.age);
	fprintf(addpat_view,"%d\t",pat.age);
	fflush(stdin);
	
	puts("Enter Room Number where the patient is admitted to: ");
	scanf("%d",&pat.roomnum);
	fprintf(addpat_view,"%d\t",pat.roomnum);
	fflush(stdin);
	
	puts("Enter Name of Department where the patient has been admitted to: ");
	fflush(stdin);
	gets(pat.admitteddept);
	fprintf(addpat_view,"%s\t",pat.admitteddept);
	fflush(stdin);

	
	puts("Cause Of Admit: ");
	fflush(stdin);
	gets(pat.cause);
	fprintf(addpat_view,"%s\t",pat.cause);
	fflush(stdin);
	
	puts("Enter Name of Doctor assigned to this patient: ");
	fflush(stdin);
	gets(pat.assigneddoc);
	fprintf(addpat_view,"%s\t",pat.assigneddoc);
	fflush(stdin);
	
	puts("Enter Patient Contact Number:");
	scanf("%u",&pat.contactnum);
	fprintf(addpat_view,"%u\t",pat.contactnum);
	fflush(stdin);
	
	
	puts("Enter Emergency Contact Number: ");
	scanf("%u",&pat.emergencycontact);
	fprintf(addpat_view,"%u\n",pat.emergencycontact);
	fflush(stdin);
	
	fseek(&pat,-(long)sizeof (struct patient),addpat);
	fwrite(&pat,sizeof(struct patient),1,addpat);
	
	fflush(stdin);
	puts("Patient Record Succesfully Modified.");
	puts("Press any Key to Print the Modified Data");
	getch();
	system("cls");
				printf("\n\n\t\t\t!!!!!!!!!!!!!! Display Modified Patients's Record !!!!!!!!!!!!!\n");
				printf("Patient Name:%s\nPatient id:%d\nPatient Room Number:%d\nAssigned Doctor:%s\nADMITTED Department:%s\nContact Number:+92%u\nEmergency Contact Number:+92%u\nCause of Admission:%s\n",pat.pname,pat.id,pat.roomnum,pat.assigneddoc,pat.admitteddept,pat.contactnum,pat.emergencycontact,pat.cause);
	}
	if(flag==0){
		puts("Patients's ID is not Found!\nPlease Input Correct Id Again.\nPress:\n\t(1)Enter ID Again\n\t(2)Go to Main Page.");
		scanf("%d",choice0);
		if(choice0==1){
			system("cls");
			goto here;
		}
		else if(choice0==2){
			system("cls");
			mainpage();
		}
		
	}
	fclose(addpat);
	fclose(addpat_view);
	}
	
int opd(){
	int flag=0,call=0;
	printf("Please select patient symptoms: ");
	
	flag=symptoms(call);
	
	return flag;
}

int symptoms(call){
	char ch;
	int n=-1,flagA=0,flagB=0,flagC=0,flagD=0,flagE=0,flagF=0,flagG=0,flagH=0,flagI=0,flagJ=0,flagK=0,flagL=0,flagM=0,flagN=0,flagO=0,flagP=0,flagQ=0,flagR=0,flag=0;
	
	printf("\nA-Fever\nB-Vomiting\nC-Diarrhea\nD-Breathing Problems\nE-Ear Pain\nF-Skin Infection\nG-Heavy Cough\n-Wheezing\nI-Physical Pain\nJ-Runny Nose\nK-Congestion\nL-Light Cough\nM-Rhinnorea\nN-Weakness\nO-Headache\nP-Rash\nQ-Colouration of skin and eyes\nR-Fatigue\nS-Done\n");
	do{
		printf("\nEnter corresponding letter of symptom(ENTER T IF PATIENT IS TO BE ADMITTED): ");
		fflush(stdin);				
		scanf("%c",&ch);
		switch(ch){
 	        case 'A':
 	        case 'a':
	        	if(flagA==1){
	 			    continue;
			 	}
	        	flagA=1;
				break;
			case 'B':
	 	    case 'b':
			 	if(flagB==1){
				    continue;
			 	}     	
	        	flagB=1;
				break;
			case 'C':
	 	    case 'c':
	     	    if(flagC==1){
				    continue;
			 	}
	        	flagC=1;
				break;
			case 'D':
	 	    case 'd':
	     	    if(flagD==1){
				    continue;
			 	}
	        	flagD=1;
				break;
			case 'E':
	 	    case 'e':
	     	    if(flagE==1){
				    continue;
                }
	        	flagE=1;
				break;
			case 'F':
	 	    case 'f':
	     	    if(flagF==1){
				    continue;
			 	}
	        	flagF=1;
				break;
			case 'G':
	 	    case 'g':
	     	    if(flagG==1){
				    continue;
			 	}
	        	flagG=1;
				break;
			case 'H':
	 	    case 'h':
	     	    if(flagH==1){
				    continue;
			 	}
	        	flagH=1;
				break;
			case 'I':
	 	    case 'i':
	     	    if(flagI==1){
				    continue;
			 	}
	        	flagI=1;
				break;
			case 'J':
	 	    case 'j':
			 	if(flagJ==1){
				    continue;
			 	}     	
	        	flagJ=1;
				break;
			case 'K':
	 	    case 'k':
  	            if(flagK==1){
				    continue;
			 	}
	        	flagK=1;
				break;
			case 'L':
	 	    case 'l':
	     	    if(flagL==1){
				    continue;
			 	}
	        	flagL=1;
				break;
			case 'M':
	 	    case 'm':
	     	    if(flagM==1){
				    continue;
			 	}		
	        	flagM=1;
				break;
			case 'N':
	 	    case 'n':
	     	    if(flagN==1){
				    continue;
  			 	}
	        	flagN=1;
				break;
			case 'O':
	 	    case 'o':
	     	    if(flagO==1){
	 			    continue;
			    }
	        	flagO=1;
				break;
			case 'P':
	 	    case 'p':
	     	    if(flagP==1){
	                continue;
                }
	        	flagP=1;
				break; 
	        case 'Q':
        	case 'q':
        		if(flagQ==1){
	                continue;
                }
	        	flagQ=1;
				break;
			case 'R':
	 	    case 'r':
	     	    if(flagR==1){
	                continue;
                }
	        	flagR=1;
				break;
			case 'S':
	 	    case 's':
	     	    break;
		    case 'T':
     	    case 't':
   		    	return 0;
		    default: 
                printf("Invalid Choice, try again");
                continue;
		}
	    n++;
	}
	while((ch!='S')&&(ch!='T')&&(ch!='s')&&(ch!='t'));
	
	switch(n){
		    case 0:
				if(call==0){
			    printf("\nPlease recheck patient and look for symptoms\n");
				call++;
				symptoms(call);	  	
                }
                else{
                	printf("\nPatient Is Well\nKindly Discharge\n");
                	flag=1;
				}
				break;
	        case 1:
			    if((flagA==1)&&(flagI==1)||(flagO==1)){
		    	    printf("\nPrescribe Patient with Panadol or Tylenol.\n");
		    	    flag=1;
				} 
				if((flagB==1)||(flagC==1)){
		    	    printf("\nPrescribe Patient with Pepto-Bismol.\n");
		    	    flag=1;
				}
				if(flagD==1){
		    	    printf("\nPrescribe Patient with Theophylline.\n");
		    	    flag=1;
				}  
		        if(flagE==1){
		    	    printf("\nPrescribe Patient with Ibuprofen or Naproxen.\n");
		    	    flag=1;
				} 
		        if(flagF==1){
		    	    printf("\nPrescribe Patient with either one of Dicloxacillin, Erythromycine or Tetracycline if light, or Fluconazole or Itraconazole in case of serious infections.\n");
				    flag=1;
				} 
		        if(flagG==1){
		    	    printf("\nPrescribe Patient with Dextromethorphan.\n");
				    flag=1;
				} 
		        if(flagH==1){
		    	    printf("\nPrescribe Patient with Albuterol or Levalbuterol.\n");
				    flag=1;
				} 
                if((flagJ==1)||(flagM==1)){
		    	    printf("\nPrescribe Patient with Chlorpheniramine.\n");
				    flag=1;
				} 
		        if((flagK==1)||(flagL=1)){
		    	    printf("\nPrescribe Patient with Phenylephrine.\n");
				    flag=1;
				} 
		        if(flagN==1){
		    	    printf("\nPrescribe Patient with Tagamet or Zidovudine.\n");
				    flag=1;
				} 
		        if(flagP==1){
		    	    printf("\nPrescribe Patient with Hydrocortisone Cream.\n");
				    flag=1;
				}
		        if(flagQ==1){
		    	    printf("\nPrescribe Patient with Cysteamine Cream.\n");
				    flag=1;
				} 
		        if(flagR==1){
		    	    printf("\nPrescribe Patient with Klonopin or Xanax.\n");
				    flag=1;
				}
				break; 
		    case 2:
				if((flagA==1)&&(flagP==1)){
				    printf("\nPrescribe patient with Zovirax or Sitavig.\nDiagnosed with Chicken Pox\n");	
				    flag=1;
				}     
				if((flagB==1)&&(flagC==1)){
				    printf("\nPrescribe patient with ORS or Ciprofloxacin.\nDiagnosed with Cholera\n");	
				    flag=1;
				}  
				printf("Vaccinations recommended.\n");
				break;
			case 3:
			    if((flagA==1)&&(flagI==1)&&(flagO==1)){
				    printf("\nPrescribe patient with Acetaminophen.\nRecommended to have the patient admitted under observation till improvement.\nDiagnosed with Dengue");     	
				    flag=1;
				}
				if((flagA==1)&&(flagI==1)&&(flagO==1)){
				    printf("Recommended to have the patient admitted under observation till improvement.\nNeed lots of rest and to stay hydrated.\nDiagnosed with Chikungunya");     	
				    flag=1;
				}   
				break;
			case 4:
			    if((flagA==1)&&(flagN==1)&&(flagC==1)&&(flagO==1)){
				    printf("\nPrescribe patient with Ceftiraxone.\nRecommended to keep patient under observation.\nDiagnosed with Typhoid.\n");  	     	
				    flag=1;
				}
				if((flagA==1)&&(flagC==1)&&(flagJ==1)&&(flagQ==1)){
					printf("Prescribe patient with Phenobarbital.\nDiagnosed with Jaundice.\n"); 	    	
				    flag=1;
				}
			    break;
			case 5:
			    if((flagK==1)&&(flagM==1)&&(flagJ==1)&&(flagL==1)&&(flagO==1)){
					printf("Prescribe patient with Tylenol.\nDiagnosed with Common Cold.\n");		   	      	
					flag=1;				   	    	
				}			   
		
	    //take back to start of program
	}
	if((n>0)&&(flag==1)){
		return 1;
	}
	else{
		printf("\nPatient is to be checked by a Doctor so Press Enter to Proceed to Add Patient's Details...\n");
		getch();
		system("cls");
		addpatient();
	}
}
void gotodoc(){
	int choice;
	here:
	printf("\nEnter The Numbers For Following Options:\n\n\n");
	printf("(1)Add Doctor\n(2)Modify Doctor's Details\n(3)Delete Doctor's Details\n(4)Display All Doctors\n(5)Search a Doctor\n(6)Return to Main Page\n");
	scanf("%d",&choice);
	switch(choice){
	case 1:{
		    system("cls");
			adddoc();
			printf("\nPress Enter to Continue.......\n");
			getch();
			system("cls");
		break;
	}
	case 2:{
			system("cls");
			modify_doc();
			printf("\nPress Enter to Continue.......\n");
			getch();
			system("cls");
		break;
	}
	case 3:{
			system("cls");
			deleted();
			printf("\nPress Enter to Continue.......\n");
			getch();
			system("cls"); 
		break;
	}
	case 4:{
			system("cls");
			displayd();
			printf("\nPress Enter to Continue.......\n");
			getch();
			system("cls");
		break;
	}
	case 5:{
			system("cls");
			search_doc();
			printf("\nPress Enter to Continue.......\n");
			getch();
			system("cls"); 
		break;
	}
	case 6:{
			system("cls");
			mainpage();
			printf("\nPress Enter to Continue.......\n");
			getch();
			system("cls");	
		break;
	}
	default:{
			puts("Wrong Input!");
			puts("Press Enter to Retry");
			getch();
			system("cls");
			goto here;
	}
	}
}
void gotopat(){
	int choice;
	here:
		printf("\nEnter The Numbers For Following Options:\n");
		printf("\n\n\n(1)Add Pateint\n(2)Modify Pateint's Details\n(3)Delete Pateint's Details\n(4)Display All Pateint\n(5)Search a Pateint\n(6)Return to Main Page\n");
		scanf("%d",&choice);
	switch(choice){
	case 1:{
		    system("cls");
			addpatient();
			printf("\nPress Enter to Continue.......\n");
			getch();
			system("cls");
		break;
	}
	case 2:{
			system("cls");
			modify_pat();
			printf("\nPress Enter to Continue.......\n");
			getch();
			system("cls");
		break;
	}
	case 3:{
			system("cls");
			deletep(); 
			printf("\nPress Enter to Continue.......\n");
			getch();
			system("cls"); 
		break;
	}
	case 4:{
			system("cls");
			displayp(); 
			printf("\nPress Enter to Continue.......\n");
			getch();
			system("cls");
		break;
	}
	case 5:{
			system("cls");
			search_pat(); 
			printf("\nPress Enter to Continue.......\n");
			getch();
			system("cls"); 
		break;
	}
	case 6:{
			system("cls");
			mainpage(); 
			printf("\nPress Enter to Continue.......\n");
			getch();
			system("cls");	
		break;
	}
	default:{
			puts("Wrong Input!");
			puts("Press Enter to Retry");
			getch();
			system("cls");
			goto here;
	}
	}
}