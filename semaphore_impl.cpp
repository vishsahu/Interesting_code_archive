class semaphore {
public:
  semaphore() : count_{0}, lock_{0} {};
  void up();
  void down();
private:
  lock_;
  count_;
  queue<int> sema_wq_;
};

void semaphore::up() {
  while (test_and_set(&lock_))
    ;
  // critical section begins
  if (!sema_wq_.empty()) {
    uint32_t pid = sema_wq_.front();
    sema_wq_.pop();
    pid.status = RUNNABLE;
  }
  else {
    count_++;
  }
  // end of critical section
  lock_ = 0;
}

void semaphore::down() {
  while (test_and_set(&lock_))
    ;
  // critical section begins
  if (count_ == 0) {
    uint32_t pid = get_pid(curr_process);
    sema_wq_.push(pid);
    // end of critical section
    lock_ = 0;
    pid.status = WAITING;
  }
  else {
    count_--;
    // end of critical section
    lock_ = 0;
  }
}

