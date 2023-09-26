// 很离谱，输入很头疼，cin遇到空格会停，while(cin >> data)会一直等待输入，改用cin.getline
#include <bits/stdc++.h>
using namespace std;

struct mypair{
  string key;
  int value;
};

bool cmp(mypair a, mypair b) {
  if (a.value == b.value){
    return a.key > b.key; //小于就是大的在前面，大于就是大的在后面
  }else{
    return a.value < b.value; //小于就是大的在前面，大于就是大的在后面
  }
}

void quick_sort(vector<mypair> &final_data, int left, int right) {
    if (left >= right) {
        return;
    }
    int l = left;
    int r = right;
    int middle = (left + right) >> 1;
    while(left < right) {
        while (cmp(final_data[left], final_data[middle])) {
            left++;
        }
        while(cmp(final_data[middle], final_data[right])) {
            right--;
        }
        if (left < right) {
            swap(final_data[left], final_data[right]);
            left++;
            right--;
        }
    }
    quick_sort(final_data, l, middle);
    quick_sort(final_data, middle+1, r); //这里必须是middle+1，否则死循环，当只剩最后两个元素的时候，比如l = 0, middle = 0, r = 1时，(middle, r)就会一直重复(0,1)
}

int main() {
  // const int bufferSize = 100;
  // char data[bufferSize];
  // cin.getline(data, bufferSize);
  // int length = strlen(data);
  // for (int i = 0; i < length; i++) {
  //   cout << data[i] << endl;
  //   if (data[i] == '\0') {
  //     break;
  //   }
  // }
  string input;
  getline(cin, input);
  istringstream iss(input); // 使用istringstream将字符串转换为输入流
  vector<string> parts; // 存储分隔后的部分
  string part;
  while (iss >> part) { // 使用输入流的运算符>>按空格分隔字符串
    parts.push_back(part); // 将分隔后的部分存储到vector中
  }
  // // 输出分隔后的部分
  // for (const auto& str : parts) {
  //   cout << str << endl;
  // }
  set<string> myset;
  vector<mypair> final_data;
  unordered_map<string, int> mymap;
  for (const auto& str : parts) {
    myset.insert(str);
    if(mymap.count(str) != 0) {
      mymap[str] += 1;
    }else{
      mymap.insert({str, 1});
    }
  }
  for (auto i : myset){
    if (mymap[i] >= 3) {
      mypair *a = new mypair;
      a->key = i;
      a->value = mymap[i];
      final_data.push_back(*a);
    }
  }
//   //选择排序
//   for (int i = 0; i < final_data.size(); i++){
//     for (int j = i+1; j < final_data.size(); j++){
//       if (cmp(final_data[i], final_data[j])) {
//         mypair tmp;
//         tmp = final_data[i];
//         final_data[i] = final_data[j];
//         final_data[j] = tmp;
//       }
//     }
//   }
  //快速排序
  int left = 0, right = final_data.size() - 1;
  quick_sort(final_data, left, right);
  for (int i = 0; i < final_data.size(); i++) {
    cout << final_data[i].key << endl;
  }
  return 0;
}