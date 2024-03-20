#include<iostream>
class binarySearchTree{
private:
    int val;
    binarySearchTree *left;
    binarySearchTree *right;
public:
    binarySearchTree(int val);
    void isAVl();
    void push(int val,binarySearchTree*& root);
    void traversal(binarySearchTree* root);
    void inorder(binarySearchTree* root);
    void preorder(binarySearchTree* root);
    void postorder(binarySearchTree* root);
    binarySearchTree* deletenode(binarySearchTree*& root,int value);
};

binarySearchTree* binarySearchTree::deletenode(binarySearchTree*& root, int value) {
    if (root == nullptr)
        return root;

    if (value < root->val) {
        root->left = deletenode(root->left, value);
    } else if (value > root->val) {
        root->right = deletenode(root->right, value);
    } else {
        // Node to be deleted is found
        if (root->left == nullptr) {
            binarySearchTree* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            binarySearchTree* temp = root->left;
            delete root;
            return temp;
        } else {
            binarySearchTree* insucc = root->right;
            while (insucc->left != nullptr)
                insucc = insucc->left;
            root->val = insucc->val;
            root->right = deletenode(root->right, insucc->val);
        }
    }
    return root;
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
void binarySearchTree::isAVl(){

}

void binarySearchTree::push(int value, binarySearchTree*& root){
    if (root == nullptr){
       root = new(std::nothrow) binarySearchTree(value);
       return;
    }
   if (value < val) {
    push(value,root->left);
   }
   else{
    push(value,root->right);
   }
}

void binarySearchTree::traversal(binarySearchTree* root) {
    int choice;
    std::cout << "Choose the traversal option:" << std::endl;
    std::cout << "1. Inorder" << std::endl;
    std::cout << "2. Preorder" << std::endl;
    std::cout << "3. Postorder" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        inorder(root);
        break;
    case 2:
        preorder(root);
        break;
    case 3:
        postorder(root);
        break;
    default:
        std::cout << "Invalid choice!" << std::endl;
    }
}

int main(){
    int val;
    std::cout<<"Enter the value of root node(might change afterwards):- ";
    std::cin>>val;
    binarySearchTree* root = new(std::nothrow) binarySearchTree(val);
    int choice;
   while (1) {
        std::cout << std::endl;
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Insert a node" << std::endl;
        std::cout << "2. Delete a node" << std::endl;
        std::cout << "3. Perform traversal" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            int insertVal;
            std::cout << "Enter the value to insert: ";
            std::cin >> insertVal;
            root->push(insertVal, root);
            break;
        case 2:
            int deleteVal;
            std::cout << "Enter the value to delete: ";
            std::cin >> deleteVal;
            root = root->deletenode(root, deleteVal);
            break;
        case 3:
            root->traversal(root);
            break;
        case 4:
            std::cout << "Exiting..." << std::endl;
            delete root; // Clean up memory
            return 0;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    }
    return 0;
}
