//response time ???????
#include<stdio.h>
typedef struct srtf{
    int pid,at,bt,ct,tat,wt,rt,rem,comp;
}srtf;
int fun(srtf p[],int n,int curr){
    int ind=-1;
    int mint=1e9;
    for(int i=0;i<n;++i){
        if(p[i].rem<mint && p[i].comp==0 && p[i].at<=curr){
            ind=i;
            mint=p[i].rem;
        }
    }
    return ind;
}
int main(){
    int n;
    printf("Enter no of processes:");
    scanf("%d",&n);
    srtf p[n];
    printf("Enter the AT & BT of processes:\n");
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        p[i].pid=i+1;
        p[i].at=a;
        p[i].bt=b;
        p[i].comp=0;
        p[i].rt=-1;
        p[i].rem=p[i].bt;
    }
    int t=0,curr=0,idle=0;
    float avgwt=0,avgrt=0,avgtat=0;
    while(t<n){
        int ind=fun(p,n,curr);
        if(ind==-1){
            curr++;
            idle++;
            continue;
        }
        if(p[ind].rt==-1)
            p[ind].rt=curr;
        p[ind].rem--;
        curr++;
        if(p[ind].rem==0){
            p[ind].comp=1;
            p[ind].ct=curr;
            p[ind].tat=p[ind].ct-p[ind].at;
            p[ind].wt=p[ind].tat-p[ind].bt;
            p[ind].rt=p[ind].rt-p[ind].at;
            t++;
        }
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
