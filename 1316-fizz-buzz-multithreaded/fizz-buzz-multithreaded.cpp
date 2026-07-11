class FizzBuzz {
private:
    int n;
    int i; // The single global counter representing the current number
    mutex mtx;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1; // Start counting from 1
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            // Wait until it's a Fizz number or we've finished processing up to n
            cv.wait(lock, [this]() { return i > n || (i % 3 == 0 && i % 5 != 0); });
            
            if (i > n) return; // Exit condition
            
            printFizz();
            i++; // Increment the global counter
            cv.notify_all(); // Wake up other threads to evaluate the new 'i'
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return i > n || (i % 3 != 0 && i % 5 == 0); });
            
            if (i > n) return;
            
            printBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return i > n || (i % 3 == 0 && i % 5 == 0); });
            
            if (i > n) return;
            
            printFizzBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return i > n || (i % 3 != 0 && i % 5 != 0); });
            
            if (i > n) return;
            
            printNumber(i);
            i++;
            cv.notify_all();
        }
    }
};