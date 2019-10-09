#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_STRING_LENGTH 256

//NB funziona, ma fa schifo
//correggerlo e commentarlo

// consumatore.c e' un filtro
int main(int argc, char* argv[]){

	char read_char, charToRemove[MAX_STRING_LENGTH];
	int nread, fd, trovato;
	
	//charSeq mi servirà per considerare ciascun carattere della stringa FILTRO
	char carSeq;

	//per leggibilità memorizzo la stringa filtro nel puntatore a caratteri charToRemove
	strcpy(charToRemove, argv[1]);
	
	//argc == 3
	//parametri assegnati:
	// nomeprogramma.c ciao nomefile.txt
	if( argc == 3 ){

		fd = open(argv[2], O_RDONLY);
		if (fd < 0){
			perror("P0: Impossibile aprire il file.");
			exit(2);
		}
	//argc ==2 
	//parametri assegnati:
	//nomeprogramma.c ciao < nomefile.txt
	} else if (argc == 2){
		fd = STDIN_FILENO;
	} else {
		perror("Numero di argomenti errato");
		exit(1);
	}
	
	while (nread = read(fd, &read_char, sizeof(char))) /* Fino ad EOF*/{
		if (nread < 0) {
			perror("Errore nella lettura del file");
			exit(3);
		}
		//trovato mi dice se il carattere letto è uguale a un carattere presente nella stringa FILTRO
		trovato = 0;
		//se metto prima la condizione trovato e la condizione trovato è falsa, allora non mi valuta i<strlen(..)
		for (int i = 0; !trovato && i < strlen(charToRemove); i++){
			//salvo ciascun carattere volta per volta della stringa filtro nel char carSeq
			carSeq = charToRemove[i];

			if (read_char == carSeq){
				trovato = 1;
			} 
				
		}

		if (!trovato){
			putchar(read_char);
		}
	}
	close(fd);

}