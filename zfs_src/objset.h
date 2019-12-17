typedef struct objset_phys {
	dnode_phys_t	os_meta_dnode;
	zil_header_t	os_zil_header;
	uint64_t	os_type;
	uint64_t	os_flags;
	char 		os_pad[OBJSET_PHYS_SIZE - sizeof (dnode_phys_t)*3 -
			       sizeof (zil_header_t) - sizeof (uint64_t)*2];
	dnode_phys_t	os_userused_dnode;
	dnode_phys_t	os_groupused_dnode;
} objset_phys_t;
