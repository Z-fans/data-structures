#include <iostream>
#include "ArrayQueue.h"

int main() {
    ArrayQueue<int> queue;    //����һ������

    for (int i = 0; i < 100; ++i) {     //ѹ��100������
        queue.push(i);
    }
    cout << "ȡ������Ԫ�أ�" << queue.front() << endl;
    cout << "ȡ����βԪ�أ�" << queue.back() << endl;
    cout << "���д�С��" << queue.size() << endl;
    cout << "�����Ƿ�Ϊ�գ�1/0����" << queue.empty() << endl;
    cout << "������Ԫ�س��ӣ�1��ʾ�ɹ���0��ʾʧ�ܣ���" << queue.pop() << endl;
    cout << "ȡ������Ԫ�أ�" << queue.front() << endl;
    cout << "ȡ����βԪ�أ�" << queue.back() << endl;
    cout << "���д�С��" << queue.size() << endl;
    cout << "�����Ƿ�Ϊ�գ�1/0����" << queue.empty() << endl;

    ArrayQueue<int> PrintBinomialCoefficients;
    cout << "��ӡ����ʽϵ����8�㣩��" << endl;
    PrintBinomialCoefficients.PrintBinomialCoefficients(8);
    return 0;
}