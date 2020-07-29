#include <iostream>
#include <Windows.h>
#include "SetColor.h"

void ShowHowToPlay()
{
	system("cls");
	std::cout << "Bienvenido a ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)SetColor::IntenseGreen);
	std::cout << "Asterisk." << "\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)SetColor::White);
	std::cout << "\nLe mostraremos lo basico para que entienda la mecanica del juego." << "\n";

	std::cout << "\nUsted sera el jugador 'P'. Durante su sesion de juego, estara en un mapa en donde\nse generaran asteriscos(*), los cuales debera evitar para poder juntar la mayor" << "\n";
	std::cout << "cantidad de puntos al terminar la partida." << "\n";

	std::cout << "\nModos de Juego:" << "\n";
	std::cout << "1.30 segundos: " << "\n";
	std::cout << "En este modo de juego, usted contara con 30 segundos para juntar la mayor cantidad\nde puntos. " << "\n";

	std::cout << "\n2.Unica Vida:" << "\n";
	std::cout << "En este modo de juego tendra que juntar la mayor cantidad de puntos sin chocar con\nlos asteriscos(*)." << "\n";

	std::cout << "\n3.Tiempo Ilimitado:" << "\n";
	std::cout << "Como el nombre lo indica, podra jugar sin tiempo limite procurando hacer la mayor\npuntuacion posible. " << "\n";
	std::cout << "Para salir de este modo, aprete la tecla ESC en su teclado." << "\n";


	std::cout << "\nESC para salir" << "\n";
}