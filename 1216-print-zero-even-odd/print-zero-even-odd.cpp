class ZeroEvenOdd {
private:
    int n;
    int x;
    int turn ;
    condition_variable cv;
    mutex mtx;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        turn =0;
        x =0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i =0;i<n;i++){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock,[this](){return this->turn == 0;});
            printNumber(0);
            turn = (x&1)?2:1;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i =0;i<n/2;i++){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock,[this](){return this->turn ==2;});
            printNumber(++x);
            turn = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i =0;i<(n+1)/2;i++){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock,[this](){return this->turn ==1;});
            printNumber(++x);
            turn = 0;
            cv.notify_all();
        }
    }
};