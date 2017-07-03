#include <algorithm>
#include <fstream>
#include <map>
#include <string>

using std::map;
using std::string;
using std::endl;
using std::ifstream;
using std::ofstream;

void print(ofstream &os, const map<string, size_t>& m) {
	for(const auto &v : m) {
		os << v.first << " " << v.second << endl;
	}
}

int main() {
  ifstream infile("infile");
  ofstream outfile("outfile");
  if (!infile.good()) {
    return -1;
  }

  map<string, size_t> word_count;
  string s;
/*  while(infile >> s) {
  	++word_count[s];
  }*/
  while(infile >> s) {
  /*	auto ret = word_count.insert({s, 1});
  	if(!ret.second) {
  		++ ret.first -> second; 
  	}*/
  	++ word_count.insert({s, 0}).first -> second;
  }


  print(outfile, word_count);

  return 0;
}