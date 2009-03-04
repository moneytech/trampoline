/*Instance of task t3*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t2);
DeclareTask(t3);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t3_instance(void)
{
	int result_inst_2,result_inst_3, result_inst_4;
	
	EventMaskType result_inst_1;
	result_inst_2 = GetEvent(t3, &result_inst_1);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_1); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2); 
	
	result_inst_3 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_3);

	result_inst_4 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_4);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq5_t3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance",test_t3_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence5",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}