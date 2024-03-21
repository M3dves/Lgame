#include <iostream>
#include <winbgim.h>
#include <graphics.h>
#include <stdlib.h>
using namespace std;
struct optiuneCerc
{
int culoare;
int pozitie;
} vectorcerc[3];
struct optiuneL
{
int l1, l2;
int pozitie;
} vectorL[3];
void meniu(int bk, int vectorbk[], optiuneCerc vectorcerc[], optiuneL vectorL[]);
void selectare(int bk, int vectorbk[], optiuneCerc vectorcerc[], optiuneL vectorL[]);
void schimbarepagina(int mx, int my, int bk, int vectorbk[], optiuneCerc vectorcerc[], optiuneL vectorL[]);
void modJocPvP(int L1, int L2,int bk, optiuneCerc vectorcerc[], optiuneL vectorL[]);
void modJocPvComputerEasy(int L1, int L2,int bk, optiuneCerc vectorcerc[], optiuneL vectorL[]);
void modJocPvComputerHard(int L1, int L2,int bk,int vectorbk[],optiuneCerc vectorcerc[], optiuneL vectorL[]);
void setaripag1(int bk, int vectorbk[], optiuneCerc vectorcerc[], optiuneL vectorL[]);
void selectSetari1(int bk, int vectorbk[], optiuneCerc vectorcerc[], optiuneL vectorL[]);
void setaripag2(int bk, int vectorbk[]);
void selectSetari2(int bk, int vectorbk[]);
bool DejaPus();
void MutaCalculatorulRand(int jucator, int bk);
bool DejaPus(int lin1, int col1, int lin2, int col2, int lin3, int col3, int lin4, int col4, int jucator);
int leftt = 200, topp = 200, rightt = 600, bottomm = 600;
struct patratel
{
bool gri = 0;
int x, y;
int val;
} Tabla[4][4];
bool Mutare_Posibila(int lin1, int col1, int lin2, int col2, int lin3, int col3, int lin4, int col4, int jucator
)
{
if (Tabla[lin1][col1].val == 0 || Tabla[lin1][col1].val == jucator)
if (Tabla[lin2][col2].val == 0 || Tabla[lin2][col2].val == jucator)
if (Tabla[lin3][col3].val == 0 || Tabla[lin3][col3].val == jucator)
if (Tabla[lin4][col4].val == 0 || Tabla[lin4][col4].val == jucator)
return 1;
return 0;
}
bool End_game(int jucator)
{
int cnt = 0;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
 {
if (i >= 2 && j <= 2 && Mutare_Posibila(i, j, i - 1, j, i - 2, j, i - 2, j + 1, jucator))
cnt++;
if (i >= 2 && j >= 1 && Mutare_Posibila(i, j, i - 1, j, i - 2, j, i - 2, j - 1, jucator))
cnt++;
if (i <= 2 && j <= 1 && Mutare_Posibila(i, j, i, j + 1, i, j + 2, i + 1, j + 2, jucator))
cnt++;
if (i >= 1 && j <= 1 && Mutare_Posibila(i, j, i, j + 1, i, j + 2, i - 1, j + 2, jucator))
cnt++;
if (i <= 1 && j <= 2 && Mutare_Posibila(i, j, i + 1, j, i + 2, j, i + 2, j + 1, jucator))
cnt++;
if (i <= 1 && j >= 1 && Mutare_Posibila(i, j, i + 1, j, i + 2, j, i + 2, j - 1, jucator))
cnt++;
if (i <= 2 && j >= 2 && Mutare_Posibila(i, j, i, j - 1, i, j - 2, i + 1, j - 2, jucator))
cnt++;
if (i >= 1 && j >= 2 && Mutare_Posibila(i, j, i, j - 1, i, j - 2, i - 1, j - 2, jucator))
cnt++;
if (i <= 1 && j <= 2 && Mutare_Posibila(i, j, i, j + 1, i + 1, j + 1, i + 2, j + 1, jucator))
cnt++;
if (i >= 2 && j <= 2 && Mutare_Posibila(i, j, i, j + 1, i - 1, j + 1, i - 2, j + 1, jucator))
cnt++;
if (i <= 2 && j <= 1 && Mutare_Posibila(i, j, i + 1, j, i + 1, j + 1, i + 1, j + 2, jucator))
cnt++;
if (i <= 2 && j >= 2 && Mutare_Posibila(i, j, i + 1, j, i + 1, j - 1, i + 1, j - 2, jucator))
cnt++;
if (i <= 1 && j >= 1 && Mutare_Posibila(i, j, i, j - 1, i + 1, j - 1, i + 2, j - 1, jucator))
cnt++;
if (i >= 2 && j >= 1 && Mutare_Posibila(i, j, i, j - 1, i - 1, j - 1, i - 2, j - 1, jucator))
cnt++;
if (i >= 1 && j <= 1 && Mutare_Posibila(i, j, i - 1, j, i - 1, j + 1, i - 1, j + 2, jucator))
cnt++;
if (i >= 1 && j >= 2 && Mutare_Posibila(i, j, i - 1, j, i - 1, j - 1, i - 1, j - 2, jucator))
cnt++;
 }
if (cnt / 2 > 1)
return 1;
return 0;
}
void mutare(int jucator, optiuneL vectorL[])
{
int cul1, cul2;
for (int k = 0; k < 3; k++)
if (vectorL[k].pozitie)
 {
cul1 = vectorL[k].l1;
cul2 = vectorL[k].l2;
 }
for (int i = 0; i < 4; i++)
for (int j = 0; j < 4; j++)
if (Tabla[i][j].val == jucator || Tabla[i][j].gri == 1)
 {
setfillstyle(SOLID_FILL, BLACK);
floodfill(Tabla[i][j].x, Tabla[i][j].y, WHITE);
Tabla[i][j].val = 0;
 }
for (int i = 0; i < 4; i++)
for (int j = 0; j < 4; j++)
if (Tabla[i][j].gri == 1)
 {
if (jucator == 1)
 {
setfillstyle(SOLID_FILL, cul1);
floodfill(Tabla[i][j].x, Tabla[i][j].y, WHITE);
 }
else if (jucator == 2)
 {
setfillstyle(SOLID_FILL, cul2);
floodfill(Tabla[i][j].x, Tabla[i][j].y, WHITE);
 }
Tabla[i][j].gri = 0;
Tabla[i][j].val = jucator;
 }
}
int v[16] = {3, 1, 1, 0, 0, 2, 1, 0, 0, 2, 1, 0, 0, 2, 2, 3};
void Matriceinit()
{
int k = 0;
int a, b = 250;
for (int i = 0; i < 4; ++i)
 {
a = 250;
for (int j = 0; j < 4; ++j)
 {
Tabla[i][j].val = v[k++];
Tabla[i][j].x = a;
Tabla[i][j].y = b;
a += 100;
 }
b += 100;
 }
}
void umplePatratelul(int i, int j, optiuneCerc vectorcerc[], optiuneL vectorL[])
{
if (Tabla[i][j].val == 3)
 {
if (Tabla[i][j].gri)
 {
Tabla[i][j].val = 0;
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(Tabla[i][j].x, Tabla[i][j].y, WHITE);
 }
else
{
for (int k = 0; k < 3; k++)
if (vectorcerc[k].pozitie == 1)
 {
setfillstyle(SOLID_FILL, BLACK);
floodfill(Tabla[i][j].x, Tabla[i][j].y, WHITE);
circle(Tabla[i][j].x, Tabla[i][j].y, 49);
setfillstyle(SOLID_FILL, vectorcerc[k].culoare);
floodfill(Tabla[i][j].x, Tabla[i][j].y, WHITE);
 }
 }
 }
else if (Tabla[i][j].val == 2)
 {
for (int k = 0; k < 3; k++)
if (vectorL[k].pozitie)
 {
setfillstyle(SOLID_FILL, vectorL[k].l2);
floodfill(Tabla[i][j].x, Tabla[i][j].y, WHITE);
 }
 }
else if (Tabla[i][j].val == 1)
 {
for (int k = 0; k < 3; k++)
if (vectorL[k].pozitie)
 {
setfillstyle(SOLID_FILL, vectorL[k].l1);
floodfill(Tabla[i][j].x, Tabla[i][j].y, WHITE);
 }
 }
else if (Tabla[i][j].val == 0)
 {
setcolor(BLACK);
circle(Tabla[i][j].x, Tabla[i][j].y, 49);
setfillstyle(SOLID_FILL, BLACK);
floodfill(Tabla[i][j].x, Tabla[i][j].y, WHITE);
setcolor(WHITE);
 }
}
void Revino(optiuneCerc vectorcerc[], optiuneL vectorL[])
{
for (int i = 0; i < 4; i++)
for (int j = 0; j < 4; j++)
if (Tabla[i][j].gri)
 {
Tabla[i][j].gri = 0;
umplePatratelul(i, j, vectorcerc, vectorL);
 }
}
void afisareTablaDeJoc()
{
Matriceinit();
setcolor(WHITE);
rectangle(leftt, topp, rightt, bottomm);
int numar = 4;
int x = 300;
for (int i = 1; i < numar; i++, x += 100)
 {
line(200, x, 600, x);
line(x, 200, x, 600);
 }
}
void desen(int bk, optiuneCerc vectorcerc[], optiuneL vectorL[])
{
Matriceinit();
for (int i = 0; i < 4; i++)
for (int j = 0; j < 4; j++)
umplePatratelul(i, j, vectorcerc, vectorL);
}
void mutacerc(int bk, optiuneCerc vectorcerc[], optiuneL vectorL[])
{
int mX, mY, l, c;
int i, j;
bool ok = false;
do
{
if (ismouseclick(WM_LBUTTONDOWN))
 {
mX = mousex();
c = (mX - leftt) / 100;
mY = mousey();
l = (mY - topp) / 100;
clearmouseclick(WM_LBUTTONDOWN);
if (((c < 4 && c >= 0 && mX - leftt >= 0) && (l < 4 && l >= 0 && mY - topp >= 0)))
if (Tabla[l][c].val == 3)
 {
Tabla[l][c].gri = 1;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[l][c].val = 0;
i = l, j = c;
ok = true;
 }
 }
 } while (!ok);
do
{
if (ismouseclick(WM_LBUTTONDOWN))
 {
mX = mousex();
c = (mX - leftt) / 100;
mY = mousey();
l = (mY - topp) / 100;
clearmouseclick(WM_LBUTTONDOWN);
if (((c < 4 && c >= 0 && mX - leftt >= 0) && (l < 4 && l >= 0 && mY - topp >= 0)))
if (Tabla[l][c].val == 0)
 {
Tabla[l][c].val = 3;
Tabla[i][j].gri = 0;
umplePatratelul(i, j, vectorcerc, vectorL);
umplePatratelul(l, c, vectorcerc, vectorL);
ok = false;
 }
 }
 } while (ok);
}
int EsteL(int lin[], int col[])
{
int cnt = 0;
for (int i = 0; i < 3; ++i)
 {
if ((abs(lin[i] - lin[i + 1] > 1)) || (abs(col[i] - col[i + 1] > 1)))
return 0;
if (Tabla[lin[i]][col[i]].val == Tabla[lin[i + 1]][col[i + 1]].val && Tabla[lin[i]][col[i]].val != 0)
cnt++;
 }
if (cnt == 3)
return 2;
if ((lin[2] == lin[0] && col[2] == col[3]) || (lin[2] == lin[3] && col[2] == col[0]) || (lin[1] == lin[0] &&
col[1] == col[3]) || (lin[1] == lin[3] && col[1] == col[0]))
if ((abs(lin[0] - lin[3]) == 1 && abs(col[0] - col[3]) == 2) || (abs(lin[0] - lin[3]) == 2 && abs(col[0] -
col[3]) ==
1))
return 1;
return 0;
}
int selecteazapiesa(int jucator, int bk, optiuneCerc vectorcerc[], optiuneL vectorL[])
{
bool prima_mutare = 0;
int lin[4], col[4];
int mX, mY, pmX, pmY;
int cnt = 0, linia, coloana, plinia, pcoloana;
do
{
if (ismouseclick(WM_LBUTTONDOWN))
 {
mX = mousex();
coloana = (mX - leftt) / 100;
mY = mousey();
linia = (mY - topp) / 100;
clearmouseclick(WM_LBUTTONDOWN);
if (linia < 4 && linia >= 0 && mY - topp >= 0 && Tabla[linia][coloana].gri == 0)
if ((coloana < 4 && coloana >= 0 && mX - leftt >= 0))
if (((abs(coloana - pcoloana) == 1 && abs(linia - plinia) == 0) || (abs(coloana - pcoloana) == 0 &&
abs(linia -
plinia) ==
1)) ||
prima_mutare == 0)
 {
if (Tabla[linia][coloana].val == 3 - jucator)
 {
Revino(vectorcerc, vectorL);
return 2;
 }
else if (Tabla[linia][coloana].val == 3)
 {
Revino(vectorcerc, vectorL);
return 3;
 }
else if (!Tabla[linia][coloana].gri)
 {
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(mX, mY, WHITE);
Tabla[linia][coloana].gri = 1;
lin[cnt] = linia;
col[cnt] = coloana;
cnt++;
prima_mutare = 1;
 }
pmX = mX, pmY = mY;
plinia = linia, pcoloana = coloana;
 }
 }
 } while (cnt != 4);
int L = EsteL(lin, col);
if (L == 1)
 {
mutare(jucator, vectorL);
return 0;
 }
else if (L == 2)
 {
Revino(vectorcerc, vectorL);
return 4;
 }
else if (L == 0)
 {
Revino(vectorcerc, vectorL);
return 1;
 }
}
void modJocPvP(int L1, int L2, int bk, int vectorbk[], optiuneCerc vectorcerc[], optiuneL vectorL[])
{
initwindow(800, 800);
setbkcolor(bk);
cleardevice();
afisareTablaDeJoc();
desen(bk, vectorcerc, vectorL);
int eroare1, eroare2, jucator1 = 1, jucator2 = 2;
int castiga = 0;
bool gata = End_game(jucator1);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
int cul, cul1, cul2;
for (int k = 0; k < 3; k++)
if (vectorcerc[k].pozitie)
cul = vectorcerc[k].culoare;
for (int k = 0; k < 3; k++)
if (vectorL[k].pozitie)
 {
cul1 = vectorL[k].l1;
cul2 = vectorL[k].l2;
 }
while (gata)
 {
if (gata)
 {
do
{
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
setcolor(bk);
outtextxy(218, 75, "Move one circle!");
outtextxy(230, 75, "Player2's turn");
setcolor(cul1);
outtextxy(230, 75, "Player1's turn");
setcolor(WHITE);
eroare1 = selecteazapiesa(jucator1, bk, vectorcerc, vectorL);
if (!eroare1)
 {
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(cul);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
outtextxy(218, 75, "Move one circle!");
setcolor(WHITE);
mutacerc(bk, vectorcerc, vectorL);
 }
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(LIGHTGRAY);
switch (eroare1)
 {
case 1:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(225, 125, "It's not an 'L'.Try again!");
break;
case 2:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(100, 125, "You put over the opponent's piece.Try again!");
break;
case 3:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(165, 125, "You put over the circle.Try again!");
break;
case 4:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(80, 125, "You can't move on the same position.Try again!");
break;
 }
setcolor(WHITE);
gata = End_game(jucator2);
if (gata == 0)
eroare1 = 0, castiga = 1;
 } while (eroare1);
 }
if (gata)
 {
do
{
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
setcolor(bk);
outtextxy(218, 75, "Move one circle!");
outtextxy(230, 75, "Player1's turn");
setcolor(cul2);
outtextxy(230, 75, "Player2's turn");
setcolor(WHITE);
eroare2 = selecteazapiesa(jucator2, bk, vectorcerc, vectorL);
if (!eroare2)
 {
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
setcolor(cul);
outtextxy(218, 75, "Move one circle!");
setcolor(WHITE);
mutacerc(bk, vectorcerc, vectorL);
 }
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(LIGHTGRAY);
switch (eroare2)
 {
case 1:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(225, 125, "It's not an 'L'.Try again!");
break;
case 2:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(100, 125, "You put over the opponent's piece.Try again!");
break;
case 3:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(165, 125, "You put over the circle.Try again!");
break;
case 4:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(80, 125, "You can't move on the same position.Try again!");
break;
 }
gata = End_game(jucator1);
if (gata == 0)
eroare2 = 0, castiga = 2;
 } while (eroare2);
 }
 }
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
if (castiga == 2)
 {
setcolor(bk);
outtextxy(218, 75, "Move one circle!");
L2++;
if (L2 != 5)
 {
setcolor(cul2);
outtextxy(160, 75, "Player2 won the game!");
 }
 }
else
{
setcolor(bk);
outtextxy(218, 75, "Move one circle!");
L1++;
if (L1 != 5)
 {
setcolor(cul1);
outtextxy(160, 75, "Player1 won the game!");
 }
 }
settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
char s[2] = " ", t;
t = char(L1 + 48);
s[0] = t;
setcolor(cul1);
outtextxy(335, 125, s);
setcolor(LIGHTGRAY);
outtextxy(385, 125, "-");
t = char(L2 + 48);
s[0] = t;
setcolor(cul2);
outtextxy(430, 125, s);
if (L1 < 5 && L2 < 5)
 {
setcolor(WHITE);
rectangle(249, 650, 350, 700);
setfillstyle(SOLID_FILL, BLACK);
floodfill(250, 651, WHITE);
setcolor(LIGHTCYAN);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setbkcolor(0);
outtextxy(251, 667, "REMATCH");
setcolor(WHITE);
rectangle(449, 650, 550, 700);
setfillstyle(SOLID_FILL, BLACK);
floodfill(450, 651, WHITE);
setcolor(LIGHTCYAN);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
outtextxy(472, 667, "MENU");
bool ok = false;
do
{
if (ismouseclick(WM_LBUTTONDOWN))
 {
int mx = mousex();
int my = mousey();
clearmouseclick(WM_LBUTTONDOWN);
if ((my > 650 && my < 700))
 {
if ((mx > 249 && mx < 350))
 {
closegraph();
modJocPvP(L1, L2, bk, vectorbk, vectorcerc, vectorL);
 }
else if (mx > 449 && mx < 550)
 {
closegraph();
meniu(bk, vectorbk, vectorcerc, vectorL);
 }
ok = true;
 }
 }
 } while (!ok);
 }
else
{
setcolor(WHITE);
rectangle(352, 650, 453, 700);
setfillstyle(SOLID_FILL, BLACK);
floodfill(450, 651, WHITE);
setbkcolor(0);
setcolor(LIGHTCYAN);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
outtextxy(375, 667, "MENU");
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
setbkcolor(bk);
setcolor(LIGHTGRAY);
outtextxy(290, 75, "Game over!");
bool ok = false;
do
{
if (ismouseclick(WM_LBUTTONDOWN))
 {
int mx = mousex();
int my = mousey();
clearmouseclick(WM_LBUTTONDOWN);
if ((my > 650 && my < 700) && (mx > 352 && mx < 453))
 {
closegraph();
meniu(bk, vectorbk, vectorcerc, vectorL);
 }
ok = true;
 }
 } while (!ok);
 }
}
bool NuECerc(int lin1, int col1, int lin2, int col2, int lin3, int col3, int lin4, int col4)
{
if (Tabla[lin1][col1].val != 3 && Tabla[lin2][col2].val != 3 && Tabla[lin3][col3].val != 3 &&
Tabla[lin4][col4].val != 3)
return 1;
return 0;
}
bool Pattern_gasit(int jucator)
{
if (Tabla[1][0].val == 1 && Tabla[2][0].val == 1 && Tabla[3][0].val == 1 && Tabla[3][1].val == 1 && !DejaPus(1
, 1, 1, 2, 2, 2, 3, 2, jucator) && NuECerc(1, 1, 1, 2, 2, 2, 3, 2))
 {
// cout << "caz1";
if (Tabla[0][0].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][2].val = 3;
umplePatratelul(0, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][2].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][0].val = 3;
umplePatratelul(0, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][0].val == 1 && Tabla[0][0].val == 1 && Tabla[0][1].val == 1 && Tabla[0][2].val == 1 && !DejaPus(2
, 0, 2, 1, 2, 2, 1, 2, jucator) && NuECerc(2, 0, 2, 1, 2, 2, 1, 2))
 {
// cout << "caz2";
if (Tabla[0][3].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][3].val = 3;
umplePatratelul(2, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[2][3].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][3].val = 3;
umplePatratelul(0, 3, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][2].val == 1 && Tabla[0][3].val == 1 && Tabla[1][3].val == 1 && Tabla[2][3].val == 1 && !DejaPus(0
, 1, 1, 1, 2, 1, 2, 2, jucator) && NuECerc(0, 1, 1, 1, 2, 1, 2, 2))
 {
// cout << "caz3";
if (Tabla[3][1].val == 3)
 {
Tabla[0][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][3].val = 3;
umplePatratelul(3, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][3].val == 3)
 {
Tabla[0][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][1].val = 3;
umplePatratelul(3, 1, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][3].val == 1 && Tabla[3][3].val == 1 && Tabla[3][2].val == 1 && Tabla[3][1].val == 1 && !DejaPus(2
, 1, 1, 1, 1, 2, 1, 3, jucator) && NuECerc(2, 1, 1, 1, 1, 2, 1, 3))
 {
// cout << "caz4";
if (Tabla[3][0].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][0].val = 3;
umplePatratelul(1, 0, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[1][0].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][1].val = 3;
umplePatratelul(3, 1, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][0].val == 1 && Tabla[2][0].val == 1 && Tabla[3][0].val == 1 && Tabla[3][1].val == 1 && !DejaPus(1
, 1, 1, 2, 2, 2, 3, 2, jucator) && NuECerc(1, 1, 1, 2, 2, 2, 3, 2))
 {
// cout << "caz5";
if (Tabla[0][0].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][3].val = 3;
umplePatratelul(0, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][3].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][0].val = 3;
umplePatratelul(0, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][0].val == 1 && Tabla[0][0].val == 1 && Tabla[0][1].val == 1 && Tabla[0][2].val == 1 && !DejaPus(2
, 0, 2, 1, 2, 2, 1, 2, jucator) && NuECerc(2, 0, 2, 1, 2, 2, 1, 2))
 {
// cout << "caz6";
if (Tabla[0][3].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][3].val = 3;
umplePatratelul(3, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][3].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][3].val = 3;
umplePatratelul(0, 3, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][2].val == 1 && Tabla[0][3].val == 1 && Tabla[1][3].val == 1 && Tabla[2][3].val == 1 && !DejaPus(0
, 1, 1, 1, 2, 1, 2, 2, jucator) && NuECerc(0, 1, 1, 1, 2, 1, 2, 2))
 {
// cout << "caz7";
if (Tabla[3][3].val == 3)
 {
Tabla[0][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][0].val = 3;
umplePatratelul(3, 0, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][0].val == 3)
 {
Tabla[0][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][3].val = 3;
umplePatratelul(3, 3, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][3].val == 1 && Tabla[3][3].val == 1 && Tabla[3][2].val == 1 && Tabla[3][1].val == 1 && !DejaPus(2
, 1, 1, 1, 1, 2, 1, 3, jucator) && NuECerc(2, 1, 1, 1, 1, 2, 1, 3))
 {
// cout << "caz8";
if (Tabla[3][0].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][0].val = 3;
umplePatratelul(0, 0, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][0].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][0].val = 3;
umplePatratelul(3, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][0].val == 1 && Tabla[2][0].val == 1 && Tabla[3][0].val == 1 && Tabla[3][1].val == 1 && !DejaPus(1
, 1, 1, 2, 2, 2, 3, 2, jucator) && NuECerc(1, 1, 1, 2, 2, 2, 3, 2))
 {
// cout << "caz9";
if (Tabla[0][0].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][3].val = 3;
umplePatratelul(1, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[1][3].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][0].val = 3;
umplePatratelul(0, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][0].val == 1 && Tabla[0][0].val == 1 && Tabla[0][1].val == 1 && Tabla[0][2].val == 1 && !DejaPus(2
, 0, 2, 1, 2, 2, 1, 2, jucator) && NuECerc(2, 0, 2, 1, 2, 2, 1, 2))
 {
// cout << "caz10";
if (Tabla[0][3].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][2].val = 3;
umplePatratelul(3, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][2].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][3].val = 3;
umplePatratelul(0, 3, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][2].val == 1 && Tabla[0][3].val == 1 && Tabla[1][3].val == 1 && Tabla[2][3].val == 1 && !DejaPus(0
, 1, 1, 1, 2, 1, 2, 2, jucator) && NuECerc(0, 1, 1, 1, 2, 1, 2, 2))
 {
// cout << "caz11";
if (Tabla[3][3].val == 3)
 {
Tabla[0][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][0].val = 3;
umplePatratelul(2, 0, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[2][0].val == 3)
 {
Tabla[0][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][3].val = 3;
umplePatratelul(3, 3, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][3].val == 1 && Tabla[3][3].val == 1 && Tabla[3][2].val == 1 && Tabla[3][1].val == 1 && !DejaPus(2
, 1, 1, 1, 1, 2, 1, 3, jucator) && NuECerc(2, 1, 1, 1, 1, 2, 1, 3))
 {
// cout << "caz12";
if (Tabla[3][0].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][1].val = 3;
umplePatratelul(0, 1, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][1].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][0].val = 3;
umplePatratelul(3, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][0].val == 1 && Tabla[2][0].val == 1 && Tabla[3][0].val == 1 && Tabla[3][1].val == 1 && !DejaPus(2
, 1, 1, 1, 1, 2, 1, 3, jucator) && NuECerc(2, 1, 1, 1, 1, 2, 1, 3))
 {
// cout << "caz13";
if (Tabla[0][0].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][2].val = 3;
umplePatratelul(3, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][2].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][0].val = 3;
umplePatratelul(0, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][0].val == 1 && Tabla[0][0].val == 1 && Tabla[0][1].val == 1 && Tabla[0][2].val == 1 && !DejaPus(1
, 1, 1, 2, 2, 2, 3, 2, jucator) && NuECerc(1, 1, 1, 2, 2, 2, 3, 2))
 {
// cout << "caz14";
if (Tabla[0][3].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][0].val = 3;
umplePatratelul(2, 0, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[2][0].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][3].val = 3;
umplePatratelul(0, 3, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][2].val == 1 && Tabla[0][3].val == 1 && Tabla[1][3].val == 1 && Tabla[2][3].val == 1 && !DejaPus(1
, 2, 2, 2, 2, 1, 2, 0, jucator) && NuECerc(1, 2, 2, 2, 2, 1, 2, 0))
 {
// cout << "caz15";
if (Tabla[3][3].val == 3)
 {
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][0].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][1].val = 3;
umplePatratelul(0, 1, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][1].val == 3)
 {
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][0].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
Tabla[3][3].val = 3;
umplePatratelul(l, c, vectorcerc, vectorL);
umplePatratelul(3, 3, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][3].val == 1 && Tabla[3][3].val == 1 && Tabla[3][2].val == 1 && Tabla[3][1].val == 1 && !DejaPus(2
, 2, 2, 1, 1, 1, 0, 1, jucator) && NuECerc(2, 2, 2, 1, 1, 1, 0, 1))
 {
// cout << "caz16";
if (Tabla[3][0].val == 3)
 {
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[0][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][3].val = 3;
umplePatratelul(1, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[1][3].val == 3)
 {
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[0][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][0].val = 3;
umplePatratelul(3, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][0].val == 1 && Tabla[2][0].val == 1 && Tabla[3][0].val == 1 && Tabla[3][1].val == 1 && !DejaPus(2
, 1, 1, 1, 1, 2, 1, 3, jucator) && NuECerc(2, 1, 1, 1, 1, 2, 1, 3))
 {
// cout << "caz17";
if (Tabla[0][1].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][2].val = 3;
umplePatratelul(3, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][2].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][1].val = 3;
umplePatratelul(0, 1, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][0].val == 1 && Tabla[0][0].val == 1 && Tabla[0][1].val == 1 && Tabla[0][2].val == 1 && !DejaPus(1
, 1, 1, 2, 2, 2, 3, 2, jucator) && NuECerc(1, 1, 1, 2, 2, 2, 3, 2))
 {
// cout << "caz18";
if (Tabla[1][3].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][0].val = 3;
umplePatratelul(2, 0, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[2][0].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][3].val = 3;
umplePatratelul(1, 3, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][2].val == 1 && Tabla[0][3].val == 1 && Tabla[1][3].val == 1 && Tabla[2][3].val == 1 && !DejaPus(1
, 2, 2, 2, 2, 1, 2, 0, jucator) && NuECerc(1, 2, 2, 2, 2, 1, 2, 0))
 {
// cout << "caz19";
if (Tabla[3][2].val == 3)
 {
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][0].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][1].val = 3;
umplePatratelul(0, 1, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][1].val == 3)
 {
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][0].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
Tabla[3][2].val = 3;
umplePatratelul(l, c, vectorcerc, vectorL);
umplePatratelul(3, 2, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][3].val == 1 && Tabla[3][3].val == 1 && Tabla[3][2].val == 1 && Tabla[3][1].val == 1 && !DejaPus(2
, 2, 2, 1, 1, 1, 0, 1, jucator) && NuECerc(2, 2, 2, 1, 1, 1, 0, 1))
 {
// cout << "caz20";
if (Tabla[2][0].val == 3)
 {
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[0][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][3].val = 3;
umplePatratelul(1, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[1][3].val == 3)
 {
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[0][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][0].val = 3;
umplePatratelul(2, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][0].val == 1 && Tabla[2][0].val == 1 && Tabla[3][0].val == 1 && Tabla[3][1].val == 1 && !DejaPus(2
, 2, 2, 1, 1, 1, 0, 1, jucator) && NuECerc(2, 2, 2, 1, 1, 1, 0, 1))
 {
// cout << "caz21";
if (Tabla[3][2].val == 3)
 {
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[0][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][3].val = 3;
umplePatratelul(2, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[2][3].val == 3)
 {
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[0][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][2].val = 3;
umplePatratelul(3, 2, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][0].val == 1 && Tabla[0][0].val == 1 && Tabla[0][1].val == 1 && Tabla[0][2].val == 1 && !DejaPus(2
, 1, 1, 1, 1, 2, 1, 3, jucator) && NuECerc(2, 1, 1, 1, 1, 2, 1, 3))
 {
// cout << "caz22";
if (Tabla[2][0].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][1].val = 3;
umplePatratelul(3, 1, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][1].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][0].val = 3;
umplePatratelul(2, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][2].val == 1 && Tabla[0][3].val == 1 && Tabla[1][3].val == 1 && Tabla[2][3].val == 1 && !DejaPus(1
, 1, 1, 2, 2, 2, 3, 2, jucator) && NuECerc(1, 1, 1, 2, 2, 2, 3, 2))
 {
// cout << "caz23";
if (Tabla[1][0].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][1].val = 3;
umplePatratelul(0, 1, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][1].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][0].val = 3;
umplePatratelul(1, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][3].val == 1 && Tabla[3][3].val == 1 && Tabla[3][2].val == 1 && Tabla[3][1].val == 1 && !DejaPus(2
, 0, 2, 1, 2, 2, 1, 2, jucator) && NuECerc(2, 0, 2, 1, 2, 2, 1, 2))
 {
// cout << "caz24";
if (Tabla[0][2].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][3].val = 3;
umplePatratelul(1, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[1][3].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][2].val = 3;
umplePatratelul(0, 2, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][0].val == 1 && Tabla[2][0].val == 1 && Tabla[3][0].val == 1 && Tabla[3][1].val == 1 && !DejaPus(2
, 2, 2, 1, 1, 1, 0, 1, jucator) && NuECerc(2, 2, 2, 1, 1, 1, 0, 1))
 {
// cout << "caz25";
if (Tabla[3][2].val == 3)
 {
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[0][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][3].val = 3;
umplePatratelul(1, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[1][3].val == 3)
 {
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[0][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][2].val = 3;
umplePatratelul(3, 2, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][0].val == 1 && Tabla[0][0].val == 1 && Tabla[0][1].val == 1 && Tabla[0][2].val == 1 && !DejaPus(2
, 1, 1, 1, 1, 2, 1, 3, jucator) && NuECerc(2, 1, 1, 1, 1, 2, 1, 3))
 {
// cout << "caz26";
if (Tabla[2][0].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][2].val = 3;
umplePatratelul(3, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][2].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][0].val = 3;
umplePatratelul(2, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][2].val == 1 && Tabla[0][3].val == 1 && Tabla[1][3].val == 1 && Tabla[2][3].val == 1 && !DejaPus(1
, 1, 1, 2, 2, 2, 3, 2, jucator) && NuECerc(1, 1, 1, 2, 2, 2, 3, 2))
 {
// cout << "caz27";
if (Tabla[2][0].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][1].val = 3;
umplePatratelul(0, 1, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][1].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][0].val = 3;
umplePatratelul(2, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][3].val == 1 && Tabla[3][3].val == 1 && Tabla[3][2].val == 1 && Tabla[3][1].val == 1 && !DejaPus(2
, 0, 2, 1, 2, 2, 1, 2, jucator) && NuECerc(2, 0, 2, 1, 2, 2, 1, 2))
 {
// cout << "caz28";
if (Tabla[0][1].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][3].val = 3;
umplePatratelul(1, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[1][3].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][1].val = 3;
umplePatratelul(0, 1, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][3].val == 1 && Tabla[2][3].val == 1 && Tabla[3][3].val == 1 && Tabla[3][2].val == 1 && !DejaPus(2
, 2, 1, 2, 0, 2, 0, 1, jucator) && NuECerc(2, 2, 1, 2, 0, 2, 0, 1))
 {
// cout << "caz29";
if (Tabla[3][1].val == 3)
 {
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[0][2].gri = 1;
Tabla[0][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][0].val = 3;
umplePatratelul(1, 0, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[1][0].val == 3)
 {
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[0][2].gri = 1;
Tabla[0][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][1].val = 3;
umplePatratelul(3, 1, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][0].val == 1 && Tabla[3][0].val == 1 && Tabla[3][1].val == 1 && Tabla[3][2].val == 1 && !DejaPus(2
, 1, 2, 2, 2, 3, 1, 3, jucator) && NuECerc(2, 1, 2, 2, 2, 3, 1, 3))
 {
// cout << "caz30";
if (Tabla[1][0].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][2].val = 3;
umplePatratelul(0, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][2].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][0].val = 3;
umplePatratelul(1, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][0].val == 1 && Tabla[1][0].val == 1 && Tabla[0][0].val == 1 && Tabla[0][1].val == 1 && !DejaPus(1
, 1, 2, 1, 3, 1, 3, 2, jucator) && NuECerc(1, 1, 2, 1, 3, 1, 3, 2))
 {
// cout << "caz31";
if (Tabla[2][3].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[3][1].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][2].val = 3;
umplePatratelul(0, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][2].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[3][1].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][3].val = 3;
umplePatratelul(2, 3, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][1].val == 1 && Tabla[0][2].val == 1 && Tabla[0][3].val == 1 && Tabla[1][3].val == 1 && !DejaPus(2
, 0, 1, 0, 1, 1, 1, 2, jucator) && NuECerc(2, 0, 1, 0, 1, 1, 1, 2))
 {
// cout << "caz32";
if (Tabla[3][1].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][3].val = 3;
umplePatratelul(2, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[2][3].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][1].val = 3;
umplePatratelul(3, 1, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][3].val == 1 && Tabla[2][3].val == 1 && Tabla[3][3].val == 1 && Tabla[3][2].val == 1 && !DejaPus(2
, 2, 1, 2, 0, 2, 0, 1, jucator) && NuECerc(2, 2, 1, 2, 0, 2, 0, 1))
 {
// cout << "caz33";
if (Tabla[3][1].val == 3)
 {
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[0][2].gri = 1;
Tabla[0][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][0].val = 3;
umplePatratelul(2, 0, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[2][0].val == 3)
 {
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[0][2].gri = 1;
Tabla[0][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][1].val = 3;
umplePatratelul(3, 1, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][0].val == 1 && Tabla[3][0].val == 1 && Tabla[3][1].val == 1 && Tabla[3][2].val == 1 && !DejaPus(2
, 1, 2, 2, 2, 3, 1, 3, jucator) && NuECerc(2, 1, 2, 2, 2, 3, 1, 3))
 {
// cout << "caz34";
if (Tabla[1][0].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][1].val = 3;
umplePatratelul(0, 1, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][1].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][0].val = 3;
umplePatratelul(1, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][0].val == 1 && Tabla[1][0].val == 1 && Tabla[0][0].val == 1 && Tabla[0][1].val == 1 && !DejaPus(1
, 1, 2, 1, 3, 1, 3, 2, jucator) && NuECerc(1, 1, 2, 1, 3, 1, 3, 2))
 {
// cout << "caz35";
if (Tabla[1][3].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[3][1].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][2].val = 3;
umplePatratelul(0, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][2].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[3][1].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][3].val = 3;
umplePatratelul(1, 3, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][1].val == 1 && Tabla[0][2].val == 1 && Tabla[0][3].val == 1 && Tabla[1][3].val == 1 && !DejaPus(2
, 0, 1, 0, 1, 1, 1, 2, jucator) && NuECerc(2, 0, 1, 0, 1, 1, 1, 2))
 {
// cout << "caz36";
if (Tabla[3][2].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][3].val = 3;
umplePatratelul(2, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[2][3].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][2].val = 3;
umplePatratelul(3, 2, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[3][2].val == 1 && Tabla[3][3].val == 1 && Tabla[2][3].val == 1 && Tabla[1][3].val == 1 && !DejaPus(2
, 0, 2, 1, 2, 2, 1, 2, jucator) && NuECerc(2, 0, 2, 1, 2, 2, 1, 2))
 {
// cout << "caz37";
if (Tabla[3][1].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][2].val = 3;
umplePatratelul(0, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][2].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][1].val = 3;
umplePatratelul(3, 1, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][0].val == 1 && Tabla[3][0].val == 1 && Tabla[3][1].val == 1 && Tabla[3][2].val == 1 && !DejaPus(0
, 1, 1, 1, 2, 1, 2, 2, jucator) && NuECerc(0, 1, 1, 1, 2, 1, 2, 2))
 {
// cout << "caz38";
if (Tabla[1][0].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[3][0].gri = 1;
Tabla[3][1].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][3].val = 3;
umplePatratelul(2, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[2][3].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[3][0].gri = 1;
Tabla[3][1].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][0].val = 3;
umplePatratelul(1, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][0].val == 1 && Tabla[1][0].val == 1 && Tabla[0][0].val == 1 && Tabla[0][1].val == 1 && !DejaPus(2
, 1, 1, 1, 1, 2, 1, 3, jucator) && NuECerc(2, 1, 1, 1, 1, 2, 1, 3))
 {
// cout << "caz39";
if (Tabla[0][2].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][1].val = 3;
umplePatratelul(3, 1, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][1].val == 3)
 {
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][2].val = 3;
umplePatratelul(0, 2, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][1].val == 1 && Tabla[0][2].val == 1 && Tabla[0][3].val == 1 && Tabla[1][3].val == 1 && !DejaPus(1
, 1, 1, 2, 2, 2, 3, 2, jucator) && NuECerc(1, 1, 1, 2, 2, 2, 3, 2))
 {
// cout << "caz40";
if (Tabla[2][3].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][0].val = 3;
umplePatratelul(1, 0, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[1][0].val == 3)
 {
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[3][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][3].val = 3;
umplePatratelul(2, 3, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][3].val == 1 && Tabla[2][3].val == 1 && Tabla[3][3].val == 1 && Tabla[3][2].val == 1 && !DejaPus(1
, 0, 1, 1, 1, 2, 0, 2, jucator) && NuECerc(1, 0, 1, 1, 1, 2, 0, 2))
 {
// cout << "caz41";
if (Tabla[2][2].val == 3)
 {
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[0][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][1].val = 3;
umplePatratelul(3, 1, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][1].val == 3)
 {
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[0][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][2].val = 3;
umplePatratelul(2, 2, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][0].val == 1 && Tabla[3][0].val == 1 && Tabla[3][1].val == 1 && Tabla[3][2].val == 1 && !DejaPus(0
, 2, 1, 2, 2, 2, 2, 3, jucator) && NuECerc(0, 2, 1, 2, 2, 2, 2, 3))
 {
// cout << "caz42";
if (Tabla[1][0].val == 3)
 {
Tabla[0][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][1].val = 3;
umplePatratelul(2, 1, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[2][1].val == 3)
 {
Tabla[0][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][0].val = 3;
umplePatratelul(1, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][0].val == 1 && Tabla[1][0].val == 1 && Tabla[0][0].val == 1 && Tabla[0][1].val == 1 && !DejaPus(3
, 1, 2, 1, 2, 2, 2, 3, jucator) && NuECerc(3, 1, 2, 1, 2, 2, 2, 3))
 {
// cout << "caz43";
if (Tabla[1][1].val == 3)
 {
Tabla[3][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][2].val = 3;
umplePatratelul(0, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][2].val == 3)
 {
Tabla[3][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][1].val = 3;
umplePatratelul(1, 1, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][1].val == 1 && Tabla[0][2].val == 1 && Tabla[0][3].val == 1 && Tabla[1][3].val == 1 && !DejaPus(1
, 0, 1, 1, 2, 1, 3, 1, jucator) && NuECerc(1, 0, 1, 1, 2, 1, 3, 1))
 {
// cout << "caz44";
if (Tabla[1][2].val == 3)
 {
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[3][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][3].val = 3;
umplePatratelul(2, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[2][3].val == 3)
 {
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[3][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][2].val = 3;
umplePatratelul(1, 2, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][3].val == 1 && Tabla[2][3].val == 1 && Tabla[3][3].val == 1 && Tabla[3][2].val == 1 && !DejaPus(1
, 0, 1, 1, 2, 1, 3, 1, jucator) && NuECerc(1, 0, 1, 1, 2, 1, 3, 1))
 {
// cout << "caz45";
if (Tabla[1][2].val == 3)
 {
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[3][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][3].val = 3;
umplePatratelul(0, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][3].val == 3)
 {
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[3][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][2].val = 3;
umplePatratelul(1, 2, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][0].val == 1 && Tabla[3][0].val == 1 && Tabla[3][1].val == 1 && Tabla[3][2].val == 1 && !DejaPus(1
,0,1,1,1,2,0,2, jucator) && NuECerc(1,0,1,1,1,2,0,2))
 {
// cout << "caz46";
if (Tabla[2][2].val == 3)
 {
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[0][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][3].val = 3;
umplePatratelul(3, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][3].val == 3)
 {
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
Tabla[0][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][2].val = 3;
umplePatratelul(2, 2, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][0].val == 1 && Tabla[1][0].val == 1 && Tabla[0][0].val == 1 && Tabla[0][1].val == 1 && !DejaPus(0
,2,1,2,2,2,2,3, jucator) && NuECerc(0,2,1,2,2,2,2,3))
 {
// cout << "caz47";
if (Tabla[3][0].val == 3)
 {
Tabla[0][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][1].val = 3;
umplePatratelul(2, 1, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[2][1].val == 3)
 {
Tabla[0][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][0].val = 3;
umplePatratelul(3, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][1].val == 1 && Tabla[0][2].val == 1 && Tabla[0][3].val == 1 && Tabla[1][3].val == 1 && !DejaPus(2
,3,2,2,2,1,3,1, jucator) && NuECerc(2,3,2,2,2,1,3,1))
 {
// cout << "caz48";
if (Tabla[0][0].val == 3)
 {
Tabla[2][3].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
Tabla[3][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][1].val = 3;
umplePatratelul(1, 1, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[1][1].val == 3)
 {
Tabla[2][3].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
Tabla[3][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][0].val = 3;
umplePatratelul(0, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[3][0].val == 1 && Tabla[3][1].val == 1 && Tabla[2][1].val == 1 && Tabla[1][1].val == 1 && !DejaPus(0
,1,0,2,1,2,2,2, jucator) && NuECerc(0,1,0,2,1,2,2,2))
 {
// cout << "caz49";
if (Tabla[1][0].val == 3)
 {
Tabla[0][1].gri = 1;
Tabla[0][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][2].val = 3;
umplePatratelul(3, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][2].val == 3)
 {
Tabla[0][1].gri = 1;
Tabla[0][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][0].val = 3;
umplePatratelul(1, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][0].val == 1 && Tabla[1][0].val == 1 && Tabla[1][1].val == 1 && Tabla[1][2].val == 1 && !DejaPus(1
,3,2,3,2,2,2,1, jucator) && NuECerc(1,3,2,3,2,2,2,1))
 {
// cout << "caz50";
if (Tabla[0][2].val == 3)
 {
Tabla[1][3].gri = 1;
Tabla[2][3].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][0].val = 3;
umplePatratelul(2, 0, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[2][0].val == 3)
 {
Tabla[1][3].gri = 1;
Tabla[2][3].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][2].val = 3;
umplePatratelul(0, 2, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][3].val == 1 && Tabla[0][2].val == 1 && Tabla[1][2].val == 1 && Tabla[2][2].val == 1 && !DejaPus(3
,2,3,1,2,1,1,1, jucator) && NuECerc(3,2,3,1,2,1,1,1))
 {
// cout << "caz51";
if (Tabla[0][1].val == 3)
 {
Tabla[3][2].gri = 1;
Tabla[3][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][3].val = 3;
umplePatratelul(2, 3, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[2][3].val == 3)
 {
Tabla[3][2].gri = 1;
Tabla[3][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[1][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][1].val = 3;
umplePatratelul(0, 1, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[3][3].val == 1 && Tabla[2][3].val == 1 && Tabla[2][2].val == 1 && Tabla[2][1].val == 1 && !DejaPus(2
,0,1,0,1,1,1,2, jucator) && NuECerc(2,0,1,0,1,1,1,2))
 {
// cout << "caz52";
if (Tabla[1][3].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][1].val = 3;
umplePatratelul(3, 1, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][1].val == 3)
 {
Tabla[2][0].gri = 1;
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][2].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][3].val = 3;
umplePatratelul(1, 3, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][3].val == 1 && Tabla[1][3].val == 1 && Tabla[2][3].val == 1 && Tabla[2][2].val == 1 && !DejaPus(0
,2,1,2,1,1,1,0, jucator) && NuECerc(0,2,1,2,1,1,1,0))
 {
// cout << "caz53";
if (Tabla[2][1].val == 3)
 {
Tabla[0][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][0].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][2].val = 3;
umplePatratelul(3, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][2].val == 3)
 {
Tabla[0][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][0].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][1].val = 3;
umplePatratelul(2, 1, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[2][1].val == 1 && Tabla[3][1].val == 1 && Tabla[3][2].val == 1 && Tabla[3][3].val == 1 && !DejaPus(0
,2,1,2,2,2,2,3, jucator) && NuECerc(0,2,1,2,2,2,2,3))
 {
// cout << "caz54";
if (Tabla[2][0].val == 3)
 {
Tabla[0][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][1].val = 3;
umplePatratelul(1, 1, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[1][1].val == 3)
 {
Tabla[0][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][0].val = 3;
umplePatratelul(2, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[3][0].val == 1 && Tabla[2][0].val == 1 && Tabla[1][0].val == 1 && Tabla[1][1].val == 1 && !DejaPus(3
,1,2,1,2,2,2,3, jucator) && NuECerc(3,1,2,1,2,2,2,3))
 {
// cout << "caz55";
if (Tabla[0][1].val == 3)
 {
Tabla[3][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][2].val = 3;
umplePatratelul(1, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[1][2].val == 3)
 {
Tabla[3][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][1].val = 3;
umplePatratelul(0, 1, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][0].val == 1 && Tabla[0][1].val == 1 && Tabla[0][2].val == 1 && Tabla[1][2].val == 1 && !DejaPus(1
,0,1,1,2,1,3,1, jucator) && NuECerc(1,0,1,1,2,1,3,1))
 {
// cout << "caz56";
if (Tabla[1][3].val == 3)
 {
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[3][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][2].val = 3;
umplePatratelul(2, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[2][2].val == 3)
 {
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[3][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][3].val = 3;
umplePatratelul(1, 3, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][2].val == 1 && Tabla[2][2].val == 1 && Tabla[3][2].val == 1 && Tabla[3][3].val == 1 && !DejaPus(1
,0,1,1,2,1,3,1, jucator) && NuECerc(1,0,1,1,2,1,3,1))
 {
// cout << "caz57";
if (Tabla[1][3].val == 3)
 {
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[3][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][2].val = 3;
umplePatratelul(0, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[0][2].val == 3)
 {
Tabla[1][0].gri = 1;
Tabla[1][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[3][1].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][3].val = 3;
umplePatratelul(1, 3, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[3][0].val == 1 && Tabla[2][0].val == 1 && Tabla[2][1].val == 1 && Tabla[2][2].val == 1 && !DejaPus(0
,2,1,2,1,1,1,0, jucator) && NuECerc(0,2,1,2,1,1,1,0))
 {
// cout << "caz58";
if (Tabla[2][3].val == 3)
 {
Tabla[0][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][0].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 3)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][2].val = 3;
umplePatratelul(3, 2, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][2].val == 3)
 {
Tabla[0][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[1][1].gri = 1;
Tabla[1][0].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 2)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][3].val = 3;
umplePatratelul(2, 3, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[0][0].val == 1 && Tabla[0][1].val == 1 && Tabla[1][1].val == 1 && Tabla[2][1].val == 1 && !DejaPus(0
,2,1,2,2,2,2,3, jucator) && NuECerc(0,2,1,2,2,2,2,3))
 {
// cout << "caz59";
if (Tabla[2][0].val == 3)
 {
Tabla[0][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 2 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[3][1].val = 3;
umplePatratelul(3, 1, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[3][1].val == 3)
 {
Tabla[0][2].gri = 1;
Tabla[1][2].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 3 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[2][0].val = 3;
umplePatratelul(2, 0, vectorcerc, vectorL);
return 1;
 }
 }
if (Tabla[1][1].val == 1 && Tabla[1][2].val == 1 && Tabla[1][3].val == 1 && Tabla[0][3].val == 1 && !DejaPus(3
,1,2,1,2,2,2,3, jucator) && NuECerc(3,1,2,1,2,2,2,3))
 {
// cout << "caz60";
if (Tabla[0][1].val == 3)
 {
Tabla[3][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 0 && j == 1)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[1][0].val = 3;
umplePatratelul(1, 0, vectorcerc, vectorL);
return 1;
 }
else if (Tabla[1][0].val == 3)
 {
Tabla[3][1].gri = 1;
Tabla[2][1].gri = 1;
Tabla[2][2].gri = 1;
Tabla[2][3].gri = 1;
mutare(jucator, vectorL);
int l, c;
for (int i = 0; i < 4; ++i)
for (int j = 0; j < 4; ++j)
if (i == 1 && j == 0)
continue;
else if (Tabla[i][j].val == 3)
l = i, c = j, i = 4, j = 4;
Tabla[l][c].val = 0;
umplePatratelul(l, c, vectorcerc, vectorL);
Tabla[0][1].val = 3;
umplePatratelul(0, 1, vectorcerc, vectorL);
return 1;
 }
 }
return 0;
}
void modJocPvComputerHard(int L1, int L2,int bk,int vectorbk[], optiuneCerc vectorcerc[], optiuneL vectorL[])
{
initwindow(800, 800);
setbkcolor(bk) ;
cleardevice() ;
afisareTablaDeJoc();
desen(bk, vectorcerc, vectorL);
int cul,cul1,cul2 ;
for(int k=0;k<3;k++)
if(vectorcerc[k].pozitie) cul=vectorcerc[k].culoare ;
for(int k=0;k<3;k++)
if(vectorL[k].pozitie){
cul1=vectorL[k].l1 ;
cul2=vectorL[k].l2 ;
 }
int eroare1, eroare2, jucator1 = 1, Computer = 2;
int castiga = 0;
bool gata = End_game(jucator1);
while (gata)
 {
if (gata)
 {
do
{
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
setcolor(cul1);
outtextxy(285, 75, "Your turn!");
eroare1 = selecteazapiesa(jucator1, bk, vectorcerc, vectorL);
if (!eroare1)
 {
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(cul) ;
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
outtextxy(218, 75, "Move one circle!");
setcolor(WHITE);
mutacerc(bk,vectorcerc,vectorL);
 }
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(LIGHTGRAY);
switch (eroare1)
 {
case 1:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(225, 125, "It's not an 'L'.Try again!");
break;
case 2:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(100, 125, "You put over the opponent's piece.Try again!");
break;
case 3:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(165, 125, "You put over the circle.Try again!");
break;
case 4:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(80, 125, "You can't move on the same position.Try again!");
break;
 }
gata = End_game(Computer);
if (gata == 0)
eroare1 = 0, castiga = 1;
 } while (eroare1);
 }
if (gata)
 {
do
{
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
setcolor(cul2);
outtextxy(217, 75, "Computer's turn!");
delay(1000);
if (Pattern_gasit(Computer))
 {
gata = 0;
 }
else
{
MutaCalculatorulRand(Computer, bk);
eroare2 = 0;
 }
setcolor(bk);
outtextxy(217, 75, "Computer's turn!");
delay(0);
gata = End_game(jucator1);
if (gata == 0)
eroare2 = 0, castiga = 2;
 } while (eroare2);
 }
 }
if (castiga == 2)
 {
setcolor(bk);
outtextxy(218, 75, "Move one circle!");
L2++;
if(L2!=5)
 {
setcolor(cul2);
outtextxy(200, 75, "You lost the game!") ;
 }
 }
else
{
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
setcolor(bk);
outtextxy(218, 75, "Computer's turn!");
L1++;
if(L1!=5)
 {
setcolor(cul1) ;
outtextxy(195, 75, "You won the game!");
 }
 }
settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
char s[2]=" ",t ;
t=char(L1+48);
s[0]=t ;
setcolor(cul1) ;
outtextxy(335,125,s) ;
setcolor(LIGHTGRAY) ;
outtextxy(385,125,"-") ;
t=char(L2+48);
s[0]=t ;
setcolor(cul2) ;
outtextxy(430,125,s) ;
if(L1<5 && L2<5)
 {
     setbkcolor(BLACK) ;
 setcolor(WHITE);
rectangle(249, 650, 350, 700);
setfillstyle(SOLID_FILL,BLACK) ;
floodfill(250,651,WHITE) ;
setcolor(LIGHTCYAN);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
outtextxy(251, 667, "REMATCH");
setcolor(WHITE);
rectangle(449, 650, 550, 700);
floodfill(450,651,WHITE) ;
setcolor(LIGHTCYAN);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
outtextxy(472, 667, "MENU");
bool ok = false;
do
{
if (ismouseclick(WM_LBUTTONDOWN))
 {
int mx = mousex();
int my = mousey();
clearmouseclick(WM_LBUTTONDOWN);
if ((my > 650 && my < 700))
 {
if ((mx > 249 && mx < 350))
 {
closegraph();
modJocPvComputerHard(L1,L2,bk,vectorbk, vectorcerc, vectorL);
 }
else if (mx > 449 && mx < 550)
 {
closegraph();
meniu(bk, vectorbk, vectorcerc, vectorL);
 }
ok = true;
 }
 }
 } while (!ok);
 }
else
{
setcolor(WHITE) ;
rectangle(352, 650, 453, 700);
setfillstyle(SOLID_FILL,BLACK) ;
floodfill(450,651,WHITE) ;
setbkcolor(0) ;
setcolor(LIGHTCYAN);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
outtextxy(375, 667, "MENU");
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
setbkcolor(bk) ;
setcolor(LIGHTGRAY) ;
outtextxy(290,75,"Game over!") ;
bool ok = false;
do
{
if (ismouseclick(WM_LBUTTONDOWN))
 {
int mx = mousex();
int my = mousey();
clearmouseclick(WM_LBUTTONDOWN);
if ((my > 650 && my < 700)&&(mx > 352 && mx <453))
 {
closegraph();
meniu(bk,vectorbk,vectorcerc,vectorL);
 }
ok = true;
 }
 } while (!ok);
}
}
bool DejaPus(int lin1, int col1, int lin2, int col2, int lin3, int col3, int lin4, int col4, int jucator)
{
if (Tabla[lin1][col1].val == jucator && Tabla[lin2][col2].val == jucator && Tabla[lin3][col3].val == jucator
&&
Tabla[lin4][col4].val == jucator)
return 1;
return 0;
}
void MutaCalculatorulRand(int jucator, int bk)
{
bool ok = 1;
while (ok == 1)
 {
int i, j;
i = rand() % 4;
j = rand() % 4;
int caz;
caz = rand() % 16;
// cout << caz << ' ' << i << ' ' << j << endl;
if (caz == 0)
 {
if (i >= 2 && j <= 2 && Mutare_Posibila(i, j, i - 1, j, i - 2, j, i - 2, j + 1, jucator) && !DejaPus(i, j,
i - 1, j, i - 2, j, i - 2, j + 1, jucator))
 {
ok = 0;
Tabla[i][j].gri = 1;
Tabla[i - 1][j].gri = 1;
Tabla[i - 2][j].gri = 1;
Tabla[i - 2][j + 1].gri = 1;
mutare(jucator, vectorL);
 }
 }
else if (caz == 1)
 {
if (i >= 2 && j >= 1 && Mutare_Posibila(i, j, i - 1, j, i - 2, j, i - 2, j - 1, jucator) && !DejaPus(i, j,
i - 1, j, i - 2, j, i - 2, j - 1, jucator))
 {
ok = 0;
Tabla[i][j].gri = 1;
Tabla[i - 1][j].gri = 1;
Tabla[i - 2][j].gri = 1;
Tabla[i - 2][j - 1].gri = 1;
mutare(jucator, vectorL);
 }
 }
else if (caz == 2)
 {
if (i <= 2 && j <= 1 && Mutare_Posibila(i, j, i, j + 1, i, j + 2, i + 1, j + 2, jucator) && !DejaPus(i, j,
i, j + 1, i, j + 2, i + 1, j + 2, jucator))
 {
ok = 0;
Tabla[i][j].gri = 1;
Tabla[i][j + 1].gri = 1;
Tabla[i][j + 2].gri = 1;
Tabla[i + 1][j + 2].gri = 1;
mutare(jucator, vectorL);
 }
 }
else if (caz == 3)
 {
if (i >= 1 && j <= 1 && Mutare_Posibila(i, j, i, j + 1, i, j + 2, i - 1, j + 2, jucator) && !DejaPus(i, j,
i, j + 1, i, j + 2, i - 1, j + 2, jucator))
 {
ok = 0;
Tabla[i][j].gri = 1;
Tabla[i][j + 1].gri = 1;
Tabla[i][j + 2].gri = 1;
Tabla[i - 1][j + 2].gri = 1;
mutare(jucator, vectorL);
 }
 }
else if (caz == 4)
 {
if (i <= 1 && j <= 2 && Mutare_Posibila(i, j, i + 1, j, i + 2, j, i + 2, j + 1, jucator) && !DejaPus(i, j,
i + 1, j, i + 2, j, i + 2, j + 1, jucator))
 {
ok = 0;
Tabla[i][j].gri = 1;
Tabla[i + 1][j].gri = 1;
Tabla[i + 2][j].gri = 1;
Tabla[i + 2][j + 1].gri = 1;
mutare(jucator, vectorL);
 }
 }
else if (caz == 5)
 {
if (i <= 1 && j >= 1 && Mutare_Posibila(i, j, i + 1, j, i + 2, j, i + 2, j - 1, jucator) && !DejaPus(i, j,
i + 1, j, i + 2, j, i + 2, j - 1, jucator))
 {
ok = 0;
Tabla[i][j].gri = 1;
Tabla[i + 1][j].gri = 1;
Tabla[i + 2][j].gri = 1;
Tabla[i + 2][j - 1].gri = 1;
mutare(jucator, vectorL);
 }
 }
else if (caz == 6)
 {
if (i <= 2 && j >= 2 && Mutare_Posibila(i, j, i, j - 1, i, j - 2, i + 1, j - 2, jucator) && !DejaPus(i, j,
i, j - 1, i, j - 2, i + 1, j - 2, jucator))
 {
// cout << DejaPus(i, j, i, j - 1, i, j - 2, i + 1, j - 2, jucator);
ok = 0;
Tabla[i][j].gri = 1; // aici
Tabla[i][j - 1].gri = 1;
Tabla[i][j - 2].gri = 1;
Tabla[i + 1][j - 2].gri = 1;
mutare(jucator, vectorL);
 }
 }
else if (caz == 7)
 {
if (i >= 1 && j >= 2 && Mutare_Posibila(i, j, i, j - 1, i, j - 2, i - 1, j - 2, jucator) && !DejaPus(i, j,
i, j - 1, i, j - 2, i - 1, j - 2, jucator))
 {
ok = 0;
Tabla[i][j].gri = 1;
Tabla[i][j - 1].gri = 1;
Tabla[i][j - 2].gri = 1;
Tabla[i - 1][j - 2].gri = 1;
mutare(jucator, vectorL);
 }
 }
else if (caz == 8)
 {
if (i <= 1 && j <= 2 && Mutare_Posibila(i, j, i, j + 1, i + 1, j + 1, i + 2, j + 1, jucator) && !DejaPus(i
, j, i, j + 1, i + 1, j + 1, i + 2, j + 1, jucator))
 {
ok = 0;
Tabla[i][j].gri = 1;
Tabla[i][j + 1].gri = 1;
Tabla[i + 1][j + 1].gri = 1;
Tabla[i + 2][j + 1].gri = 1;
mutare(jucator, vectorL);
 }
 }
else if (caz == 9)
 {
if (i >= 2 && j <= 2 && Mutare_Posibila(i, j, i, j + 1, i - 1, j + 1, i - 2, j + 1, jucator) && !DejaPus(i
, j, i, j + 1, i - 1, j + 1, i - 2, j + 1, jucator))
 {
ok = 0;
Tabla[i][j].gri = 1;
Tabla[i][j + 1].gri = 1;
Tabla[i - 1][j + 1].gri = 1;
Tabla[i - 2][j + 1].gri = 1;
mutare(jucator, vectorL);
 }
 }
else if (caz == 10)
 {
if (i <= 2 && j <= 1 && Mutare_Posibila(i, j, i + 1, j, i + 1, j + 1, i + 1, j + 2, jucator) && !DejaPus(i
, j, i + 1, j, i + 1, j + 1, i + 1, j + 2, jucator))
 {
ok = 0;
Tabla[i][j].gri = 1;
Tabla[i + 1][j].gri = 1;
Tabla[i + 1][j + 1].gri = 1;
Tabla[i + 1][j + 2].gri = 1;
mutare(jucator, vectorL);
 }
 }
else if (caz == 11)
 {
if (i <= 2 && j >= 2 && Mutare_Posibila(i, j, i + 1, j, i + 1, j - 1, i + 1, j - 2, jucator) && !DejaPus(i
, j, i + 1, j, i + 1, j - 1, i + 1, j - 2, jucator))
 {
ok = 0;
Tabla[i][j].gri = 1;
Tabla[i + 1][j].gri = 1;
Tabla[i + 1][j - 1].gri = 1;
Tabla[i + 1][j - 2].gri = 1;
mutare(jucator, vectorL);
 }
 }
else if (caz == 12)
 {
if (i <= 1 && j >= 1 && Mutare_Posibila(i, j, i, j - 1, i + 1, j - 1, i + 2, j - 1, jucator) && !DejaPus(i
, j, i, j - 1, i + 1, j - 1, i + 2, j - 1, jucator))
 {
ok = 0;
Tabla[i][j].gri = 1;
Tabla[i][j - 1].gri = 1;
Tabla[i + 1][j - 1].gri = 1;
Tabla[i + 2][j - 1].gri = 1;
mutare(jucator, vectorL);
 }
 }
else if (caz == 13)
 {
if (i >= 2 && j >= 1 && Mutare_Posibila(i, j, i, j - 1, i - 1, j - 1, i - 2, j - 1, jucator) && !DejaPus(i
, j, i, j - 1, i - 1, j - 1, i - 2, j - 1, jucator))
 {
ok = 0;
Tabla[i][j].gri = 1;
Tabla[i][j - 1].gri = 1;
Tabla[i - 1][j - 1].gri = 1;
Tabla[i - 2][j - 1].gri = 1;
mutare(jucator, vectorL);
 }
 }
else if (caz == 14)
 {
if (i >= 1 && j <= 1 && Mutare_Posibila(i, j, i - 1, j, i - 1, j + 1, i - 1, j + 2, jucator) && !DejaPus(i
, j, i - 1, j, i - 1, j + 1, i - 1, j + 2, jucator))
 {
ok = 0;
Tabla[i][j].gri = 1;
Tabla[i - 1][j].gri = 1; // aici
Tabla[i - 1][j + 1].gri = 1;
Tabla[i - 1][j + 2].gri = 1;
mutare(jucator, vectorL);
 }
 }
else if (caz == 15)
 {
if (i >= 1 && j >= 2 && Mutare_Posibila(i, j, i - 1, j, i - 1, j - 1, i - 1, j - 2, jucator) && !DejaPus(i
, j, i - 1, j, i - 1, j - 1, i - 1, j - 2, jucator))
 {
ok = 0;
Tabla[i][j].gri = 1;
Tabla[i - 1][j].gri = 1;
Tabla[i - 1][j - 1].gri = 1;
Tabla[i - 1][j - 2].gri = 1;
mutare(jucator, vectorL);
 }
 }
 }
delay(1000);
int cnt = 0, lc1, lc2, cc1, cc2;
for (int i = 0; i < 4 && cnt < 2; ++i)
for (int j = 0; j < 4 && cnt < 2; ++j)
 {
if (Tabla[i][j].val == 3 && cnt == 0)
 {
lc1 = i;
cc1 = j;
cnt++;
 }
else if (Tabla[i][j].val == 3 && cnt == 1)
 {
lc2 = i;
cc2 = j;
cnt++;
 }
 }
int caz = rand() % 2 + 1;
int l, c;
if (caz == 1)
 {
l = lc1;
c = cc1;
 }
else if (caz == 2)
 {
l = lc2;
c = cc2;
 }
int ml, mc;
bool gata = 0;
while (!gata)
 {
ml = rand() % 4;
mc = rand() % 4;
if (Tabla[ml][mc].val == 0)
 {
Tabla[l][c].val = 0;
Tabla[ml][mc].val = 3;
umplePatratelul(l, c, vectorcerc, vectorL);
umplePatratelul(ml, mc, vectorcerc, vectorL);
gata = 1;
 }
 }
}
void modJocPvComputerEasy(int L1, int L2, int bk, int vectorbk[], optiuneCerc vectorcerc[], optiuneL vectorL[])
{
initwindow(800, 800);
setbkcolor(bk);
cleardevice();
afisareTablaDeJoc();
desen(bk, vectorcerc, vectorL);
int cul, cul1, cul2;
for (int k = 0; k < 3; k++)
if (vectorcerc[k].pozitie)
cul = vectorcerc[k].culoare;
for (int k = 0; k < 3; k++)
if (vectorL[k].pozitie)
 {
cul1 = vectorL[k].l1;
cul2 = vectorL[k].l2;
 }
int eroare1, eroare2, jucator1 = 1, Computer = 2;
int castiga = 0;
bool gata = End_game(jucator1);
while (gata)
 {
if (gata)
 {
do
{
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
setcolor(cul1);
outtextxy(285, 75, "Your turn!");
eroare1 = selecteazapiesa(jucator1, bk, vectorcerc, vectorL);
if (!eroare1)
 {
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(cul);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
outtextxy(218, 75, "Move one circle!");
setcolor(WHITE);
mutacerc(bk, vectorcerc, vectorL);
 }
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(LIGHTGRAY);
switch (eroare1)
 {
case 1:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(225, 125, "It's not an 'L'.Try again!");
break;
case 2:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(100, 125, "You put over the opponent's piece.Try again!");
break;
case 3:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(165, 125, "You put over the circle.Try again!");
break;
case 4:
setcolor(bk);
outtextxy(80, 125, "You can't move on the same position.Try again!");
setcolor(LIGHTGRAY);
outtextxy(80, 125, "You can't move on the same position.Try again!");
break;
 }
gata = End_game(Computer);
if (gata == 0)
eroare1 = 0, castiga = 1;
 } while (eroare1);
 }
if (gata)
 {
do
{
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
setcolor(cul2);
outtextxy(217, 75, "Computer's turn!");
delay(1000);
MutaCalculatorulRand(Computer, bk);
eroare2 = 0;
setcolor(bk);
outtextxy(217, 75, "Computer's turn!");
delay(0);
gata = End_game(jucator1);
if (gata == 0)
eroare2 = 0, castiga = 2;
 } while (eroare2);
 }
 }
if (castiga == 2)
 {
setcolor(bk);
outtextxy(218, 75, "Move one circle!");
L2++;
if (L2 != 5)
 {
setcolor(cul2);
outtextxy(200, 75, "You lost the game!");
 }
 }
else
{
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
setcolor(bk);
outtextxy(218, 75, "Computer's turn!");
L1++;
if (L1 != 5)
 {
setcolor(cul1);
outtextxy(195, 75, "You won the game!");
 }
 }
settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
char s[2] = " ", t;
t = char(L1 + 48);
s[0] = t;
setcolor(cul1);
outtextxy(335, 125, s);
setcolor(LIGHTGRAY);
outtextxy(385, 125, "-");
t = char(L2 + 48);
s[0] = t;
setcolor(cul2);
outtextxy(430, 125, s);
if (L1 < 5 && L2 < 5)
 {
setcolor(WHITE);
rectangle(249, 650, 350, 700);
setfillstyle(SOLID_FILL, BLACK);
floodfill(250, 651, WHITE);
setcolor(LIGHTCYAN);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setbkcolor(0);
outtextxy(251, 667, "REMATCH");
setcolor(WHITE);
rectangle(449, 650, 550, 700);
setfillstyle(SOLID_FILL, BLACK);
floodfill(450, 651, WHITE);
setcolor(LIGHTCYAN);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
outtextxy(472, 667, "MENU");
bool ok = false;
do
{
if (ismouseclick(WM_LBUTTONDOWN))
 {
int mx = mousex();
int my = mousey();
clearmouseclick(WM_LBUTTONDOWN);
if ((my > 650 && my < 700))
 {
if ((mx > 249 && mx < 350))
 {
closegraph();
modJocPvComputerEasy(L1, L2, bk, vectorbk, vectorcerc, vectorL);
 }
else if (mx > 449 && mx < 550)
 {
closegraph();
meniu(bk, vectorbk, vectorcerc, vectorL);
 }
ok = true;
 }
 }
 } while (!ok);
 }
else
{
setcolor(WHITE);
rectangle(352, 650, 453, 700);
setfillstyle(SOLID_FILL, BLACK);
floodfill(450, 651, WHITE);
setbkcolor(0);
setcolor(LIGHTCYAN);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
outtextxy(375, 667, "MENU");
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
setbkcolor(bk);
setcolor(LIGHTGRAY);
outtextxy(290, 75, "Game over!");
bool ok = false;
do
{
if (ismouseclick(WM_LBUTTONDOWN))
 {
int mx = mousex();
int my = mousey();
clearmouseclick(WM_LBUTTONDOWN);
if ((my > 650 && my < 700) && (mx > 352 && mx < 453))
 {
closegraph();
meniu(bk, vectorbk, vectorcerc, vectorL);
 }
ok = true;
 }
 } while (!ok);
 }
}
void setaripag1(int bk, int vectorbk[], optiuneCerc vectorcerc[], optiuneL vectorL[])
{
initwindow(800, 800);
setbkcolor(bk);
cleardevice();
// optiunea 1
rectangle(100, 280, 124, 290);
rectangle(100, 200, 112, 280);
rectangle(100, 190, 124, 200);
rectangle(112, 200, 124, 280);
rectangle(102, 310, 122, 330);
// optiunea 2
rectangle(360, 280, 384, 290);
rectangle(360, 200, 372, 280);
rectangle(360, 190, 384, 200);
rectangle(372, 200, 384, 280);
rectangle(362, 310, 382, 330);
// optiunea 3
rectangle(620, 280, 644, 290);
rectangle(620, 200, 632, 280);
rectangle(620, 190, 644, 200);
rectangle(632, 200, 644, 280);
rectangle(622, 310, 642, 330);
// pagini
rectangle(330, 760, 360, 790);
rectangle(380, 760, 410, 790);
// optiunecerc 1
circle(115, 500, 35);
rectangle(105, 560, 125, 580);
// optiunecerc 2
circle(375, 500, 35);
rectangle(365, 560, 385, 580);
// optiunecerc 3
circle(635, 500, 35);
rectangle(625, 560, 645, 580);
setfillstyle(SOLID_FILL, BLACK);
floodfill(626, 561, WHITE);
// backtomenu
setcolor(WHITE);
rectangle(10, 760, 215, 790);
setfillstyle(SOLID_FILL, BLACK);
floodfill(11, 761, WHITE);
setbkcolor(0);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(LIGHTCYAN);
outtextxy(15, 767, "Return to Menu");
// optiunea 1
setfillstyle(SOLID_FILL, LIGHTMAGENTA);
floodfill(101, 281, WHITE);
floodfill(101, 201, WHITE);
setfillstyle(SOLID_FILL, LIGHTGREEN);
floodfill(101, 191, WHITE);
floodfill(113, 201, WHITE);
setcolor(LIGHTMAGENTA);
line(100, 280, 112, 280);
setcolor(LIGHTGREEN);
line(113, 200, 124, 200);
setcolor(WHITE);
if (vectorL[0].pozitie)
 {
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(106, 311, WHITE);
 }
else
{
setfillstyle(SOLID_FILL, BLACK);
floodfill(106, 311, WHITE);
 }
// optiunea 2
setfillstyle(SOLID_FILL, LIGHTRED);
floodfill(361, 281, WHITE);
setfillstyle(SOLID_FILL, LIGHTRED);
floodfill(361, 201, WHITE);
setfillstyle(SOLID_FILL, LIGHTBLUE);
floodfill(361, 191, WHITE);
setfillstyle(SOLID_FILL, LIGHTBLUE);
floodfill(373, 201, WHITE);
if (vectorL[1].pozitie)
 {
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(363, 311, WHITE);
 }
else
{
setfillstyle(SOLID_FILL, BLACK);
floodfill(363, 311, WHITE);
 }
setcolor(LIGHTRED);
line(360, 280, 372, 280);
setcolor(LIGHTBLUE);
line(373, 200, 384, 200);
setcolor(WHITE);
// optiunea 3
setfillstyle(SOLID_FILL, BROWN);
floodfill(621, 281, WHITE);
setfillstyle(SOLID_FILL, BROWN);
floodfill(621, 201, WHITE);
setfillstyle(SOLID_FILL, CYAN);
floodfill(621, 191, WHITE);
setfillstyle(SOLID_FILL, CYAN);
floodfill(633, 201, WHITE);
if (vectorL[2].pozitie)
 {
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(623, 311, WHITE);
 }
else
{
setfillstyle(SOLID_FILL, BLACK);
floodfill(623, 311, WHITE);
 }
setcolor(BROWN);
line(620, 280, 632, 280);
setcolor(CYAN);
line(632, 200, 643, 200);
setcolor(WHITE);
// optiunecerc1
setfillstyle(SOLID_FILL, YELLOW);
floodfill(115, 500, WHITE);
if (vectorcerc[0].pozitie)
 {
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(106, 561, WHITE);
 }
else
{
setfillstyle(SOLID_FILL, BLACK);
floodfill(106, 561, WHITE);
 }
// optiunecerc 2
setfillstyle(SOLID_FILL, BLUE);
floodfill(375, 500, WHITE);
if (vectorcerc[1].pozitie)
 {
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(366, 561, WHITE);
 }
else
{
setfillstyle(SOLID_FILL, BLACK);
floodfill(366, 561, WHITE);
 }
// optiunecerc 3
setfillstyle(SOLID_FILL, RED);
floodfill(635, 500, WHITE);
if (vectorcerc[2].pozitie)
 {
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(626, 561, WHITE);
 }
else
{
setfillstyle(SOLID_FILL, BLACK);
floodfill(626, 561, WHITE);
 }
// pagini
setfillstyle(SOLID_FILL, BLACK);
floodfill(331, 761, WHITE);
setfillstyle(SOLID_FILL, BLACK);
floodfill(381, 761, WHITE);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(LIGHTGRAY);
setbkcolor(0);
outtextxy(339, 768, "1");
setcolor(LIGHTGRAY);
outtextxy(389, 768, "2");
settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
setcolor(LIGHTCYAN);
setbkcolor(bk);
outtextxy(150, 75, "Choose 'L' Color");
setcolor(LIGHTCYAN);
outtextxy(100, 375, "Choose circle Color");
selectSetari1(bk, vectorbk, vectorcerc, vectorL);
}
void schimbarepagina(int mx, int my, int bk, int vectorbk[], optiuneCerc vectorcerc[], optiuneL vectorL[])
{
int L1, L2;
L1 = L2 = 0;
if ((mx > 320 && mx < 445) && (my > 690 && my < 730))
closegraph();
else
{
if ((mx > 320 && mx < 445) && (my > 290 && my < 330))
 {
closegraph();
modJocPvComputerEasy(L1, L2, bk, vectorbk, vectorcerc, vectorL);
 }
else if ((mx > 320 && mx < 445) && (my > 390 && my < 430))
 {
closegraph();
modJocPvComputerHard(L1,L2,bk, vectorbk, vectorcerc, vectorL);
 }
else if ((mx > 270 && mx < 500) && (my > 490 && my < 530))
 {
closegraph();
modJocPvP(L1, L2, bk, vectorbk, vectorcerc, vectorL);
 }
else if ((mx > 285 && mx < 485) && (my > 590 && my < 630))
 {
closegraph();
setaripag1(bk, vectorbk, vectorcerc, vectorL);
 }
 }
}
void selectare(int bk, int vectorbk[], optiuneCerc vectorcerc[], optiuneL vectorL[])
{
bool ok = false;
do
{
if (ismouseclick(WM_LBUTTONDOWN))
 {
int mx = mousex();
int my = mousey();
clearmouseclick(WM_LBUTTONDOWN);
if ((mx > 320 && mx < 445) && (my > 290 && my < 330))
ok = true;
else if ((mx > 320 && mx < 445) && (my > 390 && my < 430))
ok = true;
else if ((mx > 270 && mx < 500) && (my > 490 && my < 530))
ok = true;
else if ((mx > 285 && mx < 485) && (my > 590 && my < 630))
ok = true;
else if ((mx > 320 && mx < 445) && (my > 690 && my < 730))
ok = true;
if (ok)
 {
delay(100);
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(mx, my, WHITE);
delay(0);
schimbarepagina(mx, my, bk, vectorbk, vectorcerc, vectorL);
 }
 }
 } while (!ok);
}
void meniu(int bk, int vectorbk[], optiuneCerc vectorcerc[], optiuneL vectorL[])
{
initwindow(800, 800);
setbkcolor(bk);
cleardevice();
settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
rectangle(265, 75, 290, 175);
rectangle(290, 150, 500, 175);
outtextxy(300, 100, "BonoL");
setfillstyle(SOLID_FILL, LIGHTBLUE);
floodfill(266, 76, WHITE);
setfillstyle(SOLID_FILL, LIGHTRED);
floodfill(291, 151, WHITE);
setbkcolor(0);
setfillstyle(SOLID_FILL, BLACK);
setcolor(WHITE);
rectangle(320, 290, 445, 330);
floodfill(321, 291, WHITE);
setcolor(LIGHTCYAN);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
setcolor(WHITE);
rectangle(320, 390, 445, 430);
floodfill(336, 401, WHITE);
setcolor(LIGHTCYAN);
outtextxy(335, 300, "EASY");
outtextxy(335, 400, "HARD");
setcolor(WHITE);
rectangle(270, 490, 500, 530);
floodfill(271, 491, WHITE);
setcolor(LIGHTCYAN);
outtextxy(275, 500, "2 PLAYERS");
setcolor(WHITE);
rectangle(285, 590, 485, 630);
floodfill(286, 591, WHITE);
setcolor(LIGHTCYAN);
outtextxy(290, 600, "SETTINGS");
setcolor(WHITE);
rectangle(320, 690, 445, 730);
floodfill(321, 691, WHITE);
setcolor(LIGHTCYAN);
outtextxy(336, 700, "EXIT");
setcolor(WHITE) ;
setbkcolor(bk) ;
settextstyle(DEFAULT_FONT,HORIZ_DIR,1) ;
outtextxy(630,745,"Stoian Cristian") ;
outtextxy(630,760,"Medves Denis-Stelian") ;
outtextxy(630,775,"Simiuc Robert-Andrei") ;
selectare(bk, vectorbk, vectorcerc, vectorL);
}
void setaripag2(int bk, int vectorbk[])
{
initwindow(800, 800);
setbkcolor(bk);
cleardevice();
// optiuni background
rectangle(80, 200, 110, 230);
rectangle(80, 290, 110, 320);
rectangle(80, 380, 110, 410);
// incadrare text
rectangle(125, 200, 220, 230);
rectangle(125, 290, 220, 320);
rectangle(125, 380, 230, 410);
rectangle(100, 65, 707, 110);
setfillstyle(SOLID_FILL, 0);
floodfill(126, 201, WHITE);
floodfill(126, 291, WHITE);
floodfill(126, 381, WHITE);
floodfill(101, 66, WHITE);
// pagini
rectangle(330, 760, 360, 790);
rectangle(380, 760, 410, 790);
// pagini
setfillstyle(SOLID_FILL, BLACK);
floodfill(331, 761, WHITE);
setfillstyle(SOLID_FILL, BLACK);
floodfill(381, 761, WHITE);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(LIGHTGRAY);
setbkcolor(0);
outtextxy(339, 768, "1");
setcolor(LIGHTGRAY);
outtextxy(389, 768, "2");
// selectare background
if (vectorbk[0])
 {
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(81, 201, WHITE);
 }
else
{
setfillstyle(SOLID_FILL, BLACK);
floodfill(81, 201, WHITE);
 }
if (vectorbk[1])
 {
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(81, 291, WHITE);
 }
else
{
setfillstyle(SOLID_FILL, BLACK);
floodfill(81, 291, WHITE);
 }
if (vectorbk[2])
 {
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(81, 381, WHITE);
 }
else
{
setfillstyle(SOLID_FILL, BLACK);
floodfill(81, 381, WHITE);
 }
setcolor(WHITE);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
outtextxy(130, 205, "BLACK");
outtextxy(130, 295, "GREEN");
outtextxy(130, 385, "MAGENTA");
setcolor(WHITE);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
outtextxy(102, 75, "Choose a background color");
selectSetari2(bk, vectorbk);
}
void selectSetari1(int bk, int vectorbk[], optiuneCerc vectorcerc[], optiuneL vectorL[])
{
bool ok = false;
do
{
if (ismouseclick(WM_LBUTTONDOWN))
 {
int mx = mousex();
int my = mousey();
clearmouseclick(WM_LBUTTONDOWN);
// returnare
if ((mx > 10 && mx < 215) && (my > 760 && my < 790))
 {
ok = true;
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(11, 761, WHITE);
delay(100);
setfillstyle(SOLID_FILL, BLACK);
floodfill(11, 761, WHITE);
delay(0);
closegraph();
meniu(bk, vectorbk, vectorcerc, vectorL);
 }
// primul L
else if ((mx > 102 && mx < 122) && (my > 310 && my < 330))
 {
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(106, 311, WHITE);
setfillstyle(SOLID_FILL, BLACK);
floodfill(363, 311, WHITE);
setfillstyle(SOLID_FILL, BLACK);
floodfill(623, 311, WHITE);
vectorL[0].pozitie = 1;
vectorL[1].pozitie = 0;
vectorL[2].pozitie = 0;
 }
// al doilea L
else if ((mx > 362 && mx < 382) && (my > 310 && my < 330))
 {
setfillstyle(SOLID_FILL, BLACK);
floodfill(106, 311, WHITE);
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(363, 311, WHITE);
setfillstyle(SOLID_FILL, BLACK);
floodfill(623, 311, WHITE);
vectorL[0].pozitie = 0;
vectorL[1].pozitie = 1;
vectorL[2].pozitie = 0;
 }
// al treilea L
else if ((mx > 622 && mx < 642) && (my > 310 && my < 330))
 {
setfillstyle(SOLID_FILL, BLACK);
floodfill(106, 311, WHITE);
setfillstyle(SOLID_FILL, BLACK);
floodfill(363, 311, WHITE);
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(623, 311, WHITE);
vectorL[0].pozitie = 0;
vectorL[1].pozitie = 0;
vectorL[2].pozitie = 1;
 }
// primul cerc
else if ((mx > 105 && mx < 125) && (my > 560 && my < 580))
 {
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(106, 561, WHITE);
setfillstyle(SOLID_FILL, BLACK);
floodfill(366, 561, WHITE);
setfillstyle(SOLID_FILL, BLACK);
floodfill(626, 561, WHITE);
vectorcerc[0].pozitie = 1;
vectorcerc[1].pozitie = 0;
vectorcerc[2].pozitie = 0;
 }
// al doilea cerc
else if ((mx > 365 && mx < 385) && (my > 560 && my < 580))
 {
setfillstyle(SOLID_FILL, BLACK);
floodfill(106, 561, WHITE);
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(366, 561, WHITE);
setfillstyle(SOLID_FILL, BLACK);
floodfill(626, 561, WHITE);
vectorcerc[0].pozitie = 0;
vectorcerc[1].pozitie = 1;
vectorcerc[2].pozitie = 0;
 }
// al treilea cerc
else if ((mx > 625 && mx < 645) && (my > 560 && my < 580))
 {
setfillstyle(SOLID_FILL, BLACK);
floodfill(106, 561, WHITE);
setfillstyle(SOLID_FILL, BLACK);
floodfill(366, 561, WHITE);
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(626, 561, WHITE);
vectorcerc[0].pozitie = 0;
vectorcerc[1].pozitie = 0;
vectorcerc[2].pozitie = 1;
 }
// pagina1
else if ((mx > 330 && mx < 360) && (my > 760 && my < 790))
 {
ok = true;
setbkcolor(0);
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(331, 761, WHITE);
delay(100);
setfillstyle(SOLID_FILL, BLACK);
floodfill(331, 761, WHITE);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(LIGHTGRAY);
outtextxy(339, 768, "1");
delay(100);
closegraph();
setaripag1(bk, vectorbk, vectorcerc, vectorL);
 }
// pagina 2
else if ((mx > 380 && mx < 410) && (my > 760 && my < 790))
 {
ok = true;
setbkcolor(0);
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(381, 761, WHITE);
delay(100);
setfillstyle(SOLID_FILL, BLACK);
floodfill(381, 761, WHITE);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(LIGHTGRAY);
outtextxy(389, 768, "2");
closegraph();
setaripag2(bk, vectorbk);
 }
 }
 } while (!ok);
}
void selectSetari2(int bk, int vectorbk[])
{
bool ok = false;
do
{
if (ismouseclick(WM_LBUTTONDOWN))
 {
int mx = mousex();
int my = mousey();
clearmouseclick(WM_LBUTTONDOWN);
// optiunea 1
if ((mx > 80 && mx < 110) && (my > 200 && my < 230))
 {
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(81, 201, WHITE);
setfillstyle(SOLID_FILL, BLACK);
floodfill(81, 291, WHITE);
setfillstyle(SOLID_FILL, BLACK);
floodfill(81, 381, WHITE);
setfillstyle(SOLID_FILL, BLACK);
floodfill(1, 1, WHITE);
vectorbk[0] = 1, vectorbk[1] = 0, vectorbk[2] = 0;
bk = 0;
 }
// optiunea 2
if ((mx > 80 && mx < 110) && (my > 290 && my < 320))
 {
setfillstyle(SOLID_FILL, BLACK);
floodfill(81, 201, WHITE);
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(81, 291, WHITE);
setfillstyle(SOLID_FILL, BLACK);
floodfill(81, 381, WHITE);
setfillstyle(SOLID_FILL, GREEN);
floodfill(1, 1, WHITE);
vectorbk[0] = 0, vectorbk[1] = 1, vectorbk[2] = 0;
bk = 2;
 }
// optiunea 3
if ((mx > 80 && mx < 110) && (my > 380 && my < 410))
 {
setfillstyle(SOLID_FILL, BLACK);
floodfill(81, 201, WHITE);
setfillstyle(SOLID_FILL, BLACK);
floodfill(81, 291, WHITE);
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(81, 381, WHITE);
setfillstyle(SOLID_FILL, MAGENTA);
floodfill(1, 1, WHITE);
vectorbk[0] = 0, vectorbk[1] = 0, vectorbk[2] = 1;
bk = 5;
 }
// pagina 1
if ((mx > 330 && mx < 360) && (my > 760 && my < 790))
 {
ok = true;
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(331, 761, WHITE);
delay(100);
setfillstyle(SOLID_FILL, BLACK);
floodfill(331, 761, WHITE);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(LIGHTGRAY);
outtextxy(339, 768, "1");
delay(100);
setaripag1(bk, vectorbk, vectorcerc, vectorL);
closegraph();
 }
// pagina 2
if ((mx > 380 && mx < 410) && (my > 760 && my < 790))
 {
ok = true;
setfillstyle(SOLID_FILL, LIGHTGRAY);
floodfill(381, 761, WHITE);
delay(100);
setfillstyle(SOLID_FILL, BLACK);
floodfill(381, 761, WHITE);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(LIGHTGRAY);
outtextxy(389, 768, "2");
delay(100);
setaripag2(bk, vectorbk);
closegraph();
 }
 }
 } while (!ok);
}
int main()
{
int bk = 0;
int vectorbk[3] = {1, 0, 0};
vectorcerc[0].culoare = 14;
vectorcerc[1].culoare = 1;
vectorcerc[2].culoare = 4;
vectorcerc[0].pozitie = 1;
vectorcerc[1].pozitie = 0;
vectorcerc[2].pozitie = 0;
vectorL[0].pozitie = 0;
vectorL[1].pozitie = 1;
vectorL[2].pozitie = 0;
vectorL[0].l1 = 10;
vectorL[0].l2 = 13;
vectorL[1].l1 = 9;
vectorL[1].l2 = 12;
vectorL[2].l1 = 3;
vectorL[2].l2 = 6;
meniu(bk, vectorbk, vectorcerc, vectorL);
closegraph();
return 0;
}
