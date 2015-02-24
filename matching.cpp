#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main(){
	srand(time(0));
	char** columnA;
	char** columnB;
	vector<char*> mixedColumnA;
	vector<char*> mixedColumnB;
	char* word;
	int colA, colB, ans, ans2, ansA, ansB, ansA2, ansB2;
	double correct = 0.0, count = 0.0;
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
		cout << "Palabras Columna A: " << endl;
		for (int i = 0; i < colA; i++){
			cout << "Palabra " << i+1 << ": ";
			cin >> word;
			columnA[i] = new char[strlen(word)];
			strcpy(columnA[i], word);
			word = new char[50];
		}
		word =  new char[50];
		columnB = new char*[colB];
		cout << "Palabras Columna B: " << endl;
		for (int i = 0; i < colB; i++){
			cout << "Palabra " << i+1 << ": ";
			cin >> word;
			columnB[i] = new char[strlen(word)];
			strcpy(columnB[i], word);
			word = new char[50];
		}
		cout << "Ingrese las respuestas correctas" << endl;
		answ = 's';
		while(answ == 's' || answ == 'S'){
			cout << "Columna A: " << endl;
			for (int i = 0; i < colA; i++){
				cout << i+1  << ". " << columnA[i] << endl;
			}
			cout << "Columna B: " << endl;
			for (int i = 0; i < colB; i++){
				cout << i+1  << ". " << columnB[i] << endl;
			}
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
			correct = 0, count = 0;
			for (int i = 0; i < colA; i++){
				mixedColumnA.push_back(columnA[i]);
			}
			for (int i = 0; i < colB; i++){
				mixedColumnB.push_back(columnB[i]);
			}
			for (int i = 0; i < colA; i++){
				random_shuffle(mixedColumnA.begin(), mixedColumnA.end());
			}
			for (int i = 0; i < colB; i++){
				random_shuffle(mixedColumnB.begin(), mixedColumnB.end());
			}
			
			answ = 's';
			while(answ == 's' || answ == 'S'){
				cout << "Columna A: " << endl;
				for (int i = 0; i < colA; i++){
					cout << i+1 << ". "  << mixedColumnA[i] << endl;
				}
				cout << "Columna B: " << endl;
				for (int i = 0; i < colB; i++){
					cout << i+1 << ". "  << mixedColumnB[i] << endl;
				}
				cout << "Columna A: ";
				cin >> ansA;
				cout << "Columna B: ";
				cin >> ansB;
				for (int i = 0; i < colA; i++){
					if (strcmp(mixedColumnA[ansA-1], columnA[i]) == 0){
						ansA2 = i+1;
					}
				}
				for (int i = 0; i < colB; i++){
					if (strcmp(mixedColumnB[ansB-1], columnB[i]) == 0){
						ansB2 = i+1;
					}
				}
				for (int i = 0; i < answersA.size(); i++){
					if (answersA[i] == ansA2 && answersB[i] == ansB2){
						correct++;
					}
				}
				count++;
				cout << "¿Desea continuar? S/N " << endl;
				cin >> answ;
			}
			double percentage = correct/count;
			percentage*=100;
			cout << endl << setprecision(0) << fixed << "Su nota es: " << percentage << "\%" << endl << endl;
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
	return 0;
}
