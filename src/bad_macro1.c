#define MACRO	{ statement0; statement1; }
if (condition)
	MACRO()		/* => { stattement0; statement1; } OK but UGLY */
else
	/* another statement */
