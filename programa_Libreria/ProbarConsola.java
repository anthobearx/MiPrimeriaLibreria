//ProbarConsola.java
//Programa para probar los metodos nativos de Consola.DLL
import java.util.Scanner;

public class ProbarConsola{
    public static void main(String[] args){
	

	Scanner scanner = new Scanner(System.in);
	String titulo;
	
	//Datos mios
	String nombre = "Nombre: Jesus Antonio";
	String apellido = "Apellidos: Vega Gonzalez";
	String nombreMateria = "Materia: Topicos Avanzados de Programacion";
	String edad = "Edad: 21";
	String colorFavorito = "Color favorito: Rojo";
	
	//Pedir titulo de la ventana
	System.out.print("Escribe un nombre para la ventana>>");
	titulo = scanner.nextLine();

 	//**Limpiar la consola (como es estatico, no ocupo crear objeto)
        Consola.limpiarConsola();

        //**Poner datos 1
	Consola.cambiarColor(1);
	Consola.cambiarCursor(0,0);
	System.out.println(nombre);

	//**Poner datos 2
	Consola.cambiarColor(2);
	Consola.cambiarCursor(30,0);
	System.out.println(apellido);
	
	//**Poner datos 3
	Consola.cambiarColor(3);
	Consola.cambiarCursor(60,0);
	System.out.println(edad);

	//**Poner datos 4
	Consola.cambiarColor(5);
	Consola.cambiarCursor(20,5);
	System.out.println(nombreMateria);

	//**Poner datos 5
	Consola.cambiarColor(4);
	Consola.cambiarCursor(20,10);
	System.out.println(colorFavorito);

	//**Poner titulo
	Consola.cambiarTitulo(titulo);
	
    }
}