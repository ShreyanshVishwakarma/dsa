#include <iostream>
using namespace std;
void sumbypara(int n, int sum)
{
    if (n < 1)
    {
       cout<<sum;
        return;
    }

    sumbypara(n - 1, sum + n);
}

int sumbyreturn(int n){
    if (n==0)
    {
        return 0;
    }
    return n+sumbyreturn(n-1);
}


int main(int argc, char const *argv[])
{
    sumbypara(4,0);
    cout<<endl<<sumbyreturn(4);
    return 0;
}
