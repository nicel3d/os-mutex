#include <thread>
#include <iostream>
#include <mutex>
#include <unistd.h>
using namespace std;

void foo(int& n, mutex& mtx);

int main(int args, char** argv)
{
	cout << "Hardware concurrency: " << thread::hardware_concurrency() << endl;
	int n = 10;
	mutex mtx;
	thread z (foo, ref(n), ref(mtx));
	thread t (foo, ref(n), ref(mtx));
	t.join();
	z.join();
	cout << "Hello" << endl;
	pause();
	return 0;
}

void foo(int& n, mutex& mtx)
{
	while(1)
	{
		//mtx.lock();
		n += 2;
		cout << n << " foo " << endl;
		//mtx.unlock();
		usleep(50000);
	}
}