#include "header.h"

void Merger_sort(int* arr, int* tmp, int left_index, int right_index) { //аргументы - индексы границ рассматриваемого участка
  //разбиение участка пополам
    if (left_index < right_index) {
        Merger_sort(arr, tmp, left_index, ((left_index + right_index) / 2)); //после этого вызова будет отсортирована левая часть участка
        //третий аргумент - это середина участка
        Merger_sort(arr, tmp, ((left_index + right_index) / 2) + 1, right_index); //после этого вызова будет отсортирована правая часть

        //***********************************//
        //слияние двух отсортированных массивов
        //***********************************//

        int left_spot = left_index, right_spot = ((left_index + right_index) / 2) + 1, i, sorted_spot = left_index;
        //размещаем в начале каждой половинки по указателю на индекс, указатель sorted_spot говорит о том, для какого элемента мы принимаем решение
        while ((left_spot <= ((left_index + right_index) / 2)) && (right_spot <= right_index)) { //пока не разобрали одну из половинок, записываем и сравниваем в штатном режиме
            if (arr[left_spot] <= arr[right_spot]) { //наименьшее из значений ставим уже в слитый массив
                tmp[sorted_spot] = arr[left_spot];
                left_spot++; //этот элемент левого массива отсортирован, рассматриваем следующий
                sorted_spot++; //перемещаем указатель дальше
            }
            else {
                tmp[sorted_spot] = arr[right_spot]; //аналогично
                right_spot++;
                sorted_spot++;
            }
        }
        if (left_spot > ((left_index + right_index) / 2)) { //если левая половина закончилась
            while (right_spot <= right_index) {
                tmp[sorted_spot] = arr[right_spot];
                right_spot++;
                sorted_spot++;
            }
        }
        else { //если правая половина закончилась
            while (left_spot <= ((left_index + right_index) / 2)) {
                tmp[sorted_spot] = arr[left_spot];
                left_spot++;
                sorted_spot++;
            }
        }

        for (i = left_index; i <= right_index; i++) //перезапись массива, полученного слиянием обратно из временного в обычный
            arr[i] = tmp[i]; //обновляется только часть массива, затрагиваемая действом
    }
}