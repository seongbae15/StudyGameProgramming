#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
using namespace std;
///////////////////////////////////////////////////////
#define MAP_WIDTH 65
#define MAP_HEIGHT 35
#define MAX_NAME_LEN 10
//////////////////////////////////////////////////////
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PURPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//���� ����
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
#define BG_GRAY_TEXT_RED SetConsoleTextAttribute( col,0x008c );
#define BG_GRAY_TEXT_BLUE_GREEN SetConsoleTextAttribute( col,0x0083 );
#define BG_GRAY_TEXT_PURPLE SetConsoleTextAttribute( col,0x0085 );
#define BG_GRAY_TEXT_ORIGINAL SetConsoleTextAttribute( col,0x0087 );
//////////////////////////////////////////////////////
#define MAP_WIDTH 65
#define MAP_HEIGHT 35
