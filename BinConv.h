#pragma once

#include <iostream>
#include <vector>
using namespace std;
using byte = char;

class BinConv
{
public:
	string printBits(byte);
	vector<byte> convertToBytes(int);
	vector<char> getBin(unsigned int);
	vector<int> getDivs(unsigned int);
};