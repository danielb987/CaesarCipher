package cipher.implementation;

import cipher.Cipher;

/**
 * Caesar cipher
 * 
 * Info about JNI:
 * https://www3.ntu.edu.sg/home/ehchua/programming/java/JavaNativeInterface.html
 * https://www.ibm.com/developerworks/library/j-jni/index.html
 * https://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/jniTOC.html
 * 
 * On Windows, generate the JNI header file by running the command:
 *   javac -h ..\C\headers cipher\implementation\CaesarCipher.java
 * in the src folder.
 * 
 * @author Daniel Bergqvist
 */
public class CaesarCipher implements Cipher {
    
    static {
        String folder;
        
        folder = "C/Windows/CaesarCrypt_Windows/Debug/";
        
        // Load native library caesar.dll (Windows) or libcaesar.so (Unixes) at runtime
        // This library contains a native method called sayHello()
        System.loadLibrary(folder+"CaesarCrypt_Windows");
    }
    
    public native void setNumShifts(int num);
    
    @Override
    public native String encrypt(String message);
    
    @Override
    public native String decrypt(String message);
    
}
