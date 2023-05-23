#include<iostream>
using namespace std;

class node
{
    public:
    node *temp,*next, *down;
    node *root=NULL;
    int flag;
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

    void display()
    {
        int i =0;
        if(root==NULL)
        {
                cout<<"there is no root node"<<endl;
        }
        else
        {
            
            cout<<endl<<endl<<"name of the book: "<<endl;
            cout<<root->name<<endl<<endl;
            if(root->down==NULL)
            {
                    cout<<"No chapters to display."<<endl;
            }
            else
            {
                
                
                cout<<"chapters: "<<endl;
                temp=root->down;
                while(temp!=NULL)
                {
                    cout<<i+1<<") "<<temp->name<<"   ";
                    temp=temp->next;
                    i++;
                }
                
            }
        }
    }
    
};




int main()
{
        node ob;
        ob.insertB();
        ob.insertC();
        cout<<endl;
        ob.display();
        return 0;
}
