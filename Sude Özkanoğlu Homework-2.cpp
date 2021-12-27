/****************************************************************************
**								SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**						   BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**						     PROGRAMLAMAYA GİRİŞİ DERSİ
**
**							ÖDEV NUMARASI:2
**							ÖĞRENCİ ADI:SUDE ÖZKANOĞLU
**							ÖĞRENCİ NUMARASI:G201210034
**							DERS GRUBU:II. ÖĞRETİM - C GRUBU 
****************************************************************************/

#include <iostream>
#include <ctime>
#include <stdio.h>
#include "conio.h"
#include <windows.h>

using namespace std;

char STRAIGHT_LINE = 205;
char UPPER_LEFT_LINE = 201;
char UPPER_RIGHT_LINE = 187;
char VERTICAL_LINE = 186;
char DOWN_BRANCH = 203;
char BOTTOM_LEFT_CORNER = 200;
char BOTTOM_RIGHT_CORNER = 188;
char UP_BRANCH = 202;

class Character 
{
public:
	//We wrote constructor and methods
	Character();
	Character(char randomChar, int randomColor) 
	{
		letter = randomChar;
		color = randomColor;
	}
	char letter;
	int color;

	char getLetter()
	{
		return letter;
	}
	char getColor () 
	{
		return color;
	}
};

class Katar
{
public:
	//We are creating constructors
	Katar()
	{
		numberofCharacter = 0;
		characters[50];
	}
	void character_Add();
	void character_Remove();
	void print();

	int getNumberofCharacter()
	{
		return numberofCharacter;
	}
private:

	int numberofCharacter;
	char characters[];
};
enum COLORS
{
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
};

//Global Variables
char randomChars[50] = {};
char randomColors[100] = {};
int j = 0;
int keep = 0;

//We created object
Katar katar;

int main()
{
	//Necessary definitions for coloring letters
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	//Decision mechanism
	int operationDecision = 0;
	cout << "Select Operation:" << endl;
	cout << "1- Add Character" << endl;
	cout << "2- Remove Character " << endl;
	cout << "3- Exit the Programme" << endl;
	cin >> operationDecision;

	if (operationDecision == 1) {
		katar.character_Add();
		return 0;
	}
	else if (operationDecision == 2) {
		katar.character_Remove();
		return 0;
	}
	else if (operationDecision == 3) {
		cout << "See You Later!" << endl;
		system("exit");
	}
	else if (operationDecision == 4) {
		katar.print();
		return 0;
	}

}

void Katar::character_Add() {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	srand(time(0)); // <----------- We get time=0 to generate random numbers

	//Before the character_Add() method, we check if a deletion has been made
	if (keep != j) {
		j++;
		katar.numberofCharacter++;
		srand(time(0));
		char randomChar = rand() % 25 + 65;
		srand(time(0));
		int randomColor = rand() % 6 + 9;
		Character Character(randomChar, randomColor);

		katar.characters[j] = { Character.getLetter() };
		randomColors[j] = { Character.getColor() };
	}
	//If not, we continue from here
	else {
		j++;
		katar.numberofCharacter++;
		srand(time(0));
		char randomChar = rand() % 25 + 65;

		srand(time(0));
		int randomColor = rand() % 6 + 9;
		Character Character(randomChar, randomColor);

		katar.characters[j] = { Character.getLetter() };
		randomColors[j] = { Character.getColor() };
	}
	//To print an empty box ,if there is no expression on the screen
	if (j <= 1) {
		cout << "Previous State:" << "Number of Elements:" << j - 1 << endl;
		cout << UPPER_LEFT_LINE << STRAIGHT_LINE << UPPER_RIGHT_LINE << endl;
		cout << VERTICAL_LINE << " " << VERTICAL_LINE << endl;
		cout << BOTTOM_LEFT_CORNER << STRAIGHT_LINE << BOTTOM_RIGHT_CORNER;
	}
	//Here,we create the previous version .(We provided this with variables)
	if (j > 1) {
		cout << "Previous State:" << "Number of Elements:" << j - 1 << endl;
		cout << UPPER_LEFT_LINE << STRAIGHT_LINE << UPPER_RIGHT_LINE;
	}
	for (int a = 0; a < katar.numberofCharacter - 2; a++) {

		cout << UPPER_LEFT_LINE << STRAIGHT_LINE << UPPER_RIGHT_LINE;
	}
	cout << endl;

	for (int b = 0; b < katar.numberofCharacter - 1; b++) {

		cout << VERTICAL_LINE;
		SetConsoleTextAttribute(h, COLORS(randomColors[b + 1]));
		cout << katar.characters[b + 1];
		SetConsoleTextAttribute(h, wOldColorAttrs);
		cout << VERTICAL_LINE;

	}
	cout << endl;
	for (int c = 0; c < katar.numberofCharacter - 1; c++) {
		cout << BOTTOM_LEFT_CORNER << STRAIGHT_LINE << BOTTOM_RIGHT_CORNER;
	}
	cout << endl;

	// Here ,we create the next state part .(We provided it with variables)
	cout << "Next State:" << "Number of Elements:" << j << endl;
	cout << UPPER_LEFT_LINE << STRAIGHT_LINE << UPPER_RIGHT_LINE;

	for (int a = 0; a < katar.numberofCharacter - 1; a++) {
		cout << UPPER_LEFT_LINE << STRAIGHT_LINE << UPPER_RIGHT_LINE;
	}
	cout << endl;

	for (int b = 0; b < katar.numberofCharacter; b++) {

		cout << VERTICAL_LINE;
		SetConsoleTextAttribute(h, COLORS(randomColors[b + 1]));
		cout << katar.characters[b + 1];
		SetConsoleTextAttribute(h, wOldColorAttrs);
		cout << VERTICAL_LINE;

	}
	cout << endl;
	for (int c = 0; c < katar.numberofCharacter; c++) {
		cout << BOTTOM_LEFT_CORNER << STRAIGHT_LINE << BOTTOM_RIGHT_CORNER;
	}
	cout << endl;
	keep = j;
	main();

}

