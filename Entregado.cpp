//Ethan Muñoz López          19300098                3C         21/10/2020
#include <iostream> //Incluimos las librerias
#include <array>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Alumnos //Crearemos una estructura que contenga los principales caracteristicas de nuestra lsita de alumnos
{
    vector<int>registros;
    vector<string>nombres;
    vector<string>apellido1;
    vector<string>apellido2;
    vector<string> materias;
};

int obtenerCantidad() { //Creemos una funcion para leer un entero
    int cantidad = 0;
    cin >> cantidad;
    return cantidad;
}

float obtenerAprobacion(int nEstudiantes, int nMaterias, int calificaciones[40][20], vector<string>materias, int varArregloJ) {
    int aprobados = 0; //Aprobados sera un contador de alumnos que aprovaron
        for (int i = 0; i < nEstudiantes; i++) {
            if (calificaciones[varArregloJ][i] >= 70) { //Vemos si la calificacion es aprobatoria y si si sumamos uno a nuestra 
                aprobados++;                            //variable que cuenta los alumnos que aprobaron
            }
        }
    //Zona de calculo aciertos*10/total
    float aprobadosP = 0; //Creamos una variable de porcentaje
    aprobadosP = ((aprobados * 100) / nEstudiantes); //Utilizamos la formula con 100 debido a que es calificacion sobre 100 en vez de entre 10
    return aprobadosP;
}

void imprimirPorcentajes() {

}

int main() { //Ethan Muñoz López          19300098                3C         21/10/2020
    printf("Bienvenido!\nCalificaremos a los alumnos de un grupo\n");
    Alumnos listaAlumnos; //Instanciamos la lista de alumnos
    printf("Cuantos estudiantes vamos a guardar?: ");
    int cantidadEstudiantes = obtenerCantidad(); //Obtenemos las cantidades
    cout << "Cuantas materias llevan?\n";
    int cantidadMaterias = obtenerCantidad();
    printf("Muy bien, llenemos los datos alumno por alumno\n");
    printf("\n\n---------------------------\n\n");
	int provisionalRegistro = 0;
    string provisionalNombre = " ";
    string provisionalApellido1 = " ";
    string provisionalApellido2 = " ";
    for (int i = 0; i < cantidadEstudiantes; i++){ //En este ciclo llenamos los datos del alumno
        printf("\nRegistro: ");
        cin >> provisionalRegistro;
        printf("\nNombre: ");
        cin >> provisionalNombre;
        printf("\nApellido 1: ");
        cin >> provisionalApellido1;
        printf("\nApellido 2: ");
        cin >> provisionalApellido2;
        listaAlumnos.registros.push_back(provisionalRegistro); //Aqui pasamos todos los datos que hemos almacenado en nuestra estructura con el push back
        listaAlumnos.nombres.push_back(provisionalNombre);
        listaAlumnos.apellido1.push_back(provisionalApellido1);
        listaAlumnos.apellido2.push_back(provisionalApellido2);
    }

    printf("Ingrese el nombre de las materias (Una por una):\n");
    for (int x = 0; x < cantidadMaterias; x++) {
        listaAlumnos.materias.push_back(""); //LLenaremos las materias de nuestra estructura
        cin >> listaAlumnos.materias[x];     //Y reestablecemos el valor que hemos pasado con uno ingresado por el usuario
    }
    
    //Llenado de materias
    int provicionalCalif = 0;
    int arregloCalificaciones[40][20];
    printf("Llenado de calificaciones\n\n");
    for (int j = 0; j < cantidadEstudiantes; j++) {
        cout << "Ingresa la calificacion de " << listaAlumnos.registros[j];     //Imprimiremos los registros para pedirle las calificaciones
        int calificacionIP = 0;
       for (int i = 0; i < cantidadMaterias; i++) {									                                                              
            cout << " en la clase " << listaAlumnos.materias[i] << ": "; 
            cin >> calificacionIP;
            arregloCalificaciones[j][i] = calificacionIP;
            printf("\n");
        }
    }

    string verAprobacion = "";
    cout << "Deseas ver el porcentaje de aprobacion y reprobacion por materia?\nUsa si/no: ";   //Preguntaremos si se quiere ver o no el porcentaje de aprobacion, porque se debe incluir la opcion
    cin >> verAprobacion;                                                                       //Le pedimos que nos responda con si/no para más adelante al imprimir añadir o no la opcion
    string verPasaron = "";
    cout << "Deseas ver que estudiantes pasaron cada materia? Usa si/no: ";
    cin >> verPasaron;
    //Impresion del formato
    printf("Registro escolar de un grupo\n\n____________________________________________________________\n\n");
    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (i == 0) {
            cout << setw(50);
            for (int j = 0; j < listaAlumnos.materias.size(); j++) {
                cout << listaAlumnos.materias[j] << "          ";
            }
            printf("\n\n");
        }
        cout << listaAlumnos.registros[i] << "   " << listaAlumnos.nombres[i] << "   ";
        cout << listaAlumnos.apellido1[i] << "   " << listaAlumnos.apellido2[i] << "   ";
        cout << "            ";
        for (int j = 0; j < cantidadMaterias; j++) {
            cout << arregloCalificaciones[i][j] << "          "; //Imprimos las calificaciones 
        }
        printf("\n");
    }
    printf("\n\n");
    if (verAprobacion == "si") { //En el caso de que el usuario nos haya dicho que si quiere ver los porcentajes añadimos esta opcion
        for (int j = 0; j < cantidadMaterias; j++) {
            cout << "El porcentaje de aprobacion de " << listaAlumnos.materias[j] << " es ";
            float porcentajeAprobacion = obtenerAprobacion(cantidadEstudiantes, cantidadMaterias, arregloCalificaciones, listaAlumnos.materias, j);
            cout << porcentajeAprobacion << "%\n";
            //Verificar Reprobacion
            float porcentajeReprobados = 0;
            porcentajeReprobados = 100 - porcentajeAprobacion;
            cout << "El porcentaje de reprobacion de " << listaAlumnos.materias[j] << " es ";
            cout << porcentajeReprobados << "%\n";
        }
    }    
    printf("\n\n________________________________________\n\n");
    if (verPasaron == "si") { //En el caso de que el usuario nos haya dicho que si quiere ver los aprobados añadimos esta opcion
        for (int j = 0; j < cantidadMaterias; j++) {
            printf("\n\n-----------\n");
            cout << "Aprobaron la materia " << listaAlumnos.materias[j] << "\n";
            for (int i = 0; i < cantidadEstudiantes; i++) {
                if (arregloCalificaciones[i][j] >= 70) {
                    cout << listaAlumnos.nombres[i] << " " << listaAlumnos.apellido1[i] << " " << listaAlumnos.apellido2[i] <<" con calificacion de " << arregloCalificaciones[i][j] << "\n";
                }
            }
        }
    }
    printf("\n\n________________________________________\n\n");
    printf("Genial! Ten un buen dia\n\n");
    return 0;
}
