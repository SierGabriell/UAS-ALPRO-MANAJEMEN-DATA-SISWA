#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string.h>

// Struktur data untuk menyimpan informasi siswa
struct Siswa {  
    char nama[40];
    int npm;
    float rerata[5];  // Nilai rata-rata tiap mata kuliah
    float ipk;
};

// Fungsi untuk membersihkan layar
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Fungsi untuk menghitung nilai rata-rata untuk satu mata kuliah
// Rumus: ((hadir * 10 - 60) * 0.2) + (uts * 0.4) + (uas * 0.4)
float hitung_rerata(int hadir, int uts, int uas) {
    return (float)(((hadir * 10 - 60) * 0.2) + (uts * 0.4) + (uas * 0.4));
}

// Fungsi untuk mengkonversi nilai numerik ke dalam grade
char getLetterGrade(float score) {
    if(score >= 80)
        return 'A';
    else if(score >= 70)
        return 'B';
    else if(score >= 60)
        return 'C';
    else if(score >= 50)
        return 'D';
    else
        return 'E';
}

int main() {
    int brp;

    printf("PROGRAM PERHITUNGAN NILAI SISWA\n");
    printf("Berapa siswa? : ");
    scanf("%i", &brp);

    std::vector<Siswa> daftar_siswa(brp);

    // Proses input data untuk setiap siswa
    for (int i = 0; i < brp; i++) {
        Siswa siswa;

        printf("\nData Siswa ke-%d\n", i + 1);
        printf("Masukkan nama Anda: ");
        scanf(" %[^\n]", siswa.nama);  // Membaca nama yang mengandung spasi
        printf("Masukkan NPM Anda: ");
        scanf("%d", &siswa.npm);

        const char* matkul[5] = {"B Indonesia", "Algoritma", "Agama", "Diskrit", "Kalkulus"};
        for (int j = 0; j < 5; j++) {
            int hadir, uts, uas;
            printf("\nMatkul %s\n", matkul[j]);

            // Validasi input kehadiran (harus antara 1 dan 16)
            while (1) {
                printf("Masukkan banyak kehadiran Anda (1-16): ");
                scanf("%d", &hadir);
                if (hadir >= 1 && hadir <= 16) {
                    break;
                } else {
                    printf("Input tidak valid. Harap masukkan nilai antara 1 dan 16.\n");
                }
            }

            // Validasi input nilai UTS (harus antara 1 dan 100)
            while (1) {
                printf("Masukkan nilai UTS Anda (1-100): ");
                scanf("%d", &uts);
                if (uts >= 1 && uts <= 100) {
                    break;
                } else {
                    printf("Input tidak valid. Harap masukkan nilai antara 1 dan 100.\n");
                }
            }

            // Validasi input nilai UAS (harus antara 1 dan 100)
            while (1) {
                printf("Masukkan nilai UAS Anda (1-100): ");
                scanf("%d", &uas);
                if (uas >= 1 && uas <= 100) {
                    break;
                } else {
                    printf("Input tidak valid. Harap masukkan nilai antara 1 dan 100.\n");
                }
            }

            // Hitung nilai rata-rata untuk mata kuliah tersebut
            siswa.rerata[j] = hitung_rerata(hadir, uts, uas);
        }

        // Hitung IPK sebagai rata-rata dari kelima mata kuliah
        siswa.ipk = (siswa.rerata[0] + siswa.rerata[1] + siswa.rerata[2] + siswa.rerata[3] + siswa.rerata[4]) / 5;
        daftar_siswa[i] = siswa;
    }

    // Membersihkan layar sebelum menampilkan hasil
    clearScreen();

    // Menampilkan hasil nilai seluruh siswa
    printf("\nHASIL NILAI SELURUH SISWA\n");
    for (int i = 0; i < brp; i++) {
        Siswa siswa = daftar_siswa[i];

        printf("\nNama: %s\n", siswa.nama);
        printf("NPM: %d\n", siswa.npm);
        // Untuk tiap mata kuliah, tampilkan nilai rata-rata dan grade hurufnya
        printf("Rerata Matkul B Indonesia: %.2f (%c)\n", siswa.rerata[0], getLetterGrade(siswa.rerata[0]));
        printf("Rerata Matkul Algoritma: %.2f (%c)\n", siswa.rerata[1], getLetterGrade(siswa.rerata[1]));
        printf("Rerata Matkul Agama: %.2f (%c)\n", siswa.rerata[2], getLetterGrade(siswa.rerata[2]));
        printf("Rerata Matkul Diskrit: %.2f (%c)\n", siswa.rerata[3], getLetterGrade(siswa.rerata[3]));
        printf("Rerata Matkul Kalkulus: %.2f (%c)\n", siswa.rerata[4], getLetterGrade(siswa.rerata[4]));
        printf("IPK: %.2f\n", siswa.ipk);

        if (siswa.ipk > 70)
            printf("ANDA LULUS\n");
        else
            printf("ANDA TIDAK LULUS\n");
    }

    return 0;
}
