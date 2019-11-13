#define NULL 0
#include<iostream>
#include<string.h>
#include<cstdio>
#include<stdlib.h>
#include<stack>
using namespace std;
#include<stdio.h>

typedef char datatype;
typedef struct node{
    datatype elem;
    struct node* lchild,*rchild;
}BTNode,*BinTree;

BinTree creatBinTree_1(BinTree bt,int isRoot);//交互式创建二叉树
BinTree creatBinTree_2();//先序创建二叉树
void DelTree(BinTree root);//销毁二叉树
void display(BinTree root);//显示树形结构
void preOrder(BinTree root);
void inOrder(BinTree root);
void postOrder(BinTree root);
int maxDepth(BinTree root);//求二叉树的最大深度
BinTree parent(BinTree bt,char NodeName);//查询某个结点的父结点
BinTree Search(BinTree bt,char NodeName);//查询某个结点
int Nodes(BinTree bt);//统计二叉树中的结点个数
void DispLeaf(BinTree bt);//输出二叉树中的所有叶子结点

int main(){
    BinTree root=NULL;
    root=creatBinTree_2();
    cout<<"输出此二叉树："<<endl;
    display(root);
    cout<<"\n 先序排列为：";
    preOrder(root);
     cout<<"\n 中序排列为：";
    inOrder(root);
     cout<<"\n 后序排列为：";
    postOrder(root);
    int num=maxDepth(root);
    cout<<"\n 该二叉树的深度为："<<num<<endl;
    BinTree nn;
    char name;
    cout<<"输入要查找的结点名；";
    cin>>name;
    nn=parent(root,name);
    if(nn)
    cout<<name<<"的父结点名为："<<nn->elem<<endl;
    nn=Search(root,name);
    if(nn->lchild)
        cout<<name<<"的左孩子为："<<nn->lchild->elem<<endl;
        else
        cout<<"没有左孩子"<<endl;
    if(nn->rchild)
        cout<<name<<"的右孩子为："<<nn->rchild->elem<<endl;
        else
        cout<<"没有右孩子"<<endl;
        cout<<"此二叉树的结点数为：";
        cout<<Nodes(root)<<endl;
        cout<<"输出所有的叶子结点：\n";
        DispLeaf(root);
        return 0;

        
}

BinTree creatBinTree_1(BinTree bt,int isRoot){
    char ch;
    if(isRoot)
        cout<<"Root:";
        fflush(stdin);//清空缓存区
        cin>>ch;
        fflush(stdin);
        if(ch!='#'){
            isRoot=0;
            bt=new BTNode;
            bt->elem=ch;
            bt->lchild=NULL;
            bt->rchild=NULL;
            cout<<bt->elem<<"的左孩子是";
            bt->lchild=creatBinTree_1(bt->lchild,isRoot);
             cout<<bt->elem<<"的右孩子是";
            bt->rchild=creatBinTree_1(bt->rchild,isRoot);
        }
        return bt;
}
BinTree creatBinTree_2(){
    BinTree bt=NULL;
    char ch;
    cin>>ch;
    if(ch!='#'){
        bt=new BTNode;
        bt->elem=ch;
        bt->lchild=creatBinTree_2();
        bt->rchild=creatBinTree_2();
    }
    return bt;
}
void DelTree(BinTree root){
    if(root!=NULL){
        DelTree(root->lchild);
        DelTree(root->rchild);
    }
    free(root);
}
void display(BinTree root){
    if(root!=NULL){
        cout<<root->elem;
        if(root->lchild!=NULL||root->rchild!=NULL){
            cout<<'(';
            display(root->lchild);
        }
        if(root->rchild!=NULL){
            cout<<',';
            display(root->rchild);
            cout<<')';
        }
    }
}
void preOrder(BinTree root){
   if(root!=NULL){
       cout<<root->elem;
       preOrder(root->lchild);
       preOrder(root->rchild);
   }
}
void inOrder(BinTree root){
    if(root!=NULL){
       
       preOrder(root->lchild);
       cout<<root->elem;
       preOrder(root->rchild);
   }
}
void postOrder(BinTree root){
    if(root!=NULL){
       
       preOrder(root->lchild);
       
       preOrder(root->rchild);
       cout<<root->elem;
   }
}







int maxDepth(BinTree root){
    if(root==NULL)
    return 0;
    else{
         int m=maxDepth(root->lchild);
         int n=maxDepth(root->rchild);
         if(m>n)
    return (m+1);
    else
        return n+1;
    
    }
    

}




BinTree parent(BinTree bt,char NodeName){
    if(bt)
    {
        if(bt->elem==NodeName){
            cout<<"该结点为根结点"<<endl;
            return NULL;        
        }
    }
    if((bt->lchild->elem==NodeName&&bt->lchild!=NULL)||(bt->rchild->elem==NodeName&&bt->rchild!=NULL))
    return bt;
    else{
        BTNode* tempP=NULL;
        if(tempP==parent(bt->lchild,NodeName))
        return tempP;
        if(tempP==parent(bt->rchild,NodeName))
        return tempP;
    }
    return NULL;
}
BinTree Search(BinTree bt,char NodeName){
    BinTree p;
    if(bt){
        if(bt->elem==NodeName)
        return bt;
        if(bt->lchild){
            p=Search(bt->lchild,NodeName);
            if(p)
            return p;
        }
        if(bt->rchild){
            p=Search(bt->rchild,NodeName);
            if(p)
            return p;
        }
    }
    return NULL;
}
int Nodes(BinTree bt){
    if(bt==NULL)
    return 0;
    else
    {
        return Nodes(bt->lchild)+Nodes(bt->rchild)+1;
    }
    
}
void DispLeaf(BinTree bt){
    if(bt!=NULL)
    {
        if(bt->lchild==NULL&&bt->rchild==NULL)
        cout<<bt->elem<<'.';
        DispLeaf(bt->lchild);
        DispLeaf(bt->rchild)
    
    }
}
