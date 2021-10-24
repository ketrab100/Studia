/*************************************************************************************/

//  Szkielet programu do tworzenia modelu sceny 3-D z wizualizacją osi 
//  układu współrzednych

/*************************************************************************************/

#include <windows.h>
#include <iostream>
#include <gl/gl.h>
#include <gl/glut.h>
#include <math.h>
#include <corecrt_math_defines.h>


typedef float point3[3];

/*************************************************************************************/

// Funkcja rysująca osie układu współrzędnych
static GLfloat theta[] = { 0.0, 0.0, 0.0 }; // trzy kąty obrotu
int model = 1;
const int N = 10;
void RandomColor(point3 color)
{
	color[0] = rand() % 100 / 100.0f;
	color[1] = rand() % 100 / 100.0f;
	color[2] = rand() % 100 / 100.0f;
}
void Egg(void)
{
	point3 tab[N][N];
	point3 colors[N][N];
	float u, v;
	float maxy = -1000;
	for (int i = 0; i < N; i++)
	{
		
		u = float(i) / N;
		for (int j = 0; j < N; j++)
		{
			v = float(j) / N;
			tab[i][j][0] = (-90 * pow(u, 5) + 225 * pow(u, 4) - 270 * pow(u, 3) + 180 * pow(u, 2) - 45 * u) * cos(M_PI * v);
			tab[i][j][1] = 160 * pow(u, 4) - 320 * pow(u, 3) + 160 * pow(u, 2);
			maxy = max(tab[i][j][1], maxy);
			tab[i][j][2] = (-90 * pow(u, 5) + 224 * pow(u, 4) - 270 * pow(u, 3) + 180 * pow(u, 2) - 45 * u) * sin(M_PI * v);
			RandomColor(colors[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tab[i][j][1] -= maxy/2;
		}
	}

	if (model == 1)
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_POINTS);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				glVertex3fv(tab[i][j]);
			}
		}
		glEnd();
	}
	if (model == 2)
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (j + 1 < N)
				{
					glBegin(GL_LINES);
					glVertex3fv(tab[i][j]);
					glVertex3fv(tab[i][(j + 1)]);
					glEnd();
				}
				else if (i!=0)
				{
					glBegin(GL_LINES);
					glVertex3fv(tab[i][j]);
					glVertex3fv(tab[N-i][(0)]);
					glEnd();
				}
				if (i + 1 < N)
				{
					glBegin(GL_LINES);
					glVertex3fv(tab[i][j]);
					glVertex3fv(tab[i+1][(j)]);
					glEnd();
				}
				else
				{
					glBegin(GL_LINES);
					glVertex3fv(tab[i][j]);
					glVertex3fv(tab[0][0]);
					glEnd();
				}
				
				if (i+1<N && j+1 <N)
				{
					glBegin(GL_LINES);
					glVertex3fv(tab[i][j]);
					glVertex3fv(tab[i + 1][(j+1)]);
					glEnd();
				}
				else if( i+1==N)
				{
					glBegin(GL_LINES);
					glVertex3fv(tab[i][j]);
					glVertex3fv(tab[0][(j+1)]);
					glEnd();
				}
				else if (j + 1 == N)
				{
					glBegin(GL_LINES);
					glVertex3fv(tab[i][j]);
					glVertex3fv(tab[N-i-1][(0)]);
					glEnd();
				}




			}
		}
		
		
	}
	if (model == 3)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (j + 1 != N)
				{
					glBegin(GL_TRIANGLES);
					glColor3fv(colors[i][j]);
					glVertex3fv(tab[i][j]);
					glColor3fv(colors[(i+1)%N][j]);
					glVertex3fv(tab[(i+1)%N][j]);
					glColor3fv(colors[i][j+1]);
					glVertex3fv(tab[i][j+1]);
					glEnd();
					glBegin(GL_TRIANGLES);
					glColor3fv(colors[(i + 1) % N][j]);
					glVertex3fv(tab[(i + 1) % N][j]);
					glColor3fv(colors[(i + 1) % N][j+1]);
					glVertex3fv(tab[(i + 1) % N][j+1]);
					glColor3fv(colors[i][j + 1]);
					glVertex3fv(tab[i][j + 1]);
					glEnd();
				}
				else
				{
					if (i > 0)
					{
						glBegin(GL_TRIANGLES);
						glColor3fv(colors[(i) ][j]);
						glVertex3fv(tab[(i) ][j]);
						glColor3fv(colors[(i + 1) % N][j]);
						glVertex3fv(tab[(i + 1) % N][j]);
						glColor3fv(colors[(N - i)] [0]);
						glVertex3fv(tab[(N - i)] [0]);
					}
					glBegin(GL_TRIANGLES);
					glColor3fv(colors[(i + 1) % N][j]);
					glVertex3fv(tab[(i + 1) % N][j]);
					glColor3fv(colors[(N-i) % N][0]);
					glVertex3fv(tab[(N - i) % N][0]);
					glColor3fv(colors[(N - 1-i) % N][0]);
					glVertex3fv(tab[(N - 1-i) % N][0]);
					glEnd();
				}

			}
		}
	}
}

