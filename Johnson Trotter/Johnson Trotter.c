#include <stdio.h>

int main()
{
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    int p[n], dir[n];

    for(int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        dir[i] = -1;
    }

    printf("Permutations:\n");

    while(1)
    {
        for(int i = 0; i < n; i++)
            printf("%d ", p[i]);
        printf("\n");

        int mobile = 0, mobileIndex = -1;

        for(int i = 0; i < n; i++)
        {
            int next = i + dir[i];

            if(next >= 0 && next < n && p[i] > p[next])
            {
                if(p[i] > mobile)
                {
                    mobile = p[i];
                    mobileIndex = i;
                }
            }
        }

        if(mobileIndex == -1)
            break;

        int swapIndex = mobileIndex + dir[mobileIndex];

        int temp = p[mobileIndex];
        p[mobileIndex] = p[swapIndex];
        p[swapIndex] = temp;

        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[swapIndex];
        dir[swapIndex] = temp;

        for(int i = 0; i < n; i++)
        {
            if(p[i] > mobile)
                dir[i] = -dir[i];
        }
    }

    return 0;
}
