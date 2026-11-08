#define _CRT_SECURE_NO_DEPRECATE
#include <locale.h>
#include <stdio.h>
#include <string.h>
int main()
{
    task1_1();
    task1_2();
    task1_3();
    task2();
    task3();

}
int task1_1() {
    setlocale(LC_ALL, ".UTF8");
    int rows = 9;
    int cols = 9;
    int i, j;

    printf("\nТаблица умножения (Пифагора):\n");

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= cols; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    return 0;
}
int task1_2() {
    int rows = 9;
    int i = 1, j;

    printf("\nЛевый нижний треугольник:\n");

    while (i <= rows) {
        for (j = 1; j <= i; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
        i++;
    }

    return 0;
}
int task1_3() {
    int height = 4; // Количество строк
    int width = 6;  // Количество столбцов
    int i, j;

    printf("\nМатрица из цифр 5:\n");

    // Внешний цикл по строкам
    for (i = 0; i < height; i++) {
        // Внутренний цикл по столбцам
        for (j = 0; j < width; j++) {
            printf("%4d", 5);
        }
        printf("\n");
    }

    return 0;
}
int task2() {
    char str[50];
    char ans;

    do {
        printf("\nВведите число: ");
        scanf("%s", str);

        int len = strlen(str);
        int c3 = 0, cL = 0, cE = 0, cG5 = 0, sOdd = 0, sG7 = 0, cS = 0, p8 = 0, s9 = 0, s1 = 0, s2 = 0, se = 0, so = 0;
        long long prod = 1;
        int last = str[len - 1] - '0'; 

        for (int i = 0; i < len; i++) {
            int d = str[i] - '0';

            if (d == 3) c3++;
            if (d == last) cL++;
            if (d % 2 == 0) cE++;
            if (d > 5) cG5++;
            if (d % 2 != 0) sOdd += d;
            if (d >= 7) sG7 += d;
            if (d != 0) prod *= d;

            if (i > 0 && d == (str[i - 1] - '0')) cS++;

            if (i < len - 1 && d % 2 == 0) s9 += d;

            if ((len - i) % 2 != 0) so += d; else se += d;

            if (i < len / 2) s1 += d; else s2 += d;
        }

        if (len >= 2) p8 = (str[len - 2] - '0') * (str[1] - '0');

        printf("1) %d\n2) %d\n3) %d\n4) %d\n5) %d\n6) %d\n7) %lld\n", c3, cL, cE, cG5, sOdd, sG7, prod);
        if (len >= 2) printf("8) %d\n", p8);
        printf("9) %d\n10) %d\n", s9, cS);

        if (len % 2 == 0 && s1 == s2) printf("11) Равны\n");
        else if (len % 2 != 0) printf("11) Нечетная длина\n");
        else printf("11) Не равны\n");

        printf("12) %d\n", se * so);

        printf("\nПродолжить? (y/n): ");
        scanf(" %c", &ans);
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
int task3() {
    char s; int h, a, r = 1;
    while (r != 0) {
        printf("\nСимвол: "); scanf(" %c", &s);
        printf("Высота: "); scanf("%d", &h);
        printf("Ширина: "); scanf("%d", &a);
        printf("Угол (напр. 45): "); scanf("%d", &r);

        int step = (r / 45 < 1) ? 1 : r / 45; 
        printf("\nФигура:\n");

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < (h - 1 - i) * step; j++) printf(" "); 

            for (int j = 0; j < a; j++) {
                if (i == 0 || i == h - 1 || j == 0 || j == a - 1) printf("%c", s);
                else printf(" ");
            }
            printf("\n");
        }
        printf("\nПродолжить? (0 - выход, другое - повтор): ");
        scanf("%d", &r);
    }
    return 0;
}