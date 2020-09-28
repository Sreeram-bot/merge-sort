#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void merge(int a[],int n,int lo,int hi)     //Each element is compared here and put where it belongs with help of p1,p2 and a while loop 
{
    int temp[hi-lo+1];
    int mid=lo+(hi-lo)/2;
    int k=0,p1=lo,p2=mid+1;
    while(p1<=mid && p2<=hi)
    {
        if(a[p1]<a[p2])
            temp[k++]=a[p1++];
        else
            temp[k++]=a[p2++];
    }
    while(p1<=mid)
        temp[k++]=a[p1++];
    while(p2<=hi)
        temp[k++]=a[p2++];
    for(int i=lo;i<=hi;i++)
    {
        a[i]=temp[i-lo];
    }
    
}
void ms(int a[],int n,int lo,int hi)
{
    if(lo==hi)
        return;
    int mid=lo+(hi-lo)/2;   //Efficient to find mid (acc to my instructor)
    ms(a,n,lo,mid);     //first half of elements that's split is further asked to split 
    ms(a,n,mid+1,hi);       //second half of elements that's split is further asked to split ... this thing's done until we have solo elements by themselves everywhere 
    merge(a,n,lo,hi);       //one by one they are now compred and swapped in this function call
}
int main()
{
    int n,lo=0,hi;
    printf("Enter the number of elements\n");       //Had to do this cuz its c (Handling dynamic memory allocation is a headache unlike python)
    scanf("%d",&n);
    int a[n];
    hi=n-1;
    for(int j=0;j<n;j++)
        scanf("%d",&a[j]);
    ms(a,n,lo,hi);      //A recursive function to split elements first and then merge later
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
