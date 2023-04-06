//Consola.java
//Clase para contener los métodos nativos
public class Consola{
	//Métodos nativos (ahora estaticos)
	public static native void limpiarConsola();
	public static native void cambiarTitulo(String titulo);


	//modificacion
	public static native void cambiarColor(int color);
	public static native void cambiarCursor(int x, int y);

	
	static{
	System.loadLibrary("Consola");
	}
	

}