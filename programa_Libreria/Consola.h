/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class Consola */

#ifndef _Included_Consola
#define _Included_Consola
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     Consola
 * Method:    limpiarConsola
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_Consola_limpiarConsola
  (JNIEnv *, jclass);

/*
 * Class:     Consola
 * Method:    cambiarTitulo
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_Consola_cambiarTitulo
  (JNIEnv *, jclass, jstring);

/*
 * Class:     Consola
 * Method:    cambiarColor
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_Consola_cambiarColor
  (JNIEnv *, jclass, jint);

/*
 * Class:     Consola
 * Method:    cambiarCursor
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_Consola_cambiarCursor
  (JNIEnv *, jclass, jint, jint);

#ifdef __cplusplus
}
#endif
#endif