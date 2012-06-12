#include<iostream>
#include"provincia.h"
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<new>
using namespace std;



int main(int argc, char **argv){

provincia *p,*q,*provin;
ifstream fi;
int escanios,provincias;
char nombre[200];
provincia *g;
if((argc>4)||(argc==1)){
	cout<<"error";
	exit(1);
}

if(argc==2){
	fi.open(argv[1]);
	if(!fi){
		cerr<<"error";
		exit(1);
		}
	
	do{
	 fi.getline (nombre,200);
	}while(nombre[0]=='\r'||nombre[0]=='\t'||nombre[0]==' '||nombre[0]=='\0');
	bool ban ;
	for(int n=0;n<strlen(nombre)-1&&!ban;n++){
		if(nombre[n]==' ' && nombre[n+1]==' '){
			nombre[n]='\0';
			ban= false;
			}
		if(nombre[n]=='\t'){
		nombre[n]='\0';
		ban= false;

		}
		}
	cout<<nombre<<endl;
	fi>>provincias;
	cout<<"Provincias:"<<right<<setw(12)<<provincias<<endl;
	fi>>escanios;
	cout<<"Escaños:"<<right<<setw(15)<<escanios<<endl;
	for(int w=1;w<=provincias;++w){
	
		q=new(nothrow)provincia;
		if(!q){
			cerr<<"error en la reserva/n";
			exit(1);
		}
	fi>>*q;
	if(w==0)
		q->cambiarpro(NULL);
	else
		q->cambiarpro(p);

	p=q;
	q=0;	
	}
	fi.close();
	provincia *gg;
	gg=p;
	provin=p;
	for(int r=0;r<provincias;r++){
		leydhont(*p);
		p=p->siguiente();
	}
	p=gg;
	cout<<"electores: "<<right<<setw(13)<<p->sumaelectores(provincias)<<endl;
	cout<<"Votantes: "<<right<<setw(14)<<p->sumavotantes(provincias)<<endl;
	cout<<"	A candidaturas:"<<right<<setw(9)<<p->votoscandidaturas(provincias)<<endl;
	cout<<"	blancos:"<<right<<setw(16)<<p->sumablancos(provincias)<<endl;
	cout<<"	Nulos:"<<right<<setw(18)<<p->sumanulos(provincias)<<endl;
	cout<<endl;
	cout<<"	Validos:"<<right<<setw(9)<<p->sumablancos(provincias)+p->votoscandidaturas(provincias)<<endl;
	cout<<"	Nulos:"<<right<<setw(11)<<p->sumanulos(provincias)<<endl;
	cout<<endl;
	cout<<"Abstencion:"<<right<<setw(14)<<p->sumaelectores(provincias)-p->sumavotantes(provincias)<<endl;
	cout<<endl;
	cout<<"DISTRIBUCIÓN DE ESCAÑOS POR CIRCUNSCRIPCIÓN"<<endl;
	//p->dis(provincias,cout);
	
	p=gg;
	ofstream fo;
	fo.open("archivo.bin");

	char bufer[1024];
	strcpy(bufer,nombre);
	fo.write(bufer,200);
	int aux;
	aux=p->sumaelectores(provincias);
	 fo.write((char *)(&aux),sizeof(int));
	aux=p->sumavotantes(provincias);
	 fo.write((char *)(&aux),sizeof(int));
	aux=p->votoscandidaturas(provincias);
	 fo.write((char *)(&aux),sizeof(int));
	aux=p->sumablancos(provincias);
	 fo.write((char *)(&aux),sizeof(int));
	aux=p->sumanulos(provincias);
	 fo.write((char *)(&aux),sizeof(int));
	aux=p->sumablancos(provincias)+p->votoscandidaturas(provincias);
	 fo.write((char *)(&aux),sizeof(int));
	aux=p->sumanulos(provincias);
	 fo.write((char *)(&aux),sizeof(int));
	aux=p->sumaelectores(provincias)-p->sumavotantes(provincias);
	 fo.write((char *)(&aux),sizeof(int));
	aux=provincias;
	 fo.write((char *)(&aux),sizeof(int));
	g=gg;
	int utiles=0;
	char **partidos;
	partidos=g->obtenerpartidos(utiles,provincias);
	aux=utiles;
	fo.write((char *)(&aux),sizeof(int));
	bool imprime;
	char * aux1;
	aux1 = new (nothrow) char[256];
		if(!aux){
			cerr << "Error en la reserva de memoria" << endl;
			exit(1);
		}
cout <<"                                       ";
	for(int i=0; i<utiles; i++)								//Imprimimos las iniciales de los partidos.
		{
			imprime=true;
			int util=0;
			fo.write(partidos[i],200);					//Escribimos en el fichero el nombre de todos los partidos
			for(unsigned int j=0;j<strlen(partidos[i]); j++)
			{
				if(partidos[i][j]==' ')
					imprime=true;
				else{
					if(imprime)
					{
						aux1[util]=partidos[i][j];
						util++;
						imprime=false;
					}							
				}
			}

			aux1[util]='\0';
			cout << right << setw(8) << aux1 ;
		}

g=gg;
cout<<endl;
for(int u=0,o=0;u<provincias;u++){
	cout<<right<<setw(40)<<g->vernombre();
	fo.write(g->vernombre(),200);
 	for(int s=0;s<utiles;s++){
		o=g->buscarpartido(partidos[s]);
		if(o==-1){
 			cout<<"|"<< right << setw(6) << ' ';
			fo.write((char *)(&o),sizeof(int));
			}
		else{
			cout<< "|"<<right << setw(6) << o;
			fo.write((char *)(&o),sizeof(int));
		}
	cout<<"|";
	}
cout<<endl;
if(g!=NULL)
  g=g->siguiente();
}

g=provin;
aux=0;
cout<<"\n \n"<<"DISTRIBUCIÓN PORCENTUAL DE ESCAÑOS"<<endl;
for(int s=0;s<utiles;s++){
	//cout<<right<<setw(40)<<g->vernombre();
	cout<<setw(56)<<partidos[s];
	fo.write(partidos[s],200);
	g=provin;
	aux=0;
 	for(int u=0,o=0;u<provincias;u++){
		if(g->buscarpartido(partidos[s])!=-1){
		o=g->buscarpartido(partidos[s]);
		aux=aux+o;
		}
		if(g!=NULL){
  			g=g->siguiente();
		}
		
	}
cout<<setw(8)<<aux<<"(" <<fixed<<setprecision(2)<< ((aux*100.0)/escanios)<<"%)"<<endl;
fo.write((char *)(&aux),sizeof(int));
}
fo.close();
delete aux1;
for(int i=0;i<utiles;i++)
			delete [] partidos[i];
		delete [] partidos;
}
else{
	fi.open(argv[1]);
	if(!fi){
		cerr<<"error";
		exit(1);
		}
	do{
		 fi.getline (nombre,200);
	}while(nombre[0]=='\r'||nombre[0]=='\t'||nombre[0]==' '||nombre[0]=='\0');
	cout<<nombre<<endl;
	fi>>provincias;
	fi>>escanios;
	for(int w=1; w<=provincias ;++w){
	
		q=new(nothrow)provincia;
		if(!q){
			cerr<<"error en la reserva/n";
			exit(1);
		}
		fi>>*q;	
		if(w==0)
			q->cambiarpro(NULL);
		else
			q->cambiarpro(p);
	
		p=q;
		q=0;	
	}
	fi.close();
	provin=p;
	g=p;
	for(int r=0;r<provincias;r++){
	leydhont(*p);
	p=p->siguiente();
	}
	g-> buscar (provincias,argv[2]);
	
}

	g=provin;
	
	
	for(int n=0;n<provincias;n++){
		provin=provin->siguiente();
		delete g ;
		g=provin;
		
	}
	
}


