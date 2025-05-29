///////////////////////////////////////////////////////////////////////////////////////////
// @class:  leaf_sub_tree 
// @author: Zhang Zhongyan
// @date:   2024/06/07
//---------
// 叶子节点，内部只存储一个方法，运行也仅运行此方法，并返回此方法的返回即可
//---------
//TODO:
//  1. 没有在run()时添加对“有没有function”进行判断
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef BT_LITE_LEAF_SUB_TREE
#define BT_LITE_LEAF_SUB_TREE
#include "sub_tree.hpp"
#include <functional>

class leafSubTree: public subTree{
public:

bool run(){
  return function_();
}

void add(std::function<bool()> function){
  function_ = function;
}

private:
std::function<bool()> function_;

};
#endif