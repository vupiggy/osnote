#define MACRO	statement0; statement1;
if (condition)
	MACRO();	/* => stattement0; statement1; WRONG */
else
	/* another statement */

