/*************************************************************************************/

//  Szkielet programu do tworzenia modelu sceny 3-D z wizualizacj¹ osi 
//  uk³adu wspó³rzêdnych dla rzutowania perspektywicznego

/*************************************************************************************/

#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include<cmath>


typedef float point3[3];

static GLfloat viewer[] = { 0.0, 0.0, 10.0 };
// inicjalizacja po³o¿enia obserwatora
static GLfloat radius = 0.0;
static GLfloat theta = 0.0;   // k¹t obrotu obiektu

static GLfloat phi = 0.0;
static GLfloat pix2angle = 0.0;     // przelicznik pikseli na stopnie

static GLint statusl = 0;       // stan klawiszy myszy
                               // 0 - nie naciœniêto ¿adnego klawisza
                               // 1 - naciœniêty zostaæ lewy klawisz
static GLint statusr = 0;



static int x_pos_old = 0;       // poprzednia pozycja kursora myszy
static int y_pos_old = 0;
static int delta_x = 0;        // ró¿nica pomiêdzy pozycj¹ bie¿¹c¹
static int delta_y = 0;        // i poprzedni¹ kursora myszy

static int z_pos_old = 0;
static int delta_z = 0;


/*************************************************************************************/

// Funkcja rysuj¹ca osie uk³adu wspó?rz?dnych

typedef float point3[3];
int model = 3;  // 1- punkty, 2- siatka, 3 - wype³nione trójk¹ty

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
        glRotated(15, 1, 0, 0);
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
        glRotated(15, 1, 0, 0);
        glBegin(GL_LINES);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                glVertex3fv(array[i][j]);
                glVertex3fv(array[(i + 1) % n][j]);
                if (j + 1 < n)
                {
                    glVertex3fv(array[i][j]);
                    glVertex3fv(array[i][j + 1]);
                }
                else
                {
                    glVertex3fv(array[i][j]);
                    glVertex3fv(array[(n - i) % n][0]);
                }
                if (j + 1 < n)
                {
                    glVertex3fv(array[i][j]);
                    glVertex3fv(array[(i + 1) % n][j + 1]);
                }
                else
                {
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


void Axes(void)
{

    point3  x_min = { -5.0, 0.0, 0.0 };
    point3  x_max = { 5.0, 0.0, 0.0 };
    // pocz?tek i koniec obrazu osi x

    point3  y_min = { 0.0, -5.0, 0.0 };
    point3  y_max = { 0.0,  5.0, 0.0 };
    // pocz?tek i koniec obrazu osi y

    point3  z_min = { 0.0, 0.0, -5.0 };
    point3  z_max = { 0.0, 0.0,  5.0 };
    //  pocz?tek i koniec obrazu osi y

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

}


/*************************************************************************************/
// Funkcja "bada" stan myszy i ustawia wartoœci odpowiednich zmiennych globalnych

void Mouse(int btn, int state, int x, int y)
{


    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        x_pos_old = x;        // przypisanie aktualnie odczytanej pozycji kursora
                                // jako pozycji poprzedniej
        statusl = 1;          // wciêniêty zosta³ lewy klawisz myszy

        y_pos_old = y;
    }
    else
        statusl = 0;          // nie zosta³ wciêniêty ¿aden klawisz

    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        z_pos_old = y;
        statusr = 1;
    }
    else
        statusr = 0;
}

/*************************************************************************************/
// Funkcja "monitoruje" po³o¿enie kursora myszy i ustawia wartoœci odpowiednich
// zmiennych globalnych

void Motion(GLsizei x, GLsizei y)
{

    delta_x = x - x_pos_old;     // obliczenie ró¿nicy po³o¿enia kursora myszy

    x_pos_old = x;            // podstawienie bie¿¹cego po³o¿enia jako poprzednie

    delta_y = y - y_pos_old;

    y_pos_old = y;


    delta_z = y - z_pos_old;
    z_pos_old = y;

    glutPostRedisplay();     // przerysowanie obrazu sceny
}

/*************************************************************************************/



/*************************************************************************************/

// Funkcja okreœlaj¹ca co ma byæ rysowane (zawsze wywo³ywana, gdy trzeba
// przerysowaæ scenê)



