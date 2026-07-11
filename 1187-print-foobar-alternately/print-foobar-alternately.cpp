class FooBar {
private:
    int n;
    int turn;
    condition_variable cv;
    mutex mtx;
public:
    FooBar(int n) {
        this->n = n;
        turn = 0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(mtx);
            cv.wait(lock,[this](){return this->turn ==0;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            this->turn = 1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(mtx);
            cv.wait(lock,[this](){return this->turn ==1;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            this->turn = 0;
            cv.notify_all();
        }
    }
};