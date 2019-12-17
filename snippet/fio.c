static int
fd_find(uf_info_t *fip, int minfd)
{
	int size, ralloc, fd;

	for (fd = minfd; (uint_t)fd < fip->fi_nfiles; fd |= fd + 1 /* 右祖先 */) {
		/* 完全二叉树右子树（包括根）的节点数 */
		size = fd ^ (fd | (fd + 1));
		/* 此树已满，沿右祖先上溯 */
		if (fip->fi_list[fd].uf_alloc == size)
			continue;
		for (ralloc = 0, size >>= 1; size != 0; size >>= 1 /* csize(child) */ ) {
			/* 右子树 fd 分配数目 */
			ralloc += fip->fi_list[fd + size].uf_alloc;
			/* 根分配数减去右子树分配数恰好是csize(child)，
			 * 说明左子树已满，转而尝试到右子树找空闲fd。
			 */
			if (fip->fi_list[fd].uf_alloc == ralloc + size) {
				/* 右子成为新一轮搜索的 root */
				fd += size;
				ralloc = 0;
			}
		}
		return (fd);
	}
	return (-1);
}
