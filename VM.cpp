// VM.cpp

#include <iostream>
#include <vector>
#include "BinConv.h"
using namespace std;

// char is 1 byte integer
using byte = char;

void printBits(unsigned int);

int main(int argc, char **argv) {

	BinConv binConv = BinConv();


	vector<byte> bytes = binConv.convertToBytes(1234);

	for (byte b : bytes) {
		
		cout << binConv.printBits(b) << " ";
	}

	//vector<char> bin;

	//bin = binConv.getBin(4294967295);
	
	//for (char c : bin) {
		//binConv.printBits(c);
		//cout << " ";
	//}

	return 0;
}

void printBits(unsigned int i) {
	for (int i = 32; i > 0; i--) {
		if (i & (1 << (i - 1))) {
			cout << "1";
		}
		else {
			cout << "0";
		}
	}
}