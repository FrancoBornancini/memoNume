#include <iostream>
#include <string>
#include <conio.h>
#include <math.h> //para usar funciones matematicas
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //para usar srand(time(NULL)) y consecuentemente rand()
#include <iostream>
#include <windows.h> //para usar Sleep()
#include "stackLifoTDA.h" //TDA para crear y manejar listas
#include <windows.h>

using namespace std;

//Inicia la onfiguracion de la consola para poder usar el cambio de colores en cualquier modulo
HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
CONSOLE_SCREEN_BUFFER_INFO csbi;
//Inicia la onfiguracion de la consola para poder usar el cambio de colores en cualquier modulo

//Creacion del struct para jugadores (maximo 7)
struct player{
	string name;
	int quantity,time,score=0;
}pl[7];

//Modulos (de procedimientos y funciones)
void introductionTo();
int chargerPlayers(); //tambien regresara la cantidad de jugadores
int challangePlayer(int); //tambien regresa el puntaje que gano el jugador
void comparePlayers(int); //informa el ranking de los jugadores
int check(int,int); //verifica que se ingrese un entero en su rango correcto

// Funcion principal (es la Big Boss 7:])
int main(){
	int i,numberOfPlayers,score;
	int games=0;
	char option;
	string losser[8]={"Pero vos sos una lacra,","Te hemos evaluado y no das la Talla.","ATENCION: Marmota en el teclado.","Che manco, usa teclado y mouse NO el Joystick.","Ba Dum Pss.. Que? tu jugada no fue una broma?.","AnalfaBESTIA pero con numeros,","Igual, nunca espere nada de ti,","vos otra vez? sabia que no lo lograrias..."};
	string congratularion[8]={"Sorprendente!,","Krack de las teclitas,","O.O Si te pagaran por recordar numeros!, serias pobre... Bueno es una realidad, no quita que ganaste pero.. que mas esperabas?,","Muy bien! pero cuidado con la competencia,","Increible!... Hiciste trampa?,","Flipante! (AH rrre Gallego),","Si (TuGanar == Perder) Entonces return Falso ;),","Se te da bien,"};
	//system("color 8F");
	introductionTo();
	system("pause");
	system("cls");
	numberOfPlayers=chargerPlayers();
	system("pause");
	system("cls");
	do
	{
		cout<<"Partida numero "<<games+1<<endl<<endl;
		comparePlayers(numberOfPlayers);
		for (int i = 0; i < numberOfPlayers; i++)
		{
			score=challangePlayer(i);
			if (score != 100)
			{
				printf("%s %s tu puntaje fue: +",congratularion[(0+rand()%(9-1))].c_str(),pl[i].name.c_str());
				cout<<score<<endl;
				pl[i].score = pl[i].score + score;
			}
			else
			{
				printf("%s %s tu puntaje fue: +",losser[(0+rand()%(9-1))].c_str(),pl[i].name.c_str());
				cout<<score<<endl;
				pl[i].score = pl[i].score + score;
			}
			system("pause");
			system("cls");
		}
		comparePlayers(numberOfPlayers);
		cout<<"\nContinuar partida? (s=SI, n=NO): ";
		cin>>option;
		if (option=='s' || option=='S'){games++;}
		else{games=0;}
		system("cls");
	}while(games!=0);
}

