#include <cstdio>

int A = 1;
char C;

int main()
{
    while(~(C = getchar()))
        if(C == ' ') A++;
    printf("%d", A);
    return 0;
}

/*
mathan's in c

main(int A, char** C) {
    while(~(*(*C) = getchar()))
        if(*(*C) == ' ') A++;
    printf("%d", A);
}


*/
