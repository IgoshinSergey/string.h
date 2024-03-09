#include "s21_string_test.h"

void run_testcase(Suite *testcase) {
  printf("\n");
  SRunner *suite_runner = srunner_create(testcase);
  // Для Valgrind нужно использовать CK_NOFORK
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  srunner_free(suite_runner);
}

void run_tests(void) {
  printf("\n\033[30;43m -=S21_STRING_TESTS=- \033[0m\n");
  Suite *case_list[] = {suite_insert(),
                        suite_memcmp(),
                        suite_memset(),
                        suite_sprintf(),
                        suite_strchr(),
                        suite_strcspn(),
                        suite_strerror(),
                        suite_strncpy(),
                        suite_strpbrk(),
                        suite_strstr(),
                        suite_to_upper(),
                        suite_memchr(),
                        suite_memcpy(),
                        suite_strcspn(),
                        suite_strlen(),
                        suite_strncat(),
                        suite_strncmp(),
                        suite_strrchr(),
                        suite_to_lower(),
                        suite_sscanf(),
                        suite_trim(),
                        suite_strtok(),
                        NULL};
  for (Suite **cur_test_case = case_list; *cur_test_case != NULL;
       cur_test_case++) {
    run_testcase(*cur_test_case);
  }
}

int main() {
  run_tests();
  return 0;
}