#include <iostream>
#include <windows.h>
using namespace std;

char mappa[7][8] = {
	"#1#3#5#",
	"1 | | #",
	"#-----#",
	"3 | | #",
	"#-----#",
	"5 | | #",
	"#######"
};

void StampaMappa()
{
	for (int i = 0; i < 7; i++)
		cout<<mappa[i]<<"\n";
}

void Aggiorna1(char mappa[][8])
{
	int x1, x2, c=0;

	do
	{
		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 8; j++)
			{
				if (mappa[i][j] == ' ')
					c++;
			}

		if (c != 0) //mappa non cmpleta
		{
		errore: //flag goto
			cout << "\nInserisci le coordinate x e y di una casella vuota: ";
			cin >> x1 >> x2;

			if (mappa[x1][x2] == 'X' || mappa[x1][x2] == '0')
			{
				cout << "\n\aHai inseirito le coordinate di una casella gia' occupata! Inserisci delle nuove coordinate!\n";
				goto errore;
			}

			if (x1 > 0 && x1 <= 5 && x2 > 0 && x2 <= 5)
			{
				if (x1 == 2 || x1 == 4)
				{
					cout << "\n\aHai inserito le coordinarte di una casella non modificabile! Inserisci delle nuove coordinate!\n";
					goto errore;
				}

				if (mappa[x1][x2] == ' ' && mappa[x1][x2] != '0')
					mappa[x1][x2] = 'X';
			}
		}
		else
		{
			cout << "\nNon ha vinto nessuno dei due giocatori!!!\n";
			break; //se la tabella è piena esce dal ciclo
		}

	} while (x1 < 1 || x1>5 || x2 < 1 || x2>5);

	StampaMappa();
}

void Aggiorna2(char mappa[][8])
{
	int x1, x2, c=0;

	do
	{
		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 8; j++)
			{
				if (mappa[i][j] == ' ')
					c++;
			}

		if (c != 0) //mappa non cmpleta
		{
		errore: //flag goto
			cout << "\nInserisci le coordinate x e y di una casella vuota: ";
			cin >> x1 >> x2;

			if (mappa[x1][x2] == '0' || mappa[x1][x2] == 'X')
			{
				cout << "\n\aHai inseirito le coordinate di una casella gia' occupata! Inserisci delle nuove coordinate!\n";
				goto errore;
			}

			if (x1 > 0 && x1 <= 5 && x2 > 0 && x2 <= 5)
			{
				if (x1 == 2 || x2 == 4)
				{
					cout << "\n\aHai inserito le coordinarte di una casella non modificabile! Inserisci delle nuove copordinate!\n";
					goto errore;
				}

				if (mappa[x1][x2] == ' ' && mappa[x1][x2] != 'X')
					mappa[x1][x2] = '0';
			}
		}
		else
		{
			cout << "\nNon ha vinto nessuno dei due giocatori!!!\n";
			break; //se la tabella è piena esce dal ciclo
		}

	}while (x1 < 1 || x1>5 || x2 < 1 || x2>5);

	StampaMappa();
}

int Vittoria(char mappa[][8])
{	//casisitche giocatore1			//riga1														//riga2																	//riga3																		//colonna1													//colonna2															//colonna3																	//diag1															//diag2
	if ((mappa[1][1] == 'X' && mappa[1][3] == 'X' && mappa[1][5] == 'X') || (mappa[3][1] == 'X' && mappa[3][3] == 'X' && mappa[3][5] == 'X') || (mappa[5][1] == 'X' && mappa[5][3] == 'X' && mappa[5][5] == 'X') || (mappa[1][1] == 'X' && mappa[3][1] == 'X' && mappa[5][1] == 'X') || (mappa[1][3] == 'X' && mappa[3][3] == 'X' && mappa[5][3] == 'X') || (mappa[1][5] == 'X' && mappa[3][5] == 'X' && mappa[5][5] == 'X') || (mappa[1][1] == 'X' && mappa[3][3] == 'X' && mappa[5][5] == 'X') || (mappa[5][1] == 'X' && mappa[3][3] == 'X' && mappa[1][5] == 'X'))
		return 1;	//casistiche giocatore2 //riga1													//riga2																	//riga3																		//colonna1													//colonna2															//colonna3																	//diag1															//diag2
	else if ((mappa[1][1] == '0' && mappa[1][3] == '0' && mappa[1][5] == '0') || (mappa[3][1] == '0' && mappa[3][3] == '0' && mappa[3][5] == '0') || (mappa[5][1] == '0' && mappa[5][3] == '0' && mappa[5][5] == '0') || (mappa[1][1] == '0' && mappa[3][1] == '0' && mappa[5][1] == '0') || (mappa[1][3] == '0' && mappa[3][3] == '0' && mappa[5][3] == '0') || (mappa[1][5] == '0' && mappa[3][5] == '0' && mappa[5][5] == '0') || (mappa[1][1] == '0' && mappa[3][3] == '0' && mappa[5][5] == '0') || (mappa[5][1] == '0' && mappa[3][3] == '0' && mappa[1][5] == '0'))
		return 2;
	else
		return 0;
}

bool MappaCompleta(char mappa[][8]) //funzione chiamata solo nella main
{
	int c=0;

	for(int i=0; i<7; i++)
		for (int j=0; j < 8; j++)
		{
			if (mappa[i][j] == ' ')
				c++;
		}
	if (c == 0)
		return true; //mappa completa
	else
		return false; //mappa non completa
}

void Pulisci(char mappa[][8])
{
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 8; j++)
		{
			if (mappa[i][j] != ' ')
				mappa[i][j] = ' ';
		}
}

int main()
{
	int x;
	
	inizio:
	system("cls");

	StampaMappa();

	while (Vittoria(mappa) == 0 && MappaCompleta(mappa) == false) //gioco non finito (no output risultati)
	{
		cout << "\nGiocatore 1:\n";
		Aggiorna1(mappa);

		cout << "\nGiocatore 2:\n";
		Aggiorna2(mappa);
	}

	system("cls"); 

	//gioco finito 
	if (Vittoria(mappa) == 1)
		cout << "\n\aHa vinto il giocatore 1!!!\n"; //in caso di vittoria certa del primo utente è comunque necessario l'input del secondo utente
	else if (Vittoria(mappa) == 2)
		cout << "\n\aCongratulazioni ha vinto il giocatore 2!!!\n";
	
	if (MappaCompleta(mappa) == true)
		cout << "\nNon ha vinto nessuno dei due giocatori!!!\n";
		
	cout<<"\nSi vuole giocare ancora? (Se si inserire 0) ";
	cin>>x;
	
	if (x == 0)
	{
		Pulisci(mappa);
		goto inizio;
	}
	else
		cout << "\n\aGRazie per aver giocato al nostro gioco!";

	return 0;
}
