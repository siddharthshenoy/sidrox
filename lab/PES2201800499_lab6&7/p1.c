#include <pthread.h>
#include <stdio.h>
#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in, out;

void *Producer()
{
    int next_produced = 1;
    while(1)
    {

        printf("Producer: Produced item %d\n", next_produced);
        next_produced++;
        while(((in + 1) % BUFFER_SIZE) == out)
        ;
        buffer[in] = next_produced;
        in = (in + 1) % BUFFER_SIZE;
    }
}

void *Consumer()
{
    int next_consumed;
    while(1)
    {
        while(in == out)
        ;
        next_consumed = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        printf("Consumer: Consumed item %d\n", next_consumed);
    }
}

int main()
{
    pthread_t producer_thread_id, consumer_thread_id;
    pthread_create(&producer_thread_id, NULL, Producer, NULL);
    pthread_create(&consumer_thread_id, NULL, Consumer, NULL);
    pthread_join(producer_thread_id, NULL);
    pthread_join(consumer_thread_id, NULL);
}