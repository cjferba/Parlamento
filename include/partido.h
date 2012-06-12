#include<iostream>

using namespace std;

class partido{
	private:
		
		char nombre[75];
		int votos;
		int escanios;
		partido *sig;
	public:
		/**
		@brief contructor
		*/
		partido ();
		/**
		@brief contructor con parametros
		@param nombre de el partido
		@param votos del partido
		@param puntero a un partido
		*/
		partido (char nombre[],int votos,int escanios,partido *sig);
		/**
		@brief devuelve los votos
		@return votos
		*/
		int vervotos();
		/**
		@brief devuelve el nombre
		@return nombre
		*/
		char* vernombre();
		void asignarescanios(int n);
		partido (const partido & otro);
		//partido &  siguiente();
		int verescanios();
		/**
		@brief sobrecarga del operador d extraccion de flujo
		@param partido que se le extrae el flujo
		@return ostream
		*/
		friend ostream & operator << (ostream &, const partido &);
		/**
		@brief sobrecarga del operador d insercion de flujo
		@param partido que se le inserta el flujo
		@return istream
		*/
		friend istream & operator >> (istream &, partido &);
		int numdhont (){
			return(votos/(escanios+1));
		}
		/**
		@brief siguiente partido
		@return puntero suigiente partido
		*/
		partido *siguiente(void){
			return sig;
		}
		partido *cambiarsig(partido *p){
			sig=p;
		}	
};





