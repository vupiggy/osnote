struct node *
bst_lca(struct node *root, struct node *p, struct node *q)
{
	if (!root || !p || !q)
		return NULL;
	
	if (max(p->data, q->data) < root->data)
		return bst_lca(root->left, p, q);
	else if (min(p->data, q->data) > root->data)
		return bst_lca(root->right, p, q);
	else
		return root;
}

struct node *
bst_lca(struct node *root, struct node *p, struct node *q)
{
	if (!root || !p || !q)
		return NULL;

	while (root) {
		if (max(p->data, q->data) < root->data)
			root = root->left;
		else if (min(p->data, q->data) > root->data)
			root = root->right;
		else
			return root;
	}
	
	return NULL;
}

/* Not BST */
struct node *
lca(struct node *root, struct node *p, struct node *q)
{  
	if (!root) return NULL;
	
	if (root == p || root == q) return root;
        
	struct node *L = lca(root->left, p, q); 
	struct node *R = lca(root->right, p, q);

	/* p,q locate in different subtree, it's LCA */
	if (L && R) return root;

	/* going up until reaching the LCA */
	return L ? L : R;
}
