#include "cutest/CuTest.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

/* 
 * Add your tests here
 * A few sample tests 
 * are provided
 */

void TestHeap(CuTest *tc) {
	Heap* h = makeHeap(10);
	CuAssertIntEquals(tc, 0, h->size);
	cleanupHeap(h);
}

void TestOne(CuTest *tc) {
	int two = 2;
	int four = 4;
	CuAssertIntEquals(tc, four, two+two);
}

void TestTwo(CuTest *tc) {
	char* lol = "lol";
	char* alsoLol = "lol";
	CuAssertStrEquals(tc, lol, alsoLol);
}

void TestAdd(CuTest *tc){

	Heap* h = makeHeap(5);
	add(h,5,"e");
	add(h,3,"c");
	add(h,1,"a");	
	add(h,4,"d");
	add(h,2,"h");

	char* value = "a";
	char* output = peek(h);

	CuAssertStrEquals(tc,value,output);
	cleanupHeap(h);
}

void TestSize(CuTest *tc){

	Heap* h = makeHeap(5);
	add(h,5,"e");
	add(h,3,"c");
	add(h,1,"a");	
	add(h,4,"d");

	CuAssertIntEquals(tc,4,h->size);
	cleanupHeap(h);
}

void TestSize1(CuTest *tc){

	Heap* h = makeHeap(5);
	add(h,5,"e");
	add(h,3,"c");
	add(h,1,"a");	
	add(h,4,"d");

	CuAssertIntEquals(tc,4,size(h));
	cleanupHeap(h);
}

void TestExpCap(CuTest *tc){

	Heap* h = makeHeap(4);
	add(h,5,"e");
	add(h,3,"c");
	add(h,1,"a");	
	add(h,4,"d");
	add(h,2,"h");

	CuAssertIntEquals(tc,8,h->capacity);
	cleanupHeap(h);
}

void TestRemoveCalledToMakeEmpty(CuTest *tc){

	Heap* h = makeHeap(4);
	add(h,10,"e");

	removeMin(h);

	CuAssertIntEquals(tc,0,size(h));
	cleanupHeap(h);
}

void TestRemoveCalledOnNonEmpty(CuTest *tc){

	Heap* h = makeHeap(4);
	add(h,5,"e");
	add(h,3,"c");
	add(h,1,"a");	
	add(h,4,"d");
	add(h,2,"h");

       	removeMin(h);

	CuAssertIntEquals(tc,2,h->elements[0]->key);
	cleanupHeap(h);
}

void TestBubbleRight(CuTest *tc){

	Heap* h = makeHeap(4);
	add(h,1,"e");
	add(h,3,"c");
	add(h,2,"a");	
        add(h,4,"q");
	add(h,5,"a");	
        add(h,6,"q");
	add(h,7,"w");

       	removeMin(h);

	CuAssertIntEquals(tc,6,h->size);
	cleanupHeap(h);
}

void TestRemoveCalledOnEmpty(CuTest *tc){

	Heap* h = makeHeap(4);
       	removeMin(h);

	CuAssertIntEquals(tc,0,size(h));
	cleanupHeap(h);
}

void TestPeekCalledOnEmpty(CuTest *tc){

	Heap* h = makeHeap(5);

	CuAssertStrEquals(tc,NULL,peek(h));
	cleanupHeap(h);
}

void TestDuplicate(CuTest *tc){

	Heap* h = makeHeap(5);
	add(h,1,"e");
	add(h,3,"c");
	add(h,3,"c");	
	add(h,4,"d");

	CuAssertIntEquals(tc,3,h->elements[2]->key);
	cleanupHeap(h);
}


CuSuite* StrUtilGetSuite() {
	CuSuite* suite = CuSuiteNew();

	/** ADD YOUR TESTS HERE **/
	SUITE_ADD_TEST(suite, TestHeap);
	SUITE_ADD_TEST(suite, TestOne);
	SUITE_ADD_TEST(suite, TestTwo);
	SUITE_ADD_TEST(suite, TestAdd);
	SUITE_ADD_TEST(suite, TestSize);
	SUITE_ADD_TEST(suite, TestExpCap);
	SUITE_ADD_TEST(suite, TestRemoveCalledOnNonEmpty);
	SUITE_ADD_TEST(suite, TestSize1);
	SUITE_ADD_TEST(suite, TestRemoveCalledToMakeEmpty);
	SUITE_ADD_TEST(suite, TestRemoveCalledOnEmpty);
	SUITE_ADD_TEST(suite, TestPeekCalledOnEmpty);
	SUITE_ADD_TEST(suite, TestDuplicate);
	SUITE_ADD_TEST(suite, TestBubbleRight);
	return suite;
}


// Don't edit below this line

void RunAllTests(void) {
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();
	CuSuite* ourSuite = StrUtilGetSuite();

	CuSuiteAddSuite(suite, ourSuite);

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);

	CuStringDelete(output);
	CuSuiteDelete(suite);
	free(ourSuite);
}

int main(void) {
	RunAllTests();
	return 0;
}
