//
// Created by R.Peters on 11/12/2017.
//
#include <iostream>
#include <sstream>
#include "BSTNode.h"

using namespace std;


BSTNode::BSTNode(int _data) : data(_data), hasData(true) {}


std::string BSTNode::makeString() const {
    stringstream ss;
    ss << data;
    return ss.str();
}

int BSTNode::getData() const {
    return data;
}

void BSTNode::setData(int _data) {
    data = _data;
}

bool BSTNode::hasDatas() const {
    return hasData;
}
