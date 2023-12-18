#include <stdio.h.
#include <string.h>

int main ()
{
    char username[50], password[50], usernameTersimpan[50], passwordTersimpan[50],
    kata[50], inputMatkul[50], inputStatus[50], inputBulan[50];

    int opsi, opsi2, opsi3, opsi4, opsi5, opsi6, nomorTugas, inputTanggal, 
    inputTahun, signInBerhasil = 0, keMenuUtama = 1;

    char konfirmasi, konfirmasi2, konfirmasi3, konfirmasi4;

    while (keMenuUtama == 1)
    {
        signInBerhasil = 0;
        printf("\n--Selamat Datang di LiSA--\n1. Sign Up\n2. Sign In\n3. Exit\nPilih Opsi: ");
        scanf("%d", &opsi);

        if (opsi == 1)
        {
            printf("Buat Username: ");
            scanf("%s", username);
            printf("Buat Password: ");
            scanf("%s", password);

            strcpy(usernameTersimpan, username);
            strcpy(passwordTersimpan, password);
            printf("\nUsername dan Password Tersimpan!\n");
        }

        else if (opsi == 2)
        {
            printf("\n--Masuk ke Akun Anda--\n");
            printf("\nMasukkan Username: ");
            scanf("%s", username);
            printf("Masukan Password: ");
            scanf("%s", password);

            while (strcmp(username, usernameTersimpan) !=0 || strcmp(password, passwordTersimpan) !=0)
            {
                printf("Data Tidak Benar, Silahkan Ulangi\n");
                printf("Masukkan Username: ");
                scanf("%s", username);
                printf("Masukkan Password: ");
                scanf("%s", password);
            }
            printf("\n"
                  "sign In berhasil!\n"
                  "              \n");
                  signInBerhasil = 1;
        }
    }
}
