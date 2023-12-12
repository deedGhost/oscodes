#include<stdio.h>
int fun(int a[],int start,int n,int val){
    for(int i=start;i<n;i++){
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
                int maxi=-1,flag=0,save;
                for(int k=0;k<f;k++){
                    int ind=fun(s,i+1,n,pf[k]);
                    if(ind==-1){
                        pf[k]=s[i];
                        flag=1;
                        break;
                    }
                    if(maxi<ind){
                            maxi=ind;
                            save=k;
                    }
                }
                if(flag==0)
                    pf[save]=s[i];
            }
        }
    }
    printf("Page hits:%d ",ph);
    printf("Page misses:%d",pm);
}
