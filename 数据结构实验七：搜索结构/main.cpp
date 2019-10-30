#include <iostream>
#include <chrono>
#include "SeqList.h"
#include "BinarySearchTree.h"

using namespace std;
using namespace chrono;

const int Size = 10000;//��������

int BinarySearch(int target, int *arr, int length, int &ComparisonTimes) {
    int start = 0, end = length - 1;
    while (end >= start) {
        int mid = end + (start - end) / 2;
        ComparisonTimes++;
        if (arr[mid] > target) {
            end = mid - 1;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else
            return mid;
    }
    return -1;
}

int main() {
    srand((unsigned) time(nullptr));

    int a = 0, b = INT_MAX;

    SeqList<int> seqList;

    for (int i = 0; i < Size; ++i) { //�������Size��������Ҫ�󻥲���ͬ���洢��˳�����
        int number = (rand() % (b - a + 1)) + a;//[a,b] ���������
        if (!seqList.QuerySpecifiedElement(number))
            seqList.push_back(number);
        else
            i--;
    }

    int randomNumber[Size];
    for (int j = 0; j < Size; ++j) {
        seqList.getDataByIndex(j + 1, randomNumber[j]);
    }

    seqList.Sort();//��˳����Ϊ����˳���

    int seqListTemp[Size];
    for (int j = 0; j < Size; ++j) {
        seqList.getDataByIndex(j + 1, seqListTemp[j]);
    }

    int TotalNumberOfComparisons = 0;

    auto seqListStart = system_clock::now();
    for (int k = 0; k < Size; ++k) {
        int ComparisonTimes = 0;
        BinarySearch(seqListTemp[k], seqListTemp, seqList.Length(), ComparisonTimes);
        TotalNumberOfComparisons += ComparisonTimes;
    }
    auto seqListEnd = system_clock::now();
    auto duration = duration_cast<microseconds>(seqListEnd - seqListStart);
    cout << "����˳�����۰�����ƽ����������Ϊ��" << TotalNumberOfComparisons / seqList.Length() << endl;
    cout << "����˳�����۰���������ʱΪ��"
         << (double(duration.count()) * microseconds::period::num / microseconds::period::den) * 1000
         << "ms"
         << endl;

    BinarySearchTree<int, int> BST;

    for (int l = 0; l < Size; ++l) {
        BST.insert(randomNumber[l], randomNumber[l]);
    }

    TotalNumberOfComparisons = 0;

    auto BinarySearchTreeStart = system_clock::now();
    for (int m = 0; m < Size; ++m) {
        int ComparisonTimes = 0;
        BST.existence(randomNumber[m], ComparisonTimes);
        TotalNumberOfComparisons += ComparisonTimes;
    }
    auto BinarySearchTreeEnd = system_clock::now();
    duration = duration_cast<microseconds>(BinarySearchTreeEnd - BinarySearchTreeStart);
    cout << "�����������Ĳ���ƽ����������Ϊ��" << TotalNumberOfComparisons / seqList.Length() << endl;
    cout << "�����������Ĳ�������ʱΪ��" << (double(duration.count()) * microseconds::period::num / microseconds::period::den) * 1000
         << "ms"
         << endl;

    return 0;
}