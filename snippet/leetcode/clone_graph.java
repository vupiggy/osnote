/* BFS 非递归 */
UndirectedGraphNode cloneGraph(UndirectedGraphNode node)
{
        if(node == null)
		return null;
            
        HashMap<UndirectedGraphNode, UndirectedGraphNode> hm =
		new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
        LinkedList<UndirectedGraphNode> queue =
		new LinkedList<UndirectedGraphNode>();
        UndirectedGraphNode head =
		new UndirectedGraphNode(node.label);
	
        hm.put(node, head);
        queue.add(node);
        
        while (!queue.isEmpty()) {
		UndirectedGraphNode curnode = queue.poll();
		// iterate each neighbor first, i.e., BFS
		for (UndirectedGraphNode neighbor: curnode.neighbors) {
			if (!hm.containsKey(neighbor)) {
				// not visited
				queue.add(neighbor);
				UndirectedGraphNode newneighbor =
					new UndirectedGraphNode(neighbor.label);
				hm.put(neighbor, newneighbor);
			}
                
			hm.get(curnode).neighbors.add(hm.get(neighbor));
		}
        }
        
        return head;
}

/* DFS 递归 */
UndirectedGraphNode cloneGraph(UndirectedGraphNode node)
{
        if(node == null)
		return null;
            
        HashMap<UndirectedGraphNode, UndirectedGraphNode> hm =
		new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
        UndirectedGraphNode head =
		new UndirectedGraphNode(node.label);
        hm.put(node, head);
        
        _clone_graph(hm, node);
        return head;
}

void cloneGraph(HashMap<UndirectedGraphNode, UndirectedGraphNode> hm,
		UndirectedGraphNode node)
{
        if(node == null)
		return;
            
        for (UndirectedGraphNode neighbor: node.neighbors) {
		if (!hm.containsKey(neighbor)) {
			// not visited
			UndirectedGraphNode newneighbor =
				new UndirectedGraphNode(neighbor.label);
			hm.put(neighbor, newneighbor);
			cloneGraph(hm, neighbor); // DFS
		}
		hm.get(node).neighbors.add(hm.get(neighbor));
        }
}

/* DFS 非递归 */
UndirectedGraphNode cloneGraph(UndirectedGraphNode node)
{
        if(node == null)
		return null;
            
        HashMap<UndirectedGraphNode, UndirectedGraphNode> hm =
		new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
        LinkedList<UndirectedGraphNode> stack =
		new LinkedList<UndirectedGraphNode>();
        UndirectedGraphNode head = new UndirectedGraphNode(node.label);
        hm.put(node, head);
        stack.push(node);
        
        while(!stack.isEmpty()){
		UndirectedGraphNode curnode = stack.pop();
		// for each neighbor
		for (UndirectedGraphNode neighbor: curnode.neighbors) {
			// not visited
			if(!hm.containsKey(neighbor)){
				stack.push(neighbor);
				UndirectedGraphNode newneighbor =
					new UndirectedGraphNode(neighbor.label);
				hm.put(neighbor, newneighbor);
			}
			hm.get(curnode).neighbors.add(hm.get(neighbor));
		}
        }
        
        return head;
}
