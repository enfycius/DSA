#include <bits/stdc++.h>

using namespace std;

const int N = 11;

class DF
{
public:
    DF()
    {
        d = new int[N+2];
    }

    int fibonacci()
    {
        d[0] = 0;
        d[1] = 1;

        for(int i=2; i<=N; i++)
        {
            d[i] = d[i-1] + d[i-2];
        }

        return d[N];
    }

    ~DF()
    {
        delete d;
    }

private:
    int *d;
};

int main(void)
{
    DF df;

    cout << df.fibonacci();

    return 0;
}