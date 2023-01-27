/***********************************************************************
 * UFA-ESPE
 * Nombres: Steven Pozo,Quilumbaquin Jairo
 * Fecha de creacion: miércoles, 26 de octubre de 2022 19:06:30
 * Purpose: Implementation of the class Persona
 * Enunciado del problema: programar en datos abstractos para ingresar datos personales y calcular la edad
 ***********************************************************************/ 

#include <string>

using namespace std;

#if !defined(__UML_Class_Diagram_1_Persona_h)
#define __UML_Class_Diagram_1_Persona_h

class Persona
{
public:
   string getapellido(void);
   void setapellido(string newApellido);
   string getnombre(void);
   void setnombre(string newNombre);
   
   void setdiaNacimiento(int newDiaNacimiento);
   int getdiaNacimiento(void);
   void setmesNacimiento(int newMesNacimiento);
   int getmesNacimiento(void);
   
   int getanioNacimiento(void);
   void setanioNacimiento(int newAnioNacimiento);
   Persona();
   void pedirDatos(void);
   int calcularEdad();
   void imprimirEdad(void);
   
   

protected:
private:
   string apellido;
   string nombre;
   int anioNacimiento;
   int mesNacimiento;
   int diaNacimiento;


};

#endif