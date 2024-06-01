#include<bits/stdc++.h>
using namespace std;

struct Student {
  int id;
  char name[100];
  double cgpa;
};

void partition(Student arr[], int low, int high, int& pivot) {
  int i = (low - 1);
  double pivotElement = arr[high].cgpa;

  for (int j = low; j < high; j++) {
    if (arr[j].cgpa <= pivotElement) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[high]);
  pivot = (i + 1);
}

void quickSort(Student arr[], int low, int high) {
  if (low < high) {
    int pivot;
    partition(arr, low, high, pivot);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}

int main() {
  Student students[] = {
    {1, "a", 3.25},
    {2, "b", 3},
    {3, "c", 4},
    {4, "d", 2.5},
    {5, "e", 3.75}
  };

  int n = sizeof(students) / sizeof(students[0]);
  quickSort(students, 0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << students[i].id << " " << students[i].name << " " << students[i].cgpa << std::endl;
  }

  return 0;
}
