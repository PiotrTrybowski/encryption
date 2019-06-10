#include <iostream>
#include <string>
using namespace std;



char cesar(int litera, int stala)
{
	int po_zakodowaniu;
	po_zakodowaniu = litera + stala;
	if (po_zakodowaniu > 122)
	{
		po_zakodowaniu -= 26;
	}
	return po_zakodowaniu;
}

char AtBash(int litera)
{
	int po_zakodowaniu = 0;
	int od_poczatku = -(litera - 97);
	int koniec = 122;
	_asm {
		finit
		fld DWORD PTR koniec
		fld DWORD PTR od_poczatku
		fadd st(1), st(0)
		fxch st(1)
		fstp DWORD PTR po_zakodowaniu
		fwait
	}
	return po_zakodowaniu;

}



char cesar_asm(int litera, int stala)
{
	int po_zakodowaniu =0;
	_asm {
	finit
	fld DWORD PTR litera
	fld DWORD PTR stala
	fadd st(1), st(0)
	fxch st(1)
	fstp DWORD PTR po_zakodowaniu
	fwait
	}
	if (po_zakodowaniu > 122)
	{
		po_zakodowaniu -= 26;
	}
	return po_zakodowaniu;
}

char AtBash_asm(int litera)
{
	int po_zakodowaniu = 0;
	int od_poczatku = litera - 97;
	po_zakodowaniu = 122 - od_poczatku;
	return po_zakodowaniu;
}


int main()
{
	cout << "wybierz metodę kodowania:" << endl << "1: Szyfr Cezara" << endl << "2: Szyfr AtBash"<<endl;
	int ktory_szyfr;
	cin >> ktory_szyfr;
	if (ktory_szyfr == 1)
	{
		cout << "podaj stałą (0-26)";
		int stala;
		cin >> stala;
		cout << "podaj ciąg liter do zaszyfrowania" << endl;
		string input;
		string output;
		cin >> input;
		int length = input.length();
		for (int i = 0; i < length; i++)
		{
			output += cesar_asm(input[i], stala);
		}
		cout << output<<endl;
		return 0;
	}
	if (ktory_szyfr == 2)
	{
		cout << "podaj ciąg liter do zaszyfrowania"<<endl;
		string input;
		string output;
		cin >> input;
		int length = input.length();
		for (int i = 0; i < length; i++)
		{
			output += AtBash_asm(input[i]);
		}
		cout << output << endl;
	}
	else
	{
		cout << "nie ma takiego kodu";
		main();
	}

	return 0;
}