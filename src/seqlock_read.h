unsigned int seq;
do {
	seq = read_seqbegin(&seqlock);
	/* ... CRITICAL REGION ... */
} while (read_seqretry(&seqlock, seq));
