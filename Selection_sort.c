#include "header.h"

void Selection_sort(int* arr, int Amount_of_elements) {
        int min, temp;                                          // ��� ������ ������������ �������� � ��� ������
        for (int i = 0; i < Amount_of_elements - 1; i++)
        {
            min = i;                                            // ���������� ������ �������� ��������
                                                                // ���� ����������� ������� ����� ��������� �� ����� i-���
            for (int j = i + 1; j < Amount_of_elements; j++)    // ��� ��������� ��������� ����� i-���
            {
                if (arr[j] < arr[min])                          // ���� ������� ������ ������������,
                    min = j;                                    // ���������� ��� ������ � min
            }
            temp = arr[i];                                      // ������ ������� i-�� � ����������� ��������
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }