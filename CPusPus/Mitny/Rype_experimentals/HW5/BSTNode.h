//
// Created by R.Peters on 11/12/2017.
//

#ifndef HW5_BSTNODE_H
#define HW5_BSTNODE_H

#include <iosfwd>
#include <cstddef>
#include <string>
class BSTNode{
public:
    explicit BSTNode(int _data);
    BSTNode() = default;

    bool operator==(const int &dat)const{return data == dat;}
    bool operator!=(const int &dat)const{return data != dat;}
    bool operator>=(const int &dat)const{return data >= dat;}
    bool operator<=(const int &dat)const{return data <= dat;}
    bool operator>(const int &dat)const{return data > dat;}
    bool operator<(const int &dat)const{return data < dat;}

    bool operator==(const BSTNode &dat)const{return data == dat.data;}
    bool operator!=(const BSTNode &dat)const{return data != dat.data;}
    bool operator>=(const BSTNode &dat)const{return data >= dat.data;}
    bool operator<=(const BSTNode &dat)const{return data <= dat.data;}
    bool operator>(const BSTNode &dat)const{return data > dat.data;}
    bool operator<(const BSTNode &dat)const{return data < dat.data;}

    std::string makeString()const;
    int getData()const;
    void setData(int _data);
    bool hasDatas()const;
private:
    bool hasData = false;
    int data;

};


#endif //HW5_BSTNODE_H
