#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Operations_Counter(int n, int arr[n]){
    int count = 1, pairs = 0;

/*Initial Counting of pairs before performing operations*/
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i]>arr[j])
            {
                pairs++;
            }
        }
    }
    /*Performing operations on array*/

    while (count<=n)
    {
        int temp_pairs = 0;
        bool flipped_0 = true; //this is to check whether we flipped 0->1 or 1->0.

        /* Flipping (count-1)th of the array */
        if (arr[count-1]==1)
        {
            arr[count-1]=0;
            flipped_0=false;
        }
        else{
            arr[count-1]=1;
        }
/* Counting the possible pairs that can be formed. */
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (arr[i]>arr[j])
                {
                    temp_pairs++;
                }
            }
        }

/*Comparing the pairs formed by flipping with max number of available pairs*/
        if (temp_pairs>pairs)
        {
            pairs = temp_pairs;
        }

/*Reversing the change that was made to check possibility of max pairs*/
        if (flipped_0==true)
        {
            arr[count-1]=0;
        }
        else{
            arr[count-1]=1;
        }
/*Increasing count value*/
        count++;
    }
    return pairs;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int max_pairs = Operations_Counter(n, arr);
    printf("%d", max_pairs);
    return 0;
}