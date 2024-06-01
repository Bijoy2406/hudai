#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;

};
node *root=NULL;
queue<node*>a;
void BST_insert(int value){

    node *temp;
    temp=new node();
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL) root=temp;
    else{
        node *curr_node=root;
        node *prev_node=root;
        while(curr_node!=NULL){
            prev_node=curr_node;
            if(curr_node->data<value){
                curr_node=curr_node->right;
            }else{
            curr_node=curr_node->left;
            }
        }
        if(prev_node->data<value){
            prev_node->right=temp;
        }else{
            prev_node->left=temp;
        }
    }


}
void In_order(node *root){
    if(root!=NULL){
        In_order(root->left);
        cout<<root->data<<" ";
        In_order(root->right);
    }


}
void Post_order(node *root){
    if(root!=NULL){
        Post_order(root->left);
        Post_order(root->right);
        cout<<root->data<<" ";
    }
}
void min_value(node *root){
   if(root->left!=NULL){
    min_value(root->left);
   }else
     cout<<root->data<<endl;

}
void max_value(node *root){
   if(root->right!=NULL){
    max_value(root->right);
   }else
     cout<<root->data<<endl;

}
void Pre_order(node *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        Pre_order(root->left);
        Pre_order(root->right);

    }
}
void tree_build(int value){
    node *temp;
    temp=new node();
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL) {
            root=temp;
            a.push(root);
    }
    else{
            node *curr_node=a.front();
            if(curr_node->left==NULL){
                curr_node->left=temp;
                a.push(temp);
            }else{
                curr_node->right=temp;
                a.push(temp);
                a.pop();
            }

    }

}
int main(){
    int x;
    for(int i=1;i<=11;i++){
        cin>>x;
        tree_build(x);
    }
    //Post_order(root);
    cout<<"In order: ";
    In_order(root);
    cout<<endl;
    cout<<"Pre order: ";
    Pre_order(root);
    cout<<endl;
    cout<<"Post order: ";
    Post_order(root);

}
/*
5 6
1 3
1 2
5 3
1 5
2 4
4 5
*/