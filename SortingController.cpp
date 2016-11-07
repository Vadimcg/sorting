//
// Created by vadimcg on 05.11.16.
//

#include "SortingController.h"

SortingController* SortingController::selectionSortInstance_= nullptr;

SelectionSortDestroyer* SortingController::selectionSortDestroyer_;

SortingController::SortingController(){
}

SortingController::~SortingController(){
    std::cout<<"SortingController instance call destroy";
}

SelectionSortDestroyer::~SelectionSortDestroyer(){
    delete selectionSort_;
}
void SelectionSortDestroyer::initialize(SortingController* selectionSort){
    this->selectionSort_=selectionSort;
}


SortingController& SortingController::getInstance(){
    if(!selectionSortInstance_){
        selectionSortInstance_=new  SortingController();
        selectionSortDestroyer_->initialize(selectionSortInstance_);
    }

    return *selectionSortInstance_;
}

void SortingController::selectionSortRecursiveStart(int* data,int size){
    this->size_=size;
    this->selectionSortRecursive(data,0);
}

void SortingController::selectionSortRecursive(int* data,int start){
    if(start<this->size_){
        this->swap(data,start,this->findMinimumIndex(data,start));
        this->selectionSortRecursive(data,start+1);
    }

}

int SortingController::findMinimumIndex(int* data,int start){
    int minPos=start;

    for(int i=start+1;i<this->size_;i++){

        if(data[minPos]>data[i])
            minPos=i;
    }

    return minPos;
}

void SortingController::swap(int* data,int indexFirt,int indexSecond){
    if(indexFirt!=indexSecond){
        int firstValue=data[indexFirt];
        data[indexFirt]=data[indexSecond];
        data[indexSecond]=firstValue;
    }
}

void  SortingController::insertingSort(int* data){
    for(int which=1;which<this->size_;which++){
        int val=data[which];

        for(int i=0;i<which;i++){
            if(data[i]>val){
                std::copy(data[i],data[i+1],data[which-i]);
                data[i]=val;
                break;
            }
        }
    }

}




