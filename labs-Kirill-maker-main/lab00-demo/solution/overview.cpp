#ifdef _MSC_VER
#include <crtdbg.h>
#endif
#include <iostream>
// #include <vector>

// std::vector<int> read_vector() {
//  std::size_t n{};
//  std::cin >> n;
//  std::vector<int> result(n);
//
//  for (int i = 0; i < n; i++) {
//    std::cin >> result[i];
//  }
//
//  return result;
//}

// void print_vector(std::vector<int> data) {
//  std::size_t bound = data.size() - 1;
//  for (std::size_t i = 0; i < data.size() - 1; i++) {
//    std::cout << data[i] << " ";
//  }
//  std::cout << data[data.size() - 1];
//}

int main() {
#ifdef _MSC_VER
  _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
  _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
  _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
  _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
#endif
  int case_number = 0;
  while (true) {
    std::cin >> case_number;
    switch (case_number) {
    case -1:
      return 0;
    case 1: {
      int a = 0;
      int b = 0;
      std::cin >> a >> b;
      std::cout << a + b << std::endl;
      break;
    }
      //    case 2: {
      //      std::vector<int> data = read_vector();
      //
      //      std::vector<int> reversed(data.size());
      //      for (std::size_t i = 0; i < data.size(); i++) {
      //        reversed[i] = data[reversed.size() - i];
      //      }
      //
      //      print_vector(reversed);
      //      break;
      //    }
      //    case 3: {
      //      std::vector<int> data = read_vector();
      //      int sum = 0;
      //      for (int i = 0; i < data.size(); i++) {
      //        sum += data[i];
      //      }
      //
      //      std::cout << sum << std::endl;
      //      std::sort(data.begin(), data.end(), [](int a, int b) -> bool {
      //        return std::abs(a) <= std::abs(b);
      //      });
      //      print_vector(data);
      //      break;
      //    }
    default:
      std::cout << "Undefined case number!\n";
    }
  }
}
