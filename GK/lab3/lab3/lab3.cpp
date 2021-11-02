#include <windows.h>
#include <cmath>
#include <math.h>
#include <gl/gl.h>
#include <gl/glut.h>


typedef float point3[3];
int model = 1;  // 1- punkty, 2- siatka, 3 - wypełnione trójkąty
static GLfloat theta[] = { 0.0, 0.0, 0.0 }; // trzy kąty obrotu

/*************************************************************************************/
const int n = 20;
//tablica zawierajaca informacje o kolorach
point3 colors[n][n];

//Funkcja wypelniajaca tablice losowymi kolorami
void randomColors()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			colors[i][j][0] = float(rand() % 101) / 100;
			colors[i][j][1] = float(rand() % 101) / 100;
			colors[i][j][2] = float(rand() % 101) / 100;
		}
	}
}

//Funkcja rysujaca jajko
void Egg(void)
{
	// tablica punktow 
	point3 array[n][n];
	float u, v;
	//generowanie wspolrzednych punktow w 3D
	for (int i = 0; i < n; i++)
	{
		u = float(i) / n;
		for (int j = 0; j < n; j++)
		{
			v = float(j) / n;
			array[i][j][0] = (-90 * pow(u, 5) + 225 * pow(u, 4) - 270 * pow(u, 3) + 180 * pow(u, 2) - 45 * u) * cos(3.14 * v);
			array[i][j][1] = 160 * pow(u, 4) - 320 * pow(u, 3) + 160 * pow(u, 2) - 3.5f;
			array[i][j][2] = (-90 * pow(u, 5) + 225 * pow(u, 4) - 270 * pow(u, 3) + 180 * pow(u, 2) - 45 * u) * sin(3.14 * v);
		}
	}
	//rysowanie punktow
	if (model == 1)
	{
		glColor3f(1.0f, 1.0f, 0);
		glBegin(GL_POINTS);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				glVertex3fv(array[i][j]);
			}
		}
		glEnd();
	}
	//rysowanie siatki
	if (model == 2)
	{
		glColor3f(1.0f, 1.0f, 0);
		glBegin(GL_LINES);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				//linie pionowe
				glVertex3fv(array[i][j]);
				glVertex3fv(array[(i + 1) % n][j]);
				
				if (j + 1 < n)
				{
					//linie poziome
					glVertex3fv(array[i][j]);
					glVertex3fv(array[i][j + 1]);
				}
				else
				{
					//polczenie linii poziomch w pelny okrag
					glVertex3fv(array[i][j]);
					glVertex3fv(array[(n - i) % n][0]);
				}
				if (j + 1 < n)
				{
					//linie skosne
					glVertex3fv(array[i][j]);
					glVertex3fv(array[(i + 1) % n][j + 1]);
				}
				else
				{
					//lczenie linii skosnych
					glVertex3fv(array[i][j]);
					glVertex3fv(array[(n - (i + 1)) % n][0]);
				}
			}
		}
		glEnd();
	}
	//rysowanie trojkatow
	if (model == 3)
	{
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j + 1 < n)
				{
					glColor3fv(colors[i][j]);
					glVertex3fv(array[i][j]);
					glColor3fv(colors[(i + 1) % n][j]);
					glVertex3fv(array[(i + 1) % n][j]);
					glColor3fv(colors[(i + 1) % n][j + 1]);
					glVertex3fv(array[(i + 1) % n][j + 1]);
				}
				else
				{
					//laczenie trojkatow w osi poziomej 
					glColor3fv(colors[i][j]);
					glVertex3fv(array[i][j]);
					glColor3fv(colors[(i + 1) % n][j]);
					glVertex3fv(array[(i + 1) % n][j]);
					glColor3fv(colors[(n - (i + 1)) % n][0]);
					glVertex3fv(array[(n - (i + 1)) % n][0]);
				}
				if (j + 1 < n)
				{
					glColor3fv(colors[i][j]);
					glVertex3fv(array[i][j]);
					glColor3fv(colors[i][j + 1]);
					glVertex3fv(array[i][j + 1]);
					glColor3fv(colors[(i + 1) % n][j + 1]);
					glVertex3fv(array[(i + 1) % n][j + 1]);
				}
				else
				{
					//laczenie trojkatow w osi poziomej
					glColor3fv(colors[i][j]);
					glVertex3fv(array[i][j]);
					glColor3fv(colors[(n - i) % n][0]);
					glVertex3fv(array[(n - i) % n][0]);
					glColor3fv(colors[(n - (i + 1)) % n][0]);
					glVertex3fv(array[(n - (i + 1)) % n][0]);
				}
			}
		}
		glEnd();
	}

}



// Funkcja rysująca osie układu współrzędnych
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
	glRotated(60.0, 1.0, 1.0, 1.0);  // Obrót o 60 stopni
	glutWireTeapot(3.0); // Narysowanie obrazu czajnika do herbaty
}

/*************************************************************************************/

// Funkcja określająca co ma być rysowane (zawsze wywoływana gdy trzeba
// przerysować scenę)



void RenderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Czyszczenie okna aktualnym kolorem czyszczącym

	glLoadIdentity();
	// Czyszczenie macierzy bieżącej

	// Narysowanie osi przy pomocy funkcji zdefiniowanej wyżej
	glRotatef(theta[0], 1.0, 0.0, 0.0);

	glRotatef(theta[1], 0.0, 1.0, 0.0);

	glRotatef(theta[2], 0.0, 0.0, 1.0);

	Egg();

	glFlush();
	// Przekazanie poleceń rysujących do wykonania



	glutSwapBuffers();

}


void keys(unsigned char key, int x, int y)
{
	if (key == 'p') model = 1;
	if (key == 'w') model = 2;
	if (key == 's') model = 3;

	RenderScene(); // przerysowanie obrazu sceny
}

/*************************************************************************************/

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



void main(void)
{
	randomColors();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(300, 300);

	glutCreateWindow("Jajko");

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