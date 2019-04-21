package cipher.implementation;

import cipher.Cipher;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * An implementation of CaesarCipher that uses a Linux Kernel Module.
 * This only works on Linux and only if the Linux Kernel Module is loaded.
 * 
 * @author Daniel Bergqvist
 */
public class CaesarCipher_KernelModule implements Cipher {

    private static final String PATH = "/proc/daniel.bergqvist/caesar_cipher/";
    
    
    private String convert(String inFileName, String outFileName, String message) {
        
        // This will reference one line at a time
        String line = null;

        try( BufferedReader bufferedReader = new BufferedReader(new FileReader(inFileName));
                PrintWriter bufferedWriter = new PrintWriter(new BufferedWriter(new FileWriter(outFileName)))
                ) {
            
            bufferedWriter.println(message);
            bufferedWriter.close();
            
            while ((line = bufferedReader.readLine()) != null) {
                return line;
            }
            
            // If here, there was no data to read.
            return "Error: No data";
        }
        catch(FileNotFoundException ex) {
            return "Error: Unable to open file";
        }
        catch(IOException ex) {
            return "Error: Error reading or writing file";
        }
    }
    
    @Override
    public String encrypt(String message) {
        return convert(PATH+"encrypt_in", PATH+"encrypt_out", message);
    }

    @Override
    public String decrypt(String message) {
        return convert(PATH+"decrypt_in", PATH+"decrypt_out", message);
    }
    
}
