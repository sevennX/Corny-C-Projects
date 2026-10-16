

int sum(int *arr, int size)
{
    int i, sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}