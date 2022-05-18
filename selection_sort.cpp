int allIndexes(int input[], int n, int x, int output[])
{
    if (n == 0)
    {
        return -1;
    }
    int sA = allIndexes(int input[] + 1, int n - 1, int x, int output[]);
    int s = sizeof(output) / sizeof(int);
    for (int i = 0; i < s; i++)
    {
        output[i] = output[i] + 1;
    }

    if (input[0] == x)
    {
        if (sA == -1)
        {
            output[0] = 0;
        }
        else
        {
            for (int i = s; i > 0; i--)
            {
                output[i] = output[s - 1];
            }
            output[0] = 0;
        }
    }
}