#include <stdio.h>
#include <locale.h>

// Типы элементов для поиска
#define POSITIVE 1 // положительные числа
#define NEGATIVE 2 // отрицательные числа
#define ZERO 3     // нули
#define N_ARR_1 10
#define N_ARR_2 8
#define N_ARR_3 5

// Функция для поиска индекса элемента в середине интервала
int find_middle_element_index(double *ptr_array, int n, int type)
{
    if (n <= 0)
    {
        return -1; // Ошибка: неверные параметры
    }

    int first_index = -1;
    int last_index = -1;

    // Поиск первого и последнего элемента заданного типа
    for (int i = 0; i < n; i++)
    {
        int matches_condition = 0;

        switch (type)
        {
        case POSITIVE:
            matches_condition = (ptr_array[i] > 0);
            break;
        case NEGATIVE:
            matches_condition = (ptr_array[i] < 0);
            break;
        case ZERO:
            matches_condition = (ptr_array[i] == 0);
            break;
        default:
            return -1; // Неизвестный тип
        }

        if (matches_condition == 1)
        {
            if (first_index == -1)
            {
                first_index = i;
            }
            last_index = i;
        }
    }

    if (first_index == -1 || last_index == -1 || first_index == last_index)
    {
        return -1; // Не найдено достаточно элементов
    }

    // Вычисление индекса элемента в середине интервала
    int middle_index = (first_index + last_index) / 2;

    return middle_index;
}

// Функция для ввода массива
void input_array(double *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Элемент [%d]: ", i);
        scanf("%lf", &arr[i]);
    }
}

// Функция для вывода массива
void print_array(double *arr, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f", arr[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");
}

int main()
{
    setlocale(LC_ALL, "RUS");
    double array_1[N_ARR_1], array_2[N_ARR_2], array_3[N_ARR_3];
    printf("Введите %d элементов массива:\n", N_ARR_1);
    input_array(array_1, N_ARR_1);
    printf("Массив 1:\n");
    print_array(array_1, N_ARR_1);

    int result1 = find_middle_element_index(array_1, N_ARR_1, POSITIVE);
    printf("Середина между первым и последним положительным: индекс %d (значение: %.2f)\n",
           result1, result1 != -1 ? array_1[result1] : 0);

    int result2 = find_middle_element_index(array_1, N_ARR_1, NEGATIVE);
    printf("Середина между первым и последним отрицательным: индекс %d (значение: %.2f)\n",
           result2, result2 != -1 ? array_1[result2] : 0);

    int result3 = find_middle_element_index(array_1, N_ARR_1, ZERO);
    printf("Середина между первым и последним нулевым: индекс %d\n", result3);

    printf("Введите %d элементов массива:\n", N_ARR_2);
    input_array(array_2, N_ARR_2);

    printf("\nМассив 2:\n");
    print_array(array_2, N_ARR_2);

    int result4 = find_middle_element_index(array_2, N_ARR_2, ZERO);
    printf("Середина между первым и последним нулевым: индекс %d (значение: %.2f)\n",
           result4, result4 != -1 ? array_2[result4] : 0);

    printf("Введите %d элементов массива:\n", N_ARR_3);
    input_array(array_3, N_ARR_3);

    printf("\nМассив 3:\n");
    print_array(array_3, N_ARR_3);

    int result5 = find_middle_element_index(array_3, N_ARR_3, POSITIVE);
    printf("Середина между первым и последним положительным: индекс %d (значение: %.2f)\n",
           result5, result5 != -1 ? array_3[result5] : 0);

    return 0;
}