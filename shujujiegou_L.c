#include<stdio.h>
//dynamtic Array，first
#include<stdlib.h>
//Define a dynamic array structure that stores an array and its size
typedef struct {
	int* array;
	size_t size;
}dynamic_array;

//draw a map to understand
//Function to create a new dynamic array，结构体作为函数返回值，几乎相当于两遍函数；
dynamic_array* creat_array(size_t size){
	dynamic_array* arr = malloc(sizeof(dynamic_array));
	arr->array = malloc(size * sizeof(int));
	arr->size = size;
	return arr;
}
//Function to read an element from a dynamic array
int read_array(dynamic_array* arr, size_t index)
{
	//如果超出字节，做出提示；
	if (index < arr->size)
	{
		return arr->array[index];
	}
	else
	{
		printf("Error: index out of bounds: %d\n",index);
		return -1;
	}
}
 //Function to update an element from a dynamic array
void update_array(dynamic_array* arr, size_t index, int value)
{
	if (index < arr->size)
	{
		arr->array[index] = value;
	}
	else
	{
		printf("Error:index out of bounds: %d\n ", index);
	}
}
//Function to delete a dynamic array
void delete_array(dynamic_array* arr) {
	free(arr->array);
	free(arr);
}
//main,delete清空；删除与update一样；
int main() {
	dynamic_array* arr = creat_array(10);
	update_array(arr, 5, 33333);
	int value = read_array(arr, 5);
	printf("The value is: %d\n", value);
	delete_array(arr);
} 