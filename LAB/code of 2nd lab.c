#include<isotream>
using namespace std;
int main(){

cout<<"Enter number of processes: ";
cin >> n;
int p[n],p[a];
}

count<<"Enter process sequence:"
for(i=0;i<n,i++){
    cin>> a[i];
}
cout<<"Enter Burst time:";
for (i=0;i<n;i++){
    cin>>b[i];
}

for (i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if(b[i]>b[j])
    }

    temp=p[i];
    p[i]=p[j];
    p[j]=temp;

    temp=a[i];
    a[i]=a[j];
    a[j]=temp;

    temp=b[i];
    b[i]=b[j];
    b[j]=temp;
}
}
}
}
min =a[0];
for(i=0;i<n;i++){
    if (min >a[i]){
        min=a[i];
        d=i;
    }
}

tt=min;
c[d]=tt+b[d];
tt=c[d];
for(i=0;i<n;i++){
    if (a[i]!=min){
        c[i]=b[i]+tt;
        tt=c[i];
        }
}
cout<<"Process\t\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n";
for(i=0;i<n;i++){
    tat[i]=c[i]-a[i];
    t_wt=t_wt+wt[i];
    cout << "P"
}
