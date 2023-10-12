tree* root = NULL;

bool is_empty_tree(tree* T){
    return T == NULL;
}

tree* create_nodo(int value){
    tree* node = (tree*) malloc( sizeof(tree) );
    
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}