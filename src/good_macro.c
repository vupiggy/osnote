#define MACRO	do { statement0; statement1; } while(0)
if (condition)
	MACRO();	/* => do { stattement0; statement1; } while(0); GOOD */
else
	/* another statement */
