#include <iostream>
#include<string.h>
using namespace std;

struct node
{
    char key[20];
    char mean[20];
    node *left;
    node *right;
};
class Dict
{
    public:
    node *root;
    void create();
    void display(node *);
    void insert(node *, node *);
    int search(node *, char []);
    int update(node *,char []);
    node *del(node *,char []);
    node *min(node *);
};

void Dict::create()
{
    node *temp;
    int ch;
    do
    {
        temp=new node;
        cout<<"\n Enter the Keyword:";
        cin>>temp->key;
        cout<<"\n Enter the meaning : ";
        cin>>temp->mean;
        temp->left=NULL;
        temp->right=NULL;
        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            insert(root, temp);
        }
        cout<<"\n Do you want to Add more? (Press 1 for Yes and Press 0 for no):"<<endl;
        cin>>ch;
        
    }while(ch==1);
}

void Dict::insert(node *root, node *temp)
{
    if(strcmp(temp->key, root->key)<0)
    {
        if(root->left==NULL)
        {
            root->left=temp;
        }
        else
        {
            insert(root->left,temp);
        }
    }
    else
    {
        if(root->right==NULL)
        {
            root->right=temp;
        }
        else
        {
            insert(root->right,temp);
        }
    }
}

void Dict::display(node *root)
{
    if(root!=NULL)
    {
        display(root->left);
        cout<<"\n keyword is :"<<root->key;
        cout<<"\n Meaning is :"<<root->mean;
        display(root->right);
    }
}

int Dict::search(node *root, char k[])
{
    int c=0;
    while(root!=NULL)
    { 
        c++;
        if(strcmp(k,root->key)==0)
        {
            cout<<"\n no. of comparison : "<<c;
            return 1;
        }
        else
        {
            if(strcmp(k,root->key)<0)
                root=root->left;
            if(strcmp(k,root->key)>0) 
                root=root->right;
        }
    }
    return -1;
}

int Dict::update(node *root,char k[])
{
    
    while(root!=NULL)
    {
        if(strcmp(k,root->key)==0)
        {
            cout<<"\n Enter the new meaning of that keyword :";
            cin>>root->mean;
            return 1;
        }
        else
        {
            if(strcmp(k,root->key)<0)
                root=root->left;
            if(strcmp(k,root->key)>0)
                root=root->right;
        }
    }
    return -1;
}

node *Dict::del(node *root,char k[])
{
    node *temp;
    if(root==NULL)
    {
        cout<<"No keyword found";
        return root;
    }
    if(strcmp(k,root->key)<0)
    {
        root->left=del(root->left,k);
        return root;
    }
    if(strcmp(k,root->key)>0)
    {
        root->right=del(root->right,k);
        return root;
    }
    if(root->left==NULL && root->right==NULL)
    {
        temp=root;
        delete temp;
        return NULL;
    }
    if(root->right==NULL)
    {
        temp=root;
        root=root->left;
        delete temp;
        return root;
    }
    else if(root->left==NULL)
    {
        temp=root;
        root=root->right;
        delete temp;
        return root;
    }
    temp=min(root->right);
    strcpy(root->key,temp->key);
    root->right=del(root->right,temp->key);
    return root;
}

node * Dict::min(node *z)
{
    while(z->left!=NULL)
    {
        z=z->left;
    }
    return z;
}

int main()
{
    int ch;
    Dict ob;
    ob.root=NULL;
    char keyword[20];
    do
    {
        cout<<"\n Press 1. to Create a BST:";
        cout<<"\n Press 2. to display:";
        cout<<"\n Press 3. to search:";
        cout<<"\n Press 4. to update:";
        cout<<"\n Press 5. to delete a node:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                ob.create();
                break;
            case 2:
                if(ob.root==NULL)
                    cout<<"\n No keyword is present ";
                else
                    ob.display(ob.root);
                break;
            case 3:
                if(ob.root==NULL)
                    cout<<"\n Dictionary is not present ";
                else
                {
                    cout<<"\n Enter the keyword which you want to search";
                    cin>>keyword;
                    if(ob.search(ob.root,keyword)==1)
                        cout<<"\n Keyword is present";
                    else
                        cout<<"\nKeyword is not present";
                }
                break;
            case 4:
                if(ob.root==NULL)
                    cout<<"\n Dictionary is not present ";
                else
                {
                    cout<<"\n Enter the keyword whose meaning you want to change :";
                    cin>>keyword;
                    if(ob.update(ob.root,keyword)==1)
                        cout<<"\n Meaning has been updated";
                    else
                        cout<<"\n Meaning has not been updated";
                }
                break;
            case 5:
                if(ob.root==NULL)
                    cout<<"\n Dictionary is not present ";
                else
                {
                    cout<<"\n Enter the keyword which you want to delete:";
                    cin>>keyword;
                    if(ob.root==NULL)
                        cout<<"\n No keyword";
                    else
                    {
                        ob.root=ob.del(ob.root,keyword);
                    }
                }
            
        }
    }while(ch<=5);

    return 0;
}


