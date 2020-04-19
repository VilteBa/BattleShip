#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib> 
#include <stdlib.h> 
#include <unistd.h>
#include "pabaiga.h"
#include <vector>
using namespace std;

void pabaiga();

class bazine
{
public:
	virtual void virt1() = 0;
	virtual void virt2() = 0;

};

class pirma : public bazine
{
public:
	void virt2()
	{
		cout << "..";
	}
};

class trecia
{
private:
	int nn = 1;
	void operator +(trecia a)
	{
		cout << nn + a.nn;
	}
};

class lentele
{
private:
	vector <int> laivv;
	char l[10][10];
	int  op, kieklaivu = 10, eile, stul, x, zzz = 0, z, kk = 1, pat = 0, pat1 = -1, pat2 = -1, kryp = 0, kiek[5]{ 0,0,0,0 };
	char kryptis, raide, y = 5;
	//. reiskia tuscia vieta
	//x pataikytas laivas, XX pilnai sunaikintas laivas
	//# mano laivas
	//* prasauta vieta

public:
	//KONSTRUKTORIUS BE ARG
	lentele()//lenteles kurimas
	{
		for (int i = 0; i<10; i++)
			for (int j = 0; j<10; j++)
				l[i][j] = '.';
	}

	void len()  //lenteles spausdinimas
	{
		cout << endl << "   A B C D E F G H I J" << endl;
		for (int i = 0; i<10; i++)
		{
			cout << i + 1 << " ";
			if (i != 9) cout << " ";
			for (int j = 0; j<10; j++)
			{
				if (l[i][j] == 'x')
					cout << "\033[38;5;9m" << l[i][j] << "\033[0m" << " ";
				else if (l[i][j] == 'X')
					cout << "\033[38;5;124m" << l[i][j] << "\033[0m" << " ";
				else  if (l[i][j] == 'o')
					cout << "\033[38;5;176m" << l[i][j] << "\033[0m" << " ";
				else  if (l[i][j] == '#')
					cout << "\033[38;5;14m" << l[i][j] << "\033[0m" << " ";
				else
					cout << l[i][j] << " ";
			}
			cout << endl;
		}
	}

	//////////////////////RANDOM IVEDIMAS
	void randomivedimas()
	{
		for (int i = 4; i>0; i--)
		{
			for (int j = 0; j<(5 - i); j++)
			{
				int kiek = 0;
				eile = rand() % 10 + 1;
				stul = rand() % 10 + 1;
				kryptis = rand() % 10 + 1;

				if (kryptis <= 5)
					kryptis = 'D';
				else
					kryptis = 'A';
				//cout<<eile<<" "<<stul<<" "<<kryptis<<endl;
				if (kryptis == 'D' && (stul + i - 1) <= 10)
				{
					for (int x = eile - 1; x <= eile + 1; x++)
						for (int z = stul - 1; z<(stul + i + 1); z++)
						{
							if (l[x - 1][z - 1] != '#')
								kiek++;
						}//cout<<kiek<<" "<<(i+2)*3<<"  j"<<j<<endl;
					if (kiek == (i + 2) * 3)
					{
						for (int z = stul; z<(stul + i); z++)
							l[eile - 1][z - 1] = '#';
					}
					else
						j--;
				}
				else if (kryptis == 'A' && (eile + i - 1) <= 10)
				{
					for (int x = stul - 1; x <= stul + 1; x++)
						for (int z = eile - 1; z<eile + i + 1; z++)
						{
							if (l[z - 1][x - 1] != '#')
								kiek++;
						}//cout<<kiek<<" "<<(i+2)*3<<"  j"<<j<<endl;
					if (kiek == (i + 2) * 3)
					{
						for (int z = eile; z<eile + i; z++)
							l[z - 1][stul - 1] = '#';
					}
					else
						j--;
				}
				else
					j--;
			}
		}
	}

