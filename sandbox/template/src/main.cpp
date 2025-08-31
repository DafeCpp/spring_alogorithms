// #include <iostream>
// #include <vector>

// void MergeSort(std ::vector<int>& array) {
//   int i{0}, j{1};
//   int slice{1};
//   do {
//     while (j <= array.size() - 1) {
//       if (array[i] > array[j]) {
//         iter_swap(array.begin() + i, array.begin() + j);

//         ++j;
//       } else
//         ++i;
//       if (j - i > slice) {
//         i = j;
//         j = i + slice;
//       } else if (j == i) {
//         i += 1;
//         j = i + slice;
//       }
//     }
//     slice *= 2;
//     slice > array.size() ? j = array.size() - 1 : j = slice;
//     i = 0;
//     if (j == array.size() - 1) {
//       if (i == 0) {
//         return;
//       }
//     }
//   } while (true);
// }

int main() {
  //   std ::vector<int> unsort{3, 2, 4, 5, 1, 9, 7};
  //   MergeSort(unsort);
  //   for (int i = 0; i < unsort.size(); ++i) {
  //     std ::cout << unsort[i] << " ";
  //   }
  //   std ::cout << std ::endl;
}
