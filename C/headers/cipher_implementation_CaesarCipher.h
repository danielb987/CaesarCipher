/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class cipher_implementation_CaesarCipher */

#ifndef _Included_cipher_implementation_CaesarCipher
#define _Included_cipher_implementation_CaesarCipher
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     cipher_implementation_CaesarCipher
 * Method:    setNumShifts
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_cipher_implementation_CaesarCipher_setNumShifts
  (JNIEnv *, jobject, jint);

/*
 * Class:     cipher_implementation_CaesarCipher
 * Method:    encrypt
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cipher_implementation_CaesarCipher_encrypt
  (JNIEnv *, jobject, jstring);

/*
 * Class:     cipher_implementation_CaesarCipher
 * Method:    decrypt
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cipher_implementation_CaesarCipher_decrypt
  (JNIEnv *, jobject, jstring);

#ifdef __cplusplus
}
#endif
#endif
