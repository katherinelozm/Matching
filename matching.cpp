#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void mixColumns(char**, char**, char**, char**, int, int);

int main(){
	char** columnA;
	char** columnB;
	char** mixedColumnA;
	char** mixedColumnB;
	char* word;
	int colA, colB, ans, ans2, ansA, ansB;
	char answ;
	vector<int> answersA;
	vector<int> answersB;
	do{
		cout << "Numero de palabras de la columna A: ";
		cin >> colA;
		cout << "Numero de palabras de la columna B: ";
		cin >> colB;
		word =  new char[50];
		columnA = new char*[colA];
		cout << "Columna A: " << endl;
		for (int i = 0; i < colA; i++){
			cout << "Palabra " << i+1 << ": ";
			cin >> word;
			columnA[i] = new char[strlen(word)];
			strcpy(columnA[i], word);
			word = new char[50];
		}
		word =  new char[50];
		columnB = new char*[colB];
		cout << "Columna B: " << endl;
		for (int i = 0; i < colB; i++){
			cout << "Palabra " << i+1 << ": ";
			cin >> word;
			columnB[i] = new char[strlen(word)];
			strcpy(columnB[i], word);
			word = new char[50];
		}
		cout << "Columna A: " << endl;
		for (int i = 0; i < colA; i++){
			cout << i+1  << ". " << columnA[i] << endl;
		}
		cout << "Columna B: " << endl;
		for (int i = 0; i < colB; i++){
			cout << i+1  << ". " << columnB[i] << endl;
		}
		cout << "Ingrese las respuestas correctas" << endl;
		answ = 's';
		while(answ == 's' || answ == 'S'){
			cout << "Columna A: ";
			cin >> ansA;
			answersA.push_back(ansA--);
			cout << "Columna B: ";
			cin >> ansB;
			answersB.push_back(ansB--);
			cout << "¿Desea continuar? S/N " << endl;
			cin >> answ;
		}
		cout << "1. Jugar" << endl;
		cout << "2. Salir" << endl;
		cin >> ans2;
		if (ans2==1){
			mixedColumnA = new char*[colA];
			mixedColumnB = new char*[colB];
			mixColumns(columnA, columnB, mixedColumnA, mixedColumnB, colA, colB);
			cout << "Columna A: " << endl;
			for (int i = 0; i < colA; i++){
				cout << i+1 << ". "  << mixedColumnA[i] << endl;
			}
			cout << "Columna B: " << endl;
			for (int i = 0; i < colB; i++){
				cout << i+1 << ". "  << mixedColumnB[i] << endl;
			}
			answ = 's';
			while(answ == 's' || answ == 'S'){
				cout << "Columna A: ";
				cin >> ansA;
				answersA.push_back(ansA--);
				cout << "Columna B: ";
				cin >> ansB;
				answersB.push_back(ansB--);
				cout << "¿Desea continuar? S/N " << endl;
				cin >> answ;
			}
		} else {
			exit(0);
		}
		cout << "¿Desea empezar de nuevo? 1. Si" << endl;
		cin >> ans;
	} while(ans==1);
	delete[] word;
	for (int i = 0; i < colA; i++){
		delete[] columnA[i];
	}
	delete[] columnA;
	for (int i = 0; i < colB; i++){
		delete[] columnB[i];
	}
	delete[] columnB;
	for (int i = 0; i < colA; i++){
		delete[] mixedColumnA[i];
	}
	delete[] mixedColumnA;
	for (int i = 0; i < colB; i++){
		delete[] mixedColumnB[i];
	}
	delete[] mixedColumnB;
	return 0;
}

void mixColumns(char** A, char** B, char** mixedA, char** mixedB, int size_a, int size_b){
	
}