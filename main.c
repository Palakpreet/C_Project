#include<sys/resource.h>
#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include<time.h>

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
   printf("\nCPU Time used %f seconds\n", cpu_time_used);
   
}
