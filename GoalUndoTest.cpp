  /**
   * NAME : Rahul Shinde
   * EXAM : Unit Tests for GoalUndo class
  **/

  #include <gtest/gtest.h>
  #include "GoalUndo.h"

  class GoalUndoTest : public ::testing::Test
  {
  	protected:
  		GoalUndoTest(){}
  		virtual ~GoalUndoTest(){}
  		virtual void SetUp(){}
  		virtual void TearDown(){}
  };
  //Test Case 1: Check whether program compiles properly without any error.
  TEST(GoalUndoTest, sanityCheck)
  {
  	ASSERT_TRUE(true);
  }

  //Test Case 2: Check whether the test pass for empty goal and no operation.
  TEST(GoalUndoTest, isEmptyGoal)
  {
    GoalUndo goalObj;
    ASSERT_EQ("", goalObj.getGoal());
  }

  //Test Case 3: Check whether the test pass for empty operation and no goal.
  TEST(GoalUndoTest, isEmptyOperation)
  {
    GoalUndo goalObj;
    ASSERT_EQ("", goalObj.getOperations());
  }

  //Test Case 4: Check whether the test pass for empty goal and operation.
  TEST(GoalUndoTest, addEmptyGoalOperation)
  {
    GoalUndo goalObj;
    goalObj.addOperation("","");
    ASSERT_EQ("",goalObj.getGoal());
    ASSERT_EQ("",goalObj.getOperations());
  }

  //Test Case 5: Check whether the test pass for empty goal.
  TEST(GoalUndoTest, addEmptyGoal)
  {
    GoalUndo goalObj;
    goalObj.addOperation("","Operation1");
    ASSERT_EQ("",goalObj.getGoal());
  }

  //Test Case 6: Check whether the test pass for empty operation.
  TEST(GoalUndoTest, addEmptyOperation)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Goal1","");
    ASSERT_EQ("",goalObj.getOperations());
  }

  //Test Case 7: Check whether the test pass after adding simple goal and operation.
  TEST(GoalUndoTest, addSingleGoalOperation)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Goal1","Operation1");
    ASSERT_EQ("Goal1",goalObj.getGoal());
    ASSERT_EQ("Operation1",goalObj.getOperations());
  }

  //Test Case 8: Check whether the test pass after adding one goal and
  //multiple operations.
  TEST(GoalUndoTest, addSingleGoalMultipleOperations)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Goal1","Operation1");
    goalObj.addOperation("Operation2");
    goalObj.addOperation("Operation3");
    goalObj.addOperation("Operation4");
    goalObj.addOperation("Operation5");
    ASSERT_EQ("Goal1",goalObj.getGoal());
    ASSERT_EQ("Operation1 Operation2 Operation3 Operation4 Operation5",
              goalObj.getOperations());
  }

  //Test Case 9: Check whether the test pass after adding multiple goals
  //and operations.
  TEST(GoalUndoTest, addMultipleGoalsOperations)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Goal1","Operation1");
    goalObj.addOperation("Goal2","Operation2");
    goalObj.addOperation("Operation3");
    goalObj.addOperation("Operation4");
    goalObj.addOperation("Operation5");
    ASSERT_EQ("Goal2",goalObj.getGoal());
    ASSERT_EQ("Operation2 Operation3 Operation4 Operation5",goalObj.getOperations());
  }

  //Test Case 10: Check whether the test pass for duplicate goals.
  TEST(GoalUndoTest, addDuplicateGoal)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Goal1","Operation1");
    goalObj.addOperation("Goal2","Operation2");
    goalObj.addOperation("Operation2a");
    goalObj.addOperation("Goal1","Operation3");
    ASSERT_EQ("Goal1",goalObj.getGoal());
    ASSERT_EQ("Operation3",goalObj.getOperations());
  }
  //Test Case 11: Check whether the test pass for operation and goal with the
  //same name.
  TEST(GoalUndoTest, addOperation)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Operation1");
    ASSERT_EQ("Operation1", goalObj.getGoal());
    ASSERT_EQ("Operation1", goalObj.getOperations());
  }

  //Test Case 12: Check whether the test pass for undoing empty goal and operation.
  TEST(GoalUndoTest, undoEmpty)
  {
    GoalUndo goalObj;
    goalObj.undoGoal();
    goalObj.undoOperation();
    ASSERT_EQ("",goalObj.getGoal());
    ASSERT_EQ("",goalObj.getOperations());
  }

  //Test Case 13: Check whether the test pass for undoing goal only when there is
  //only one goal and operation.
  TEST(GoalUndoTest, undoGoalOnly)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Goal1", "Operation1");
    goalObj.undoGoal();
    ASSERT_EQ("", goalObj.getGoal());
  }

  //Test Case 14: Check whether the test pass for undoing operation only when there
  //is only one goal and operation.
  TEST(GoalUndoTest, undoOperationOnly)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Goal1", "Operation1");
    goalObj.undoOperation();
    ASSERT_EQ("", goalObj.getOperations());
  }

  //Test Case 15: Check whether the test pass for undoing goal and operation only
  //when there is only one goal and operation.
  TEST(GoalUndoTest, undoGoalOperation)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Goal1", "Operation1");
    goalObj.undoGoal();
    goalObj.undoOperation();
    ASSERT_EQ("",goalObj.getGoal());
    ASSERT_EQ("", goalObj.getOperations());
  }

  //Test Case 16: Check whether the test pass for undoing goal operation using
  //operation name.
  TEST(GoalUndoTest, undoAll)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Goal1", "Operation1");
    goalObj.undoOperation("Operation1");
    ASSERT_EQ("",goalObj.getGoal());
    ASSERT_EQ("", goalObj.getOperations());
  }

  //Test Case 17: Check whether the test pass for undoing recently added operation.
  TEST(GoalUndoTest, undoRecentOperation)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Goal1", "Operation1");
    goalObj.addOperation("Operation2");
    goalObj.addOperation("Operation3");
    goalObj.addOperation("Operation4");
    goalObj.addOperation("Operation5");
    goalObj.undoOperation();
    ASSERT_EQ("Goal1",goalObj.getGoal());
    ASSERT_EQ("Operation1 Operation2 Operation3 Operation4", goalObj.getOperations());
  }

  //Test Case 18: Check whether the test pass for undoing goal and operations when
  //there are multiple operations under single goal.
  TEST(GoalUndoTest, undoGoalAllOperations)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Goal1", "Operation1");
    goalObj.addOperation("Operation2");
    goalObj.addOperation("Operation3");
    goalObj.addOperation("Operation4");
    goalObj.addOperation("Operation5");
    goalObj.undoGoal();
    ASSERT_EQ("",goalObj.getGoal());
    ASSERT_EQ("", goalObj.getOperations());
  }

  //Test Case 19: Check whether the test pass for undoing random operation.
  TEST(GoalUndoTest, undoRandomOperation)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Goal1", "Operation1");
    goalObj.addOperation("Operation2");
    goalObj.addOperation("Operation3");
    goalObj.addOperation("Operation4");
    goalObj.addOperation("Operation5");
    goalObj.undoOperation("Operation3");
    ASSERT_EQ("Goal1",goalObj.getGoal());
    ASSERT_EQ("Operation1 Operation2 Operation4 Operation5", goalObj.getOperations());
  }

  //Test Case 20: Check whether the test pass for undoing operation and goal with
  //the same name as operation.
  TEST(GoalUndoTest, undoOpeartionConvertedGoal)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Operation1");
    goalObj.undoOperation();
    ASSERT_EQ("",goalObj.getGoal());
    ASSERT_EQ("",goalObj.getOperations());
  }

  //Test Case 21: Check whether the test pass for undoing duplicate operation.
  TEST(GoalUndoTest, undoDuplicateOperation)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Goal1","Operation1");
    goalObj.addOperation("Operation1");
    goalObj.undoOperation();
    ASSERT_EQ("Goal1",goalObj.getGoal());
    ASSERT_EQ("Operation1",goalObj.getOperations());
  }

  //Test Case 22: Check whether the test pass for undoing recently added goal by
  //undoing recently added operation.
  TEST(GoalUndoTest, undoRecentGoalOperationUsingundoOperation)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Goal1","Operation1");
    goalObj.addOperation("Goal2","Operation2");
    goalObj.undoOperation();
    ASSERT_EQ("Goal1",goalObj.getGoal());
    ASSERT_EQ("Operation1",goalObj.getOperations());
  }

  //Test Case 23: Check whether the test pass for undoing goal and operation
  //by undoing recently added goal.
  TEST(GoalUndoTest, undoRecentGoalOperationUsingundoGoal)
  {
    GoalUndo goalObj;
    goalObj.addOperation("Goal1","Operation1");
    goalObj.addOperation("Goal2","Operation2");
    goalObj.undoGoal();
    ASSERT_EQ("Goal1",goalObj.getGoal());
    ASSERT_EQ("Operation1",goalObj.getOperations());
  }
