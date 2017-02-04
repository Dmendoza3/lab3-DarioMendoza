#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> 
#include <time.h>

using namespace std;

int menu();

void minesweeper();

void balanceCorchetes();

int main()
{
	bool menuB = true;
	while(menuB)
	{	
		switch(menu())
		{
			case 1:
				minesweeper();
				break;
			case 2:
				balanceCorchetes();
				break;
			case 0:
				menuB = false;
				break;
			default:
				cout << "No existe esa opcion.\n";
				break;
		}	
	}
	return 0;
}

int menu()
{
        cout << "1- Ejercicio 1" << endl
        <<      "2- Ejercicio 2" << endl
	<<	"0- Salir" << endl
        <<      "Ingrese la opcion: " << endl;

        int op;
        cin >> op;

        return op;
}


void printTable(int***, int);

bool checkTable(int*** table, int posx, int posy,int size)
{
	if (table[posx][posy][1] == 9)
		return true;

	if(table[posx][posy][0] == 0)
	//retorna true si es una mina
{
	table[posx][posy][0] = 1;
	if(posx == 0 && posy == 0)
	{
		if(checkTable(table, posx + 1, posy, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx + 1, posy + 1, size))	
			table[posx][posy][1]++;
		if(checkTable(table, posx, posy + 1, size))
			table[posx][posy][1]++;
	}
	
	if(posx == size - 1 && posy == 0)
	{
		if(checkTable(table, posx - 1, posy, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx - 1, posy + 1, size))	
			table[posx][posy][1]++;
		if(checkTable(table, posx, posy + 1, size))
			table[posx][posy][1]++;
	}
	
	if(posx == 0 && posy == size - 1)
	{
		if(checkTable(table, posx + 1, posy, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx + 1, posy - 1, size))	
			table[posx][posy][1]++;
		if(checkTable(table, posx, posy - 1, size))
			table[posx][posy][1]++;
	}

	if(posx == size - 1 && posy == size - 1)
	{
		if(checkTable(table, posx - 1, posy, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx - 1, posy - 1, size))	
			table[posx][posy][1]++;
		if(checkTable(table, posx, posy - 1, size))
			table[posx][posy][1]++;
	}
	
	if(posx == 0 && posy != 0 && posy != size - 1)
	{
		
		if(checkTable(table, posx, posy - 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx + 1, posy - 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx + 1, posy, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx + 1, posy + 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx, posy + 1, size))
			table[posx][posy][1]++;
	}
	
	if(posx == size - 1 && posy != 0 && posy != size - 1)
	{
		
		if(checkTable(table, posx, posy - 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx - 1, posy - 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx - 1, posy, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx - 1, posy + 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx, posy - 1, size))
			table[posx][posy][1]++;
	}

	if(posy == 0 && posx != 0 && posx != size - 1)
	{
		
		if(checkTable(table, posx - 1, posy, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx - 1, posy + 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx, posy + 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx + 1, posy + 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx + 1, posy, size))
			table[posx][posy][1]++;
	}

	
	if(posy == size - 1 && posx != 0 && posx != size - 1)
	{
		
		if(checkTable(table, posx - 1, posy, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx - 1, posy - 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx, posy - 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx + 1, posy - 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx + 1, posy, size))
			table[posx][posy][1]++;
	}

	if(posx > 0 && posx < size - 1 && posy > 0 && posy < size -1)
	{
		if(checkTable(table, posx - 1, posy - 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx - 1, posy, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx - 1, posy + 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx, posy + 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx + 1, posy + 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx + 1, posy, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx + 1, posy - 1, size))
			table[posx][posy][1]++;
		if(checkTable(table, posx, posy - 1, size))
			table[posx][posy][1]++;
	}
	printTable(table,size);
	cout << "\n\n";
}
	return false;
}

void printTable(int*** table, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (table[i][j][0] == 1)
				cout <<"[" <<table[i][j][1] << "]";
			else
				cout << "[ ]";
		}
		cout << endl;
	}
}

void minesweeper()
{
	//Pedir el tamaño
	int n = 0, nMines = 0;
	
	while (n < 9){
		cout << "Ingrese el espacio del tablero: ";	
		cin >> n;
	}
	
	while (nMines < 1){
		cout << "Ingrese el numero de minas:";
		cin >> nMines;
	}

	//Hacer matriz
	int*** table = 0;
	table = new int**[n];
	for (int i = 0; i < n; i++){
		table[i] = 0;
		table[i] = new int*[n];
		for (int j = 0; j < n; j++){
			table[i][j] = 0;
			table[i][j] = new int[2];
		}
	}

	//Juego******************************************************************
	//
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			table[i][j][0] = 0;
			table[i][j][1] = 0;
		}
	
	srand ((unsigned)time(NULL));
	
	while(nMines > 0)
	{
		int rx = rand() % n,
		    ry = rand() % n;

		if (table[rx][ry][1] == 0){
			table[rx][ry][1] = 9;
			nMines--;
		}
	}
	
	printTable(table,n);
	
	bool game = true;
	while(game)
	{
		int row,col;
		cout << "Ingrese la posicion a leer: ";
		cin >> row >> col;

		if (table[row][col][1] == 9)
			game = false;
		else
			checkTable(table,row,col,n);

		printTable(table,n);
	}
	cout << "Fin del juego.\n";
	
	//Fin juego*************************************************************

	//Liberar espacio
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			delete[] table[i][j];
			table[i][j] = NULL;
		}	
		delete[] table[i];
	
		table[i] = NULL;
	}

	delete[] table;
}

bool validarCadena(char* val)
{
	for(int i = 0; i < 20; i++)
		if(val[i] == '{' && val[i] == '}'
		&& val[i] == '[' && val[i] == ']'
		&& val[i] == '(' && val[i] == ')')
			return true;
	return false;
}

bool balance(char* val)
{
	
	int cP = 0, cC = 0, cL = 0;
	
	for(int i = 0; i < 20; i++)
	{
		if(val[i] == '}')
			cL++;
		if(val[i] == '}')
			cL--;
		if(val[i] == '[')
			cC++;
		if(val[i] == ']')
			cC--;
		if(val[i] == '(')
			cP++;
		if(val[i] == ')')
			cP--;
	}
	if(cL == 0 && cC == 0 && cP == 0)
		return true;
	return false;
}

void balanceCorchetes()
{
	char cadena[20];
	do{
		cout << "Ingrese la cadena: ";
		cin >> cadena;
	}while(validarCadena(cadena));
	
	if(balance(cadena))
		cout << "La secuencia esta balanceada.\n";
	else
		cout << "La secuencia no esta balanceada.\n";
}
