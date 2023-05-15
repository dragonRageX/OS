#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

///SRTF

void arrangeProcessesInAscendingBT(int AT[], int BT[], int n, int visited[], int processNumbers[])
{
    int temp;
    bool temp1;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            if(BT[j+1] < BT[j])
            {
                temp = AT[j];
                AT[j] = AT[j+1];
                AT[j+1] = temp;

                temp = BT[j];
                BT[j] = BT[j+1];
                BT[j+1] = temp;

                temp1 = visited[j];
                visited[j] = visited[j+1];
                visited [j+1] = temp1;

                temp = processNumbers[j];
                processNumbers[j] = processNumbers[j+1];
                processNumbers[j+1] = temp;
            }
            else if(BT[j+1] == BT[j])
            {
                if(AT[j+1] < AT[j])
                {
                    temp = AT[j];
                    AT[j] = AT[j+1];
                    AT[j+1] = temp;

                    temp = BT[j];
                    BT[j] = BT[j+1];
                    BT[j+1] = temp;

                    temp1 = visited[j];
                    visited[j] = visited[j+1];
                    visited [j+1] = temp1;

                    temp = processNumbers[j];
                    processNumbers[j] = processNumbers[j+1];
                    processNumbers[j+1] = temp;
                }
            }
        }
    }
    printf("Process Numbers: ");
    for(int i = 0; i < n; i++)
    {
        printf("P%d ", processNumbers[i]);
    }
    printf("\n");
}

int main()
{
    int AT[] = {0, 1, 2, 4};
    int BT[] = {5, 3, 4, 1};   //this is given in the question
    int n = sizeof(AT) / sizeof(AT[0]);
    int CT[n];
    int TAT[n];
    int WT[n];

    int processNumbers[n];
    int originalBT[n];
    bool visited[n];
    int summationOfBurstTime = 0;
    for(int i = 0; i < n; i++)
    {
        processNumbers[i] = i + 1;
        originalBT[i] = BT[i];
        visited[i] = false;
        summationOfBurstTime = summationOfBurstTime + BT[i];
    }

    arrangeProcessesInAscendingBT(AT, BT, n, visited, processNumbers);
    printf("AT: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", AT[i]);
    }
    printf("\n");
    printf("BT: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", BT[i]);
    }
    printf("\n");

    int time = 0;
    while(summationOfBurstTime != 0)
    {
        int f=0;
        for(int j = 0; j < n; j++)
        {
            if(AT[j] <= time && visited[j] == false)
            {
                //CT[j] = time + BT[j];
                BT[j] = BT[j] - 1;
                //time = CT[j];
                time++;
                if(BT[j] == 0)
                {
                    CT[j] = time;
                    visited[j] = true;
                }
                arrangeProcessesInAscendingBT(AT, BT, n, visited, processNumbers);
                summationOfBurstTime--;
                f = 1;
                break;
            }
        }
        if(f==0)
        {
            time++;
            summationOfBurstTime--;
        }
    }
    /*for(int i=0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }*/
    printf("Process Numbers: ");
    for(int i = 0; i < n; i++)
    {
        printf("P%d ", processNumbers[i]);
    }
    printf("\n");
    printf("AT: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", AT[i]);
    }
    printf("\n");
    printf("BT: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", BT[i]);
    }
    printf("\n");
    printf("Completion Time: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", CT[i]);
    }
    printf("\n");

    return 0;
}
