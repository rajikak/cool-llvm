#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <sstream>

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

	string path = "/Users/kumarasiri/github/cool-llvm/examples";

	string content;
	for(const auto & file: filesystem::directory_iterator(path)) {
		content = read(file.path());
		cout << content << endl;
	}
}