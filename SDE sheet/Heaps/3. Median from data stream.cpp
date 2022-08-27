
class MedianFinder {
public:
  /** initialize your data structure here. */
  priority_queue<int> left_heap; // max heap
  priority_queue<int, vector<int>, greater<int>> right_heap;  // min heap
  double med = INT_MAX;

  MedianFinder() {

  }

  void addNum(int num) {
    if (left_heap.size() > right_heap.size()) {
      if (num < med) {
        right_heap.push(left_heap.top());
        left_heap.pop();
        left_heap.push(num);
      }
      else {
        right_heap.push(num);
      }
      med = (double)(left_heap.top() + right_heap.top()) / 2;
    }

    else if (right_heap.size() > left_heap.size()) {
      if (num < med) {
        left_heap.push(num);
      }
      else {
        left_heap.push(right_heap.top());
        right_heap.pop();
        right_heap.push(num);
      }
      med = (double)(left_heap.top() + right_heap.top()) / 2;
    }

    else {
      if (num < med) {
        left_heap.push(num);
        med = left_heap.top();
      }

      else {
        right_heap.push(num);
        med = right_heap.top();
      }
    }

  }

  double findMedian() {
    return med;
  }
};