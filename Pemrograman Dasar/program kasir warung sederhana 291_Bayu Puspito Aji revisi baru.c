#include <stdio.h>

main(){
 float total_harga, kembali, pembayaran, kurang;
 int pilih, banyak_pembelian;
 char jawab;
 
 do{
 printf("\n=======================================================\n");
 printf("             Warung Bayu ni Bosss\n");
 printf("            Enak Murah dan Higienis \n");
 printf("=======================================================\n");
 printf("\n Berikut daftar menunya boskuuu\n");
 printf("-------------------------------------------------------\n");
 printf("| No  |  Menu Makanan  |           Harga              |\n");
 printf("-------------------------------------------------------\n");
 printf("| 1.  |  Tahu Telor    |         Rp. 12.000           |\n");
 printf("| 2.  |  Mie Goreng    |         Rp. 8.000            |\n");
 printf("| 3.  |  Nasi Goreng   |         Rp. 10.000           |\n");
 printf("-------------------------------------------------------\n");
 
 printf("\n Masukan nomor menu yang dipilih [1/2/3] = ");scanf("%d", &pilih);
 
 switch(pilih){
  
  case 1:
   printf("\nMenu yang dipilih adalah Tahu Telor\n");
   printf("Masukan Jumlah Pesanan   = ");
   scanf("%d", &banyak_pembelian);
   total_harga=12000*banyak_pembelian;
   printf("Grand Total              = Rp. %.0f", total_harga);
   printf("\nTunai                    = Rp. ");scanf("%f", &pembayaran);
   if (total_harga<=pembayaran){
    kembali=pembayaran-total_harga;
    printf("Kembali                  = Rp. %.0f   \nTerima Kasih", kembali);
   }  
   else if(total_harga>=pembayaran){
    kurang=total_harga-pembayaran;
    printf("Maaf Uang Anda Kurang  Rp. %.0f", kurang);
   }break;
   
  case 2:
   printf("\nMenu yang dipilih adalah Mie Goreng\n");
   printf("Masukan Jumlah Pesanan   = ");scanf("%d", &banyak_pembelian);
   total_harga=8000*banyak_pembelian;
   printf("Grand Total              = Rp. %.0f", total_harga);
   printf("\ndibayar                  = Rp. ");scanf("%f", &pembayaran);
   if (total_harga<=pembayaran){
    kembali=pembayaran-total_harga;
    printf("Kembali                  = Rp. %.0f", kembali);
   }
   else if(total_harga>=pembayaran){
    kurang=total_harga-pembayaran;
    printf("Maaf Uang Anda Kurang  Rp. %.0f", kurang);
   }break;
  
  case 3:
   printf("\nMenu yang dipilih adalah Nasi Goreng\n");
   printf("Masukan Jumlah Pesanan   = ");scanf("%d", &banyak_pembelian);
   total_harga=10000*banyak_pembelian;
   printf("Grand Total              = Rp. %.0f", total_harga);
   printf("\ndibayar                  = Rp. ");scanf("%f", &pembayaran);
   if (total_harga<=pembayaran){
    kembali=pembayaran-total_harga;
    printf("Kembali                  = Rp. %.0f", kembali);
   }
   else if(total_harga>=pembayaran){
    kurang=total_harga-pembayaran;
    printf("Maaf Uang Anda Kurang   Rp. %.0f", kurang);
   }break;
 
  default:    
        printf("\n Jawaban yang anda masukan salah atau tidak tersedia");
        break;
 }
   fflush(stdin);
   printf("\n-------------------------------------------------------");
   printf("\n Pesan Lagi ? (y/n) : ");
   scanf("%c", &jawab);
}while (jawab == 'y' || jawab == 'Y');

return 0;
}