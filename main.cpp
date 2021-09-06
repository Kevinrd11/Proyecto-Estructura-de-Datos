// Estudiante: Kevin Rojas Duran
// Profesora: Lorena
// Curso: Estructura de Datos 
// 2da Tarea: Primer avance del proyecto

#include <iostream>
using namespace std;

// Lista para los cursos
struct Curso{

    string codigo;
    string nombre;
    int creditos;

    Curso *sig;
    struct grupo * subListaGrupos;

    // Constructor 
    Curso(string cod, string nom, int cred){
        codigo = cod;
        nombre = nom;
        creditos = cred;
        sig = NULL;
        subListaGrupos = NULL;
    }
}*primeroCurso;// primero de la lista de cursos

// Lista para los grupos
struct Grupo{

    int idGrupo;// 10, 50 ...

    Grupo *sig;
    struct curso * enlaceCurso;

    struct asignaciones* subListaTareas;
    struct asignaciones* subListaProyectos;
    struct asignaciones* subListaGiras;
    struct asignaciones* subListaExamen;

    Grupo( int id){
        idGrupo = id;
        sig = NULL;
        enlaceCurso = NULL;
        subListaTareas= NULL;
        subListaProyectos = NULL;
        subListaGiras= NULL;
        subListaExamen= NULL;
    }
};
//no tiene un primero de grupos

// Lista para las asignaciones
 struct Asignaciones{

    int idA;
    string nombre;
    int portacentaje;
    //fecha de entrega
    int dia,mes, a; //  date fecha;// time.h
    asignaciones*sig;
    Asignaciones(int id, string nom, int p, int d, int m, int year){
        idA= id;
        nombre = nom;
        portacentaje = p;
        dia = d;
        mes= m;
        a = year;
        sig = NULL;
    }

 };
//no tiene un primero de asignaciones

// Puntero para Grupos asignados
struct GruposAsignados{

        GruposAsignados* sig;
        struct Grupo *enlace;

};
//no tiene un primero de GruposAsignados

// Lista para profesor
struct profesor{
    int cedula;
    string nombre;
    profesor *sig, *ant;//Lista doble
    GruposAsignados* subListaGruposAsignados;

}*primeroProfesor;//el primero de la lista de profesores

 //asignar una tarea, o un examen o una gira, o
 //proyecto en un grupo en especifico que imparte un profesor
 void asignarAsignaciones(string tipo, int id, string nom, int p, int d, int m, int year, string codCurso, int idGrupo, int cedula){

   
   ////*********************************PRESENTA UN ERRROR ESTA PARTE!!!!! **********************************************
    //********************************************************************************************************

     // Parte del codigo de  la profesora, pero no funciona: falta la función buscarProfesor (creo)

    //********************************************************************************************************

    profesor* tempProf = buscarProfesor(cedula);
    if(tempProf == NULL){
        cout<<"No se encuentra el profesor");
        return NULL;
    }
// si existe el profesor
 else{
 
    GruposAsignados *temp = tempProf->subListaGruposAsignados;
    //verificar si tiene el grupo asignado
    while(temp!= NULL){
        if(temp->enlace->idGrupo == idGrupo)
                if(temp->enlace->enlaceCurso->codigo ==codCurso){
                    //si lo tiene asignado
                    Asignaciones *nn = new Asignaciones(id,nom,p,d,m,year);
                    //ocupo saber en cual de las cuatros  sublista es

                   //FALTA la programacion de insertar ordenado por fecha de entrega.
                   // Hacer esta parte con menos codigo.
                    if(tipo == "Proyecto" ){

                        nn->sig = temp->enlace->subListaProyectos;
                        temp->enlace->subListaProyectos = nn;// aqu� se hizo insercion al inicio y no ORDENADO
                    }
                    else if(tipo == "Tarea" ){

                        nn->sig = temp->enlace->subListaTareas;
                        temp->enlace->subListaTareas = nn;
                    }
                    else if(tipo == "Giras" ){

                        nn->sig = temp->enlace->subListaGiras;
                        temp->enlace->subListaGiras = nn;
                    }
                    else if(tipo == "Examen" ){

                        nn->sig = temp->enlace->subListaExamen;
                        temp->enlace->subListaExamen = nn;
                    }
                    else{
                        cout<<"El tipo de asignacion no existe";
                        return;

                    }
                    cout<<"Se inserto la asignacion correctamente";
                    break;// Salir del bloque cuando se inserta
                }

        temp = temp->sig;
    }
    if(temp == NULL){

        cout<<"No tiene el curso asignado";
        return;
    }
 }





 }





int main()
{
//...

   //asignar asignaciones a un grupo en especifico que imparte un profesor
   asignarAsignaciones("Proyecto", 1, "Proyecto programado1", 15, 28, 9, 2021, "IC2000", 50,
                       2520730);

    return 0;
}
