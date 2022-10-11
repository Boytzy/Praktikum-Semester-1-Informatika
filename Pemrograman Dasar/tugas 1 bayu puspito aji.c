#include <stdio.h>

int main(){
    int boruto[3] = {85, 90, 86};
    int sarada[3] = {84, 90, 89};
    printf("===============================================\n");
    printf("\nNilai Boruto : \n");
    printf("Nilai Ujian Pemrograman Dasar ke-1 : %d \n", boruto[0]);
    printf("Nilai Ujian Pemrograman Dasar ke-2 : %d \n", boruto[1]);
    printf("Nilai Ujian Pemrograman Dasar ke-3 : %d \n", boruto[2]);
    printf("\n===============================================\n");
    printf("\nNilai Sarada : \n");
    printf("Nilai Ujian Pemrograman Dasar ke-1 : %d \n", sarada[0]);
    printf("Nilai Ujian Pemrograman Dasar ke-2 : %d \n", sarada[1]);
    printf("Nilai Ujian Pemrograman Dasar ke-3 : %d \n", sarada[2]);
    printf("\n===============================================\n");

    
    printf("\nRekap Perbandingan Nilai Boruto dan Sarada : \n");
    int i;
    for(i = 0; i < 3; i++)
    {
        if(boruto[i] > sarada[i])
        {
            printf("Hasilnya: 1\n");
        }
        else
        {
            printf("Hasilnya: 0\n");
        }
    }
    printf("\n===============================================\n");
}