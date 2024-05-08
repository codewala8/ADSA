#include<iostream>
#include<stdio.h>
#include<string.h> 
using namespace std;
class Tree
{
    typedef struct node
    { 
        char key[10]; 
        char meaning[10]; 
        struct node *left; 
        struct node *right;
    } 
    btree; 
    public: 
    btree *New,*root;
    Tree(); void 
    create();
    void insert(btree *root,btree *New);
    void inorder();
    void inorder_rec(btree *root);
    void postorder();
    void postorder_rec(btree *root);
};
Tree::Tree()
{
    root=NULL;
}
void Tree::inorder()
{
    inorder_rec(root);
}
void Tree::inorder_rec(btree*root)
{
    if(root!=NULL)
    {
        inorder_rec(root->left);
        cout<<"\n\t"<<root->key<<"\t"<<root->meaning;
        inorder_rec(root->right);
    }
}
void Tree::postorder()
{
    postorder_rec(root);
}
void Tree::postorder_rec(btree *root)
{ 
    if(root!=NULL)
    {
       postorder_rec(root->right); cout<<"\n\t"<<root->key<<"\t"<<root->meaning;
       postorder_rec(root->left);
    }
}
void Tree::create()
{
    New=new btree;
    New->left=New->right=NULL; 
    cout<<"\n\tenter the keyword:";
    cin>>New->key;
    cout<<"n\tenter the meaning of"<<New->key<<":";
    cin>>New->meaning; 
    if(root==NULL)
    { 
        root=New;
    } 
    else 
    {
        insert(root,New);
    }
}
void Tree::insert(btree *root,btree *New)
{
    if(strcmp(root->key,New->key)>0)
    { 
        if(root->left==NULL) root->left=New; 
        else
        insert(root->left,New);
    } 
    else 
    {
    if(root->right==NULL) 
    root->right=New; else
    insert(root->right,New);
    }
} 
main()
{
Tree tr; 
int ch; 
char ans; 
do 
{
    cout<<"\n\t********** BST operations ***********"; 
    cout<<"\n\t1. create\n\t2. display\n\t3. exit"; 
    cout<<"\n\t......enter your choice:";
    cin>>ch; 
    switch(ch) 
    { 
        case 1:
        do 
        { 
            tr.create();
            cout<<"......do you want to continue:";
            cin>>ans;
        }
        while(ans=='y'||ans=='Y');
        break; case 2: cout<<"\n\t\t1. ascending\n\t\t2. descending\n\t\t....enter your choice :";
        cin>>ch;
        cout<<"\n\tkeyword\tmeaning";
        switch(ch) 
        { 
            case 1: 
            tr.inorder(); 
            break; 
            case 2: 
            tr.postorder(); 
            break;
        } 
        break; 
        case 3: 
        break;
    }
    cout<<"\n\t\t....do you want to continue:";
    cin>>ans;
}
while(ans=='y'||ans=='Y');
}