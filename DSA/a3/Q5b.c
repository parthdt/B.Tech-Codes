int identical(struct Node* tree1, struct Node* tree2)
{
	if(tree1==NULL && tree2==NULL) return 1;
	
	if(tree1==NULL || tree2==NULL) return 0;
	
	return (tree1==tree2 && identical(tree1->left,tree2->left) && identical(tree1->right,tree2->right));
	
}

int subTree(struct Node* t, struct Node* s)
{
	if(s==NULL) return 1;
	
	if(t==NULL) return 0;
	
	if(identical(t,s))return 1;
	
	return (subTree(t->left,s) || subTree(t->right,s));
	
}

//returns 1 if s is a subtree, else returns 0.
