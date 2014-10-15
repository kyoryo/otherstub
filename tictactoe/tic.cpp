#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <float.h>
#include <unistd.h>

using namespace std;

class Board {
	public:
	int v[3][3];

	void Init ();
	int Win (bool show);
	bool Draw ();
	int Hue ();
};

void Board::Init () {
	for (int y=0; y<3; y++) {
		for (int x=0; x<3; x++) {v[y][x] = 0;}
	}
	return;
}

int Board::Win (bool show) {	
	if (v[1][1] == 1) {	
		if (v[0][0]+v[1][1]+v[2][2] == 3) {	
			if (show) {cout << "X wins downslope diagonal\n";}
			return 1;
		}
		if (v[1][0]+v[1][1]+v[1][2] == 3) {	
			if (show) {cout << "X wins middle row\n";}
			return 1;
		}
		if (v[2][0]+v[1][1]+v[0][2] == 3) {	
			if (show) {cout << "X wins upslope diagonal\n";}
			return 1;
		}
		if (v[0][1]+v[1][1]+v[2][1] == 3) {	
			if (show) {cout << "X wins middle column\n";}
			return 1;
		}
	}
	else if (v[1][1] == -1) {	
		if (v[0][0]+v[1][1]+v[2][2] == -3) {	
			if (show) {cout << "O wins downslope diagonal\n";}
			return -1;
		}
		if (v[1][0]+v[1][1]+v[1][2] == -3) {	
			if (show) {cout << "O wins middle row\n";}
			return -1;
		}
		if (v[2][0]+v[1][1]+v[0][2] == -3) {	
			if (show) {cout << "O wins upslope diagonal\n";}
			return -1;
		}
		if (v[0][1]+v[1][1]+v[2][1] == -3) {	
			if (show) {cout << "O wins middle column\n";}
			return -1;
		}
	}

	if (v[0][0] == 1) {
		if (v[0][0]+v[1][0]+v[2][0] == 3) {	
			if (show) {cout << "X wins left column\n";}
			return 1;
		}
		if (v[0][0]+v[0][1]+v[0][2] == 3) {	
			if (show) {cout << "X wins top row\n";}
			return 1;
		}
	}
	else if (v[0][0] == -1) {	
		if (v[0][0]+v[1][0]+v[2][0] == -3) {	
			if (show) {cout << "O wins left column\n";}
			return -1;
		}
		if (v[0][0]+v[0][1]+v[0][2] == -3) {	
			if (show) {cout << "O wins top row\n";}
			return -1;
		}
	}

	if (v[2][2] == 1) {	
		if (v[0][2]+v[1][2]+v[2][2] == 3) {	
			if (show) {cout << "X wins right column\n";}
			return 1;
		}
		if (v[2][0]+v[2][1]+v[2][2] == 3) {	
			if (show) {cout << "X wins bottom row\n";}
			return 1;
		}
	}
	else if (v[2][2] == -1) {	
		if (v[0][2]+v[1][2]+v[2][2] == -3) {	
			if (show) {cout << "O wins right column\n";}
			return -1;
		}
		if (v[2][0]+v[2][1]+v[2][2] == -3) {	
			if (show) {cout << "O wins bottom row\n";}
			return -1;
		}
	}
	return 0;
}

bool Board::Draw () {	
	bool ret = true;
	for (int y=0; y<3; y++) {
		ret *= v[y][0]*v[y][1]*v[y][2];
	}
	return ret;
}

int Board::Hue () {
	int H = 0;
	for (int i=0;i<3;i++) {
		if (v[i][0]*v[i][1]*v[i][2] == 0) {		
			int s = v[i][0]+v[i][1]+v[i][2];
			if (s == 2) {H+=3;}	
			else if (s == 1) {H++;}	
			else if (s == -2) {H-=3;}	
			else if (s == -1) {H--;}	
		}
		if (v[0][i]*v[1][i]*v[2][i] == 0) {		
			int s = v[0][i]+v[1][i]+v[2][i];
			if (s == 2) {H+=3;}	
			else if (s == 1) {H++;}	
			else if (s == -2) {H-=3;}	
			else if (s == -1) {H--;}	
		}
	}
	if (v[0][0]*v[1][1]*v[2][2] == 0) {		
		int s = v[0][0]+v[1][1]+v[2][2];
		if (s == 2) {H+=3;}
		else if (s == 1) {H++;}	
		else if (s == -2) {H-=3;}	
		else if (s == -1) {H--;}	
	}
	if (v[0][2]*v[1][1]*v[2][0] == 0) {		
		int s = v[0][2]+v[1][1]+v[2][0];
		if (s == 2) {H+=3;}	
		else if (s == 1) {H++;}	
		else if (s == -2) {H-=3;}	
		else if (s == -1) {H--;}	
	}
	return H;	
}

class Move {
	public:
	Move *TL;	
	Move *T;	
	Move *TR;	
	Move *L;	
	Move *C;	
	Move *R;	
	Move *BL;	
	Move *B;
	Move *BR;

