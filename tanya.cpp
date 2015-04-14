// tanya.cpp: определяет точку входа для консольного приложения.
//
// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;
//char caesar(char c, int n);
char caesar(char c, int n)
{
	if (isalpha(c))
	{
		c = toupper(c);
		c = (((c - 65) + n) % 26) + 65;
	}
	return c;
}

int main(int argc, char* argv[])
{
	string s;
	int *mas = NULL;
	int tmp, sdv;
	tmp=atoi(argv[1]);
	ifstream in(argv[2]);
	
	
	switch (tmp)
	{
	case 1:
	{
		sdv = atoi(argv[3]);
		getline(in, s);
		string snew = "";
		for (int x = 0; x < s.length(); x++)
		{
			snew += caesar(s[x], sdv);
		}
		cout << snew << endl;
		break;
	}
	case 2:
	{
		string key = (argv[3]);
		getline(in, s);
		int slen = s.length();
		int klen = key.length();
		string keynew = "";
		if (slen > klen)
		{
			for (int i = 0; i < (slen / klen); i++)
			{
				keynew = keynew + key;
			}
			for (int j = 0; j < (slen %klen); j++)
			{
				keynew = keynew + key[j];
			}
		}
		else
		{
			for (int i = 0; i < slen; i++)
			{
				keynew = keynew + key[i];
			}
		}
		string snew = "";
		mas = new int[slen];
		for (int x = 0; x < slen; x++)
		{
			keynew[x] = toupper(keynew[x]);
			mas[x] = keynew[x] - 65;
		}
		for (int x = 0; x < slen; x++)
		{
			snew += caesar(s[x], mas[x]);
		}
		cout << snew << endl;
		break;
		break;
	}
	default:
		break;

	}

}
