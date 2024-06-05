#include<iostream>
using namespace std;
#include "create_binary_tree_using_recursive_defination.cpp"

//Final
int main()
{
    Tree t;
    t.createTree();
    cout<<"Preorder : "<<endl;
    t.preOrder(t.root);
    cout<<endl;
    cout<<"Postorder : "<<endl;
    t.PostOrder(t.root);
    cout<<endl;
    cout<<"Inorder : "<<endl;
    t.InOrder(t.root);
    cout<<endl;
    cout<<"Level order : "<<endl;
    t.LevelOrder(t.root);
    cout<<endl;
    cout<<"Hight of the tree is : "<<t.Height(t.root)<<endl;
    cout<<"Total numbers of node is : "<<t.count(t.root)<<endl;
    cout<<"Total number of leaf node is : "<<t.leaf_node(t.root)<<endl;
    cout<<"Total number of node with degree 2 is : "<<t.degree_2(t.root)<<endl;
    cout<<"Total number of node with degree 1 is : "<<t.degree_1(t.root)<<endl;
    cout<<"Total number of node with degree 1 or 2 is : "<<t.degree_1_or_2(t.root)<<endl;
return 0;
}