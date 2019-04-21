#include<graphics.h>
#include<windows.h>

COORD coord;
void windowsize(int x, int y)
{	
	SMALL_RECT rect;
	coord.X=x; // Defining out X and
	coord.Y=y; // Y size for buffer.
	rect.Top=0;
	rect.Left=0;
	rect.Bottom=coord.Y-1; // Height for window
	rect.Right=coord.X-1; // Width for window
	HANDLE hwnd=GetStdHandle(STD_OUTPUT_HANDLE); // Get handle
	SetConsoleScreenBufferSize(hwnd, coord); // Set buffer size
	SetConsoleWindowInfo(hwnd, TRUE, &rect); // Set window size
	
	HWND hConsole;
	SetConsoleTitle("PROJECT 1.2");
	Sleep(10); //Let the window to update the Title!
	hConsole=FindWindow(NULL, "PROJECT 1.2");
	HMENU hMenu = GetSystemMenu ( (HWND)hConsole, FALSE);
	::DeleteMenu( hMenu, 2, MF_BYPOSITION); // disable 'Size'
	::DeleteMenu( hMenu, 3, MF_BYPOSITION); // disable 'Maximize'
}

void hidecursor (char string)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursoInfo;
	CursoInfo.dwSize = 1;         // The size of caret
	CursoInfo.bVisible = !(string);   // Caret is visible?
	SetConsoleCursorInfo(hConsole, &CursoInfo);
}

void console_color(int color)
{
	HANDLE col=GetStdHandle(STD_OUTPUT_HANDLE);
	
	switch (color)
	{
		case 0:
			SetConsoleTextAttribute(col, 0);	// BLACK
			break;
			
		case 1:
			SetConsoleTextAttribute(col, FOREGROUND_BLUE);	// DARKBLUE
			break;
			
		case 2:
			SetConsoleTextAttribute(col, FOREGROUND_GREEN);	// DARKGREEN 
			break;
			
		case 3:
			SetConsoleTextAttribute(col, FOREGROUND_GREEN | FOREGROUND_BLUE);	// DARKCYAN
			break;
			
		case 4:
			SetConsoleTextAttribute(col, FOREGROUND_RED);	// DARKRED 
			break;
			
		case 5:
			SetConsoleTextAttribute(col, FOREGROUND_RED | FOREGROUND_BLUE);	// DARKMAGENTA
			break;
			
		case 6:
			SetConsoleTextAttribute(col, FOREGROUND_RED | FOREGROUND_GREEN);	// DARKYELLOW
			break;
			
		case 7:
			SetConsoleTextAttribute(col, FOREGROUND_INTENSITY);	// GRAY
			break;
			
		case 8:
			SetConsoleTextAttribute(col, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);	// DARKGRAY
			break;
			
		case 9:
			SetConsoleTextAttribute(col, FOREGROUND_INTENSITY | FOREGROUND_BLUE);	// BLUE
			break;
			
		case 10:
			SetConsoleTextAttribute(col, FOREGROUND_INTENSITY | FOREGROUND_GREEN);	// GREEN
			break;
			
		case 11:
			SetConsoleTextAttribute(col, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);	// CYAN
			break;
			
		case 12:
			SetConsoleTextAttribute(col, FOREGROUND_INTENSITY | FOREGROUND_RED);	// RED
			break;
			
		case 13:
			SetConsoleTextAttribute(col, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);	// MAGENTA
			break;
			
		case 14:
			SetConsoleTextAttribute(col, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);	// YELLOW
			break;
			
		case 15:
			SetConsoleTextAttribute(col, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);	// WHITE
			break;
	}
}

void display(int n, int** array)
{
	int scl, disp;
	
	coord.X=(int)(GetSystemMetrics(SM_CXSCREEN));
	coord.Y=(int)(GetSystemMetrics(SM_CYSCREEN));
	
	scl=coord.Y/(n+1);
	
	disp=initwindow(coord.Y, coord.Y, "PROJECT 10", 0, 0);
	setcurrentwindow(disp);
	cleardevice();
	
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (array[i][j]==1)
			{
				setfillstyle(SOLID_FILL, GREEN);
				floodfill((j*scl), (i*scl), 15);
			}
			else
			{
				
				setfillstyle(SOLID_FILL, CYAN);
				floodfill((j*scl), (i*scl), 15);
			}
			rectangle((j*scl), (i*scl), ((i+1)*scl), ((j+1)*scl));
		}
	}
	
	while(!kbhit()) delay(1);
	
	closegraph();
}
