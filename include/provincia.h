#include"partido.h"

using namespace std;

class provincia{
	private: 
		char nombre[100];
		int escanios;
		int censo;
		int numpartidos;
		partido *par;
		int nulos;
		int blancos;
		int votantes;
		provincia *pro;
	public:
		/**
		@brief constructor
		*/
		provincia();
		/**
		@brief constructor con parametros
		@param char nombre1 :nombre de la provincia
		@param int escanios1:escaños de la provincia
		@param int censo1 :censo de la provincia
		@param int numpartidos1:numero de partidos en la provincia
		@param partido *par1: puntero ala lista de partidos de la provincia
		@param int nulos:votos nulos
		@param int blancos:votos en blanco
		@param int votantes:votantes de la provincia
		@param provincia *pro:puntero a la siguiente provincia		
		*/
		provincia(char nombre1[],int escanios1,int censo1,int numpartidos1,partido *par1,int nulos1,int blancos1,int votantes1,provincia *pro);
		/**
		@brief destructor	
		*/		
		~provincia();
		/**
		@brief constructor de copias
		@param cons provincia otro :provincia que se copia que pasa por referencia
		*/
		provincia (const provincia & otro);
		
		
		void blan(char s[]);


		/**
		@brief suma de los votos
		@return int suma total de votos de los partidos de la provincia	
		*/
		int suma();
		/**
		@brief devuelve el censo
		@return int censo de la provincia
		*/
		int vercenso();
		/**
		@brief devuelve votos nulos
		@return int votos nulos de la provincia	
		*/
		int vernulos();
		/**
		@brief devuelve los votos blancos
		@return int votos en blanco de la provincia
		*/
		int verblancos();
		/**
		@brief devuelve los votantes
		@return int votantes de la provincia	
		*/
		int vervotantes();
		/**
		@brief devuelve los escaños
		@return int escaños de la provincia
		*/
		int verescanios();
		/**
		@brief numero de partidos
		@return int devuelve numero d partidos de la provincia	
		*/ 
		int vernumpartidos();
		/**
		@brief nombre de pa provincia
		@return char* nombre de la provincia	
		*/
		char* vernombre();
		/**
		@brief suma de los votos a las candidaaturas
		@param provincias que se suman sus votos
		@return int suma total de votos a las candidaturas
		*/		
		int votoscandidaturas(int provincias);
		/**
		@brief suma de los votos nulos a las candidaaturas
		@param provincias que se suman sus votos nulos
		@return int suma total de votos nulos
		*/	
		int sumanulos(int provincias);
		/**
		@brief suma de los votos en blanco
		@param provincias que se suman sus votos
		@return int suma total de votos en blanco
		*/
		int sumablancos(int provincias);
		/**
		@brief suma de los votos a las candidaaturas
		@param provincias que se pasa la funcion 
		@param ostream out flujo de salida d los datos
		*/
		void dis(int provincias,ostream & out);
		/**
		@brief siguiente provincia
		@return puntero a provincia siguiente
		*/
		provincia *siguiente(void){
		return pro;
		}
		/**
		@brief cambia el puntero de la provincia 
		@param provincia puntero por el que se cambia
		*/
		provincia *cambiarpro(provincia *p){
		pro=p;
		}
		/**
		@brief sobrecarga del operador d insercion de flujo
		@param provincia que se le inserta el flujo
		@return istream
		*/
		friend ostream & operator << (ostream &, const provincia &);
		/**
		@brief sobrecarga del operador d extraccion de flujo
		@param provincia que se le extrae el flujo
		@return ostream
		*/
		friend istream & operator >> (istream &, provincia &);	
		/**
		@brief maximo para la ley de dhont 
		@param provincia que se le inserta para calcular su maximo
		@return int maximo
		*/
		int  max();
		/**
		@brief funcion friend que reparte los escaños
		@param provincia que se le reparten sus escaños
		*/
		friend void leydhont(provincia &);
		
		void buscar(int provincias,char*);
		/**
		@brief suma los electores
		@param provincias a las que se le pasa
		@return int electores
		*/
		int sumaelectores (int provincias);
		/**
		@brief suma de los votantes
		@param provincias a las que se le pasa
		@return int votantes
		*/
		int sumavotantes (int provincias); 	
		int buscarpartido(char* n);
		char** obtenerpartidos(int & utiles,int partidos);
		

};
