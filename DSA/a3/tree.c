#include<stdio.h>
#include<stdlib.h>

#define Max(a,b) ((a>b)?a:b)
struct Node
{
	int data;
	struct Node *left,*right;
};

struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	
	node->data=data;
	
	node->left=node->right=NULL;
	
	return node;
}

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

int printLessThanV(struct Node* root, int v)
{
	if(root==NULL)return 0;
	
	if(root->data < v)printf("%d\n",root->data);
	printLessThanV(root->left,v);
	printLessThanV(root->right,v);
}

int balanced(struct Node *root)
{
	if(root==NULL) return 1;
	
	int lh,rh;
	
	lh=height(root->left);							//height funtion defined in Q2 (a)
	rh=height(root->right);
	
	if(abs(rh-lh) <=1 && balanced(root->left) && balanced(root->right)) return 1;
	
	else return 0;
}

int po[100]={0};

void postOrderN(struct Node *root,int n)
{
	static int count=0;
	if(root==NULL) return;
	
	
	postOrderN(root->left,n);
	postOrderN(root->right,n);
	count++;
	
	if(count==n)printf("%d",root->data);
	
}

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
int main()
{
	struct Node* new=newNode(1);
	new->left=newNode(2);
	new->left->left=newNode(1);
	new->left->right=newNode(10);
	new->right=newNode(4);
	
	printf("%d",cost(new));
	return 0;
}

		
		
		
		
		
