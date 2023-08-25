#include<sys/resource.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define FILE_NAME "operation.bin"
typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;
typedef struct
{
    char username[50];
    char password[50];
} sFileHeader;

typedef struct
{
    unsigned int student_id;
    char fatherName[50];
    char studentName[50];
    char studentAddr[100];
 } s_file;

void addstudentrecord(){
     s_file addstudentdata={0};
     FILE  *fp=NULL;
     fp=fopen(FILE_NAME,"ab+");
     fflush(stdin);
     printf("Give student id\n");
     scanf("%u",&addstudentdata.student_id);
     fflush(stdin);
     printf("Give student Name\n");
     char stu[50];
     fgets(stu,50,stdin);
     fgets(addstudentdata.studentName,50,stdin);
     fflush(stdin);
     printf("Give fatherName\n");
     fgets(addstudentdata.fatherName,50,stdin);
     fflush(stdin);
     printf("Give student address\n");
     fgets(addstudentdata.studentAddr,50,stdin);
     fwrite(&addstudentdata,sizeof(addstudentdata),1,fp);
     fclose(fp);
}
void viewstudent(){
     s_file addstudentdata={0};
     FILE *fp=NULL;
     fp=fopen(FILE_NAME,"rb");
     while(fread(&addstudentdata,sizeof(addstudentdata),1,fp)){
        printf("\n\nStudent Id is %u",addstudentdata.student_id);
        printf("\nStudent Name is%s" ,addstudentdata.studentName);
        printf("\nFather Name is %s",addstudentdata.fatherName);
        printf("\nStudent Address is %s",addstudentdata.studentAddr);
       
}
}
void searchstudent(){
    int found=0;
    printf("\n Enter student id you want to search\n");
    s_file addstudentdata={0};
    FILE *fp=fopen(FILE_NAME,"rb");
    fflush(stdin);
    int studentid;
    scanf("%u",&studentid);
    while(fread(&addstudentdata,sizeof(addstudentdata),1,fp)){
        if(addstudentdata.student_id==studentid){
             found=1;
             break;
          }
      }
    if(found){
     printf("\n\n Searched Student is found: \n\n");
     printf("\n Student Name is %s ",addstudentdata.studentName);
     printf("\n Father Name is %s ",addstudentdata.fatherName);
     printf("\n Student Address is %s ",addstudentdata.studentAddr);
   }
   else{
    printf("\n Data not found");
   }
}
void deletestudentdata(){
    int found=0;
    printf("\n Enter student id you want to delete\n");
    s_file addstudentdata={0};
    FILE *fp=fopen(FILE_NAME,"rb");
    FILE *tmp=fopen("tmp.bin","wb");
    
    fflush(stdin);
    int studentid;
    scanf("%u",&studentid);
    while(fread(&addstudentdata,sizeof(addstudentdata),1,fp)){
        if(addstudentdata.student_id!=studentid){
             fwrite(&addstudentdata,sizeof(addstudentdata),1,tmp);
          }
        else{
          found=1;
        }
     }
    fclose(fp);
    fclose(tmp);
    remove(FILE_NAME);
    rename("tmp.bin",FILE_NAME);

      }


int main(){
    clock_t start_time,end_time;
    start_time=clock();
    struct rusage usage_start,usage_end;
    getrusage(RUSAGE_SELF,&usage_start);
    printf("\n\n\n<----------------------------WELCOME TO STUDENT DATABASE MANAGEMENT SYSTEM---------------------------------------------->");
    printf("\nChoose appropriate option from the following menu\n");
    printf("\n\n1. Insert student data");
    printf("\n\n2. Show all data inserted");
    printf("\n\n3. Search for a particular student");
    printf("\n\n4. Delete data if a particular student");
    printf("\n\n5. Exit");
    int p;
    printf("\n\nGive input ");
    scanf("%d",&p);

    while(p!=5){
      if(p==1)  addstudentrecord();
      else if(p==2)  viewstudent();
      else if(p==3) searchstudent();
      else if(p==4) deletestudentdata();
      else if(p==5) break;
      printf("Give next input");
      scanf("%d",&p);

} 
   getrusage(RUSAGE_SELF,&usage_end);
   end_time=clock();
   double cpu_time_used=((double)(end_time-start_time));
   long memory_used=usage_end.ru_maxrss-usage_start.ru_maxrss;
   printf("\n\n Memory used %ld ",memory_used);
   printf("\nCPU Time used %f seconds", cpu_time_used);
   
}
