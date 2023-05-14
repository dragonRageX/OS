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

void firstFit(int mainMemoryBlocks[], int m, int processes[], int n)
{
    int allocation[n];

    for(int i = 0; i < n; i++)
    {
        int firstBlock = -1;
        int firstBlockIndex = -1;
        for(int j = 0; j < m; j++)
        {
            if(mainMemoryBlocks[j] >= processes[i])
            {
                firstBlock = mainMemoryBlocks[j];
                firstBlockIndex = j;
                break;
            }
        }
        printf("%d \n", firstBlock);
        allocation[i] = firstBlockIndex;
        if(firstBlockIndex != -1)
        {
            mainMemoryBlocks[firstBlockIndex] = mainMemoryBlocks[firstBlockIndex] - processes[i];   //if a block has been allocated to the process
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

    firstFit(mainMemoryBlocks, m, processes, n);

    return 0;
}
