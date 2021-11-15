// Exercise 1.5 – Base 32 printing of integers
//

#include "stdafx.h"
#include <iostream> 

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char c[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUV"};									// string (array karakterjev, isti qrac) za preslikavo z indeksom, temu se reèe "lookup table"

	unsigned int basebits = 5;															// base 32 rabi 5 bitov, od 0 do 31... lahko poskusš prevest tut z 1(binarno), 3(oct) ali 4(hex)
	unsigned int ndigits = (8 * sizeof(unsigned int) + basebits - 1) / basebits;		// sizeof(int) vrne 4(byte), 32 bitna cifra paè... finta z basebits - 1 je zato, da zaokroži navzgor, ker 32/5 se ne izide in rabš še eno polje
	short *digits = new short[ndigits]{};												// alokacija in brisanje na 0 z {}

	while (1) {																			// neskonèna zanka
		cout << endl << "enter value:" ;												// vpis
		unsigned int i,j;
		cin >> i;
		if (i == 101198)																// prekini zanko, èe vtipkaš rojstni datum :)
			break;
		for (j = 0; j < ndigits; ++j)
		{
			digits[j] = c[i & ((1 << basebits) - 1)];									// izloèanje (maskiranje) z 31 !!!  torej 1<<basebits je 1<<5 je 32 je binarno 10 0000. èe odšteješ 1, dobiš 1 1111, petbitna maska
			i = i >> basebits;															// za poljubno bazo delaš obièajno z funkcijo modulo po deljenju z bazo. Èe je baza monogokratni 2^N, je dober tut binarni AND 
		}																				// cifro 5 x premakneš v desno in jovo na novo

		j = ndigits;																	// izpis morš pa obrnt, ker grejo most significant najprej vun :)
		while (j--) {
			cout << char(digits[j]);
		}
	}
	return 0;
}


