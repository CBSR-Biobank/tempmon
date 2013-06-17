#ifndef F_PARSE_TEST
#define F_PARSE_TEST

#define TEST_FILE "/home/cpeck1/workspace/tempmon/tempmon/client/tests/testfile.ini"
#include <stdio.h>
#include "test_funcs.c"

int file_parse_test(void)
{
  char xbf[150];

  int test_number;
  int tests_passed;

  char *test_desc;
  char *got = "";

  char *test;
  int index;
  int found;
  int val;
  FILE *f;

  test_desc = xbf; /* magic */
  got = xbf;
  test = xbf; 

  test_number = 0;
  tests_passed = 0;

  /******************************************/
  test_desc = "Testing get_char_index(case 0)";
  /******************************************/
  test_number++;

  test = "a";
  index = get_char_index(test, 'b');
  if (index == -1) {
    tests_passed++;
  }
  else {
    sprintf(got, "%d", index);
    report_error(test_number, test_desc, "-1", got);
  }  

  test_number++;
  test = "b";
  index = get_char_index(test, 'b');
  if (index == 0) {
    tests_passed++;
  }
  else {
    sprintf(got, "%d", index);
    report_error(test_number, test_desc, "0", got);
  }

  /*******************************************/
  test_desc = "Testing get_char_index(case 1)";
  /*******************************************/
  test = "abcdefghijklmnopqrstuvwxyz";

  test_number++;
  index = get_char_index(test, 'z');
  if (index == 25) {
    tests_passed++;
  }
  else {
    sprintf(got, "%d", index);
    report_error(test_number, test_desc, "25", got);
  }

  test_number++;
  index = get_char_index(test, 'a');
  if (index == 0) {
    tests_passed++;
  }
  else {
    sprintf(got, "%d", index);
    report_error(test_number, test_desc, "0", got);
  }

  test_number++;
  index = get_char_index(test, 'n');
  if (index == 13) {
    tests_passed++;
  }
  else {
    sprintf(got, "%d", index);
    report_error(test_number, test_desc, "13", got);
  }

  /*****************************************/
  test_desc = "Testing get_id_value(case 0)";
  /*****************************************/
  test_number++;

  test = "This_val=booga";
  found = get_id_value(test, &val);
  if (found == 0) {
    tests_passed++;
  }
  else {
    sprintf(got, "%d", index);
    report_error(test_number, test_desc, "0", got);
  }

  test_number++;
  test = "";
  found = get_id_value(test, &val);
  if (found == 0) {
    tests_passed++;
  }
  else {
    sprintf(got, "%d", index);
    report_error(test_number, test_desc, "0", got);
  }
  
  /*****************************************/
  test_desc = "Testing get_id_value(case 1)";
  /*****************************************/
  test_number++;

  test = "This_val=1\n";
  found = get_id_value(test, &val);
  if ((found == 1) && (val == 1)) {
    tests_passed++;
  }
  else {
    sprintf(got, "%d", val);
    report_error(test_number, test_desc, "1", got);
  }

  test_number++;
  
  test = "This_val=35623\n";
  found = get_id_value(test, &val);
  if ((found != 0) && (val == 35623)) {
    tests_passed++;
  }
  else {
    sprintf(got, "%d", val);
    report_error(test_number, test_desc, "35623", got);
  }


  /*********************************************/
  test_desc = "Testing get_specified_id(case 0)";
  /*********************************************/
  f = fopen(TEST_FILE, "r");

  test_number++;

  found = get_specified_id(f, "fake_id", &val);
  if (found == 0) {
    tests_passed++;
  }
  else {
    sprintf(got, "%d", found);
    report_error(test_number, test_desc, "0", got);
  }
  test_number++;


  found = get_specified_id(f, "faker_id", &val);
  if (found == 0) {
    tests_passed++;
  }
  else {
    sprintf(got, "%d", found);
    report_error(test_number, test_desc, "0", got);
  }

  /*********************************************/
  test_desc = "Testing get_specified_id(case 1)";
  /*********************************************/

  test_number++;
  
  found = get_specified_id(f, "real_id", &val);
  if (val == 3) {
    tests_passed++;
  }
  else {
    sprintf(got, "%d", val);
    report_error(test_number, test_desc, "3", got);
  }

  test_number++;
  
  found = get_specified_id(f, "realer_id", &val);
  if (val == 12345) {
    tests_passed++;
  }
  else {
    sprintf(got, "%d", val);
    report_error(test_number, test_desc, "12345", got);
  }

  return 0;
}

#endif