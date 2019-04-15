#include "CaesarCrypt.h"

/*
 * Class:     cipher_implementation_CaesarCipher
 * Method:    setNumShifts
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_cipher_implementation_CaesarCipher_setNumShifts
(JNIEnv*, jobject, jint) {

}

/*
 * Class:     cipher_implementation_CaesarCipher
 * Method:    encrypt
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cipher_implementation_CaesarCipher_encrypt
(JNIEnv* env, jobject obj, jstring str)
{
	return str;
}

/*
 * Class:     cipher_implementation_CaesarCipher
 * Method:    decrypt
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cipher_implementation_CaesarCipher_decrypt
(JNIEnv* env, jobject obj, jstring str)
{
	return str;
}

