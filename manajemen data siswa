#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string.h>

struct Siswa {
    char nama[40];
    int npm;
    float rerata[5];
    float ipk;
};

float hitung_rerata(int hadir, int uts, int uas) {
    return (float)((hadir * 10 * 0.2) + (uts * 0.4) + (uas * 0.4));
}

int main() {
    int brp;

    printf("PROGRAM PERHITUNGAN NILAI SISWA\n");
    printf("Berapa siswa? : ");
    scanf("%i", &brp);

    std::vector<Siswa> daftar_siswa(brp);

    for (int i = 0; i < brp; i++) {
        Siswa siswa;

        printf("\nData Siswa ke-%d\n", i + 1);
        printf("Masukkan nama Anda: ");
        scanf("%39s", siswa.nama); // Baca string hingga 39 karakter
        printf("Masukkan NPM Anda: ");
        scanf("%d", &siswa.npm);

        const char* matkul[5] = {"B Indonesia", "Algoritma", "Agama", "Diskrit", "Kalkulus"};
        for (int j = 0; j < 5; j++) {
            int hadir, uts, uas;
            printf("\nMatkul %s\n", matkul[j]);
            printf("Masukkan banyak kehadiran Anda (1-10): ");
            scanf("%d", &hadir);
            printf("Masukkan nilai UTS Anda: ");
            scanf("%d", &uts);
            printf("Masukkan nilai UAS Anda: ");
            scanf("%d", &uas);

            siswa.rerata[j] = hitung_rerata(hadir, uts, uas);
        }

        siswa.ipk = (siswa.rerata[0  ] + siswa.rerata[1] + siswa.rerata[2] + siswa.rerata[3] + siswa.rerata[4]) / 5;
        daftar_siswa[i] = siswa;

        system("cls");
    }

    printf("\nHASIL NILAI SELURUH SISWA\n");
    for (int i = 0; i < brp; i++) {
        Siswa siswa = daftar_siswa[i];

        printf("\nNama: %s\n", siswa.nama);
        printf("NPM: %d\n", siswa.npm);
        printf("Rerata Matkul B Indonesia Anda: %.2f\n", siswa.rerata[0]);
        printf("Rerata Matkul Algoritma Anda: %.2f\n", siswa.rerata[1]);
        printf("Rerata Matkul Agama Anda: %.2f\n", siswa.rerata[2]);
        printf("Rerata Matkul Diskrit Anda: %.2f\n", siswa.rerata[3]);
        printf("Rerata Matkul Kalkulus Anda: %.2f\n", siswa.rerata[4]);
        printf("IPK Anda: %.2f\n", siswa.ipk);

        if (siswa.ipk > 70)
            printf("ANDA LULUS\n");
        else
            printf("ANDA TIDAK LULUS\n");
    }

    return 0;
}
