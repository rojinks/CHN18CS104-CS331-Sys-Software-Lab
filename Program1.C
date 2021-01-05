#include<stdio.h>
#include<conio.h>
#define max 30

int main()
{
     int toggle, i, j, n, min, temp, proc[max], bt[max], wt[max], tat[max];
     float awt = 0, atat = 0;
     printf("Enter the number of processes: ");
     scanf("%d", &n);
     for(i=0; i<n; i++)
     { proc[i] = i+1; }
     printf("Enter process burst time: ");
     for(i=0; i<n; i++)
     { scanf("%d", &bt[i]); }
     printf("Enter 1 for SJF. Enter any other number for FCFS.\n");
     scanf("%d", &toggle);
     if(toggle == 1)
     {  for(i=0;i<n;i++)
        { for(j=i;j<n;j++)
          { if(bt[i]>bt[j])
            {   temp = bt[i];
	              bt[i] = bt[j];
	              bt[j] = temp;

                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;  }
          }
        }
      }
     printf("Process\t Burst Time\t Waiting Time\t Turnaround Time\n");
     for(i=0; i<n; i++)
     {  wt[i] = 0;
        tat[i] = 0;
        for(j=0; j<i; j++)
        {   wt[i] += bt[j];  }
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", proc[i], bt[i], wt[i], tat[i]);
      }
      awt /= n;
      atat /= n;
      printf("Average waiting time = %f\n", awt);
      printf("Average turnaround time = %f\n", atat);
      getch();
      return 0;
}
