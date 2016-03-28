#include <stdio.h>
#include <check.h>

#include "../src/parse.c"
#include "../src/syntax.c"

#define MAX_TOKEN_SIZE 80

//PARSE TESTS

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
    token = nextToken();
    ck_assert_str_eq(token, "World");
}
END_TEST

START_TEST (test_hasNextToken) {
    char *string = "Hello World\r\n";
    initBuffer(string);
    ck_assert(hasNextToken());
}
END_TEST

START_TEST (test_hasNextToken_false) {
    char *string = "Hello\r\n";
    initBuffer(string);
    nextToken();
    ck_assert(!hasNextToken());
}
END_TEST

START_TEST (test_myRewind) {
    char *string = "Hello World\r\n";
    initBuffer(string);
    nextToken();
    myRewind();
    char *token = nextToken();
    ck_assert_str_eq(token, "Hello");
}
END_TEST

//SYNTAX TESTS

START_TEST (test_upper) {
    char *string = "takeastep\r\n";
    initBuffer(string);
    char *token = nextToken();
    upper(token);
    ck_assert_str_eq(token, "TAKEASTEP");
}
END_TEST

START_TEST (test_isValidCommand) {
    char *string = "TAKEASTEP\r\n";
    initBuffer(string);
    char *token = nextToken();
    ck_assert(isValidCommand(token));
}
END_TEST

START_TEST (test_isValidExpression_command) {
    char *string = "TAKEASTEP\r\n";
    ck_assert(isValidExpression(string));
}
END_TEST

START_TEST (test_isValidExpression_repeat) {
    char *string = "REPEAT 10 TIMES TAKEASTEP, LEFT, TAKEASTEP END\r\n";
    ck_assert(isValidExpression(string));
}
END_TEST

START_TEST (test_isValidExpression_while) {
    char *string = "WHILE NOT DETECTMARKER DO TAKEASTEP, LEFT, TAKEASTEP END\r\n";
    ck_assert(isValidExpression(string));
}
END_TEST

START_TEST (test_isCommaSeperatedCommands) {
    char *string = "TAKEASTEP, LEFT, TAKEASTEP END\r\n";
    initBuffer(string);
    ck_assert(isCommaSeperatedCommands());
}
END_TEST

START_TEST (test_isInteger) {
    char *string = "42";
    ck_assert(isInteger(string));
    char *string2 = "ab";
    ck_assert(!isInteger(string2));
}
END_TEST

Suite *parse_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("parse");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_initBuffer);
    tcase_add_test(tc_core, test_nextToken);
    tcase_add_test(tc_core, test_hasNextToken);
    tcase_add_test(tc_core, test_hasNextToken_false);
    tcase_add_test(tc_core, test_myRewind);

    suite_add_tcase(s, tc_core);
    
    return s;
}
    
Suite *syntax_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("syntax");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_upper);
    tcase_add_test(tc_core, test_isValidCommand);
    tcase_add_test(tc_core, test_isValidExpression_command);
    tcase_add_test(tc_core, test_isValidExpression_repeat);
    tcase_add_test(tc_core, test_isValidExpression_while);
    tcase_add_test(tc_core, test_isCommaSeperatedCommands);
    tcase_add_test(tc_core, test_isInteger);

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
