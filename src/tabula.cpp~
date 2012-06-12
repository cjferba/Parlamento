#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<new>
using namespace std;

char* LeerLinea(ifstream & fi,int tam)
{
	char* buffer = new (nothrow) char [tam+1];
	
	if(!buffer)
	{
		cerr << "Error en la reserva de memoria" << endl;
		exit(1);
	}
	
	do{
		fi.read(buffer,tam);
	}while(buffer[0]==' ' || buffer[0]=='\t' || buffer[0]=='\r' || buffer[0]=='\0');
	

	return buffer;
}

int LeerEntero (ifstream & fi)
{
	int n;
	fi.read((char*)(&n), sizeof(int));
	return n;		
}

int main(int argc, char **argv){
if(argc!=2){
 cerr<<"error"<<endl;
 exit(1);
}
else{
ofstream fo;
ifstream fi;
fi.open(argv[1]);
if(!fi){
		cerr<<"error";
		exit(1);
		}
char bufer[1025];
fo.open("tabla.html");
if(!fo){
		cerr<<"error";
		exit(1);
		}
fi.read(bufer,200);
int votantes,elec;
fo<<"<h1>"<<bufer<<"</h1>"<<"<br>";
fo<<"<h4>"<<"Estadisticas"<<"</h4>";
int aux;
aux=LeerEntero(fi);
fo<<"Electores: "<<right<<setw(13)<<aux<<"<br>";
elec=aux;
aux=LeerEntero(fi);
fo<<"Votantes: "<<right<<setw(14)<<aux<<"<br>";
votantes=aux;
aux=LeerEntero(fi);
fo<<"&nbsp; A candidaturas:"<<right<<setw(9)<<aux<<"("<<fixed<<setprecision(2)<<(aux*100.0)/votantes<<"% de "<<votantes<<" )"<<"<br>";
aux=LeerEntero(fi);
fo<<"&nbsp; blancos:"<<right<<setw(16)<<aux<<"("<<fixed<<setprecision(2)<<(aux*100.0)/votantes<<"% de "<<votantes<<" )"<<"<br>";
aux=LeerEntero(fi);
fo<<"&nbsp; Nulos:"<<right<<setw(18)<<aux<<"("<<fixed<<setprecision(2)<<(aux*100.0)/votantes<<"% de "<<votantes<<" )"<<"<br>";
fo<<"<br>";
aux=LeerEntero(fi);
fo<<"&nbsp; Validos:"<<right<<setw(9)<<aux<<"("<<fixed<<setprecision(2)<<(aux*100.0)/votantes<<"% de "<<votantes<<" )"<<"<br>";
aux=LeerEntero(fi);
fo<<"&nbsp; Nulos:"<<right<<setw(11)<<aux<<"("<<fixed<<setprecision(2)<<(aux*100.0)/votantes<<"% de "<<votantes<<" )"<<"<br>";
fo<<"<br>";
aux=LeerEntero(fi);
fo<<"Abstencion:"<<right<<setw(14)<<aux<<"("<<fixed<<setprecision(2)<<(aux*100.0)/elec<<"% de "<<elec<<" )"<<"<br>"<<endl<<"<br clear=all>";
int utiles,provincias;
aux=LeerEntero(fi);
provincias=aux;
aux=LeerEntero(fi);
utiles=aux;

fo<<"<table border=1>"<<'\n';
fo<<"<tr>"<<'\n'<<"<td>"<<"    "<<"</td>"<<endl;
for(int n=0;n<utiles;n++){

fo<<"<td>"<<LeerLinea(fi,200)<<"</td>"<<endl;
 }
for(int y=0;y<provincias;y++){
fo<<"<tr>"<<'\n';
fo<<"<td>"<<"<b>"<<LeerLinea(fi,200)<<"</b>"<<"</td>"<<endl;

//cout<<y<<" "<<provincias<<endl;
	for(int n=0;n<utiles;n++){
	aux=LeerEntero(fi);
	if(aux<0)
	fo<<"<td>"<<"-"<<"</td>"<<endl;
	else
	fo<<"<td>"<<aux<<"</td>"<<endl;
	}

fo<<"</tr>"<<'\n';	
}
fo<<"</table>";
fo<<"<br>"<<"<h3>"<<"DISTRIBUCI&Oacute;N PORCENTUAL DE ESCA&Ntilde;OS"<<"</h3>"<<"<br>";
fo<<"<table border=2>"<<'\n';
for(int n=0;n<utiles;n++){
	
	fo<<"<tr>"<<"<td>"<<"<b>"<<LeerLinea(fi,200)<<"</b>"<<"</td>";		
	aux=LeerEntero(fi);
	fo<<"<td>"<<"<div align=right>"<<"      "<<aux<<"</div>"<<"</td>"<<"</tr>";
}	
fo<<"</table>";
fo.close();
fi.close();


}
}
