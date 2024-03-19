#include<iostream>

class binarySearchTree{
private:
    int val;
    binarySearchTree *left;
    binarySearchTree *right;
public:
    binarySearchTree(int val);
    ~binarySearchTree();
    void isAVl();
    void push(int val,binarySearchTree* root);
    void traversal(binarySearchTree* root);
    void inorder(binarySearchTree* root);
    void preorder(binarySearchTree* root);
    void postorder(binarySearchTree* root);
};

void binarySearchTree::inorder(binarySearchTree* head){
    binarySearchTree* temp = head;
    if (temp == nullptr)
    {
        return;
    }
    inorder(temp->left);
    std::cout<<"value= "<<temp->val<<std::endl;
    inorder(temp->right);
}

void binarySearchTree::inorder(binarySearchTree* head){
    binarySearchTree* temp = head;
    if (temp == nullptr)
    {
        return;
    }
    inorder(temp->left);
    std::cout<<"value= "<<temp->val<<std::endl;
    inorder(temp->right);
}

void binarySearchTree::preorder(binarySearchTree* head){
    binarySearchTree* temp = head;
    if (temp == nullptr){
        return;
    }
    std::cout<<"value= "<<temp->val<<std::endl;
    preorder(temp->left);
    preorder(temp->right);
}

void binarySearchTree::postorder(binarySearchTree* head){
    binarySearchTree* temp = head;
    if (temp == nullptr){
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    std::cout<<"value= "<<temp->val<<std::endl;
}

binarySearchTree::binarySearchTree(int value){
    val = value;
    left = nullptr;
    right = nullptr;
}

binarySearchTree::~binarySearchTree(){
    
}

void binarySearchTree::isAVl(){

}

void binarySearchTree::push(int value, binarySearchTree* root){
    if (root == nullptr){
       return;
    }
  if (val>value) {
    push(value,root->left);
    binarySearchTree* ptr = new(std::nothrow) binarySearchTree(value);
    root->left = ptr;
  }
  else{
    push(value,root->right);
    binarySearchTree* ptr = new(std::nothrow) binarySearchTree(value);
    root->right = ptr;
  }
}
void binarySearchTree::traversal(binarySearchTree* root){
    std::cout<<"choose the option:- "<<std::endl<<"1. Inorder"<<std::endl<<"2.preorder"<<std::endl<<"3.postorder"<<std::endl;
}

int main(){
    int val;
    std::cout<<"enter the calue of root node(might change afterwards):- ";
    std::cin>>val;
    binarySearchTree* root = new(std::nothrow) binarySearchTree(val);
    return 0;
}
