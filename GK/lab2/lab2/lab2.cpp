#include <windows.h>

#include <gl/gl.h>

#include <gl/glut.h>

//definicj typu point2
typedef float point2[2];
//procent perturbacji
float disp = 0.02f;
//ilosc poziomow dywanu
int level = 3;
//rozmiar dywanu
float size = 190;
//dywan jest kolorowy czy bialy
bool color = true;


//stawienie glColor na losowy kolor
void RandomColor()
{
	// losowanie wartosci kazdego z kanalow RGB
	float r = rand() % 100 / 100.0f;
	float g = rand() % 100 / 100.0f;
	float b = rand() % 100 / 100.0f;
	glColor3f(r, g, b);
}

//dodanie perturbacji
void AddDisp(point2 tl, float len)
{
	//losowanie liczby z przedziału (0,100)
	int r = rand() % 101;
	//obliczenie przesuniecia kwadratu 
	//przesuniecie jest z przedzialu (-len*disp,len*disp)
	float d = len * disp * r /100 ;
	//losowanie drugi raz liczy r
	r = rand() % 101;
	//jezeli r>50 przesuwam kwadrat w lewo
	if (r > 50)
	{
		d *= -1;
	}
	tl[0] += d;
	d *= -1;
	r = rand() % 101;
	//jezeli r>50 przesuwam kwadrat w dol
	if (r > 50)
	{
		d *= -1;
	}
	tl[1] += d;
}

//narysowanie kwadratu
void DrawRect(point2 topLeft, point2 botRight, bool color)
{
	point2 topRight = { botRight[0],topLeft[1] };
	point2 botLeft = { topLeft[0], botRight[1] };
	if (color == true)
	{
		glBegin(GL_POLYGON);
		RandomColor();
		glVertex2fv(topLeft);
		RandomColor();
		glVertex2fv(topRight);
		RandomColor();
		glVertex2fv(botRight);
		RandomColor();
		glVertex2fv(botLeft);
		glEnd();
	}
	else
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_POLYGON);
		glVertex2fv(topLeft);
		glVertex2fv(topRight);
		glVertex2fv(botRight);
		glVertex2fv(botLeft);
		glEnd();
	}
}


//narysowanie dywanu Sierpinskiego
void DrawFractal(point2 point, float len, int level, bool color)
{
	//dodanie perturbacji
	AddDisp(point, len);
	//warunek przerwania rekurncji
	if (level == 0)
	{
		point2 point2 = { point[0] + len,point[1] - len };
		//narysowanie kwadratu
		DrawRect(point, point2, color);
		return;
	}
	//dlugosc krawedzi mniejszego kwadratu jest 3 razy mniejsza 
	//od dlugosci krawdzedzi duzego kwadratu 
	len /= 3;
	//rysowanie mniejszych kwadratow zaczynam od lewego gornego rogu
	float x = point[0];
	float y = point[1];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//jezeli nie jest to srodkowy kwadrat 
			if (i != 1 || j != 1)
			{
				//wywoluje kolejny poziom rekurnecji
				point2 newPoint = { x,y };
				DrawFractal(newPoint, len, level - 1, color);
			}
			x += len;
		}
		y -= len;
		x = point[0];
	}
}

// Funkcaja określająca, co ma być rysowane
// (zawsze wywoływana, gdy trzeba przerysować scenę)
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	// Czyszczenie okna aktualnym kolorem czyszczącym

	point2 tl = { -size / 2,size / 2 };

	DrawFractal(tl, size, level, color);

	glFlush();
	// Przekazanie poleceń rysujących do wykonania
}


// Funkcja ustalająca stan renderowania
void MyInit(void)
{

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	// Kolor okna wnętrza okna - ustawiono na szary

}

// Funkcja służąca do kontroli zachowania proporcji rysowanych obiektów
// niezależnie od rozmiarów okna graficznego
void ChangeSize(GLsizei horizontal, GLsizei vertical)
// Parametry horizontal i vertical (szerokość i wysokość okna) są
// przekazywane do funkcji za każdym razem, gdy zmieni się rozmiar okna
{

	GLfloat AspectRatio;

	// Deklaracja zmiennej AspectRatio określającej proporcję wymiarów okna



	if (vertical == 0)
		// Zabezpieczenie pzred dzieleniem przez 0

		vertical = 1;

	glViewport(0, 0, horizontal, vertical);
	// Ustawienie wielkościokna okna urządzenia (Viewport)
	// W tym przypadku od (0,0) do (horizontal, vertical)

	glMatrixMode(GL_PROJECTION);
	// Określenie układu współrzędnych obserwatora

	glLoadIdentity();
	// Określenie przestrzeni ograniczającej

	AspectRatio = (GLfloat)horizontal / (GLfloat)vertical;
	// Wyznaczenie współczynnika proporcji okna

	// Gdy okno na ekranie nie jest kwadratem wymagane jest
	// określenie okna obserwatora.
	// Pozwala to zachować właściwe proporcje rysowanego obiektu
	// Do określenia okna obserwatora służy funkcja glOrtho(...)



	if (horizontal <= vertical)

		glOrtho(-100.0, 100.0, -100.0 / AspectRatio, 100.0 / AspectRatio, 1.0, -1.0);

	else

		glOrtho(-100.0 * AspectRatio, 100.0 * AspectRatio, -100.0, 100.0, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	// Określenie układu współrzędnych    

	glLoadIdentity();

}

// Główny punkt wejścia programu. Program działa w trybie konsoli
void main(void)
{

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	// Ustawienie trybu wyświetlania
	// GLUT_SINGLE - pojedynczy bufor wyświetlania
	// GLUT_RGBA - model kolorów RGB



	glutCreateWindow("Dywan Sierpińskiego z perturbacjami");
	// Utworzenie okna i określenie treści napisu w nagłówku okna

	glutDisplayFunc(RenderScene);
	// Określenie, że funkcja RenderScene będzie funkcją zwrotną (callback)
	// Biblioteka GLUT będzie wywoływała tą funkcję za każdym razem, gdy
	// trzeba będzie przerysować okno


	glutReshapeFunc(ChangeSize);
	// Dla aktualnego okna ustala funkcję zwrotną odpowiedzialną za
	// zmiany rozmiaru okna

	MyInit();
	// Funkcja MyInit (zdefiniowana powyżej) wykonuje wszelkie
	// inicjalizacje konieczneprzed przystąpieniem do renderowania


	glutMainLoop();
	// Funkcja uruchamia szkielet biblioteki GLUT
}
