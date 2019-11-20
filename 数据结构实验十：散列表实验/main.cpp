#include <iostream>
#include <fstream>
#include "ClosedHashTable.h"
#include "Contact.h"
#include "OpenHashTable.h"
#include <cmath>

using namespace std;

unsigned long long userNameHash(const string &str) {
    unsigned long long key = 0;
    int i = str.size() - 1;
    for (auto ele:str) {
        key += ele * pow(10, i--);
    }
    return key;
}

int main() {
    cout << "���������ݹ�1000�飬��test.txt�ļ��ж�ȡ��" << endl;

    cout << "---------------------------------------------------------------------��ɢ�б�-����̽�ⷨ-�Ե绰����Ϊ�ؼ���" << endl;
    cout << "ʹ�ñ�ɢ�б�Ĺ��췽������������̽�ⷨ�����ͻ��" << endl;
    cout << "�Ե绰����Ϊ�ؼ��ֽ���ɢ�б�" << endl << endl;

    ifstream in01(R"(C:\Users\10944\Desktop\HashTable\test.txt)"); //�������������� �ļ�·������˵��Զ���

    ClosedHashTable<Contact> closedHT01(79);  //��������79Ϊɢ�к�������

    //����1000��������
    Contact temp01;
    while (in01 >> temp01) {
        closedHT01.Insert(temp01.getTellNumber(), temp01);
    }

    cout << "��������������13320572294Ϊ���������еĵ�100�����ݣ�" << endl;
    if (closedHT01.Search(13320572294, temp01)) {//�����ɹ�����true ��������������Ϣ��ֵ��temp δ�����ɹ�����false
        cout << "����13320572294�ɹ������������" << temp01 << endl;
    } else
        cout << "����13320572294ʧ�ܣ�" << endl;

    cout << "����ɾ��������ɾ��13320572294��13320572294Ϊ���������еĵ�100�����ݣ�" << endl;
    if (closedHT01.Remove(13320572294)) {
        cout << "ɾ��13320572294�ɹ���" << endl << endl;
    } else
        cout << "ɾ��13320572294ʧ�ܣ�" << endl << endl;

    cout << "��������������13320572294Ϊ���������еĵ�100�����ݣ�" << endl;
    if (closedHT01.Search(13320572294, temp01)) {//�����ɹ�����true ��������������Ϣ��ֵ��temp δ�����ɹ�����false
        cout << "����13320572294�ɹ������������" << temp01 << endl;
    } else
        cout << "����13320572294ʧ�ܣ�" << endl;

    cout << "---------------------------------------------------------------------��ɢ�б�-����̽�ⷨ-���û���Ϊ�ؼ���" << endl;
    cout << "ʹ�ñ�ɢ�б�Ĺ��췽������������̽�ⷨ�����ͻ��" << endl;
    cout << "���û���Ϊ�ؼ��ֽ���ɢ�б�" << endl << endl;

    ifstream in02(R"(C:\Users\10944\Desktop\HashTable\test.txt)"); //�������������� �ļ�·������˵��Զ���

    ClosedHashTable<Contact> closedHT02(79);  //��������79Ϊɢ�к�������

    //����1000��������
    Contact temp02;
    while (in02 >> temp02) {
        closedHT02.Insert(userNameHash(temp02.getUserName()), temp02);
    }

    cout << "��������������PQDATQHNVFOEVNOΪ���������еĵ�600�����ݣ�" << endl;
    if (closedHT02.Search(userNameHash("PQDATQHNVFOEVNO"), temp02)) {//�����ɹ�����true ��������������Ϣ��ֵ��temp δ�����ɹ�����false
        cout << "����PQDATQHNVFOEVNO�ɹ������������" << temp02 << endl;
    } else
        cout << "����PQDATQHNVFOEVNOʧ�ܣ�" << endl;

    cout << "����ɾ��������ɾ��PQDATQHNVFOEVNO��PQDATQHNVFOEVNOΪ���������еĵ�600�����ݣ�" << endl;
    if (closedHT02.Remove(userNameHash("PQDATQHNVFOEVNO"))) {
        cout << "ɾ��PQDATQHNVFOEVNO�ɹ���" << endl << endl;
    } else
        cout << "ɾ��PQDATQHNVFOEVNOʧ�ܣ�" << endl << endl;

    cout << "��������������PQDATQHNVFOEVNOΪ���������еĵ�600�����ݣ�" << endl;
    if (closedHT02.Search(userNameHash("PQDATQHNVFOEVNO"), temp02)) {//�����ɹ�����true ��������������Ϣ��ֵ��temp δ�����ɹ�����false
        cout << "����PQDATQHNVFOEVNO�ɹ������������" << temp02 << endl;
    } else
        cout << "����PQDATQHNVFOEVNOʧ�ܣ�" << endl;

    cout << "---------------------------------------------------------------------��ɢ�б�-������-�Ե绰����Ϊ�ؼ���" << endl;
    cout << "ʹ�ÿ�ɢ�б�Ĺ��췽�������������������ͻ��" << endl;
    cout << "�Ե绰����Ϊ�ؼ��ֽ���ɢ�б�" << endl << endl;

    ifstream in03(R"(C:\Users\10944\Desktop\HashTable\test.txt)"); //�������������� �ļ�·������˵��Զ���

    OpenHashTable<Contact> openHT01(79);  //��������79Ϊɢ�к�������

    //����1000��������
    Contact temp03;
    while (in03 >> temp03) {
        openHT01.Insert(temp03.getTellNumber(), temp03);
    }

    cout << "��������������13345982139Ϊ���������еĵ�300�����ݣ�" << endl;
    if (openHT01.Search(13345982139, temp03)) {//�����ɹ�����true ��������������Ϣ��ֵ��temp δ�����ɹ�����false
        cout << "����13345982139�ɹ������������" << temp03 << endl;
    } else
        cout << "����13345982139ʧ�ܣ�" << endl;

    cout << "����ɾ��������ɾ��13345982139��13345982139Ϊ���������еĵ�300�����ݣ�" << endl;
    if (openHT01.Remove(13345982139)) {
        cout << "ɾ��13345982139�ɹ���" << endl << endl;
    } else
        cout << "ɾ��13345982139ʧ�ܣ�" << endl << endl;

    cout << "��������������13345982139Ϊ���������еĵ�300�����ݣ�" << endl;
    if (openHT01.Search(13345982139, temp03)) {//�����ɹ�����true ��������������Ϣ��ֵ��temp δ�����ɹ�����false
        cout << "����13345982139�ɹ������������" << temp03 << endl;
    } else
        cout << "����13345982139ʧ�ܣ�" << endl;

    cout << "---------------------------------------------------------------------��ɢ�б�-������-���û���Ϊ�ؼ���" << endl;
    cout << "ʹ�ÿ�ɢ�б�Ĺ��췽�������������������ͻ��" << endl;
    cout << "���û���Ϊ�ؼ��ֽ���ɢ�б�" << endl << endl;

    ifstream in04(R"(C:\Users\10944\Desktop\HashTable\test.txt)"); //�������������� �ļ�·������˵��Զ���

    OpenHashTable<Contact> openHT02(79);  //��������79Ϊɢ�к�������

    //����1000��������
    Contact temp04;
    while (in04 >> temp04) {
        openHT02.Insert(userNameHash(temp04.getUserName()), temp04);
    }

    cout << "��������������IVTJEUNZLGATΪ���������еĵ�800�����ݣ�" << endl;
    if (openHT02.Search(userNameHash("IVTJEUNZLGAT"), temp04)) {//�����ɹ�����true ��������������Ϣ��ֵ��temp δ�����ɹ�����false
        cout << "����IVTJEUNZLGAT�ɹ������������" << temp04 << endl;
    } else
        cout << "����IVTJEUNZLGATʧ�ܣ�" << endl;

    cout << "����ɾ��������ɾ��IVTJEUNZLGAT��IVTJEUNZLGATΪ���������еĵ�800�����ݣ�" << endl;
    if (openHT02.Remove(userNameHash("IVTJEUNZLGAT"))) {
        cout << "ɾ��IVTJEUNZLGAT�ɹ���" << endl << endl;
    } else
        cout << "ɾ��IVTJEUNZLGATʧ�ܣ�" << endl << endl;

    cout << "��������������IVTJEUNZLGATΪ���������еĵ�800�����ݣ�" << endl;
    if (openHT02.Search(userNameHash("IVTJEUNZLGAT"), temp04)) {//�����ɹ�����true ��������������Ϣ��ֵ��temp δ�����ɹ�����false
        cout << "����IVTJEUNZLGAT�ɹ������������" << temp04 << endl;
    } else
        cout << "����IVTJEUNZLGATʧ�ܣ�" << endl;

    cout << "---------------------------------------------------------------------�Աȷ��������ֲ�ͬ�����ͻ������ƽ����������ֵ�ı仯" << endl;

    int flag = 1;
    cout << "����̽�ⷨ��ƽ����������ֵ�ı仯��100��~200��~300�Ρ����������Ի���ÿ��̽��ɢ�б���Ԫ�ض�+1����" << endl;
    for (auto ele:closedHT01.getAsl()) {
        flag++;
        if (flag % 100 == 0)
            cout << ele << " ";
    }

    flag = 1;
    cout << endl << "��������ƽ����������ֵ�ı仯��100��~200��~300�Ρ����������Ի���ÿ��̽��ɢ�б���Ԫ�ض�+1����" << endl;
    for (auto ele:openHT01.getAsl()) {
        flag++;
        if (flag % 100 == 0)
            cout << ele << " ";
    }

    return 0;
}