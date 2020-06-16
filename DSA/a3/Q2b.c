int cost(struct Node* root)
{
	static int max = 0;
	static int cmax = 0;
	
	if(root==NULL) 
	{	
		max=Max(cmax,max);
		cmax=0;
		return max;
	}

	cmax+=root->data;
	cost(root->left);
	cmax+=root->data;
	cost(root->right);	
	
	return max;
}
