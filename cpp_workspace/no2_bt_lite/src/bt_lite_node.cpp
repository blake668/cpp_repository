#include <cstdio>
#include <iostream>

#include "../include/sub_tree.hpp"
#include "../include/leaf_sub_tree.hpp"
#include "../include/sequence_sub_tree.hpp"
#include "../include/fallback_sub_tree.hpp"
#include "../include/parallel_sub_tree.hpp"

int counter = 0; 

bool func_1(){
  std::cout<<"\033[34mfunc_1() thred: 4\033[0m";
  
  if(counter > 4){
    std::cout<<" func1: pass"<<std::endl;
    return true;
  }
  
  std::cout<<"\033[31m func1: not pass\033[0m"<<std::endl;
  return false;
}

bool func_2(){
  std::cout<<"\033[34mfunc_2() thred: 7\033[0m";
  
  if(counter > 7){
    std::cout<<" func2: pass"<<std::endl;
    return true;
  }
  
  std::cout<<"\033[31m func2: not pass\033[0m"<<std::endl;
  return false;
}

bool func_3(){  
  std::cout<<"\033[34mfunc_3() thred: 10\033[0m";
  
  if(counter > 10){
    std::cout<<" func3: pass"<<std::endl;
    return true;
  }
  
  std::cout<<"\033[31m func3: not pass\033[0m"<<std::endl;
  return false;
}


int main(int argc, char ** argv)
{
  (void) argc;
  (void) argv;
  /*
  leafSubTree leaf;
  
  leaf.add(&greater);
  
  if(leaf.run()){
    printf("leaf return true\n");
  }else{
    printf("leaf return false\n");
  }
  */
  counter = 0;
  
  leafSubTree leaf_1;
  leaf_1.add(&func_1);
  
  leafSubTree leaf_2;
  leaf_2.add(&func_2);
  
  leafSubTree leaf_3;
  leaf_3.add(&func_3);
  
  sequenceSubTree seq_sub_tree;
  seq_sub_tree.add(&leaf_1);
  seq_sub_tree.add(&leaf_2);
  seq_sub_tree.add(&leaf_3);
  
  sequenceSubTree seq_sub_tree_1;
  seq_sub_tree_1.add(&seq_sub_tree);
  
  fallbackSubTree fbk_sub_tree;
  fbk_sub_tree.add(&leaf_1);
  fbk_sub_tree.add(&leaf_2);
  fbk_sub_tree.add(&leaf_3);
  
  parallelSubTree prl_sub_tree;
  prl_sub_tree.add(&leaf_1);
  prl_sub_tree.add(&leaf_2);
  prl_sub_tree.add(&leaf_3);
  prl_sub_tree.set_threshold(1);
  
  for(int i = 0 ; i < 20; i++){
  
    std::cout<<"head: counter:"<<std::to_string(counter)<<std::endl;
    
    //seq_sub_tree.run();
    
    if(!seq_sub_tree_1.run()){
      std::cout<<"seq_sub_tree_1: not pass"<<std::endl;
    }else{
      std::cout<<"seq_sub_tree_1: pass"<<std::endl;
    }
    
    if(!fbk_sub_tree.run()){
      std::cout<<"fbk_sub_tree: not pass"<<std::endl;
    }else{
      std::cout<<"fbk_sub_tree: pass"<<std::endl;
    }
    
    if(!prl_sub_tree.run()){
      std::cout<<"prl_sub_tree: not pass"<<std::endl;
    }else{
      std::cout<<"prl_sub_tree: pass"<<std::endl;
    }   
    
    std::cout<<"----"<<std::endl;
    counter++;
  }
  
  
  
  
  return 0;
}