/* Longest Substring Without Repeating Characters */
#include<iostream>
#include<unordered_set>
#include<string>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>letters;
        int len = 0;
        int left = 0;
        for (int i = 0;i < s.size();i++) {
            while (letters.count(s[i])) {
                letters.erase(s[left]);
                left++;
            }
            letters.insert(s[i]);
            len = max(len, i - left + 1);
        }
        return len;
    }
    //int arr[256];
    //for(int i=0;i<256;i++){
      // arr[i]=0;
   // }
    //int maxlen=0;
    //int l=0;
    //for(int j=0;j<s.size();j++){
      // if(arr[s[j]]>=l){
          // l=arr[s[j]]+1;
      // }
      // arr[s[j]]=j;
      // maxlen=max(maxlen,j-l+1);
  //  }
  // return maxlen;
  // }
};
int main() {

}