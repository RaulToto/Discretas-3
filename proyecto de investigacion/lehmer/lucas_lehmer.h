#ifndef LUCAS_LEHMER_H
#define LUCAS_LEHMER_H


#include <mutex>
#include <queue>
#include <set>
#include <thread>

class LucasLehmer {
private:
  bool algo(int p);
  int get_next(int done, bool mersenne_prime);
  void worker_thread();
  std::queue<int> to_check;
  std::set<int> in_progress;
  std::set<int> to_print;
  std::vector<std::thread> threads;
  std::mutex mutex_queue;

public:
  LucasLehmer(int start, int stop, int num_threads);
  void compute();
};


#endif // LUCAS_LEHMER_H
