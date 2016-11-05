//
// Created by vadimcg on 05.11.16.
//

#include "SelectionSort.h"

SelectionSort* SelectionSort::selectionSortInstance_= nullptr;


SelectionSort::SelectionSort(){
}

SelectionSort::~SelectionSort(){
    std::cout<<"SelectionSort instance call destroy";
}


SelectionSort& SelectionSort::getInstance(){
    if(!selectionSortInstance_){
        selectionSortInstance_=new  SelectionSort();
    }

    return *selectionSortInstance_;
}

void SelectionSort::selectionSortRecursiveStart(int* data,int size){
    this->size_=size;
    this->selectionSortRecursive(data,0);
}

void SelectionSort::selectionSortRecursive(int* data,int start){
    if(start<this->size_){
        this->swap(data,start,this->findMinimumIndex(data,start));
        this->selectionSortRecursive(data,start+1);
    }

}

int SelectionSort::findMinimumIndex(int* data,int start){
    int minPos=start;

    for(int i=start+1;i<this->size_;i++){

        if(data[minPos]>data[i])
            minPos=i;
    }

    return minPos;
}

void SelectionSort::swap(int* data,int indexFirt,int indexSecond){
    if(indexFirt!=indexSecond){
        int firstValue=data[indexFirt];
        data[indexFirt]=data[indexSecond];
        data[indexSecond]=firstValue;
    }
}
