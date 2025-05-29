#ifndef BT_LITE_FALLBACK_SUB_TREE
#define BT_LITE_FALLBACK_SUB_TREE
#include "leaf_sub_tree.hpp"

class fallbackSubTree : public subTree{
public:
bool run(){
  for(auto i = sub_tree_vec_.begin(); i != sub_tree_vec_.end(); i++){
    if((*i)->run()) return true;
  }
  return false;
}

void add(subTree* sub_tree){
  sub_tree_vec_.push_back(sub_tree);
}

private:
std::vector<subTree*> sub_tree_vec_;

};
#endif