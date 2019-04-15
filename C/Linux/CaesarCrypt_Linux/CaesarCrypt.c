#include "CaesarCrypt.h"
#include <string.h>
#include <malloc.h>

const char* UCASE_LETTERS = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
const char* LCASE_LETTERS = "abcdefghijklmnopqrstuvxyz";

int numShifts = 0;


int getIndex(const char* letters, const char ch)
{
	for (int i = 0; i < strlen(letters); i++)
	{
		if (letters[i] == ch)
			return i;
	}

	return -1;
}

/*
 * Class:     cipher_implementation_CaesarCipher
 * Method:    setNumShifts
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_cipher_implementation_CaesarCipher_setNumShifts
(JNIEnv* env, jobject obj, jint num) {

	numShifts = num % strlen(UCASE_LETTERS);
}

/*
 * Class:     cipher_implementation_CaesarCipher
 * Method:    encrypt
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cipher_implementation_CaesarCipher_encrypt
(JNIEnv* env, jobject obj, jstring str)
{
	const char* str1 = (*env)->GetStringUTFChars(env, str, NULL);

	char* str2 = (char*) malloc(strlen(str1)+2);

	for (int i = 0; i < strlen(str1); i++)
	{
		int pos = getIndex(UCASE_LETTERS, str1[i]);

		if (pos != -1)
		{
			pos = (pos + numShifts) % strlen(UCASE_LETTERS);
			str2[i] = UCASE_LETTERS[pos];
		}
		else
		{
			pos = getIndex(LCASE_LETTERS, str1[i]);

			if (pos != -1)
			{
				pos = (pos + numShifts) % strlen(LCASE_LETTERS);
				str2[i] = LCASE_LETTERS[pos];
			}
			else
			{
				str2[i] = str1[i];
			}
		}
	}

	// Set zero as "end of string"
	str2[strlen(str1)] = '\0';

	jstring result = (*env)->NewStringUTF(env, str2);

	free(str2);

	return result;
}

/*
 * Class:     cipher_implementation_CaesarCipher
 * Method:    decrypt
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cipher_implementation_CaesarCipher_decrypt
(JNIEnv* env, jobject obj, jstring str)
{
	const char* str1 = (*env)->GetStringUTFChars(env, str, NULL);

	char* str2 = (char*)malloc(strlen(str1) + 2);

	for (int i = 0; i < strlen(str1); i++)
	{
		int pos = getIndex(UCASE_LETTERS, str1[i]);

		if (pos != -1)
		{
			pos -= numShifts;
			if (pos < 0)
				pos += strlen(UCASE_LETTERS);
			str2[i] = UCASE_LETTERS[pos];
		}
		else
		{
			pos = getIndex(LCASE_LETTERS, str1[i]);

			if (pos != -1)
			{
				pos -= numShifts;
				if (pos < 0)
					pos += strlen(UCASE_LETTERS);
				str2[i] = LCASE_LETTERS[pos];
			}
			else
			{
				str2[i] = str1[i];
			}
		}
	}

	// Set zero as "end of string"
	str2[strlen(str1)] = '\0';

	jstring result = (*env)->NewStringUTF(env, str2);

	free(str2);

	return result;
}

