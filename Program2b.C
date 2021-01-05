#include<stdio.h>
#include<conio.h>
#define max 30

int main()
{
     int i, j, temp, nop, pos, proc[max], bt[max], prio[max], wt[max], tat[max];
     float awt = 0, atat = 0;
     printf("Priority CPU Scheduling\n");
     printf("Enter the number of processes: ");
     scanf("%d", &nop);
     for(i=0; i<nop; i++)
     { proc[i] = i+1; }
     printf("Enter process burst time: ");
     for(i=0; i<nop; i++)
     { scanf("%d", &bt[i]); }
     printf("Enter process priority: ");
     for(i=0; i<nop; i++)
     { scanf("%d", &prio[i]); }

     for(i=0; i<nop; i++)
        {   for(j=i; j<nop; j++)
            {   if(prio[i]<prio[j])
                {   temp = prio[i];
	                  prio[i] = prio[j];
	                  prio[j] = temp;

                    temp = bt[i];
    	              bt[i] = bt[j];
    	              bt[j] = temp;

                    temp = proc[i];
                    proc[i] = proc[j];
                    proc[j] = temp;  }
              }
        }

      printf("Process\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
      for(i=0; i<nop; i++)
      {   wt[i] = 0;
          tat[i] = 0;
          for(j=0; j<i; j++)
          {   wt[i] += bt[j];  }
          tat[i] = wt[i] + bt[i];
          awt += wt[i];
          atat += tat[i];
          printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i], prio[i], bt[i], wt[i], tat[i]);
      }
      awt /= nop;
      atat /= nop;
      printf("Average waiting time = %f\n", awt);
      printf("Average turnaround time = %f\n", atat);
      getch();
      return 0;

}
