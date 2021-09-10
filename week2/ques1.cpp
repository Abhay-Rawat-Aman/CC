//author: Abhay Rawat
//Week 2: Ques 1
#include<bits/stdc++.h>
using namespace std;
int first_occ(int arr[],int n,int key)
{
    int l=0,r=n-1,ans=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]==key)
        {
            ans=mid;
            r=mid-1;
        }
        else if(arr[mid]>key)
            r=mid-1;
        else
            l=mid+1;
    }
    return ans;
}
int last_occ(int arr[],int n,int key)
{
    int ans=-1;
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(key==arr[mid])
        {
            ans=mid;
            l=mid+1;
        }
        else if(arr[mid]>key)
            r=mid-1;
        else
            l=mid+1;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int key;
        cin>>key;
        int f=first_occ(arr,n,key);
        int l=last_occ(arr,n,key);
        if(f<0)   
            cout<<"Key not present"<<endl;
        else
            cout<<key<<"-"<<l-f+1<<endl;
    }
    return 0;
}