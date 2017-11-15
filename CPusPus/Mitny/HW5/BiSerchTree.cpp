//
// Created by R.Peters on 11/11/2017.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include <random>
#include "BiSerchTree.h"

using namespace std;

BiSerchTree::BiSerchTree():treeSize(0),capacity(InitCap){
    tree = new BSTNode[capacity];
};

/**
 *
 * @tparam T
 * @param t
 */
void BiSerchTree::add(const int &t) {
    auto tmp = BSTNode(t);
    if(tree[1].hasDatas()){
        unsigned int pos = 1;
        while(tree[pos].hasDatas()){
            pos = (tree[pos]<t)?pos*2+1:pos*2;
            if(pos > capacity) growTree((pos*2+1)*2+1);
        }
        tree[pos] = tmp;
        if(tmp <= tree[head]) head = pos;
        else if(tmp > tree[tail]) tail = pos;
    }else {
        tree[1] = tmp;
        tail = head = 1;
    }
    ++treeSize;
}

/**
 *
 * @tparam T
 * @param node
 */
void BiSerchTree::add(const BSTNode &node) {
    add(node.getData());
}

void BiSerchTree::growTree(int newCap) {
    BSTNode* tmp = new BSTNode[newCap];
    copy(tree, tree +capacity,tmp);
    delete[] tree;
    tree = tmp;
    capacity = newCap;
}

/**
 *
 * @tparam T
 * @param vec
 */
void BiSerchTree::addAll(const vector<BSTNode> &vec) {
    for(const auto &node : vec)add(node);
}

/**
 *
 * @tparam T
 * @param vec
 */
void BiSerchTree::addAll(const vector<int> &vec) {
    for(const auto &ele : vec){
        add(ele);
    }
}



const BSTNode* BiSerchTree::getTree() const {
    return tree;
}

ostream &operator<<(ostream &os, const BiSerchTree &bst) {
    os << "{ " << bst.getTree()[1].makeString();
    for(int i = 2; i < bst.capacity;++i) {
        if(bst.getTree()[i].hasDatas()) {
            os << "," << bst.getTree()[i].makeString();
        }
    }
    os << " }";
    return os;
}

int BiSerchTree::getSize() const {
    return treeSize;
}

BiSerchTree::~BiSerchTree() {
    delete[] tree;
}

int BiSerchTree::getCapacity() const {
    return capacity;
}

BSTNode &BiSerchTree::getHead() {
    return tree[head];
}

BSTNode &BiSerchTree::getTail() {
    return tree[tail];
}

/**
 *
 * @param name
 * @return
 */
vector<int> readFromRandoIntFile( const string& name){
    ifstream file(name);
    vector<int> dest;
    if(file.is_open()) while(file.good()) dest.push_back(file.get());
    return dest;

}

/**
 *
 * @param name
 * @param lowBound
 * @param hiBound
 */
void generateRandoIntFile(const string& name,const int &lowBound,const int &hiBound){
    ofstream myfile;
    myfile.open(name, ofstream::app);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(lowBound,hiBound);
    int burner = distribution(generator);
    myfile << distribution(generator);
    for(int i = 0; i < 100;++i){
        myfile << "," << distribution(generator);
        myfile.flush();
    }

    myfile.close();
}


/**
 *
 * @return
 */
int main() {
    BiSerchTree biTree = BiSerchTree();

    // I generated this test vector by using the the generateRanoIntFile function to create a stored list of random ints
    // which I then copy/pasted into the bellow vector for use in testing.
    vector<int> testingData = {132,756,459,533,219,48,679,680,935,384,520,831,35,54,530,672,8,384,67,418,687,589,931,847,
                               527,92,654,416,702,911,763,263,48,737,329,633,757,992,366,248,983,723,754,652,73,632,885,
                               273,437,767,478,238,275,360,167,487,898,910,61,905,505,517,320,987,494,267,91,948,74,501,
                               385,278,914,530,465,941,51,762,771,828,126,16,689,869,630,737,726,1000,889,234,307,352,
                               514,592,846,413,842,270,416,538,468};

    cout << "number of values in fromFile = " << testingData.size() << endl;
    for(int i = 0; i < testingData.size(); ++i){
//        cout << testingData[i] << endl;
        biTree.add(testingData[i]);
//        cout << biTree<< "\nnumber of elements in biTree = " << biTree.getSize()<<"\ncapacity of biTree = " << biTree.getCapacity()<<endl<<endl;
    }
//    biTree.add(10);
//    biTree.add(10);
//    biTree.add(20);
//    biTree.add(1);
//    biTree.add(30);
    cout << biTree;
    cout << "\n\nwhat does the head produce? biTree.getHead() = " << biTree.getHead().makeString();
    cout << "\n\nwhat does the tail produce? biTree.getHead() = " << biTree.getTail().makeString();

    return 0;
}