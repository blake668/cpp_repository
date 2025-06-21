#include <vector>
#include <iostream>

using namespace std;

int main(){
  int a;
  vector<int> arr;
  a = 0;
  arr.push_back(a);
  a = 1;
  arr.push_back(a);
  a = 2;
  arr.push_back(a);
  a = 3;
  arr.push_back(a);
  cout<<"i++ --------"<<endl;
  for(int i = 0; i < arr.size(); i++){
    cout<<"arr["<<std::to_string(i)<<"]: "<<std::to_string(arr[i])<<endl;
  }
  cout<<"------------"<<endl;
  cout<<"++i --------"<<endl;
  for(int i = 0; i < arr.size(); ++i){
    cout<<"arr["<<std::to_string(i)<<"]: "<<std::to_string(arr[i])<<endl;
  }
  cout<<"------------"<<endl;
  for(int i = 0; i <arr.size(); ){
    int a = arr[i++];
    cout<<std::to_string(a)<<endl;
  }
  cout<<"------------"<<endl;
  for(int i = 0; i <arr.size(); ){
    int a = arr[++i];
    cout<<std::to_string(a)<<endl;
  }

  return 0;
}
/*
zhangzh6@zhangzh6-ThinkPad-P52:~/cpp_ws$ ./test_i++_++i 
i++ --------
arr[0]: 0
arr[1]: 1
arr[2]: 2
arr[3]: 3
------------
++i --------
arr[0]: 0
arr[1]: 1
arr[2]: 2
arr[3]: 3
------------
0
1
2
3
------------
1
2
3
0
*/