void RenderScene(void)
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Czyszczenie okna aktualnym kolorem czyszcz¹cym

    glLoadIdentity();
    // Czyszczenie macierzy bie??cej

    if (statusr == 1)
    {
       radius += delta_z;
       if (radius > 15)
       {
           radius = 15;
       }
       if (radius < 0.5)
       {
           radius = 0.5;
       }
    }

    
    // Zdefiniowanie po³o¿enia obserwatora

    Axes();
    // Narysowanie osi przy pomocy funkcji zdefiniowanej powy¿ej 

    if (statusl == 1)                     // jeœli lewy klawisz myszy wciêniêty
    {
        theta += delta_x * pix2angle/100;    // modyfikacja k¹ta obrotu o kat proporcjonalny
        phi += delta_y * pix2angle/100;      // do ró¿nicy po³o¿eñ kursora myszy
    }         

    viewer[0] = radius * cos(theta) * cos(phi);
    viewer[1] = radius * sin(phi);
    viewer[2] = radius * sin(theta) * cos(phi);

    gluLookAt(viewer[0], viewer[1], viewer[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


    glColor3f(1.0f, 1.0f, 1.0f);
    // Ustawienie koloru rysowania na bia³y

    Egg();
    // Narysowanie czajnika 

    glFlush();
    // Przekazanie poleceñ rysuj¹cych do wykonania

    glutSwapBuffers();



}
/*************************************************************************************/

// Funkcja ustalaj¹ca stan renderowania



void MyInit(void)
{

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // Kolor czyszcz¹cy (wype³nienia okna) ustawiono na czarny

}

/*************************************************************************************/

// Funkcja ma za zadanie utrzymanie sta³ych proporcji rysowanych
// w przypadku zmiany rozmiarów okna.
// Parametry vertical i horizontal (wysokoœæ i szerokoœæ okna) s¹ 
// przekazywane do funkcji za ka¿dym razem gdy zmieni siê rozmiar okna.



void ChangeSize(GLsizei horizontal, GLsizei vertical)
{
    pix2angle = 360.0 / (float)horizontal;  // przeliczenie pikseli na stopnie

    glMatrixMode(GL_PROJECTION);
    // Prze³¹czenie macierzy bie¿¹cej na macierz projekcji

    glLoadIdentity();
    // Czyszcznie macierzy bie¿¹cej

    gluPerspective(70, 1.0, 1.0, 30.0);
    // Ustawienie parametrów dla rzutu perspektywicznego


    if (horizontal <= vertical)
        glViewport(0, (vertical - horizontal) / 2, horizontal, horizontal);

    else
        glViewport((horizontal - vertical) / 2, 0, vertical, vertical);
    // Ustawienie wielkoœci okna okna widoku (viewport) w zale¿noœci
    // relacji pomiêdzy wysokoœci¹ i szerokoœci¹ okna

    glMatrixMode(GL_MODELVIEW);
    // Prze³¹czenie macierzy bie¿¹cej na macierz widoku modelu  

    glLoadIdentity();
    // Czyszczenie macierzy bie¿¹cej

}

/*************************************************************************************/

// G³ówny punkt wejœcia programu. Program dzia³a w trybie konsoli



void main(void)
{
    randomColors();
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(300, 300);





    glutCreateWindow("Rzutowanie perspektywiczne");

    glutDisplayFunc(RenderScene);
    // Okreœlenie, ¿e funkcja RenderScene bêdzie funkcj¹ zwrotn¹
    // (callback function).  Bêdzie ona wywo³ywana za ka¿dym razem
    // gdy zajdzie potrzeba przerysowania okna

    glutMouseFunc(Mouse);
    // Ustala funkcjê zwrotn¹ odpowiedzialn¹ za badanie stanu myszy

    glutMotionFunc(Motion);
    // Ustala funkcjê zwrotn¹ odpowiedzialn¹ za badanie ruchu myszy



    glutReshapeFunc(ChangeSize);
    // Dla aktualnego okna ustala funkcjê zwrotn¹ odpowiedzialn¹
    // za zmiany rozmiaru okna                       



    MyInit();
    // Funkcja MyInit() (zdefiniowana powy¿ej) wykonuje wszelkie
    // inicjalizacje konieczne  przed przyst¹pieniem do renderowania 

    glEnable(GL_DEPTH_TEST);
    // W³¹czenie mechanizmu usuwania niewidocznych elementów sceny

    glutMainLoop();
    // Funkcja uruchamia szkielet biblioteki GLUT

}

/*************************************************************************************/