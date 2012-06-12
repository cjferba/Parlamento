#include<cstring>
#include <iostream>
#include<iomanip>
#include"provincia.h"
#include<new>
#include<cstdlib>
#include<fstream>

using namespace std;

provincia :: provincia (){
		nombre[0]='\0';
		escanios=0;
		censo=0;
		numpartidos=0;
		par=0;
		nulos=0;
		blancos=0;
		votantes=0;
		pro=0;
}
		
provincia :: provincia(char nombre1[],int escanios1,int censo1,int numpartidos1,partido *par1,int nulos1,int blancos1,int votantes1,provincia *pro1){
		strcpy(nombre,nombre1);
		escanios=escanios1;
		censo=censo1;
		numpartidos=numpartidos1;
		par=par1;
		nulos=nulos1;
		blancos=blancos1;
		votantes=votantes1;
		pro=pro1;
		
}
provincia :: ~provincia(){
		partido *p=par;
	for(int t=0;t<numpartidos;t++){
		p=p->siguiente();
		delete par;
		par=p;
	}

}
provincia :: provincia (const provincia & otro){
		strcpy(nombre,otro.nombre);
		escanios=otro.escanios;
		censo=otro.censo;
		numpartidos=otro.numpartidos;
		par=otro.par;
		nulos=otro.nulos;
		blancos=otro.blancos;
		votantes=otro.votantes;
}
int provincia :: suma(){
partido* q;
partido r;
int suma=0;
	q=par;
	for(int t=0;t<numpartidos;t++){
	r=*q;
	suma=suma+r.vervotos();
	q=q->siguiente();
	}
return suma;
}
int provincia :: votoscandidaturas(int provincias){
	provincia *p;
	p=this;
	int suma=0;
	for(int r=0;r<provincias;r++){
	suma=suma+p->vervotantes();
	p=p->siguiente();
	}
return suma;
}
int provincia :: verescanios(){
	return escanios;
}
int provincia:: vernumpartidos(){
	return numpartidos;
}
ostream & operator << (ostream & out, const provincia & p){
	out <<"Resultados para:"<< p.nombre<<endl;
	out <<endl;
	out.setf (ios::right);
	out << "Escaños:  " << setw(9) << p.escanios << endl;
	out << "Electores:" << setw(9) << p.censo << '\n'<<endl;
	out << "Votantes: " << setw(9) <<p.votantes+p.nulos+p.blancos<<"("<<((0.0+p.votantes+p.nulos+p.blancos)/p.censo+0.0)*100.0 <<"% de "<<p.censo<<")"<< endl;
	out <<"	A candidaturas:"<< setw(8)<<p.votantes<<"("<<((p.votantes+0.0)/(p.votantes+p.nulos+p.blancos+0.0))*100.0<<" % de "<<p.votantes+p.nulos+p.blancos<<")"<<endl;
	out <<"	Nulos:         " << setw(8) << p.nulos<<"("<<(p.nulos/(p.censo+0.0))*100.0<<" % de "<<p.censo<<")" << endl;
	out <<"	Blancos:       " << setw(8) << p.blancos <<"("<<(p.blancos/(p.censo+0.0))*100.0<<" % de "<<p.censo<<")" << '\n' <<endl;
	out <<"	Válidos:       " << setw(8) << p.blancos+p.votantes<<"("<<((p.blancos+p.votantes+0.0)/(p.votantes+p.nulos+p.blancos))*100.0<<" % de "<<p.votantes+p.nulos+p.blancos<<")"<<endl;	
	partido* q;
	q=p.par;
	out<<endl;
	out <<left<< setw(75)<<"NOMBRE"<<right<<setw(8)<<"VOTOS"<<setw(9)<<"ESCAÑOS"<<setw(10)<<"PORC"<<endl;
	for(int t=0;t<p.numpartidos;t++){
	out<<*q<<right<<" "<<setprecision(2)<<fixed<<setw(8)<<(((q->vervotos()+0.0)/p.votantes+0.0)*100.0)<<"%"<<endl;
	q=q->siguiente();
	}
	out <<endl;
	return (out);
}
int provincia :: vercenso(){
	return censo;
}
int provincia :: vernulos(){
	return nulos;
}
int provincia :: verblancos(){
	return blancos;
}
int provincia :: vervotantes(){
	return votantes;
}
istream & operator >> (istream & in, provincia & p){
		
		do{
 			in.getline(p.nombre,100);
		}while(p.nombre[0]=='\r'||p.nombre[0]=='\t'||p.nombre[0]==' '||p.nombre[0]=='\0');
		bool ban;
		for(int n=0;n<strlen(p.nombre)&&!ban;n++){
			if(p.nombre[n]==' ' && p.nombre[n+1]==' '){
				p.nombre[n]='\0';
				ban= false;
			}
			if(p.nombre[n]=='\t'){
				p.nombre[n]='\0';
				ban= false;
			}
			if(p.nombre[n]=='\r'){
				p.nombre[n]='\0';
				ban= false;
			}
		}							//Eliminamos los espacios en blanco y tabuladores			
		in>>p.escanios;
		in>>p.censo;
		in>>p.numpartidos;
		partido *q;
		for(int w=0;w<p.numpartidos;++w){
			if(w==0){
		 		q=new(nothrow)partido;
			 		if(!q){
						cerr<<"error en la reserva/n";
						exit(1);
					}
				in>>*q;
				q->cambiarsig(NULL);
				p.par=q;
 				q=0;
				//in >> p.par;
		 	
			}
			else{
				
				q=new(nothrow)partido;
				if(!q){
					cerr<<"error en la reserva/n";
					exit(1);
				}
			in>>*q;
			q->cambiarsig(p.par);
			p.par=q;
			q=0;
			//in>>p->par;
			
		}
		}
		p.votantes=p.suma();
		in>>p.nulos;
		in>>p.blancos;
		

	return (in);
}
char* provincia :: vernombre(){
	return nombre;
}
int provincia ::  max(){
 int max=0,w,n=0;
 partido *p;
 p=par;
 for(int r=0;r<numpartidos;r++){
	w=p->numdhont();
	if(w>max){
	max=w;
	n=r;
	}
 p=p->siguiente();
}
return n;
}
void leydhont(provincia & p){
 int lugar;
 partido *q;
 q=p.par;
 for(int e=0;e<p.escanios;++e){
 lugar=p.max();
 q=p.par;
	for(int r=0;r<lugar;r++){
		q=q->siguiente();	
	}
 q->asignarescanios(1);
	
}

}


