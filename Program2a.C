#include<stdio.h>
#include<conio.h>
#define max 30

int main()
{
     int nop, i, qtime, count=0, sq=0, temp, proc[max], bt[max], rem_bt[max], wt[max], tat[max];
     float awt = 0, atat = 0;
     printf("Pre-Emptive Round Robin CPU Scheduling\n");
     printf("Enter the number of processes: ");
     scanf("%d", &nop);
     for(i=0; i<nop; i++)
     { proc[i] = i+1; }
     printf("Enter process burst time: ");
     for(i=0; i<nop; i++)
     {  scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
      }
     printf("Enter quantum time: ");
     scanf("%d", &qtime);
     while(1)
     {
          for(i=0, count=0; i<nop; i++)
          {
              temp = qtime;
              if(rem_bt[i]==0)
              {   count++;
                  continue;   }
              if(rem_bt[i] > qtime)
                  rem_bt[i] -= qtime;
              else
                  if(rem_bt[i] >= 0)
                  {   temp = rem_bt[i];
                      rem_bt[i] = 0;
                  }
                  sq += temp;
                  tat[i] = sq;

          }

          if(nop == count)
              {   break;  }
      }

      printf("Process\t Burst Time\t Waiting Time\t Turnaround Time\n");
      for(i=0; i<nop; i++)
      {   wt[i] = tat[i] - bt[i];
          awt += wt[i];
          atat += tat[i];
          printf("%d\t%d\t\t%d\t\t%d\n", proc[i], bt[i], wt[i], tat[i]);
      }

      awt /= nop;
      atat /= nop;
      printf("Average waiting time = %f\n", awt);
      printf("Average turnaround time = %f\n", atat);
      getch();

      return 0; 

}
