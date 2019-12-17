/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)−>MEMBER)
#define container_of(ptr, type, member) ({				\
      const typeof( ((type *)0)->member ) *__mptr = (ptr);		\
      (type *)( (char *)__mptr - offsetof(type,member) );})


