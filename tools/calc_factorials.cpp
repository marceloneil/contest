//note: if n is really small, then it may be good to use a lookup table.
//note2: remember I don't have to calculate a factorial to determine how many zeros n! ends with. (remember 5*2 = 10) = 1 zero

unsigned int factorial(unsigned int n)
{
    if (n == 0)
       return 1;
    return n * factorial(n - 1);
}