void introductionTo()
{
	//Se muestra la pantalla 1
	
	GetConsoleScreenBufferInfo( hstdout, &csbi );
	// Configurar colores
	SetConsoleTextAttribute( hstdout, 0xF9 );
	cout<<" 																																									  "<<endl;
	cout<<"                                                                                                                                                                       "<<endl;
	cout<<"         ++++++++++++++++++++++++++++++++++                                                                                                                            "<<endl;
	cout<<"         ++++++++++++++++++++++++++++++++++         :      .:   :      ,,   :  .:       :    :::::,  ,:::::       :+',    :    ::::,         ,:      :::::             "<<endl;
	cout<<"         ++++++++++++++++++++++++++++++++++         +.     ++   ++     +'   +  ,+      '+  `+++++++  +++++++`   '++++++   +.  .++++++'       ++      +++++++           "<<endl;
	cout<<"         ++++++++++++;;++++++++++++++++++++         +.     ++   ++;    +'   +   +;     ++  +'        +'    ++   +,    `   +.  .+    :++     :++'     +    `++          "<<endl;
	cout<<"         +++++++++'     ,++++++++++++++++++         +.     ++   +.+    +'   +   ++     +   +'        +'    `+  .+         +.  .+     ;+     +';+     +      +`         "<<endl;
	cout<<"         ++++++++' ,+++: ,+++++++++++++++++         +.     ++   + ++   +'   +   .+    '+   +'        +'    `+   +'        +.  .+      +;    +` +     +      +'         "<<endl;
	cout<<"         ++++++++ .+++++' +++++++++++++++++         +.     ++   +  +.  +'   +    +:   +'   +':::::   +'    ++   '++:      +.  .+      +'   '+  ++    +      '+         "<<endl;
	cout<<"         +++++++; +++++++ :++++++++++++++++         +.     ++   +  '+  +'   +    '+   +`   +++++++   +++++++      ;+++    +.  .+      ++   +'  ;+    +      '+         "<<endl;
	cout<<"         +++++++; +++++++ .++++++++++++++++         +.     ++   +   ++ +'   +    `+  '+    +'        +'```++.       .++   +.  .+      +;   +    +.   +      '+         "<<endl;
	cout<<"         +++++++; +++++++ `++++++++++++++++         +.     ++   +   `+ +'   +     +' +;    +'        +'    ++         +'  +.  .+      +,  ;+++++++   +      +'         "<<endl;
	cout<<"         ++++++++ ;+++++' +++++++++++++++++         ++     ++   +    +++'   +     ;+ +     +'        +'    :+         ++  +.  .+     ;+   ++'''''+   +     `+`         "<<endl;
	cout<<"         ++++++++:+++ .++.+++++++++++++++++         '+     ++   +     ++'   +      +;+     +'        +'     +. ,`    `+,  +.  .+    ;+;  `+`     +`  +    .++          "<<endl;
	cout<<"         +++++++++++   '+++++++++++++++++++          ++++++++   +     ;+'   +      ++:     .+++++++  +'     ++ ++++++++   +.  .++++++;   '+      ++ `+++++++           "<<endl;
	cout<<"         ++++++++++:    +++++++++++++++++++           `::::`    `      `    `       `        ``````  `      ``   `:::     `    `````     `       ``  `````             "<<endl;
	cout<<"         ++++++++++      +++  ++++++'++++++                                                                                                                            "<<endl;
	cout<<"         +++++++++       ++.   ++++: ++++++                                                                                                                            "<<endl;
	cout<<"         ++++++++       ++;    '+++   +++++                                                                                                                            "<<endl;
	cout<<"         +++++++       +++      ++  : .++++         +++++++     ;++++++'       ++           ++           +++++++:   +.     :+   ++     .+  +++++++++   `++             "<<endl;
	cout<<"         ++++++,      ,++          ++  .+++         +.   ,++    +;             ++          ,++;          ++    ++   +.     :+   +++    .+     `+       '++`            "<<endl;
	cout<<"         ;;;;;;       ++.         :+++  '++         +.    `+,   +              ++          +''+          ++     +,  +.     :+   +.+.   .+     `+       +.++            "<<endl;
	cout<<"                     ++'          +++++  ++         +.     ++   +              ++          +` +          ++     +.  +.     :+   +,'+   .+     `+      .+ ;+            "<<endl;
	cout<<"         ++++++++++++++          +++++++  +         +.     ;+   +``````        ++         ,+  +;         ++    `+`  +.     :+   +, ++  .+     `+      ++  +,           "<<endl;
	cout<<"         :++++++++++++          '++++++++           +.     ,+   +++++++        ++         +'  ++         ++:::+++   +.     :+   +, .+` .+     `+      +,  ++           "<<endl;
	cout<<"                               ,++++++++++          +.     ,+   +              ++         +`   +`        ++++++,    +.     :+   +,  ++ .+     `+     ,+   :+           "<<endl;
	cout<<"          .....................+++++++++++          +.     ++   +              ++        :+''''+'        ++         +`     :+   +,   +:.+     `+     ++''''+.          "<<endl;
	cout<<"           ++++++++++++++++++++++++++++++           +.     +;   +              ++        ++++++++        ++         +'     :+   +,   :+.+     `+     ++++++++          "<<endl;
	cout<<"           '+++++++++++++++++++++++++++++           +.    ++    +,             ++        +.    `+`       ++         '+     :+   +,    +++     `+    :+     :+          "<<endl;
	cout<<"            ++++++++++++++++++++++++++++            +++++++     +++++++'       .+++++++ '+      +'       ++          ++++++++   +,     ++     `+    ++      +:         "<<endl;
	cout<<"             ++++++++++++++++++++++++++             :::::        .:::::,         :::::: ::      ,:       :,           ,++++:    :      ::      :    :.      :,         "<<endl;
	cout<<"              ++++++++++++++++++++++++                                                                                                                                 "<<endl;
	cout<<"               ++++++++++++++++++++++                                                                                                                                  "<<endl;
	cout<<"                '+++++++++++++++++++                                                                                                                                   "<<endl;
	cout<<"                 ,++++++++++++++++;                                                                                                                                    "<<endl;
	cout<<"                   ++++++++++++++                                                                                                                                      "<<endl;
	cout<<"                    ++++++++++++                                                                                                                                       "<<endl;
	cout<<"                     ;++++++++:                                                                                                                                        "<<endl;
	cout<<"                       ++++++                                                                                                                                          "<<endl;
	cout<<"                        `++                                                                                                                                            "<<endl;
	cout<<"                                                                                                                                                                       "<<endl;
	SetConsoleTextAttribute( hstdout, csbi.wAttributes );
	SetConsoleTextAttribute( hstdout, 0x9);
	cout<<"	Carrera:"<<endl;
	SetConsoleTextAttribute( hstdout, csbi.wAttributes );
	SetConsoleTextAttribute( hstdout, csbi.wAttributes );
	SetConsoleTextAttribute( hstdout, 0xF);
	cout<<"		Tecnicatura en desarrollo de VideoJuegos"<<endl;
	SetConsoleTextAttribute( hstdout, csbi.wAttributes );
	system("pause");
	system("cls");
	
	//Se muestra la pantalla 2
	
	GetConsoleScreenBufferInfo( hstdout, &csbi );
	// Configurar colores
	SetConsoleTextAttribute( hstdout, 0xF9 );
	cout<<"                                                                                                                                                                                                   "<<endl;
	cout<<"                             @@,       @@,                                                              ,@@    ,@@,                                                                                "<<endl;
	cout<<"                             @@,       @@,                                                              ,@@    ,@@,                                                                                "<<endl;
	cout<<"                             @@,       @@,                                                              ,@@    ,@@,                                                                                "<<endl;
	cout<<"                             @@@@    ,@@@,                                                              ,@@@,  ,@@,                                                                                "<<endl;
	cout<<"                             @@@@    ,@@@,                                                              ,@@@,  ,@@,                                                                                "<<endl;
	cout<<"                             @@@@    ,@@@,                                                              ,@@@,  ,@@,                                                                                "<<endl;
	cout<<"                             @@@@@, @@@@@,                                                              ,@@@@@ ,@@,                                                                                "<<endl;
	cout<<"                             @@@@@, @@@@@,          @@@@@@         @@@@@@@@@            @@@@@@          ,@@ ,@ ,@@,        ,@@   @@@         @@@@@@@@@            @@@@@@                           "<<endl;
	cout<<"                             @@@@@, @@@@@,          @@@@@@         @@@@@@@@@            @@@@@@          ,@@ ,@ ,@@,        ,@@   @@@         @@@@@@@@@            @@@@@@                           "<<endl;
	cout<<"                             @@, @@@@, @@,        ,@@,  ,@@,       @@@ ,@ ,@@,        ,@@,  ,@@,        ,@@ ,@@@@@,        ,@@   @@@         @@@ ,@ ,@@,        ,@@,  ,@@,                         "<<endl;
	cout<<"                             @@, @@@@, @@,        ,@@,  ,@@,       @@@ ,@ ,@@,        ,@@,  ,@@,        ,@@   @@@@,        ,@@   @@@         @@@ ,@ ,@@,        ,@@,  ,@@,                         "<<endl;
	cout<<"                             @@, @@@@, @@,        ,@@,  ,@@,       @@@ ,@ ,@@,        ,@@,  ,@@,        ,@@   @@@@,        ,@@   @@@         @@@ ,@ ,@@,        ,@@,  ,@@,                         "<<endl;
	cout<<"                             @@,  ,@   @@,        ,@@@@@@@@,       @@@ ,@ ,@@,        ,@@,  ,@@,        ,@@   @@@@,        ,@@   @@@         @@@ ,@ ,@@,        ,@@@@@@@@,                         "<<endl;
	cout<<"                             @@,  ,@   @@,        ,@@@@@@@@,       @@@ ,@ ,@@,        ,@@,  ,@@,        ,@@    ,@@,        ,@@   @@@         @@@ ,@ ,@@,        ,@@@@@@@@,                         "<<endl;
	cout<<"                             @@,  ,@   @@,        ,@@,             @@@ ,@ ,@@,        ,@@,  ,@@,        ,@@    ,@@,        ,@@   @@@         @@@ ,@ ,@@,        ,@@,                               "<<endl;
	cout<<"                             @@,       @@,        ,@@,             @@@ ,@ ,@@,        ,@@,  ,@@,        ,@@    ,@@,        ,@@   @@@         @@@ ,@ ,@@,        ,@@,                               "<<endl;
	cout<<"                             @@,       @@,        ,@@,  ,@@,       @@@ ,@ ,@@,        ,@@,  ,@@,        ,@@    ,@@,        ,@@   @@@         @@@ ,@ ,@@,        ,@@,  ,@@,                         "<<endl;
	cout<<"                             @@,       @@,        ,@@,  ,@@,       @@@ ,@ ,@@,        ,@@,  ,@@,        ,@@    ,@@,        ,@@   @@@         @@@ ,@ ,@@,        ,@@,  ,@@,                         "<<endl;
	cout<<"                             @@,       @@,          @@@@@@         @@@ ,@ ,@@,          @@@@@@          ,@@    ,@@,           @@@            @@@ ,@ ,@@,          @@@@@@                           "<<endl;
	cout<<"                                                    @@@@@@                              @@@@@@                                @@@                                 @@@@@@                           "<<endl;
	cout<<"                                                                                                                                                                                                   "<<endl;
	SetConsoleTextAttribute( hstdout, csbi.wAttributes );
	cout<<"San Luis ULP - Universidad de la Punta"<<endl;
	cout<<"Carrera: Tecnicatura en desarrollo de VideoJuegos"<<endl;
	cout<<"Materia: Desarrollo de VideoJuegos I"<<endl;
	cout<<"Profesor: Mercado Luis"<<endl;
	cout<<"Alumnos: Franco Bornancini y Careglio Albornoz Jesus Lautaro"<<endl;
}

