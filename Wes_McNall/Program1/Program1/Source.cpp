// Wes McNall
// wwmgbr@mail.umkc.edu
// 1/28/2020
// CS201R Program 1

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

bool _Dice_Bust(int die) {
	if (die == 1) {
		return true;
	}
	return false;
}

int Roll_Die() {
	return (rand() % 6) + 1;;
}

void Output_Roll_Pot(int die, int pot) {

	cout << "Die Roll : " << die << "\tPot : " << pot;

	return;
}

void Hold() {
	return;
}

void Increase_Player_Score() {
	return;
}

void Reset_Pot() {
	return;
}

void Output_Score(int you_score, int ai_score) {

	cout << "Score\t" << "You : " << you_score << " AI : " << ai_score << endl << endl;

	return;
}

int _Roll_And_Output(int die, int pot) {
	die = Roll_Die();
	if (_Dice_Bust(die)) {
		cout << "Dice Roll 1: BUST" << endl << endl;
		return -1;
	}
	//pot += die;
	Output_Roll_Pot(die, (die + pot));
	return die;
}

char _Player_input() {
	// Might fail if player inputs something not char?
	char input;

	cout << "\t(R)oll again or (H)old? ";
	cin >> input;
	return toupper(input);
}

int Roll(int die, int pot) {
	int roll;
	roll = _Roll_And_Output(die, pot);
	if (roll == -1) {
		// BUSTED
		return 0;
	}
	else {
		pot += roll;
		return pot;
	}
}

int Player_Turn(int die, int pot) {
	char input;

	cout << "Players Turn" << endl;

	pot = Roll(die, pot);
	if (pot == 0) { // Bust check
		return 0;
	}

	// Player Turn Loop
	while (1 == 1) {
		input = _Player_input();
		while ((input != 'R') && (input != 'H')) {
			cout << endl << "You must enter R or H" << endl;
			input = _Player_input();
		}

		if (input == 'R') {
			pot = Roll(die, pot);
			if (pot == 0) { // Bust check
				return 0;
			}
			continue;
		}
		else { // input == 'H'
			return pot;
		}
	}
}

int AI_Turn(int die, int pot) {

	cout << "AI Turn" << endl;

	do {
		pot = Roll(die, pot);
		cout << endl;
		if (pot == 0) { // Bust check
			return 0;
		}
	} while ((pot >= 1) && (pot <= 20));

	return pot;
}

char _Again_Input() {
	// Might fail if player inputs something not char?
	char input;

	cout << endl << endl << "Play agian? (Y/N) ";
	cin >> input;

	return toupper(input);
}

bool Play_Again() {
	char input;

	input = _Again_Input();

	while ((input != 'Y') && (input != 'N')) {
		cout << endl << "You must enter Y or N" << endl;
		input = _Again_Input();
	}

	if (input == 'Y') {
		cout << endl << endl;
		return true;
	}
	return false;
}

int main() {

	int die=0, pot = 0, you_score, ai_score;
	char input;
	srand(time(0));

	// Program Loop
	while (1 == 1) {
		// Game Loop
		you_score = 0;
		ai_score = 0;
		Output_Score(0, 0);
		while (ai_score <= 50) {
			pot = Player_Turn(die, 0);
			you_score += pot;
			if (you_score >= 50) {
				break;
			}
			Output_Score(you_score, ai_score);
			pot = AI_Turn(die, 0);
			ai_score += pot;
			Output_Score(you_score, ai_score);
		}

		Output_Score(you_score, ai_score);
		if (you_score > ai_score) {
			cout << "Humans win!";
		}
		else {
			cout << "Machines win!";
		}

		if (Play_Again()) {
			continue;
		}
		else {
			break;
		}
	}

	// Game stops when someone's score is >= 50

	// Automatic dice roll once
	// Check for input 'r' or 'h'
	// Sanitize input
	// Go on until hold
	// Output score
	// AI turn
	// Repeat player turn

	return 0;

}