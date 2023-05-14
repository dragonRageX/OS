#include <stdio.h>
#include <stdlib.h>

int getMinTrackNumber(int trackNumbers[])
{
    int min = 199;   // = lastTrackNumber
    for(int i = 0; i < 8; i++)
    {
        if(trackNumbers[i] < min)
        {
            min = trackNumbers[i];
        }
    }
    //printf("min %d\n", min);
    return min;
}

int getMaxTrackNumber(int trackNumbers[])
{
    int max = 0;   // = firstTrackNumber
    for(int i = 0; i < 8; i++)
    {
        if(trackNumbers[i] > max  && trackNumbers[i] < 199)
        {
            max = trackNumbers[i];
        }
    }
    //printf("max %d\n", max);
    return max;
}

int getDirection(int previousDirection, int currentHeadPosition, int trackNumbers[], int firstTrackNumber, int lastTrackNumber)
{
    int duplicateTrackNumbers[8] = {176, 79, 34, 60, 92, 11, 41, 114};

    if(currentHeadPosition == getMinTrackNumber(duplicateTrackNumbers))
    {
        printf("The R/W Header is currently at track 0");
        printf("\n");
        return 1;
    }
    else if(currentHeadPosition == getMaxTrackNumber(duplicateTrackNumbers))   //change the get
    {
        printf("The R/W Header is currently at track 199");
        printf("\n");
        return -1;
    }
    else if(previousDirection == -1 && currentHeadPosition != getMinTrackNumber(duplicateTrackNumbers))
    {
        return -1;
    }
    else if(previousDirection == 1 && currentHeadPosition != getMaxTrackNumber(duplicateTrackNumbers))
    {
        return 1;
    }
}

int getNextLeftTrack(int currentHeadPosition, int trackNumbers[], int firstTrackNumber)
{
    int maxTrackNumber = 0;
    int maxTrackIndex;
    for(int i = 0; i < 8; i++)
    {
        if(trackNumbers[i] > firstTrackNumber && trackNumbers[i] < currentHeadPosition)
        {
            if(trackNumbers[i] > maxTrackNumber)
            {
                maxTrackNumber = trackNumbers[i];
                maxTrackIndex = i;
            }
        }
    }
    trackNumbers[maxTrackIndex] = 100000;
    return maxTrackNumber;
}

int getNextRightTrack(int currentHeadPosition, int trackNumbers[], int lastTrackNumber)
{
    int minTrackNumber = 199;
    int minTrackIndex;
    for(int i = 0; i < 8; i++)
    {
        if(trackNumbers[i] > currentHeadPosition && trackNumbers[i] < lastTrackNumber)
        {
            if(trackNumbers[i] < minTrackNumber)
            {
                minTrackNumber = trackNumbers[i];
                minTrackIndex = i;
            }
        }
    }
    trackNumbers[minTrackIndex] = 100000;
    return minTrackNumber;
}

int main()
{
    int trackNumbers[8] = {176, 79, 34, 60, 92, 11, 41, 114};
    int currentHeadPosition = 50;
    printf("The R/W Header is currently at track 50");
    printf("\n");
    int firstTrackNumber = 0;
    int lastTrackNumber = 199;

    int direction = -1;   //we set DOWN as the initial direction of the scan.

    for(int i = 0; i < 8; i++)
    {
        if(direction == -1)   //downward SCAN
        {
            currentHeadPosition = getNextLeftTrack(currentHeadPosition, trackNumbers, firstTrackNumber);
            printf("The R/W Header is currently at track %d", currentHeadPosition);
            printf("\n");
            direction = getDirection(direction, currentHeadPosition, trackNumbers, firstTrackNumber, lastTrackNumber);
        }
        else if(direction == 1)   //upward SCAN
        {
            currentHeadPosition = getNextRightTrack(currentHeadPosition, trackNumbers, lastTrackNumber);
            printf("The R/W Header is currently at track %d", currentHeadPosition);
            printf("\n");
            direction = getDirection(direction, currentHeadPosition, trackNumbers, firstTrackNumber, lastTrackNumber);
        }
    }

    return 0;
}