	bool XTurn;
	Board State;	
	int score;		
	void Init ();
	void Del ();
	void Display ();
	void DefineMoves (int depth, bool h);
};

void Move::Init () {

	TL = 0;
	T = 0;
	TR = 0;
	L = 0;
	C = 0;
	R = 0;
	BL = 0;
	B = 0;
	BR = 0;
	State.Init ();	
	score = 0;
}

void Move::Del () {	
	if (TL != 0) {
		TL->Del ();
		free (TL = 0);
	}
	if (T != 0) {
		T->Del ();
		free (T = 0);
	}
	if (TR != 0) {
		TR->Del ();
		free (TR = 0);
	}
	if (L != 0) {
		L->Del ();
		free (L = 0);
	}
	if (C != 0) {
		C->Del ();
		free (C = 0);
	}
	if (R != 0) {
		R->Del ();
		free (R = 0);
	}
	if (BL != 0) {
		BL->Del ();
		free (BL);
	}
	if (B != 0) {
		B->Del ();
		free (B = 0);
	}
	if (BR != 0) {
		BR->Del ();
		free (BR = 0);
	}
	return;
}

void Move::Display () {	
	cout << "	BOARD  #  SCORE\n";
	for (int y=0; y<3; y++) {
		cout << "  -----------  #  -----------\n";
		for (int x=0; x<3; x++) {
			cout << " | ";
			if (State.v[y][x] > 0) {cout << 'X';}
			else if (State.v[y][x] < 0) {cout << 'O';}
			else {//cout << '.';}
				cout << y*3+x+1;	
			}
		}
		cout << " | #";
		for (int x=0; x<3; x++) {
			cout << " | ";
			Move *disp = 0;	
			switch (y*3+x) {
				case 0: disp = TL; break;
				case 1: disp = T; break;
				case 2: disp = TR; break;
				case 3: disp = L; break;
				case 4: disp = C; break;
				case 5: disp = R; break;
				case 6: disp = BL; break;
				case 7: disp = B; break;
				case 8: disp = BR; break;
			}
			if (!disp) {cout << '#';}
			else {cout << disp->score;}
		}
		cout << " |\n";
	}
	cout << "  -----------  #  -----------\n";
	return;
}

void Move::DefineMoves (int depth, bool h) {
	int W = State.Win (false);	
	if (W != 0 || depth == 0 || State.Draw ()) {	
		score = W;
		if (h && !W) {score = State.Hue ();}	
		return;
	}
	if (XTurn) {score = -1-(4*h);}	
	else {score = 1+(4*h);}

	
	for (int y=0; y<3; y++) {
		for (int x=0; x<3; x++) {
			if (State.v[y][x] == 0) {	
				Move *NewMove = 0;
				switch (y*3+x) {
					case 0: NewMove = TL; break;
					case 1: NewMove = T; break;
					case 2: NewMove = TR; break;
					case 3: NewMove = L; break;
					case 4: NewMove = C; break;
					case 5: NewMove = R; break;
					case 6: NewMove = BL; break;
					case 7: NewMove = B; break;
					case 8: NewMove = BR; break;
				}
				if (!NewMove) {
					NewMove = new (Move);
					NewMove->Init ();
				}
				NewMove->XTurn = (XTurn == 0);
				NewMove->State = State;
				NewMove->State.v[y][x] = -1+XTurn*2;	
				switch (y*3+x) {
					case 0: TL = NewMove; break;
					case 1: T = NewMove; break;
					case 2: TR = NewMove; break;
					case 3: L = NewMove; break;
					case 4: C = NewMove; break;
					case 5: R = NewMove; break;
					case 6: BL = NewMove; break;
					case 7: B = NewMove; break;
					case 8: BR = NewMove; break;
				}
				NewMove->DefineMoves (depth-1, h);
				if ((XTurn && score < NewMove->score) || (!XTurn && score > NewMove->score)) {	
					score = NewMove->score;
				}
				free (NewMove = 0);	
			}
		}
	}
	return;
}

