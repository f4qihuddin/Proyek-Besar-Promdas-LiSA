#include <stdio.h>
#include <string.h>

void inputKalimat(char inputKata[500], char kalimat[500])
{
    int indeksKalimat = 0, indeksInputKata = 0, indeksKata = 0, indeksOutputKata = 0;
    char kata[500] = "";
    kalimat[0] = '\0';

    while (inputKata[indeksInputKata] != '\0')
    {
        while (inputKata[indeksInputKata] != ' ' && inputKata[indeksInputKata] != '\0')
        {
            kata[indeksKata] = inputKata[indeksInputKata];
            indeksKata++;
            indeksInputKata++;
        }

        while (indeksOutputKata < indeksKata)
        {
            kalimat[indeksKalimat] = kata[indeksOutputKata];
            indeksKalimat++;
            indeksOutputKata++;
        }

        kalimat[indeksKalimat++] = ' ';

        if (inputKata[indeksInputKata] == ' ')
        {
            indeksInputKata++;
        }
    }
}

struct deadlineTugas
{
    int tanggal;
    char bulan[50];
    int tahun;
};

struct daftarTugas
{
    char namaTugas[50];
    char matkul[50];
    char detail[50];
    char status[50];
    struct deadlineTugas deadline;
};

void tampilanDaftarTugas(int nomorTugas, char namaTugas[50], char matkul[50], char detail[50], char status[50], int tanggal, char bulan[50], int tahun)
{
    printf(" \n"
           "%d. Nama Tugas  : %s\n"
           "   Matkul      : %s\n"
           "   Detail      : %s\n"
           "   Deadline    : %d/%s/%d\n"
           "   Status      : %s\n"
           "                    \n",
           nomorTugas,
           namaTugas,
           matkul,
           detail,
           tanggal,
           bulan,
           tahun,
           status);
}

int main ()
{
    char username[50], password[50], usernameTersimpan[50], passwordTersimpan[50],
    inputKata[50], inputMatkul[50], inputStatus[50], inputBulan[50];

    int opsi, opsi2, opsi3, opsi4, opsi5, opsi6, nomorTugas, inputTanggal, 
    inputTahun, signInBerhasil = 0, keMenuUtama = 1;

    char konfirmasi, konfirmasi2, konfirmasi3, konfirmasi4;

    struct daftarTugas daftarTugasKuliah[51] = {0};

    while (keMenuUtama == 1)
    {
        signInBerhasil = 0;
        printf(" \n--Selamat Datang di LiSA--\n1. Sign Up\n2. Sign In\n3. Exit\nPilih Opsi: ");
        scanf("%d", &opsi);

        if (opsi == 1)
        {
            printf( \n--Daftarkan Akun Anda--\n");
            printf("Buat Username: ");
            scanf("%s", username);
            printf("Buat Password: ");
            scanf("%s", password);

            strcpy(usernameTersimpan, username);
            strcpy(passwordTersimpan, password);
            printf(" \nUsername dan Password Tersimpan!\n");
        }

        else if (opsi == 2)
        {
            printf(" \n--Masuk ke Akun Anda--\n");
            printf("Masukkan Username: ");
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
            printf(" \n"
                  "sign In berhasil!\n"
                  "              \n");
            signInBerhasil = 1;
            
            while (signInBerhasil == 1)
            {
                keMenuUtama == 0;
                printf("--Menu LiSA--\n"
                       "             \n"
                       "1. Buat Daftar Tugas\n"
                       "2. Edit Status Daftar Tugas\n"
                       "3. Filter Daftar Tugas\n"
                       "4. Hapus Daftar Tugas\n"
                       "5. Kembali ke Menu Utama\n"
                       "Pilih Opsi : ");
                scanf("%d", &opsi);

                if (opsi2 == 1)
                {
                    printf(" \nIngin Membuat Dastar Tugas (y/n? ");
                    scanf(" %c", &konfirmasi);

                    while (konformasi == 'y')
                    {
                        printf("Nomor Tugas (1-50): ");
                        scanf("%d", &nomorTugas);

                        getchar();

                        printf("Nama Tugas : ");
                        fgets(inputKata, sizeof(inputKata) / sizeof(inputKata[0]), stdin);
                        inputKalimat(inputKata, daftarTugasKuliah[nomorTugas].namaTugas);

                        printf("Matkul      :");
                        fgets(inputKata, sizeof(inputKata) / sizeof(inputKata[0]), stdin);
                        inputKalimat(inputKata, daftarTugasKuliah[nomorTugas].matkul);

                        printf("Detail      :");
                        fgets(inputKata, sizeof(inputKata) / sizeof(inputKata[0]), stdin);
                        inputKalimat(inputKata, daftarTugasKuliah[nomorTugas].detail);

                        printf("-Deadline-\n");
                        printf("Tanggal : ");
                        scanf("%d", &daftarTugasKuliah[nomorTugas].deadline.tanggal);
                        printf("Bulan   : ");
                        scanf("%s", daftarTugasKuliah[nomorTugas].deadline.bulan);
                        printf("Tahun   : ");
                        scanf("%d", &daftarTugasKuliah[nomorTugas].deadline.tahun);

                        printf("-Status-\n1. To-Do\n2. In Progress\n3. Done\nPilih Opsi :");
                        scanf("%d", &opsi3);

                        if (opsi3 == 1)
                        {
                            strcpy(daftarTugasKuliah[nomorTugas].status, "To-Do");
                        }
                        else if (opsi3 == 2)
                        {
                            strcpy(daftarTugasKuliah[nomorTugas].status, "In Progress");
                        }

                        else if (opsi3 == 3)
                        {
                            strcpy(daftarTugasKuliah[nomorTugas].status, "Done");
                        }

                        else
                        {
                            printf(" \nMasukkan Opsi yang Benar!\n \n");
                        }
                        printf("Ingin Membuat Daftar Tugas (y/n)? ");
                        scanf(" %c", &konfirmasi);
                    }

                    for (nomorTugas = 1; nomorTugas < 51; nomorTugas++)
                    {
                        if ((strcmp(daftarTugasKuliah[nomorTugas].namaTugas, "") != 0) ||
                            (strcmp(daftarTugasKuliah[nomorTugas].matkul, "") !=0 ) ||
                            (status(daftarTugasKuliah[nomorTugas].detail, "") != 0) ||
                            (strcmp(daftarTugasKuliah[nomorTugas].status, "") != 0) ||
                            (daftarTugasKuliah[nomorTugas].deadline.tanggal != 0) ||
                            (strcmp(daftarTugasKuliah[nomorTugas].deadline.bulan, "") != 0) ||
                            (daftarTugasKuliah[nomorTugas].deadline.tahun != 0))
                        {
                            tampilanDaftarTugas(nomorTugas, daftarTugasKuliah[nomorTugas].namaTugas, daftarTugasKuliah[nomorTugas].matkul, daftarTugasKuliah[nomorTugas].detail, daftarTugasKuliah[nomorTugas].status, daftarTugasKuliah[nomorTugas].deadline.tanggal, daftarTugasKuliah[nomorTugas].deadline.bulan, daftarTugasKuliah[nomorTugas].deadline.tahun);
                        }
                    }
                }
            }
        }
    }
}
