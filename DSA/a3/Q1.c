int countNodes(struct Node* root)
{
	int count=0;
	if(root!=NULL)
	{
		count=1;
		count += countNodes(root->left);
		count += countNodes(root->right);
	}
	
	return count;
}
