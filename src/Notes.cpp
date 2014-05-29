/*
 * Notes.cpp
 *
 *  Created on: 29 May 2014
 *      Author: andy
 */

#include "Notes.h"

#include <cmath>

using namespace std;

#define NotePitch(key,val) std::pair<char,int>(key,val)
#define Interval(key,val) std::pair<int,std::string>(key,val)

Notes::Notes() :
	notes_(){

	notes_.insert(NotePitch('C',1));
	notes_.insert(NotePitch('D',3));
	notes_.insert(NotePitch('E',5));
	notes_.insert(NotePitch('F',6));
	notes_.insert(NotePitch('G',8));
	notes_.insert(NotePitch('A',10));
	notes_.insert(NotePitch('B',12));

	intervals_.insert(Interval(0,"Perfect Unison"));
	intervals_.insert(Interval(1,"Minor Second"));
	intervals_.insert(Interval(2,"Major Second"));
	intervals_.insert(Interval(3,"Minor Third"));
	intervals_.insert(Interval(4,"Major Third"));
	intervals_.insert(Interval(5,"Perfect Fourth"));
}

Notes::~Notes() {

}

int Notes::getPitch(const std::string& note) const{
	try{
		char n = note.at(0);
		if(note.size() == 1){
			return this->getPitchFromNote(n);
		}
		char s = note.at(1);
		if(s == '#'){
			return this->sharpNote(n);
		} else if(s == 'b'){
			return this->flatNote(n);
		}
	}
	catch(...){

	}
	return 0;
}

int Notes::getPitchOctave(const std::string& note,int octave) const{
	return this->getPitch(note) + (octave * 12) - 9;
}

int Notes::getPitchFromFrequency(float frequency) const{
	if(frequency == 440){
		return this->getPitch("A");
	}
	double ratio = frequency / 440;
	return ceil(12 * log2(ratio) + 49);
}


int Notes::getPitchFromNote(char note) const{
	return notes_.at(note);
}

int Notes::sharpNote(char note) const{
	return this->getPitchFromNote(note) + 1;
}

int Notes::flatNote(char note) const{
	return this->getPitchFromNote(note) - 1;
}

const std::string& Notes::getInterval(const std::string& first,const std::string& second) const{
	int interval =  this->getPitch(second) - this->getPitch(first);
	return intervals_.at(interval);
}
