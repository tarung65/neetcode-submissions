class Solution {
public:
    double findMedianSortedArraysC(vector<int>& A, vector<int>& B){
        int len1 = A.size();
        int len2 = B.size();
        int total = len1+len2;
        int half = (len1+len2+1)>>1;
        int l = 0;
        int r = len1;
        while(l<=r){
            int i = l+((r-l)>>1);
            int j =  half - i;
            int ALeft = i>0 ?A[i-1]:INT_MIN;
            int ARight = i<A.size()?A[i]:INT_MAX;
            int BLeft = j>0 ? B[j-1]:INT_MIN;
            int BRight = j<B.size()?B[j]:INT_MAX;
            if(ALeft <= BRight && ARight >=BLeft ){
                if(total%2==0){
                    return (max(ALeft,BLeft)+min(ARight,BRight))/2.0;
                } else {
                    return max(ALeft,BLeft);
                }
            }
            if(ALeft > BRight)
                r = i-1;
            else
                l = i+1;
            
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()> nums2.size())
            return findMedianSortedArraysC(nums2,nums1);
        return findMedianSortedArraysC(nums1,nums2);
    }
};