int chargerPlayers(){
	int cplayer,c;
	cout<<"Ingrese la cantidad de Jugadores (se recomienda + de 2) ";
	cplayer=check(1,7);
	for(c=0;c<cplayer;c++){
	    cout<<"Ingrese el nombre del "<<c+1<<"° jugador ";
	    cin>>pl[c].name;
	}
	return cplayer;
}

int challangePlayer(int player){
	int i,ran,x;

	printf("\nEs el turno de %s\n",pl[player].name.c_str());
	cout<<"Ingrese cantidad de numeros a recordar (mientras mas, mas puntos ganaras) ";
	pl[player].quantity=check(1,90);
	cout<<"Ingrese el tiempo para recordarlos (mientras menos, mas puntos ganaras) ";
	pl[player].time=check(1,15);

	//Se usa el TDA pilas o stacks (LIFO) solo para probarlas (no es recomentable usarlas para este tipo de problemas)
	//Se crearan 2 pilas con el tamaño de la cantidad de numeros elejidos por el jugador
	Stack s1 (pl[player].quantity);
	Stack s2 (pl[player].quantity);

    cout<<"\nAHORA memorisa estos numeros en secuencia:"<<endl;
    for (i=0;i<pl[player].quantity;i++){
    	ran=(0+rand()%(10-1));
    	s1.push(ran);
   		s2.push(ran);
	}
	for (i=0;i<pl[player].quantity;i++){
    	cout<<".:."<<s2.getTop();
		s2.pop();
	}
	cout<<".:."<<endl;

	cout<<"\nTIENES "<<pl[player].time<<" segundos"<<endl;
	Sleep(pl[player].time * 1000);
	system("cls");
	cout<<"Para avanzar ingresa TODA la secuencia: (uno a uno)"<<endl;
	for (i=0;i<pl[player].quantity;i++){
		cout<<"El "<<i+1<<"°: ";
		cin>>x;
		if(x != s1.getTop()){;
  			return 100;
		}
		s1.pop();
	}
	//Formula que calcula el puntaje en relacion de la cantidad de palabras y el tiempo elejidos
	return ((pow((pl[player].quantity * (pl[player].time + 2.5)),(1.5 / (pl[player].time + 4.5))))*100);
}

void comparePlayers(int quan){
	int i,j;
	struct player plTemp;

	for (i=0;i<(quan - 1);i++) 
	{
	  	for (j=i+1;j<quan;j++) 
	    {
	    	if (pl[j].score > pl[i].score) 
	    	{
	        	plTemp.name = pl[j].name;
	        	plTemp.quantity = pl[j].quantity;
	        	plTemp.score = pl[j].score;
	        	plTemp.time = pl[j].time;
	        	
	        	pl[j].name = pl[i].name;
	        	pl[j].quantity = pl[i].quantity;
	        	pl[j].score = pl[i].score;
	        	pl[j].time = pl[i].time;
	        	
	        	pl[i].name = plTemp.name;
	        	pl[i].quantity = plTemp.quantity;
	        	pl[i].score = plTemp.score;
	        	pl[i].time = plTemp.time;
			} 
		} 
	} 

	for(i=0;i<quan;i++){
		printf("°°Puesto %i°° %s °° ----> %i memoPoints °°\n",i+1,pl[i].name.c_str(),pl[i].score);
	}
}

int check(int min, int max){
	int num;
	do
	{
		cout<<"(valor entre "<<min<<" y "<<max<<"): ";
		cin>>num;
	}while(num>max or num<min);
	return num;
}
