#include <stdio.h>


float hitung_rerata(int hadir, int uts, int uas) {
    return (float)((hadir * 10 * 0.2) + (uts * 0.4) + (uas * 0.4));
}

int main() {
    char nama[40];
    int npm;
    int uts, uas, hadir;
    float ipk, rerata1, rerata2, rerata3, rerata4, rerata5;
    int brp;

    printf("PROGRAM PERHITUNGAN NILAI SISWA\n");
    printf("Berapa siswa? : ");
    scanf("%i", &brp);

    for (int i = 0; i < brp; i++) {
        printf("\nData Siswa ke-%d\n", i + 1);
        printf("Masukkan nama Anda: ");
        scanf("%39s", nama); // Baca string hingga 39 karakter
        printf("Masukkan NPM Anda: ");
        scanf("%d", &npm);

        // Matkul B Indonesia
        printf("\nMatkul B Indonesia\n");
        printf("Masukkan banyak kehadiran Anda (1-10): ");
        scanf("%d", &hadir);
        printf("Masukkan nilai UTS Anda: ");
        scanf("%d", &uts);
        printf("Masukkan nilai UAS Anda: ");
        scanf("%d", &uas);
        rerata1 = hitung_rerata(hadir, uts, uas);

        // Matkul Algoritma
        printf("\nMatkul Algoritma\n");
        printf("Masukkan banyak kehadiran Anda (1-10): ");
        scanf("%d", &hadir);
        printf("Masukkan nilai UTS Anda: ");
        scanf("%d", &uts);
        printf("Masukkan nilai UAS Anda: ");
        scanf("%d", &uas);
        rerata2 = hitung_rerata(hadir, uts, uas);

        // Matkul Agama
        printf("\nMatkul Agama\n");
        printf("Masukkan banyak kehadiran Anda (1-10): ");
        scanf("%d", &hadir);
        printf("Masukkan nilai UTS Anda: ");
        scanf("%d", &uts);
        printf("Masukkan nilai UAS Anda: ");
        scanf("%d", &uas);
        rerata3 = hitung_rerata(hadir, uts, uas);

        // Matkul Diskrit
        printf("\nMatkul Diskrit\n");
        printf("Masukkan banyak kehadiran Anda (1-10): ");
        scanf("%d", &hadir);
        printf("Masukkan nilai UTS Anda: ");
        scanf("%d", &uts);
        printf("Masukkan nilai UAS Anda: ");
        scanf("%d", &uas);
        rerata4 = hitung_rerata(hadir, uts, uas);

        // Matkul Kalkulus
        printf("\nMatkul Kalkulus\n");
        printf("Masukkan banyak kehadiran Anda (1-10): ");
        scanf("%d", &hadir);
        printf("Masukkan nilai UTS Anda: ");
        scanf("%d", &uts);
        printf("Masukkan nilai UAS Anda: ");
        scanf("%d", &uas);
        rerata5 = hitung_rerata(hadir, uts, uas);
        
    

        // Output hasil
        printf("\nNama: %s\n", nama);
        printf("NPM: %d\n", npm);
        printf("Rerata Matkul B Indonesia Anda: %.2f\n", rerata1);
        printf("Rerata Matkul Algoritma Anda: %.2f\n", rerata2);
        printf("Rerata Matkul Agama Anda: %.2f\n", rerata3);
        printf("Rerata Matkul Diskrit Anda: %.2f\n", rerata4);
        printf("Rerata Matkul Kalkulus Anda: %.2f\n", rerata5);
        
        ipk = (rerata1 + rerata2 + rerata3 + rerata4 + rerata5) / 5;
        printf("IPK Anda: %.2f\n", ipk);
        
        if (ipk > 70)
            printf("ANDA LULUS\n");
        else 
            printf("ANDA TIDAK LULUS\n");
    }

    return 0;
}