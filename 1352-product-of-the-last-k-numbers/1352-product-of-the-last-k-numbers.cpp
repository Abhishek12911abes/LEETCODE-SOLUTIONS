class ProductOfNumbers {
public:
   vector<int>vec;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        vec.push_back(num);
    }
    
    int getProduct(int k) {
        int prod=1;
        int n=vec.size(); // 5
        int p=n-1; // 4
        while(k--){
            prod*=vec[p];
            p--;
        }
        return prod;

        // 3 0 2 5 4 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */