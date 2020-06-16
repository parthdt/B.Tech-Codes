int height(struct Node* root)
{
	if(root==NULL) return 0;
	
	else
	{
		int l=height(root->left);
		int r=height(root->right);
		
		return l>r ? l+1 : r+1;
	}
}
