#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    node *temp,*next, *down,*t4;
    node *root=NULL;
    int flag;
    char ch[20];
    char name[20];
    node *create()
    {
        node *t = new node;
        t->flag=0;
        t->down=NULL;
        t->next=NULL;
        cin>>t->name;
        return t;
    }
    
    void insertB()
    {
        if(root==NULL)
        {
            cout<<"enter the name of the book: "<<endl;
            node *t1= create();
            root=t1;
        }
        else
        {
            cout<<"can not insert book"<<endl;
        }
    }
            
    void insertC()
    {
        if(root==NULL)
        {
                cout<<"Can not add chapters"<<endl;
        }
        else
        {
                int n;
                cout<<endl<<"Enter the number of chapters: "<<endl;
                cin>>n;
                for(int i=0;i<n;i++)
                {
                        cout<<"Enter the name of chapter "<<i+1<<" : ";
                        node *t2 = create();
                        if(root->down==NULL)
                        {
                                root->down=t2;
                                root->flag=1;
                        }
                        else
                        {
                                temp=root->down;
                                while(temp->next!=NULL)
                                {
                                        temp=temp->next;
                                }
                                temp->next=t2;
                        }
                }
        }
    }
    void insertS(){
        if(root==NULL){
            cout<<"Cannot add sections"<<endl;
        }
        else{
            int n;
            cout<<"Enter chapter name to which you want to add section."<<endl;
            cin>>ch;
            temp=root;
            if(temp->flag==0){
                cout<<"there are no chapters in the book"<<endl;

            }
            else{
                temp = temp->down;
                while(temp!=NULL){
                    if(!strcmp(ch,temp->name)){
                        cout<<"enter number of sections you want to add: "<<endl;
                        cin>>n;
                        for(int i=0;i<n;i++){
                            node* t3 = create();
                            if(temp->flag==0){
                                temp->down = t3;
                                temp->flag=1;
                                t4=temp->down;
                            }
                            else{
                                while(t4->next!=NULL){
                                    t4=t4->next;
                                }
                                t4->next = t3;
                            }
                        }
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
    }

    void display()
    {
        int i =0;
        if(root==NULL)
        {
                cout<<"there is no root node"<<endl;
        }
        else
        {
            temp = root;
            cout<<endl<<endl<<"name of the book: "<<endl;
            cout<<root->name<<endl<<endl;
            if(root->flag==0)
            {
                    cout<<"No chapters to display."<<endl;
            }
            else
            {
                cout<<"chapters: "<<endl;
                temp=temp->down;
                while(temp!=NULL)
                {
                    cout<<i+1<<") "<<temp->name<<endl;
                    t4 = temp;
                    if(t4->flag==1){
                        cout<<"sections of "<<i+1<<" chapter"<<endl;
                        t4=t4->down;
                        while(t4!=NULL){
                            cout<<t4->name<<endl;
                            t4=t4->next;
                        }
                    }
                    temp = temp->next;
                    i++;
                }
                temp=temp->down;
            }
        }
    }
    
};




int main()
{
        node ob;
        ob.insertB();
        ob.insertC();
        ob.insertS();
        cout<<endl;
        ob.display();
        return 0;
}
