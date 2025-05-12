%{
#include <stdio.h>
#include <string.h>
#include <signal.h>id

#define BUF_SIZE 1000000
int line_num = 0;
size_t buf_len = 0;
char buf[BUF_SIZE] = {};

char *elim_dup_double_quote(const char *str) {
    static char result[65536];

    size_t len = strlen(str);
    size_t i = 0, j = 0;
    while (i < len) {
        if (str[i] == '"' && str[i + 1] == '"') {
            result[j++] = '"';
            i += 2;  // Skip the second quote
        } else {
            result[j++] = str[i++];
        }
    }

    result[j] = '\0';  // Null-terminate the result string
    return result;
}

#define putToBuf()          do { memcpy(buf + buf_len, yytext, yyleng);buf_len += yyleng; buf[buf_len] = '\0';  } while(0)
#define dumpBuf()           do { printf("%d: %s\n", ++line_num, buf); buf_len = 0; buf[0] = '\0';               } while(0)

#define token(t)            do { printf("<'%s'>\n", t);                                     } while(0)
#define tokenInteger()      do { printf("<INT:%s>\n", yytext);                              } while(0)
#define tokenIden()         do { printf("<ID:%s>\n", yytext); insert(st, yytext);           } while(0)
#define tokenFloat()        do { printf("<FLOAT:%s>\n", yytext);                            } while(0)
#define tokenString()       do { printf("<string:%s>\n", elim_dup_double_quote(yytext));    } while(0)

#define  TABLE_SIZE 64
typedef struct Symbol {
    const char *name;
    const char *type;
    int scope;
    struct Symbol *next;
} Symbol;

typedef Symbol* SymTlb[TABLE_SIZE] ;
SymTlb st = {};

unsigned hash(const char *str) {
    unsigned h = 5381;
    while (*str) h = ((h << 5) + h) + *str++;
    return h % TABLE_SIZE;
}
const char *lookup(const SymTlb st, const char *str) {
    unsigned h = hash(str);
    for (Symbol *s = st[h]; s; s = s->next) {
        if (strcmp(s->name, str) == 0) {
            return str;
        }
    }
    return NULL;
}
void insert(SymTlb st, const char *id) {
    unsigned h = hash(id);
    Symbol *sym = malloc(sizeof(Symbol));
    sym->name = strdup(id);
    sym->next = st[h];
    st[h] = sym;
}
void dump(SymTlb st) {
    printf("Symbol Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (Symbol *s = st[i]; s; s = s->next) {
            printf("%s\n", s->name);
        }
    }
}
%}

%x CSTYLE_COMMENT
%x CPPSTYLE_COMMENT
%x STRING

%%
"."    { putToBuf(); token(".");    }
".."   { putToBuf(); token("..");   }
","    { putToBuf(); token(",");    }
":"    { putToBuf(); token(":");    }
";"    { putToBuf(); token(";");    }
"("    { putToBuf(); token("(");    }
")"    { putToBuf(); token(")");    }
"["    { putToBuf(); token("[");    }
"]"    { putToBuf(); token("]");    }
"{"    { putToBuf(); token("{");    }
"}"    { putToBuf(); token("}");    }

"+"    { putToBuf(); token("+");    }
"++"   { putToBuf(); token("++");   }
"-"    { putToBuf(); token("-");    }
"--"   { putToBuf(); token("--");   }
"*"    { putToBuf(); token("*");    }
"/"    { putToBuf(); token("/");    }
"%"    { putToBuf(); token("%");    }
"="    { putToBuf(); token("=");    }
"<"    { putToBuf(); token("<");    }
"<="   { putToBuf(); token("<=");   }
">"    { putToBuf(); token(">");    }
">="   { putToBuf(); token(">=");   }
"=="   { putToBuf(); token("==");   }
"!="   { putToBuf(); token("!=");   }
"&&"   { putToBuf(); token("&&");   }
"||"   { putToBuf(); token("||");   }
"!"    { putToBuf(); token("!");    }

"bool"       { putToBuf(); token("BOOL");       }
"break"      { putToBuf(); token("BREAK");      }
"case"       { putToBuf(); token("CASE");       }
"char"       { putToBuf(); token("CHAR");       }
"const"      { putToBuf(); token("CONST");      }
"continue"   { putToBuf(); token("CONTINUE");   }
"default"    { putToBuf(); token("DEFAULT");    }
"do"         { putToBuf(); token("DO");         }
"double"     { putToBuf(); token("DOUBLE");     }
"else"       { putToBuf(); token("ELSE");       }
"extern"     { putToBuf(); token("EXTERN");     }
"false"      { putToBuf(); token("FALSE");      }
"float"      { putToBuf(); token("FLOAT");      }
"for"        { putToBuf(); token("FOR");        }
"foreach"    { putToBuf(); token("FOREACH");    }
"if"         { putToBuf(); token("IF");         }
"int"        { putToBuf(); token("INT");        }
"print"      { putToBuf(); token("PRINT");      }
"println"    { putToBuf(); token("PRINTLN");    }
"read"       { putToBuf(); token("READ");       }
"return"     { putToBuf(); token("RETURN");     }
"string"     { putToBuf(); token("STRING");     }
"switch"     { putToBuf(); token("SWITCH");     }
"true"       { putToBuf(); token("TRUE");       }
"void"       { putToBuf(); token("VOID");       }
"while"      { putToBuf(); token("WHILE");      }

[0-9]+                              { putToBuf(); tokenInteger();                   }
[0-9]+\.[0-9]+([eE][+-]?[0-9]+)?    { putToBuf(); tokenFloat();                     }
[a-zA-Z_][a-zA-Z0-9_]*              { putToBuf(); tokenIden();                      }
\n                                  { dumpBuf();                                    }
[ \t]                               { putToBuf(); /* skip whitespace */             }

\"                                  { putToBuf(); BEGIN(STRING);                    }
<STRING>[^\"]*(\"\")*[^\"]*         { putToBuf(); tokenString();                    }
<STRING>\"                          { putToBuf(); BEGIN(INITIAL);                   }

"//"                                { putToBuf(); BEGIN(CPPSTYLE_COMMENT);          }
<CPPSTYLE_COMMENT>\n                { dumpBuf();  BEGIN(INITIAL);                   }
<CPPSTYLE_COMMENT>[^\n]*            { putToBuf(); /* do nothing */                  }

"/*"                                { putToBuf(); BEGIN(CSTYLE_COMMENT);            }
<CSTYLE_COMMENT>"*/"                { putToBuf(); BEGIN(INITIAL);                   }
<CSTYLE_COMMENT>[^\n]               { putToBuf(); /* do nothing */                  }
<CSTYLE_COMMENT>\n                  { dumpBuf();                                    }
%%

int main(int argc, char **argv) {
    yylex();
    dump(st);
    return 0;
}
