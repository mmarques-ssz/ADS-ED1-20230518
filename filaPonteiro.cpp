#include <iostream>
using namespace std;

struct No {
	float dado;
	struct No *prox;
};

struct Fila {
	No *ini;
	No *fim;
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == NULL);
}

int count(Fila *f) {
	int qtde = 0;
	No *no;
	no = f->ini;
	while(no != NULL) {
		qtde++;
		no = no->prox;
	}
	return qtde;
}

void print(Fila *f) {
	No *no;
	no = f->ini;
	cout << "------------" << endl;
	while(no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "------------" << endl;
}

void freeFila(Fila *f) {
	No *no = f->ini;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
	free(f);
}

// Enfileirar
void enqueue(Fila *f, float v) {
	No *no = new No;
	no->dado = v;
	no->prox = NULL;
	if (isEmpty(f)) {
	   f->ini = no;
	}
	else {
		f->fim->prox = no;
	}
	f->fim = no;
}


// Desenfileirar
float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		No *no = f->ini;
		ret = no->dado;
		f->ini = no->prox;
		if (f->ini == NULL) {
			f->fim = NULL;
		}
		free(no);
	}
	return ret;
}

int main(int argc, char** argv)
{
	Fila *filaFloat;
	filaFloat = init();
	
	cout << "Qtde de elementos na fila: " << count(filaFloat) << endl;
	print(filaFloat);
	
	enqueue(filaFloat, 1.11);
	enqueue(filaFloat, 2.22);
	enqueue(filaFloat, 3.33);
	enqueue(filaFloat, 4.44);
	
	cout << "Qtde de elementos na fila: " << count(filaFloat) << endl;
	print(filaFloat);
	
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
    cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
    
    cout << "Qtde de elementos na fila: " << count(filaFloat) << endl;
	print(filaFloat);
	
	enqueue(filaFloat, 5.55);
	
	cout << "Qtde de elementos na fila: " << count(filaFloat) << endl;
	print(filaFloat);
	
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
    cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
    
    cout << "Qtde de elementos na fila: " << count(filaFloat) << endl;
	print(filaFloat);
	
	freeFila(filaFloat);
	
	return 0;
}