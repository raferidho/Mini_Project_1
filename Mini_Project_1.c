#include <stdio.h>

// Fungsi manual untuk menghitung panjang string tanpa <string.h>
int string(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Fungsi manual untuk mengonversi huruf kecil ke kapital
char kapital(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

int main() {
    char name[50];
    char fav_food[50];
    int age;
    char id[100];

    // 1. Input Terminal (Tetap 3 input sesuai kriteria)
    printf("Masukkan Nama             : ");
    scanf("%49[^\n]", name);

    printf("Masukkan Makanan Favorit  : ");
    scanf(" %49[^\n]", fav_food); // Membaca string termasuk spasi

    printf("Masukkan Umur             : ");
    scanf("%d", &age);

    // 2. Pemrosesan Karakter Nama
    int name_len = string(name);

    // a. Huruf Pertama (Inisial)
    char first_char = kapital(name[0]);

    // b. Huruf Akhir
    char last_char = kapital(name[name_len - 1]);

    // 3. Pemrosesan Karakter Makanan Favorit
    int fav_food_len = string(fav_food);

    // c. Dua Huruf Pertama (Kombinasi Karakter 1 dan 2)
    char first_two[3];
    first_two[0] = kapital(fav_food[0]);
    if (fav_food_len >= 2) {
        first_two[1] = kapital(fav_food[1]);
    } else {
        first_two[1] = first_two[0]; // Perkondisian jika makanan favorit hanya 1 huruf
    }
    first_two[2] = '\0'; // Null terminator untuk string 2 karakter

    // 3. Operasi 1: Matematika Umur (20000 - Umur)
    int op1 = 20000 - age;

    // 4. Konkatenasi ID Menggunakan sprintf() Sesuai Urutan Baru
    // Urutan: HurufAkhir + (20000-Umur) + Umur + DuaHurufPertama + Inisial
    sprintf(id, "%c%d%d%s%c", last_char, op1, age, first_two, first_char);

    // 5. Tampilan Output
    printf("\n----------------------------------------------\n");
    printf("|                 Member  ID                 |\n");
    printf("----------------------------------------------\n");
    printf("|   ID            : %s\n", id);
    printf("|   Name          : %s\n", name);
    printf("|   Favorite Food : %s\n", fav_food);
    printf("|   Age           : %d\n", age);
    printf("----------------------------------------------\n");

    return 0;
}

/* Catatan : 

"*" adalah pointer yang digunakan untuk mengakses alamat memori dari variabel. Dalam konteks ini, digunakan untuk mengakses karakter dalam string.

"\0" adalah karakter null terminator yang menandai akhir string dalam bahasa C. 

Pake while loop karena mudah dipahami.

c-32 ASCII, Kapital 65-90, Kecil 97-122, jadi jika huruf kecil dikurangi 32 akan menjadi huruf kapital.

%49 adalah untuk membatasi input string agar tidak melebihi 49 karakter, sehingga masih ada ruang untuk null terminator.
[^\n] Scanset Spesifier, ^ kecuali (negasi), "Baca dan terima semua karakter (termasuk spasi), KECUALI tombol Enter (\n)".
" %49[^\n]" ada spasi di awal untuk mengabaikan karakter newline yang tersisa di buffer input dari input sebelumnya.

*/