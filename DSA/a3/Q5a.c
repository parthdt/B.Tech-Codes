void postOrderN(struct Node *root,int n)
{
	static int count=0;
	if(root==NULL) return;
	
	
	postOrderN(root->left,n);
	postOrderN(root->right,n);
	count++;
	
	if(count==n)printf("%d",root->data);
	
}
