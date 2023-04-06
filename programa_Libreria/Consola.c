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

JNIEXPORT void JNICALL Java_Consola_cambiarTitulo(JNIEnv *env, jclass clase, jstring titulo)
{
	const jchar *str = (*env)->GetStringChars(env, titulo, NULL);
    if (str != NULL) {
        DWORD len = (*env)->GetStringLength(env, titulo);
        int size = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)str, len, NULL, 0, NULL, NULL);
        char *buf = (char*)malloc(size + 1);
        if (buf != NULL) {
            WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)str, len, buf, size, NULL, NULL);
            buf[size] = '\0';
            SetConsoleTitle(buf);
            free(buf);
        }
        (*env)->ReleaseStringChars(env, titulo, str);
    }
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

