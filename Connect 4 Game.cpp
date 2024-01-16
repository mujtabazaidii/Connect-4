#include<iostream>

#include<fstream>
#include<string>

using namespace std;
ifstream Out("D:/gamedata.txt");
int rows, columns, k = 0,limit;

char a[50][50], N, o;
void savegame() {
	ofstream In("D:/gamedata.txt");
	In << rows << "  " << columns << endl;
	In << N << "  " << o << endl;
	In << limit << endl;
	for (int i = 1;i <= rows;i++) {
		for (int j = 1;j <= columns;j++)
			In << a[i][j] << "   ";
		In << endl;
	}

	cout << endl << "Game has been saved to the given file location " << " D:/gamedata.txt" << " to continue load game please " << endl;
}
void loadgame() {

	Out >> rows >> columns;
	Out >> N >> o;
	Out >> limit;
	for (int i = 1;i <= rows;i++) {
		for (int j = 1;j <= columns;j++) {
			Out >> a[i][j];


		}
		cout << endl;

	}

}
bool check(int u, int q) {
	int e = 1, r = 1, s = 1, d = 1, x = 1, i, t = 1, f = 1,b,j;
	b = limit - 1;
	j = b - 1;
	for (i = 1;i <= limit; i++) {
		if (q + j<= columns) {
			if (i <= b) {
				if (a[u][q + i] == a[u][q])
					e = e + 1;
			}
			else {
				if (a[u][q - 1] == a[u][q])
					e = e + 1;
			}
		}
		if (q - j >= 1) {
			if (i <= b) {
				if (a[u][q - i] == a[u][q])
					r = r + 1;
			}
			else {
				if (a[u][q + 1] == a[u][q])
					r = r + 1;
			}
		}
		if (u + j <= rows) {
			if (i <= b) {
				if (a[u + i][q] == a[u][q])
					s = s + 1;
			}
			else {
				if (a[u - 1][q] == a[u][q])
					s = s + 1;
			}
		}
		if (u + j <= rows && q + j <= columns) {
			if (i <= b) {
				if (a[u + i][q + i] == a[u][q])
					x = x + 1;
			}
			else {
				if (a[u - 1][q - 1] == a[u][q])
					x = x + 1;
			}
		}
		if (u + j <= rows && q - j>= 1) {
			if (i <= b) {
				if (a[u + i][q - i] == a[u][q])
					d = d + 1;
			}
			else {
				if (a[u - 1][q + 1] == a[u][q])
					d = d + 1;
			}
		}
		if (u - j >= 1 && q - j >= 1) {
			if (i <= b) {
				if (a[u - i][q - i] == a[u][q])
					t = t + 1;
			}
			else {
				if (a[u + 1][q + 1] == a[u][q])
					t = t + 1;
			}

		}
		if (u - j>= 1 && q + j <= columns) {
			if (i <= b) {
				if (a[u - i][q + i] == a[u][q])
					f = f + 1;
			}
			else {
				if (a[u + 1][q - 1] == a[u][q])
					f = f + 1;
			}
		}

	}
	i = i - 1;
	if (i == e)
		return true;
	else if (i == r)
		return true;
	else if (i == s)
		return true;
	else if (i == d)
		return true;
	else if (i == x)
		return true;
	else if (i == t)
		return true;
	else if (i == f)
		return true;
	else
		return false;


}
int turn() {

	char d;
	k = k + 1;
	if (k % 2 == 0)
		d = N;
	else
		d = o;


	return d;
}

