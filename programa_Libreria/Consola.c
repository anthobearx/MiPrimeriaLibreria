//despues de ejecutar javah
//Consola.c
//implementacion de las funciones de la libreria Consola.DLL
#include <jni.h>
#include "Consola.h"
#include <stdlib.h>			//lib para system
#include <windows.h>		//para las demas funciones

JNIEXPORT void JNICALL Java_Consola_limpiarConsola(JNIEnv *env, jclass clase)
{
	system("cls");
}

JNIEXPORT void JNICALL Java_Consola_cambiarTitulo(JNIEnv* env, jclass objeto, jstring titulo) {
    const char* str = (*env)->GetStringUTFChars(env, titulo, 0);
    SetConsoleTitle(str);
    system("pause");
}

JNIEXPORT void JNICALL Java_Consola_cambiarColor(JNIEnv* env, jclass clase, jint color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);//conseguir el objeto para imprimir en consola
    SetConsoleTextAttribute(hStdout,color);
}

JNIEXPORT void JNICALL Java_Consola_cambiarCursor(JNIEnv* env, jclass clase, jint x, jint y)
{
    //conseguir el objeto para imprimir en consola
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    //variable para guardar la posicion
    COORD posicion;
    posicion.X = x;
    posicion.Y = y;
    //colocar la posicion
    SetConsoleCursorPosition(hStdout, posicion);
}

