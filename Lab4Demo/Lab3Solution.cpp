/*
Uses 2 indices to traverse the sorted vector of integers to find if 2 of them sum to the input sum or not
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



bool twoSum(vector<int> &nums,int &required_sum){
    int i = 0;
    int j = nums.size()-1;
    int intermediate_sum;
    sort(nums.begin(),nums.end());
    while(i<j){
        intermediate_sum = nums[i] + nums[j];
        if(intermediate_sum==required_sum){
            return true;
        }
        else if(intermediate_sum<required_sum){
            i++;
        }
        else{
            j--;
        }
    
    }
    return false;


}


int main(){
    int required_sum;
    vector<int> nums = {-2,1,-3,4,6};
    cout<<"Enter the required sum: ";
    cin>>required_sum;
    cout<<endl;
    if(twoSum(nums,required_sum)){

        cout<<"Found a pair that sums up to "<<required_sum<<endl;
    
    }
    else{
        cout<<"Pair not found"<<endl;
    }
    return 0;
}