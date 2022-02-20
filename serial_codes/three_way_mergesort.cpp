#include <bits/stdc++.h>
#define ll long long int

using namespace std;
ll flop;

void merge(vector<ll>& arr,ll low,ll mid1,ll mid2,ll high)
{
    ll ptr1=low,ptr2=mid1+1,ptr3=mid2+1;
    vector<ll> temp;

    while((ptr1<=mid1) && (ptr2<=mid2) && (ptr3<=high))
    {
        if(arr[ptr1]<=arr[ptr2] && arr[ptr1]<=arr[ptr3])
        {
            temp.push_back(arr[ptr1]);
            ptr1++;
        }
        else if(arr[ptr2]<=arr[ptr1] && arr[ptr2]<=arr[ptr3])
        {
            temp.push_back(arr[ptr2]);
            ptr2++;
        }
        else
        {
            temp.push_back(arr[ptr3]);
            ptr3++;
        }
        //flop++;
    }

    while(ptr1<=mid1 && ptr2<=mid2)
    {
        if(arr[ptr1]<=arr[ptr2])
        {
            temp.push_back(arr[ptr1]);
            ptr1++;
        }
        else
        {
            temp.push_back(arr[ptr2]);
            ptr2++;
        }
        //flop++;
    }

    while(ptr1<=mid1 && ptr3<=high)
    {
        if(arr[ptr1]<=arr[ptr3])
        {
            temp.push_back(arr[ptr1]);
            ptr1++;
        }
        else
        {
            temp.push_back(arr[ptr3]);
            ptr3++;
        }
        //flop++;
    }

    while(ptr3<=high && ptr2<=mid2)
    {
        if(arr[ptr3]<=arr[ptr2])
        {
            temp.push_back(arr[ptr3]);
            ptr3++;
        }
        else
        {
            temp.push_back(arr[ptr2]);
            ptr2++;
        }
        //flop++;
    }

    while(ptr1<=mid1)
    {
        temp.push_back(arr[ptr1]);
        ptr1++;
        //flop++;
    }

    while(ptr2<=mid2)
    {
        temp.push_back(arr[ptr2]);
        ptr2++;
        //flop++;
    }

    while(ptr3<=high)
    {
        temp.push_back(arr[ptr3]);
        ptr3++;
        //flop++;
    }

    for(int i=0;i<temp.size();i++)
    {
        arr[i+low]=temp[i];
        //flop++;
    }
    
}

void mergesort(vector<ll>& arr,ll low,ll high)
{
    if(high-low>=1)
    {
        int mid1=low+(high-low)/3;
        int mid2=low+(2*((high-low)/3))+1;
        mergesort(arr,low,mid1);
        mergesort(arr,mid1+1,mid2);
        mergesort(arr,mid2+1,high);
        merge(arr,low,mid1,mid2,high);
        flop+=8;
    }

}

int main()
{
    clock_t start,end;
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
    
}
