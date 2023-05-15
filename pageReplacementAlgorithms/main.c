#include <stdio.h>
#include <stdlib.h>

void optimal()
{
    int referenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0 ,1};
    int frames[4] = {9999, 9999, 9999, 9999};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);
    int hits = 0;
    int faults = 0;
    for(int i = 0; i < n; i++)
    {
        int f = 0;
        for(int j = 0; j < 4; j++)
        {
            if(frames[j] == referenceString[i])
            {
                hits++;
                f = 1;
                //print frames;
                printf("Hit: %d \n", frames[j]);
                for(int k = 0; k < 4; k++)
                {
                    printf("%d \n", frames[k]);
                }
            }
        }
        if(f == 0)
        {
            faults++;
            if(i < 4)   //for filling up the initial 4 frames
            {
                frames[i] = referenceString[i];
            }
            else
            {
                int max = -1;
                int optimalIndex;
                for(int j = 0; j < 4; j++)
                {
                    int f = 0;
                    for(int k = i + 1; k < n; k++)
                    {
                        if(referenceString[k] == frames[j])
                        {
                            f = 1;
                            if(k > max)
                            {
                                max = k;
                                optimalIndex = j;
                            }
                            break;
                        }
                    }
                    if(f == 0)
                    {
                        optimalIndex = j;
                        break;
                    }
                }
                frames[optimalIndex] = referenceString[i];
            }
            //print frames
            printf("Fault \n");
            for(int k = 0; k < 4; k++)
            {
                printf("%d \n", frames[k]);
            }
        }
    }
}

void lru()
{
    int referenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0 ,1};
    int frames[4] = {9999, 9999, 9999, 9999};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);
    int hits = 0;
    int faults = 0;
    for(int i = 0; i < n; i++)
    {
        int f = 0;
        for(int j = 0; j < 4; j++)
        {
            if(frames[j] == referenceString[i])
            {
                hits++;
                f = 1;
                //print frames;
                printf("Hit: %d \n", frames[j]);
                for(int k = 0; k < 4; k++)
                {
                    printf("%d \n", frames[k]);
                }
            }
        }
        if(f == 0)
        {
            int recentDistance[4];
            faults++;
            if(i < 4)   //for filling up the initial 4 frames
            {
                frames[i] = referenceString[i];
            }
            else
            {
                int min = 9999;
                int lruIndex;
                for(int j = 0; j < 4; j++)
                {
                    for(int k = i - 1; k >= 0; k--)
                    {
                        if(referenceString[k] == frames[j])
                        {
                            if(k < min)
                            {
                                min = k;
                                lruIndex = j;
                            }
                            break;
                        }
                    }
                }
                frames[lruIndex] = referenceString[i];
            }
            //print frames
            printf("Fault \n");
            for(int k = 0; k < 4; k++)
            {
                printf("%d \n", frames[k]);
            }
        }
    }
}

void fifo()
{
    int referenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 1, 2, 0};
    int frames[3] = {9999, 9999, 9999};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);
    int pointer = 0;
    int hits = 0;
    int faults = 0;
    for(int i = 0; i < n; i++)
    {
        int f = 0;
        for(int j = 0; j < 3; j++)
        {
            if(frames[j] == referenceString[i])
            {
                hits++;
                f = 1;
                //print frames;
                printf("Hit: %d \n", frames[j]);
                for(int k = 0; k < 3; k++)
                {
                    printf("%d \n", frames[k]);
                }
            }
        }
        if(f == 0)
        {
            faults++;
            frames[pointer] = referenceString[i];
            pointer = (pointer + 1) % 3;
            //print frames
            printf("Fault \n");
            for(int k = 0; k < 3; k++)
            {
                printf("%d \n", frames[k]);
            }
        }
    }
}

int main()
{
    //fifo();
    //lru();
    optimal();

    return 0;
}
