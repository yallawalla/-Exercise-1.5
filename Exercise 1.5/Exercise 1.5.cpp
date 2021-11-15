// Exercise 1.5 � Base 32 printing of integers
//

#include "stdafx.h"
#include <iostream> 

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char c[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUV"};									// string (array karakterjev, isti qrac) za preslikavo z indeksom, temu se re�e "lookup table"

	unsigned int basebits = 5;															// base 32 rabi 5 bitov, od 0 do 31... lahko poskus� prevest tut z 1(binarno), 3(oct) ali 4(hex)
	unsigned int ndigits = (8 * sizeof(unsigned int) + basebits - 1) / basebits;		// sizeof(int) vrne 4(byte), 32 bitna cifra pa�... finta z basebits - 1 je zato, da zaokro�i navzgor, ker 32/5 se ne izide in rab� �e eno polje
	short *digits = new short[ndigits]{};												// alokacija in brisanje na 0 z {}

	while (1) {																			// neskon�na zanka
		cout << endl << "enter value:" ;												// vpis
		unsigned int i,j;
		cin >> i;
		if (i == 101198)																// prekini zanko, �e vtipka� rojstni datum :)
			break;
		for (j = 0; j < ndigits; ++j)
		{
			digits[j] = c[i & ((1 << basebits) - 1)];									// izlo�anje (maskiranje) z 31 !!!  torej 1<<basebits je 1<<5 je 32 je binarno 10 0000. �e od�teje� 1, dobi� 1 1111, petbitna maska
			i = i >> basebits;															// za poljubno bazo dela� obi�ajno z funkcijo modulo po deljenju z bazo. �e je baza monogokratni 2^N, je dober tut binarni AND 
		}																				// cifro 5 x premakne� v desno in jovo na novo

		j = ndigits;																	// izpis mor� pa obrnt, ker grejo most significant najprej vun :)
		while (j--) {
			cout << char(digits[j]);
		}
	}
	return 0;
}


