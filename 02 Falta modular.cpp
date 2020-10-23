//Ethan Muñoz López          19300098                3C         21/10/2020
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Alumnos
{
    vector<int>registros;
    vector<string>nombres;
    vector<string>apellido1;
    vector<string>apellido2;
    vector<string> materias;
};

float obtenerAprobacion(int nEstudiantes, int nMaterias, int calificaciones[100][100], vector<string>materias, int varArregloJ) {
    int aprobados = 0;
        for (int i = 0; i < nEstudiantes; i++) {
            if (calificaciones[varArregloJ][i] >= 70) {
                aprobados++;
            }
        }
    //Zona de calculo aciertos*10/total
    float aprobadosP = 0;
    aprobadosP = ((aprobados * 100) / nEstudiantes);
    return aprobadosP;
}

int main() {
    //Ethan Muñoz López          19300098                3C         21/10/2020
    int cantidadMaterias = 0;
    int cantidadEstudiantes = 0;
    printf("Bienvenido!\nCalificaremos a los alumnos de un grupo\n");
    Alumnos listaAlumnos;
    printf("Cuantos estudiantes vamos a guardar?: ");
    cin >> cantidadEstudiantes;
    cout << "Cuantas materias llevan?\n";
    cin >> cantidadMaterias;
    //
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
        listaAlumnos.registros.push_back(provisionalRegistro);
        listaAlumnos.nombres.push_back(provisionalNombre);
        listaAlumnos.apellido1.push_back(provisionalApellido1);
        listaAlumnos.apellido2.push_back(provisionalApellido2);
    }
    //
    printf("Ingrese el nombre de las materias (Una por una):\n");
    for (int x = 0; x < cantidadMaterias; x++) {
        listaAlumnos.materias.push_back("");
        cin >> listaAlumnos.materias[x];
    }
    
    //Llenado de materias
    int provicionalCalif = 0;
    const int cantidadEstudiantesC = cantidadEstudiantes;
    const int cantidadMateriasC = cantidadMaterias;
    int arregloCalificaciones[100][100];
    printf("Llenado de calificaciones\n\n");
    for (int j = 0; j < cantidadEstudiantes; j++) {
        cout << "Ingresa la calificacion de " << listaAlumnos.registros[j];
        int calificacionIP = 0;
       for (int i = 0; i < cantidadMaterias; i++) {									                                                              
            cout << " en la clase " << listaAlumnos.materias[i] << ": "; 
            cin >> calificacionIP;
            arregloCalificaciones[j][i] = calificacionIP;
            printf("\n");
        }
    }

    string verAprobacion = "";
    cout << "Deseas ver el porcentaje de aprobacion y reprobacion por materia?\nUsa si/no: ";
    cin >> verAprobacion;

    //Impresion del formato
    printf("Registro escolar de un grupo\n\n____________________________________________________________\n\n");
    for (int i = 0; i < cantidadEstudiantes;i++){
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
            cout << arregloCalificaciones[i][j] << "          ";
        }
        printf("\n");
    }
    printf("\n\n");
    if (verAprobacion == "si") {
        for (int j = 0; j < cantidadMaterias; j++) {
            cout << "El porcentaje de aprobacion de " << listaAlumnos.materias[j] << " es ";
            float porcentajeAprobacion = obtenerAprobacion(cantidadEstudiantes, cantidadMaterias, arregloCalificaciones, listaAlumnos.materias, j);
            cout << porcentajeAprobacion << "%\n";
            //Verificar Reprobacion
            float porcentajeReprobados = 0;
            porcentajeReprobados = 100 - porcentajeAprobacion;            
            cout << "El porcentaje de reprobacion de " << listaAlumnos.materias[j] << " es ";
            cout << porcentajeReprobados << "%\n" ;
        }
    }
    printf("Genial! Ten un buen dia\n\n");
    return 0;
}
