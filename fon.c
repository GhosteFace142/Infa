// Вариант №9
#include <stdio.h>

int main()
{
    int a, pc = 0, acc = 0, i = 1, b;
    int cpu_state[8] = {0};
    int memory[256] = {0};

    while (scanf("%d", b) == 1 && i < 256)
    {
        memory[i] = b;
        i++;
    }
    while (scanf("%d", &a) == 1 && a != '0')
    {
        switch (a)
        {
        case '0':
            printf("0. Стоп\n");
            cpu_state[4] = 1;
            break;
        case '1':
            printf("1. Аккумулятор = %d\n", cpu_state[1]);
            pc++;
            break;
        case '2':
            pc++;
            acc = memory[memory[cpu_state[0]]];
            printf("2. Загружено. Из ячейки %d загружено %d. Аккум = %d\n", memory[cpu_state[0]], cpu_state[1], cpu_state[1]);
            pc++;
            break;
        case '3':
            pc++;
            acc = acc * memory[memory[cpu_state[0]]];
            printf("3. Умножение на ячейку %d. Аккум = %d\n", memory[cpu_state[0]], cpu_state[1]);
            pc++;
            break;
        default:
            printf("Прерывание\n");
            cpu_state[5] = 2;
            cpu_state[4] = 1;
            break;
        }
    }
    printf("Завершение работы\n");
    return 0;
}