void provincia :: buscar (int provincias,char* y){
	bool bandera=true;
	provincia *p;
	p=this;
	int r;
	for( r=0;r<provincias && bandera;r++){
		if(strcasecmp(p->vernombre(),y)==0){
			cout<<*p;
			bandera=false;
		}	
	p=p->siguiente();
	}
	if((r==provincias)&&(bandera=true)){
		cerr<<"error no se encuentra la provincia\n";	
		exit(0);
	}
}
int provincia :: sumavotantes (int provincias){
	provincia *p;
	p=this;
	int suma=0,v=0,n=0,b=0;
	for(int r=0;r<provincias;r++){
	v=p->vervotantes();
	n=p->vernulos();
	b=p->verblancos();
	suma=suma+v+n+b;
	p=p->siguiente();
	}
return suma;
} 
int provincia :: sumaelectores (int provincias){
	provincia *p;
	p=this;
	int suma=0;
	for(int r=0;r<provincias;r++){
	suma=suma+p->vercenso();
	p=p->siguiente();
	}
return suma;
} 
int provincia :: sumanulos (int provincias){
	provincia *p;
	p=this;
	int suma=0;
	for(int r=0;r<provincias;r++){
	suma=suma+p->vernulos();
	p=p->siguiente();
	}
return suma;
} 
int provincia :: sumablancos(int provincias){
	provincia *p;
	p=this;
	int suma=0;
	for(int r=0;r<provincias;r++){
	suma=suma+p->verblancos();
	p=p->siguiente();
	}
return suma;
} 

void provincia ::dis(int provincias,ostream & out){
provincia *p,*p1;
partido *pa,*pa1;
p=this;
for(int n=0;n<provincias;++n){
	out<<"  "<<setw(56)<<left<<p->nombre<<endl;
	pa=p->par;
	for(int t=0;t<p->numpartidos;++t){
	if(pa->verescanios()!=0)
		out<<setw(50)<<pa->vernombre()<<setw(6)<<pa->verescanios()<<endl;
	pa=pa->siguiente();
	}
	p=p->pro;
}

}
int provincia :: buscarpartido(char* n){
 partido *p;
 p=par;
 int elec=-1,s;
 bool ban;
 for(s=0;s<numpartidos&&!ban;s++){
 	if(strcasecmp(p->vernombre(),n)==0){
		elec=p->verescanios();   
		//cout<<p->verescanios();
		ban=false;
		}	
	else
		p=p->siguiente();
 }

                return elec;
}

//buscamos lois escaños de un partido en una provincia despues sino existira devolvemos ' '.


char** provincia :: obtenerpartidos(int & utiles,int partidos) {

	char **orig, **copia;	
	int util=0, max=3;
	provincia* aux=this;
	partido *par;
	bool fin;

	orig = new (nothrow) char* [max];
	if(!orig)
	{
		cerr << "Error en la reserva de memoria" << endl;	
		exit(1);
	}	

	for(int y=0;y<partidos;y++) {										//Mientras no acabemos
	
	par=aux->par;
	
		for(int i=0; i<aux->numpartidos; i++) {				
			if(par->verescanios()!=0) {						//Comprovamos si el partido tiene algun escaño
				fin=false;
				for(int j=0; j<util && !fin; j++) {			//Comprovamos si el partido no lo habiamos metido antes
					if(!strcmp(par->vernombre(), orig[j]))
						fin=true;
				}
				if(!fin) {									//En caso de no haberlo encontrado	
					if(util==max) {							//Hacemos hueco para meter una cadena mas
						copia = new(nothrow) char* [util+1];
						if(!copia)
						{
							cerr << "Error en la reserva de memoria" << endl;
							exit(1);
						}
						for(int h=0; h<util; h++)
							copia[h]=orig[h];	
						delete [] orig;
						max=max+1;
						orig=copia;
					}

					orig[util]=new(nothrow) char[strlen(par->vernombre())+1];		//Añadimos el nombre del partido y incrementamos los utiles.
					if(!orig[util])	
					{
						cerr << "Error en la reserva de memoria" << endl;
						exit(1);
					}
			
					strcpy(orig[util], par->vernombre());
					util++;
				}
			}
		
		par=par->siguiente();
		}
		
		aux=aux->siguiente();
	}

	utiles=util;
	copia=orig;
	return orig;

}



















