#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
    BinaryTree<char> bt01('#');
    const char *str01 = "ABC##DE##F##G#H##";
    cout << "ʹ��ǰ������������������ݹ飩str01 = \"ABC##DE##F##G#H##\"��";
    bt01.PreorderCreateBinaryTree(str01);
    cout << "\nǰ��������ݹ飩��";
    bt01.PreOrder();
    cout << "\nǰ��������ǵݹ飩��";
    bt01.NonRecursivePreOrder();
    cout << "\n����������ݹ飩��";
    bt01.InOrder();
    cout << "\n����������ǵݹ飩��";
    bt01.NonRecursiveInOrder();
    cout << "\n����������ݹ飩��";
    bt01.PostOrder();
    cout << "\n����������ǵݹ飩��";
    bt01.NonRecursivePostOrder();
    cout << "\n�����������ǵݹ飩��";
    bt01.LevelOrder();
    const char *str02 = "A(B(D,E(G,)),C(,F))#";
    cout << "\nʹ�ù���������������ǵݹ飩str02 = \"A(B(D,E(G,)),C(,F))#\"��";
    bt01.GeneralizedTableCreateBinaryTree(str02);
    cout << "\n           A              ";
    cout << "\n       B       C           ";
    cout << "\n    D     E      F        ";
    cout << "\n        G                   ";
    cout << "\nǰ��������ݹ飩��";
    bt01.PreOrder();
    cout << "\nǰ��������ǵݹ飩��";
    bt01.NonRecursivePreOrder();
    cout << "\n����������ݹ飩��";
    bt01.InOrder();
    cout << "\n����������ǵݹ飩��";
    bt01.NonRecursiveInOrder();
    cout << "\n����������ݹ飩��";
    bt01.PostOrder();
    cout << "\n����������ǵݹ飩��";
    bt01.NonRecursivePostOrder();
    cout << "\n�����������ǵݹ飩��";
    bt01.LevelOrder();
    cout << "\n������E���ڲ�Σ�";
    cout << bt01.NodeLevel('E');
    cout << "\n�ڵ�������";
    cout << bt01.Size();
    cout << "\nҶ���������";
    cout << bt01.LeafSize();
    cout << "\n�������ĸ߶ȣ�";
    cout << bt01.Height();
    cout << "\n������B�Ķȣ�";
    cout << bt01.DegreeOfNode('B');
    cout << "\n������C�Ķȣ�";
    cout << bt01.DegreeOfNode('C');
    cout << "\n���D��˫�ף�";
    cout << bt01.Parent('D');
    cout << "\n���E����Ů��";
    if (bt01.LeftChild('E'))
        cout << bt01.LeftChild('E');
    if (bt01.RightChild('E'))
        cout << bt01.RightChild('E');
    cout << "\n�������죨bt02����bt01����";
    BinaryTree<char> bt02(bt01);
    cout << "\n��������bt02���ǵݹ飩��";
    bt02.LevelOrder();
    BinaryTree<char> bt03;
    cout << "\nbt03����bt02��";
    bt03.CopyBinaryTree(bt02);
    cout << "\n��������bt03���ǵݹ飩��";
    bt03.LevelOrder();
    cout << "\n�����������bt01����";
    cout << bt01;
    return 0;
}