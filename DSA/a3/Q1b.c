int sum(struct Node* root)
{
	int count=0;
	if(root!=NULL)
	{
		count=root->data;
		count += sum(root->left);
		count += sum(root->right);
	}
	
	return count;
}
