#include <stdio.h>
#include <stdlib.h>

int main()
{
    int AT[] = {0, 1, 5, 6};
    int BT[] = {2, 2, 3, 4};   //this is given in the question
    int n = sizeof(AT) / sizeof(AT[0]);
    int CT[n];
    int TAT[n];
    int WT[n];

    printf("Arrival Time: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", AT[i]);
    }
    printf("\n");
    printf("Burst Time: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", BT[i]);
    }
    printf("\n");

    int temp;
    for(int i = 0; i < n - 1; i++)   //sort the AT and the BT ascendingly
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(AT[j + 1] < AT[j])
            {
                temp = AT[j + 1];
                AT[j + 1] = AT[j];
                AT[j] = temp;

                temp = BT[j + 1];
                BT[j + 1] = BT[j];
                BT[j] = temp;
            }
        }
    }

    int time = 0;
    for(int i = 0; i < n; i++)   //for AT
    {
        if(AT[i] <= time)   //then remove it from the ready queue and send it for execution
        {
            CT[i] = time + BT[i];
        }
        else if(AT[i] > time)   //wait and then send the process for execution
        {
            time = AT[i];
            CT[i] = time + BT[i];
        }
        time = time + BT[i];
    }
    printf("Completion Time: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", CT[i]);
    }
    printf("\n");

    for(int i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }
    printf("Turnaround Time: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", TAT[i]);
    }
    printf("\n");
    printf("Waiting Time: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", WT[i]);
    }
    printf("\n");

    return 0;
}
