#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll flop;
//merge sort function 
void merge(vector<long long int> & arr,long long int left,long long int mid,long long int right){
    //creating dummy array to store the results
	vector<long long int> dummy;
	long long int i=left,j=mid+1,k=left;
	
	while(i<=mid && j<=right){
	    //if left part has small element
		if(arr[i]<arr[j]){
			dummy.push_back(arr[i]);
			i++;
		}//if right part has small element 
		else{
			dummy.push_back(arr[j]);
			j++;
		}
		k++;
		//flop+=2;
	}
	//if still elements are pending in left part 
	while(i<=mid){
		dummy.push_back(arr[i]);
		i++;
		k++;
		//flop+=2;
	}
	//if still elements are pending in right part
	while(j<=right){
		dummy.push_back(arr[j]);
		j++;
		k++;
		//flop+=2;
	}
	//again assigning the dummy array to array 
	for(k=0;k<dummy.size();k++){
		arr[k+left]=dummy[k];
	}
}
  
void mergesort(vector<long long int>& arr,long long int left,long long int right){
   //if array has atleast two elements
   if(left<right){
		long long int mid = left + (right-left)/2;
		//deviding array into two parts
		//recusrsively calling mergesort function for left part 
		mergesort(arr,left,mid);
		//recusrsively calling mergesort function for right part 
		mergesort(arr,mid+1,right);
		//calling merge function to merge two sorted parts of array
		merge(arr,left,mid,right);
		flop+=3;		
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
	
	return 0;
}
