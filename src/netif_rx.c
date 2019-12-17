rcu_read_lock();

/* SOME code */

list_for_each_entry_rcu(ptype, &ptype_base[ntohs(type)&15], list) {
	if (ptype->type == type &&
	    (!ptype->dev || ptype->dev == skb->dev)) {
		if (pt_prev) 
			ret = deliver_skb(skb, pt_prev);
		pt_prev = ptype;
	}
}

if (pt_prev) {
	ret = pt_prev->func(skb, skb->dev, pt_prev);
} else {
	kfree_skb(skb);
	/* ... SOME CODE */
}

out:
	rcu_read_unlock();
