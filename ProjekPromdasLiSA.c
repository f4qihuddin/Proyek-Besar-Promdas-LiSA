#include <stdio.h>
#include <string.h>

void inputKalimat(char inputKata[500])
{
    size_t len = strlen(inputKata);
    if (len > 0 && inputKata[len - 1] == '\n')
    {
        inputKata[len - 1] = '\0';
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
    char namaTugas[500];
    char matkul[500];
    char detail[500];
    char status[50];
    struct deadlineTugas deadline;
};

void tampilanDaftarTugas(int nomorTugas, char namaTugas[500], char matkul[500], char detail[500], char status[50], int tanggal, char bulan[50], int tahun)
{
    if ((strcmp(namaTugas, "") != 0) ||
        (strcmp(matkul, "") != 0) ||
        (strcmp(detail, "") != 0) ||
        (strcmp(status, "") != 0) ||
        (tanggal != 0) ||
        (strcmp(bulan, "") != 0) ||
        (tahun != 0))
    {
        printf(" \n"
               "%d. Nama Tugas  : %s\n \n"
               "   Matkul      : %s\n \n"
               "   Detail      : %s\n \n"
               "   Deadline    : %d/%s/%d\n \n"
               "   Status      : %s\n"
               " \n",
               nomorTugas,
               namaTugas,
               matkul,
               detail,
               tanggal,
               bulan,
               tahun,
               status);
    }
}

int keMenuLisa(char konfirmasi5)
{
    if (konfirmasi5 == 'y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int keMenuFilter(char konfirmasi6)
{
    if (konfirmasi6 == 'y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main ()
{
    char username[50], password[50], usernameTersimpan[50] = "", passwordTersimpan[50] = "", inputKata[500], inputMatkul[500], inputStatus[50], inputBulan[50];
    int opsi, opsi2, opsi3, opsi4, opsi5, opsi6, nomorTugas, inputTanggal, inputTahun, sigInBerhasil = 0, keMenuUtama = 1, menuLisa = 0, menuFilter = 0, menuStatus = 0, menuDeadline = 0;
    char konfirmasi, konfirmasi2, konfirmasi3, konfirmasi4, konfirmasi5, konfirmasi6, konfirmasi7;

    struct daftarTugas daftarTugasKuliah[51] = {0};

    while (keMenuUtama == 1)
    {
        signInBerhasil = 0;
        printf(" \n--Selamat Datang di LiSA--\n \n1. Sign In\n3. Exit\nPilih Opsi: ");
        scanf("%d", &opsi);

        if (opsi == 1)
        {
            printf(" \n--Daftarkan Akun Anda--\n \n");
            printf("Buat Username : ");
            scanf("%s", username);
            printf("Buat Password : ");
            scanf("%s", password);

            strcpy(usernameTersimpan, username);
            strcpy(passwordTersimpan, password);
            printf("\nUsername dan Password Tersimpan!\n");
        }

        else if (opsi == 2) 
        {
            printf(" \n--Masuk ke Akun Anda--\n \n");
            printf("Masukkan Username : ");
            scanf("%s", username);
            printf("Masukkan Password : ");
            scanf("%s", password);

            if (strcmp(usernameTersimpan, "") == 0 && strcmp(passwordTersimpan, "") == 0)
            {
                printf(" \nSign Up Terlebih Dahulu!\n");
            }
            else
            {
                while (strcmp(username, usernameTersimpan) != 0 || strcmp(password, passwordTersimpan) != 0)
                {
                    printf("Data Tidak Benar, Silahkan Ulangi!\n");
                    print("Masukkan Username ! ");
                    scanf("%s", username);
                    printf("Masukkan Password : ");
                    scanf("%s", password);
                }
                printf(" \n"
                       "Sign In Berhasil!\n");
                signInBerhasil = 1;
            }

            while (signInBerhasil == 1)
            {
                keMenuUtama=0;
                menuLisa = 0;
                printf(" \n--Menu LiSA--\n"
                       "             \n"
                       "1. Buat Daftar Tugas\n"
                       "2. Edit Status Daftar Tugas\n"
                       "3. Filter Daftar Tugas\n"
                       "4. Hapus Daftar Tugas\n"
                       "5. Tampilkan Daftar Tugas\n"
                       "6. Kembali ke Menu Utama\n"
                       "Pilih OPsi : ");
                scanf("%d", &opsi2);
                 if (opsi2 == 1)
                {
                    while (menuLisa = 0)
                    {
                        printf(" \nIngin membuat daftar tugas (y/t)? ");
                        scanf(" %c", &konfirmasi);

                        if (konfirmasi != 'y')
                        {
                            menuLisa = 1;
                        }

                        while (konfirmasi == 'y')
                        {
                            prinf("Nomor Tugas (1-50): ");
                            scanf("%d", &nomorTugas);

                            getchar();

                            prinf("Nama Tugas : ");
                            fgets(inputKata, sizeof(inputKata) / sizeof(inputKata[0]), stdin);
                            inputKalimat(inputKata);
                            strcpy(daftarTugasKuliah[nomorTugas].namaTugas, inputKata);

                            prinf("Matkul : ");
                            fgets(inputKata, sizeof(inputKata) / sizeof(inputKata[0]), stdin);
                            inputKalimat(inputKata);
                            strcpy(daftarTugasKuliah[nomorTugas].matkul, inputKata);

                            prinf("Detail : ");
                            fgets(inputKata, sizeof(inputKata) / sizeof(inputKata[0]), stdin);
                            inputKalimat(inputKata);
                            strcpy(daftarTugasKuliah[nomorTugas].detail, inputKata);

                            printf("-Deadline-\n");
                            printf("Tanggal : ");
                            scanf("%d", &daftarTugaskuliah[nomorTugas].deadline.tanggal);
                            printf("Bulan : ");
                            scanf("%d", &daftarTugaskuliah[nomorTugas].deadline.bulan);
                            printf("Tahun : ");
                            scanf("%d", &daftarTugaskuliah[nomorTugas].deadline.tahun);

                            menuStatus = 0;
                            while (menuStatus == 0)
                            {
                                print("-Status-\n1. To-Do\n2. In Progress\n3. Done\nPilih Opsi ");
                                scanf("%d", &opsi3);

                                if (opsi3 == 1)
                                {
                                    strcpy(daftarTugasKuliah[nomorTugas].status, "To-Do");
                                    menuStatus =
                                }

                                else if ( opsi3 == 2)
                                {
                                    strcpy(daftarTugasKuliah[nomorTugas].status, "In Progress");
                                    menuStatus = 1;
                                }

                                else
                                {
                                    printf(" \nMasukkan Opsi yang Benar!\n \n");
                                }
                            }

                            print("Ingin Membuat Daftar Tugas Lagi (y/t)? ");
                            scanf(" &c", &konfirmasi);
                        }
                        while (menuLisa == 0)
                        {
                            prinf(" \n------------------------- DAFTAR TUGAS -------------------------------\n");
                            for (nomorTugas = 1; nomorTugas <51; nomorTugas)
                            {
                                tampilanDaftarTugas(nomorTugas, daftarTugasKuliah[nomorTugas], daftarTugasKuliah[nomorTugas].matkul, daftarTugasKuliah[nomorTugas].detail, daftarTugasKuliah[nomorTugas].status, daftarTugasKuliah[nomorTugas].deadline.tanggal, daftarTugasKuliah[nomorTugas].deadline.bulan, daftarTugasKuliah[nomorTugas].deadline.tahun);
                            }
                            printf("----------------------------------------------------------------------\n");
                            printf(" \nKembali ke Menu LiSA (y/t)? ");
                            scanf(" %c", &konfirmasi5);
                            menuLisa = keMenuLisa(konfirmasi5);
                        }
                    }
                }
            else if (opsi2 == 2)
                {
                    while (menuLisa == 0)
                    {
                        printf(" \nIngin Mengedit Status Daftar Tugas (y/t)? ");
                        scanf(" %c", &konfirmasi2);

                        if (konfirmasi2 != 'y')
                        {
                            menuLisa = 1;
                        }

                        while (konfirmasi2 == 'y')
                        {
                            printf(" \nNomor Tugas: ");
                            scanf("%d", &nomorTugas);

                            menuStatus = 0;
                            while (menuStatus == 0)
                            {
                                printf(" \n-Status-\n1. To-Do\n2. In Progress\n3. Done\nPilih Opsi :");
                                scanf("%d", &opsi3);

                                if (opsi3 == 1)
                                {
                                    strcpy(daftarTugasKuliah[nomorTugas].status, "To-Do");
                                    menuStatus = 1;
                                }

                                else if (opsi3 == 2)
                                {
                                    strcpy(daftarTugasKuliah[nomorTugas].status, "In Progress");
                                    menuStatus = 1;
                                }

                                else if (opsi3 == 3)
                                {
                                    strcpy(daftarTugasKuliah[nomorTugas].status, "Done");
                                    menuStatus = 1;
                                }

                                else
                                {
                                    printf(" \nMasukkan Opsi yang Benar!\n");
                                }
                            }

                            printf(" \nIngin Mengedit Status Daftar Tugas Lagi (y/t)? ");
                            scanf(" %c", &konfirmasi2);
                        }

                        while (menuLisa == 0)
                        {
                            printf(" \n------------------------- DAFTAR TUGAS -------------------------------\n");
                            for (nomorTugas = 1; nomorTugas < 51; nomorTugas++)
                            {
                                tampilanDaftarTugas(nomorTugas, daftarTugasKuliah[nomorTugas].namaTugas, daftarTugasKuliah[nomorTugas].matkul, daftarTugasKuliah[nomorTugas].detail, daftarTugasKuliah[nomorTugas].status, daftarTugasKuliah[nomorTugas].deadline.tanggal, daftarTugasKuliah[nomorTugas].deadline.bulan, daftarTugasKuliah[nomorTugas].deadline.tahun);
                            }
                            printf("----------------------------------------------------------------------\n");
                            printf(" \nKembali ke Menu LiSA (y/t)? ");
                            scanf(" %c", &konfirmasi5);
                            menuLisa = keMenuLisa(konfirmasi5);
                        }
                    }
                }
                else if (opsi2 == 3)
                {
                    while (menuLisa == 0)
                    {
                        printf(" \nIngin Mem-filter Daftar Tugas (y/t)? ");
                        scanf(" %c", &konfirmasi3);

                        if (konfirmasi3 != 'y')
                        {
                            menuLisa = 1;
                        }

                        while (konfirmasi3 == 'y')
                        {
                            menuFilter = 0;
                            printf(" \nFilter Berdasarkan:\n1. Matkul\n2. Status Tugas\n3. Deadline\n4. Kembali ke Menu LiSA\nPilih Opsi : ");
                            scanf("%d", &opsi4);
                            getchar();

                            if (opsi4 == 1)
                            {
                                printf(" \nMatkul: ");
                                fgets(inputKata, sizeof(inputKata) / sizeof(inputKata[0]), stdin);
                                inputKalimat(inputKata);
                                strcpy(inputMatkul, inputKata);

                                while (menuFilter == 0)
                                {
                                    printf(" \n------------------------- DAFTAR TUGAS -------------------------------\n");
                                    for (nomorTugas = 1; nomorTugas < 51; nomorTugas++)
                                    {
                                        if (strcmp(daftarTugasKuliah[nomorTugas].matkul, inputMatkul) == 0)
                                        {
                                            tampilanDaftarTugas(nomorTugas, daftarTugasKuliah[nomorTugas].namaTugas, daftarTugasKuliah[nomorTugas].matkul, daftarTugasKuliah[nomorTugas].detail, daftarTugasKuliah[nomorTugas].status, daftarTugasKuliah[nomorTugas].deadline.tanggal, daftarTugasKuliah[nomorTugas].deadline.bulan, daftarTugasKuliah[nomorTugas].deadline.tahun);
                                        }
                                    }
                                    printf("----------------------------------------------------------------------\n");
                                    printf(" \nKembali ke Menu Filter (y/t)? ");
                                    scanf(" %c", &konfirmasi6);
                                    menuFilter = keMenuFilter(konfirmasi6);
                                }
                            }
                        else if (opsi4 == 2)
                        {
                            printf(" \nStatus Tugas :\n1. To-Do\n2. In Progress\n3. Done\nPilih Opsi :");
                            scanf("%d", &opsi5);

                            if (opsi5 == 1)
                            {
                                for (nomorTugas = 1; nomorTugas < 51; nomorTugas++)
                                {
                                    if (strcmp(daftarTugasKuliah[nomorTugas].status, "To-Do") == 0)
                                    {
                                        if ((strcmp(daftarTugasKuliah[nomorTugas].namaTugas, "") != 0) ||
                                            (strcmp(daftarTugasKuliah[nomorTugas].matkul, "") != 0) ||
                                            (strcmp(daftarTugasKuliah[nomorTugas].detail, "") != 0) ||
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

                            else if (opsi5 == 2)
                            {
                                for (nomorTugas = 1; nomorTugas < 51; nomorTugas++)
                                {
                                    if (strcmp(daftarTugasKuliah[nomorTugas].status, "In Progress") == 0)
                                    {
                                        if ((strcmp(daftarTugasKuliah[nomorTugas].namaTugas, "") != 0) ||
                                            (strcmp(daftarTugasKuliah[nomorTugas].matkul, "") != 0) ||
                                            (strcmp(daftarTugasKuliah[nomorTugas].detail, "") != 0) ||
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
                            else if (opsi5 == 3)
                            {
                                for (nomorTugas = 1; nomorTugas < 51; nomorTugas++)
                                {
                                    if (strcmp(daftarTugasKuliah[nomorTugas].status, "Done") == 0)
                                    {
                                        if ((strcmp(daftarTugasKuliah[nomorTugas].namaTugas, "") != 0) ||
                                            (strcmp(daftarTugasKuliah[nomorTugas].matkul, "") != 0) ||
                                            (strcmp(daftarTugasKuliah[nomorTugas].detail, "") != 0) ||
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

                            else
                            {
                                printf(" \nMasukkan Opsi yang Benar!\n \n");
                            }
                        }

                        else if (opsi4 == 3)
                        {
                            printf(" \nDeadline :\n1. Tanggal\n2. Bulan\n3. Tahun\n4. Tanggal/Bulan/Tahun\nPilih Opsi :");
                            scanf("%d", &opsi6);

                            if (opsi6 == 1)
                            {
                                printf("Tanggal : ");
                                scanf("%d", &inputTanggal);

                                for (nomorTugas = 1; nomorTugas < 51; nomorTugas++)
                                {
                                    if (daftarTugasKuliah[nomorTugas].deadline.tanggal == inputTanggal)
                                    {
                                        if ((strcmp(daftarTugasKuliah[nomorTugas].namaTugas, "") != 0) ||
                                            (strcmp(daftarTugasKuliah[nomorTugas].matkul, "") != 0) ||
                                            (strcmp(daftarTugasKuliah[nomorTugas].detail, "") != 0) ||
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

                            else if (opsi6 == 2)
                            {
                                printf("Bulan : ");
                                scanf("%s", inputBulan);

                                for (nomorTugas = 1; nomorTugas < 51; nomorTugas++)
                                {
                                    if (strcmp(daftarTugasKuliah[nomorTugas].deadline.bulan, inputBulan) == 0)
                                    {
                                        if ((strcmp(daftarTugasKuliah[nomorTugas].namaTugas, "") != 0) ||
                                            (strcmp(daftarTugasKuliah[nomorTugas].matkul, "") != 0) ||
                                            (strcmp(daftarTugasKuliah[nomorTugas].detail, "") != 0) ||
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

 else if (opsi6 == 3)
                            {
                                printf("Tahun : ");
                                scanf("%d", &inputTahun);

                                for (nomorTugas = 1; nomorTugas < 51; nomorTugas++)
                                {
                                    if (daftarTugasKuliah[nomorTugas].deadline.tahun == inputTahun)
                                    {
                                        if ((strcmp(daftarTugasKuliah[nomorTugas].namaTugas, "") != 0) ||
                                            (strcmp(daftarTugasKuliah[nomorTugas].matkul, "") != 0) ||
                                            (strcmp(daftarTugasKuliah[nomorTugas].detail, "") != 0) ||
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

                            else if (opsi6 == 4)
                            {
                                printf("Tanggal : ");
                                scanf("%d", &inputTanggal);
                                printf("Bulan   : ");
                                scanf("%s", inputBulan);
                                printf("Tahun   : ");
                                scanf("%d", &inputTahun);

                                for (nomorTugas = 1; nomorTugas < 51; nomorTugas++)
                                {
                                    if ((daftarTugasKuliah[nomorTugas].deadline.tanggal == inputTanggal) && (strcmp(daftarTugasKuliah[nomorTugas].deadline.bulan, inputBulan) == 0) && (daftarTugasKuliah[nomorTugas].deadline.tahun == inputTahun))
                                    {
                                        if ((strcmp(daftarTugasKuliah[nomorTugas].namaTugas, "") != 0) ||
                                            (strcmp(daftarTugasKuliah[nomorTugas].matkul, "") != 0) ||
                                            (strcmp(daftarTugasKuliah[nomorTugas].detail, "") != 0) ||
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

                            else
                            {
                                printf(" \nMasukkan Opsi yang Benar!\n \n");
                            }
                        }

                        else if (opsi4 == 4)
                        {
                            break;
                        }

                        else
                        {
                            printf(" \nMasukkan Opsi yang Benar!\n \n");
                        }
                    }
                }

                else if (opsi2 == 4)
                {
                    printf(" \nIngin Menghapus Daftar Tugas (y/n)? ");
                    scanf(" %c", &konfirmasi4);

                    while (konfirmasi4 == 'y')
                    {
                        printf("Nomor Tugas: ");
                        scanf("%d", &nomorTugas);

                        strcpy(daftarTugasKuliah[nomorTugas].namaTugas, "");
                        strcpy(daftarTugasKuliah[nomorTugas].matkul, "");
                        strcpy(daftarTugasKuliah[nomorTugas].detail, "");
                        strcpy(daftarTugasKuliah[nomorTugas].status, "");
                        strcpy(daftarTugasKuliah[nomorTugas].deadline.bulan, "");
                        daftarTugasKuliah[nomorTugas].deadline.tanggal = 0;
                        daftarTugasKuliah[nomorTugas].deadline.tahun = 0;

                        printf(" \nIngin Menghapus Daftar Tugas (y/n)? ");
                        scanf(" %c", &konfirmasi4);
                    }

                    for (nomorTugas = 1; nomorTugas < 51; nomorTugas++)
                    {
                        if ((strcmp(daftarTugasKuliah[nomorTugas].namaTugas, "") != 0) ||
                            (strcmp(daftarTugasKuliah[nomorTugas].matkul, "") != 0) ||
                            (strcmp(daftarTugasKuliah[nomorTugas].detail, "") != 0) ||
                            (strcmp(daftarTugasKuliah[nomorTugas].status, "") != 0) ||
                            (daftarTugasKuliah[nomorTugas].deadline.tanggal != 0) ||
                            (strcmp(daftarTugasKuliah[nomorTugas].deadline.bulan, "") != 0) ||
                            (daftarTugasKuliah[nomorTugas].deadline.tahun != 0))
                        {
                            tampilanDaftarTugas(nomorTugas, daftarTugasKuliah[nomorTugas].namaTugas, daftarTugasKuliah[nomorTugas].matkul, daftarTugasKuliah[nomorTugas].detail, daftarTugasKuliah[nomorTugas].status, daftarTugasKuliah[nomorTugas].deadline.tanggal, daftarTugasKuliah[nomorTugas].deadline.bulan, daftarTugasKuliah[nomorTugas].deadline.tahun);
                        }
                    }
                }

                else if (opsi2 == 5)
                {
                    keMenuUtama = 1;
                    break;
                }

                else
                {
                    printf(" \nMasukkan Opsi yang Benar!\n \n");
                }
            }
        }

        else if (opsi == 3)
        {
            break;
        }

        else
        {
            printf(" \nMasukkan Opsi yang Benar!\n");
        }
    }
    return 0;
}
