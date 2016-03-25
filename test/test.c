#include <stdio.h>
#include <check.h>

#include "../src/parse.c"

#define MAX_TOKEN_SIZE 80

START_TEST (test_initBuffer) {
    char *string = "Hello World\r\n";
    initBuffer(string);
}
END_TEST

START_TEST (test_nextToken) {
    char *string = "Hello World\r\n";
    initBuffer(string);
    char *token = nextToken();
    ck_assert_str_eq(token, "Hello");
}
END_TEST

Suite *parse_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("parse");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_initBuffer);
    tcase_add_test(tc_core, test_nextToken);

    suite_add_tcase(s, tc_core);
    
    return s;
}
    
Suite *syntax_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("syntax");

    tc_core = tcase_create("Core");

    //tcase_add_test(tc_core, test_upperCase);

    suite_add_tcase(s, tc_core);
    
    return s;
}

int main(void) {
    int number_failed;

    Suite *parse_suite();
    Suite *syntax_suite();
     
    SRunner *sr;
    sr = srunner_create(parse_suite());
    srunner_add_suite(sr, syntax_suite());

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 0 : 1; 
}
