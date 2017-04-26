// StatPal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <math.h>
using namespace std;
int main();

struct probe {
	float val;
	float times;
};

void calculatelarge() {
	int total = 0;
	cout << "Insert number of different valued probes: "; int size; cin >> size;
	probe* tab = new probe[size];
	for (int i = 0; i < size; i++) {
		cout << "Insert " << i << " probe value: "; cin >> tab[i].val;
		cout << "Insert " << i << " probe quantity:  "; cin >> tab[i].times;
	}
	cout << "Is ";
	for (int i = 0; i < size; i++) {
		cout<<"\t" << tab[i].val << " times "<<tab[i].times<<" \n";
		total += tab[i].times;
	}cout << "The correct probe chain with total "<<total<<" of probes?\n1 = Yes\n0 = No\nInput: "; int sw; cin >> sw;
	if (sw <= 0) { system("cls"); calculatelarge(); }
	cout << "Calculating\n";
	float srednia = 0;
	for (int i = 0; i < size; i++) {
		srednia += tab[i].val*tab[i].times;
	}float keeper = srednia; srednia /= total;
	float bigS = 0;
	for (int i = 0; i < size; i++) {
		bigS += tab[i].times*pow((tab[i].val - srednia), 2);
	}float keepers = bigS; bigS /= total;
	float smallS = sqrt(bigS);
	system("cls");
	cout << "Your values are:\n"
		"Average =\t" << keeper << " / " << total << " = " << srednia << endl <<
		"S^2 =\t" << keepers << " / " << total << " = " << bigS << endl <<
		"S =\t" << smallS << endl;
	cout << endl << "Continue running program?\1 = Yes\n0 = No\nInput: "; cin >> sw;
	if (sw >= 1) {
		system("cls");
		delete tab; main();
	}
	else delete tab;
	
}

void calculatesmall(float *tab, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Insert " << i << " probe value: "; cin >> tab[i];
	}
	cout << "Is ";
	for (int i = 0; i < size; i++) {
		cout << tab[i] << "  ";
	}cout << "The correct probe chain?\n1 = Yes\n0 = No\nInput: "; int sw; cin >> sw;
	if (sw <= 0) { system("cls"); calculatesmall(tab, size); }
	cout << "\nCalculating...\n";
	float srednia = 0;
	for (int i = 0; i < size; i++) {
		srednia += tab[i];
	}float keeper = srednia;
	srednia /= size;//srednia correct;
	float bigS = 0;
	for (int i = 0; i < size; i++) {
		bigS += pow((tab[i] - srednia),2);
	}float keepers = bigS;
	bigS /= size; //cout << bigS;//S^2
	float smallS = sqrt(bigS);
	float med = 0;
	if (size % 2 == 0) {
		med = 0.5*(tab[size / 2] + tab[(size / 2) + 1]);
		//med = tab[(size + 1) / 2];
	}
	else {
		med = tab[(size + 1) / 2];
		//med = 0.5*(tab[size / 2] + tab[size / 2 + 1]);
	}
	system("cls");
	cout << "Your Stats are\n";
	cout << "Average:\t" << keeper << " / " << size << " = " << srednia << endl;
	cout << "S^2:\t\t" << "1 / " << size << " * " << keepers << " = " << bigS << endl;
	cout << "S:\t\t" << smallS << endl;
	cout << "Medium:\t\t" << med << endl;
	cout << "Change:\t\t" << (smallS / srednia * 100) << endl;
	cout << endl << "Continue with program?\n1 = Yes\n0 = No\n"; cin >> sw;
	if (sw >= 1) {
		delete tab;
		system("cls");
		main();
	}
}


int main()
{
	int size;
	cout << "Insert number of probes: "; cin >> size;
	cout << "Is " << size << " a correct number of probes?\n1 = Yes\n0 = No\n>>input: "; int dec = 0; cin >> dec;
	if (dec >= 1) {
		
		if (size <= 30) {
			float *tab = new float[size]; calculatesmall(tab, size);
		}
		else if (size > 30)calculatelarge();
	}
	else {
		system("cls"); main();
	}

	float * tab = new float[size];


	delete tab;
    return 0;
}

