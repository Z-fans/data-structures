#include <iostream>
#include <ctime>
#include "Heap.h"

using namespace std;

struct object {
    int value;
    int priority;

    bool operator>(const object &b) const {
        return this->priority > b.priority;
    }

    bool operator<=(const object &b) const {
        return this->priority <= b.priority;
    }

    bool operator<(const object &b) const {
        return this->priority < b.priority;
    }

    friend ostream &operator<<(ostream &out, object &object) {
        out << "priority��" << object.priority << " "
            << "value��" << object.value << endl;
        return out;
    }
};

void SchemeOne(object *arr, int size) {
    cout << "����һ���ԣ�" << endl;
    object *obArr = new object[size];
    for (int i = 0; i < size; ++i) {
        obArr[i] = arr[i];
    }
    int size_t = size, totalCompareCount = 0;
    for (int j = 0; j < size; ++j) {
        int minPriorityObjectIndex = 0;
        for (int i = 0; i < size_t; ++i) {
            if (obArr[minPriorityObjectIndex].priority > obArr[i].priority) {
                swap(obArr[minPriorityObjectIndex], obArr[i]);
                totalCompareCount++;
            }
        }
        //  cout << obArr[minPriorityObjectIndex];
        swap(obArr[minPriorityObjectIndex], obArr[size_t - 1]);
        size_t--;
    }
    cout << "SchemeOne��������ƽ���Ƚϴ�����" << totalCompareCount / size << endl;
}

void SchemeTwo(object *arr, int size) {
    cout << "���������ԣ�" << endl;
    object *obArr = new object[size];
    for (int i = 0; i < size; ++i) {
        obArr[i] = arr[i];
    }
    int totalCompareCount = 0;
    //ֱ�Ӳ�������
    for (int i = 1; i < size; i++) {
        object temp = obArr[i]; // ���浱ǰλ�õ�ֵ
        int j = i - 1;
        while (j >= 0 && obArr[j].priority > temp.priority) { // ��ǰ�Ҳ����λ��
            obArr[j + 1] = obArr[j]; // ������
            j--;
            totalCompareCount++;
        }
        obArr[j + 1] = temp;
    }
    for (int k = 0; k < size; ++k) {
        // cout << obArr[k];
    }
    cout << "SchemeTwo��������ƽ���Ƚϴ�����" << totalCompareCount / size << endl;
}

void SchemeThe(object *arr, int size) {
    cout << "���������ԣ�" << endl;
    Heap<object> SchemeTheHeap(arr, size);
    for (int j = 0; j < size; ++j) {
        object t = SchemeTheHeap.getTop();
        //cout << t;
    }
    cout << "SchemeThe��������ƽ���Ƚϴ�����" << SchemeTheHeap.getGetTopTotalCompareCount() / size << endl;
}

int main() {
    int tempA[] = {53, 17, 78, 9, 45, 65, 87, 23};
    Heap<int> Heap01(tempA, 8);
    cout << "������һ����СΪ" << Heap01.getSize() << "��int��";
    if (Heap01.getType())
        cout << "�����";
    else
        cout << "С����";
    cout << "\n������Ϊ��" << Heap01.getCapacity();
    cout << "\n����С����������ʱ�����������Զ���չ��ÿ������һ��Ĭ�ϳ��ȡ�";
    cout << "\nĿǰ�ѵ������";
    Heap01.DisPlayHeap();
    cout << "\n����һ��Ԫ��19��";
    Heap01.Insert(19);
    Heap01.DisPlayHeap();
    cout << "\nɾ���Ѷ�Ԫ��9��";
    Heap01.Remove();
    Heap01.DisPlayHeap();
    if (Heap01.isEmpty())
        cout << "\n��ʱ��Ϊ��";
    else
        cout << "\n��ʱ�Ѳ�Ϊ��";
    cout << "\n�����򣨴�С���󣩣�";
    Heap01.HeapSort();
    Heap01.DisPlayHeap();
    cout << "\nת��Ϊ";
    if (Heap01.getType())
        cout << "����ѣ�";
    else
        cout << "С���ѣ�";
    Heap01.toMaxHeap();
    Heap01.DisPlayHeap();
    cout << "\n�����򣨴Ӵ�С����";
    Heap01.HeapSort();
    Heap01.DisPlayHeap();
    cout << "\nת��Ϊ";
    if (Heap01.getType())
        cout << "����ѣ�";
    else
        cout << "С���ѣ�";
    Heap01.toMinHeap();
    Heap01.DisPlayHeap();
    cout << "\nִ��makeEmpty()��";
    Heap01.makeEmpty();
    if (Heap01.isEmpty())
        cout << "��ʱ��Ϊ��";
    else
        cout << "��ʱ�Ѳ�Ϊ��";
    cout << "\n�Ѵ�С��" << Heap01.getSize()
         << "\n��������" << Heap01.getCapacity();

    srand((unsigned) time(nullptr));
    int a = 20000, b = 100000;//n����[a,b];
    int n = (rand() % (b - a + 1)) + a;
    cout << "\n������" << n << "������" << endl;
    object *arr = new object[n];
    for (int i = 0; i < n; ++i) {
        arr[i].value = rand() % INT_MAX;
        arr[i].priority = rand() % INT_MAX;
    }
    clock_t SchemeOneStart, SchemeOneEnd;
    SchemeOneStart = clock();
    SchemeOne(arr, n);
    SchemeOneEnd = clock();
    cout << "SchemeOne����ʱ��" <<
         ((double) (SchemeOneEnd - SchemeOneStart) / CLOCKS_PER_SEC) * 1000 << "ms" << endl;

    clock_t SchemeTwoStart, SchemeTwoEnd;
    SchemeTwoStart = clock();
    SchemeTwo(arr, n);
    SchemeTwoEnd = clock();
    cout << "SchemeTwo����ʱ��" <<
         ((double) (SchemeTwoEnd - SchemeTwoStart) / CLOCKS_PER_SEC) * 1000 << "ms" << endl;

    clock_t SchemeTheStart, SchemeTheEnd;
    SchemeTheStart = clock();
    SchemeThe(arr, n);
    SchemeTheEnd = clock();
    cout << "SchemeThe����ʱ��" <<
         ((double) (SchemeTheEnd - SchemeTheStart) / CLOCKS_PER_SEC) * 1000 << "ms" << endl;

    return 0;
}