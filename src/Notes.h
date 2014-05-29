
#ifndef NOTES_H_
#define NOTES_H_

#include <map>
#include <string>

class Notes {

public:
	Notes();
	virtual ~Notes();

	void addNote(char c,int pitch);

	int getPitchOctave(const std::string& note,int octave) const;
	int getPitch(const std::string& note) const;
	int getPitchFromFrequency(float frequency) const;
	const std::string& getInterval(const std::string& first,const std::string& second) const;
//	char getNote() const;

private:
	int sharpNote(char note) const;
	int flatNote(char note) const;
	int getPitchFromNote(char note) const;
	std::map<char,int> notes_;
	std::map<int,std::string> intervals_;
};

#endif /* NOTES_H_ */
