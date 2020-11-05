#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <tuple>

int main()
{

    //FILE *fp;

    long long int N;

    //fp = fopen("/home/vanias/poleodomia/input20.txt", "r");
    /*
    while(1)
    {
        c = fgetc(fp);
        if (feof(fp))
        {
            break;
        }
        printf("%c",c);
    }
    */

    //fscanf(fp, "%lld", &N);

    scanf("%lld", &N);

    //printf("%lld\n",N);

    long long int *input, *rev_input, *right_sums, *left_sums;

    input = (long long int *) malloc(N * sizeof(long long int));
    rev_input = (long long int *)malloc(N * sizeof(long long int));
    right_sums = (long long int *)malloc(N * sizeof(long long int));
    left_sums = (long long int *)malloc(N * sizeof(long long int));

    long int i;

    /*
    for(i=0; i<N; i++)
    {
        fscanf(fp, "%lld", &input[i]);
        rev_input[N-1-i] = input[i];
    }
    */

    for(i=0; i<N; i++)
    {
        scanf("%lld", &input[i]);
        rev_input[N-1-i] = input[i];
    }

    std::stack<std::pair<long long int,long long int>> maximals;
    maximals.push(std::make_pair(input[0],1));
    right_sums[0] = input[0];

    for(i=1; i<N; i++)
    {
        if(input[i] < maximals.top().first)
        {
            maximals.push(std::make_pair(input[i],i+1));
            right_sums[i] = right_sums[i-1] + input[i];
        }

        else
        {
            while(!maximals.empty())
            {
                if(input[i] >= maximals.top().first)
                {
                    maximals.pop();
                }

                else
                {
                    right_sums[i] = input[i]*((i+1) - maximals.top().second) + right_sums[(maximals.top().second) - 1]; //maximals.top().first * maximals.top().second;
                    maximals.push(std::make_pair(input[i],i+1));
                    break;
                }

                if(maximals.empty())
                {
                    maximals.push(std::make_pair(input[i],i+1));
                    right_sums[i] = maximals.top().first * maximals.top().second;
                    break;
                }
            }
        }
    }

    while(!maximals.empty())
    {
        maximals.pop();
    }

    maximals.push(std::make_pair(rev_input[0],1));
    left_sums[0] = rev_input[0];

    for(i=1; i<N; i++)
    {
        if(rev_input[i] < maximals.top().first)
        {
            maximals.push(std::make_pair(rev_input[i],i+1));
            left_sums[i] = left_sums[i-1] + rev_input[i];
        }

        else
        {
            while(!maximals.empty())
            {
                if(rev_input[i] >= maximals.top().first)
                {
                    maximals.pop();
                }

                else
                {
                    left_sums[i] = rev_input[i]*((i+1) - maximals.top().second) + left_sums[(maximals.top().second) - 1]; //maximals.top().first * maximals.top().second;
                    maximals.push(std::make_pair(rev_input[i],i+1));
                    break;
                }

                if(maximals.empty())
                {
                    maximals.push(std::make_pair(rev_input[i],i+1));
                    left_sums[i] = maximals.top().first * maximals.top().second;
                    break;
                }
            }
        }
    }

    long long int min;

    min = right_sums[0] + left_sums[N-1] - input[0];

    for(i=1; i<N; i++)
    {
        if(min > right_sums[i] + left_sums[N-1-i] - input[i])
            min = right_sums[i] + left_sums[N-1-i] - input[i];
    }

    printf("%lld\n", min);

    /*
    for(i=0; i<N; i++)
    {
        printf("%lld ", input[i]);
    }

    printf("\n");


    for(i=0; i<N; i++)
    {
        printf("%lld ", rev_input[i]);
        }

    printf("\n");

    for(i=0; i<N; i++)
    {
        printf("%lld ", right_sums[i]);
    }

    printf("\n");

    for(i=0; i<N; i++)
    {
        printf("%lld ", left_sums[i]);
    }

    printf("\n");
    */

    //fclose(fp);

    return 0;
}
