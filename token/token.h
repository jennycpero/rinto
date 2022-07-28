#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <map>

typedef int token;
typedef std::pair<const std::string, token> token_pair;

/* The position type keeps track of character/token
   positions, with respect to their parent document,
   for error/warnings and debugging*/
typedef struct {
  std::string file;
  int offset;
  int line;
  int column;
} position;

/* Reserved identifiers */
enum TOKENS {
  // Generic
  ILLEGAL = 0,
  IDENT, COMMENT,

  // Types
  type_beg,
  RID_INT, RID_FLOAT, RID_CHAR, RID_STRING, RID_DOUBLE,
  RID_VOID, RID_STRUCT, RID_BOOL, RID_FUNC,
  type_end,

  /* Modifiers */
  mod_beg,
  RID_UNSIGNED, RID_LONG, RID_CONST, RID_SHORT,
  mod_end,

  /* Expressions */
  expr_beg,
  RID_IF, RID_ELSE, RID_FOR, RID_SWITCH, RID_CASE,
  RID_BREAK, RID_CONTINUE, RID_RETURN, RID_GOTO,
  RID_WHILE, RID_DEFAULT, RID_SIZEOF,
  expr_end,

  /* State */
  state_beg,
  RID_TRUE, RID_FALSE, RID_NULL,
  state_end
};

/* Initialize string-token map. */
void init_keywords();

/* Takes a string 'tok' and returns the assosciated
   token.*/
token lookup(std::string tok);

/* Takes a string 'tok' and returns true/false if
   instance of specified token type. */
bool is_modifier(std::string tok);
bool is_type(std::string tok);
bool is_expression(std::string tok);
bool is_state(std::string tok);
bool is_identifier(std::string tok);

#endif