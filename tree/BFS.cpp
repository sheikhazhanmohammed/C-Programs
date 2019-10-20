#include<bits/stdc++.h>
using namespace std;
#define lli long long 
struct tree{
    lli data;
    struct tree *left;
    struct tree *right;
};

struct tree *createNode(int val) {
   struct tree *temp =  (struct tree *)malloc(sizeof(struct tree));
   temp->data = val;
   temp->left = temp->right = NULL;
   return temp;
}

struct tree* insertNode(struct tree *node, int val) {   
   if (node == NULL) return createNode(val);
   if (val < node->data)
      node->left  = insertNode(node->left, val);
   else if (val > node->data)
      node->right = insertNode(node->right, val);   
   return node;
}

void bfs(struct tree *root){
    queue<tree*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        tree *f  = q.front();
        if(f == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return ;
}

lli nodeSum(struct tree *root){
    if(root){
        if(root->left == NULL && root->right == NULL){
            return root-> data;
        }
        lli left = nodeSum(root->left);
        lli right = nodeSum(root->right);
        int temp = root->data;
        root->data =  left + right;
        return temp + left + right;
    }
    return 0;
}
int main(){
    struct tree *root = NULL;
    root = insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 2);
    insertNode(root, 9);
    insertNode(root, 1);
    insertNode(root, 3);
    bfs(root);
    cout<<endl;
    nodeSum(root);
    cout<<endl;
    bfs(root);
    return 0;
}