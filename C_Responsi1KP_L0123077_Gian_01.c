// M. Maulana Gian Pranaja
// L0123077
// Kelas C

// library yg digunakan
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Scope
char name[100];
int pilihanserangan;

// struktur karakter
typedef struct
{
    int nama;
    int maxhealth;
    int currenthealth;
    int attack;
    int defense;
    int mana;
    int maxmana;
    int currentmana;
} karakter;

// struktur item inventory
typedef struct
{
    char nama[100];
    char deskripsi[100];
    int jenis;
    int power;
} Item;

void gunakanItem(Item *inventory, int *jumlahItem, karakter *karakter, int indeks)
{
    if (indeks >= 0 && indeks < *jumlahItem)
    {
        // Proses efek item pada karakter
        switch (inventory[indeks].jenis)
        {
        case 1: // HP Potion
            karakter->currenthealth += inventory[indeks].power;
            printf("%s menggunakan %s dan memulihkan %d HP!\n", karakter->nama, inventory[indeks].nama, inventory[indeks].power);
            break;
        case 2: // Mana Potion
            karakter->currentmana += inventory[indeks].power;
            printf("%s menggunakan %s dan memulihkan %d Mana!\n", karakter->nama, inventory[indeks].nama, inventory[indeks].power);
            break;
        case 3:
            karakter->currenthealth += inventory[indeks].power;
            printf("%s menggunakan %s dan memulihkan %d HP!\n", karakter->nama, inventory[indeks].nama, inventory[indeks].power);
            break;
        case 4:
            karakter->currentmana += inventory[indeks].power;
            printf("%s menggunakan %s dan memulihkan %d Mana!\n", karakter->nama, inventory[indeks].nama, inventory[indeks].power);
            break;
        case 5:
            karakter->currenthealth += inventory[indeks].power;
            printf("%s menggunakan %s dan memulihkan %d HP!\n", karakter->nama, inventory[indeks].nama, inventory[indeks].power);
            break;
        // Tambahkan jenis item dan efek lain sesuai kebutuhan
        default:
            printf("Item tidak dapat digunakan.\n");
        }

        // Hapus item dari inventory setelah digunakan
        for (int i = indeks; i < *jumlahItem - 1; i++)
        {
            inventory[i] = inventory[i + 1];
        }

        (*jumlahItem)--;
    }
    else
    {
        printf("Indeks item tidak valid.\n");
    }
}

// menu inventory
void tampilkanInventory(Item *inventory, int jumlahItem)
{
    printf("=== Inventory ===\n");
    for (int i = 0; i < jumlahItem; i++)
    {
        printf("%d. %s - %s\n", i + 1, inventory[i].nama, inventory[i].deskripsi);
    }
}

// fungsi HP bar player
void HP(int currentHealth, int maxHealth)
{
    int barLength = 20; // Panjang total health bar
    int barFill = (int)((double)currentHealth / maxHealth * barLength);

    printf("HP kamu: [");
    for (int i = 0; i < barLength; i++)
    {
        if (i < barFill)
        {
            printf("=");
        }
        else
        {
            printf("-");
        }
    }
    printf("] %d/%d\n", currentHealth, maxHealth);
}

// fungsi mana player
void playermana(int currentmana, int maxmana)
{
    int barlength = 20;
    int barfill = (int)((double)currentmana / maxmana * barlength);

    printf("Mana mu: [");
    for (int i = 0; i < barlength; i++)
    {
        if (i < barfill)
        {
            printf("/");
        }
        else
        {
            printf("-");
        }
    }
    printf("] %d/%d\n", currentmana, maxmana);
}

// fungsi recovery hp dan mna player
void recoverHP(karakter *karakter, int recoveryhp)
{
    karakter->currenthealth += recoveryhp;

    // Pastikan tidak melebihi maksimum
    if (karakter->currenthealth > karakter->maxhealth)
    {
        karakter->currenthealth = karakter->maxhealth;
    }
}

