#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int Rows, Coloumns;
double MenuChoice;
int Diagonal = 0;
int Player1Choice, Player2Choice;
int XCount1 = 0, XCount2 = 0, WinCheck = 0;
int a, b;
int WinCondition;
int c, d;
char Connect4[14][14];
char FileName[10000];


void TurnPlayer1() {

	cout << "Turn Player 1" << endl << endl;

	cout << "Enter the column to drop your ball (1 - " << Coloumns << "): ";
	cin >> Player1Choice;

	while (Player1Choice < 1 || Player1Choice > Coloumns) {
		cout << "Invalid input. Please try again." << endl;

		cout << " Enter the coloumn to drop your Mark : ";
		cin >> Player1Choice;
	}

	int EmptyRow1 = Rows - 1;



	if (Connect4[EmptyRow1][Player1Choice - 1] != '-') {

		while (Connect4[EmptyRow1][Player1Choice - 1] != '-') {
			EmptyRow1--;

			if (EmptyRow1 < 0) {
				cout << "\nThis coloumn is full! Please pick another: ";
				cin >> Player1Choice;

				EmptyRow1 = Rows - 1;
			}
		}

		Connect4[EmptyRow1][Player1Choice - 1] = 'X';
	}
	else {
		Connect4[EmptyRow1][Player1Choice - 1] = 'X';
	}
	EmptyRow1 = Rows;
	XCount1++;																						// PLAYER 1 DONE



	cout << endl << endl;
	for (int y = 0; y < Rows; y++) {

		for (int x = 0; x < Coloumns; x++) {                       // cout matrix

			cout << Connect4[y][x] << "  ";
		}
		cout << endl << endl;
	}

	for (int x = 1; x <= Coloumns; x++) {

		cout << x << "  ";                  // cout index

	}
	cout << endl << endl;

}

void TurnPlayer2() {

	cout << "Turn Player 2 " << endl << endl;

	cout << "Enter the coloumn to drop your ball (1 - " << Coloumns<< ") : ";
	cin >> Player2Choice;

	while (Player2Choice < 1 || Player2Choice > Coloumns) {
		cout << "Invalid input. Please try again." << endl;

		cout << "\n\nEnter the coloumn to drop your ball: ";
		cin >> Player2Choice;
	}

	int EmptyRow2 = Rows - 1;


	if (Connect4[EmptyRow2][Player2Choice - 1] != '-') {

		while (Connect4[EmptyRow2][Player2Choice - 1] != '-') {
			EmptyRow2--;

			if (EmptyRow2 < 0) {
				cout << "\nThis column is full! Please pick another: ";
				cin >> Player2Choice;

				EmptyRow2 = Rows - 1;
			}

		}
		Connect4[EmptyRow2][Player2Choice - 1] = 'O';
	}
	else {
		Connect4[EmptyRow2][Player2Choice - 1] = 'O';
	}


	EmptyRow2 = Rows;
	XCount2++;                                                             // PLAYER 2 DONE



	cout << endl << endl;
	for (int y = 0; y < Rows; y++) {

		for (int x = 0; x < Coloumns; x++) {               // cou t matrix

			cout << Connect4[y][x] << "  ";
		}
		cout << endl << endl;
	}


	for (int x = 1; x <= Coloumns; x++) {

		cout << x << "  ";                  // cout index

	}
	cout << endl << endl;

}

bool WinCheckMain(){

	int WinCheckMainer = 0;


	for (int y = 0; y < Rows; y++) {

		for (int x = 0; x < Coloumns; x++) {

			if (Connect4[y][x] == 'X') {                      // try both horizon and vertical check

				c = y;
				d = x;

				while (Connect4[c][d] == 'X') {
					d++;
					WinCheckMainer++;
				}

				if (WinCheckMainer == WinCondition) {

					return true;
				}

				else {
					c = y;
					d = x;
					WinCheckMainer = 0;
				}
																			//

				while (Connect4[c][d] == 'X') {
					c++;
					WinCheckMainer++;
				}

				if (WinCheckMainer == WinCondition) {
					return true;
				}

				else {
					c = y;
					d = x;
					WinCheckMainer = 0;
				}

																						//
				while (Connect4[c][d] == 'X') {
					d++;
					c++;
					WinCheckMainer++;
				}

				if (WinCheckMainer == WinCondition) {
					return true;
				}

				else {
					c = y;
					d = x;
					WinCheckMainer = 0;
				}

																								//
				while (Connect4[c][d] == 'X') {
					d--;
					c++;
					WinCheckMainer++;
				}

				if (WinCheckMainer == WinCondition) {
					return true;
				}

				else {
					c = y;
					d = x;
					WinCheckMainer = 0;
				}


			}

			// PLAYER 2 REALLL THIS TIME 'O' !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



			if (Connect4[y][x] == 'O') {                      // try both horizon and vertical check

			    c = y;
				d = x;


				while (Connect4[c][d] == 'O') {
					d++;
					WinCheckMainer++;
				}

				if (WinCheckMainer == WinCondition) {
					return true;
				}

				else {
					c = y;
					d = x;
					WinCheckMainer = 0;
				}
																				//

				while (Connect4[c][d] == 'O') {
					c++;
					WinCheckMainer++;
				}

				if (WinCheckMainer == WinCondition) {
					return true;
				}

				else {
					c = y;
					d = x;
					WinCheckMainer = 0;
				}

																				//
				while (Connect4[c][d] == 'O') {
					d++;
					c++;
					WinCheckMainer++;
				}

				if (WinCheckMainer == WinCondition) {
					return true;
				}

				else {
					c = y;
					d = x;
					WinCheckMainer = 0;
				}

																//
				while (Connect4[c][d] == 'O') {
					d --;
					c ++;
					WinCheckMainer++;
				}

				if (WinCheckMainer == WinCondition) {
					return true;
				}

				else {
					c = y;
					d = x;
					WinCheckMainer = 0;
				}


			}
		}

	}
	return false;

}


