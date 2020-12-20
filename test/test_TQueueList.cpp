# include "queuelist.h"
# include "../gtest/gtest.h"

TEST(TQueueList, can_create_queue_list)
{
	ASSERT_NO_THROW(TQueueList<int> qu);
}

TEST(TQueueList, can_copy_queue_list)
{
	TQueueList<int> qu1;

	qu1.Put(5);

	ASSERT_NO_THROW(TQueueList<int> qu2(qu1));
}

TEST(TQueueList, queue_empty_check)
{
	TQueueList<int> qu;

	EXPECT_EQ(true, qu.IsEmpty());
}

TEST(TQueueList, queue_full_check)
{
	TQueueList<int> qu;

	EXPECT_EQ(false, qu.IsFull());
}

TEST(TQueueList, can_put_elem)
{
	TQueueList<int> qu;

	ASSERT_NO_THROW(qu.Put(5));
}

TEST(TQueueList, can_get_elem)
{
	TQueueList<int> qu;

	qu.Put(5);

	EXPECT_EQ(5, qu.Get());
}

TEST(TQueueList, error_while_get_from_empty_queue_list)
{
	TQueueList<int> qu;

	ASSERT_ANY_THROW(qu.Get());
}

TEST(TQueueList, can_assing_queue_list)
{
	TQueueList<int> qu1;
	TQueueList<int> qu2;

	qu1.Put(5);
	qu2 = qu1;

	EXPECT_EQ(5, qu2.Get());
}

TEST(TQueueList, can_get_count)
{
	TQueueList<int> qu;

	qu.Put(5);
	qu.Put(10);

	EXPECT_EQ(2, qu.GetCount());
}