void newgame() {

	cout << "enter max. colunms of connect4" << endl;
	cin >> columns;
	cout << "enter max. rows of connect4 " << endl;
	cin >> rows;
	cout<<"enter limit of connect4 " << endl;
	cin >> limit;
	cout << "First Player Name? ";

	cin >> N;
	cout << "Second Player Name? ";
	cin >> o;

}
void data() {
	char ch;
	ch = 46;
	for (int i = 1;i <= rows;i++) {
		for (int j = 1;j <= columns;j++)
			a[i][j] = ch;
	}
}
void grid() {
	system("CLS");
	cout << "\n";
	int C, K;
	char g;
	g = 219;
	if (columns >= 10) {
		K = columns * 7 - 10;
		C = K / 2 - 6;
	}
	else {
		K = columns * 6;
		C = K / 3;
	}

	for (int i = 1;i <= K;i++)
		cout << g;
	cout << "\n";
	for (int j = 0;j <= 2;j++) {
		if (j != 2)
			cout << g;

		for (int i = 1;i <= K;i++) {
			if (j != 2)
				cout << " ";
			if (j == 1 && i == C)
				cout << "CONNECT 4";

			if (j == 2)
				cout << g;

		}
		if (j == 0)
			cout << "\b\b" << g;
		if (j == 1)
			cout << "\b\b\b\b\b\b\b\b\b\b\b" << g;
		cout << endl;
	}
	for (int j = 0;j <= 2;j++) {
		if (j != 2)
			cout << g;
		if (j == 1) {
			cout << " ";
			for (int y = 1;y <= columns;y++)
				cout << y << "     ";
			if (columns >= 10) {
				for (int y = 1;y <= 4;y++)
					cout << "\b";
			}
			else
				cout << "\b\b\b";
			cout << g;
			cout << endl;
		}



		if (j != 2) {
			if (j == 0) {
				for (int i = 1;i <= K;i++)
					cout << " ";
				cout << "\b\b";
				cout << g;
				cout << endl;
			}


		}

	}
	for (int i = 1;i <= K;i++)
		cout << g;
	cout << endl;
	for (int i = 1;i <= rows;i++) {
		cout << g;
		for (int j = 1;j <= columns;j++) {
			if (i <= rows) {
				if (j < 10) {
					cout << " " << a[i][j] << "    ";
					if (j == columns)
						cout << " ";

				}
				if (j >= 10)
					cout << "  " << a[i][j] << "    ";
			}
		}
		cout << "\b\b\b" << g << endl;

	}
	for (int i = 1;i <= K;i++)
		cout << g;




}
void play() {
	int n, p[100], c = 5, aa = 6, tt, kk;
	char h;
	for (int j = 1;j <= columns;j++) {
		p[j] = rows;
	}
	int Q = 1;
	while (Q <= rows + 3) {
		Q = Q + 1;

		for (int j = 1;j <= columns;j++) {

			cout << endl << "please enter your move( 1-" << columns << " )" << " and (20) for save game  = ";
			cin >> n;
			if (n >= 1 && n <= columns && p[n] >= 1) {
				h = turn();
				for (kk = n;n <= rows;kk++) {
					if (a[p[n]][n] == N || a[p[n]][n] == o)
						p[n] = p[n] - 1;
					else
						break;
				}
				a[p[n]][n] = h;
				p[n] = p[n] - 1;
				tt = p[n] + 1;
				if (check(tt, n))
					c = aa;

				grid();
				if (c == aa) {
					cout << endl << endl << "Game over : Player " << h << " is winner" << endl;
					break;
				}
			}
			else if (n != 20)
				cout << endl << "Invalid selection";
			else if (n == 20) {
				savegame();
				break;
			}
		}
		if (c == aa)
			break;
		if (n == 20)
			break;
	}
}
int Menu() {
	int Choice;
	do {
		cout << endl << "1. Play" << endl
			<< "2. Save Game" << endl
			<< "3. Load Game" << endl
			<< "4. Exit" << endl
			<< "Enter You Choice (1 - 4)";
		cin >> Choice;
	} while (Choice < 1 || Choice > 4);
	return Choice;
}
int main() {
	int oo;

	do {
		oo = Menu();
		if (oo == 1) {
			newgame();
			data();
			grid();
			play();
		}
		if (oo == 3) {

			loadgame();
			grid();
			play();

		}
		if (oo == 2) {
			savegame();
		}
	} while (oo != 4);
	return 0;
}