//Character is subtraction method
void Katar::character_Remove() {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	//If there is no character on the screen, we warn that subtraction cannot be made
	if (j == 0) {
		SetConsoleTextAttribute(h, 4);
		cout << "Can not be Subtracted!" << endl;
		SetConsoleTextAttribute(h, wOldColorAttrs);
		main();
	}

	j--;
	// We create the previous version here .(We provided it with variables)

	cout << "Previous State:" << "Number of Elements:" << j + 1 << endl;
	cout << UPPER_LEFT_LINE << STRAIGHT_LINE << UPPER_RIGHT_LINE;
	for (int a = 0; a < katar.numberofCharacter - 1; a++) {

		cout << UPPER_LEFT_LINE << STRAIGHT_LINE << UPPER_RIGHT_LINE;
	}
	cout << endl;

	for (int b = 0; b < katar.numberofCharacter; b++) {

		cout << VERTICAL_LINE;
		SetConsoleTextAttribute(h, COLORS(randomColors[b + 1]));
		cout << katar.characters[b + 1];
		SetConsoleTextAttribute(h, wOldColorAttrs);
		cout << VERTICAL_LINE;

	}
	cout << endl;
	for (int c = 0; c < katar.numberofCharacter; c++) {
		cout << BOTTOM_LEFT_CORNER << STRAIGHT_LINE << BOTTOM_RIGHT_CORNER;
	}
	cout << endl;

	//If there is no expression left on the screen, click to create an empty box on the screen.
	if (j == 0) {
		cout << "Next State:" << "Number of Elements:" << j << endl;
		cout << UPPER_LEFT_LINE << STRAIGHT_LINE << UPPER_RIGHT_LINE << endl;
		cout << VERTICAL_LINE << " " << VERTICAL_LINE << endl;
		cout << BOTTOM_LEFT_CORNER << STRAIGHT_LINE << BOTTOM_RIGHT_CORNER;
	}


	//We created here to create the next version (We provided this with variables)
	if (katar.numberofCharacter > 1 && j != 0) {
		cout << "Next State:" << "Number of Elements:" << j << endl;
		cout << UPPER_LEFT_LINE << STRAIGHT_LINE << UPPER_RIGHT_LINE;
	}

	for (int a = 0; a < katar.numberofCharacter - 2; a++) {
		cout << UPPER_LEFT_LINE << STRAIGHT_LINE << UPPER_RIGHT_LINE;
	}
	cout << endl;

	for (int b = 0; b < katar.numberofCharacter - 1; b++) {

		cout << VERTICAL_LINE;
		SetConsoleTextAttribute(h, COLORS(randomColors[b + 1]));
		cout << katar.characters[b + 1];
		SetConsoleTextAttribute(h, wOldColorAttrs);
		cout << VERTICAL_LINE;

	}
	cout << endl;
	for (int c = 0; c < katar.numberofCharacter - 1; c++) {
		cout << BOTTOM_LEFT_CORNER << STRAIGHT_LINE << BOTTOM_RIGHT_CORNER;
	}
	cout << endl;
	katar.numberofCharacter--;

	main();
}

//We added the print command which is not in the output. Accessible from the home screen
void Katar::print() {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	//We called all our characters from the array in our class
	cout << UPPER_LEFT_LINE << STRAIGHT_LINE << UPPER_RIGHT_LINE;
	for (int a = 0; a < katar.numberofCharacter - 1; a++) {
		cout << UPPER_LEFT_LINE << STRAIGHT_LINE << UPPER_RIGHT_LINE;
	}
	cout << endl;

	for (int b = 0; b < katar.numberofCharacter; b++) {

		cout << VERTICAL_LINE;
		SetConsoleTextAttribute(h, COLORS(randomColors[b + 1]));
		cout << katar.characters[b + 1];
		SetConsoleTextAttribute(h, wOldColorAttrs);
		cout << VERTICAL_LINE;

	}
	cout << endl;
	for (int c = 0; c < katar.numberofCharacter; c++) {
		cout << BOTTOM_LEFT_CORNER << STRAIGHT_LINE << BOTTOM_RIGHT_CORNER;
	}
	cout << endl;


	main();
}


