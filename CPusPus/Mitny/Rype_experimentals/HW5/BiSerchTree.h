//
// Created by R.Peters on 11/11/2017.
//

#ifndef HW5_BISERCHTREE_H
#define HW5_BISERCHTREE_H

#include <vector>
#include <type_traits>
#include <cstddef>
#include <iosfwd>
#include <ostream>
#include "BSTNode.h"


#define InitCap 10
class BiSerchTree {
//    static_assert(
//            std::is_same<T, int>::value ||
//            std::is_same<T, unsigned int>::value ||
//            std::is_same<T, long int>::value ||
//            std::is_same<T, unsigned long int>::value ||
//            std::is_same<T, float>::value ||
//            std::is_same<T, double>::value ||
//            std::is_same<T, long double>::value,
//                  "Given typename int needs to be one of the following: int, float, or double! Good day... I said good day!!!");


public:

    BiSerchTree();

    virtual ~BiSerchTree();

    void add(const int& t);
    void add(const BSTNode& node);
    void addAll(const std::vector<BSTNode> &vec);
    void addAll(const std::vector<int> &vec);
    const BSTNode* getTree() const ;
    int getSize()const;
    void growTree(int newCap);
    friend std::ostream &operator<<(std::ostream &os, const BiSerchTree &bst);
    BSTNode& getHead();
    BSTNode& getTail();
    int getCapacity() const;

private:

    /*
     * Because we will be storing the tree in an array, we only need to maintain pointers to the head and tail "nodes"
     * of the tree. The root node is implicitly tracked as the first element of the array, default referenced to index 1.
     * */
    int head = 0,tail = 0;

    /*
     * We will use a vector<T> container for organizing and handeling the nodes of the tree. This will greatly simplify
     * the task of conducting a breadth first search.
     *
     * However, if the data is passed in ascending order, we encounter a very wasteful Big-O space complexity. That is
     * to say, if passed a stream of integers from 1 to 10, the value for 10 would end up being stored in the 2047'th
     * index position of our array... This is due to how we will be handling the left/right branching between parent and
     * child nodes.
     *
     * For any parent node of index i, the child nodes will be at index 2*i, and 2*i+1.
     *
     * root will be at index 1, in the interest of the above stated branching strategy an index of zero just makes for
     * messy logic. Therefor, the zero'th index will be left blank.
     */
    BSTNode* tree;
    int treeSize, capacity;

};


#endif //HW5_BISERCHTREE_H
