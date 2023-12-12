#include<stdio.h>
#include<math.h>
#define size 200
void sort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
}
int main(){
    int n,c,pos,s=0,ind;
    printf("Enter the no of requests:");
    scanf("%d",&n);
    int arr[n+1];
    printf("Enter the head position:");
    scanf("%d",&pos);
    arr[0]=pos;
    printf("Enter the requests:\n");
    for(int i=1;i<n+1;i++)
        scanf("%d",&arr[i]);
    sort(arr,n+1);
    for(int i=0;i<n+1;i++){
        if(arr[i]==pos)
            ind=i;
    }
    printf("Enter the direction 0-larger 1-smaller");
    scanf("%d",&c);
    if(c==0)
        s+=abs(pos-arr[n])+abs(arr[0]-arr[n])+abs(arr[0]-arr[ind-1]);
    else if(c==1)
        s+=abs(pos-arr[0])+abs(arr[n]-arr[0])+abs(arr[n]-arr[ind+1]);
    printf("Total seek time:%d",s);
    return 0;
}
