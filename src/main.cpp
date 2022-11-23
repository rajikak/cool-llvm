#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Lexer.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/raw_ostream.h"

using namespace std;

string read(const string file_name) {
  ifstream f(file_name);
  string str;

  if (f) {
    ostringstream ss;
    ss << f.rdbuf();
    str = ss.str();
  }

  return str;
}

int main() {

  string path =
      "/Users/kumarasiri/github/cool-llvm/suite"; // test suite for the compiler

  string content;
  for (const auto &file : filesystem::directory_iterator(path)) {
    content = read(file.path());
	cout << "parsing: " << file.path() << endl;
	Lexer Lex(content);
	Token Tok;
	Lex.nextToken(Tok);

	charinfo::printToken(Tok);
  }
}
