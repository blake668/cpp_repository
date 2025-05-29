#ifndef BT_LITE_SEQUENCE_SUB_TREE
#define BT_LITE_SEQUENCE_SUB_TREE
#include "leaf_sub_tree.hpp"

#include <vector>

class sequenceSubTree : public subTree{
public:
bool run(){
  for(auto i = sub_tree_vec_.begin(); i != sub_tree_vec_.end(); i++){
    if(!(*i)->run()) return false;
  }
  return true;
}

void add(subTree* sub_tree){
  sub_tree_vec_.push_back(sub_tree);
}

private:
std::vector<subTree*> sub_tree_vec_;

};
#endif
