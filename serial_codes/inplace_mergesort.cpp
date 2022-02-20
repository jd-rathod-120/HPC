#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll flop;
void merge(vector<ll> &a,ll l,ll mid,ll r)
{
    ll i=l,j=mid+1,k=i;
    ll mx=max(a[mid],a[r])+1;
    flop++;
    while(i<=mid && j<=r && k<=r)
    {
        ll element1=a[i]%mx;
        ll element2=a[j]%mx;
        flop+=2;
        if(element1<=element2)
        {
            a[k]+=element1*mx;
            i++;
        }
        else
        {
            a[k]+=element2*mx;
            j++;
        }
        k++;
        flop+=2;
    }

    while(i<=mid)
    {
        ll element=a[i]%mx;
        a[k]+=element*mx;
        i++;
        k++;
        flop+=3;
    }

    while(j<=r)
    {
        ll element=a[j]%mx;
        a[k]+=element*mx;
        j++;
        k++;
        flop+=3;
    }

    for(ll i=l;i<=r;i++)
    {
        a[i]/=mx;
        flop++;
    }
}

void mergesort(vector<ll>&a,ll l,ll r)
{
    if(l<r)
    {
        ll mid = (l+r)>>1;
        flop+=2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

void solve()
{   
    ll n;
    clock_t start, end;
    double walltime;
    for(ll i=2;i<=300000000;i*=2)
    {
        flop=0;
        vector<ll> a(i);
        for(ll j=0;j<i;j++)
        {
            a[j]=rand();
            //cout<<a[j]<<endl;
        }
        
        start=clock();
        mergesort(a,0,i-1);
        end=clock();
        walltime = (end - start)/((double)CLOCKS_PER_SEC);
        double throughput = (8.0 * flop)/walltime;
        //cout<<throughput<<endl;
        double memory= (8.0 * i)/walltime;
        
        printf("%ld, %lf, %lf, %lf\n",i,walltime,throughput,memory);
        
        
    }
        /*for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<endl;*/
}

int main()
{
 	int t=1;
    //cin>>t;
 	while(t--)
 	{
 		solve();
 	}
}
