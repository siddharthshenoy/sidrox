#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#define SIZE 10
int main()
{
    pid_t pid;
    ssize_t byte;
    char bin[SIZE], bout[SIZE];
    int fields[2],ch=0,count = 0;
    pipe(fields);
    pid = fork();
    if(pid==0)
    {        
            close(fields[0]);
            while(count<SIZE)
            {
                printf("Producer Sent : ");
                fgets(bin,3,stdin);
                size_t length = strlen(bin);
    		if((length > 0) && (bin[length-1] == '\n'))
    		{
        		bin[length-1] ='\0';
    		}
                write(fields[1], bin, SIZE);
                count++;
            }
            close(fields[1]);       
    }
    else
    {
        close(fields[1]);        
        wait(NULL);
        count=0;
        while(count++<SIZE)
        {
            byte = read(fields[0], bout, SIZE);
            if(byte!=0)
            {
            	 printf("Consumer got : ");                
                puts(bout);
            }            
        }
        count=0;        
    }
    return 0;
}
