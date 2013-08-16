/* Projeto de Compiladores 2013-2 - Etapa 1
   Fernando Soller Mecking
   Lucas Herbert Jones
   Mateus Cardoso da Silva
*/

/* Declarações*/

%x MLCOMMENT
%option noyywrap

%{

#include "tokens.h"

%}

/* Expressões Regulares */

ID          [_a-zA-Z][_a-zA-Z0-9]*
INT         (\-)?[0-9]+
FLOAT       (\-)?[0-9]+"."[0-9]+
CHAR        '[^\']'
STRING      \"[^\"]+\"
WHITESPACE  [ \t\v\f]*


/* Regras */
%%
\n			        { yylineno++; }
{WHITESPACE}    { }
"int"           { return TK_PR_INT; }
"float"         { return TK_PR_FLOAT; }
"bool"          { return TK_PR_BOOL; }
"char"          { return TK_PR_CHAR; }
"string"        { return TK_PR_STRING; }
"if"            { return TK_PR_IF; }
"then"          { return TK_PR_THEN; }
"else"          { return TK_PR_ELSE; }
"while"         { return TK_PR_WHILE; }
"do"            { return TK_PR_DO; }
"input"         { return TK_PR_INPUT; }
"output"        { return TK_PR_OUTPUT; }
"return"        { return TK_PR_RETURN; }
"false"         { return TK_LIT_FALSE; }
"true"          { return TK_LIT_TRUE; }
","|";"|":"     { return yytext[0]; }
"("|")"	        { return yytext[0]; }
"["|"]"         { return yytext[0]; }
"{"|"}"         { return yytext[0]; }
"+"|"-"         { return yytext[0]; }
"*"|"/"         { return yytext[0]; }
"<"|">"	        { return yytext[0]; }
"="|"!"  	      { return yytext[0]; }
"&"|"$"  	      { return yytext[0]; }
"<="		        { return TK_OC_LE; }
">="		        { return TK_OC_GE; }
"=="		        { return TK_OC_EQ; }
"!="		        { return TK_OC_NE; }
"&&"		        { return TK_OC_AND; }
"||"		        { return TK_OC_OR; }
{ID}            { return TK_IDENTIFICADOR; }
{INT}           { return TK_LIT_INT; }
{FLOAT}         { return TK_LIT_FLOAT; }
{CHAR}          { return TK_LIT_CHAR; }
{STRING}        { return TK_LIT_STRING; }
"/*"	          { BEGIN( MLCOMMENT ); }
"//"[^\r\n]*    { }
<MLCOMMENT>"*/" { BEGIN( INITIAL ); }
<MLCOMMENT>.    {  }
<MLCOMMENT>\n	  { yylineno++; }
.               { return TOKEN_ERRO; }
%%

