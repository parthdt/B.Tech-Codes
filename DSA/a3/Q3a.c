int balanced(struct Node *root)
{
	if(root==NULL) return 1;
	
	int lh,rh;
	
	lh=height(root->left);							//height funtion defined in Q2 (a)
	rh=height(root->right);
	
	if(abs(rh-lh) <=1 && balanced(root->left) && balanced(root->right)) return 1;
	
	else return 0;
}
