#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>

#define MAX_MSG_LEN 256
sem_t sem1;
char msg1[MAX_MSG_LEN]="1";
char msg2[MAX_MSG_LEN]="2";
int j=0;

void * thrdFun1(void *arg);
void toggleCase(char *buf);
int main()
{
  pthread_t thrd1;
  char       argmsg1[]="Thread1: ";
  int        res;
  int        thNum;
   int result =100;
   int k;
  res=sem_init(&sem1,0,1);
  res=pthread_create(&thrd1,NULL,thrdFun1,argmsg1);
   printf("I am in Main +\n");
  
     sem_wait(&sem1);
   printf("Prasad1\n");
   for(k=0;k<100000;k++)
      {
        //  printf("inside for loop\n");
                   j=j+1;
      }
    printf("Prasad2\n");
    printf(" Main 1  value=%d\n",j);
   sem_post(&sem1);
     
      printf("I am in Main - \n");
      
      pthread_join(thrd1,NULL);
      
      printf(" Main end\n");
  
}

void * thrdFun1(void *arg)
{
    int i=0;
     
  printf("I am in thread1\n");
 
    sem_wait(&sem1);
       printf("Prasad3\n");
      for(i=0;i<100000;i++)
      {
        //  printf("inside for loop\n");
                   j=j+1;
      }
      printf(" Thread 1j value=%d\n",j);
       printf("Prasad4\n");
      sem_post(&sem1);
       printf("Prasad5\n");
}



