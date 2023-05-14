#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int getNextTrack(int currentHeadPosition, int trackNumbers[])
{
    int nearestTrackIndex;
    int min = abs(trackNumbers[0] - currentHeadPosition);
    for(int i = 0; i < 8; i++)
    {
        if(abs(trackNumbers[i] - currentHeadPosition) < min)
        {
            min = abs(trackNumbers[i] - currentHeadPosition);
            nearestTrackIndex = i;
        }
    }
    currentHeadPosition = trackNumbers[nearestTrackIndex];
    trackNumbers[nearestTrackIndex] = 100000;   //set the nearest track number to a very large value so that it cannot be arrived at again by the header
    return currentHeadPosition;
}

int main()
{
    int trackNumbers[8] = {176, 79, 34, 60, 92, 11, 41, 114};
    int currentHeadPosition = 50;   //initial position of the Header
    printf("The initial position of the R/W Header is %d", currentHeadPosition);
    printf("\n");

    for(int i = 0; i < 8; i++)
    {
        currentHeadPosition = getNextTrack(currentHeadPosition, trackNumbers);
        printf("The R/W Header is currently at track %d", currentHeadPosition);
        printf("\n");
    }

    return 0;
}
