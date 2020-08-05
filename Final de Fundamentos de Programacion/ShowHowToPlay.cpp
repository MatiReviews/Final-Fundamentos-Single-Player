#include <iostream>
#include <Windows.h>
#include "SetColor.h"
#include "Color.h"
#include "PowerUps.h"

void ShowHowToPlay(Color powerUpColor)
{
	system("cls");
	std::cout << "Bienvenido a ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)SetColor::IntenseGreen);
	std::cout << "Asterisk." << "\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)SetColor::White);
	std::cout << "Le mostraremos lo basico para que entienda la mecanica del juego." << "\n";

	std::cout << "\nEl jugador es 'P' y durante su sesion de juego, estara en un mapa en donde se\ngeneraran asteriscos(*), los cuales debera evitar para poder juntar la mayor" << "\n";
	std::cout << "cantidad de puntos al terminar la partida." << "\n";

	std::cout << "\nLos asteriscos pueden aparecer en la posicion del jugador, incluso estando quieto\no moviendose por el mapa, haciendo que pierda los puntos ganados." << "\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)SetColor::IntenseGreen);
	std::cout << "\nModos de Juego:" << "\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)SetColor::White);
	std::cout << "1.30 segundos: " << "\n";
	std::cout << "En este modo de juego, usted contara con 30 segundos para juntar la mayor cantidad\nde puntos. " << "\n";

	std::cout << "\n2.Unica Vida:" << "\n";
	std::cout << "En este modo de juego tendra que juntar la mayor cantidad de puntos sin chocar con\nlos asteriscos(*)." << "\n";

	std::cout << "\n3.Tiempo Ilimitado:" << "\n";
	std::cout << "Como el nombre lo indica, podra jugar sin tiempo limite procurando hacer la mayor\npuntuacion posible. " << "\n";
	std::cout << "Para salir de este o cualquier otro modo , aprete la tecla ESC en su teclado." << "\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)SetColor::IntenseGreen);
	std::cout << "\nPower Ups." << "\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color1);
	std::cout << (char)PowerUp::SpeedUp;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color4);
	std::cout << "- Velocidad Rapida: Duplica la velocidad de juego" << "\n";

	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color2);
	std::cout << (char)PowerUp::DoublePoints;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color4);
	std::cout << "- Puntos Dobles: Duplica la cantidad de puntos ganados" << "\n";
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color3);
	std::cout << (char)PowerUp::GodMode;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color4);	
	std::cout << "- Modo Dios: Los asteriscos no te haran danio al tocarlos" << "\n";

	std::cout << "\nESC para salir";
}