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


        //**Poner datos
        Consola.colocarDatos(nombre, apellido, edad, nombreMateria,  colorFavorito);

	
	//**Poner titulo
	Consola.cambiarTitulo(titulo);
	

       

        //Mensaje en Java que ya termino
        //System.out.println("Finalizado");

	
    }
}