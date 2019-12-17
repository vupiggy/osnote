int
unique_trees(unsigned int n)
{
	int	 i, j;
    	int	 res;
    	int	*trees;
    	
        if(n == 0) return 1;
        
        trees = (int *) malloc((n + 1) * sizeof(int));
    	if (trees == NULL)
    		return -1;
    
    	memset(trees, 0, (n + 1) * sizeof(int));
        trees[0] = 1;
        trees[1] = 1;
        
        for (i = 2; i <= n; ++i)
        	for(j = 0; j < i; ++j)
        		trees[i] += trees[j] * trees[i - j - 1];
    	
        res = trees[n];
        free(trees);
        return res;
}

