using namespace std;

#include "reader.hpp"

enum order {IN,PRE,POST};


typedef struct node {
    Battalion data;
    struct node* left;
    struct node* right;
} tree;

tree* root = NULL;

bool is_empty_tree(tree* T){
    return T == NULL;
}




tree* create_nodo(Battalion value){
    tree* node = (tree*) malloc( sizeof(tree) );
    
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}


void insert_aux(tree* T, Battalion value){
    if(value.getId() <= T->data.getId())
        if(T->left == NULL) T->left = create_nodo(value);
        else insert_aux(T->left, value);
    else
        if(T->right == NULL) T->right = create_nodo(value);
        else insert_aux(T->right, value);
}       

void insert(tree* T, Battalion value){
    if(is_empty_tree(T)) root = create_nodo(value);
    else insert_aux(T, value);
}

void show_in_order(tree* T){
    if(T == NULL){
        cout << "- ";
        return;
    }
    cout << "[ ";
    cout << T->data.getId() << " ";
    show_in_order(T->left);
    show_in_order(T->right);
    cout << "] ";
}

void show_pre_order(tree* T){
    if(T == NULL){
        cout << "- ";
        return;
    }
    cout << "[ ";
    show_pre_order(T->left);
    cout << T->data.getId() << " ";
    show_pre_order(T->right);
    cout << "] ";
}

void show_post_order(tree* T){
    if(T == NULL){
        cout << "- ";
        return;
    }
    cout << "[ ";
    show_post_order(T->left);
    show_post_order(T->right);
    cout << T->data.getId() << " ";
    cout << "] ";
}

void show(tree* T, order mode){
    switch(mode){
        case IN:
            show_in_order(T);
            break;
        case PRE:
            show_pre_order(T);
            break;
        case POST:
            show_post_order(T);
            break;
    }
    cout << "\n";
}


int main(int argc, char** argv){
    
    Battalion data[1000];
    load_data(data);


    for(int i = 0; i < 1000; ++i)
        insert(root, data[i]);

    cout << "Mostrando árbol en In-Order:\n";
        show(root, IN);

    return 0;

    //comparando strings
}