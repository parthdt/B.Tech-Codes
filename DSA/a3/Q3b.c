int printLessThanV(struct Node* root, int v)
{
	if(root==NULL)return 0;
	
	if(root->data < v)printf("%d\n",root->data);
	printLessThanV(root->left,v);
	printLessThanV(root->right,v);
}

