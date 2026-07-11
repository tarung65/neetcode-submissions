class H2O {
public:
    int turn;
    condition_variable cv;
    mutex mtx;
    H2O() {
        turn=0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex>lock(mtx);
        cv.wait(lock,[this](){return this->turn != 0;});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        turn = (turn==2)?0: turn+1;
     
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex>lock(mtx);
        cv.wait(lock,[this](){return this->turn == 0;});
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        turn++;
        cv.notify_all();
    }
};