#include <stdio.h>
#include <string.h>

int main()
{

    int i = 0, pilihMenu, loop, loop1;

    // nim [i+1] = Banyak Data, [15] = Banyak Kumpulan Karakter    
    char nim[i + 1][15], nama[i + 1][100], kelas[i + 1][20], dosen[i + 1][100], search[15];

// backMenu = label untuk alur jalannya program
backMenu:
    printf("Sistem Pendataan Akun I-Lab Infotech\n");
    printf("=== Pilih Menu ===\n");
    printf("1. Create Data\n");
    printf("2. Show Data\n");
    printf("3. Update Data\n");
    printf("4. Delete Data\n");
    printf("5. Search Data\n");
    printf("6. Exit\n");
    printf("\nMasukan Menu Yang Ingin Dipilih : ");
    scanf("%i", &pilihMenu);

    switch (pilihMenu)
    {

    case 1:

        printf("Input Nim Praktikan : ");
        scanf("%s", &nim[i]);

        //Jika banyak data = 0
        if (i == 0)
        {
            //Jika banyak karakter = 10
            if (strlen(nim[i]) == 10)
            {
                printf("Input Nama Praktikan : ");
                scanf(" %[^\n]s", &nama[i]);
                printf("Input Kelas Pemrograman Dasar : ");
                scanf(" %[^\n]s", &kelas[i]);
                printf("Input Nama Dosen Pengampu : ");
                scanf(" %[^\n]s", &dosen[i]);
                //Jika setiap data berhasil ditambah, maka i ditambah 1 agar indexnya bisa berpindah
                i = i + 1;
                printf("\nData Berhasil Ditambah\n\n");

                //Di akan Pergi ke label backMenu (yang diatas tadi)
                goto backMenu;
            }
            //Jika Tidak
            else
            {
                printf("Data Gagal Ditambah, Nim Anda Kurang atau Lebih Dari 10\n");
            }
        }
        //Jika Tidak
        else
        {
            //Jika banyak karakter = 10
            if (strlen(nim[i]) == 10)
            {
                //Perulangan yang patokannya mulai dari 'loop', dan diulang sebanyak 'i'
                for (loop = 0; loop < i; loop++)
                {
                    //Jika perbandingan variable 'nim[i]' dan 'nim[loop]', berbeda
                    if (strcmp(nim[i], nim[loop]))
                    {
                        printf("Input Nama Praktikan : ");
                        scanf(" %[^\n]s", &nama[i]);
                        printf("Input Kelas Pemrograman Dasar : ");
                        scanf(" %[^\n]s", &kelas[i]);
                        printf("Input Nama Dosen Pengampu : ");
                        scanf(" %[^\n]s", &dosen[i]);
                        i = i + 1;
                        printf("\nData Berhasil Ditambah\n\n");

                        //Di akan Pergi ke label backMenu (yang diatas tadi)
                        goto backMenu;
                    }
                }
                printf("Data Gagal Ditambah, Nim yang Anda Masukan Sudah Tersedia\n");
            }
            //Jika Tidak
            else
            {
                printf("Data Gagal Ditambah, Nim Anda Kurang atau Lebih Dari 10\n");
            }
        }

        break;

    case 2:

        //Perulangan yang dimulai dari nilai 0, diulang sebanyak variable 'i'
        for (loop = 0; loop < i; loop++)
        {
            printf("\nData Ke-%i", loop + 1);
            printf("\nNim Praktikan : %s", nim[loop]);
            printf("\nNama Praktikan : %s", nama[loop]);
            printf("\nKelas Pemrograman Dasar : %s", kelas[loop]);
            printf("\nNama Dosen Pengampu : %s\n\n", dosen[loop]);
        }
        break;

    case 3:
        printf("Masukan Nim Data yang Ingin Anda Ubah : ");
        scanf("%s", &search);

        //Perulangan yang dimulai dari nilai 0, diulang sebanyak variable 'i'
        for (loop = 0; loop < i; loop++)
        {
            //Jika variable 'search' dan 'nim[loop]' datanya sama
            if (strcmp(search, nim[loop]) == 0)
            {
                printf("Input Nama Praktikan : ");
                scanf(" %[^\n]s", &nama[loop]);
                printf("Input Kelas Pemrograman Dasar : ");
                scanf(" %[^\n]s", &kelas[loop]);
                printf("Input Nama Dosen Pengampu : ");
                scanf(" %[^\n]s", &dosen[loop]);
                printf("Data Berhasil Diubah\n");
                //Di akan Pergi ke label backMenu (yang diatas tadi)
                goto backMenu;
            }
        }
        printf("\nData Dengan Nim yang Anda Cari Tidak Ditemukan");
        break;

    case 4:
        printf("Masukan Nim Data yang Ingin Anda Hapus : ");
        scanf("%s", &search);

        //Perulangan yang dimulai dari nilai 0, diulang sebanyak variable 'i'
        for (loop = 0; loop < i; loop++)
        {
            //Jika variable 'search' dan 'nim[loop]' datanya sama
            if (strcmp(search, nim[loop]) == 0)
            {

                //Perulangan mulai dari nilai variable 'loop1', dan diulang sebanyak 'loop1 - 1'
                for (loop1 = loop; loop1 < (loop - 1); loop1++)
                {
                    //Akan Mengcopy variable 'nim[loop1+1]' ke 'nim[loop1]
                    strcpy(nim[loop1], nim[loop1 + 1]);
                    strcpy(nama[loop1], nama[loop1 + 1]);
                    strcpy(kelas[loop1], kelas[loop1 + 1]);
                    strcpy(dosen[loop1], dosen[loop1 + 1]);
                }
                //Jika Perulangan tersebut selesai, maka banyak 'i' akan dikurang satu
                i = i - 1;
                printf("Data Berhasil Dihapus\n");
                //Di akan Pergi ke label backMenu (yang diatas tadi)
                goto backMenu;
            }
        }
        printf("\nData Dengan Nim yang Anda Cari Tidak Ditemukan\n");
        break;

    case 5:
        printf("Masukan Nim Data yang Ingin Anda Cari : ");
        scanf("%s", &search);

        //Perulangan yang dimulai dari nilai 0, diulang sebanyak variable 'i'
        for (loop = 0; loop < i; loop++)
        {
            //Jika variable 'search' dan 'nim[loop]' datanya sama
            if (strcmp(search, nim[loop]) == 0)
            {
                printf("\nNim Praktikan : %s", nim[loop]);
                printf("\nNama Praktikan : %s", nama[loop]);
                printf("\nKelas Pemrograman Dasar : %s", kelas[loop]);
                printf("\nDosen Pengampu : %s\n\n", dosen[loop]);
                //Di akan Pergi ke label backMenu (yang diatas tadi)
                goto backMenu;
            }
        }
        printf("\nData Dengan Nim yang Anda Cari Tidak Ditemukan");
        break;

    case 6:
        //Di akan Pergi ke label keluar (yang dibawah)
        goto keluar;
        break;
    default:
        break;
    }
    //Di akan Pergi ke label backMenu (yang diatas tadi)
    goto backMenu;

// keluar = label untuk alur jalannya program
keluar:
    printf("Terimakasih Sudah Menggunakan Program Kami ;D");
}
