#include <stdio.h>
#include <stdlib.h>
int main()
{
    _Bool start_program = 1;
    _Bool loading;
    _Bool main_menu = 1;
    _Bool menu1 = 0;
    _Bool menu2 = 0;
    _Bool menu3 = 0;
    _Bool menu4 = 0;
    char option;
    char num1S[20], num2S[20];
    int num1, num2;

    while (start_program)
    {
        loading = 1;

        if (main_menu)
        {

            printf("Zadaj zvolenú operáciu: \n"
                   "1 - a + b\n"
                   "2 - a - b\n"
                   "3 - a * b\n"
                   "4 - a / b\n"
                   "0 - koniec\n");

            scanf("%c", &option);
            fflush(stdin);


            switch (option)
            {
                case '1':
                    menu1 = 1;
                    break;
                case '2':
                    menu2 = 1;
                    break;
                case '3':
                    menu3 = 1;
                    break;
                case '4':
                    menu4 = 1;
                    break;
                case '0':
                    start_program = 0;
                    continue;
                default:
                    printf("Neplatný znak: \n");
                    loading = 0;
            }
        }

        while (loading)
        {
            printf("Zadajme čísla a a b:\n");
            scanf("%s %s", num1S, num2S);
            num1 = atoi(num1S);
            num2 = atoi(num2S);

            if ((num1 == 0 && num1S[0] != '0') || (num2 == 0 && num2S[0] != '0'))
                printf("Nezadali sme číslo, poďme ešte raz: \n");

            else
                loading = 0;
            fflush(stdin);
        }

        if (menu1)
        {
            printf("Súčet a + b = %d\n", num1 + num2);
            menu1 = 0;
        }

        if (menu2)
        {
            printf("Rozdiel a - b = %d\n", num1 - num2);
            menu2 = 0;
        }

        if (menu3)
        {
            printf("Súčin a * b = %d\n", num1 * num2);
            menu3 = 0;
        }

        if (menu4)
        {
           if (num2 == 0)
           {
               printf("Chyba: Delenie 0\nZadajme znovu!");
               main_menu = 0;
           }
           else
           {
               printf("Podiel: a / b = %f\n", (double) num1 / num2);
               main_menu = 1;
               menu4 = 0;
           }

        }

          printf("\nAny key - chcem ešte niečo zadať, 0 - chcem skončiť program\n");
          scanf("%c",&option);
          fflush(stdin);


         if (option == '0')
            start_program = 0;
    }

    return 0;
}
