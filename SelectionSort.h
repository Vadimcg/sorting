//
// Created by vadimcg on 05.11.16.
//


#include <iostream>

#ifndef SORTING_SELECTIONSORT_H
#define SORTING_SELECTIONSORT_H



class SelectionSortDestroyer{

};

class SelectionSort {

    private:

        int size_;
        static SelectionSort* selectionSortInstance_;

        void selectionSortRecursive(int* data,int start);
        int findMinimumIndex(int* data,int start);
        void swap(int* data,int indexFirt,int indexSecond);

    public:

        static SelectionSort& getInstance();

        SelectionSort();
        ~SelectionSort();
        void selectionSortRecursiveStart(int* data,int size);

};


#endif //SORTING_SELECTIONSORT_H
