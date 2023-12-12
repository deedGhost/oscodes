#include<stdio.h>
#include<math.h>
int main(){
    int n,s=0;
    printf("Enter no of requests:");
    scanf("%d",&n);
    int arr[n+1];
    printf("Enter position of head:");
    scanf("%d",&arr[0]);
    printf("Enter requests:\n");
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<n;i++)
        s+=abs(arr[i]-arr[i+1]);
    printf("Total seek time:%d\n",s);
    printf("Sequence:\n");
    for(int i=1;i<=n;i++)
        printf("%d ",arr[i]);
    return 0;
}
