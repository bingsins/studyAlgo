class FizzBuzz {
private:
    int n;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        
    }
};

class FizzBuzz {
    int n;
    int cnt =1;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz( function<void()> printFizz)
    {
        unique_lock<mutex> lck(m);
        while (true) {
            if (cnt > n) return;
            if (cnt % 3 == 0 && cnt % 5 != 0) {
                printFizz();
                ++cnt;
                cv.notify_all();
            }
            cv.wait(lck, [&] { return cnt > n || (cnt % 3 == 0 && cnt % 5 != 0); });
        }
    }

    // printBuzz() outputs "buzz".
    void buzz( function<void()> printBuzz)
    {
        unique_lock<mutex> lck(m);
        while (true) {
            if (cnt > n) return;
            if (cnt % 3 != 0 && cnt % 5 == 0) {
                printBuzz();
                ++cnt;
                cv.notify_all();
            }
            cv.wait(lck, [&] { return cnt > n || (cnt % 3 != 0 && cnt % 5 == 0); });
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz( function<void()> printFizzBuzz)
    {
        unique_lock<mutex> lck(m);
        while (true) {
            if (cnt > n) return;
            if (cnt % 3 == 0 && cnt % 5 == 0) {
                printFizzBuzz();
                ++cnt;
                cv.notify_all();
            }
            cv.wait(lck, [&] { return cnt > n || (cnt % 3 == 0 && cnt % 5 == 0); });
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        unique_lock<mutex> lck(m);
        while (true) {
            if (cnt > n) return;
            if (cnt % 3 != 0 && cnt % 5 != 0) {
                printNumber(cnt);
                ++cnt;
                cv.notify_all();
            }
            cv.wait(lck, [&] { return cnt > n || (cnt % 3 != 0 && cnt % 5 != 0); });
        }
    }
};