int Play(int Rows, int Coloumns){

	int Order = Rows * Coloumns;

	Connect4[Rows][Coloumns];

	for (int y = 0; y < Rows; y++) {

		for (int x = 0; x < Coloumns; x++) {

			Connect4[y][x] = '-';
		}
	}

	int xD = 0;

	for (int y = 0; y < Rows; y++) {


		if (Connect4[y][xD] == '-') {
			xD++;
			Diagonal++;
		}

	}

	cout << " Connectivity :  ";
	cin >> WinCondition;

	if (Rows < Coloumns) {
		a = Rows;
		b = Coloumns;
	}
	else if (Coloumns < Rows) {
		a = Coloumns;
		b = Rows;
	}
	else {
		b = Rows;
	}



	while (WinCondition > b || WinCondition > Diagonal || WinCondition < 2) {

		cout << "\n\nThis win condition is not possible. Please enter another: ";
		cin >> WinCondition;
	}


	cout << endl << endl;

	cout << "Match Started ! " << endl;

	for (int y = 0; y < Rows; y++) {


		for (int x = 0; x < Coloumns; x++) {

			cout << Connect4[y][x] << "  ";                  // cout matrix
		}
		cout << endl << endl;
	}



	for (int x = 1; x <= Coloumns; x++) {

		cout << x << "  ";                  // cout index

	}
	cout << endl << endl;

	TurnPlayer1();

	TurnPlayer2();




	WinCheckMain();

	int time = 2;

	while ( time < Order) {


		TurnPlayer1();

		if (WinCheckMain() != false) {
			cout << " \n GAME OVER! " << endl;
			cout << "\n Player 1 wins!";
			cout << "\n\n";
			return Rows;
		}

		time++;

		if (time >= Order) {

			if (WinCheckMain() != false) {
				cout << "\n GAME OVER!!" << endl;
				cout << "\nPlayer 1 wins!";
				cout << "\n\n";
				return Rows;
			}

			cout << "\n Draw !" << endl;
			return Rows;

		}

		TurnPlayer2();

		if (WinCheckMain() != false) {							//player 1 turn
			cout << "\n GAME OVER!" << endl;
			cout << "\nPlayer 2 wins!";
			cout << "\n\n";
			return Rows;
		}

		time++;

		if (time >= Order) {

			if (WinCheckMain() != false) {							//player 1 turn
				cout << "\n GAME OVER!" << endl;
				cout << "\nPlayer 2 wins!";
				cout << "\n\n";
				return Rows;
			}

			cout << "\n\n Draw !" << endl;
			return Rows;

		}

	}

	if (time >= Order) {

		cout << "\n\n Draw !" << endl;

	}

	cout << "\n\n";
	return Rows;
}

    bool SaveGame(char FileName[]){

         ofstream FOUT( FileName );
         for(int r = 0; r < Rows; r++){
            for(int c = 0; c < Coloumns; c++){
                FOUT << Connect4[r][c]<<"  ";
            }
            FOUT << endl;
        }
        FOUT.close();
        return true;
    }


    bool LoadSavedGame(char FileName[]){

        ifstream FIN(FileName);

        if(!FIN.is_open())
            return false;

        if(!SaveGame(FileName))
            return false;

        for(int r = 0; r < Rows; r++){
            for(int c = 0; c < Coloumns; c++){
               FIN >> Connect4[r][c];
            }
        }

        FIN.close();
        return true;
    }



int main()
{


	while (MenuChoice != 4) {

		cout << " 1. Play " << endl;
		cout << " 2. Save " << endl;
		cout << " 3. Load " << endl;
		cout << " 4. Exit " << endl;

		cout << "\n\n Enter your choice (1 - 4): ";
		cin >> MenuChoice;


		if (MenuChoice == 1) {

			cout << " Enter Rows : ";
			cin >> Rows;

			cout << " Enter Coloumns :  ";
			cin >> Coloumns;

			Play(Rows, Coloumns);
		}

		else if (MenuChoice == 2) {
             cout << " Enter Filename to Save : ";
             cin >> FileName;
             if (SaveGame(FileName) )
			    cout << " GAME SAVED " <<endl;
			else
			    cout << " GAME NOT SAVED "<<endl;
		}

		else if (MenuChoice == 3) {
            cout<<" Enter File Name :  ";
            cin>>FileName;
            if(LoadSavedGame(FileName) )
            {
               cout<<" SAVED GAME LOADED SUCCESSFULLY "<<endl;
               Play(Rows , Coloumns);
           }
            else
                cout<<" SAVED GAME NOT LOADED "<<endl;
		}

		else if (MenuChoice == 4) {
			cout <<" Game Ended " << endl;
			return 0;
		}

		else {
			cout << "\nInvalid input. Please try again.\n" << endl;
		}
	}
}
