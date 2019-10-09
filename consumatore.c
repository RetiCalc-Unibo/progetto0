#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_STRING_LENGTH 256

int main(int argc, char* argv[]) {
	char read_char, charToRemove[MAX_STRING_LENGTH], carSeq;
	int nread, fd, trovato;
	
	strcpy(charToRemove, argv[1]);
	
	if (argc == 3) {
		fd = open(argv[2], O_RDONLY);
		if (fd < 0){
			perror("Impossibile aprire il file.");
			exit(1);
		}
	} else if (argc == 2) {
		fd = STDIN_FILENO;
	} else {
		perror("Numero di argomenti errato");
		exit(2);
	}
	
	while (nread = read(fd, &read_char, sizeof(char))) /* Fino ad EOF */ {
		if (nread < 0) {
			perror("Errore nella lettura del file");
			exit(3);
		}

		trovato = 0;
		
		for (int i = 0; !trovato && i < strlen(charToRemove); i++) {
			carSeq = charToRemove[i];

			if (read_char == carSeq) {
				trovato = 1;
			}	
		}

		if (!trovato) {
			putchar(read_char);
		}
	}

	close(fd);
}