#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#define BUFFER_SIZE 10 
void *producer(void *p);
void *consumer(void *c);
sem_t empty; 
sem_t full; 
int input=0;
int output=0;
int buffer[BUFFER_SIZE];
pthread_mutex_t mutex;

void *producer(void *p)
{
	int item;
	int i=0;
	while (i<BUFFER_SIZE)
	{
        	item=rand(); 
        	sem_wait(&empty); 
        	pthread_mutex_lock(&mutex); 
        	buffer[input]=item;
        	printf("Producer produced item %d\n",input);
       		input=(input+1)%BUFFER_SIZE;
        	pthread_mutex_unlock(&mutex); 
        	sem_post(&full); 
        	i++;
    	}
    	pthread_exit(0);
}

void *consumer(void *c)
{
	int i=0;
    	while(i<BUFFER_SIZE)
    	{
        	sem_wait(&full); 
        	pthread_mutex_lock(&mutex); 
        	int item=buffer[output];
        	printf("Consumer consumed item %d\n",output);
        	output=(output+1)%BUFFER_SIZE;
        	pthread_mutex_unlock(&mutex); 
        	sem_post(&empty); 
        	i++;    	
    	}
    	pthread_exit(0);
}

int main()
{
	pthread_t thread_p, thread_c; 
	sem_init(&empty,0,BUFFER_SIZE); 
	sem_init(&full,0,0); 
    	pthread_mutex_init(&mutex,NULL); 
    	pthread_attr_t attr1, attr2; 
    	pthread_attr_init(&attr1); 
    	pthread_attr_init(&attr2); 
    	pthread_create(&thread_p, &attr1, producer, NULL); 
    	pthread_create(&thread_c, &attr2, consumer, NULL); 
    	pthread_join(thread_p,NULL); 
    	pthread_join(thread_c,NULL);
    	pthread_mutex_destroy(&mutex); 
    	sem_destroy(&empty); 
    	sem_destroy(&full); 
    	return 0;
}


