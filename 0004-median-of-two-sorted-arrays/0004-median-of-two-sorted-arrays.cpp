class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > m) return findMedianSortedArrays(nums2, nums1);


        if (n==0){
            if (m%2 == 1) return nums2[m>>1];
            return (nums2[m>>1] + nums2[(m>>1) -1])/ 2.0;
        }
        else if (m==0){
            if (n%2 == 1) return nums1[n>>1];
            return (nums1[n>>1] + nums1[(n>>1) -1])/ 2.0;
        }

       
        auto findmed = [&] (int goal) {
            int a, b, mid1, mid2;
            int l1 =0, l2 = 0, r1 = n-1, r2 = m-1;

            while(l1 <= r1 || l2 <= r2){           
                mid1 = l1 + ((r1 - l1 + 1)>>1);
                mid2 = l2 + ((r2 - l2 + 1)>>1);

                auto temp = lower_bound(nums2.begin(), nums2.end(), nums1[mid1]);
                b = temp - nums2.begin();                              
                if ((mid1 +  b ) == (goal)) return nums1[mid1];

                if ((b + mid1) < goal) l1 = (mid1 < n-1) ? mid1 + 1 : n-1;
                else r1 = (mid1 > 0) ? mid1 - 1: 0;
                
                temp = lower_bound(nums1.begin(), nums1.end(), nums2[mid2]);
                a = temp - nums1.begin();                               
                if ((mid2 +  a ) == (goal)) return nums2[mid2];

                if ((a + mid2) < goal) l2 = (mid2 < m-1) ? mid2 + 1 : m-1;
                else r2 = (mid2 > 0) ? mid2 - 1: 0;
            } 
            return 0;
            
        };

        if ((n+m)%2 == 1){
            if(nums1[(n+1)/2 - 1]==nums2[(m+1)/2 - 1]) return nums1[(n+1)/2 - 1];
            return findmed(m + ((n-m)>>1));
        }
       
        if (n%2 == 1) {      
            if(nums1[(n+1)/2 - 1]==nums2[(m+1)/2 - 1]) return nums1[(n+1)/2 - 1];
        }
        else {
            if( nums1[n>>1] == nums2[(m>>1) -1 ] ) return nums1[n>>1];
            if( nums2[m>>1] == nums1[(n>>1) -1 ] ) return nums2[m>>1];
            if (nums1[n>>1] == nums2[m>>1] && nums1[(n>>1) -1] == nums2[(m>>1) -1]) {
                return (nums1[n>>1] + nums1[(n>>1) -1]) /2.0;
            }
        }
        int left = findmed(m - 1 + ((n-m)>>1));
        int right = findmed(m + ((n-m)>>1));
        return (right + left)/2.0;
    }
};