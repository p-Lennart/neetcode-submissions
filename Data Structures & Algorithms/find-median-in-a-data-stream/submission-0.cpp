class MedianFinder {
    const int MIN_N = -100001;
    const int MAX_N = 100001;

    priority_queue<int> left; // max heap
    int rmid;
    priority_queue<int, vector<int>, greater<int>> right; // min heap

    bool oddLen;
public:
    MedianFinder() {
        left.push(MIN_N);
        rmid = MIN_N;
        right.push(MAX_N);

        oddLen = false;
    }
    
    void addNum(int num) {
        // init
        if (rmid == MIN_N) {
            rmid = num;
            oddLen = true;
            return;
        }

        // normal cases
        if (oddLen) {
            // == oddlen insert (3+1+3) -> (4+1+3)
            // INS  ---  m ---
            // LT:  ---n m --- 
            // GT1: ---m n ---
            // GT2: ---m - n--
            if (num < rmid) {
                left.push(num);
            } else if (num < right.top()) {
                left.push(rmid);
                rmid = num;
            } else {
                left.push(rmid);
                rmid = right.top();
                right.pop();
                right.push(num);
            }
        } else {
            // == evenlen insert (4+1+3) -> (4+1+4)
            // INS  ----  m ---
            // GT:  ----  m n---
            // LT1: ----  n m--- 
            // LT2: ---n  - m---
            if (num > rmid) {
                right.push(num);
            } else if (num > left.top()) {
                right.push(rmid);
                rmid = num;
            } else {
                right.push(rmid);
                rmid = left.top();
                left.pop();
                left.push(num);
            }
        }

        oddLen = !oddLen;
    }
    
    double findMedian() {
        if (oddLen) return rmid;
        else return (rmid + left.top()) / 2.0;
    }
};
