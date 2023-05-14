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

void nextFit(int mainMemoryBlocks[], int m, int processes[], int n)
{
    int allocation[n];

    int pointer = 0;
    for(int i = 0; i < n; i++)
    {
        int nextBlock = -1;
        int nextBlockIndex = -1;
        int j = pointer;
        do
        {
            if(mainMemoryBlocks[j] >= processes[i])
            {
                nextBlock = mainMemoryBlocks[j];
                nextBlockIndex = j;
                break;
            }
            j = (j + 1) % n;
        }while(j != pointer);
        printf("%d \n", nextBlock);
        allocation[i] = nextBlockIndex;
        if(nextBlockIndex != -1)
        {
            mainMemoryBlocks[nextBlockIndex] = mainMemoryBlocks[nextBlockIndex] - processes[i];
            pointer = (nextBlockIndex + 1) % n;
        }
    }

    printAllocationArray(allocation, n);
}

int main()
{
    int mainMemoryBlocks[] = {5, 10, 20};
    int processes[] = {10, 20, 5};
    int m = sizeof(mainMemoryBlocks) / sizeof(mainMemoryBlocks[0]);
    int n = sizeof(processes) / sizeof(processes[0]);

    nextFit(mainMemoryBlocks, m, processes, n);

    return 0;
}
