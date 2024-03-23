#include<iostream>
class binarySearchTree{
private:
    int val;
    int height;
    binarySearchTree *left;
    binarySearchTree *right;
public:
    binarySearchTree(int val);
    void isAVl();
    void push(int val,binarySearchTree*& root,int height);
    void traversal(binarySearchTree* root);
    void inorder(binarySearchTree* root);
    void preorder(binarySearchTree* root);
    void postorder(binarySearchTree* root);
    binarySearchTree* deletenode(binarySearchTree*& root,int value);
    void search(binarySearchTree* root,int value);
};

void binarySearchTree::search(binarySearchTree* root, int value){
    if (root == nullptr){
        std::cout<<"Node not found !"<<std::endl;
        return;
    }
    
    else if (root->val == value){
        std::cout<<value<<" found at level : "<<root->height-1<<std::endl;
        return;
    }
    else if (value < root->val){
        search(root->left,value);
        return;
    }
    else if (value > root->val){
        search(root->right,value);
        return;
    }
}

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
    if (head == nullptr)
    {
        return;
    }
    inorder(head->left);
    std::cout<<"value= "<<head->val<<std::endl;
    inorder(head->right);
    
}

void binarySearchTree::preorder(binarySearchTree* head){
    if (head == nullptr){
        return;
    }
    std::cout<<"value= "<<head->val<<std::endl;
    preorder(head->left);
    preorder(head->right);
}

void binarySearchTree::postorder(binarySearchTree* head){
    if (head == nullptr){
        return;
    }
    postorder(head->left);
    postorder(head->right);
    std::cout<<"value= "<<head->val<<std::endl;
}

binarySearchTree::binarySearchTree(int value){
    val = value;
    left = nullptr;
    right = nullptr;
    height = 1;
}
void binarySearchTree::isAVl(){

}

void binarySearchTree::push(int value, binarySearchTree*& root,int height){
    if (root == nullptr){
       root = new(std::nothrow) binarySearchTree(value);
       root->height = height;
       return;
    }
   if (value < root->val) {
    push(value,root->left,++height);
   }
   else{
    push(value,root->right,++height);
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
        std::cout << "4. Search Node" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            int insertVal;
            std::cout << "Enter the value to insert: ";
            std::cin >> insertVal;
            root->push(insertVal, root,1);
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
            int searchVal;
            std::cout << "Enter the value to search: ";
            std::cin >> searchVal;
            root->search(root,searchVal);
            std::cout << "value of root node : "<<" at level ";

            break;
        case 5:
            std::cout << "Exiting..." << std::endl;
            delete root; // Clean up memory
            return 0;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    }
    return 0;
}
