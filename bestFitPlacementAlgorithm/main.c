#include <stdio.h>
#include <stdlib.h>

printAllocationArray(int allocation[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(allocation[i] != -1)
        {
            printf("Process %d is allocated the block number %d", (i + 1), allocation[i] + 1);
            printf("\n");
        }
        else if(allocation[i] == -1)
        {
            printf("Process %d has not been allocated a block", i + 1);
            printf("\n");
        }
    }
}

void bestFit(int mainMemoryBlocks[], int m, int processes[], int n)
{
    int allocation[n];   //this stores the index of the main memory blocks assigned to a process. It takes the process number as the index and gives the index of the main memory block assigned to that process.

    for(int i = 0; i < n; i++)
    {
        int bestBlock = -1;
        int bestBlockIndex = -1;
        for(int j = 0; j < m; j++)
        {
            if(mainMemoryBlocks[j] >= processes[i])
            {
                if(bestBlock == -1)
                {
                    bestBlock = mainMemoryBlocks[j];
                    bestBlockIndex = j;
                }
                else if(mainMemoryBlocks[j] < bestBlock)
                {
                    bestBlock = mainMemoryBlocks[j];
                    bestBlockIndex = j;
                }
            }
        }
        printf("%d \n", bestBlock);
        allocation[i] = bestBlockIndex;
        if(bestBlockIndex != -1)   //if a block has been allocated to the process
        {
            mainMemoryBlocks[bestBlockIndex] = mainMemoryBlocks[bestBlockIndex] - processes[i];
        }
    }

    printAllocationArray(allocation, n);
}

int main()
{
    int mainMemoryBlocks[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};
    int m = sizeof(mainMemoryBlocks) / sizeof(mainMemoryBlocks[0]);
    int n = sizeof(processes) / sizeof(processes[0]);

    bestFit(mainMemoryBlocks, m, processes, n);

    return 0;
}
