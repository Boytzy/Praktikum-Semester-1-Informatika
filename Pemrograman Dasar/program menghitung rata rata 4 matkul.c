#include <stdio.h>

int main()
{
	int a, b, c, d;
	char nama[50];
	char nim[20];
	float rata; 
	
	printf("Masukan Nama Anda : ");
	scanf("%s", &nama);
	printf("Masukan Nim Anda : ");
	scanf("%s", &nim);
	printf("------------------------------\n");
	printf("masukan nilai Pemrograman Dasar: ");
	scanf("%i", &a);
	printf("masukan nilai Kalkulus: ");
	scanf("%i", &b);
	printf("masukan nilai PTI: ");
	scanf("%i", &c);
	printf("masukan nilai Orkom: ");
	scanf("%i", &d);
	printf("------------------------------\n");
	
	rata =(a + b + c + d) / 4;
	printf("Nim : %s", nim);
	printf("\Nama : %s", nama);
	printf("\nNilai Perograman Dasar : %i", a);
	printf("\nNilai Kalkulus : %i", b);
	printf("\nNilai PTI : %i", c);
	printf("\nNilai Orkom : %i", d);
	printf("\nNilai Rata Rata :%f", rata);
	
	if(rata >= 75){
		printf("\nStatus : Lulus");
	}
	else{
		printf("\nStatus : Tidak Lulus");
	}
	
}