#include<stdio.h>
int main()
{
int i, n, total = 0, x, counter = 0, qt;
int wt = 0, tt = 0, at[10], bt[10], temp[10];
float average_wait_time, average_turnaround_time;
printf("\nEnter Total Number of Processes : ");
scanf("%d", &n);
x = n;
for(i = 0; i < n; i++)
{
    printf("\nEnter Details of Process[%d]\n", i + 1);
    printf("Arrival Time:\t");
    scanf("%d", &at[i]);
    printf("Burst Time:\t");
    scanf("%d", &bt[i]);
    temp[i] = bt[i];
}
      printf("\nEnter Time Quantum:\t");
      scanf("%d", &qt);
      printf("\nProcess ID\t\tBurst Time\tarrival time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= qt && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - qt;
                  total = total + qt;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess%d\t\t\t%d\t\t%d\t\t %d\t\t\t %d", i + 1,bt[i],at[i],total - at[i], total - at[i] - bt[i]);
                  wt = wt + total - at[i] - bt[i];
                  tt = tt + total - at[i];
                  counter = 0;
            }
            if(i == n - 1)
            {
                  i = 0;
            }
            else if(at[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
      average_wait_time = wt * 1.0 / n;
      average_turnaround_time = tt * 1.0 / n;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
      return 0;
}