#ifndef BT_LITE_PARALLEL_SUB_TREE
#define BT_LITE_PARALLEL_SUB_TREE


#include "sub_tree.hpp"
#include <vector>

class parallelSubTree : public subTree{
public:
parallelSubTree():threshold_(-1){}

bool run(){
  int count = 0;
  
  for(auto i = sub_tree_vec_.begin(); i != sub_tree_vec_.end(); i++){
    if((*i)->run()) count ++;
  }
  
  if(count > threshold_){
    return true;
  }else{
    return false;
  }
}

void set_threshold(int threshold){
  threshold_ = threshold;
}

void add(subTree* sub_tree){
  sub_tree_vec_.push_back(sub_tree);
}

private:
std::vector<subTree*>          sub_tree_vec_;
int                       threshold_;

};

#endif