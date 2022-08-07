#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
void zasada(){
		std::cout<<"Zasady: "<<std::endl<<"1.   Gracz rzuca koscia (3 elem. lub 6 elem.) i porusza sie o dana ilosc pol,"<<std::endl<<" nastepnie porusza sie komputer (lub drugi gracz)"<<std::endl;
		std::cout<<"2.   Pole S jest STARTEM, gra konczy sie gdy gracz lub komputer (albo drugi gracz) dotrze na pole M-META,"<<std::endl<<" wtedy ten kto ma wiecej punktow wygrywa"<<std::endl;			//funkcja z zasadami
		std::cout<<"3.   Jesli Gracz lub Komputer stanie na polu parzystym zyskuje 5 punktow"<<std::endl;
		std::cout<<"3.1. Jesli Gracz lub Komputer stanie na polu nieparzystym traci 10 punktow"<<std::endl;
		std::cout<<"4.1. Jesli Gracz lub Komputer stanie na polu z * zyskuje 10 razy liczba oczek jak¹ wyrzucil"<<std::endl;
		std::cout<<"4.2. Jesli Gracz lub Komputer stanie na polu z % traci 10 razy liczba oczek jak¹ wyrzucil"<<std::endl;
		std::cout<<"5.1. Mozna zbic przeciwnika jezeli staniemy na tym samym polu co on, (w druga strone to dziala tak samo)"<<std::endl;
		std::cout<<"5.2. Ten kto zbije drugiego gracza zyskuje 20 punktow"<<std::endl;
		std::cout<<"5.3. Gracz zaczyna wtedy od Startu ale nie traci dotychczasowych punktow"<<std::endl;
		std::cout<<"6.   Efekty dodawania/odejmowania punktow sie lacza"<<std::endl<<std::endl;
}
int rzut(int &a,int l){			//funkcja do rzucania kosci¹
	a=rand()%l+1;
	return a;}
int main(){
	srand(time(nullptr));
std::vector<std::vector<std::string>> plan{{   
"| | | | | | | | | | | | | | | | | | | | | | |",//45
" S 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 2 M ",
" T 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 M "},
{
"| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",//84
" S 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 4 M",												//wszystkie plansze
" T 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 M"},
{
"| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",//124
" S 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5 5 5 6 M",
" T 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 M"}};
int a,b;

int p1=100,p2=100,z=42,o=0,k,k1,l;
int column = 1,column1 = 1;
const int row=0;

zasada();
std::cout<<"1.Jeden gracz"<<std::endl<<"2.Dwoch graczy"<<std::endl;
char m;
std::cin>>m;						//wybor ktory gracz m- zmienia potem kod gdy dla dwoch graczy, domyslnie jest gra z komputerem

std::system("cls");		//czyszcze ekran
	zasada();
std::cout<<"m-MALA"<<std::endl<<"s-SREDNIA"<<std::endl<<"d-DUZA"<<std::endl;
	char c;
	std::cin>>c;
	switch(c){
	case 'm':{
		o=0;					//wybor rozmiaru mapy
		z=42;
	break;}
		
	case 's':{
		o=1;
		z=82;
	break;}
		
	case 'd':{
		o=2;
		z=122;
	break;}
		
	default: {
		
	break;}		
}
b=rand()%(z/2)+1;
b=b*2+1;									//jednorazowe losowanie na mapie nagrody * i pu³apki %
plan[o][row][b]='%';

a=rand()%(z/2)+1;
a=a*2+1;
plan[o][row][a]='*';



while(column1<z&&column<z){
	
	std::system("cls");
	std::vector<std::string> board = plan[o];					//wyœwietlanie mapy, wyswietlanie ruchu gracza B
	std::cout<<"Gracz A: "<<p1<<" Gracz B: "<<p2<<std::endl;
	board[row][column1]='B';
	board[row][column]='A';
	
	for (std::string line: board) {
            std::cout << line << std::endl; }
    
	 std::cout<<"Rzuca Gracz A"<<std::endl;        
    std::cout<<" 1.Rzut kostka - 3"<<std::endl;
	std::cout<<" 2.Rzut kostka - 6"<<std::endl;
	
	 char n;  								//wybór któr¹ kostk¹ gracz chce rzucaæ
	std::cin>>n;   
switch(n){
	case '1':{
		l=3;
		break;}
	case '2':{
		l=6;	
	break;}
	
	default:{
		l=6;
	break;}}
		
		rzut(k,l); 												//rzut
		std::cout<<"Gracz: "<<k<<'!'<<std::endl;
		
		for(int i=1;i<=k;++i){							//ruch GRACZA A po mapie o okreœlon¹ liczbê pól
			
		if(column<z){column+=2;}
		
		}
			for(int u =0;u<750000000;++u){			//odczekanie
	}	
	if((column-1)%4==0){p1+=5;}		//zliczanie punktów GRACZA A
		else if(column<(z-1))p1-=10;
		if(column==column1){
			column1=1;
			p1+=20;
		}
		if(board[row][column]=='*') p1=p1+k*10;
		if(board[row][column]=='%') p1=p1-k*10;	//tutaj do * i %
	
		std::system("cls");
	//
	std::vector<std::string> board2 = plan[o];			//wyœwietlanie ruchu GRACZA A
	std::cout<<"Gracz A: "<<p1<<" Gracz B: "<<p2<<std::endl;
	board2[row][column1]='B';
	board2[row][column]='A';
	
	for (std::string line: board2) {
            std::cout << line << std::endl; }
		
		
		
		
		if(column<z){
			if(m=='2'){				//tutaj wybory dla drugiego gracza, gdy wybrana jest opcja dla 2 graczy
				
				 std::cout<<"Rzuca Gracz B"<<std::endl<<" 1.Rzut kostka - 3"<<std::endl;
	std::cout<<" 2.Rzut kostka - 6"<<std::endl;
	
	 char n;  
	std::cin>>n;   
switch(n){
	case '1':{
		l=3;
		break;}
	case '2':{
		l=6;	
	break;}
	
	default:{
		l=6;
	break;}}
		
		//rzut(k,l);
		//std::cout<<"Gracz: "<<k<<'!'<<std::endl;
			}
		else{
			
		l=6;}					//tutaj ruch komputera dla wersji dla 1 gracza, komputer mo¿e tylko 6 kostki u¿ywaæ
		rzut(k1,l);
		
		for(int i=1;i<=k1;++i){
		
		if(column1<=z){column1+=2;}
		
		}			//
		
		if((column1-1)%4==0){p2+=5;} //tutaj jest podliczenie punktów
		else if(column1<(z-1)) p2-=10;
		if(column1==column){
			column=1;
			p2+=20;}
			if(board2[row][column1]=='*') p2=p2+k1*10;
		if(board2[row][column1]=='%') p2=p2-k1*10;	
		std::cout<<"Przeciwnik: "<<k1<<'!'<<std::endl;
	for(int u =0;u<755500000;++u){
	}
	}		
}
std::system("cls");													//tutaj jest ostatnie wyœwietlenie
	//
	std::vector<std::string> board2 = plan[o];
	std::cout<<"Gracz A: "<<p1<<" Gracz B: "<<p2<<std::endl;
	board2[row][column1]='B';
	board2[row][column]='A';
	
	for (std::string line: board2) {
            std::cout << line << std::endl; }
		
if(p1==p2)std::cout<<"REMIS";							//wskazanie kto wygra
else if(p1>p2)std::cout<<"Wygrywa Gracz A";
else std::cout<<"Wygrawa Gracz B";
}


