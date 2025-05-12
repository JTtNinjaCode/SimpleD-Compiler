%{
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "y.tab.h"
%}

%x CSTYLE_COMMENT
%x CPPSTYLE_COMMENT
%x IN_STRING

%%
"."    { return DOT;                }
".."   { return RANGE;              }
","    { return COMMA;              }
":"    { return COLON;              }
";"    { return SEMICOLON;          }
"("    { return L_PARENTHESES;      }
")"    { return R_PARENTHESES;      }
"["    { return L_SQUARE_BRACKETS;  }
"]"    { return R_SQUARE_BRACKETS;  }
"{"    { return L_BRACKETS;         }
"}"    { return R_BRACKETS;         }

"+"    { return ADD;            }
"++"   { return DADD;           }
"-"    { return SUB;            }
"--"   { return DSUB;           }
"*"    { return MUL;            }
"/"    { return DIV;            }
"%"    { return MOD;            }
"="    { return ASSIGN;         }
"<"    { return LT;             }
"<="   { return LE;             }
">"    { return GT;             }
">="   { return GE;             }
"=="   { return EQ;             }
"!="   { return NE;             }
"&&"   { return AND;            }
"||"   { return OR;             }
"!"    { return NOT;            }

"bool"       { return BOOL;         }
"break"      { return BREAK;        }
"case"       { return CASE;         }
"char"       { return CHAR;         }
"const"      { return CONST;        }
"continue"   { return CONTINUE;     }
"default"    { return DEFAULT;      }
"do"         { return DO;           }
"double"     { return DOUBLE;       }
"else"       { return ELSE;         }
"extern"     { return EXTERN;       }
"false"      { return FALSE;        }
"float"      { return FLOAT;        }
"for"        { return FOR;          }
"foreach"    { return FOREACH;      }
"if"         { return IF;           }
"int"        { return INT;          }
"print"      { return PRINT;        }
"println"    { return PRINTLN;      }
"read"       { return READ;         }
"return"     { return RETURN;       }
"string"     { return STRING;       }
"switch"     { return SWITCH;       }
"true"       { return TRUE;         }
"void"       { return VOID;         }
"while"      { return WHILE;        }

[0-9]+                              { yylval.ival = atoi(yytext);   return INT_LITERAL;         }
[0-9]+\.[0-9]+([eE][+-]?[0-9]+)?    { yylval.fval = atof(yytext);   return FLOAT_LITERAL;       }
[a-zA-Z_][a-zA-Z0-9_]*              { yylval.sval = strdup(yytext); return IDENT;               }
[ \t\n]                             { /* skip whitespace */                                     }

\"                                  { BEGIN(IN_STRING);                                         }
<IN_STRING>[^\"]*(\"\")*[^\"]*      { yylval.sval = strdup(yytext); return STRING_LITERAL;      }
<IN_STRING>\"                       { BEGIN(INITIAL);                                           }

"//"                                { BEGIN(CPPSTYLE_COMMENT);                      }
<CPPSTYLE_COMMENT>\n                { BEGIN(INITIAL);                               }
<CPPSTYLE_COMMENT>[^\n]*            { /* do nothing */                              }

"/*"                                { BEGIN(CSTYLE_COMMENT);                        }
<CSTYLE_COMMENT>"*/"                { BEGIN(INITIAL);                               }
<CSTYLE_COMMENT>.|\n                { /* do nothing */                              }
%%