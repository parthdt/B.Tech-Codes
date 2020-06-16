
#define Max(a,b) ((a>b)?a:b)

int maxNode(struct Node* root)
{
	if(root==NULL)return -1;
	int max=root->data;
	
	int lmax,rmax;
	
	lmax = maxNode(root->left);
	rmax = maxNode(root->right);
	
	max = Max(max,lmax);
	max = Max(max,rmax);
	
	return max;
}
