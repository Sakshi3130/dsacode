#include<iostream>
#include<string.h>
using namespace std;

struct node{
    char k[20];
    char m[20];
    node* left;
    node* right;
};
class dict{
    public:
    node *root;
    void create();
    void display(node*);
    void insert(node* root,node* temp);
    int search(node*,char []);
    int update(node*,char []);
    node* del(node*,char[]);
    node* min(node*);
};

void dict::create(){
    node *p;
    int ch;
    do{
        p=new node;
        cout<<"Enter keyword and its meaning: "<<endl;
        cin>>p->k>>p->m;
        p->left=NULL;
        p->right=NULL;
        if(root==NULL){
            root=p;
        }
        else{
            insert(root,p);
        }
        cout<<"enter 1 if you want to continue(1/0): "<<endl;
        cin>>ch;
    }while(ch==1);
}

void dict::insert(node* root,node* temp){
    if(strcmp(temp->k,root->k)<0){
        if(root->left==NULL){
            root->left=temp;
        }
        else{
            insert(root->left,temp);
        }
    }
    else{
        if(root->right==NULL){
            root->right=temp;
        }
        else{
            insert(root->right,temp);
        }
    }
}

void dict::display(node* root){
    if(root!=NULL){
        display(root->left);
        cout<<root->k<<"  "<<root->m<<endl;
        display(root->right);
    }
}

int dict::search(node* root,char k[20]){
    int c=0;
    while(root!=NULL){
        c++;
        if(strcmp(k,root->k)==0){
            cout<<"No. of comparisons: "<<c;
            return 1;
        }
        else if(strcmp(k,root->k)<0){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return -1;
}
int dict::update(node* root,char k[20]){
    while(root!=NULL){
        if(strcmp(k,root->k)==0){
            cout<<"Enter new meaning of keyword: "<<endl;
            cin>>root->m;
            return 1;
        }
        else if(strcmp(k,root->k)<0){
            root=root->left;
        }
        else{
            root = root->right;
        }
    }
    return -1;
}

node* dict::del(node*root,char k[20]){
    node* temp;
    if(root==NULL){
        cout<<"keyword not found."<<endl;
        return root;
    }
    if(strcmp(k,root->k)<0){
        root->left=del(root->left,k);
        return root;
    }
    if(strcmp(k,root->k)>0){
        root->right=del(root->right,k);
        return root;
    }
    if(root->left==NULL && root->right==NULL){
        temp = root;
        delete temp;
        return NULL;
    }
    if(root->left==NULL){
        temp = root;
        root=root->right;
        delete temp;
        return root;
    }
    if(root->right==NULL){
        temp = root;
        root=root->left;
        delete temp;
        return root;
    }
    temp = min(root->right);
    strcpy(root->k,temp->k);
    root->right=del(root->right,temp->k);
    return root;

}
node * dict::min(node *q){
    while(q->left!=NULL){
        q=q->left;
    }
    return q;
}

int main(){
    dict d;
    d.root=NULL;
    int ch;
    do{
        cout<<"***MENU***/n1)create/n2)display/n3)search/n4)upadate/n5)delete/nenter your choice: "<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                d.create();
                
            case 2:
                if(d.root==NULL){
                    cout<<"Tree is empty"<<endl;
                }
                else{
                    d.display(d.root);
                }
                
            case 3:
                if(d.root==NULL){
                    cout<<"Tree is empty."<<endl;
                }
                else{
                    cout<<"Enter a keyword you want to search."<<endl;
                    char k[20];
                    cin>>k;
                    if(d.search(d.root,k)==1){
                        cout<<"Keyword found."<<endl;
                    }
                    else{
                        cout<<"Keyword not found."<<endl;
                    }
                }
            case 4:
                if(d.root==NULL){
                    cout<<"Tree is empty."<<endl;
                }
                else{
                    cout<<"Enter a keyword you want to update."<<endl;
                    char k[20];
                    cin>>k;
                    if(d.update(d.root,k)==1){
                        cout<<"meaning updated."<<endl;
                    }
                    else{
                        cout<<"meaning not updated."<<endl;
                    }
                }
            case 5:
                if(d.root==NULL){
                    cout<<"Tree is empty."<<endl;
                }
                else{
                    cout<<"Enter a keyword you want to delete."<<endl;
                    char k[20];
                    cin>>k;
                    if(d.root==NULL){
                        cout<<"can't delete the keyword"<<endl;
                    }
                    else{
                        d.root=d.del(d.root,k);
                    }
                }
        }
    }while(ch<6);
    return 0;
}