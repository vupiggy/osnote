#include <stdlib.h>	/* abs */

static int
depth_of_tree(bin_tree *root)
{
	int dl, dr;

	if (root == NULL)
		return 0;
	dl = depth_of_tree(root->left);
	dr = depth_of_tree(root->right);
	if (dl == -1 || dr == -1 || abs(dl - dr) > 1)
		return -1;
	return 1 + (dl > dr) ? dl : dr;
}

int
is_tree_balanced(bin_tree *root)
{
	return depth_of_tree(root) >= 0;
}
