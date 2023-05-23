#include<bits/stdc++.h>
using namespace std;
struct node{
        string vertex;
        int time;
        node* next;
};
class graph{
    public:
        int m[20][20],n,i,j;
        string v[20];
        char ch;
        node* head[20];
        node* temp=NULL;
        graph(){
            for(i=0;i<20;i++)
            {
                head[i]=NULL;
            }
        }
        void getgraph();
        void adjlist();
        void displaym();
        void displaya();
};
void graph::getgraph() {
    cout << "Enter number of cities: " << endl;
    cin >> n;
    cout << "Enter name of cities: " << endl;
    for (i = 0; i < n; i++) {
        cin >> v[i];
        for (j = 0; j < n; j++) {
            cout << "Does path exist between " << v[i] << " and " << v[j] << " (y/n): ";
            cin >> ch;
            if (ch == 'y') {
                cout << "Enter time required to reach " << v[j] << " from " << v[i] << " in minutes: ";
                cin >> m[i][j];
            } else if (ch == 'n') {
                m[i][j] = 0;
            } else {
                cout << "\nUnknown entry" << endl;
            }
        }
    }
    adjlist();
}

void graph::adjlist(){
    for(i=0;i<n;i++){
        node* p=new node;
        p->next=NULL;
        p->vertex=v[i];
        head[i]=p;
        cout<<"\n"<<head[i]->vertex;
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(m[i][j]!=0){
                node *p=new node;
                p->next=NULL;
                p->vertex=v[j];
                p->time=m[i][j];
                if(head[i]->next==NULL){
                    head[i]->next=p;
                }
                else{
                    temp = head[i];
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->next=p;
                }
            }
        }
    }
}
void graph::displaym(){
    cout<<"\n";
    for(i=0;i<n;i++){
        cout<<"\t"<<v[i];
    }

    for(i=0;i<n;i++){
        cout<<"\n";
        for(j=0;j<n;j++){
            cout<<"\t"<<m[i][j];
        }
        cout<<"\n";
    }
}
void graph::displaya(){
    cout<<"\nadjacency list is: ";
    for(i=0;i<n;i++){
        if(head[i]==NULL){
            cout<<"\nadjacency list not present.";
        }
        else{
            cout<<"\n"<<head[i]->vertex;
            temp=head[i]->next;
            while(temp!=NULL){
                cout<<"->"<<temp->vertex;
                temp=temp->next;
            }
        }
    }
    cout<<"\nPath and time required to reach the cities.";
    for(i=0;i<n;i++){
        if(head[i]==NULL){
            cout<<"\nadjacency list not present.";
        }
        else{
            temp=head[i]->next;
            while(temp!=NULL){
                cout<<"\n"<<head[i]->vertex;
                cout<<"->"<<temp->vertex<<"\n\t[time required: "<<temp->time<<" min";
                temp=temp->next;
            }
        }
    }
}
int main(){
    graph g;
    int m;
    do{
        cout<<"\n1.enter graph\n2.adjmatrix\n3.adjlist\n4.exit";
        cin>>m;
        switch(m){
            case 1:
                g.getgraph();
                break;
            case 2:
                g.displaym();
                break;
            case 3:
                g.adjlist();
                break;
        }
    }while(m<4);
    return 0;
}