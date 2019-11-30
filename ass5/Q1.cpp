#include <iostream>
#include "Q1.hpp"

int main(int argc, char *argv[])
{
    // Hard-coded to 3*3 matrix since we are allocating arrays on the stack
    int size = 3;
    int smallest_number = INT32_MAX;
    int largest_number = INT32_MIN;
    int sum = 0;
    int matrix[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int all_values[size*size];
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            std::cout << "Enter a value for the " << j << "th index in row " << i <<": ";
            int* current_element = (*(matrix + i) + j);
            std::cin >> *current_element;
            *(all_values + count) = *current_element;
            count++;
            if(*current_element > largest_number)
            {
                largest_number = *current_element;
            }
            if(*current_element < smallest_number)
            {
                smallest_number = *current_element;
            }
            sum += *current_element;
        }
    }

    BubbleSort(all_values, count);
    double median = 0;

    if(count % 2 == 0)
    {
        //even
        median = ((*(all_values +((count/2)-1)) + *(all_values + (count/2)))/2);
    }
    else
    {
        //odd
        median = *(all_values + (count-1)/2);
    }

    double average = double(sum) / (double(size)*double(size));

    std::cout << "Minimum: " << smallest_number << std::endl;
    std::cout << "Maximum: " << largest_number << std::endl;
    std::cout << "Average: " << average << std::endl;
    std::cout << "Median: " << median << std::endl;
    std::cout << "Sum: " << sum << std::endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << *(*(matrix + i) + j) << " ";
        }
        std::cout << std::endl;
    }

}

void Swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void BubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                Swap(&arr[j], &arr[j+1]);
}