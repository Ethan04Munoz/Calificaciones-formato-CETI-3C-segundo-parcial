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
    vector<vector<int>>calificaciones;
};

float obtenerAprobacion(int nEstudiantes, int nMaterias, vector<vector<int>>calificaciones, vector<string>materias) {
    int aprobados = 0;
        for (int i = 0; i <= nEstudiantes; i++) {
            if (calificaciones[1][i] > 69) {
                aprobados++;
            }
        }
    //Zona de calculo aciertos*10/total
    float aprobadosP = 0.0;
    aprobadosP = ((aprobados * 10) / nEstudiantes);
    return 0;
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
    string provicionalmaterias;
    for (int i = 0; i <= cantidadMaterias; i++) { //En este ciclo for llenamos los nombres de las materias
        getline(cin, provicionalmaterias);
        listaAlumnos.materias.push_back(provicionalmaterias);
    }
    //Llenado de materias
    int provicionalCalif = 0;
    printf("Llenado de calificaciones\n\n");
    for (int j = 0; j <= listaAlumnos.materias.size(); j++) {
        cout << listaAlumnos.materias[j] << "\n" ;
        for (int i = 0; i <= listaAlumnos.registros.size(); i++) {
            listaAlumnos.calificaciones.push_back(listaAlumnos.registros);
            cout << listaAlumnos.registros[i] << ": ";
            cin >> provicionalCalif;
            listaAlumnos.calificaciones[j][i].push_back(provicionalCalif);
        }
    }

    string verAprobacion = "";
    cout << "Deseas ver el porcentaje de aprobacion y reprobacion por materia?\nUsa si/no";
    cin >> verAprobacion;
    
    //Impresion del formato
    printf("Registro escolar de un grupo\n\n_____________________________________\n\n");
    for (int i = 0; i <= cantidadEstudiantes;i++){
        if (i == 0) {
            cout << setw(30);
            for (int j = 0; j <= listaAlumnos.materias.size(); j++) {
                cout << listaAlumnos.materias[j] << "    ";
            }
            printf("\n\n");
        }
        cout << listaAlumnos.registros[i] << "   " << listaAlumnos.nombres[i] << "   ";
        cout << listaAlumnos.apellido1[i] << "   " << listaAlumnos.apellido2[i] << "   ";
    }

    /*
    for (int j = 0; j <= materias.size(); j++) {
        cout << materias[j] << "\n";
        */
    //Verificar Reprobacion
    obtenerAprobacion(cantidadEstudiantes, cantidadMaterias, listaAlumnos.calificaciones, listaAlumnos.materias);


    return 0;
}
