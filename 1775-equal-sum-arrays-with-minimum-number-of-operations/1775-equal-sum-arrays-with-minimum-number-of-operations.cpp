class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        int sum1=accumulate(begin(nums1),end(nums1),0);
        int sum2=accumulate(begin(nums2),end(nums2),0);
        if(sum1==sum2){
            return 0;
        }   

        if(sum1>sum2){
            // ab dekh sum1>sum2 matlab mujhe sum1 ko kam krna hoga aur sum2 ko inc krna hoga 

            //ab nums1 k har elem ko mai chahunga ki wo kam se kam 1 bane taki usse hamara sum kam ho ske . for eg agar num=6 hai toh usko 1 banao taki sum 5 se kam ho ske isliye (num-1) for eg num=5 hai toh usko bhi 1 banao taki sum 4 se kam ho ske isliye again(num-1)

            priority_queue<int>pq; // pq kyu liya hu wo aage smjh aaega

            for(int num : nums1){
                pq.push(num-1);
            }

            // ab baari hai sum2 ki mujhe sum2 ko inc krna hoga ab mai chahunga ki har elem ko 6 banau taki zyada se zyada sum ho ske. 

            //isko kaise kre --> maan le num 1 hai toh usko 6 banau taki sum 5 se inc ho ske 
            // ab ye hoga kaise ?? ---> (6-num) krega toh har elem ...sum ko kuch na kuch inc krega

            for(int num : nums2){
                pq.push(6-num);
            }

            // ab mere nums1 ka har elem jo ki mere sum1 ko kitna dec kr skta hai usko pq(maxheap) me daala hu

            // same for har elem nums2 ke sum2 ko kitna inc kr skta h usko pq(maxheap) me daala hu

            // maxheap se ye faida hoga wo ye check krega ki kaha se zyada faida mil rha hai  ---> sum1 ko dec krne me ya sum2 ko inc krne me kyuki pq ke top pe max val hoga



             
           
            int ops=0;
            int diff=sum1-sum2;
            
            while(!pq.empty() && diff>0){ // jabtak mera diff 0 se zyada hai
                int maxi=pq.top();
                pq.pop();
                diff-=maxi;
                ops++;
            }
            return diff<=0?ops:-1; // agar in future mai kabhi dono ke sum ko equal nhi kr paya toh -1;
        }

        // ab ye pura logic rev hoga for sum1<sum2 ke liye
        else{
            priority_queue<int>pq;
            for(int num : nums1){
                pq.push(6-num);
            }
            for(int num : nums2){
                pq.push(num-1);
            }

            int ops=0;
            int diff=sum2-sum1;
            while(!pq.empty() && diff>0){
                int maxi=pq.top();
                pq.pop();
                diff-=maxi;
                ops++;
            }
            return diff<=0?ops:-1;
        }
        return -1; // dummy statement
        
    }
};