void Axes(void)
{

	point3  x_min = { -5.0, 0.0, 0.0 };
	point3  x_max = { 5.0, 0.0, 0.0 };
	// początek i koniec obrazu osi x

	point3  y_min = { 0.0, -5.0, 0.0 };
	point3  y_max = { 0.0,  5.0, 0.0 };
	// początek i koniec obrazu osi y

	point3  z_min = { 0.0, 0.0, -5.0 };
	point3  z_max = { 0.0, 0.0,  5.0 };
	//  początek i koniec obrazu osi y

	glColor3f(1.0f, 0.0f, 0.0f);  // kolor rysowania osi - czerwony
	glBegin(GL_LINES); // rysowanie osi x

	glVertex3fv(x_min);
	glVertex3fv(x_max);

	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);  // kolor rysowania - zielony
	glBegin(GL_LINES);  // rysowanie osi y

	glVertex3fv(y_min);
	glVertex3fv(y_max);

	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);  // kolor rysowania - niebieski
	glBegin(GL_LINES); // rysowanie osi z

	glVertex3fv(z_min);
	glVertex3fv(z_max);

	glEnd();
	glColor3f(1.0f, 1.0f, 1.0f); // Ustawienie koloru rysowania na biały


	//glRotated(60.0, 1.0, 1.0, 1.0);
	//glutWireTeapot(3.0); // Narysowanie obrazu czajnika do herbaty
	

}

/*************************************************************************************/

// Funkcja określająca co ma być rysowane (zawsze wywoływana gdy trzeba
// przerysować scenę)

void spinEgg()
{

	theta[0] -= 0.5;
	if (theta[0] > 360.0) theta[0] -= 360.0;

	theta[1] -= 0.5;
	if (theta[1] > 360.0) theta[1] -= 360.0;

	theta[2] -= 0.5;
	if (theta[2] > 360.0) theta[2] -= 360.0;

	glutPostRedisplay(); //odświeżenie zawartości aktualnego okna
}

void RenderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Czyszczenie okna aktualnym kolorem czyszczącym

	glLoadIdentity();
	// Czyszczenie macierzy bieżącej
	glRotatef(theta[0], 1.0, 0.0, 0.0);

	glRotatef(theta[1], 0.0, 1.0, 0.0);

	glRotatef(theta[2], 0.0, 0.0, 1.0);

	Egg();
	// Narysowanie osi przy pomocy funkcji zdefiniowanej wyżej

	glFlush();
	// Przekazanie poleceń rysujących do wykonania



	glutSwapBuffers();
	//

}

/*************************************************************************************/

// Funkcja ustalająca stan renderowania



void MyInit(void)
{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Kolor czyszcący (wypełnienia okna) ustawiono na czarny

}

/*************************************************************************************/

// Funkcja ma za zadanie utrzymanie stałych proporcji rysowanych
// w przypadku zmiany rozmiarów okna.
// Parametry vertical i horizontal (wysokość i szerokość okna) są
// przekazywane do funkcji za każdym razem gdy zmieni się rozmiar okna.



void ChangeSize(GLsizei horizontal, GLsizei vertical)
{

	GLfloat AspectRatio;
	// Deklaracja zmiennej AspectRatio  określającej proporcję
	// wymiarów okna 

	if (vertical == 0)  // Zabezpieczenie przed dzieleniem przez 0

		vertical = 1;

	glViewport(0, 0, horizontal, vertical);
	// Ustawienie wielkościokna okna widoku (viewport)
	// W tym przypadku od (0,0) do (horizontal, vertical)  

	glMatrixMode(GL_PROJECTION);
	// Przełączenie macierzy bieżącej na macierz projekcji 

	glLoadIdentity();
	// Czyszcznie macierzy bieżącej            

	AspectRatio = (GLfloat)horizontal / (GLfloat)vertical;
	// Wyznaczenie współczynnika  proporcji okna
	// Gdy okno nie jest kwadratem wymagane jest określenie tak zwanej
	// przestrzeni ograniczającej pozwalającej zachować właściwe
	// proporcje rysowanego obiektu.
	// Do okreslenia przestrzeni ograniczjącej służy funkcja
	// glOrtho(...)            

	if (horizontal <= vertical)

		glOrtho(-7.5, 7.5, -7.5 / AspectRatio, 7.5 / AspectRatio, 10.0, -10.0);

	else

		glOrtho(-7.5 * AspectRatio, 7.5 * AspectRatio, -7.5, 7.5, 10.0, -10.0);

	glMatrixMode(GL_MODELVIEW);
	// Przełączenie macierzy bieżącej na macierz widoku modelu                                    

	glLoadIdentity();
	// Czyszcenie macierzy bieżącej

}

/*************************************************************************************/

// Główny punkt wejścia programu. Program działa w trybie konsoli

void keys(unsigned char key, int x, int y)
{
	if (key == 'p') model = 1;
	if (key == 'w') model = 2;
	if (key == 's') model = 3;

	RenderScene(); // przerysowanie obrazu sceny
}

void main(void)
{

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(300, 300);

	glutCreateWindow("Układ współrzędnych 3-D");
	glutKeyboardFunc(keys);
	glutIdleFunc(spinEgg);
	glutDisplayFunc(RenderScene);
	// Określenie, że funkcja RenderScene będzie funkcją zwrotną
	// (callback function).  Bedzie ona wywoływana za każdym razem
	// gdy zajdzie potrzba przeryswania okna 

	glutReshapeFunc(ChangeSize);
	// Dla aktualnego okna ustala funkcję zwrotną odpowiedzialną
	// zazmiany rozmiaru okna      

	MyInit();
	// Funkcja MyInit() (zdefiniowana powyżej) wykonuje wszelkie
	// inicjalizacje konieczne  przed przystąpieniem do renderowania 

	glEnable(GL_DEPTH_TEST);
	// Włączenie mechanizmu usuwania powierzchni niewidocznych

	glutMainLoop();
	// Funkcja uruchamia szkielet biblioteki GLUT

}

/*************************************************************************************/