import java.io.FileReader;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.io.FileNotFoundException;

public class Consumatore {
	public static void main(String[] args) {
		BufferedReader bufferedReader = null;
		boolean charIsPresent = false;
		String characters_to_remove;
		int nread;
		char read_char;
		
		// Controllo numero argomenti
		if (args.length < 1 || args.length > 2) {
			System.out.println("Il numero di argomenti in input è errato.\n");
			System.exit(0);
		}

		characters_to_remove = args[0];

		if (args.length == 1) { // Nel caso in cui passo soltanto i caratteri come argomento e ridirigo il file di testo in input
			bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		}
		else if (args.length == 2) { // Nel caso in cui passo sia i caratteri che il nome del file negli argomenti
			try {
				bufferedReader = new BufferedReader(new FileReader(args[1]));
			}
			catch(FileNotFoundException e) {
				System.out.println("Il file non è stato trovato.\n");
				System.exit(1);
			}
		}

		try {
			while ((nread = bufferedReader.read()) >= 0) {
				read_char = (char) nread;
				for (int i = 0; i < characters_to_remove.length() && !charIsPresent; i++) {
					if (read_char == characters_to_remove.charAt(i)) {
						charIsPresent = true;
					}
				}

				if (!charIsPresent) {
					System.out.print(read_char);
				}

				charIsPresent = false;
			}

			System.out.print("\n");
			bufferedReader.close();
		}
		catch (IOException e) {
			System.out.println("Errore di input.\n");
			System.exit(2);
		}
	}
}