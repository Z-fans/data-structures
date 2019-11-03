#include <iostream>
#include <chrono>
#include "Sorter.h"

using namespace std;
using namespace chrono;

const int Size = 10000;//��������

int main() {
    srand((unsigned) time(nullptr));

    int min = 0, max = INT_MAX;

    int arr[Size];

    for (int i = 0; i < Size; ++i) { //�������Size������
        arr[i] = (rand() % (max - min + 1)) + min;
    }

    int arrTemp01[Size], arrTemp02[Size], arrTemp03[Size], arrTemp04[Size], arrTemp05[Size];
    int *arrTemps[] = {arrTemp01, arrTemp02, arrTemp03, arrTemp04, arrTemp05};

    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < Size; ++i) {
            arrTemps[j][i] = arr[i];
        }
    }

    pair<int, int> result;

    Sorter<int> sorter;

    auto start = system_clock::now();
    result = sorter.bubble_sort(arrTemps[0], Size);
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "ð������ıȽϴ�����" << result.first << "   �ƶ�������" << result.second
         << "   �ܺ�ʱ��"
         << (double(duration.count()) * microseconds::period::num / microseconds::period::den) * 1000
         << "ms"
         << endl;

    start = system_clock::now();
    result = sorter.selection_sort(arrTemps[1], Size);
    end = system_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "ѡ������ıȽϴ�����" << result.first << "   �ƶ�������" << result.second
         << "   �ܺ�ʱ��"
         << (double(duration.count()) * microseconds::period::num / microseconds::period::den) * 1000
         << "ms"
         << endl;

    start = system_clock::now();
    result = sorter.insertion_sort(arrTemps[2], Size);
    end = system_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "��������ıȽϴ�����" << result.first << "   �ƶ�������" << result.second
         << "   �ܺ�ʱ��"
         << (double(duration.count()) * microseconds::period::num / microseconds::period::den) * 1000
         << "ms"
         << endl;

    start = system_clock::now();
    result = sorter.merge_sort(arrTemps[3], Size);
    end = system_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "�鲢����ıȽϴ�����" << result.first << "   �ƶ�������" << result.second
         << "   �ܺ�ʱ��"
         << (double(duration.count()) * microseconds::period::num / microseconds::period::den) * 1000
         << "ms"
         << endl;

    start = system_clock::now();
    result = sorter.shell_sort(arrTemps[4], Size);
    end = system_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "ϣ������ıȽϴ�����" << result.first << "   �ƶ�������" << result.second
         << "   �ܺ�ʱ��"
         << (double(duration.count()) * microseconds::period::num / microseconds::period::den) * 1000
         << "ms"
         << endl;

    return 0;
}