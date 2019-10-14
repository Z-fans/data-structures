#include <iostream>
#include "SeqList.h"
#include "Student.h"

int main() {

    //����˳������ ���ݱ���ΪStudent

    SeqList<Student> stu01;

    //�����ݱ����������

    for (int i = 37; i <= 100; ++i) {
        Student s(to_string(i - 36), i - 10, i - 20);
        stu01.push_back(s);
    }

    stu01.DisplayData();                 //��ӡ˳���
    cout << endl << stu01.Length() << endl;           //��ӡ˳�����

    SeqList<Student> stu02(stu01);         //���Կ������캯��
    stu02.DisplayData();
    cout << endl << stu02.Length() << endl;

    SeqList<Student> stu03 = stu02;         //����=����
    stu03.DisplayData();
    cout << endl << stu03.Length() << endl;

    //������ָ��Ԫ��ǰ����

    Student t1("InsertBeforeTheSpecifiedElement", 32, 23);
    Student t2;
    int index01 = 64;
    stu03.getDataByIndex(index01, t2);
    stu03.InsertBeforeTheSpecifiedElement(t2, t1);
    stu03.DisplayData();
    cout << endl << stu03.Length() << endl;

    //����ָ��Ԫ��֮�����

    Student t3("InsertAfterTheSpecifiedElement", 56, 76);
    Student t4;
    int index02 = 65;
    stu03.getDataByIndex(index02, t4);
    cout << stu03.LocateTheOrdinalNumberOfTheSpecifiedElement(t4) << endl;
    stu03.InsertAfterTheSpecifiedElement(t4, t3);
    stu03.DisplayData();
    cout << endl << stu03.Length() << endl;

    //������ָ��λ����ɲ���

    Student t5("InsertAtTheSpecifiedLocation", 12, 21);
    int index03 = 1;
    stu03.InsertAtTheSpecifiedLocation(index03, t5);
    stu03.DisplayData();
    cout << endl << stu03.Length() << endl;

//�����߼�ɾ��

    stu03.LogicalDeleteTheSpecifiedElement(t5);
    stu03.DisplayData();
    cout << endl << "�߼�ɾ���Ķ���" << endl;
    stu03.DisplayLogicallyDeletedData();
    cout << endl << stu03.Length() << endl;

    stu03.LogicalDeleteElementAtSpecifiedLocation(index03);
    stu03.DisplayData();
    cout << endl << "�߼�ɾ���Ķ���" << endl;
    stu03.DisplayLogicallyDeletedData();
    cout << endl << stu03.Length() << endl;

    //�����߼��ָ�
    stu03.LogicalRecoveryOfSpecifiedElement(t5);
    stu03.DisplayData();
    cout << endl << "�߼�ɾ���Ķ���" << endl;
    stu03.DisplayLogicallyDeletedData();
    cout << endl << stu03.Length() << endl;

    //��������ɾ��

    stu03.PhysicalDeleteTheSpecifiedElement(t5);
    stu03.PhysicalDeleteElementAtSpecifiedLocation(index03);
    stu03.DisplayData();
    cout << endl << stu03.Length() << endl;

    // ���Իָ�����ɾ������

    if (!stu03.LogicalRecoveryOfSpecifiedElement(t5))
        cout << "���Իָ�����ɾ������ʧ��" << endl; //ʧ����ʾ
    stu03.DisplayData();
    cout << endl << stu03.Length() << endl;

    //�������

    stu03.Sort();
    stu03.DisplayData();
    cout << endl << stu03.Length() << endl;

    //�����޸�
    Student t6("������", 100, 100);
    Student t7;
    stu03.getDataByIndex(index01, t7);
    stu03.ModifyDataForSpecifiedElement(t7, t6);
    stu03.DisplayData();
    cout << endl << stu03.Length() << endl;

    //�����ļ���д
    string sf = "student.txt";
    stu03.WriteDataToFile(sf);   //д

    SeqList<Student> stu04;
    stu04.ReadDataFromAFile(sf);    //��
    cout << "stu04:" << endl;
    stu04.DisplayData();
    cout << endl << stu04.Length() << endl;

    //�����߼����
    stu04.toLogicalEmpty();
    cout << stu04.Length() << endl;
    cout << "�߼�ɾ���Ķ���" << endl;
    stu04.DisplayLogicallyDeletedData();

    //�߼��ָ�һ������

    Student t8("������", 100, 100);
    stu04.LogicalRecoveryOfSpecifiedElement(t8);
    cout << endl << "�߼��ָ��Ķ���" << endl;
    stu04.DisplayData();

    //���Բ�ѯ

    cout << endl << "---" << stu04.QuerySpecifiedElement(t8) << "---" << endl;

    //�����������

    stu04.toPhysicalEmpty();
    cout << endl << "������պ󳤶�Ϊ��" << stu04.Length() << endl;
    stu04.DisplayData();
    stu04.DisplayLogicallyDeletedData();

    return 0;
}