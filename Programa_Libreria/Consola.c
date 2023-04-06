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

JNIEXPORT void JNICALL Java_Consola_colocarDatos(JNIEnv *env, jclass clase, jstring s1, jstring s2, jstring s3, jstring s4, jstring s5)
{
    HANDLE hStdout;
    COORD posicion;
    DWORD escritos;

    // Obtener manejador (HANDLE) de pantalla
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    // Posicion del cursor
    posicion.X = 0;
    posicion.Y = 0;

    // Llamar la funcion para posicionarn el cursor
    SetConsoleCursorPosition(hStdout, posicion);

    // Convertir los jstring a cadenas ANSI
    const char* str1 = (*env)->GetStringUTFChars(env, s1, NULL);
    const char* str2 = (*env)->GetStringUTFChars(env, s2, NULL);
    const char* str3 = (*env)->GetStringUTFChars(env, s3, NULL);
    const char* str4 = (*env)->GetStringUTFChars(env, s4, NULL);
    const char* str5 = (*env)->GetStringUTFChars(env, s5, NULL);

    // Escribir en la consola
    SetConsoleTextAttribute(hStdout, 0x7);//gris
    WriteConsole(hStdout, str1, strlen(str1), &escritos, NULL);

    posicion.X = 30;
    SetConsoleCursorPosition(hStdout, posicion);
    SetConsoleTextAttribute(hStdout, 0xD);//Purpura
    WriteConsole(hStdout, str2, strlen(str2), &escritos, NULL);

    posicion.Y = 10;
    SetConsoleCursorPosition(hStdout, posicion);
    SetConsoleTextAttribute(hStdout, 0xE);//Amarillo
    WriteConsole(hStdout, str3, strlen(str3), &escritos, NULL);

    posicion.X = 50;
    posicion.Y = 15;
    SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE);
    SetConsoleCursorPosition(hStdout, posicion);
    WriteConsole(hStdout, str4, strlen(str4), &escritos, NULL);

    posicion.X = 50;
    posicion.Y = 20;
    SetConsoleCursorPosition(hStdout, posicion);
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED);
    WriteConsole(hStdout, str5, strlen(str5), &escritos, NULL);
//Resetear
 posicion.X = 0;
 posicion.Y = 25;
SetConsoleCursorPosition(hStdout, posicion);
SetConsoleTextAttribute(hStdout, 0xF);

    // Liberar la memoria de los strings ANSI
    (*env)->ReleaseStringUTFChars(env, s1, str1);
    (*env)->ReleaseStringUTFChars(env, s2, str2);
    (*env)->ReleaseStringUTFChars(env, s3, str3);
    (*env)->ReleaseStringUTFChars(env, s4, str4);
    (*env)->ReleaseStringUTFChars(env, s5, str5);
}

