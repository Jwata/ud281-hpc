#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool load_data(std::string filename, std::vector<int> *a) {
  std::ifstream inf(filename);

  if (!inf) {
    return false;
  }

  std::string line;
  while (std::getline(inf, line)) {
    if (line.size() > 0)
      (*a).push_back(std::stoi(line));
  }

  inf.close();

  return true;
}

std::vector<int> quicksort1(std::vector<int> arr) {
  std::vector<int> sorted;
  int n = arr.size();

  if (n <= 1) {
    return arr;
  }

  int pivot = arr[rand() % n];

  std::vector<int> left;
  std::vector<int> right;

  for (int i = 0; i < n; i++) {
    int v = arr[i];
    if (v <= pivot) {
      left.push_back(v);
    } else {
      right.push_back(v);
    }
  }

  std::vector<int> left_sorted = quicksort1(left);
  std::vector<int> right_sorted = quicksort1(right);

  std::merge(left_sorted.begin(), left_sorted.end(), right_sorted.begin(),
             right_sorted.end(), std::back_inserter(sorted));

  return sorted;
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int begin, int end) {
  int pivot = arr[end];
  int i = begin - 1;

  for (int j = begin; j < end; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  i++;
  swap(&arr[i], &arr[end]);
  return i;
}

void quicksort2(int arr[], int begin, int end) {
  if (end <= begin) {
    return;
  }

  int index = partition(arr, begin, end);
  quicksort2(arr, begin, index - 1);
  quicksort2(arr, index + 1, end);
}

int main() {
  std::string filename = "lesson6/quicksort.txt";
  srand(std::time(NULL));

  std::vector<int> a;
  if (!load_data(filename, &a)) {
    std::cerr << "Cannot open the File : " << filename << std::endl;
    return 1;
  }

  int n = a.size();
  int arr[n];
  std::copy(a.begin(), a.end(), arr);

  for (int i=0; i<10; i++) {
    // quicksort1(a);
    quicksort2(arr, 0, n - 1);
  }
  // for (int i = 0; i < n; i++) {
  //   std::cout << arr[i] << "\n";
  // }

  return 0;
}