	//////////////////////RANKINIS IVEDIMAS
	void operator ++()//ivedimas
	{
		cout << "\033[2J\033[1;1H";
		cout << "Išdėstykite savo laivus" << endl;
		for (int i = 4; i>0; i--)
		{
			for (int j = 0; j<(5 - i); j++)
			{
				len();
				int kiek = 0;

				cout << endl << "Nurodykite kordinates, kur bus jūsų " << i << "-ietis laivas ir kryptį (D-desine, A-apacia)?" << endl;

				cin >> eile >> raide >> kryptis;
				cout << "\033[2J\033[1;1H";
				raide = toupper(raide);
				kryptis = toupper(kryptis);
				stul = raide - 64;
				while (!cin)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Nurodėte blogas koordinatesgg" << endl;
				}

				cout << "\033[2J\033[1;1H";
				if (kryptis == 'D' && (stul + i - 1) <= 10)
				{
					for (int x = eile - 1; x <= eile + 1; x++)
						for (int z = stul - 1; z<(stul + i + 1); z++)
						{
							if (l[x - 1][z - 1] != '#' || (x - 1)>9 || (x - 1)<0 || (z - 1)>9 || (z - 1)<0)
							{
								kiek++;
							}
						}
					if (kiek == (i + 2) * 3)
					{
						for (int z = stul; z<(stul + i); z++)
							l[eile - 1][z - 1] = '#';
					}
					else
					{
						cout << endl << "Nurodėte blogas koordinates" << endl;
						j--;
					}
				}
				else if (kryptis == 'A' && (eile + i - 1) <= 10)
				{
					for (int x = eile - 1; x <= eile + i; x++)
						for (int z = stul - 1; z <= stul + 1; z++)
						{
							if (l[x - 1][z - 1] != '#' || x - 1 >= 10 || x <= 0 || z - 1 >= 10 || z <= 0)
								kiek++;
						}
					if (kiek == (i + 2) * 3)
					{
						for (int z = eile; z<eile + i; z++)
							l[z - 1][stul - 1] = '#';
					}
					else
					{
						cout << endl << "Nurodėte blogas koordinates" << endl;
						j--;
					}
				}
				else
				{
					cout << endl << "Nurodėte blogas koordinates" << endl;
					j--;
				}
			}
		}
		cout << endl << "Jūsų lentelė pilnai užildyta" << endl;
	}

	//////////////////KOMPIUTERIO SAUDYMAS
	void priesosuvis(lentele A)
	{
		if (pat == 0)
		{
			x = rand() % 10 + 1;
			z = rand() % 10 + 1;
			if (l[x - 1][z - 1] == '.')
			{
				priesasnepataike(A, x - 1, z - 1);
			}
			else if (l[x - 1][z - 1] == 'o' || l[x - 1][z - 1] == 'x' || l[x - 1][z - 1] == 'X')
			{
				priesosuvis(A);
			}
			else if (l[x - 1][z - 1] == '#')
			{
				cout << "\033[2J\033[1;1H";
				cout << "Priešininkas pataikė :(" << endl;
				l[x - 1][z - 1] = 'x';
				pat1 = x - 1;
				pat2 = z - 1;
				pat = 1;
				if (arsunaikintaslaivas(l, x - 1, z - 1) != 1)
				{
					pat = 0;
					kieklaivu--;
					cout << "Ir sunaikino visą laivą!" << endl;
					sunaikintaslaivas(l, x - 1, z - 1, 0);

				}
				cout << endl << endl << "Priešininko lentelė:" << endl;
				A.len();
				cout << endl << endl << "Mano lentelė:" << endl;
				len();
				sleep(2);
				priesosuvis(A);
			}
		}
		else if (pat == 1)
		{
			sekantissuvis(A, pat1, pat2);
		}

	}

	void kryptis0(lentele A) // <------------->
	{
		//int kk, *kkk;
		//kkk=&kk;
		//*kkk=1;

		x = pat1;
		z = pat2;
		if (kk != 0)
			while (l[x][z - 1] == '#' && z - 1 >= 0 && kk != 0) // <-
			{
				cout << "\033[2J\033[1;1H";
				cout << "Priešininkas pataikė :(" << endl;
				l[x][z - 1] = 'x';
				if (arsunaikintaslaivas(l, x, z - 1) != 1)
				{
					kieklaivu--;
					cout << "Ir sunaikino visą laivą!" << endl;
					sunaikintaslaivas(l, x, z - 1, 0);
					pat = 0;
				}
				else
					cout << endl;
				cout << endl << "Priešininko lentelė:" << endl;
				A.len();
				cout << endl << endl << "Mano lentelė:" << endl;
				len();
				sleep(2);
				if (pat == 0 && kk != 0)
				{
					priesosuvis(A);
					kk = 0;
				}
				z--;
			}
		if (l[x][z - 1] == '.' && z - 1 >= 0 && kk != 0) // <-
		{
			priesasnepataike(A, x, z - 1);
		}
		else // ->
		{
			x = pat1;
			z = pat2;
			while (l[x][z + 1] == '#' && z + 1<10 && kk != 0) // ->
			{
				cout << "\033[2J\033[1;1H";
				cout << "Priešininkas pataikė :(" << endl;
				l[x][z + 1] = 'x';
				if (arsunaikintaslaivas(l, x, z + 1) != 1)
				{
					kieklaivu--;
					cout << "Ir sunaikino visą laivą!" << endl;
					sunaikintaslaivas(l, x, z + 1, 0);
					pat = 0;
				}
				else
					cout << endl;
				cout << endl << "Priešininko lentelė:" << endl;
				A.len();
				cout << endl << endl << "Mano lentelė:" << endl;
				len();
				sleep(2);
				if (pat == 0 && kk != 0)
				{
					priesosuvis(A);
					kk = 0;
				}
				z++;
			}
			if (pat == 1 && kk != 0)
			{
				if (l[x][z + 1] == '.' && z + 1<10)
				{
					priesasnepataike(A, x, z + 1);
				}
				else
					if (kk != 0)
						kryptis1(A);
			}
		}
	}

	void kryptis1(lentele A)// |||||
	{
		x = pat1;
		z = pat2;
		if (kk != 0)
			while (l[x - 1][z] == '#' && x - 1 >= 0 && kk != 0)
			{
				cout << "\033[2J\033[1;1H";
				cout << "Priešininkas pataikė :(" << endl;
				l[x - 1][z] = 'x';
				if (arsunaikintaslaivas(l, x - 1, z) != 1)
				{
					kieklaivu--;
					cout << "Ir sunaikino visą laivą!" << endl;
					sunaikintaslaivas(l, x - 1, z, 0);
					pat = 0;
				}
				else
					cout << endl;
				cout << endl << "Priešininko lentelė:" << endl;
				A.len();
				cout << endl << endl << "Mano lentelė:" << endl;
				len();
				sleep(2);
				if (pat == 0)
				{
					priesosuvis(A);
					kk = 0;
				}
				x--;
			}
		if (l[x - 1][z] == '.' && x - 1 >= 0 && kk != 0)
		{
			priesasnepataike(A, x - 1, z);
		}
		else
		{
			x = pat1;
			z = pat2;
			if (kk != 0)
				while (l[x + 1][z] == '#' && x + 1<10)
				{
					cout << "\033[2J\033[1;1H";
					cout << "Priešininkas pataikė :(" << endl;
					l[x + 1][z] = 'x';
					if (arsunaikintaslaivas(l, x + 1, z) != 1)
					{
						kieklaivu--;
						cout << "Ir sunaikino visą laivą!" << endl;
						sunaikintaslaivas(l, x + 1, z, 0);
						pat = 0;
					}
					else
						cout << endl;
					cout << endl << "Priešininko lentelė:" << endl;
					A.len();
					cout << endl << endl << "Mano lentelė:" << endl;
					len();
					sleep(2);
					if (pat == 0 && kk != 0)
					{
						priesosuvis(A);
						kk = 0;
					}
					x++;
				}
			if (pat == 1)
			{
				if (l[x + 1][z] == '.' && x + 1<10)
				{
					priesasnepataike(A, x + 1, z);
				}
				else
					if (kk != 0)
						kryptis0(A);
			}
		}
	}

	void sekantissuvis(lentele A, int x, int z)
	{
		kk = 1;
		kryptis = rand() % 2;
		pat1 = x;
		pat2 = z;
		pat = 1;
		if (kryptis == 0)//  <-
		{
			kryptis0(A);
		}
		else if (kryptis == 1)
		{
			kryptis1(A);
		}
	}

	void priesasnepataike(lentele A, int x, int z)
	{
		cout << "\033[2J\033[1;1H";
		cout << "Priešininkas nepataikė :)" << endl;
		l[x][z] = 'o';
		cout << endl << endl << "Priešininko lentelė:" << endl;
		A.len();
		cout << endl << endl << "Mano lentelė:" << endl;
		len();
	}

	///////////ZAIDEJO SAUDYMAS
	void manosuvis(lentele A, lentele & B)
	{
		cout << endl << "Pasirinkite taikinio koordinates" << endl;
		cin >> x >> y;
		cout << endl;
		y = toupper(y);
		z = y - 64;
		while (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
		}

		cout << "\033[2J\033[1;1H";
		if (x>0 && x <= 10 && z>0 && z <= 10)
		{
			if (l[x - 1][z - 1] == '.')
			{
				cout << "Dėja nepataikėte" << endl << endl << endl;
				l[x - 1][z - 1] = 'o';
				B.l[x - 1][z - 1] = 'o';
				cout << "Priešininko lentelė:" << endl;
				B.len();
				cout << endl << endl << "Mano lentelė:" << endl;
				A.len();
				sleep(1);
			}
			else if (l[x - 1][z - 1] == '#')
			{
				cout << "Pataikėte!  ";
				l[x - 1][z - 1] = 'x';
				B.l[x - 1][z - 1] = 'x';

				if (arsunaikintaslaivas(l, x - 1, z - 1) != 1)
				{
					kieklaivu--;
					cout << "Ir sunaikinote visą laivą!";
					sunaikintaslaivas(l, x - 1, z - 1, 1);
					sunaikintaslaivas(l, x - 1, z - 1, 1);
					sunaikintaslaivas(B.l, x - 1, z - 1, 1);
					sunaikintaslaivas(B.l, x - 1, z - 1, 1);
				}
				else
					cout << endl;
				cout << "Šaukite dar kartą" << endl << endl;
				cout << "Priešininko lentelė:" << endl;
				B.len();
				cout << endl << endl << "Mano lentelė:" << endl;
				A.len();
				manosuvis(A, B);
			}
			else
			{
				cout << "Čia jau šovėte" << endl << endl;
				cout << endl << "Priešininko lentelė:" << endl;
				B.len();
				cout << endl << endl << "Mano lentelė:" << endl;
				A.len();
				manosuvis(A, B);
			}
		}
		else
		{
			cout << "Koordinatės negalimos" << endl << endl << endl;
			cout << "Priešininko lentelė:" << endl;
			B.len();
			cout << endl << endl << "Mano lentelė:" << endl;
			A.len();
			manosuvis(A, B);
		}
	}
	///////////////////TIKRINIMAS AR LAIVAS PILNAI SUNAIKINTAS
	int arsunaikintaslaivas(char M[][10], int a, int b)
	{
		int v = 2, z = 2, d = 2, k = 2;
		for (int i = 1; i <= 4; i++)
		{
			if (a + i >= 0 && a + i<10)
			{
				if (M[a + i][b] == '.' || M[a + i][b] == 'o')
				{
					i = 5;
					v = 0;
					break;
				}
				if (M[a + i][b] == '#')
				{
					i = 5;
					v = 1;
				}
			}
		}
		for (int i = 1; i <= 4; i++)
		{
			if (a - i >= 0 && a - i<10)
			{
				if (M[a - i][b] == '.' || M[a - i][b] == 'o')
				{
					i = 5;
					z = 0;
					break;
				}
				if (M[a - i][b] == '#')
				{
					i = 5;
					z = 1;
				}
			}
		}
		for (int i = 1; i <= 4; i++)
		{
			if (b + i >= 0 && b + i<10)
			{
				if (M[a][b + i] == '.' || M[a][b + i] == 'o')
				{
					i = 5;
					d = 0;
					break;
				}
				if (M[a][b + i] == '#')
				{
					i = 5;
					d = 1;
				}
			}

		}
		for (int i = 1; i <= 4; i++)
		{
			if (b - 1 >= 0 && b - 1<10)
			{
				if (M[a][b - i] == '.' || M[a][b - i] == 'o')
				{
					i = 5;
					k = 0;
					break;
				}
				if (M[a][b - i] == '#')
				{
					i = 5;
					k = 1;
				}
			}
		}
		if (z == 1 || v == 1 || d == 1 || k == 1)
			return 1;
		else
			return 0;
	}
	///////////////////SUNAIKINTO LAIVO SIMBOLIU KEITIMAS
	void sunaikintaslaivas(char M[][10], int a, int b, int c)
	{
		M[a][b] = 'X';
		if (M[a][b - 1] == '.' && b - 1 >= 0)
			M[a][b - 1] = 'o';
		if (M[a][b + 1] == '.' && b + 1<10)
			M[a][b + 1] = 'o';
		if (M[a - 1][b] == '.' && a - 1 >= 0)
			M[a - 1][b] = 'o';
		if (M[a + 1][b] == '.' && a + 1<10)
			M[a + 1][b] = 'o';

		if (M[a - 1][b - 1] == '.' && b - 1 >= 0 && a - 1 >= 0)
			M[a - 1][b - 1] = 'o';
		if (M[a + 1][b + 1] == '.' && b + 1<10 && a + 1<10)
			M[a + 1][b + 1] = 'o';
		if (M[a - 1][b + 1] == '.' && a - 1 >= 0 && b + 1<10)
			M[a - 1][b + 1] = 'o';
		if (M[a + 1][b - 1] == '.' && b - 1 >= 0 && a + 1<10)
			M[a + 1][b - 1] = 'o';

		if (M[a][b - 1] == 'x')
			sunaikintaslaivas(M, a, b - 1, c);
		else if (M[a][b + 1] == 'x')
			sunaikintaslaivas(M, a, b + 1, c);
		else if (M[a - 1][b] == 'x')
			sunaikintaslaivas(M, a - 1, b, c);
		else if (M[a + 1][b] == 'x')
			sunaikintaslaivas(M, a + 1, b, c);

		if (kieklaivu == 0)
		{
			pabaiga(c);
		}
	}
	~lentele()
	{}
};



int main()
{
	srand(time(0));
	string ats;
	lentele M, P1, P, kopija(M);
	int qq = 0;

	P.randomivedimas();

	while (ats != "T" && ats != "N" && ats != "t" && ats != "n")
	{
		cout << endl << "Jei norite kad jūsų laivai būtų išdėstyti automatiškai įveskite T, jeigu ne N" << endl;
		cin >> ats;
	}
	if (ats == "T" || ats == "t")
		M.randomivedimas();
	else
		++M;

	cout << "\033[2J\033[1;1H";
	cout << "Žaidimas prasideda" << endl;
	cout << endl << endl << "Priešininko lentelė:" << endl;
	P1.len();/////////////////////////////////////////////////////////////
	cout << endl << endl << "Mano lentelė:" << endl;
	M.len();

	while (true)
	{
		P.manosuvis(M, P1);/////////////////////////////////////////
		M.priesosuvis(P1);//////////////////////////////////////////
	}
}