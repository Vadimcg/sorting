//
// Created by vadimcg on 05.11.16.
//


#include <iostream>

#ifndef SORTING_SELECTIONSORT_H
#define SORTING_SELECTIONSORT_H

class SortingController;

class SelectionSortDestroyer{
private:
    SortingController* selectionSort_;
public:
    ~SelectionSortDestroyer();
    void initialize(SortingController* selectionSort);
};

class SortingController {

    private:

        int size_;
        static SortingController* selectionSortInstance_;
        static SelectionSortDestroyer* selectionSortDestroyer_;

        void selectionSortRecursive(int* data,int start);
        int findMinimumIndex(int* data,int start);
        void swap(int* data,int indexFirt,int indexSecond);

    public:

        static SortingController& getInstance();

        SortingController();
        ~SortingController();
        void selectionSortRecursiveStart(int* data,int size);

        void insertingSort(int* data);

};


#endif //SORTING_SELECTIONSORT_H
