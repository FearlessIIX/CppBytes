#include "BinConv.h"
#include <vector>
using namespace std;
using byte = char;

string BinConv::printBits(byte b) {

	string repr = "";

	for (int i = 8; i > 0; i--) {
		if (b & (1 << (i - 1))) {
			repr = repr + "1";
		}
		else {
			repr = repr + "0";
		}
	}

	return repr;
}

vector<byte> BinConv::convertToBytes(int i) {

	vector<byte> bytes;
	short modBit = 8; byte b;

	// Runs through all 32 bits in number
	for (int bitIndex = 32; bitIndex > 0; bitIndex--) {
		if (modBit == 8) {
			b = 0;
		}

		// Sets current modBit if bit at bitIndex is set
		if (i & (1 << (bitIndex - 1))) {
			b |= 1UL << modBit - 1;
		}
		
		// Regardless of last if statement, set modBit down by one
		modBit--;

		// We have used all bits in current byte, and there are more bits left in number
		if (modBit == 0) {

			// Store current byte, and reset modBit and current byte
			bytes.push_back(b);
			modBit = 8;
		}
	}

	return bytes;
}

char readByte(unsigned int num, int index) {

	char byte = 0;
	int start = (index * 8) + 8;

	for (int i = start; i > start - 8; i--) {

		cout << "INDEX: " << i << "\n";

		if (num & (1 << (i - 1))) {
			byte |= 1 << (i - 1);
		}
	}

	return byte;
}

vector<char> BinConv::getBin(unsigned int num) {
	vector<char> vect;
	//1 2 4 8 16 32 64 128 256 512 1024 2048

	for (int i = 3; i >= 0; i--) {
		char c = readByte(num, i);
		vect.push_back(c);
	}

	return vect;
}

vector<int> BinConv::getDivs(unsigned int num) {
	vector<int> vect;
	for (int div = 1; div <= num; div++) {
		if (num % div == 0) vect.push_back(div);
	}

	return vect;
}

int bytesToInt(vector<byte> bytes) {
	if (bytes.size() > 4) {
		cout << "WARN  size of bytes passed greater than int type size\n";
	}

	return 0;
}