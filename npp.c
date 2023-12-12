#include<stdio.h>
typedef struct npp{
    int pid,at,bt,ct,tat,wt,rt,p,comp;
}npp;
int fun(npp p[],int n,int curr){
    int ind=-1,maxp=1e9,arr=1e9;
    for(int i=0;i<n;i++){
        if(p[i].p<=maxp && p[i].comp==0 && p[i].at<=curr){
            if(p[i].p==maxp && p[i].at>=arr)
                continue;
            ind=i;
            maxp=p[i].p;
            arr=p[i].at;
        }
    }
    return ind;
}
int main(){
    int n;
    printf("Enter no of processes:");
    scanf("%d",&n);
    npp p[n];
    printf("Enter the Priority,AT & BT of processes:\n");
    for(int i=0;i<n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        p[i].pid=i+1;
        p[i].at=b;
        p[i].bt=c;
        p[i].p=a;
        p[i].comp=0;
        p[i].rt=-1;
    }
    int curr=0,t=0,idle=0;
    float avgtat=0,avgwt=0,avgrt=0;
    curr+=p[0].bt;
    p[0].rt=p[0].at;
    p[0].ct=curr;
    p[0].tat=p[0].ct-p[0].at;
    p[0].wt=p[0].tat-p[0].bt;
    p[0].comp=1;
    t++;
    while(t<n){
        int ind=fun(p,n,curr);
        if(ind==-1){
            curr++;
            idle++;
            continue;
        }
        if(p[ind].rt==-1)
            p[ind].rt-=p[ind].at;
        curr+=p[ind].bt;
        p[ind].comp=1;
        p[ind].ct=curr;
        p[ind].tat=p[ind].ct-p[ind].at;
        p[ind].wt=p[ind].tat-p[ind].bt;
        t++;
    }
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++){
        avgtat+=p[i].tat;
        avgwt+=p[i].wt;
        avgrt+=p[i].rt;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }
    printf("Average WT=%0.2f\n",avgwt/n);
    printf("Average RT=%0.2f\n",avgrt/n);
    printf("Average TAT=%0.2f\n",avgtat/n);
}
