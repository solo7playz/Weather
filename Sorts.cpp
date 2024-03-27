#include "Sorts.h"
void Sorts::showMenuSort() {
    std::cout << "1 - ������������� ���������." << std::endl;
    std::cout << "2 - ������������� �������." << std::endl;
    std::cout << "3 - ������������� ��������." << std::endl;
    std::cout << "4 - ������������� ���������." << std::endl;
    std::cout << "0 - �����" << std::endl;
}
void Sorts::bubleSort(int*& arr, int& size){
    int tmp;
    for (int i = 0; i < size - 1; ++i){
        for (int j = 0; j < size - 1; ++j){
            if (arr[j + 1] < arr[j]){
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
void Sorts::choicesSort(int*& arr, int& len){
    for (int i = 0; i < len; i++){
        int tmp = arr[0];
        for (int j = i + 1; j < len; j++){
            if (arr[i] > arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
void Sorts::pasteSort(int*& arr, int& len) {
    int tmp, j;
    for (int i = 1; i < len; i++) {
        tmp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = tmp;
    }
}
//void Sorts::countingSort(int*& arr, int& len){
//    int min=arr[0];
//    int lenk = len;
//    int* arr1 = new int[lenk];
//    for (int i = 0;i < lenk;i++) {
//        if (min > arr[i]) {
//            min = arr[i];
//        }
//    }
//    for (int i = 0; i < lenk; i++) {
//        arr1[i] = min-1;
//    }
//    for (int i = 0; i < len; i++) {
//        arr1[arr[i]] = arr1[arr[i]] + 1;
//    }
//    int i = 0;
//    for (int j = 0; j < lenk; j++) {
//        while (arr1[j] != 0) {
//            arr[i] = j;
//            arr1[j]--;
//            i++;
//        }
//    }
//}
void Sorts::countingSort(int*& arr, int& len) {
    int min = arr[0];
    int lenk = len;
    int* arr1 = new int[len];
    for (int i = 0;i < lenk;i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    for (int i = 0; i < lenk; i++) {
        arr1[i] = min - 1;
    }
    for (int i = 0; i < lenk; i++) {
        arr1[arr[i]] = arr1[arr[i]] + 1;
    }
    int i = 0;
    for (int j = 0; j < lenk; j++) {
        while (arr1[j] != min - 1) {
            arr[i] = j;
            arr1[j]--;
            i++;
        }
    }
}