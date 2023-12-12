#include<stdio.h>
int fun(int a[],int start,int n,int val){
    for(int i=start;i<n;i++){
        if(a[i]==val)
            return i;
    }
    return -1;
}
int revs(int a[],int ind,int val){
    for(int i=ind;i>=0;i--){
        if(a[i]==val)
            return i;
    }
    return -1;
}
int main(){
    int n,ph=0,pm=0,f,count=0;
    printf("Enter size of string:");
    scanf("%d",&n);
    printf("Enter string:");
    int s[n];
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    printf("Enter the frame size:");
    scanf("%d",&f);
    int val,pf[f];
    for(int i=0;i<f;i++)
        pf[i]=-1;
    for(int i=0;i<n;i++){
        if(count<f){
            pm++;
            pf[count]=s[i];
            count++;
        }
        else{
            if(fun(pf,0,f,s[i])>-1)
                ph++;
            else{
                pm++;
                int mini=1e5,ind,save;
                for(int k=0;k<f;k++){
                    int ind=revs(s,i-1,pf[k]);
                    if(ind<mini){
                            mini=ind;
                            save=k;
                    }
                }
                pf[save]=s[i];
            }
        }
    }
    printf("Page hits:%d ",ph);
    printf("Page misses:%d",pm);
}
