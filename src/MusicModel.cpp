//============================================================================
// Name        : MusicModel.cpp
// Author      : Andrea Marangoni
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <gtest/gtest.h>

#include "Notes.h"

using namespace std;


TEST(NoteTestCase, FGives6){
	Notes notes;
	ASSERT_EQ(notes.getPitch("F"),6);
}

TEST(NoteTestCase, AHashGives11){
	Notes notes;
	ASSERT_EQ(notes.getPitch("A#"),11);
}

TEST(NoteTestCase, BFlatGives11){
	Notes notes;
	ASSERT_EQ(notes.getPitch("Bb"),11);
}

TEST(NoteTestCase, BFlatOctave2Gives26){
	Notes notes;
	ASSERT_EQ(notes.getPitchOctave("Bb",2),26);
}

TEST(NoteTestCase, ASharpFiveGives62){
	Notes notes;
	ASSERT_EQ(notes.getPitchOctave("A#",5),62);
}

TEST(NoteTestCase, AZeroGives1){
	Notes notes;
	ASSERT_EQ(notes.getPitchOctave("A",0),1);
}

TEST(NoteTestCase, EFlat2Gives19){
	Notes notes;
	ASSERT_EQ(notes.getPitchOctave("Eb",2),19);
}

TEST(NoteTestCase, G2Gives23){
	Notes notes;
	ASSERT_EQ(notes.getPitchOctave("G",2),23);
}

TEST(NoteTestCase, F2Gives21){
	Notes notes;
	ASSERT_EQ(notes.getPitchOctave("F",2),21);
}

TEST(NoteTestCase, FrequencyOf440Gives10){
	Notes notes;
	ASSERT_EQ(notes.getPitchFromFrequency(440.0f),10);
}

TEST(NoteTestCase, FrequencyOf415){
	Notes notes;
	ASSERT_EQ(notes.getPitchFromFrequency(415.0f),48);
}

TEST(NoteTestCase, IntervalBetweenCAndCisZero){
	Notes notes;
	ASSERT_EQ(notes.getInterval("C","C"),"Perfect Unison");
}

TEST(NoteTestCase, IntervalBetweenEbAndDbGivesMajorSecond){
	Notes notes;
	ASSERT_EQ(notes.getInterval("Db","Eb"),"Major Second");
}

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
