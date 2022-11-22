#include "Lexer.h"

namespace charinfo {
LLVM_READNONE inline bool isWhilteSpace(char c) {
  return c == ' ' || c == '\t' || c == '\f' || c == '\v' || c == '\r' ||
         c == '\n' || c == '\b';
}

LLVM_READNONE inline bool isDigit(char c) { return c >= '0' && c <= '9'; }

LLVM_READNONE inline bool isLetter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A')
}
} // namespace charinfo