// ==========================================
// ------------------ MAIN ------------------
// ==========================================
int main () {

	Move root, *current;			
	root.Init ();
	int mode = 0;
	string in = "y";
	while (in == "y" || in == "Y") {
		bool heur = 0, human = 0;	// whether using heuristic and whether user is playing
		int gloat = 0, depth = 1;	// gloat variable and search depth
		system ("cls");
		while (in != "h" && in != "H" && in != "c" && in != "C") {
			cout << "X (Computer) Vs. O (Human/Computer)? (H/C): ";
			cin >> in;
			if (in == "h" || in == "H") {human = true;}
			else if (in == "c" || in == "C") {human = false;}
			else {cout << "Invalid input! Try again!\n";}
		}
		while (in != "x" && in != "X" && in != "o" && in != "O") {
			cout << "Who's turn first? (X/O): ";
			cin >> in;
			if (in == "x" || in == "X" || in[0] == 'x' || in[0] == 'X') {root.XTurn = true;}
			else if (in == "o" || in == "O" || in[0] == 'o' || in[0] == 'O') {root.XTurn = false;}
			else {cout << "Invalid input! Try again!\n";}
		}
		while (in[0] < '1' || in[0] > '9') {
			cout << "Search depth? (1-9): ";
			cin >> in;
			if (in[0] >= '1' && in[0] <= '9') {depth = in[0]-'0';}
			else {cout << "Invalid input! Try again!\n";}
		}
		heur = true;
		/*while (in != "y" && in != "Y" && in != "n" && in != "N") {
			cout << "Use heuristic? (Y/N): ";
			cin >> in;
			if (in == "y" || in == "Y") {heur = true;}
			else if (in == "n" || in == "N") {heur = false;}
			else {cout << "Invalid input! Try again!\n";}
		}*/

		root.DefineMoves (depth+1, heur);	
		current = &root;
		while (!current->State.Win (false) && !current->State.Draw ()) {	
			if (current->XTurn || !human) {			
				if (depth > 1) {
					int z = 0;
					
					cout << "SCORE: " << current->score << "; Searching to depth of " << depth << '\n';
					current->DefineMoves (depth, heur);
				}
				else {
					current->DefineMoves (2, heur);
					cout << "SCORE: " << current->score << "; Searching to depth of " << depth << '\n';
					current->DefineMoves (depth, heur);
				}
				cout << "Post evaluation, pre-decision:\n";
				current->Display ();
				if (!current->State.v[0][0] && current->TL->score == current->score) {
					current = current->TL;
					cout << char('O'+('X'-'O')*!current->XTurn) << " picked TL";
				}
				else if (!current->State.v[0][1] && current->T->score == current->score) {
					current = current->T;
					cout << char('O'+('X'-'O')*!current->XTurn) << " picked T";
				}
				else if (!current->State.v[0][2] && current->TR->score == current->score) {
					current = current->TR;
					cout << char('O'+('X'-'O')*!current->XTurn) << " picked TR";
				}
				else if (!current->State.v[1][0] && current->L->score == current->score) {
					current = current->L;
					cout << char('O'+('X'-'O')*!current->XTurn) << " picked L";
				}
				else if (!current->State.v[1][1] && current->C->score == current->score) {
					current = current->C;
					cout << char('O'+('X'-'O')*!current->XTurn) << " picked C";
				}
				else if (!current->State.v[1][2] && current->R->score == current->score) {
					current = current->R;
					cout << char('O'+('X'-'O')*!current->XTurn) << " picked R";
				}
				else if (!current->State.v[2][0] && current->BL->score == current->score) {
					current = current->BL;
					cout << char('O'+('X'-'O')*!current->XTurn) << " picked BL";
				}
				else if (!current->State.v[2][1] && current->B->score == current->score) {
					current = current->B;
					cout << char('O'+('X'-'O')*!current->XTurn) << " picked B";
				}
				else if (!current->State.v[2][2] && current->BR->score == current->score) {
					current = current->BR;
					cout << char('O'+('X'-'O')*!current->XTurn) << " picked BR";
				}
				else {	// mighty big error: score selected doesn't match any possible moves.
					cout << "Nowhere left to run...expected " << current->score << "\n";
					current->Display ();
					fflush (0);
					usleep (10);
				}
				cout << " with score of " << current->score << '\n';
				if (!human) {current->Display ();}
			}
			else {							
				cerr << "Player's turn\n";
				current->Display ();
				if (gloat != current->score && !heur) {	
					gloat = current->score;
					if (gloat == 1) {cout << "I am, by any practical definition of the words, foolproof and incapable of error.\n";}
					else if (gloat == -1) {cout << "This loss can only be attributed to human error.\n";}
				}
				cout << "Input number of square to mark: ";
				cin >> in;
				if (!current->State.v[(in[0]-'0'-1)/3][(in[0]-'0'-1)%3]) {	// track user moves by traversing move tree
					switch (in[0]-'0') {
						case 1: current = current->TL; break;
						case 2: current = current->T; break;
						case 3: current = current->TR; break;
						case 4: current = current->L; break;
						case 5: current = current->C; break;
						case 6: current = current->R; break;
						case 7: current = current->BL; break;
						case 8: current = current->B; break;
						case 9: current = current->BR; break;
					}
				}
				else {cout << "Invalid Input! Try Again!\n";}
			}
		}
		
		cout << "  BOARD  \n";
		for (int y=0; y<3; y++) {
			cout << "  -----------\n";
			for (int x=0; x<3; x++) {
				cout << " | ";
				if (current->State.v[y][x] > 0) {cout << 'X';}
				else if (current->State.v[y][x] < 0) {cout << 'O';}
				else {cout << '.';}
			}
			cout << " |\n";
		}
		cout << "  -----------\n";
		if (!current->State.Win (true)) {cout << "Draw!\n";}
		else if (human) {
			if (!current->XTurn) {cout << "You lose SCUMBAG!! Bow to me Now!\n";}
			else {cout << "User won!\n";}
		}
		else {cout << char('O'+('X'-'O')*!current->XTurn) << " won!\n";}	// display which player won
		cout << "Play again? (Y/N): ";
		cin >> in;
	}
	return 0;
}
