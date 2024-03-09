#include <iostream>

void backtrackNto1(int n,int i)
{
    
    if (i < n)
    {

        backtrackNto1(n,++i);
        printf("%d ", i);
    }

    return;
}

int main(int argc, char const *argv[])
{
  backtrackNto1(10,0);
    return 0;
}
