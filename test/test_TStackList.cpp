# include "stacklist.h"
# include "../gtest/gtest.h"

TEST(TStackList, can_create_stack_list)
{
	ASSERT_NO_THROW(TStackList<int> stck);
}

TEST(TStackList, can_copy_stack_list)
{
	TStackList<int> stck;

	stck.Put(1);

	ASSERT_NO_THROW(TStackList<int> s2(stck));
}

TEST(TStackList, can_put_elem)
{
	TStackList<int> stck;

	ASSERT_NO_THROW(stck.Put(5));
}

TEST(TStackList, can_get_elem)
{
	TStackList<int> stck;

	stck.Put(5);

	EXPECT_EQ(5, stck.Get());
}

TEST(TStackList, stack_empty_check)
{
	TStackList<int> stck;

	EXPECT_EQ(true, stck.IsEmpty());
}

TEST(TStackList, stack_full_check)
{
	TStackList<int> stck;

	EXPECT_EQ(false, stck.IsFull());
}

TEST(TStackList, error_while_get_from_empty_stack_list)
{
	TStackList<int> stck;

	ASSERT_ANY_THROW(stck.Get());
}

TEST(TStackList, can_assing_stack_list)
{
	TStackList<int> stck1;
	TStackList<int> stck2;

	stck1.Put(5);
	stck2 = stck1;

	EXPECT_EQ(5, stck2.Get());
}

TEST(TStackList, can_get_count_elem)
{
	TStackList<int> stck;

	stck.Put(5);
	stck.Put(10);
	stck.Put(15);
	stck.Put(20);
	stck.Put(25);

	EXPECT_EQ(5, stck.GetCount());
}