void recoverMana(karakter *karakter, int recoverymana)
{
    karakter->currentmana += recoverymana;

    // Pastikan tidak melebihi maksimum
    if (karakter->currentmana > karakter->maxmana)
    {
        karakter->currentmana = karakter->maxmana;
    }
}

// sistem loading ke game
void loading1()
{
    int l;
    printf("Mulai Permainan : ");
    for (l = 0; l < 20; l++)
    {
        printf("=");
        fflush(stdout);
        Sleep(200);
    }
}

void loading2()
{
    int l;
    printf("Memuat : ");
    for (l = 0; l < 20; l++)
    {
        printf("=");
        fflush(stdout);
        Sleep(300);
    }
}

// menu game
void menu()
{
    printf("====================================================\n");
    printf("|%10s %s %19s|\n", " ", "The Rise Of a Slime", " ");
    printf("|%10s %s %30s|\n", " ", "1. start", " ");
    printf("|%10s %s %31s|\n", " ", "2. exit", " ");
    printf("====================================================\n");
}

// cerita
void story1()
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%1s %s", " ", "kamu adalah sebuah slime yang spawn di dalam dungeon\n", " ");
    printf("%1s %s", " ", "Tugas mu adalah keluar dari sini dan bertahan hidup\n", " ");
    printf("%1s %s", " ", "Atau kamu bisa saja menaklukan dungeon ini\n");
    printf("%1s %s", " ", "Jika kamu BISA\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void story2()
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%1s %s", " ", "setelah menyerang pion, kamu mendapatkan inventory dan sebuah skill\n");
    printf("%1s %s", " ", "itu akan sangat berguna dalam pertarungan kedepan nantinya =(0u0)=.\n");
    printf("%1s %s", " ", "ingat, setiap menyerang dengan menggunakan skill akan mengurangi mana\n");
    printf("%1s %s", " ", "item yg ada di inventory hanya bisa dipakai sekali. setiap giliranmu \n");
    printf("%1s %s", " ", "menyerang, akan memulihkan mana sebesar +15, HP = +5.\n");
    printf("%1s %s", " ", "HP dan Mana kamu tidak bisa melebihi dari MAX yang tersedia\n");
    printf("%1s %s", " ", "Jadi, kamu harus lebih berhati hati dalam menggunakannya\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void story3()
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%1s %s", " ", "kamu mulai menaiki tangga menuju lantai selanjutnya\n");
    printf("%1s %s", " ", "saat sampai dilantai selanjutnya, kamu tampak diam sejenak\n");
    printf("%1s %s", " ", "bengong, bingung, sambil melihat bentuk monster lantai ini\n");
    printf("%1s %s", " ", "seperti familiar bentuknya.....?\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void story4()
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%1s %s", " ", "kamu kaget, mengapa bisa ada tank didalam dungeon ini\n");
    printf("%1s %s", " ", "kamu sudah sangat lelah, kamu mengeluh karena kamu spawn\n");
    printf("%1s %s", " ", "dengan bentuk slime, otakmu mulai tidak bisa berfikir positif\n");
    printf("%1s %s", " ", "kamu mulai berfikir yg aneh aneh tetapi tidak ada waktu\n");
    printf("%1s %s", " ", "kalahkan tank dan keluar dari sini\n");
    printf("%1s %s", " ", "atau mati disini, tdk ada jalan keluar\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void story5()
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%1s %s", " ", "kamu berhasil mengalahkan boss lantai tersebut, tetapi kamu\n");
    printf("%1s %s", " ", "seketika tak bisa bergerak beberapa saat, badanmu sudah tak\n");
    printf("%1s %s", " ", "kuat menahan beban, tiba tiba muncul cahaya didepan mu dan\n");
    printf("%1s %s", " ", "membentuk sebuah pintu. lalu kamu berusaha meraihnya secara\n");
    printf("%1s %s", " ", "perlahan.......\n");
    printf("%1s %s", " ", "lalu...........\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void storyending()
{
    printf("%1s %s", " ", "kamu terbangun dalam mimpimu yg indah. kamu tidur\n");
    printf("%1s %s", " ", "seharian sehabis kuliah karena sangat lelah\n");
    printf("%1s %s", " ", "lalu kamu melanjutkan tugas Konsep Pemrogramanmu\n");
    printf("%1s %s", " ", "ternyata itu semua hanyalah mimpi.\n");
    printf("%1s %s", " ", "\n");
    printf("%1s %s", " ", "\n");
    printf("%1s %s", " ", "Jika kamu ingin bermimpi, tidurlah\n");
    printf("%1s %s", " ", "Jika kamu ingin meraih mimpi, bangunlah\n");
    printf("%1s %s", " ", " /_____  /\n");
    printf("%1s %s", " ", "/(`0u0`)/\n");
    printf("%1s %s", " ", " (_____)\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("=== Find ===\n");
}

// tag name
void intro()
{
    int age;
    printf("enter your name : ");
    scanf("%s", &name);
    printf("enter your age  : ");
    scanf("%d", &age);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("===================================================\n");
    printf("%20s %s %20s \n", " ", "PROFILE", " ");
    printf("Nama : %s\n", name);
    printf("Umur : %d\n", age);
    printf("%19s %s %18s \n", " ", "AS a Slime", " ");
    printf("===================================================\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

// gambar musuh
void lantai1()
{
    printf("\n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                     i0i            \n");
    printf("  @                                  [0]            \n");
    printf("====================================================\n");
}

void lantai2()
{
    printf("\n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                    _8___           \n");
    printf("                                   / () |           \n");
    printf("                                  / _()_|           \n");
    printf("  @                                 T  T            \n");
    printf("====================================================\n");
}

void lantai3()
{
    printf("\n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                         /)___/)    \n");
    printf("                                         (= -.-=)   \n");
    printf("  @                                      (`)__(`)   \n");
    printf("====================================================\n");
}

void lantai4()
{
    printf("\n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                             / /'._   /)_/)   _.'/ /\n");
    printf("  @                          |.''._'--(o.o)--'_.''.|\n");
    printf("====================================================\n");
}

void lantai5()
{
    printf("\n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                         ~~------------[]#########  \n");
    printf("                            _____;;;;;;[][]//09     \n");
    printf("                            [][][][][][][][][][][]  \n");
    printf("  @                         0000000000000000000000  \n");
    printf("====================================================\n");
}

// fungsi serang dan skill
void menuskill()
{
    printf("=================\n");
    printf("1. serang \n2. fireball (-25 Mana) \n3. beam (-40 Mana) \n4. explooosion (-70 Mana) \n5. gunakan item \n6. bertahan \nuse : ");
}

void attack(karakter *penyerang, karakter *bertahan)
{
    int damage = penyerang->attack - bertahan->defense;
    if (damage > 0)
    {
        bertahan->currenthealth -= damage;
        printf("%s deals %d damage to %s \n", penyerang->nama, damage, bertahan->nama);
    }
    else
    {
        printf("%s`s attack has no effect on %s!\n", penyerang->nama, bertahan->nama);
    }
}

void skill1(karakter *penyerang, karakter *bertahan)
{
    int dmgskill1 = rand() % 50 + 40;
    int damage = dmgskill1 - bertahan->defense;
    if (damage > 0)
    {
        bertahan->currenthealth -= damage;
        printf("%s deals %d damage to %s \n", penyerang->nama, damage, bertahan->nama);
    }
    else
    {
        printf("%s`s attack has no effect on %s|", penyerang->nama, bertahan->nama);
    }
}

void skill2(karakter *penyerang, karakter *bertahan)
{
    int dmgskill1 = rand() % 80 + 55;
    int damage = dmgskill1 - bertahan->defense;
    if (damage > 0)
    {
        bertahan->currenthealth -= damage;
        printf("%s deals %d damage to %s \n", penyerang->nama, damage, bertahan->nama);
    }
    else
    {
        printf("%s`s attack has no effect on %s", penyerang->nama, bertahan->nama);
    }
}

void skill3(karakter *penyerang, karakter *bertahan)
{
    int dmgskill1 = rand() % 110 + 75;
    int damage = dmgskill1 - bertahan->defense;
    if (damage > 0)
    {
        bertahan->currenthealth -= damage;
        printf("%s deals %d damage to %s \n", penyerang->nama, damage, bertahan->nama);
    }
    else
    {
        printf("%s`s attack has no effect on %s|", penyerang->nama, bertahan->nama);
    }
}

// main int
int main()
{
    int score = 0;
    int pil = 0;
    menu();
    while (pil != 2)
    {
        printf(" : ");
        scanf("%d", &pil);
        if (pil == 1)
        {
            loading1();
            story1();
            break;
        }
        else if (pil == 2)
        {
            printf("good bye");
            return 0;
        }
        else
        {
            printf("error\n");
        }
    }

    // player, enemy, item
    srand(time(NULL));
    int randomattackplayer = rand() % 35 + 20;
    int randomattackpion = rand() % 30 + 15;
    int randomattackgiant = rand() % 35 + 15;
    int randomattackpikachu = rand() % 40 + 15;
    int randomattackspiderbunny = rand() % 40 + 20;
    int randomattackeviltank = rand() % 50 + 20;

    char namamusuh[5][100] = {"pion", "giant", "pikachu", "spiderbunny", "eviltank"};

    karakter slime = {name, 100, 100, randomattackplayer, 25, 100, 100, 100};
    karakter pion = {namamusuh[0], 30, 30, randomattackpion, 10, 0, 0, 0};
    karakter giant = {namamusuh[1], 70, 70, randomattackgiant, 20, 0, 0, 0};
    karakter pikachu = {namamusuh[2], 90, 90, randomattackpikachu, 20, 0, 0, 0};
    karakter spiderbunny = {namamusuh[3], 140, 140, randomattackspiderbunny, 30, 0, 0, 0};
    karakter eviltank = {namamusuh[4], 200, 200, randomattackeviltank, 40, 0, 0, 0};

    Item inventory[100] = {
        {"HP potion", "memulihkan 30 HP", 1, 30},
        {"Mana Potion", "memulihkan 20 Mana", 2, 20},
        {"Heavy HP potion", "memulihkan 60 HP", 3, 60},
        {"Heavy Mana potion", "memulihkan 40 Mana", 4, 40},
        {"Immortality", "memulihkan HP semula", 5, 100},
    };
    int jumlahitem = 5;

    // abyss floor 1
    intro();
    loading2();
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                     abyss floor 1                    \n");
    while (slime.currenthealth > 0 && pion.currenthealth > 0)
    {
        recoverHP(&slime, 5);
        recoverMana(&slime, 5);
        lantai1();
        HP(slime.currenthealth, slime.maxhealth);
        playermana(slime.currentmana, slime.maxmana);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        HP(pion.currenthealth, pion.maxhealth);
        printf("====================== BATTLE ======================\n");
        printf("giliran mu\n");
        printf("1. serang \n2. bertahan \npilih : ");
        scanf("%d", &pilihanserangan);
        switch (pilihanserangan)
        {
        case 1:
            attack(&slime, &pion);
            HP(pion.currenthealth, pion.maxhealth);

            if (pion.currenthealth <= 0)
            {
                printf("enemy defeat\n");
                score += 10;
                break;
            }
            break;

        case 2:
            printf("kamu memilih bertahan (+10 defense sementara)");
            slime.defense += 10;
            break;

        default:
            printf("error");
        }

        if (pion.currenthealth > 0)
        {
            printf("\nenemy turn\n");
            attack(&pion, &slime);
            HP(slime.currenthealth, slime.maxhealth);
            if (slime.currenthealth <= 0)
            {
                printf("Player has been defeated!\n");
                return 0;
                break;
            }
        }
        else
        {
            printf("kamu menang\n");
            slime.defense = 25;
        }
    }
    // abyss floor 2
    int indexitem;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("menu inventory terbuka !, kamu mendapatkan skill ");
    story2();
    loading2();
    printf("\n                      abyss floor 2                   \n");
    while (slime.currenthealth > 0 && giant.currenthealth > 0)
    {
        recoverHP(&slime, 5);
        recoverMana(&slime, 5);
        lantai2();
        HP(slime.currenthealth, slime.maxhealth);
        playermana(slime.currentmana, slime.maxmana);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        HP(giant.currenthealth, giant.maxhealth);
        printf("====================== BATTLE ======================\n");
        printf("giliran mu\n");
        tampilkanInventory(inventory, jumlahitem);
        menuskill();
        scanf("%d", &pilihanserangan);

        switch (pilihanserangan)
        {
        case 1:
            attack(&slime, &giant);
            HP(giant.currenthealth, giant.maxhealth);

            if (giant.currenthealth <= 0)
            {
                printf("enemy defeat\n");
                score += 10;
                break;
            }
            break;

        case 2:
            if (slime.currentmana >= 25)
            {
                skill1(&slime, &giant);
                HP(giant.currenthealth, giant.maxhealth);
                slime.currentmana -= 25;
                if (giant.currenthealth <= 0)
                {
                    printf("enemy defeat\n");
                    score += 20;
                }
            }
            else
            {
                printf("kurang mana");
            }

            break;

        case 3:
            if (slime.currentmana >= 40)
            {
                skill2(&slime, &giant);
                HP(giant.currenthealth, giant.maxhealth);
                slime.currentmana -= 40;
                if (giant.currenthealth <= 0)
                {
                    printf("enemy defeat\n");
                    score += 30;
                }
            }
            else
            {
                printf("kurang mana");
            }

            break;

        case 4:
            if (slime.currentmana >= 70)
            {
                skill3(&slime, &giant);
                HP(giant.currenthealth, giant.maxhealth);
                slime.currentmana -= 70;
                if (giant.currenthealth <= 0)
                {
                    printf("enemy defeat\n");
                    score += 40;
                }
            }
            else
            {
                printf("kurang mana");
            }

            break;

        case 5:
            printf("gunakan item : ");
            scanf("%d", &indexitem);
            gunakanItem(inventory, &jumlahitem, &slime, indexitem - 1);
            break;

        case 6:
            printf("kamu memilih bertahan (+10 defense sementara)");
            slime.defense += 10;
            break;

        default:
            printf("error");
        }

        if (giant.currenthealth > 0)
        {
            printf("\nenemy turn\n");
            attack(&giant, &slime);
            HP(slime.currenthealth, slime.maxhealth);
            if (slime.currenthealth <= 0)
            {
                printf("Player has been defeated!\n");
                break;
                return 0;
            }
        }
        else
        {
            printf("kamu menang\n");
            slime.defense = 25;
        }
    }
    // abyss floor 3
    story3();
    loading2();
    printf("\n                      abyss floor 3                   \n");
    while (slime.currenthealth > 0 && pikachu.currenthealth > 0)
    {
        recoverHP(&slime, 5);
        recoverMana(&slime, 5);
        lantai3();
        HP(slime.currenthealth, slime.maxhealth);
        playermana(slime.currentmana, slime.maxmana);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        HP(pikachu.currenthealth, pikachu.maxhealth);
        printf("====================== BATTLE ======================\n");
        printf("giliran mu\n");
        tampilkanInventory(inventory, jumlahitem);
        menuskill();
        scanf("%d", &pilihanserangan);

        switch (pilihanserangan)
        {
        case 1:
            attack(&slime, &pikachu);
            HP(pikachu.currenthealth, pikachu.maxhealth);

            if (pikachu.currenthealth <= 0)
            {
                printf("enemy defeat\n");
                score += 10;
                break;
            }
            break;

        case 2:
            if (slime.currentmana >= 25)
            {
                skill1(&slime, &pikachu);
                HP(pikachu.currenthealth, pikachu.maxhealth);
                slime.currentmana -= 25;
                if (pikachu.currenthealth <= 0)
                {
                    printf("enemy defeat\n");
                    score += 20;
                }
            }
            else
            {
                printf("kurang mana");
            }

            break;

        case 3:
            if (slime.currentmana >= 40)
            {
                skill2(&slime, &pikachu);
                HP(pikachu.currenthealth, pikachu.maxhealth);
                slime.currentmana -= 40;
                if (pikachu.currenthealth <= 0)
                {
                    printf("enemy defeat\n");
                    score += 30;
                }
            }
            else
            {
                printf("kurang mana");
            }

            break;

        case 4:
            if (slime.currentmana >= 70)
            {
                skill3(&slime, &pikachu);
                HP(pikachu.currenthealth, pikachu.maxhealth);
                slime.currentmana -= 70;
                if (pikachu.currenthealth <= 0)
                {
                    printf("enemy defeat\n");
                    score += 40;
                }
            }
            else
            {
                printf("kurang mana");
            }

            break;

        case 5:
            printf("gunakan item : ");
            scanf("%d", &indexitem);
            gunakanItem(inventory, &jumlahitem, &slime, indexitem - 1);
            break;

        case 6:
            printf("kamu memilih bertahan (+10 defense sementara)");
            slime.defense += 10;
            break;

        default:
            printf("error");
        }

        if (pikachu.currenthealth > 0)
        {
            printf("\nenemy turn\n");
            attack(&pikachu, &slime);
            HP(slime.currenthealth, slime.maxhealth);
            if (slime.currenthealth <= 0)
            {
                printf("Player has been defeated!\n");
                return 0;
                break;
            }
        }
        else
        {
            printf("kamu menang\n");
            slime.defense = 25;
        }
    }

    // abyss floor 4
    loading2();
    printf("\n                      abyss floor 4                   \n");
    while (slime.currenthealth > 0 && spiderbunny.currenthealth > 0)
    {
        recoverHP(&slime, 5);
        recoverMana(&slime, 5);
        lantai4();
        HP(slime.currenthealth, slime.maxhealth);
        playermana(slime.currentmana, slime.maxmana);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        HP(spiderbunny.currenthealth, spiderbunny.maxhealth);
        printf("====================== BATTLE ======================\n");
        printf("giliran mu\n");
        tampilkanInventory(inventory, jumlahitem);
        menuskill();
        scanf("%d", &pilihanserangan);

        switch (pilihanserangan)
        {
        case 1:
            attack(&slime, &spiderbunny);
            HP(spiderbunny.currenthealth, spiderbunny.maxhealth);

            if (spiderbunny.currenthealth <= 0)
            {
                printf("enemy defeat\n");
                score += 10;
                break;
            }
            break;

        case 2:
            if (slime.currentmana >= 25)
            {
                skill1(&slime, &spiderbunny);
                HP(spiderbunny.currenthealth, spiderbunny.maxhealth);
                slime.currentmana -= 25;
                if (spiderbunny.currenthealth <= 0)
                {
                    printf("enemy defeat\n");
                    score += 20;
                }
            }
            else
            {
                printf("kurang mana");
            }

            break;

        case 3:
            if (slime.currentmana >= 40)
            {
                skill2(&slime, &spiderbunny);
                HP(spiderbunny.currenthealth, spiderbunny.maxhealth);
                slime.currentmana -= 40;
                if (spiderbunny.currenthealth <= 0)
                {
                    printf("enemy defeat\n");
                    score += 30;
                }
            }
            else
            {
                printf("kurang mana");
            }

            break;

        case 4:
            if (slime.currentmana >= 70)
            {
                skill3(&slime, &spiderbunny);
                HP(spiderbunny.currenthealth, spiderbunny.maxhealth);
                slime.currentmana -= 70;
                if (pikachu.currenthealth <= 0)
                {
                    printf("enemy defeat\n");
                    score += 40;
                }
            }
            else
            {
                printf("kurang mana");
            }
            break;

        case 5:
            printf("gunakan item : ");
            scanf("%d", &indexitem);
            gunakanItem(inventory, &jumlahitem, &slime, indexitem - 1);
            break;

        case 6:
            printf("kamu memilih bertahan (+10 defense sementara)");
            slime.defense += 10;
            break;

        default:
            printf("error");
        }

        if (spiderbunny.currenthealth > 0)
        {
            printf("\nenemy turn\n");
            attack(&spiderbunny, &slime);
            HP(slime.currenthealth, slime.maxhealth);
            if (slime.currenthealth <= 0)
            {
                printf("Player has been defeated!\n");
                return 0;
                break;
            }
        }
        else
        {
            printf("kamu menang\n");
            slime.defense = 25;
        }
    }

    // abyss floor 5
    story4();
    loading2();
    printf("\n                      abyss floor 5                   \n");
    while (slime.currenthealth > 0 && eviltank.currenthealth > 0)
    {
        recoverHP(&slime, 5);
        recoverMana(&slime, 5);
        lantai5();
        HP(slime.currenthealth, slime.maxhealth);
        playermana(slime.currentmana, slime.maxmana);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        HP(eviltank.currenthealth, eviltank.maxhealth);
        printf("====================== BATTLE ======================\n");
        printf("giliran mu\n");
        tampilkanInventory(inventory, jumlahitem);
        menuskill();
        scanf("%d", &pilihanserangan);

        switch (pilihanserangan)
        {
        case 1:
            attack(&slime, &eviltank);
            HP(eviltank.currenthealth, eviltank.maxhealth);

            if (eviltank.currenthealth <= 0)
            {
                printf("enemy defeat\n");
                score += 10;
                break;
            }
            break;

        case 2:
            if (slime.currentmana >= 25)
            {
                skill1(&slime, &eviltank);
                HP(eviltank.currenthealth, eviltank.maxhealth);
                slime.currentmana -= 25;
                if (eviltank.currenthealth <= 0)
                {
                    printf("enemy defeat\n");
                    score += 20;
                }
            }
            else
            {
                printf("kurang mana");
            }

            break;

        case 3:
            if (slime.currentmana >= 40)
            {
                skill2(&slime, &eviltank);
                HP(eviltank.currenthealth, eviltank.maxhealth);
                slime.currentmana -= 40;
                if (eviltank.currenthealth <= 0)
                {
                    printf("enemy defeat\n");
                    score += 30;
                }
            }
            else
            {
                printf("kurang mana");
            }

            break;

        case 4:
            if (slime.currentmana >= 70)
            {
                skill3(&slime, &eviltank);
                HP(eviltank.currenthealth, eviltank.maxhealth);
                slime.currentmana -= 70;
                if (eviltank.currenthealth <= 0)
                {
                    printf("enemy defeat\n");
                    score += 40;
                }
            }
            else
            {
                printf("kurang mana");
            }

            break;

        case 5:
            printf("gunakan item : ");
            scanf("%d", &indexitem);
            gunakanItem(inventory, &jumlahitem, &slime, indexitem - 1);
            break;

        case 6:
            printf("kamu memilih bertahan (+10 defense sementara)");
            slime.defense += 10;
            break;

        default:
            printf("error");
        }

        if (eviltank.currenthealth > 0)
        {
            printf("\nenemy turn\n");
            attack(&eviltank, &slime);
            HP(slime.currenthealth, slime.maxhealth);
            if (slime.currenthealth <= 0)
            {
                printf("Player has been defeated!\n");
                return 0;
                break;
            }
        }
        else
        {
            printf("kamu menang\n");
            slime.defense = 25;
        }
    }

    story5();
    storyending();
    printf("score = %d", score);

    return 0;
}
