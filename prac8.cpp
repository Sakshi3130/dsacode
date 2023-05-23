#include<iostream>
using namespace std;
class Obst{
    public:
    int a[10],r[10][10],n;
    float p[10], q[20], w[10][10],c[10][10];
    void accept();
    void cons_obst();
    int knuthmin(int , int);
    void tree(int,int);
};

void Obst::accept(){
    cout<<"how many elements you want to add?"<<endl;
    cin>>n;
    cout<<"Enter "<<n<<" elements"<<endl;
    for(int i =1;i<=n;i++)
        cin>>a[i];
    cout<<"Enter "<<n<<" probabilities"<<endl;
    for(int i =1;i<=n;i++)
        cin>>p[i];
    cout<<"Enter "<<n+1<<" failure probabilities"<<endl;
    for(int i=0;i<=n;i++)
        cin>>q[i];
}
void Obst::cons_obst(){
    int j,k;
    for(int i=0;i<n;i++){
        w[i][i]=q[i];
        c[i][i]=r[i][i]=0;
        w[i][i+1]=q[i]+q[i+1]+p[i+1];
        r[i][i+1]=i+1;
        c[i][i+1]=w[i][i+1];
    }
    w[n][n]=q[n];
    r[n][n]=c[n][n]=0;
    for(int m=2;m<=n;m++){
        for(int i=0;i<=n-m;i++){
            j=i+m;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            k=knuthmin(i,j);
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
            r[i][j]=k;
        }
    }
    cout<<"Root node: "<<a[r[0][n]]<<"  ";
    cout<<"\nLeft child of "<<a[r[0][n]]<<" is ";
    tree(0,r[0][n]-1);
    cout<<"\nRight child of "<<a[r[0][n]]<<" is ";
    tree(r[0][n],n);
}
int Obst::knuthmin(int i,int j){
    int min=999,k,z;
    for(k=r[i][j-1];k<=r[i+1][j];k++){
        if(min>c[i][k-1]+c[k][j]){
            min=c[i][k-1]+c[k][j];
            z=k;
        }
    }
    return z;
}
void Obst::tree(int i,int j){
    if(r[i][j]==0){
        cout<<"NULL"<<endl;
        return;
    }
    cout<<" :: "<<a[r[i][j]];
    cout<<"\nleft child of "<<a[r[i][j]];
    tree(i,r[i][j]-1);
    cout<<"\nRight child of "<<a[r[i][j]];
    tree(r[i][j],j);
}
int main(){
    Obst o;
    o.accept();
    o.cons_obst();
    return 0;
}