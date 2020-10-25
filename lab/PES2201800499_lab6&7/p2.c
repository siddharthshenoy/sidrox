#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int buffer[10000];
int in=0, out=0;

int mutex = 1;
int item_count = 0;

void wait(int *semaphore)
{
	while(*semaphore <= 0) ;
	*semaphore -= 1;
}

void signal(int *semaphore)
{
	*semaphore += 1;
}

void *producer()
{
    int next_produced = 0;
    while(1)
    {
        wait(&mutex);
		next_produced++;
		printf("Producer : Produced item %d\n", next_produced);
		buffer[in++] = next_produced;
		signal(&item_count);
        signal(&mutex);
        sleep(rand()%2);
    }
}

void *consumer()
{
    int next_consumed;
    while(1)
    {
        wait(&item_count);
		wait(&mutex);
			next_consumed = buffer[out++];
			printf("Consumer : Consumed item %d\n", next_consumed);
		signal(&mutex);
        sleep(rand()%3);
    }
}

int main()
{
    pthread_t p_thread, c_thread;
    pthread_create(&p_thread, NULL, producer, NULL);
    pthread_create(&c_thread, NULL, consumer, NULL);
    pthread_join(p_thread, NULL);
    pthread_join(c_thread, NULL);
}
