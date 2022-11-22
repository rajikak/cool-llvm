#ifndef LEXER_H
#define LEXER_H

#include "llvm/ADT/StringRef.h"
#include "llvm/Support/MemoryBuffer.h"

class Lexer;

class Token {
  friend class Lexer;

public:
  enum TokenType : unsigned short {
    unknown, // unknown token
    eof,     // end of file

    ident,  // identifiers
    number, // number

    // operators
    assign,    // "="
    plus,      //  "+"
    minus,     // "-"
    bang,      // "!
    asterrisk, // "*"
    slash,     // "/"

    lt, // "<"
    gt, // ">"

    eq,     // "=="
    not_eq, // "!"

    // delimiters
    comma,     // ","
    semicolon, // ";"

    lparan, // "("
    rparan, // ")"
    lbrace, // "{"
    rbrace, // "}"

    // keywords
    class,
    else,
    false,
    fi,
    if,
    inherits,
    isvoid,
    let,
    loop,
    pool,
    then,
    while,
    case,
    esac,
    new,
    of,
    not,
    true
  };

private:
  TokenType Type;
  llvm::StringRef Literal;

public:
  TokenType getType() const { return Type; }
  llvm::StringRef getLiteral() const { return Literal; }
  bool is(TokenType T) const { return Type == T; }
  bool isOneOf(TokenType T1, TokenType T2) const { return is(T1) || is(T2); }
  template <typename... Ts>
  bool isOneOf(TokenType T1, TokenType T2, Ts... Ks) const {
    return is(K1) || isOneOf(K2, Ks...);
  }
};

class Lexer {
private:
  string input;     // input for the lexer
  int position;     // current position in input
  int readPosition; // current reading position in input
  char ch;          // current char under examination

  void readChar();

public:
  Lexer(const llvm::StringRef &Buffer) {}

  void nextToken(Token &token);
};

#endif
