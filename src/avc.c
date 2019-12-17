static void avc_node_replace(struct avc_node *new, struct avc_node *old)
{
	list_replace_rcu(&old->list, &new->list);
	
	/* register  a call  that will  free the  original node  after a
	 * grace period has elapsed.
	 */
	call_rcu(&old->rhead, avc_node_free);
	
	atomic_dec(&avc_cache.active_nodes);
}

static int avc_update_node(u32 event, u32 perms, u32 ssid, u32 tsid, u16 tclass)
{
	/* ... local variables ... */

	/* alloc a new node for replacement */
	node = avc_alloc_node();

	/* ... SOME CODE ... */

	/* copy the orig to new */
	avc_node_populate(node, ssid, tsid, tclass, &orig->ae);

	switch (event) {
		/* fill the new node by cases */
	}

	/* replace */
	avc_node_replace(node, orig);

	/* ... SOME CODE ... */
}

static inline struct avc_node *avc_search_node(u32 ssid, u32 tsid, u16 tclass)
{
	struct avc_node *node, *ret = NULL;
	int hvalue;
	
	hvalue = avc_hash(ssid, tsid, tclass);

	/* the _rcu list-traversal */
	list_for_each_entry_rcu(node, &avc_cache.slots[hvalue], list) {
		if (ssid == node->ae.ssid &&
		    tclass == node->ae.tclass &&
		    tsid == node->ae.tsid) {
			ret = node;
			break;
		}
	}

	/* ... SOME CODE ... */
}

static struct avc_node *avc_lookup(u32 ssid, u32 tsid, u16 tclass, u32 requested)
{
	struct avc_node *node;

	/* ... SOME CODE ... */
	
	node = avc_search_node(ssid, tsid, tclass);

	/* ... SOME CODE ... */
}

int avc_has_perm_noaudit(u32 ssid, u32 tsid,
                         u16 tclass, u32 requested,
                         struct av_decision *avd)
{
	/* ... SOME CODE ... */

	/* preempt_disable  */
	rcu_read_lock();
	
	node = avc_lookup(ssid, tsid, tclass, requested);
	
	/* ... SOME CODE ... */

	/* preempt_enable */
	rcu_read_unlock();
}
