// Exercise 1.5 – Base 32 printing of integers
//

#include "stdafx.h"
#include <iostream> 

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int i;
	char c[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' };
	short *digits = new short[8 * sizeof(unsigned int) / 5 + 1]{};
	cin >> i;
	while (i != 0) {
		cout << c[i & ((1 << 5) - 1)];
		i /= 32;
	}
	return 0;
}
