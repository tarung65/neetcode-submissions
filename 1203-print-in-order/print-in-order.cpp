class Foo {
public:
    mutex mtx;
    condition_variable cv;
    int turn;
    Foo() {
        turn =1;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex>lock(mtx);
        cv.wait(lock,[this](){return this->turn == 1;});
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn =2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex>lock(mtx);
        cv.wait(lock,[this](){return this->turn == 2;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        turn = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex>lock(mtx);
        cv.wait(lock,[this](){return this->turn == 3;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        turn = 1;
        cv.notify_all();
    }
};