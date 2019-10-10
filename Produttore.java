import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;

public class Produttore {
	public static void main(String[] args) {		
		BufferedReader in = null;
		
		if (args.length != 1) {
			System.out.println("Utilizzo: produttore <inputFilename>");
			System.exit(1);
		}
		
		in = new BufferedReader(new InputStreamReader(System.in));
			
		FileWriter fout;
		
		try {
			String line;
			fout = new FileWriter(args[0]);

			while ((line = in.readLine()) != null) {
				fout.write(line, 0, line.length());
				fout.write("\n");
			}

			fout.close();
		}
	    catch (IOException e) {
			e.printStackTrace();
			System.exit(2);
		}
	}
}
