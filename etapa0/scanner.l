%{
#include "tokens.h"

int lineno = 1;

%}
%%

\n { lineno++; }

		/* Palavras Reservadas (PR) */
int 	{ return TK_PR_INT;		}
float 	{ return TK_PR_FLOAT;	}
bool 	{ return TK_PR_BOOL;	}
char 	{ return TK_PR_CHAR;	}
string 	{ return TK_PR_STRING;	}
if 		{ return TK_PR_IF;		}
then 	{ return TK_PR_THEN;	}
else 	{ return TK_PR_ELSE;	}
while 	{ return TK_PR_WHILE;	}
do 		{ return TK_PR_DO;		}
input 	{ return TK_PR_INPUT;	}
output 	{ return TK_PR_OUTPUT;	}
return 	{ return TK_PR_RETURN;	}

		/* Operadores Compostos (OC) */
<=		{ return TK_OC_LE;		}
>=		{ return TK_OC_GE;		}
==		{ return TK_OC_EQ;		}
!=		{ return TK_OC_NE;		}
&&		{ return TK_OC_AND;		}
||		{ return TK_OC_OR;		}

. 		{ return TOKEN_ERRO; 	}
%%
