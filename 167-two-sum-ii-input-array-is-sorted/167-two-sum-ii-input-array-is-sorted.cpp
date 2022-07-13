class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int n = numbers.size();
int high = n-1;
vector<int>temp;
while(low<high){
    if(numbers[low]+numbers[high]==target){
        temp.push_back(low+1);
        temp.push_back(high+1);
        break;
    }
    else if(numbers[low]+numbers[high]>target){
        high--;
    }else{
        low++;
    }  
}
return temp;
    }
};