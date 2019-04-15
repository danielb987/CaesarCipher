package cipher;

/**
 * The Cipher interface
 * 
 * @author Daniel Bergqvist
 */
public interface Cipher {
    
    /**
     * Encrypt a message
     * 
     * @param message the message to encrypt
     * @return the encrypted message
     */
    public String encrypt(String message);
    
    /**
     * Decrypt a message
     * 
     * @param message the encrypted message
     * @return the original message
     */
    public String decrypt(String message);
    
}
