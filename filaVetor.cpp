#include <iostream>
using namespace std;

#define MAX 5

struct Fila {
	int ini;
	int fim;
	float nos[MAX];
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = 0;
	f->fim = 0;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == f->fim);
}

int incrementa(int i) {
	return (i==MAX?0:++i);
	/*
	int ret;
	if (i == MAX) {
		ret = 0;
	}
	else {
		ret = i + 1;
	}
	return ret;
	*/
}

int count(Fila *f) {
	int qtde = 0;
	int i = f->ini;
	while (i != f->fim) {
		qtde++;
		i = incrementa(i);
	}
	return qtde;
}

void print(Fila *f) {
	int i = f->ini;
	cout << "------------" << endl;
	while (i != f->fim) {
		cout << f->nos[i] << endl;
		i = incrementa(i);
	}
    cout << "------------" << endl;
}

void freeFila(Fila *f) {
	free(f);
}

// Enfileirar
int enqueue(Fila *f, float v) {
	//int podeEnfileirar = (count(f) < MAX);
	int podeEnfileirar = (incrementa(f->fim) != f->ini);
	if (podeEnfileirar) {
		f->nos[f->fim] = v;
		f->fim = incrementa(f->fim);
	}
    return podeEnfileirar;	
}

// Desenfileirar
float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		ret = f->nos[f->ini];
		f->ini = incrementa(f->ini);
	}
	return ret;
}


int main(int argc, char** argv)
{
	Fila *filaFloat;
	filaFloat = init();
	cout << "Qtde de elementos na fila: " << count(filaFloat) << endl;
	print(filaFloat);
	cout << "Enfileirou ? " << (enqueue(filaFloat, 1.11)?"Sim":"Nao") << endl;
	cout << "Enfileirou ? " << (enqueue(filaFloat, 2.22)?"Sim":"Nao") << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Enfileirou ? " << (enqueue(filaFloat, 3.33)?"Sim":"Nao") << endl;
	cout << "Enfileirou ? " << (enqueue(filaFloat, 4.44)?"Sim":"Nao") << endl;
	cout << "Enfileirou ? " << (enqueue(filaFloat, 5.55)?"Sim":"Nao") << endl;
	cout << "Enfileirou ? " << (enqueue(filaFloat, 6.66)?"Sim":"Nao") << endl;
		
	cout << "Qtde de elementos na fila: " << count(filaFloat) << endl;
	print(filaFloat);
	
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;

	cout << "Qtde de elementos na fila: " << count(filaFloat) << endl;
	print(filaFloat);
			
	
	return 0;
}