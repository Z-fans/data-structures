#include <iostream>
#include "DoubleLinkedList.h"
#include "Student.h"

int main() {
    //����˫��������� ���ݱ���ΪStudent
    DoubleLinkedList<Student> stuList;
    //�����ݱ����������
    for (int i = 37; i <= 47; ++i) {
        Student s(to_string(i - 36), i - 10, i - 20);
        stuList.push_back(s);
    }

    cout << "��ӡ����" << endl;
    stuList.DisplayData(); //��ӡ����
    cout << endl << "��ӡ�����ȣ�";
    cout << endl << stuList.Length() << "��ѧ��" << endl << endl;           //��ӡ������


    cout << "���Կ������캯����" << endl;
    DoubleLinkedList<Student> stuList2(stuList);         //���Կ������캯��

    stuList2.DisplayData();
    cout << endl << stuList2.Length() << "��ѧ��" << endl << endl;

    cout << "����=���أ�" << endl;
    DoubleLinkedList<Student> stuList3 = stuList2;         //����=����

    stuList3.DisplayData();
    cout << endl << stuList3.Length() << "��ѧ��" << endl << endl;

    cout << "������ָ��Ԫ��ǰ���룺" << endl;
    Student t1;
    Student t2("InsertBeforeTheSpecifiedElement", 32, 23);
    stuList3.getDataByIndex(3, t1);
    stuList3.InsertBeforeTheSpecifiedElement(t1, t2);    //������ָ��Ԫ��ǰ����
    stuList3.DisplayData();
    cout << endl << stuList3.Length() << "��ѧ��" << endl << endl;

    cout << "����ָ��Ԫ��֮����룺" << endl;
    Student t3;
    Student t4("InsertAfterTheSpecifiedElement", 45, 11);
    stuList3.getDataByIndex(3, t3);
    stuList3.InsertAfterTheSpecifiedElement(t3, t4);    //����ָ��Ԫ��֮�����
    stuList3.DisplayData();
    cout << endl << stuList3.Length() << "��ѧ��" << endl << endl;

    cout << "������ָ��λ����ɲ��룺" << endl;
    Student t5("InsertAtTheSpecifiedLocation", 35, 41);
    stuList3.InsertAtTheSpecifiedLocation(2, t5);    //������ָ��λ����ɲ���
    stuList3.DisplayData();
    cout << endl << stuList3.Length() << "��ѧ��" << endl << endl;

    cout << "�����߼�ɾ����" << endl;
    stuList3.LogicalDeleteTheSpecifiedElement(t5);    //�����߼�ɾ��
    stuList3.LogicalDeleteElementAtSpecifiedLocation(3);
    stuList3.DisplayData();
    cout << endl << "�߼�ɾ���Ķ���" << endl;
    stuList3.DisplayLogicallyDeletedData();
    cout << endl << stuList3.Length() << "��ѧ��" << endl << endl;

    cout << "������߼��ָ���" << endl;
    stuList3.LogicalRecoveryOfSpecifiedElement(t5);//�����߼��ָ�
    stuList3.DisplayData();
    cout << endl << "�߼�ɾ���Ķ���" << endl;
    stuList3.DisplayLogicallyDeletedData();
    cout << endl << stuList3.Length() << "��ѧ��" << endl << endl;

    cout << "��������ɾ����" << endl;
    stuList3.PhysicalDeleteTheSpecifiedElement(t5);//��������ɾ��
    stuList3.DisplayData();
    cout << endl << "�߼�ɾ���Ķ���" << endl;
    stuList3.DisplayLogicallyDeletedData();
    cout << endl << stuList3.Length() << "��ѧ��" << endl << endl;

    cout << "���Իָ�����ɾ������t5��" << endl;
    if (!stuList3.LogicalRecoveryOfSpecifiedElement(t5))
        cout << "�ָ�����ɾ������ʧ��" << endl;    //ʧ����ʾ
    stuList3.DisplayData();
    cout << endl << "�߼�ɾ���Ķ���" << endl;
    stuList3.DisplayLogicallyDeletedData();
    cout << endl << stuList3.Length() << "��ѧ��" << endl << endl;

    cout << "�����޸ģ�" << endl;
    Student t6("������", 100, 100);
    stuList3.ModifyDataForSpecifiedElement(t4, t6);
    stuList3.DisplayData();
    cout << endl << "�߼�ɾ���Ķ���" << endl;
    stuList3.DisplayLogicallyDeletedData();
    cout << endl << stuList3.Length() << "��ѧ��" << endl << endl;

    cout << "�����ļ���д��" << endl;
    string file = "student.txt";
    stuList3.WriteDataToFile(file);

    DoubleLinkedList<Student> stuList4;
    stuList4.ReadDataFromAFile(file);
    stuList4.DisplayData();
    cout << endl << "�߼�ɾ���Ķ���" << endl;
    stuList4.DisplayLogicallyDeletedData();
    cout << endl << stuList4.Length() << "��ѧ��" << endl << endl;

    cout << "���Բ�ѯ��" << endl;
    if (stuList4.QuerySpecifiedElement(t6))
        cout << t6 << " ����" << endl << endl;

    cout << "�����Ż�ð������" << endl;
    stuList4.Sort();
    stuList4.DisplayData();
    cout << endl << "�߼�ɾ���Ķ���" << endl;
    stuList4.DisplayLogicallyDeletedData();
    cout << endl << stuList4.Length() << "��ѧ��" << endl << endl;


    cout << "�����߼���գ�" << endl;
    stuList4.toLogicalEmpty();
    stuList4.DisplayData();
    cout << endl << "�߼�ɾ���Ķ���" << endl;
    stuList4.DisplayLogicallyDeletedData();
    cout << endl << stuList4.Length() << "��ѧ��" << endl << endl;

    cout << "����������գ�" << endl;
    stuList4.toPhysicalEmpty();
    stuList4.DisplayData();
    cout << endl << "�߼�ɾ���Ķ���" << endl;
    stuList4.DisplayLogicallyDeletedData();
    cout << endl << stuList4.Length() << "��ѧ��" << endl << endl;

    return 0;
}