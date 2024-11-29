#define _CRT_SECURE_NO_WARNINGS     
#include <stdio.h>     
#include <locale.h>     
#define _USE_MATH_DEFINES     
#include <math.h>

//функция для заполнения массива значениями
double* full_elements(double *ptr_array, int size) {
	for (int i = 0; i < size; i++) {
		printf("Введите элемент %d: ", i + 1);
		scanf("%lf", &ptr_array[i]);
	}
	return ptr_array;
}

//функция для преобразования элементов массива
double* calc_elements(double *ptr_array, int size) {
	double* new_array = (double*)malloc(size * sizeof(double));
	if (new_array == NULL) {
		puts("Ошибка при выделении памяти для нового массива");
		return NULL;
	}

	for (int i = 0; i < size; i++) {
		if (i % 2 == 1) {
			new_array[i] = ptr_array[i] + 1;
		}
		else {
			new_array[i] = ptr_array[i];
		}
	}
	return new_array;
}
int main() {
	setlocale(LC_ALL, "RUS");
	double *ptr_array;
	int size;
	printf("Введите размер массива: ");
	scanf("%d", &size);

	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL) {
		puts("Ошибка выделения памяти");
		return -1;
	}
	ptr_array = full_elements(ptr_array, size);

	double* result_array = calc_elements(ptr_array, size);
	if (result_array == NULL) {
		free(ptr_array);
		return -1;
	}

	printf("Результаты преобразования:\n");
	for (int i = 0; i < size; i++) {
		printf("Элемент %d: %lf\n", i + 1, result_array[i]);
	}
	free(ptr_array);
	free(result_array);

	return 0;
}