void iterate(int *a, int i, int size, int n)
{
    for(a[i] = 0; a[i] < size; a[i]++)
    {
        if(i == n-1)
            DoStuff(a, n);  // a is the array of indices of size n
        else
            iterate(a, i+1, size, n);
    }
}

// Equivalent to 4 nested for loops
int a[4];
iterate(a, 0, size, 4);
