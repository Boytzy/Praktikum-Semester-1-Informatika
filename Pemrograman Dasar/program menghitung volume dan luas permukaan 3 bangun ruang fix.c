#include <stdio.h>

int main()
{
	printf("Nama : Bayu Puspito Aji\n");
	printf("NIM  : 291\n");
	printf("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BALOK, KUBUS, dan LIMAS SEGIEMPAT\n");
	balok();
	kubus();
    limas_segiempat();	
    return 0;
}
void balok(void)
{
	int v, p, l, t, lp, lpf;
	printf("\nBALOK");
	printf("\nnilai panjang = ");
	scanf("%d", &p);
	printf("nilai lebar = ");
	scanf("%d", &l);
	printf("nilai tinggi = ");
	scanf("%d", &t);
	
	v = p * l * t;	
	lp = (p*l)+(l*t)+(p*t);
	lpf = lp * 2;
	printf("volume Balok = %d", v);
    printf("\nluas permukaan Balok = %d\n", lpf);
    printf("\n===============================================================================\n");
}
void kubus(void)
{
	int v, s, lp;
	printf("\nKUBUS");
	printf("\nnilai sisi = ");
	scanf("%d", &s);
	
	v = s * s * s;
	lp = 6 * s * s;
	printf("volume kubus = %d", v);
	printf("\nluas permukaan kubus = %d\n", lp);
	printf("\n===============================================================================\n");
}
void limas_segiempat(void)
{
	int v, p, l, t, la, ps, tp, ts, ls, lp;
	printf("\nLIMAS SEGIEMPAT");
	printf("\nnilai panjang = ");
	scanf("%d", &p);
	printf("nilai lebar = ");
	scanf("%d", &l);
	printf("nilai tinggi = ");
	scanf("%d", &t);
	
	v = p * l * t / 3;
	la = p * l;
	ps = p/2;
	tp = (ps * ps)+(t * t);
	ts = sqrt(tp);
	ls = l * ts / 2;
	lp = la + (4 * ls);
	
	printf("volume limas segiempat = %d", v);
	printf("\nluas permukaan limas segiempat = %d\n", lp);
	printf("\n===============================================================================\n");
}