#include<iostream>
using namespace std;
class graph{
    int a[20][20],l,u,w,i,j,v,e,visited[20];
    public: 
        void input();
        void display();
        void minimum();
};

void graph::input(){
    cout<<"Enter number of vertices: "<<endl;
    cin>>v;
    for(i=0;i<v;i++){
        
        visited[i]=0;
        for(j=0;j<v;j++){
            a[i][j]=999;
        }
    }
    cout<<"Enter number of connections: "<<endl;
    cin>>e;
    for(i=0;i<v;i++){
        cout<<"Enter the end vertices of connections: "<<endl;
        cin>>l>>u;
        cout<<"Enter the phone company charges for this connection."<<endl;
        cin>>w;
        a[l-1][u-1]=a[u-1][l-1]=w;
    }
}

void graph::display(){
    for(i=0;i<v;i++){
        cout<<endl;
        for(j=0;j<v;j++){
            cout<<a[i][j]<<"    ";
        }
        cout<<endl;
    }
}

void graph::minimum(){
    int total=0,p=0,q=0,min;
    visited[0]=1;
    for(int count=0;count<(v-1);count++){
        min=999;
        for(i=0;i<v;i++){
            if(visited[i]==1){
                for(j=0;j<v;j++){
                    if(visited[j]!=1){
                        if(min>a[i][j]){
                            min=a[i][j];
                            p=i;
                            q=j;
                        }
                    }
                }
            }
        }
        visited[p]=1;
        visited[q]=1;
        total=total+min ;
        cout<<"Minimum cost of connection is: "<<(p+1)<<" -> "<<(q+1)<<" with charge: "<<min<<endl;
    }
    cout<<"The minimum total cost of connections of all branches is: "<<total<<endl;
}

int main(){
    int ch;
    graph g;
    do{
        cout<<"PRIMS ALGORITHM"<<endl;
        cout<<"1.INPUT\n2.DISPLAY\n3.MINIMUM"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                g.input();
                break;
            case 2:
                g.display();
                break;
            case 3:
                g.minimum();
                break;
        }
    }while(ch<=3);
    return 0;
}