#include <iostream>
#include <stdlib.h>

using namespace std;
long n,m,k;
struct dscanh{
    long first;
    long last;
};
dscanh *g1;
long *head, *numElement;
long **Ke;
long *request;
int main()
{
    long i=0,pos = 0;
    cin>>n>>m>>k;
    //cap phat danh sach canh (cung)
    g1 = new dscanh[m];//g1 = (dscanh *)malloc(m*sizeof(long));
    head = new long[n+1];//head = (int *)malloc((n+1)*sizeof(int));
    numElement = new long[n+1];//numElement = (int *)calloc(n+1,sizeof(int));
    for(i = 0; i < n+1; i++)
        numElement[i] = 0;
    Ke = new long* [n+1];//Ke = (int **)malloc((n+1)*sizeof(int));
    request = new long[k];//request = (int *)malloc(k*sizeof(int));
    head[1] = 1;

    //end of cap phat
    for(i = 0; i < m; i++)
    {
        cin>>g1[i].first>>g1[i].last;
    }
    for(i =0; i<k; i ++)
        cin>>request[i];
    for(i = 1; i <= n;i++)
    {
        for(long j = 0 ; j < m ; j++)
        {
            if(g1[j].first == i)
                numElement[i]++;
        }
    }
    for(i = 1; i <=n; i++)
    {
        Ke[i] = new long[numElement[i]];//Ke[i] = (int *)malloc(numElement[i]*sizeof(int));
        long t = 0;
        for(long j=0; j< m; j++)
        {
            if(g1[j].first == i)
                Ke[i][t++] = g1[j].last;
        }
        if(i != 1)
            head[i] = head[i-1]+numElement[i-1];
    }
    //In ket qua
    cout<<n<<" "<<m<<endl;
    for(i = 1;i<=n; i++)
    {
       cout<<head[i]<<" ";
    }
    cout<<endl;
    for(i = 1; i<=n; i++)
    {
        for(long j = 0; j< numElement[i];j++)
            cout<<Ke[i][j]<<" ";
    }
    cout<<endl;
    for(i = 0; i<k; i++)
    {
        for(long j = 1; j<= n; j++)
        {
            for(long t =0; t<numElement[j];t++)
                if(request[i] == Ke[j][t])
                {
                    cout<<j<<" ";
                    break;
                }

        }
        cout<<endl;
    }
    //giai phong
    delete[] g1;
    delete[] head;
    for(i = 0; i<= n; i++)
        delete[] Ke[i];
    delete [] Ke;
    delete [] request;
    delete [] numElement;
    return 0;
}
