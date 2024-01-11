#include "test.h"
int calculation(char* result,double x, long double* answer){
  * answer = 0;
  int err =0;
 
 
    
         if(validation(result)) err=1;
         else {
             s21_node* tmp =s21_create_list();
             if(!polish_notation( result,tmp, x)){
                   long double res=0;
                   if(!lexems_to_res(tmp,&res)){
                      *answer=res;
                   }else  err=1;
             }else err=1;

         }
return err;
     
}
int run_tests(Suite *test_case) {
  int number_failed;
  SRunner *sr = srunner_create(test_case);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}

int main() {
  int number_failed = 0;

  Suite *suites_list[] = {validation_suite(), calculation_suite(), NULL};
  for (Suite **current = suites_list; *current != NULL; current++) {
    printf("_________________________________________\n");
    number_failed += run_tests(*current);
  }
  return 0;
}