#include<sys/resource.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define FILE_NAME "operation.bin"

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
    // fwrite(&addstudentdata,sizeof(addstudentdata),1,fp);
     fwrite(&addstudentdata,sizeof(addstudentdata),1,fp);
     fclose(fp);
}


void viewstudent(){
     s_file addstudentdata={0};
     FILE *fp=NULL;
     int c=0;
     fp=fopen(FILE_NAME,"rb");
     while(fread(&addstudentdata,sizeof(addstudentdata),1,fp)){
        c++;
        printf("Student No. %d\n",c);
        printf("Student Id is %u\n",addstudentdata.student_id);
        printf("Student Name is %s" ,addstudentdata.studentName);
        printf("Father Name is %s",addstudentdata.fatherName);
        printf("Student Address is %s",addstudentdata.studentAddr);
       
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

