#include "Dna.h"

Dna::Dna(string _name, string _dna)
{
	char* chars = new char[_dna.length() + 1];

	name = _name;
	dna = _dna;

	convertToCharArray(_dna, chars);

	hight += chars[0] + chars[1] + chars[2] + chars[3];
	width += chars[4] + chars[5] + chars[6] + chars[7];
	color += chars[8] + chars[9] + chars[10] + chars[11] + chars[12] + chars[13] + chars[14] + chars[15];
	form += chars[16] + chars[17] + chars[18] + chars[19];

	stamina += chars[20] + chars[21] + chars[22] + chars[23];
	growthRate += chars[24] + chars[25] + chars[26] + chars[27];
	sustainability += chars[28] + chars[29] + chars[30] + chars[31];
	fragrance += chars[32] + chars[33] + chars[34] + chars[35];

	delete[] chars;
}
string Dna::GetColorDna()
{
	string sum;
	char* chars = new char[dna.length() + 1];
	Debug debug;
	convertToCharArray(dna, chars);
	for (int i = 0; i < 36; i++)
	{
		if (chars[i] == 'A')
		{
			sum += debug.InsertCyan(string(1, chars[i]));
		}
		else if (chars[i] == 'T')
		{
			sum += debug.InsertGreen(string(1, chars[i]));
		}
		else if (chars[i] == 'C')
		{
			sum += debug.InsertYellow(string(1, chars[i]));
		}
		else if (chars[i] == 'G')
		{
			sum += debug.InsertRed(string(1, chars[i]));
		}
		else
		{
			sum += string(1, chars[i]);
		}
	}
	delete[] chars;
	return debug.InsertMagenta(name) + ": " + sum;
}
