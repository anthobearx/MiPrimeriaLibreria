//Consola.java
//Clase para contener los métodos nativos
public class Consola{
	//Métodos nativos (ahora estaticos)
	public static native void limpiarConsola();
	public static native void cambiarTitulo(String titulo);
	public static native void colocarDatos(String s1,String s2,String s3,String s4,String s5);

	
	static{
	System.loadLibrary("Consola");
	}
	

}