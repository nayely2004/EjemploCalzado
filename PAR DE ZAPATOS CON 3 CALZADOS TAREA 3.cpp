#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
class calzado{
private:
	int talla;
	char ladopie;
public:
	calzado()
	{
		talla = 40;
		ladopie = 'I';
	}
	calzado(int nuevatalla, char lado)
	{
		talla = nuevatalla;
		ladopie = lado;
	}
	bool esparde(calzado cal1)
	{
		return (cal1.talla == talla && cal1.talla!=ladopie)? true : false;
	}
	void verdatos()
	{
		cout<<"talla: "<<talla<<endl;
		cout<<"lado pie: "<<(ladopie == 'I' ? "IZQUIERDO" : "DERECHO")<<endl;
	}
	void dibujarzapato()
	{
		cout<<"|°°°°°°|"<<endl;
		cout<<"|     *|"<<endl;
		cout<<"|     *|"<<endl;
		cout<<"|      --------"<<endl;
		cout<<"|              |"<<endl;
		cout<<"|--------------|"<<endl;
		cout<<"Talla: "<<talla<<endl;
		cout<<"Lado Pie: "<<(ladopie == 'I' ? "IZQUIERDO" : "DERECHO")<<endl;
	}
	void randomizar()
	{
		talla = 40+rand()%6;
		ladopie=(rand()%2==0) ? 'I' : 'D';
	}
};
void mostrarcalzado(calzado a, calzado b, calzado c)
{
	cout<<"------------------------------"<<endl;
	cout<<"     SELECION DE CALZADOS     "<<endl;
	cout<<"------------------------------"<<endl;
	cout<<"Calzado A: "<<endl;
	a.dibujarzapato();
	cout<<endl;
	
	cout<<"Calzado B:"<<endl;
	b.dibujarzapato();
	cout<<endl;
	
	cout<<"Calzado C:"<<endl;
	c.dibujarzapato();
	cout<<endl;
}
bool validarrespuesta(calzado a, calzado b, calzado c, string respuesta)
{
	if((a.esparde(b) && respuesta == "ab") || (!a.esparde(b) && respuesta == "o"))
	{
		return true;
	}
	if((b.esparde(c) && respuesta == "bc") || (!b.esparde(c) && respuesta == "o"))
	{
		return true;
	}
	if((a.esparde(c) && respuesta == "ac") || (!a.esparde(c) && respuesta == "o"))
	{
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	calzado a, b, c;
	
	int cont = 0;
	bool flag = true;
	
	
	while(flag)
	{
		//randomiza los calzados
		a.randomizar();
		b.randomizar();
		c.randomizar();
		//muestra los calzados
		mostrarcalzado(a, b, c);
		//solicita al usuario la respuesta 
		cout<<"_______________________________"<<endl;
		cout<<"    ¿Cual es el par de zapatos?  "<<endl;
		cout<<"    Escribe 'ab' si A y B son un par"<<endl;
		cout<<"    Escribe 'bc' si B y C son un par"<<endl;
		cout<<"    Escribe 'ac' si A y C son un par"<<endl;
		cout<<"    Escribe 'o' si ninguno es un par"<<endl;
		cout<<"________________________________"<<endl;
		cout<<"Tu Respuesta es: ";
		string respuesta;
		cin>>respuesta;
		
		//validamos la respuesta del usuario
		if(validarrespuesta(a, b, c, respuesta))
		{
			cout<<" ¡ACERTASTE! "<<endl;
			cont++;
		}
		else
		{
			cout<<"RESPUESTA INCORRECTA, FIN DEL JUEGO."<<endl;
			flag = false;//termina el bucle si la respuesta es incorecta
		}
		
	}
	
	cout << "-------------------------" << endl;
	cout << "NUMERO DE ACIERTOS: " << cont << endl;
	cout << "-------------------------" << endl;
	
	return 0;
}

